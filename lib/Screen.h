#include<GL/glut.h>
#include<math.h>

class Screen {
  private:
    float bgColor[3];
    float fgColor[3];
    float height;
    float width;

    void (*drawFunction)();
    void DisplayInit();
    void Clear();
    void Setup();
    float startTime;

  public:
    Screen();
    Screen(float height, float width, void (*draw_function)());

    static void Draw(void);
    float Height();
    void Height(float);
    float Width();
    void Width(float);

    void FgColor(float, float, float);
    void BgColor(float, float, float);

    void GetPixelColor(int x, int y);
    void SetDrawFunction(void (*df)());
    void SetMouseFunction(void (*df)(int, int, int, int));
    void SetMotionFunction(void (*df)(int, int));
    void SetPassiveMotionFunction(void (*df)(int, int));
    float FPS();
    void SetFPS(int n);
    void ShowWindow();
};
