<?php
/* 
* @file
* File with admin functions for DrupalToNetsuite module
*/

/*
* Menu calback and form builder for admin/settings/drupaltonetsuite
*/
function drupaltonetsuite_admin_settings($form_state) {
	$form = array();
	$form['drupaltonetsuite_username'] = array (
	'#type' => 'textfield',
	'#title' => t('UserName for Netsuite Account'),
	'#description' => t('Enter the username for Netsuite Account'),
	'#required' => TRUE,
	);
	$form['drupaltonetsuite_password'] = array (
	'#type' => 'password',
	'#title' => t('Password for the Netsuite Account'),
	'#description' => t('Enter the password for Netsuite Account'),
	'#required' => TRUE,
	);
	/*$form['submit'] = array(
    	'#type' => 'submit',
    	'#value' => 'Submit',
  );*/
  $form['#submit'][] = 'drupaltonetsuite_admin_settings_submit';
  return system_settings_form($form);
}

/*
* Pushing to DB
*/
function drupaltonetsuite_admin_settings_submit($form, &$form_state) {
	 
	 /* if(!$form_state['values']['drupaltonetsuite_password']){ 
  	*$form_state['values']['drupaltonetsuite_password'] = variable_get('drupaltonetsuite_password', 'no-pass'); 
  } */
  $username = $form_state['values']['drupaltonetsuite_username'];
  $password = $form_state['values']['drupaltonetsuite_password'];
  echo "Username:".$username." Password:".$password;
    $query = "INSERT INTO {drupaltonetsuite} (netsuite_uid, password) VALUES ('%s', '%s')";
    $result = db_query($query, $username, $password);
}