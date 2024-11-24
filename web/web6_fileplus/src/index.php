<?php
if(isset($_GET['file'])){
	$file =$_GET['file'];
	$file=str_replace("php","???",$file);
	include($file);
}else{
	highlight_file(__FILE__);
}
?>