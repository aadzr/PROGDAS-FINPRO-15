#include <stdio.h>

typedef enum {
    NEUTRAL = 1,
    NEAR_NEUTRAL = 2,
    NON_NEUTRAL = 3,
    EXTREME = 4
} PostureType;

typedef enum {
    SLOW = 1,
    FAIR = 2,
    FAST = 3,
    VERY_FAST = 4
} SpeedType;

typedef struct {
    int intensity;
    float duration_pct;
    int efforts;
    PostureType posture;
    SpeedType speed;
    float hours;
} TaskData;

typedef struct {
    float m_intensity;
    float m_duration;
    float m_efforts;
    float m_posture;
    float m_speed;
    float m_hours;
    float strain_index;
    int risk_level;
} Result;

int main () {
    TaskData task;
    Result   result;
    int      pilihan;
    char     ulangi;

    printf("========================================\n");
    printf("    RSI STRAIN INDEX CALCULATOR\n");
    printf("    Berdasarkan Moore & Garg (1995)\n");
    printf("    SDG 3: Good Health & Well-Being\n");
    printf("========================================\n");
    printf("This program calculates your risk of\n");
    printf("Repetitive Strain Injury (RSI) on your\n");
    printf("hands and wrists from gaming or coding.\n");
    printf("Answer the following 6 questions: \n");

    

    do {

        printf("\n[1/6] INTENSITY OF EXERTION\n");
        printf("How hard are your fingers/hands working\n");
        printf("during the activity?\n");

        printf("Rate based on how tired your fingers\n");
        printf("feel after 10 minutes\n");

        printf("1. Light\n");
        printf("   Fingers barely feel anything.\n");
        printf("   e.g. browsing, reading, scrolling\n");

        printf("2. Somewhat Light\n");
        printf("   Fingers slightly active, comfortable.\n");
        printf("   e.g. casual typing, replying messages\n");

        printf("3. Somewhat Hard\n");
        printf("   Fingers noticeably working.\n");
        printf("   e.g. typing reports, regular computer use\n");
        
        printf("4. Hard\n");
        printf("   Fingers work heavily, tired after 30 min\n");
        printf("   e.g. fast typing, intensive computer work\n");

        printf("5. Near Maximal\n");
        printf("   Fingers at maximum capacity\n");
        printf("   e.g. non-stop typing, high-speed repetitive work\n");

        do {
            printf("Choose (1-5): ");
            scanf("%d", &task.intensity);
        } while (task.intensity < 1 || task.intensity > 5);

        printf("\n[2/6] DURATION OF EXERTION\n");
        printf("Out of 60 seconds, how many seconds are your fingers ACTIVELY pressing keys\n");
        printf("or clicking the mouse?\n");

        printf("Do not count pauses or resting time.\n");

        printf("1. 0-5 seconds active   (5%%)\n");
        printf("   Fingers mostly resting.\n");
        printf("   e.g. reading, watching, ocassional clicks\n");

        printf("2. 6-17 seconds active  (20%%)\n");
        printf("   Fingers work occasionally.\n");
        printf("   e.g. light typing with long pauses\n");

        printf("3. 18-29 seconds active (40%%)\n");
        printf("   Fingers work and rest equally.\n");
        printf("   e.g. regular typing with thinking pauses\n");

        printf("4. 30-47 seconds active (60%%)\n");
        printf("   Fingers active more than resting.\n");
        printf("   e.g. continuous typing, fast computer work\n");

        printf("5. 48-60 seconds active (80%%)\n");
        printf("   Fingers almost constantly pressing.\n");
        printf("   e.g. non-stop typing, repetitive clicking\n");

        do {
            printf("Choose (1-5): ");
            scanf("%d", &pilihan);
        } while (pilihan < 1 || pilihan > 5);

        if      (pilihan == 1) task.duration_pct = 5.0;
        else if (pilihan == 2) task.duration_pct = 20.0;
        else if (pilihan == 3) task.duration_pct = 40.0;
        else if (pilihan == 4) task.duration_pct = 60.0;
        else                   task.duration_pct = 80.0;

        printf("\n[3/6] EFFORTS PER MINUTE\n");
        printf("How many times do you press keys or click the mouse per minute?\n");
        printf("1. Less than 50 times per minute\n");
        printf("   You press keys or click very rarely.\n");
        printf("   e.g. reading  articles, watching videos, occasional mouse clicks\n");

        printf("2. 50 to 100 times per minute\n");
        printf("   You press keys or click occasionally.\n");
        printf("   e.g. casual typing, replying messages, light computer work\n");

        printf("3. 100 to 150 times per minute\n");
        printf("   You press keys or click at a moderate rate.\n");
        printf("   e.g. regular typing, writing reports, moderate computer work\n");

        printf("4. 150 to 200 times per minute\n");
        printf("   You press keys or click frequently and quickly.\n");
        printf("   e.g. fast typing, intensive computer work, rapid data entry\n");

        printf("5. More than 200 times per minute\n");
        printf("   You press keys or click at a very high rate almost non-stop.\n");
        printf("   e.g. non stop typing, highly repetitive clicking or keystroke\n");

        do {
            printf("Choose (1-5): ");
            scanf("%d", &pilihan);
        } while (pilihan < 1 || pilihan > 5);

        if      (pilihan == 1) task.efforts = 40;
        else if (pilihan == 2) task.efforts = 75;
        else if (pilihan == 3) task.efforts = 125;
        else if (pilihan == 4) task.efforts = 175;
        else                   task.efforts = 250;

        printf("\n[4/6] HAND/WRIST POSTURE\n");
        printf("What is the position of your wrist relative to your forearm while working?\n");
        printf("1. Neutral\n");
        printf("   Your wrist is completely straight and aligned with your forearm.\n");
        printf("   There is no bending up, down, or sideways.\n");
        printf("   Setup example: using a keyboard stand with a wrist rest, or a properly adjusted desk and chair\n");

        printf("2. Near Neutral\n");
        printf("   Your wrist is almost straight with only a slight bend (less than 15 degrees).\n");
        printf("   It looks nearly flat.\n");
        printf("   Setup example: standard desktop setup without wrist rest, keyboard lying flat on desk\n");

        printf("3. Non-Neutral\n");
        printf("   Your wrist is clearly bent upward, downward, or sideways (15 to 30 degrees).\n");
        printf("   You can visibly see the bend.\n");
        printf("   Setup example: using a laptop on a desk that is too low or too high,\n");
        printf("   no keyboard stand or wrist support at all\n");

        printf("4. Extreme\n");
        printf("   Your wrist is severely bent in any direction (more than 30 degrees).\n");
        printf("   The bend is very noticeable and uncomfortable.\n");
        printf("   Setup example: gaming or typing on a laptop placed on your bed or lap,\n");
        printf("   very awkward sitting position\n");

        do {
            printf("Choose (1-4): ");
            scanf("%d", &pilihan);
        } while (pilihan < 1 || pilihan > 4);
        task.posture = (PostureType) pilihan;

        printf("\n[5/6] SPEED OF WORK\n");
        printf("How rushed is your working pace?\n");
        printf("1. Slow\n");
        printf("Very relaxed, many long pauses, you can stop anytime.\n");
        printf("e.g hobby project with no deadline, no time pressure at all\n");
        printf("2. Fair\n");
        printf("Normal pace, deadline is still far.\n");
        printf("e.g assignment due next week, light workload with enough time.\n");
        printf("3. Fast\n");
        printf("Somewhat rushed, short pauses only.\n");
        printf("e.g assignment due tomorrow, tight schedule with little time left.\n");
        printf("4. Very Fast\n");
        printf("Full sprint, almost no breaks at all.\n");
        printf("e.g assignment due in a few hours, time critical work.\n");

        do {
            printf("Choose (1-4): ");
            scanf("%d", &pilihan);
        } while (pilihan < 1 || pilihan > 4);

        task.speed = (SpeedType) pilihan;

        printf("\n[6/6] DURATION PER DAY\n");
        printf("How many hours per day do you spend gaming or coding on average?\n");
        printf("How to estimate : \n");
        printf("Add up your weekly hours, divide by 7.\n");
        printf("Example : \n");
        printf("Mon 2h + Tue 2h + Wed 2h + Thu 3h + Fri 4h + Sat 8h + Sun 6h = 28h \n");
        printf("28 / 7 = 4 hours per day.\n");
        printf("Tip : Check your screen time app for a more accurate number.\n");
        printf("Format : 1.5 = 1 hour 30 minutes\n");

        do {
            printf("Hours (0-16): ");
            scanf("%f", &task.hours);
        } while (task.hours < 0 || task.hours > 16);

        printf("Calculate again? (y/n): ");
        scanf(" %c", &ulangi);
    } while (ulangi == 'y' || ulangi == 'Y');

    return 0;
}