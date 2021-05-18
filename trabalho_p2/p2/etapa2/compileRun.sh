#!/bin/bash

#Copio o nome do arquivo e retiro a extensão do nome. Com isso coloco a extensão ".out": 
out=${1%.*}.out

#compilo o arquivo que foi passado por parâmetro e escrevo o resultado do comando no arquivo chamado "retorno":
cc $* -Wall -o $out &> retorno

#Verifico se existe algo escrito no retorno. Caso não tenha, ele foi compilado sem erros e com isso executamos. Caso tenhamos algum erro, não executamos o arquivo e também imprimimos o erro na tela: 
if [[ -z $(cat retorno) ]];
  then
       ./$out
elif [[ -z $(cat retorno | grep error) ]]
  then	  
       cat retorno
       echo "################################"
       ./$out
else
	cat retorno
fi

#apagamos o arquivo "resultado":
rm -f retorno    	 
