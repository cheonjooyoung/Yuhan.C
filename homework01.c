#include <stdio.h>
#include <stdlib.h>


int print_title_screen()
{
	printf("@@@@@@@@@@@@@@@@@@@@@@@@@2@@@@@@@@@@@@@@@\n");
	printf("@                                       @\n");
	printf("     1.게임을 시작하시겠습니까?          \n");
	printf("     2.이 게임은 무슨게임인가?           \n");
	printf("     3.게임을 종료하시겠습니까?          \n");
	printf("@                                       @\n");
	printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
	
	return 0;
}

int print_gamehelp_screen()
{
	printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
	printf("@                                                            @\n");
	printf("                   게임 설명                                  \n");
	printf("         1.이 게임은 카드게임입니다.                          \n");
	printf("         2.카드는 숫자2,3,4,왕,그리고 노예가있습니다(왕은5노예는1입니다)\n");
    printf("         3.숫자2,3,4중엔 높은 숫자를내는사람이 승리합니다,하지만 왕은 노예한테 집니다!\n");
    printf("         4.노예는2,3,4을 이길 수 없습니다.왕은 2,3,4을 이길 수 있습니다!.\n");
	printf("         5.각 플레이어는 카드를 한장씩 낼수있습니다.          \n");
	printf("         6.한번 사용한 패는 중복해서 사용가능합니다!          \n");
	printf("         7.총3번 먼저승리한 사람이 승리합니다                 \n");
	printf("         그러면 건투를 빌겠습니다 vr게임앱학과 파이팅!!       \n");
	printf("@                                                            @\n");
	printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");

	return 0;
}

int main() {
    int game_state = 0;

    while (1) {
        printf("게임을 시작하려면 1을 입력하세요. 도움말을 보려면 2를 입력하세요. 종료하려면 3을 입력하세요: ");
        scanf("%d", &game_state);

        if (game_state == 1) {
            printf("게임을 시작합니다.\n");
            printf("다음 라운드를 진행하려면 1을 입력하세요: ");
            int input;
            scanf("%d", &input);
            while (input != 1 && input != 3) {
                printf("잘못된 입력입니다. 다시 입력해주세요: ");
                scanf("%d", &input);
            }

            game_state = input;     
            int player1_card, player2_card;
            int player1_win_count = 0, player2_win_count = 0;
            int game_round = 1;

            print_title_screen();
            printf("\n재밌는 게임 시작!!\n");


            while (1) {
                printf("라운드 %d\n", game_round);
                printf("플레이어 1의 카드를 입력하세요 (1부터 5까지의 숫자): ");
                scanf("%d", &player1_card);

              
                while (player1_card < 1 || player1_card > 5) {
                    printf("잘못된 입력입니다. 다시 입력해주세요: ");
                    scanf("%d", &player1_card);
                }

                player2_card = rand() % 5 + 1;

                printf("플레이어 1의 카드: %d\n", player1_card);
                printf("플레이어 2의 카드: %d\n", player2_card);

                if (player1_card == player2_card) {
                    printf("무승부!\n");
                } else if (player1_card == 1 && player2_card == 5) {
                    printf("플레이어 1 승리!\n");
                    player1_win_count++;
                } else if (player1_card == 5 && player2_card == 1) {
                    printf("플레이어 2 승리!\n");
                    player2_win_count++;
                } else if (player1_card > player2_card) {
                    printf("플레이어 1 승리!\n");
                    player1_win_count++;
                } else {
                    printf("플레이어 2 승리!\n");
                    player2_win_count++;
                }

                if (player1_win_count == 3) {
                    printf("플레이어 1이 3번 이겼습니다. 게임 종료!\n");
                    break;
                } else if (player2_win_count == 3) {
                    printf("플레이어 2가 3번 이겼습니다. 게임 종료!\n");
                    break;
                }

                game_round++;
                player1_card = 1;
            }

            printf("다시 게임을 하려면 1을 입력하세요. 종료하려면 3을 입력하세요: ");
        } else if (game_state == 2) {
            print_gamehelp_screen();
            printf("다시 게임을 하려면 1을 입력하세요. 종료하려면 3을 입력하세요: ");
        } else {
            break;
        }
    }

    return 0;
}

