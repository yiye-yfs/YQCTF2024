<?php
	$html='';
	$link=@mysqli_connect('localhost','root','123456','root','3306');
	if(isset($link) && is_object($link)){
		if(isset($_POST['id'])){
			$id=$_POST['id'];
			$getid="SELECT first_name, last_name FROM users WHERE user_id = $id;";
			if(@mysqli_num_rows(mysqli_query($link,$getid))>0){
				$html .='<pre>User ID exists in the database.</pre>';
			}
			else{
				$html .='<pre>User ID is MISSING from the database.</pre>';
			}
		}
		else{
			$html .='<pre>Please fuzzing some arguments.</pre>';
		}
	}
	else{
		$html .='<pre>Datase connection wrong!</pre>';
	}
	echo $html;
?>
