//exemplo de como um servidor web cria subprocessos par aatendimento de requisições.
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main () {
    while(1) { //loop infinito
        req = pega_proxima_requisicao();
        pid = fork();

        if(pid == 0){
            processa_requisicao(req);
            exit(0);
        }
    }
   
    return 0;
}

/**
 * “pega_proxima_requisicao()”
Neste código, a rotina “pega_proxima_requisicao()” é responsável por verificar se existe alguma requisição enfileirada para atendimento. 
Se não houver, o processo pai fica bloqueado até que chegue uma nova requisição, sem impactar no desempenho do sistema. Enquanto isso, 
seus processos filhos continuam atendendo às requisições em andamento.

“processa_requisicao()”
A rotina “processa_requisicao()” é executada somente pelo processo filho, uma vez que o comando if anterior faz essa verificação.
 Essa rotina fica encarregada do atendimento à requisição que foi enviada ao servidor web. Depois do processamento, a chamada de sistema “exit(0)”
 encerra o processo filho.

“while (1) {…}”
Todo o código fica contido em um loop infinito “while (1) {…}”. Esse loop repetidamente pega a próxima requisição da fila,
 cria um processo filho para atendimento da requisição e retorna a aguardar uma nova requisição, enquanto o processo filho faz o
 processamento da requisição que acabou de chegar.
 */