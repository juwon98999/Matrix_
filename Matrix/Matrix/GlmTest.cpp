#include <chrono>
#include <thread>
#include <string>
#include <iostream>
#include <GLFW/glfw3.h>
#include "MuSoenMath.h"
#include <math.h>


#pragma comment(lib, "OpenGL32")

#define PI 3.14159265

using namespace std;

chrono::system_clock::time_point startRenderTimePoint;
chrono::duration<double> renderDuration;

GLFWwindow* window;
bool isFirstFrame = true;


struct Vertex
{
    Vec3 pos;
    float r, g, b, a;
};

struct Transform
{
    Mat3 translate;
    Mat3 scale;
    Mat3 rotation;
};


Vertex star[5];             // static mesh
Vertex transformedStar[5];  //화면에 그릴 오망성
Vertex circle[360];             // static mesh 
Vertex transformedCircle[360];  // 화면에 그려질 원

Transform transform;  //world 행렬이 될 transform

//<문제>////////전역변수 쓰는곳////////////////////////////////////////////////////////////

double angle = 1.0 * 3.14 / 180; //회전각도

float scaleValue = 1.0f;
float minValue = 0.99f;
float maxValue = 1.01f;


bool ismax = false; //크기 조절 bool값

 //////////////////////////////////////////////////////////////////////////////////////////

void Init();
void Update();
void Release();

static void error_callback(int error, const char* description);
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

int main(void);


void Init()
{
    glfwSetErrorCallback(error_callback);
    if (!glfwInit())
        exit(EXIT_FAILURE);
    window = glfwCreateWindow(720, 720, "Simple example", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, key_callback);


    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glfwSwapInterval(1);

    startRenderTimePoint = chrono::system_clock::now();


    //object생성부
     /// Star(오망성) 생성
    int i = 0;
    for (float theta = 0; theta < 360; theta += 72)
    {

        star[i].pos.x = -sin((theta * 180 / PI)) * 0.5f;
        star[i].pos.y = cos((theta * 180 / PI)) * 0.5f;
        star[i].pos.z = 1.0f;

        star[i].r = 0.3f;
        star[i].g = 0.0f;
        star[i].b = theta / 360.0f;
        star[i].a = 0.7f;


        transformedStar[i] = star[i];

        i++;
    }

    // 원 생성
    for (int theta = 0; theta < 360; theta++)
    {
        circle[theta].pos.x = -sin(((float)theta * 180 / PI)) * 0.5;
        circle[theta].pos.y = cos(((float)theta * 180 / PI)) * 0.5;
        circle[theta].pos.z = 1.0f;

        circle[theta].r = 0.3f;
        circle[theta].g = 0.0f;
        circle[theta].b = (float)theta / 360.0f;
        circle[theta].a = 0.7f;

        transformedCircle[theta] = circle[theta];
    }


    ////트랜스폼 초기화 (기본형 제공)
    transform.translate = Mat3(
        1, 0, 0,
        0, 1, 0,
        0, 0, 1
    );
    transform.translate.Transpose();

    transform.rotation = Mat3(
        cos(0.0f * 180 / PI), -sin(0.0f * 180 / PI), 0,
        sin((0.0f * 180 / PI)), cos((0.0f * 180 / PI)), 0,
        0, 0, 1
    );
    transform.rotation.Transpose();

    transform.scale = Mat3(
        1, 0, 0,
        0, 1, 0,
        0, 0, 1
    );
    transform.scale.Transpose();


}

