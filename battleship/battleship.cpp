#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <map>
#include <random>
#include <windows.h>
#include <algorithm>
using namespace std;
//board
    string board =  "  |A|B|C|D|E|F|G|H|I|J|K|L|M|N|O|P|Q|R|S|T|U|V|W|X|Y|Z|\n"
                    " 1| | | | | | | | | | | | | | | | | | | | | | | | | | |\n"
                    " 2| | | | | | | | | | | | | | | | | | | | | | | | | | |\n"
                    " 3| | | | | | | | | | | | | | | | | | | | | | | | | | |\n"
                    " 4| | | | | | | | | | | | | | | | | | | | | | | | | | |\n"
                    " 5| | | | | | | | | | | | | | | | | | | | | | | | | | |\n"
                    " 6| | | | | | | | | | | | | | | | | | | | | | | | | | |\n"
                    " 7| | | | | | | | | | | | | | | | | | | | | | | | | | |\n"
                    " 8| | | | | | | | | | | | | | | | | | | | | | | | | | |\n"
                    " 9| | | | | | | | | | | | | | | | | | | | | | | | | | |\n"
                    "10| | | | | | | | | | | | | | | | | | | | | | | | | | |\n"
                    "11| | | | | | | | | | | | | | | | | | | | | | | | | | |\n"
                    "12| | | | | | | | | | | | | | | | | | | | | | | | | | |\n"
                    "13| | | | | | | | | | | | | | | | | | | | | | | | | | |\n"
                    "14| | | | | | | | | | | | | | | | | | | | | | | | | | |\n"
                    "15| | | | | | | | | | | | | | | | | | | | | | | | | | |\n"
                    "  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    // index map of spots
    map<string, int> spots = {
    {"A1", 59}, {"B1", 61}, {"C1", 63}, {"D1", 65}, {"E1", 67}, {"F1", 69}, {"G1", 71}, {"H1", 73}, {"I1", 75}, {"J1", 77}, {"K1", 79}, {"L1", 81}, {"M1", 83}, {"N1", 85}, {"O1", 87}, {"P1", 89}, {"Q1", 91}, {"R1", 93}, {"S1", 95}, {"T1", 97}, {"U1", 99}, {"V1", 101}, {"W1", 103}, {"X1", 105}, {"Y1", 107}, {"Z1", 109},
    {"A2", 115}, {"B2", 117}, {"C2", 119}, {"D2", 121}, {"E2", 123}, {"F2", 125}, {"G2", 127}, {"H2", 129}, {"I2", 131}, {"J2", 133}, {"K2", 135}, {"L2", 137}, {"M2", 139}, {"N2", 141}, {"O2", 143}, {"P2", 145}, {"Q2", 147}, {"R2", 149}, {"S2", 151}, {"T2", 153}, {"U2", 155}, {"V2", 157}, {"W2", 159}, {"X2", 161}, {"Y2", 163}, {"Z2", 165},
    {"A3", 171}, {"B3", 173}, {"C3", 175}, {"D3", 177}, {"E3", 179}, {"F3", 181}, {"G3", 183}, {"H3", 185}, {"I3", 187}, {"J3", 189}, {"K3", 191}, {"L3", 193}, {"M3", 195}, {"N3", 197}, {"O3", 199}, {"P3", 201}, {"Q3", 203}, {"R3", 205}, {"S3", 207}, {"T3", 209}, {"U3", 211}, {"V3", 213}, {"W3", 215}, {"X3", 217}, {"Y3", 219}, {"Z3", 221},
    {"A4", 227}, {"B4", 229}, {"C4", 231}, {"D4", 233}, {"E4", 235}, {"F4", 237}, {"G4", 239}, {"H4", 241}, {"I4", 243}, {"J4", 245}, {"K4", 247}, {"L4", 249}, {"M4", 251}, {"N4", 253}, {"O4", 255}, {"P4", 257}, {"Q4", 259}, {"R4", 261}, {"S4", 263}, {"T4", 265}, {"U4", 267}, {"V4", 269}, {"W4", 271}, {"X4", 273}, {"Y4", 275}, {"Z4", 277},
    {"A5", 283}, {"B5", 285}, {"C5", 287}, {"D5", 289}, {"E5", 291}, {"F5", 293}, {"G5", 295}, {"H5", 297}, {"I5", 299}, {"J5", 301}, {"K5", 303}, {"L5", 305}, {"M5", 307}, {"N5", 309}, {"O5", 311}, {"P5", 313}, {"Q5", 315}, {"R5", 317}, {"S5", 319}, {"T5", 321}, {"U5", 323}, {"V5", 325}, {"W5", 327}, {"X5", 329}, {"Y5", 331}, {"Z5", 333},
    {"A6", 339}, {"B6", 341}, {"C6", 343}, {"D6", 345}, {"E6", 347}, {"F6", 349}, {"G6", 351}, {"H6", 353}, {"I6", 355}, {"J6", 357}, {"K6", 359}, {"L6", 361}, {"M6", 363}, {"N6", 365}, {"O6", 367}, {"P6", 369}, {"Q6", 371}, {"R6", 373}, {"S6", 375}, {"T6", 377}, {"U6", 379}, {"V6", 381}, {"W6", 383}, {"X6", 385}, {"Y6", 387}, {"Z6", 389},
    {"A7", 395}, {"B7", 397}, {"C7", 399}, {"D7", 401}, {"E7", 403}, {"F7", 405}, {"G7", 407}, {"H7", 409}, {"I7", 411}, {"J7", 413}, {"K7", 415}, {"L7", 417}, {"M7", 419}, {"N7", 421}, {"O7", 423}, {"P7", 425}, {"Q7", 427}, {"R7", 429}, {"S7", 431}, {"T7", 433}, {"U7", 435}, {"V7", 437}, {"W7", 439}, {"X7", 441}, {"Y7", 443}, {"Z7", 445},
    {"A8", 451}, {"B8", 453}, {"C8", 455}, {"D8", 457}, {"E8", 459}, {"F8", 461}, {"G8", 463}, {"H8", 465}, {"I8", 467}, {"J8", 469}, {"K8", 471}, {"L8", 473}, {"M8", 475}, {"N8", 477}, {"O8", 479}, {"P8", 481}, {"Q8", 483}, {"R8", 485}, {"S8", 487}, {"T8", 489}, {"U8", 491}, {"V8", 493}, {"W8", 495}, {"X8", 497}, {"Y8", 499}, {"Z8", 501},
    {"A9", 507}, {"B9", 509}, {"C9", 511}, {"D9", 513}, {"E9", 515}, {"F9", 517}, {"G9", 519}, {"H9", 521}, {"I9", 523}, {"J9", 525}, {"K9", 527}, {"L9", 529}, {"M9", 531}, {"N9", 533}, {"O9", 535}, {"P9", 537}, {"Q9", 539}, {"R9", 541}, {"S9", 543}, {"T9", 545}, {"U9", 547}, {"V9", 549}, {"W9", 551}, {"X9", 553}, {"Y9", 555}, {"Z9", 557},
    {"A10", 563}, {"B10", 565}, {"C10", 567}, {"D10", 569}, {"E10", 571}, {"F10", 573}, {"G10", 575}, {"H10", 577}, {"I10", 579}, {"J10", 581}, {"K10", 583}, {"L10", 585}, {"M10", 587}, {"N10", 589}, {"O10", 591}, {"P10", 593}, {"Q10", 595}, {"R10", 597}, {"S10", 599}, {"T10", 601}, {"U10", 603}, {"V10", 605}, {"W10", 607}, {"X10", 609}, {"Y10", 611}, {"Z10", 613},
    {"A11", 619}, {"B11", 621}, {"C11", 623}, {"D11", 625}, {"E11", 627}, {"F11", 629}, {"G11", 631}, {"H11", 633}, {"I11", 635}, {"J11", 637}, {"K11", 639}, {"L11", 641}, {"M11", 643}, {"N11", 645}, {"O11", 647}, {"P11", 649}, {"Q11", 651}, {"R11", 653}, {"S11", 655}, {"T11", 657}, {"U11", 659}, {"V11", 661}, {"W11", 663}, {"X11", 665}, {"Y11", 667}, {"Z11", 669},
    {"A12", 675}, {"B12", 677}, {"C12", 679}, {"D12", 681}, {"E12", 683}, {"F12", 685}, {"G12", 687}, {"H12", 689}, {"I12", 691}, {"J12", 693}, {"K12", 695}, {"L12", 697}, {"M12", 699}, {"N12", 701}, {"O12", 703}, {"P12", 705}, {"Q12", 707}, {"R12", 709}, {"S12", 711}, {"T12", 713}, {"U12", 715}, {"V12", 717}, {"W12", 719}, {"X12", 721}, {"Y12", 723}, {"Z12", 725},
    {"A13", 731}, {"B13", 733}, {"C13", 735}, {"D13", 737}, {"E13", 739}, {"F13", 741}, {"G13", 743}, {"H13", 745}, {"I13", 747}, {"J13", 749}, {"K13", 751}, {"L13", 753}, {"M13", 755}, {"N13", 757}, {"O13", 759}, {"P13", 761}, {"Q13", 763}, {"R13", 765}, {"S13", 767}, {"T13", 769}, {"U13", 771}, {"V13", 773}, {"W13", 775}, {"X13", 777}, {"Y13", 779}, {"Z13", 781},
    {"A14", 787}, {"B14", 789}, {"C14", 791}, {"D14", 793}, {"E14", 795}, {"F14", 797}, {"G14", 799}, {"H14", 801}, {"I14", 803}, {"J14", 805}, {"K14", 807}, {"L14", 809}, {"M14", 811}, {"N14", 813}, {"O14", 815}, {"P14", 817}, {"Q14", 819}, {"R14", 821}, {"S14", 823}, {"T14", 825}, {"U14", 827}, {"V14", 829}, {"W14", 831}, {"X14", 833}, {"Y14", 835}, {"Z14", 837},
    {"A15", 843}, {"B15", 845}, {"C15", 847}, {"D15", 849}, {"E15", 851}, {"F15", 853}, {"G15", 855}, {"H15", 857}, {"I15", 859}, {"J15", 861}, {"K15", 863}, {"L15", 865}, {"M15", 867}, {"N15", 869}, {"O15", 871}, {"P15", 873}, {"Q15", 875}, {"R15", 877}, {"S15", 879}, {"T15", 881}, {"U15", 883}, {"V15", 885}, {"W15", 887}, {"X15", 889}, {"Y15", 891}, {"Z15", 893}
    };
    //strings for random to index
    string abc = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    vector<string> num = {"1","2","3","4","5","6","7","8","9","10","11","12","13","14","15"};

