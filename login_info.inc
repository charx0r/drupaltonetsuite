<?php
/*
 * Copy rights info:
 * Owner: NetSuite Inc. 
 * Copyright (c) 2008, NetSuite Inc. 
 * All rights reserved.
*/

include('PHPtoolkit.inc');

// create a client object. You can specify the host to send requests to, e.g. live, beta, sandbox. Default is live.
$myNSclient = new nsClient( nsHost::live );

$email = "spuvala@argusoft.com";
$password = "argusadmin!";
$account = "TSTDRV658597";
$role = "3";

// set request level credentials. (email, password, account#, internal id of role)
$myNSclient->setPassport($email, $password, $account, $role);

?>