void Release()
{
    glfwDestroyWindow(window);
    glfwTerminate();
}
void Update()
{

    while (!glfwWindowShouldClose(window))
    {

        transform.translate = transform.translate * Mat3(
            1, 0, 0,
            0, 1, 0,
            0.001, 0, 1
        );

        transform.rotation = transform.rotation * Mat3(
            cos(angle), -sin(angle), 0,
            sin(angle), cos(angle), 0,
            0, 0, 1
        );

        if (ismax)
        {

            transform.scale = transform.scale * Mat3(
                minValue, 0, 0,
                0, minValue, 0,
                0, 0, 1
            );

            scaleValue *= minValue;
            if (scaleValue <= 0.7f) ismax = false;
        }
        else {

            transform.scale = transform.scale * Mat3(
                maxValue, 0, 0,
                0, maxValue, 0,
                0, 0, 1
            );

            scaleValue *= maxValue;
            if (scaleValue >= 1.3f) ismax = true;
        }

        for (int i = 0; i < 360; i++)
        {
            transformedCircle[i].pos = Trans_Mat3(transform.translate * transform.rotation * transform.scale * circle[i].pos);
        }

        for (int i = 0; i < 5; i++)
        {
            transformedStar[i].pos = Trans_Mat3(transform.translate * transform.rotation * transform.scale * star[i].pos);
        }


        glClearColor(.0f, 0.0f, 0.0f, 0.1f);
        glClear(GL_COLOR_BUFFER_BIT);
        glLineWidth(7.0f);
        glBegin(GL_LINE_STRIP);

        int a = 0;
        glColor4f(transformedStar[a].r, transformedStar[a].g, transformedStar[a].b, transformedStar[a].a);
        glVertex3f(transformedStar[a].pos.x, transformedStar[a].pos.y, 0.0f);
        a = 3;
        glColor4f(transformedStar[a].r, transformedStar[a].g, transformedStar[a].b, transformedStar[a].a);
        glVertex3f(transformedStar[a].pos.x, transformedStar[a].pos.y, 0.0f);
        a = 1;
        glColor4f(transformedStar[a].r, transformedStar[a].g, transformedStar[a].b, transformedStar[a].a);
        glVertex3f(transformedStar[a].pos.x, transformedStar[a].pos.y, 0.0f);
        a = 4;
        glColor4f(transformedStar[a].r, transformedStar[a].g, transformedStar[a].b, transformedStar[a].a);
        glVertex3f(transformedStar[a].pos.x, transformedStar[a].pos.y, 0.0f);
        a = 2;
        glColor4f(transformedStar[a].r, transformedStar[a].g, transformedStar[a].b, transformedStar[a].a);
        glVertex3f(transformedStar[a].pos.x, transformedStar[a].pos.y, 0.0f);

        a = 0;
        glColor4f(transformedStar[a].r, transformedStar[a].g, transformedStar[a].b, transformedStar[a].a);
        glVertex3f(transformedStar[a].pos.x, transformedStar[a].pos.y, 0.0f);
        glEnd();


        glBegin(GL_LINE_STRIP);
        for (int theta = 0; theta < 360; theta++)
        {
            glColor4f(transformedCircle[theta].r, transformedCircle[theta].g, transformedCircle[theta].b, transformedCircle[theta].a);
            glVertex3f(transformedCircle[theta].pos.x, transformedCircle[theta].pos.y, 0.0f);
        }
        glEnd();



        //화면 스왑
        glfwSwapBuffers(window);
        glfwPollEvents();

        //렌더시간 측정
        renderDuration = chrono::system_clock::now() - startRenderTimePoint;
        startRenderTimePoint = chrono::system_clock::now();

        float fps = 1.0 / renderDuration.count();
        if (isFirstFrame == true)
        {
            isFirstFrame = false;
            continue;
        }
        if (renderDuration.count() < (1.0f / 60.0f))
            this_thread::sleep_for(chrono::milliseconds((int)(((1.0f / 60.0f) - renderDuration.count()) * 1000)));
        /*string fps_s = "FPS : " + to_string(fps);
        std::cout << fps_s << endl;*/

    }
}

static void error_callback(int error, const char* description)
{
    fputs(description, stderr);
}
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}

int main(void)
{
    Init();
    Update();
    Release();

    exit(EXIT_SUCCESS);
}