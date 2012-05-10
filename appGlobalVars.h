#define PI 3.1415

char bodyName[10][15] = {"Sun","Mercury","Venus","Earth","Mars","Jupiter","Saturn","Uranus","Neptune","Pluto + Ceres"};
float bodyRadii[] = {0.0,0.5,0.7,0.7,0.6,1.7,1.5,1.3,1.1,0.5};
float orbitPeriod[] = {0.0,126720.0,323568.0,525888.0,989280.0,6380640.0,15475680.0,44048160.0,86112000.0,130446720.0};
float epoch[]={0.0,13627665.75,13630579.0,13922899.58,14241140.2,18535221.46,25301781.93,20140822.57,74731252.68,75518933.97};
float eccentricity[] = {0,0.205,0.007,0.017,0.094,0.049,0.057,0.046,0.011,0.244};
float aphelion[] = {0.0,69.8,108.9,152.1,249.2,816.6,1514.5,3003.6,4545.7,7304.3};
float ZInclination[] = {0.0,7.0,3.4,0.0,1.9,1.3,2.5,0.8,1.8,17.2};
float MSLR = 15.21;

float bodyColorR[] = {0,0.5,0.7,0.2,0.8,0.9,0.9,0.2,0.2,0.7};
float bodyColorG[] = {0,0.5,0.0,0.4,0.3,0.9,0.3,0.2,0.1,0.7};
float bodyColorB[] = {0,0.5,0.0,0.9,0.0,0.0,0.0,0.4,0.5,0.7};

float cameraR = -50.0;
float cameraX = 0.0;
float cameraY = 0.0;
float cameraZ = 0.0;

int timeON=0;
int timeRate = 0;
int fastForward = 0;

int appWidth,appHeight;

int currentTime;
char *currentTimeString;

int fullScreenON = 0;
int nowPlaying = 0;