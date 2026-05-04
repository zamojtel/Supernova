grammar Expr;
options{
contextSuperClass = MyContextSuperClass;
}
prog:	expr EOF {$ctx -> value = $expr.ctx -> value;} ;
expr:	expr ('*'|'/') expr
    |	left = expr ('+'|'-') right = expr{
            $ctx -> value = $left.ctx -> value + $right.ctx -> value;
        }
    |	integer
    {
        $ctx -> value = $integer.ctx -> value;
    }
    |	'(' expr ')'
    ;
integer: INT{ $ctx -> value = std::atoi($INT -> getText().data());};
NEWLINE : [\r\n]+ -> skip;
INT     : [0-9]+ ;