int main(){
    string play1;
    cout << board;

    // Randoms abc vert3
    random_device vert3devabc;
    mt19937 vert3rngabc(vert3devabc());
    uniform_int_distribution<mt19937::result_type> vert3abc(0, abc.size() - 1);
    // randoms num vert3
    random_device vert3devnum;
    mt19937 vert3rngnum(vert3devnum());
    uniform_int_distribution<mt19937::result_type> vert3num(1, num.size() - 2);

    //vertical 3 ships place
    char vert3_1_abc = abc[vert3abc(vert3rngabc)];

    int vert3_1_numindex = vert3num(vert3rngnum);

    string vert3_1_topnum = num[vert3_1_numindex - 1];
    string vert3_1_num = num[vert3_1_numindex];
    string vert3_1_bottomnum = num[vert3_1_numindex + 1];

    string vert3_1_top = vert3_1_abc + vert3_1_topnum;
    string vert3_1 = vert3_1_abc + vert3_1_num;
    string vert3_1_bottom = vert3_1_abc + vert3_1_bottomnum;

    char vert3_2_abc = abc[vert3abc(vert3rngabc)];

    int vert3_2_numindex = vert3num(vert3rngnum);

    string vert3_2_topnum = num[vert3_2_numindex - 1];
    string vert3_2_num = num[vert3_2_numindex];
    string vert3_2_bottomnum = num[vert3_2_numindex + 1];

    string vert3_2_top = vert3_2_abc + vert3_2_topnum;
    string vert3_2 = vert3_2_abc + vert3_2_num;
    string vert3_2_bottom = vert3_2_abc + vert3_2_bottomnum;

    //check if ships are same if are then change 3_2
        if (
    vert3_2 == vert3_1_top
    || vert3_2 == vert3_1
    || vert3_2 == vert3_1_bottom
    || vert3_2 == vert3_2_top
    || vert3_2 == vert3_2
    || vert3_2 == vert3_2_bottom){
        vert3_2_numindex = vert3num(vert3rngnum);

        vert3_2_topnum = num[vert3_2_numindex - 1];
        vert3_2_num = num[vert3_2_numindex];
        vert3_2_bottomnum = num[vert3_2_numindex + 1];

        vert3_2_top = vert3_2_abc + vert3_2_topnum;
        vert3_2 = vert3_2_abc + vert3_2_num;
        vert3_2_bottom = vert3_2_abc + vert3_2_bottomnum;
    }

    // Randoms abc vert2
    random_device vert2devabc;
    mt19937 vert2rngabc(vert2devabc());
    uniform_int_distribution<mt19937::result_type> vert2abc(0, abc.size() - 1);
    // randoms num vert2
    random_device vert2devnum;
    mt19937 vert2rngnum(vert2devnum());
    uniform_int_distribution<mt19937::result_type> vert2num(1, num.size() - 1);

    //vertical 2 ships place
    char vert2_1_abc = abc[vert2abc(vert2rngabc)];

    int vert2_1_numindex = vert2num(vert2rngnum);

    string vert2_1_topnum = num[vert2_1_numindex - 1];
    string vert2_1_num = num[vert2_1_numindex];

    string vert2_1_top = vert2_1_abc + vert2_1_topnum;
    string vert2_1 = vert2_1_abc + vert2_1_num;

    char vert2_2_abc = abc[vert2abc(vert2rngabc)];

    int vert2_2_numindex = vert2num(vert2rngnum);

    string vert2_2_topnum = num[vert2_2_numindex - 1];
    string vert2_2_num = num[vert2_2_numindex];

    string vert2_2_top = vert2_2_abc + vert2_2_topnum;
    string vert2_2 = vert2_2_abc + vert2_2_num;

    //check if ships are same if are then change 2_2
    if (
    vert2_2 == vert3_1_top
    || vert2_2 == vert3_1
    || vert2_2 == vert3_1_bottom
    || vert2_2 == vert3_2_top
    || vert2_2 == vert3_2
    || vert2_2 == vert3_2_bottom
    || vert2_2 == vert2_1_top
    || vert2_2 == vert2_1
    || vert2_2 == vert2_2_top
    || vert2_2 == vert2_2){
        vert2_2_numindex = vert2num(vert2rngnum);

        vert2_2_topnum = num[vert2_2_numindex - 1];
        vert2_2_num = num[vert2_2_numindex];

        vert2_2_top = vert2_2_abc + vert2_2_topnum;
        vert2_2 = vert2_2_abc + vert2_2_num;
    }
    //horiontal 3 ships
    random_device horz3devabc;
    mt19937 horz3rngabc(horz3devabc());
    uniform_int_distribution<mt19937::result_type> horz3abc(1, abc.size() - 2);
    // randoms num horz3
    random_device horz3devnum;
    mt19937 horz3rngnum(horz3devnum());
    uniform_int_distribution<mt19937::result_type> horz3num(0, num.size() - 1);

    //horzical 3 ships place
    string horz3_1_num = num[horz3num(horz3rngnum)];

    int horz3_1_abcindex = horz3abc(horz3rngabc);

    char horz3_1_leftabc = abc[horz3_1_abcindex - 1];
    char horz3_1_abc = abc[horz3_1_abcindex];
    char horz3_1_rightabc = abc[horz3_1_abcindex + 1];

    string horz3_1_left = horz3_1_leftabc + horz3_1_num;
    string horz3_1 = horz3_1_abc + horz3_1_num;
    string horz3_1_right = horz3_1_rightabc + horz3_1_num;

    //horz3_2
    string horz3_2_num = num[horz3num(horz3rngnum)];

    int horz3_2_abcindex = horz3abc(horz3rngabc);

    char horz3_2_leftabc = abc[horz3_2_abcindex - 1];
    char horz3_2_abc = abc[horz3_2_abcindex];
    char horz3_2_rightabc = abc[horz3_2_abcindex + 1];

    string horz3_2_left = horz3_2_leftabc + horz3_2_num;
    string horz3_2 = horz3_2_abc + horz3_2_num;
    string horz3_2_right = horz3_2_rightabc + horz3_2_num;

    //check if ships are same if are then change 3_2
    if (
    horz3_2 == vert3_1_top
    || horz3_2 == vert3_1
    || horz3_2 == vert3_1_bottom
    || horz3_2 == vert3_2_top
    || horz3_2 == vert3_2
    || horz3_2 == vert3_2_bottom
    || horz3_2 == vert2_1_top
    || horz3_2 == vert2_1
    || horz3_2 == vert2_2_top
    || horz3_2 == vert2_2
    || horz3_2 == horz3_1_left
    || horz3_2 == horz3_1
    || horz3_2 == horz3_1_right){
        horz3_2_num = num[horz3num(horz3rngnum)];

        horz3_2_abcindex = horz3abc(horz3rngabc);

        horz3_2_leftabc = abc[horz3_2_abcindex - 1];
        horz3_2_abc = abc[horz3_2_abcindex];
        horz3_2_rightabc = abc[horz3_2_abcindex + 1];

        horz3_2_left = horz3_2_leftabc + horz3_2_num;
        horz3_2 = horz3_2_abc + horz3_2_num;
        horz3_2_right = horz3_2_rightabc + horz3_2_num;
    }

    //horiontal 2 ships
    random_device horz2devabc;
    mt19937 horz2rngabc(horz2devabc());
    uniform_int_distribution<mt19937::result_type> horz2abc(1, abc.size() - 1);
    // randoms num horz2
    random_device horz2devnum;
    mt19937 horz2rngnum(horz2devnum());
    uniform_int_distribution<mt19937::result_type> horz2num(0, num.size() - 1);

    //horzical 2 ships place
    string horz2_1_num = num[horz2num(horz2rngnum)];

    int horz2_1_abcindex = horz2abc(horz2rngabc);

    char horz2_1_leftabc = abc[horz2_1_abcindex - 1];
    char horz2_1_abc = abc[horz2_1_abcindex];


    string horz2_1_left = horz2_1_leftabc + horz2_1_num;
    string horz2_1 = horz2_1_abc + horz2_1_num;

    //horz2_2
    string horz2_2_num = num[horz2num(horz2rngnum)];

    int horz2_2_abcindex = horz2abc(horz2rngabc);

    char horz2_2_leftabc = abc[horz2_2_abcindex - 1];
    char horz2_2_abc = abc[horz2_2_abcindex];

    string horz2_2_left = horz2_2_leftabc + horz2_2_num;
    string horz2_2 = horz2_2_abc + horz2_2_num;

    //check if ships are same if are then change 2_2
    if (
    horz2_2 == vert3_1_top
    || horz2_2 == vert3_1
    || horz2_2 == vert3_1_bottom
    || horz2_2 == vert3_2_top
    || horz2_2 == vert3_2
    || horz2_2 == vert3_2_bottom
    || horz2_2 == vert2_1_top
    || horz2_2 == vert2_1
    || horz2_2 == vert2_2_top
    || horz2_2 == vert2_2
    || horz2_2 == horz3_1_left
    || horz2_2 == horz3_1
    || horz2_2 == horz3_1_right
    || horz2_2 == horz3_2_left
    || horz2_2 == horz3_2
    || horz2_2 == horz3_2_right
    || horz2_2 == horz2_1_left
    || horz2_2 == horz2_1){
        horz2_2_num = num[horz2num(horz2rngnum)];

        horz2_2_abcindex = horz2abc(horz2rngabc);

        horz2_2_leftabc = abc[horz2_2_abcindex - 1];
        horz2_2_abc = abc[horz2_2_abcindex];

        horz2_2_left = horz2_2_leftabc + horz2_2_num;
        horz2_2 = horz2_2_abc + horz2_2_num;
    }
    /*//show spots of ships for cheat
    cout << "vert31top:    " << vert3_1_top << "\n";
    cout << "vert3_1:      " << vert3_1 << "\n";
    cout << "vert31bottom: " << vert3_1_bottom << "\n";

    cout << "vert32top:    " << vert3_2_top << "\n";
    cout << "vert3_2:      " << vert3_2 << "\n";
    cout << "vert32bottom: " << vert3_2_bottom << "\n";

    board[spots[vert3_1_top]] = 'M';
    board[spots[vert3_1]] = 'N';
    board[spots[vert3_1_bottom]] = 'W';

    board[spots[vert3_2_top]] = 'M';
    board[spots[vert3_2]] = 'N';
    board[spots[vert3_2_bottom]] = 'W';

    cout << "vert21top: " << vert2_1_top << "\n";
    cout << "vert2_1:   " << vert2_1 << "\n";

    cout << "vert22top: " << vert2_2_top << "\n";
    cout << "vert2_2:   " << vert2_2 << "\n";

    board[spots[vert2_1_top]] = 'M';
    board[spots[vert2_1]] = 'W';

    board[spots[vert2_2_top]] = 'M';
    board[spots[vert2_2]] = 'W';

    cout << "horz31left:    " << horz3_1_left << "\n";
    cout << "horz3_1:      " << horz3_1 << "\n";
    cout << "horz31right: " << horz3_1_right << "\n";

    cout << "horz32left:    " << horz3_2_left << "\n";
    cout << "horz3_2:      " << horz3_2 << "\n";
    cout << "horz32right: " << horz3_2_right << "\n";

    board[spots[horz3_1_left]] = '<';
    board[spots[horz3_1]] = '#';
    board[spots[horz3_1_right]] = '>';

    board[spots[horz3_2_left]] = '<';
    board[spots[horz3_2]] = '#';
    board[spots[horz3_2_right]] = '>';

    cout << "horz21left: " << horz2_1_left << "\n";
    cout << "horz2_1:   " << horz2_1 << "\n";

    cout << "horz22left: " << horz2_2_left << "\n";
    cout << "horz2_2:   " << horz2_2 << "\n";

    board[spots[horz2_1_left]] = '<';
    board[spots[horz2_1]] = '>';

    board[spots[horz2_2_left]] = '<';
    board[spots[horz2_2]] = '>';*/
    cout << board;

    while(true){
        cout <<"what spot: ";
        cin >> play1;
    //check for hit
    if (
    play1 == vert3_1_top
    || play1 == vert3_1
    || play1 == vert3_1_bottom
    || play1 == vert3_2_top
    || play1 == vert3_2
    || play1 == vert3_2_bottom
    || play1 == vert2_1_top
    || play1 == vert2_1
    || play1 == vert2_2_top
    || play1 == vert2_2
    || play1 == horz3_1_left
    || play1 == horz3_1
    || play1 == horz3_1_right
    || play1 == horz3_2_left
    || play1 == horz3_2
    || play1 == horz3_2_right
    || play1 == horz2_1_left
    || play1 == horz2_1
    || play1 == horz2_2_left
    || play1 == horz2_2){
        board[spots[play1]] = 'X';
    }else{
        board[spots[play1]] = 'O';
    }
    //check for win
    if (
    board[spots[vert3_1_top]] == 'X'
    && board[spots[vert3_1]] == 'X'
    && board[spots[vert3_1_bottom]] == 'X'
    && board[spots[vert3_2_top]] == 'X'
    && board[spots[vert3_2]] == 'X'
    && board[spots[vert3_2_bottom]] == 'X'
    && board[spots[vert2_1_top]] == 'X'
    && board[spots[vert2_1]] == 'X'
    && board[spots[vert2_2_top]] == 'X'
    && board[spots[vert2_2]] == 'X'
    && board[spots[horz3_1_left]] == 'X'
    && board[spots[horz3_1]] == 'X'
    && board[spots[horz3_1_right]] == 'X'
    && board[spots[horz3_2_left]] == 'X'
    && board[spots[horz3_2]] == 'X'
    && board[spots[horz3_2_right]]== 'X'
    && board[spots[horz2_1_left]] == 'X'
    && board[spots[horz2_1]] == 'X'
    && board[spots[horz2_2_left]] == 'X'
    && board[spots[horz2_2]] == 'X'
    ){
        //show ships at end
        board[spots[vert3_1_top]] = 'M';
        board[spots[vert3_1]] = 'N';
        board[spots[vert3_1_bottom]] = 'W';

        board[spots[vert3_2_top]] = 'M';
        board[spots[vert3_2]] = 'N';
        board[spots[vert3_2_bottom]] = 'W';

        board[spots[vert2_1_top]] = 'M';
        board[spots[vert2_1]] = 'W';

        board[spots[vert2_2_top]] = 'M';
        board[spots[vert2_2]] = 'W';

        board[spots[horz3_1_left]] = '<';
        board[spots[horz3_1]] = '#';
        board[spots[horz3_1_right]] = '>';

        board[spots[horz3_2_left]] = '<';
        board[spots[horz3_2]] = '#';
        board[spots[horz3_2_right]] = '>';

        board[spots[horz2_1_left]] = '<';
        board[spots[horz2_1]] = '>';

        board[spots[horz2_2_left]] = '<';
        board[spots[horz2_2]] = '>';
        
        cout << board;
        cout << '5';
        Sleep(1000);
        cout << '4';
        Sleep(1000);
        cout << '3';
        Sleep(1000);
        cout << '2';
        Sleep(1000);
        cout << '1';
        Sleep(1000);
        while (true){
            cout << "YOU WIN!!";
        }
    }
        cout << board;
    }
    return 0;
}