<?php

class DrupalOAuthRequest extends OAuthRequest {
  /**
   * Creates a OAuthRequest object from the current request
   *
   * @param string $http_method
   * @param string $http_url
   * @param array $parameters
   * @return OAuthRequest
   *  A OAuthRequest generated from the request
   */
  public static function from_request($http_method = NULL, $http_url = NULL, $parameters = NULL) {
    // Preparations that has to be made if we're going to detect parameters
    if ($parameters == NULL) {
      // The QUERY_STRING might be messed up by rewriting the URL (ie. for clean urls).
      $qs = $_SERVER['QUERY_STRING'];
      $parts = explode($_SERVER['REQUEST_URI'], '?', 2);
      $_SERVER['QUERY_STRING'] = count($parts) >= 2 ? $parts[1] : '';
      $req = parent::from_request($http_method, $http_url, $parameters);
      $_SERVER['QUERY_STRING'] = $qs;
      return $req;
    } else {
      return parent::from_request($http_method, $http_url, $parameters);
    }
  }
}
