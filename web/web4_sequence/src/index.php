<?php
show_source(__FILE__);
//you should find flag in you self
class one{
public $a;
function new(){
printf("i am new baby");
}
public function __wakeup()
{
$this->a->new();
}
}

class two{
public $func;
public $arg;
public function __call($func,$arg)
{
$this->func->arg;
}
}

class three{
public $kkk;
public function __get($kkk){
return "look!you are hero".$this->kkk;
}
}
class four {
public $s;
public function eval()
{
$pattern = "/(ls|c|a|t| |f|i|n|d')/";
if (preg_match($pattern, $this->s)) {
print("oh nonono hacker!");
return '';
} else {
return system($this->s);
}
}
public function __toString() {
$this->eval();
return 'joker!';
}
}
(unserialize(base64_decode($_GET['cmd'])));