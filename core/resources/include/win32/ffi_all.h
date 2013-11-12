typedef int sfBool;
typedef signed char sfInt8;
typedef unsigned char sfUint8;


typedef signed short sfInt16;
typedef unsigned short sfUint16;


typedef signed int sfInt32;
typedef unsigned int sfUint32;






    typedef signed long long sfInt64;
    typedef unsigned long long sfUint64;






typedef struct
{
    sfInt64 microseconds;
} sfTime;





extern __declspec(dllimport)  sfTime sfTime_Zero;









extern __declspec(dllimport)  float sfTime_asSeconds(sfTime time);









extern __declspec(dllimport)  sfInt32 sfTime_asMilliseconds(sfTime time);









extern __declspec(dllimport)  sfInt64 sfTime_asMicroseconds(sfTime time);









extern __declspec(dllimport)  sfTime sfSeconds(float amount);









extern __declspec(dllimport)  sfTime sfMilliseconds(sfInt32 amount);









extern __declspec(dllimport)  sfTime sfMicroseconds(sfInt64 amount);
typedef struct sfClock sfClock;
typedef struct sfMutex sfMutex;
typedef struct sfThread sfThread;








extern __declspec(dllimport)  sfClock* sfClock_create(void);









extern __declspec(dllimport)  sfClock* sfClock_copy(sfClock* clock);







extern __declspec(dllimport)  void sfClock_destroy(sfClock* clock);
extern __declspec(dllimport)  sfTime sfClock_getElapsedTime(const sfClock* clock);
extern __declspec(dllimport)  sfTime sfClock_restart(sfClock* clock);


typedef sfInt64 (*sfInputStreamReadFunc)(void* data, sfInt64 size, void* userData);
typedef sfInt64 (*sfInputStreamSeekFunc)(sfInt64 position, void* userData);
typedef sfInt64 (*sfInputStreamTellFunc)(void* userData);
typedef sfInt64 (*sfInputStreamGetSizeFunc)(void* userData);






typedef struct sfInputStream
{
    sfInputStreamReadFunc read;
    sfInputStreamSeekFunc seek;
    sfInputStreamTellFunc tell;
    sfInputStreamGetSizeFunc getSize;
    void* userData;
} sfInputStream;








extern __declspec(dllimport)  sfMutex* sfMutex_create(void);







extern __declspec(dllimport)  void sfMutex_destroy(sfMutex* mutex);







extern __declspec(dllimport)  void sfMutex_lock(sfMutex* mutex);







extern __declspec(dllimport)  void sfMutex_unlock(sfMutex* mutex);
extern __declspec(dllimport)  void sfSleep(sfTime duration);
extern __declspec(dllimport)  sfThread* sfThread_create(void (*function)(void*), void* userData);










extern __declspec(dllimport)  void sfThread_destroy(sfThread* thread);
extern __declspec(dllimport)  void sfThread_launch(sfThread* thread);
extern __declspec(dllimport)  void sfThread_wait(sfThread* thread);
extern __declspec(dllimport)  void sfThread_terminate(sfThread* thread);






typedef struct
{
    int x;
    int y;
} sfVector2i;






typedef struct
{
    unsigned int x;
    unsigned int y;
} sfVector2u;






typedef struct
{
    float x;
    float y;
} sfVector2f;






typedef struct
{
    float x;
    float y;
    float z;
} sfVector3f;
extern __declspec(dllimport)  void sfListener_setGlobalVolume(float volume);







extern __declspec(dllimport)  float sfListener_getGlobalVolume(void);









extern __declspec(dllimport)  void sfListener_setPosition(sfVector3f position);







extern __declspec(dllimport)  sfVector3f sfListener_getPosition();
extern __declspec(dllimport)  void sfListener_setDirection(sfVector3f orientation);







extern __declspec(dllimport)  sfVector3f sfListener_getDirection();






typedef enum
{
    sfStopped,
    sfPaused,
    sfPlaying
} sfSoundStatus;
typedef struct sfMusic sfMusic;
typedef struct sfSound sfSound;
typedef struct sfSoundBuffer sfSoundBuffer;
typedef struct sfSoundBufferRecorder sfSoundBufferRecorder;
typedef struct sfSoundRecorder sfSoundRecorder;
typedef struct sfSoundStream sfSoundStream;

typedef   unsigned int uintptr_t;








typedef char * va_list;
typedef   unsigned int size_t;






typedef size_t rsize_t;








typedef   int intptr_t;
typedef   int ptrdiff_t;





typedef unsigned short wchar_t;




typedef unsigned short wint_t;
typedef unsigned short wctype_t;
__declspec(deprecated)  typedef int errcode;
typedef int errno_t;



typedef   long __time32_t;




typedef __int64 __time64_t;







typedef __time64_t time_t;
struct threadlocaleinfostruct;
struct threadmbcinfostruct;
typedef struct threadlocaleinfostruct * pthreadlocinfo;
typedef struct threadmbcinfostruct * pthreadmbcinfo;
struct __lc_time_data;

typedef struct localeinfo_struct
{
    pthreadlocinfo locinfo;
    pthreadmbcinfo mbcinfo;
} _locale_tstruct, *_locale_t;


typedef struct tagLC_ID {
        unsigned short wLanguage;
        unsigned short wCountry;
        unsigned short wCodePage;
} LC_ID, *LPLC_ID;




typedef struct threadlocaleinfostruct {
        int refcount;
        unsigned int lc_codepage;
        unsigned int lc_collate_cp;
        unsigned long lc_handle[6];
        LC_ID lc_id[6];
        struct {
            char *locale;
            wchar_t *wlocale;
            int *refcount;
            int *wrefcount;
        } lc_category[6];
        int lc_clike;
        int mb_cur_max;
        int * lconv_intl_refcount;
        int * lconv_num_refcount;
        int * lconv_mon_refcount;
        struct lconv * lconv;
        int * ctype1_refcount;
        unsigned short * ctype1;
        const unsigned short * pctype;
        const unsigned char * pclmap;
        const unsigned char * pcumap;
        struct __lc_time_data * lc_time_curr;
} threadlocinfo;
 extern int *   _errno(void);


errno_t   _set_errno(  int _Value);
errno_t   _get_errno(  int * _Value);
extern __declspec(dllimport)  sfMusic* sfMusic_createFromFile(const char* filename);
extern __declspec(dllimport)  sfMusic* sfMusic_createFromMemory(const void* data, size_t sizeInBytes);
extern __declspec(dllimport)  sfMusic* sfMusic_createFromStream(sfInputStream* stream);







extern __declspec(dllimport)  void sfMusic_destroy(sfMusic* music);
extern __declspec(dllimport)  void sfMusic_setLoop(sfMusic* music, sfBool loop);









extern __declspec(dllimport)  sfBool sfMusic_getLoop(const sfMusic* music);









extern __declspec(dllimport)  sfTime sfMusic_getDuration(const sfMusic* music);
extern __declspec(dllimport)  void sfMusic_play(sfMusic* music);










extern __declspec(dllimport)  void sfMusic_pause(sfMusic* music);
extern __declspec(dllimport)  void sfMusic_stop(sfMusic* music);
extern __declspec(dllimport)  unsigned int sfMusic_getChannelCount(const sfMusic* music);
extern __declspec(dllimport)  unsigned int sfMusic_getSampleRate(const sfMusic* music);









extern __declspec(dllimport)  sfSoundStatus sfMusic_getStatus(const sfMusic* music);









extern __declspec(dllimport)  sfTime sfMusic_getPlayingOffset(const sfMusic* music);
extern __declspec(dllimport)  void sfMusic_setPitch(sfMusic* music, float pitch);
extern __declspec(dllimport)  void sfMusic_setVolume(sfMusic* music, float volume);
extern __declspec(dllimport)  void sfMusic_setPosition(sfMusic* music, sfVector3f position);
extern __declspec(dllimport)  void sfMusic_setRelativeToListener(sfMusic* music, sfBool relative);
extern __declspec(dllimport)  void sfMusic_setMinDistance(sfMusic* music, float distance);
extern __declspec(dllimport)  void sfMusic_setAttenuation(sfMusic* music, float attenuation);
extern __declspec(dllimport)  void sfMusic_setPlayingOffset(sfMusic* music, sfTime timeOffset);









extern __declspec(dllimport)  float sfMusic_getPitch(const sfMusic* music);









extern __declspec(dllimport)  float sfMusic_getVolume(const sfMusic* music);









extern __declspec(dllimport)  sfVector3f sfMusic_getPosition(const sfMusic* music);










extern __declspec(dllimport)  sfBool sfMusic_isRelativeToListener(const sfMusic* music);









extern __declspec(dllimport)  float sfMusic_getMinDistance(const sfMusic* music);









extern __declspec(dllimport)  float sfMusic_getAttenuation(const sfMusic* music);








extern __declspec(dllimport)  sfSound* sfSound_create(void);









extern __declspec(dllimport)  sfSound* sfSound_copy(sfSound* sound);







extern __declspec(dllimport)  void sfSound_destroy(sfSound* sound);
extern __declspec(dllimport)  void sfSound_play(sfSound* sound);










extern __declspec(dllimport)  void sfSound_pause(sfSound* sound);
extern __declspec(dllimport)  void sfSound_stop(sfSound* sound);
extern __declspec(dllimport)  void sfSound_setBuffer(sfSound* sound, const sfSoundBuffer* buffer);









extern __declspec(dllimport)  const sfSoundBuffer* sfSound_getBuffer(const sfSound* sound);
extern __declspec(dllimport)  void sfSound_setLoop(sfSound* sound, sfBool loop);









extern __declspec(dllimport)  sfBool sfSound_getLoop(const sfSound* sound);









extern __declspec(dllimport)  sfSoundStatus sfSound_getStatus(const sfSound* sound);
extern __declspec(dllimport)  void sfSound_setPitch(sfSound* sound, float pitch);
extern __declspec(dllimport)  void sfSound_setVolume(sfSound* sound, float volume);
extern __declspec(dllimport)  void sfSound_setPosition(sfSound* sound, sfVector3f position);
extern __declspec(dllimport)  void sfSound_setRelativeToListener(sfSound* sound, sfBool relative);
extern __declspec(dllimport)  void sfSound_setMinDistance(sfSound* sound, float distance);
extern __declspec(dllimport)  void sfSound_setAttenuation(sfSound* sound, float attenuation);
extern __declspec(dllimport)  void sfSound_setPlayingOffset(sfSound* sound, sfTime timeOffset);









extern __declspec(dllimport)  float sfSound_getPitch(const sfSound* sound);









extern __declspec(dllimport)  float sfSound_getVolume(const sfSound* sound);









extern __declspec(dllimport)  sfVector3f sfSound_getPosition(const sfSound* sound);










extern __declspec(dllimport)  sfBool sfSound_isRelativeToListener(const sfSound* sound);









extern __declspec(dllimport)  float sfSound_getMinDistance(const sfSound* sound);









extern __declspec(dllimport)  float sfSound_getAttenuation(const sfSound* sound);









extern __declspec(dllimport)  sfTime sfSound_getPlayingOffset(const sfSound* sound);
extern __declspec(dllimport)  sfSoundBuffer* sfSoundBuffer_createFromFile(const char* filename);
extern __declspec(dllimport)  sfSoundBuffer* sfSoundBuffer_createFromMemory(const void* data, size_t sizeInBytes);
extern __declspec(dllimport)  sfSoundBuffer* sfSoundBuffer_createFromStream(sfInputStream* stream);
extern __declspec(dllimport)  sfSoundBuffer* sfSoundBuffer_createFromSamples(const sfInt16* samples, size_t sampleCount, unsigned int channelCount, unsigned int sampleRate);









extern __declspec(dllimport)  sfSoundBuffer* sfSoundBuffer_copy(sfSoundBuffer* soundBuffer);







extern __declspec(dllimport)  void sfSoundBuffer_destroy(sfSoundBuffer* soundBuffer);
extern __declspec(dllimport)  sfBool sfSoundBuffer_saveToFile(const sfSoundBuffer* soundBuffer, const char* filename);
extern __declspec(dllimport)  const sfInt16* sfSoundBuffer_getSamples(const sfSoundBuffer* soundBuffer);
extern __declspec(dllimport)  size_t sfSoundBuffer_getSampleCount(const sfSoundBuffer* soundBuffer);
extern __declspec(dllimport)  unsigned int sfSoundBuffer_getSampleRate(const sfSoundBuffer* soundBuffer);
extern __declspec(dllimport)  unsigned int sfSoundBuffer_getChannelCount(const sfSoundBuffer* soundBuffer);









extern __declspec(dllimport)  sfTime sfSoundBuffer_getDuration(const sfSoundBuffer* soundBuffer);








extern __declspec(dllimport)  sfSoundBufferRecorder* sfSoundBufferRecorder_create(void);







extern __declspec(dllimport)  void sfSoundBufferRecorder_destroy(sfSoundBufferRecorder* soundBufferRecorder);
extern __declspec(dllimport)  void sfSoundBufferRecorder_start(sfSoundBufferRecorder* soundBufferRecorder, unsigned int sampleRate);







extern __declspec(dllimport)  void sfSoundBufferRecorder_stop(sfSoundBufferRecorder* soundBufferRecorder);
extern __declspec(dllimport)  unsigned int sfSoundBufferRecorder_getSampleRate(const sfSoundBufferRecorder* soundBufferRecorder);
extern __declspec(dllimport)  const sfSoundBuffer* sfSoundBufferRecorder_getBuffer(const sfSoundBufferRecorder* soundBufferRecorder);


typedef sfBool (*sfSoundRecorderStartCallback)(void*);
typedef sfBool (*sfSoundRecorderProcessCallback)(const sfInt16*, size_t, void*);
typedef void (*sfSoundRecorderStopCallback)(void*);
extern __declspec(dllimport)  sfSoundRecorder* sfSoundRecorder_create(sfSoundRecorderStartCallback onStart,
                                                        sfSoundRecorderProcessCallback onProcess,
                                                        sfSoundRecorderStopCallback onStop,
                                                        void* userData);







extern __declspec(dllimport)  void sfSoundRecorder_destroy(sfSoundRecorder* soundRecorder);
extern __declspec(dllimport)  void sfSoundRecorder_start(sfSoundRecorder* soundRecorder, unsigned int sampleRate);







extern __declspec(dllimport)  void sfSoundRecorder_stop(sfSoundRecorder* soundRecorder);
extern __declspec(dllimport)  unsigned int sfSoundRecorder_getSampleRate(const sfSoundRecorder* soundRecorder);
extern __declspec(dllimport)  sfBool sfSoundRecorder_isAvailable(void);
typedef struct sfContext sfContext;
typedef struct sfWindow sfWindow;










extern __declspec(dllimport)  sfContext* sfContext_create(void);







extern __declspec(dllimport)  void sfContext_destroy(sfContext* context);








extern __declspec(dllimport)  void sfContext_setActive(sfContext* context, sfBool active);






enum
{
    sfJoystickCount = 8,
    sfJoystickButtonCount = 32,
    sfJoystickAxisCount = 8
};






typedef enum
{
    sfJoystickX,
    sfJoystickY,
    sfJoystickZ,
    sfJoystickR,
    sfJoystickU,
    sfJoystickV,
    sfJoystickPovX,
    sfJoystickPovY
} sfJoystickAxis;










extern __declspec(dllimport)  sfBool sfJoystick_isConnected(unsigned int joystick);
extern __declspec(dllimport)  unsigned int sfJoystick_getButtonCount(unsigned int joystick);
extern __declspec(dllimport)  sfBool sfJoystick_hasAxis(unsigned int joystick, sfJoystickAxis axis);
extern __declspec(dllimport)  sfBool sfJoystick_isButtonPressed(unsigned int joystick, unsigned int button);
extern __declspec(dllimport)  float sfJoystick_getAxisPosition(unsigned int joystick, sfJoystickAxis axis);










extern __declspec(dllimport)  void sfJoystick_update(void);






typedef enum
{
    sfKeyUnknown = -1,
    sfKeyA,
    sfKeyB,
    sfKeyC,
    sfKeyD,
    sfKeyE,
    sfKeyF,
    sfKeyG,
    sfKeyH,
    sfKeyI,
    sfKeyJ,
    sfKeyK,
    sfKeyL,
    sfKeyM,
    sfKeyN,
    sfKeyO,
    sfKeyP,
    sfKeyQ,
    sfKeyR,
    sfKeyS,
    sfKeyT,
    sfKeyU,
    sfKeyV,
    sfKeyW,
    sfKeyX,
    sfKeyY,
    sfKeyZ,
    sfKeyNum0,
    sfKeyNum1,
    sfKeyNum2,
    sfKeyNum3,
    sfKeyNum4,
    sfKeyNum5,
    sfKeyNum6,
    sfKeyNum7,
    sfKeyNum8,
    sfKeyNum9,
    sfKeyEscape,
    sfKeyLControl,
    sfKeyLShift,
    sfKeyLAlt,
    sfKeyLSystem,
    sfKeyRControl,
    sfKeyRShift,
    sfKeyRAlt,
    sfKeyRSystem,
    sfKeyMenu,
    sfKeyLBracket,
    sfKeyRBracket,
    sfKeySemiColon,
    sfKeyComma,
    sfKeyPeriod,
    sfKeyQuote,
    sfKeySlash,
    sfKeyBackSlash,
    sfKeyTilde,
    sfKeyEqual,
    sfKeyDash,
    sfKeySpace,
    sfKeyReturn,
    sfKeyBack,
    sfKeyTab,
    sfKeyPageUp,
    sfKeyPageDown,
    sfKeyEnd,
    sfKeyHome,
    sfKeyInsert,
    sfKeyDelete,
    sfKeyAdd,
    sfKeySubtract,
    sfKeyMultiply,
    sfKeyDivide,
    sfKeyLeft,
    sfKeyRight,
    sfKeyUp,
    sfKeyDown,
    sfKeyNumpad0,
    sfKeyNumpad1,
    sfKeyNumpad2,
    sfKeyNumpad3,
    sfKeyNumpad4,
    sfKeyNumpad5,
    sfKeyNumpad6,
    sfKeyNumpad7,
    sfKeyNumpad8,
    sfKeyNumpad9,
    sfKeyF1,
    sfKeyF2,
    sfKeyF3,
    sfKeyF4,
    sfKeyF5,
    sfKeyF6,
    sfKeyF7,
    sfKeyF8,
    sfKeyF9,
    sfKeyF10,
    sfKeyF11,
    sfKeyF12,
    sfKeyF13,
    sfKeyF14,
    sfKeyF15,
    sfKeyPause,

    sfKeyCount
} sfKeyCode;










extern __declspec(dllimport)  sfBool sfKeyboard_isKeyPressed(sfKeyCode key);






typedef enum
{
    sfMouseLeft,
    sfMouseRight,
    sfMouseMiddle,
    sfMouseXButton1,
    sfMouseXButton2,

    sfMouseButtonCount
} sfMouseButton;










extern __declspec(dllimport)  sfBool sfMouse_isButtonPressed(sfMouseButton button);
extern __declspec(dllimport)  sfVector2i sfMouse_getPosition(const sfWindow* relativeTo);
extern __declspec(dllimport)  void sfMouse_setPosition(sfVector2i position, const sfWindow* relativeTo);






typedef enum
{
    sfEvtClosed,
    sfEvtResized,
    sfEvtLostFocus,
    sfEvtGainedFocus,
    sfEvtTextEntered,
    sfEvtKeyPressed,
    sfEvtKeyReleased,
    sfEvtMouseWheelMoved,
    sfEvtMouseButtonPressed,
    sfEvtMouseButtonReleased,
    sfEvtMouseMoved,
    sfEvtMouseEntered,
    sfEvtMouseLeft,
    sfEvtJoystickButtonPressed,
    sfEvtJoystickButtonReleased,
    sfEvtJoystickMoved,
    sfEvtJoystickConnected,
    sfEvtJoystickDisconnected
} sfEventType;






struct sfKeyEvent
{
    sfEventType type;
    sfKeyCode code;
    sfBool alt;
    sfBool control;
    sfBool shift;
    sfBool system;
};





struct sfTextEvent
{
    sfEventType type;
    sfUint32 unicode;
};





struct sfMouseMoveEvent
{
    sfEventType type;
    int x;
    int y;
};





struct sfMouseButtonEvent
{
    sfEventType type;
    sfMouseButton button;
    int x;
    int y;
};





struct sfMouseWheelEvent
{
    sfEventType type;
    int delta;
    int x;
    int y;
};





struct sfJoystickMoveEvent
{
    sfEventType type;
    unsigned int joystickId;
    sfJoystickAxis axis;
    float position;
};





struct sfJoystickButtonEvent
{
    sfEventType type;
    unsigned int joystickId;
    unsigned int button;
};





struct sfJoystickConnectEvent
{
    sfEventType type;
    unsigned int joystickId;
};





struct sfSizeEvent
{
    sfEventType type;
    unsigned int width;
    unsigned int height;
};






typedef union
{



    sfEventType type;
    struct sfSizeEvent size;
    struct sfKeyEvent key;
    struct sfTextEvent text;
    struct sfMouseMoveEvent mouseMove;
    struct sfMouseButtonEvent mouseButton;
    struct sfMouseWheelEvent mouseWheel;
    struct sfJoystickMoveEvent joystickMove;
    struct sfJoystickButtonEvent joystickButton;
    struct sfJoystickConnectEvent joystickConnect;
} sfEvent;








typedef struct
{
    unsigned int width;
    unsigned int height;
    unsigned int bitsPerPixel;
} sfVideoMode;








extern __declspec(dllimport)  sfVideoMode sfVideoMode_getDesktopMode(void);
extern __declspec(dllimport)  const sfVideoMode* sfVideoMode_getFullscreenModes(size_t* Count);
extern __declspec(dllimport)  sfBool sfVideoMode_isValid(sfVideoMode mode);









    struct HWND__;
    typedef struct HWND__* sfWindowHandle;






enum
{
    sfNone = 0,
    sfTitlebar = 1 << 0,
    sfResize = 1 << 1,
    sfClose = 1 << 2,
    sfFullscreen = 1 << 3,
    sfDefaultStyle = sfTitlebar | sfResize | sfClose
};






typedef struct
{
    unsigned int depthBits;
    unsigned int stencilBits;
    unsigned int antialiasingLevel;
    unsigned int majorVersion;
    unsigned int minorVersion;
} sfContextSettings;
extern __declspec(dllimport)  sfWindow* sfWindow_create(sfVideoMode mode, const char* title, sfUint32 style, const sfContextSettings* settings);
extern __declspec(dllimport)  sfWindow* sfWindow_createFromHandle(sfWindowHandle handle, const sfContextSettings* settings);







extern __declspec(dllimport)  void sfWindow_destroy(sfWindow* window);
extern __declspec(dllimport)  void sfWindow_close(sfWindow* window);
extern __declspec(dllimport)  sfBool sfWindow_isOpen(const sfWindow* window);
extern __declspec(dllimport)  sfContextSettings sfWindow_getSettings(const sfWindow* window);
extern __declspec(dllimport)  sfBool sfWindow_pollEvent(sfWindow* window, sfEvent* event);
extern __declspec(dllimport)  sfBool sfWindow_waitEvent(sfWindow* window, sfEvent* event);









extern __declspec(dllimport)  sfVector2i sfWindow_getPosition(const sfWindow* window);
extern __declspec(dllimport)  void sfWindow_setPosition(sfWindow* window, sfVector2i position);
extern __declspec(dllimport)  sfVector2u sfWindow_getSize(const sfWindow* window);








extern __declspec(dllimport)  void sfWindow_setSize(sfWindow* window, sfVector2u size);








extern __declspec(dllimport)  void sfWindow_setTitle(sfWindow* window, const char* title);
extern __declspec(dllimport)  void sfWindow_setIcon(sfWindow* window, unsigned int width, unsigned int height, const sfUint8* pixels);








extern __declspec(dllimport)  void sfWindow_setVisible(sfWindow* window, sfBool visible);








extern __declspec(dllimport)  void sfWindow_setMouseCursorVisible(sfWindow* window, sfBool visible);
extern __declspec(dllimport)  void sfWindow_setVerticalSyncEnabled(sfWindow* window, sfBool enabled);
extern __declspec(dllimport)  void sfWindow_setKeyRepeatEnabled(sfWindow* window, sfBool enabled);
extern __declspec(dllimport)  sfBool sfWindow_setActive(sfWindow* window, sfBool active);
extern __declspec(dllimport)  void sfWindow_display(sfWindow* window);
extern __declspec(dllimport)  void sfWindow_setFramerateLimit(sfWindow* window, unsigned int limit);
extern __declspec(dllimport)  void sfWindow_setJoystickThreshold(sfWindow* window, float threshold);
extern __declspec(dllimport)  sfWindowHandle sfWindow_getSystemHandle(const sfWindow* window);






typedef enum
{
    sfBlendAlpha,
    sfBlendAdd,
    sfBlendMultiply,
    sfBlendNone
} sfBlendMode;






typedef struct
{
    sfUint8 r;
    sfUint8 g;
    sfUint8 b;
    sfUint8 a;
} sfColor;


extern __declspec(dllimport)  sfColor sfBlack;
extern __declspec(dllimport)  sfColor sfWhite;
extern __declspec(dllimport)  sfColor sfRed;
extern __declspec(dllimport)  sfColor sfGreen;
extern __declspec(dllimport)  sfColor sfBlue;
extern __declspec(dllimport)  sfColor sfYellow;
extern __declspec(dllimport)  sfColor sfMagenta;
extern __declspec(dllimport)  sfColor sfCyan;
extern __declspec(dllimport)  sfColor sfTransparent;
extern __declspec(dllimport)  sfColor sfColor_fromRGB(sfUint8 red, sfUint8 green, sfUint8 blue);
extern __declspec(dllimport)  sfColor sfColor_fromRGBA(sfUint8 red, sfUint8 green, sfUint8 blue, sfUint8 alpha);










extern __declspec(dllimport)  sfColor sfColor_add(sfColor color1, sfColor color2);










extern __declspec(dllimport)  sfColor sfColor_modulate(sfColor color1, sfColor color2);






typedef struct
{
    float left;
    float top;
    float width;
    float height;
} sfFloatRect;

typedef struct
{
    int left;
    int top;
    int width;
    int height;
} sfIntRect;
extern __declspec(dllimport)  sfBool sfFloatRect_contains(const sfFloatRect* rect, float x, float y);
extern __declspec(dllimport)  sfBool sfIntRect_contains(const sfIntRect* rect, int x, int y);
extern __declspec(dllimport)  sfBool sfFloatRect_intersects(const sfFloatRect* rect1, const sfFloatRect* rect2, sfFloatRect* intersection);
extern __declspec(dllimport)  sfBool sfIntRect_intersects(const sfIntRect* rect1, const sfIntRect* rect2, sfIntRect* intersection);
typedef struct sfCircleShape sfCircleShape;
typedef struct sfConvexShape sfConvexShape;
typedef struct sfFont sfFont;
typedef struct sfImage sfImage;
typedef struct sfShader sfShader;
typedef struct sfRectangleShape sfRectangleShape;
typedef struct sfRenderTexture sfRenderTexture;
typedef struct sfRenderWindow sfRenderWindow;
typedef struct sfShape sfShape;
typedef struct sfSprite sfSprite;
typedef struct sfText sfText;
typedef struct sfTexture sfTexture;
typedef struct sfTransformable sfTransformable;
typedef struct sfVertexArray sfVertexArray;
typedef struct sfView sfView;







typedef struct
{
    float matrix[9];
} sfTransform;






extern __declspec(dllimport)  sfTransform sfTransform_Identity;
extern __declspec(dllimport)  sfTransform sfTransform_fromMatrix(float a00, float a01, float a02,
                                                      float a10, float a11, float a12,
                                                      float a20, float a21, float a22);
extern __declspec(dllimport)  void sfTransform_getMatrix(const sfTransform* transform, float* matrix);
extern __declspec(dllimport)  sfTransform sfTransform_getInverse(const sfTransform* transform);










extern __declspec(dllimport)  sfVector2f sfTransform_transformPoint(const sfTransform* transform, sfVector2f point);
extern __declspec(dllimport)  sfFloatRect sfTransform_transformRect(const sfTransform* transform, sfFloatRect rectangle);
extern __declspec(dllimport)  void sfTransform_combine(sfTransform* transform, const sfTransform* other);









extern __declspec(dllimport)  void sfTransform_translate(sfTransform* transform, float x, float y);








extern __declspec(dllimport)  void sfTransform_rotate(sfTransform* transform, float angle);
extern __declspec(dllimport)  void sfTransform_rotateWithCenter(sfTransform* transform, float angle, float centerX, float centerY);









extern __declspec(dllimport)  void sfTransform_scale(sfTransform* transform, float scaleX, float scaleY);
extern __declspec(dllimport)  void sfTransform_scaleWithCenter(sfTransform* transform, float scaleX, float scaleY, float centerX, float centerY);








extern __declspec(dllimport)  sfCircleShape* sfCircleShape_create(void);









extern __declspec(dllimport)  sfCircleShape* sfCircleShape_copy(sfCircleShape* shape);







extern __declspec(dllimport)  void sfCircleShape_destroy(sfCircleShape* shape);
extern __declspec(dllimport)  void sfCircleShape_setPosition(sfCircleShape* shape, sfVector2f position);
extern __declspec(dllimport)  void sfCircleShape_setRotation(sfCircleShape* shape, float angle);
extern __declspec(dllimport)  void sfCircleShape_setScale(sfCircleShape* shape, sfVector2f scale);
extern __declspec(dllimport)  void sfCircleShape_setOrigin(sfCircleShape* shape, sfVector2f origin);









extern __declspec(dllimport)  sfVector2f sfCircleShape_getPosition(const sfCircleShape* shape);
extern __declspec(dllimport)  float sfCircleShape_getRotation(const sfCircleShape* shape);









extern __declspec(dllimport)  sfVector2f sfCircleShape_getScale(const sfCircleShape* shape);









extern __declspec(dllimport)  sfVector2f sfCircleShape_getOrigin(const sfCircleShape* shape);
extern __declspec(dllimport)  void sfCircleShape_move(sfCircleShape* shape, sfVector2f offset);
extern __declspec(dllimport)  void sfCircleShape_rotate(sfCircleShape* shape, float angle);
extern __declspec(dllimport)  void sfCircleShape_scale(sfCircleShape* shape, sfVector2f factors);









extern __declspec(dllimport)  sfTransform sfCircleShape_getTransform(const sfCircleShape* shape);









extern __declspec(dllimport)  sfTransform sfCircleShape_getInverseTransform(const sfCircleShape* shape);
extern __declspec(dllimport)  void sfCircleShape_setTexture(sfCircleShape* shape, const sfTexture* texture, sfBool resetRect);
extern __declspec(dllimport)  void sfCircleShape_setTextureRect(sfCircleShape* shape, sfIntRect rect);
extern __declspec(dllimport)  void sfCircleShape_setFillColor(sfCircleShape* shape, sfColor color);
extern __declspec(dllimport)  void sfCircleShape_setOutlineColor(sfCircleShape* shape, sfColor color);
extern __declspec(dllimport)  void sfCircleShape_setOutlineThickness(sfCircleShape* shape, float thickness);
extern __declspec(dllimport)  const sfTexture* sfCircleShape_getTexture(const sfCircleShape* shape);









extern __declspec(dllimport)  sfIntRect sfCircleShape_getTextureRect(const sfCircleShape* shape);









extern __declspec(dllimport)  sfColor sfCircleShape_getFillColor(const sfCircleShape* shape);









extern __declspec(dllimport)  sfColor sfCircleShape_getOutlineColor(const sfCircleShape* shape);









extern __declspec(dllimport)  float sfCircleShape_getOutlineThickness(const sfCircleShape* shape);









extern __declspec(dllimport)  unsigned int sfCircleShape_getPointCount(const sfCircleShape* shape);
extern __declspec(dllimport)  sfVector2f sfCircleShape_getPoint(const sfCircleShape* shape, unsigned int index);








extern __declspec(dllimport)  void sfCircleShape_setRadius(sfCircleShape* shape, float radius);









extern __declspec(dllimport)  float sfCircleShape_getRadius(const sfCircleShape* shape);








extern __declspec(dllimport)  void sfCircleShape_setPointCount(sfCircleShape* shape, unsigned int count);
extern __declspec(dllimport)  sfFloatRect sfCircleShape_getLocalBounds(const sfCircleShape* shape);
extern __declspec(dllimport)  sfFloatRect sfCircleShape_getGlobalBounds(const sfCircleShape* shape);








extern __declspec(dllimport)  sfConvexShape* sfConvexShape_create(void);









extern __declspec(dllimport)  sfConvexShape* sfConvexShape_copy(sfConvexShape* shape);







extern __declspec(dllimport)  void sfConvexShape_destroy(sfConvexShape* shape);
extern __declspec(dllimport)  void sfConvexShape_setPosition(sfConvexShape* shape, sfVector2f position);
extern __declspec(dllimport)  void sfConvexShape_setRotation(sfConvexShape* shape, float angle);
extern __declspec(dllimport)  void sfConvexShape_setScale(sfConvexShape* shape, sfVector2f scale);
extern __declspec(dllimport)  void sfConvexShape_setOrigin(sfConvexShape* shape, sfVector2f origin);









extern __declspec(dllimport)  sfVector2f sfConvexShape_getPosition(const sfConvexShape* shape);
extern __declspec(dllimport)  float sfConvexShape_getRotation(const sfConvexShape* shape);









extern __declspec(dllimport)  sfVector2f sfConvexShape_getScale(const sfConvexShape* shape);









extern __declspec(dllimport)  sfVector2f sfConvexShape_getOrigin(const sfConvexShape* shape);
extern __declspec(dllimport)  void sfConvexShape_move(sfConvexShape* shape, sfVector2f offset);
extern __declspec(dllimport)  void sfConvexShape_rotate(sfConvexShape* shape, float angle);
extern __declspec(dllimport)  void sfConvexShape_scale(sfConvexShape* shape, sfVector2f factors);









extern __declspec(dllimport)  sfTransform sfConvexShape_getTransform(const sfConvexShape* shape);









extern __declspec(dllimport)  sfTransform sfConvexShape_getInverseTransform(const sfConvexShape* shape);
extern __declspec(dllimport)  void sfConvexShape_setTexture(sfConvexShape* shape, const sfTexture* texture, sfBool resetRect);
extern __declspec(dllimport)  void sfConvexShape_setTextureRect(sfConvexShape* shape, sfIntRect rect);
extern __declspec(dllimport)  void sfConvexShape_setFillColor(sfConvexShape* shape, sfColor color);
extern __declspec(dllimport)  void sfConvexShape_setOutlineColor(sfConvexShape* shape, sfColor color);
extern __declspec(dllimport)  void sfConvexShape_setOutlineThickness(sfConvexShape* shape, float thickness);
extern __declspec(dllimport)  const sfTexture* sfConvexShape_getTexture(const sfConvexShape* shape);









extern __declspec(dllimport)  sfIntRect sfConvexShape_getTextureRect(const sfConvexShape* shape);









extern __declspec(dllimport)  sfColor sfConvexShape_getFillColor(const sfConvexShape* shape);









extern __declspec(dllimport)  sfColor sfConvexShape_getOutlineColor(const sfConvexShape* shape);









extern __declspec(dllimport)  float sfConvexShape_getOutlineThickness(const sfConvexShape* shape);









extern __declspec(dllimport)  unsigned int sfConvexShape_getPointCount(const sfConvexShape* shape);
extern __declspec(dllimport)  sfVector2f sfConvexShape_getPoint(const sfConvexShape* shape, unsigned int index);










extern __declspec(dllimport)  void sfConvexShape_setPointCount(sfConvexShape* shape, unsigned int count);
extern __declspec(dllimport)  void sfConvexShape_setPoint(sfConvexShape* shape, unsigned int index, sfVector2f point);
extern __declspec(dllimport)  sfFloatRect sfConvexShape_getLocalBounds(const sfConvexShape* shape);
extern __declspec(dllimport)  sfFloatRect sfConvexShape_getGlobalBounds(const sfConvexShape* shape);






typedef struct
{
    int advance;
    sfIntRect bounds;
    sfIntRect textureRect;
} sfGlyph;










extern __declspec(dllimport)  sfFont* sfFont_createFromFile(const char* filename);










extern __declspec(dllimport)  sfFont* sfFont_createFromMemory(const void* data, size_t sizeInBytes);









extern __declspec(dllimport)  sfFont* sfFont_createFromStream(sfInputStream* stream);









extern __declspec(dllimport)  sfFont* sfFont_copy(sfFont* font);







extern __declspec(dllimport)  void sfFont_destroy(sfFont* font);
extern __declspec(dllimport)  sfGlyph sfFont_getGlyph(sfFont* font, sfUint32 codePoint, unsigned int characterSize, sfBool bold);
extern __declspec(dllimport)  int sfFont_getKerning(sfFont* font, sfUint32 first, sfUint32 second, unsigned int characterSize);
extern __declspec(dllimport)  int sfFont_getLineSpacing(sfFont* font, unsigned int characterSize);










extern __declspec(dllimport)  const sfTexture* sfFont_getTexture(sfFont* font, unsigned int characterSize);
extern __declspec(dllimport)  sfImage* sfImage_create(unsigned int width, unsigned int height);
extern __declspec(dllimport)  sfImage* sfImage_createFromColor(unsigned int width, unsigned int height, sfColor color);
extern __declspec(dllimport)  sfImage* sfImage_createFromPixels(unsigned int width, unsigned int height, const sfUint8* pixels);
extern __declspec(dllimport)  sfImage* sfImage_createFromFile(const char* filename);
extern __declspec(dllimport)  sfImage* sfImage_createFromMemory(const void* data, size_t size);
extern __declspec(dllimport)  sfImage* sfImage_createFromStream(sfInputStream* stream);









extern __declspec(dllimport)  sfImage* sfImage_copy(sfImage* image);







extern __declspec(dllimport)  void sfImage_destroy(sfImage* image);
extern __declspec(dllimport)  sfBool sfImage_saveToFile(const sfImage* image, const char* filename);









extern __declspec(dllimport)  sfVector2u sfImage_getSize(const sfImage* image);
extern __declspec(dllimport)  void sfImage_createMaskFromColor(sfImage* image, sfColor color, sfUint8 alpha);
extern __declspec(dllimport)  void sfImage_copyImage(sfImage* image, const sfImage* source, unsigned int destX, unsigned int destY, sfIntRect sourceRect, sfBool applyAlpha);
extern __declspec(dllimport)  void sfImage_setPixel(sfImage* image, unsigned int x, unsigned int y, sfColor color);
extern __declspec(dllimport)  sfColor sfImage_getPixel(const sfImage* image, unsigned int x, unsigned int y);
extern __declspec(dllimport)  const sfUint8* sfImage_getPixelsPtr(const sfImage* image);







extern __declspec(dllimport)  void sfImage_flipHorizontally(sfImage* image);







extern __declspec(dllimport)  void sfImage_flipVertically(sfImage* image);










typedef enum
{
    sfPoints,
    sfLines,
    sfLinesStrip,
    sfTriangles,
    sfTrianglesStrip,
    sfTrianglesFan,
    sfQuads
} sfPrimitiveType;








extern __declspec(dllimport)  sfRectangleShape* sfRectangleShape_create(void);









extern __declspec(dllimport)  sfRectangleShape* sfRectangleShape_copy(sfRectangleShape* shape);







extern __declspec(dllimport)  void sfRectangleShape_destroy(sfRectangleShape* shape);
extern __declspec(dllimport)  void sfRectangleShape_setPosition(sfRectangleShape* shape, sfVector2f position);
extern __declspec(dllimport)  void sfRectangleShape_setRotation(sfRectangleShape* shape, float angle);
extern __declspec(dllimport)  void sfRectangleShape_setScale(sfRectangleShape* shape, sfVector2f scale);
extern __declspec(dllimport)  void sfRectangleShape_setOrigin(sfRectangleShape* shape, sfVector2f origin);









extern __declspec(dllimport)  sfVector2f sfRectangleShape_getPosition(const sfRectangleShape* shape);
extern __declspec(dllimport)  float sfRectangleShape_getRotation(const sfRectangleShape* shape);









extern __declspec(dllimport)  sfVector2f sfRectangleShape_getScale(const sfRectangleShape* shape);









extern __declspec(dllimport)  sfVector2f sfRectangleShape_getOrigin(const sfRectangleShape* shape);
extern __declspec(dllimport)  void sfRectangleShape_move(sfRectangleShape* shape, sfVector2f offset);
extern __declspec(dllimport)  void sfRectangleShape_rotate(sfRectangleShape* shape, float angle);
extern __declspec(dllimport)  void sfRectangleShape_scale(sfRectangleShape* shape, sfVector2f factors);









extern __declspec(dllimport)  sfTransform sfRectangleShape_getTransform(const sfRectangleShape* shape);









extern __declspec(dllimport)  sfTransform sfRectangleShape_getInverseTransform(const sfRectangleShape* shape);
extern __declspec(dllimport)  void sfRectangleShape_setTexture(sfRectangleShape* shape, const sfTexture* texture, sfBool resetRect);
extern __declspec(dllimport)  void sfRectangleShape_setTextureRect(sfRectangleShape* shape, sfIntRect rect);
extern __declspec(dllimport)  void sfRectangleShape_setFillColor(sfRectangleShape* shape, sfColor color);
extern __declspec(dllimport)  void sfRectangleShape_setOutlineColor(sfRectangleShape* shape, sfColor color);
extern __declspec(dllimport)  void sfRectangleShape_setOutlineThickness(sfRectangleShape* shape, float thickness);
extern __declspec(dllimport)  const sfTexture* sfRectangleShape_getTexture(const sfRectangleShape* shape);









extern __declspec(dllimport)  sfIntRect sfRectangleShape_getTextureRect(const sfRectangleShape* shape);









extern __declspec(dllimport)  sfColor sfRectangleShape_getFillColor(const sfRectangleShape* shape);









extern __declspec(dllimport)  sfColor sfRectangleShape_getOutlineColor(const sfRectangleShape* shape);









extern __declspec(dllimport)  float sfRectangleShape_getOutlineThickness(const sfRectangleShape* shape);









extern __declspec(dllimport)  unsigned int sfRectangleShape_getPointCount(const sfRectangleShape* shape);
extern __declspec(dllimport)  sfVector2f sfRectangleShape_getPoint(const sfRectangleShape* shape, unsigned int index);








extern __declspec(dllimport)  void sfRectangleShape_setSize(sfRectangleShape* shape, sfVector2f size);









extern __declspec(dllimport)  sfVector2f sfRectangleShape_getSize(const sfRectangleShape* shape);
extern __declspec(dllimport)  sfFloatRect sfRectangleShape_getLocalBounds(const sfRectangleShape* shape);
extern __declspec(dllimport)  sfFloatRect sfRectangleShape_getGlobalBounds(const sfRectangleShape* shape);






typedef struct
{
    sfBlendMode blendMode;
    sfTransform transform;
    const sfTexture* texture;
    const sfShader* shader;
} sfRenderStates;





typedef struct
{
    sfVector2f position;
    sfColor color;
    sfVector2f texCoords;
} sfVertex;
extern __declspec(dllimport)  sfRenderWindow* sfRenderWindow_create(sfVideoMode mode, const char* title, sfUint32 style, const sfContextSettings* settings);








extern __declspec(dllimport)  sfRenderWindow* sfRenderWindow_createFromHandle(sfWindowHandle handle, const sfContextSettings* settings);







extern __declspec(dllimport)  void sfRenderWindow_destroy(sfRenderWindow* renderWindow);







extern __declspec(dllimport)  void sfRenderWindow_close(sfRenderWindow* renderWindow);







extern __declspec(dllimport)  sfBool sfRenderWindow_isOpen(const sfRenderWindow* renderWindow);









extern __declspec(dllimport)  sfContextSettings sfRenderWindow_getSettings(const sfRenderWindow* renderWindow);










extern __declspec(dllimport)  sfBool sfRenderWindow_pollEvent(sfRenderWindow* renderWindow, sfEvent* event);










extern __declspec(dllimport)  sfBool sfRenderWindow_waitEvent(sfRenderWindow* renderWindow, sfEvent* event);









extern __declspec(dllimport)  sfVector2i sfRenderWindow_getPosition(const sfRenderWindow* renderWindow);










extern __declspec(dllimport)  void sfRenderWindow_setPosition(sfRenderWindow* renderWindow, sfVector2i position);









extern __declspec(dllimport)  sfVector2u sfRenderWindow_getSize(const sfRenderWindow* renderWindow);








extern __declspec(dllimport)  void sfRenderWindow_setSize(sfRenderWindow* renderWindow, sfVector2u size);








extern __declspec(dllimport)  void sfRenderWindow_setTitle(sfRenderWindow* renderWindow, const char* title);










extern __declspec(dllimport)  void sfRenderWindow_setIcon(sfRenderWindow* renderWindow, unsigned int width, unsigned int height, const sfUint8* pixels);








extern __declspec(dllimport)  void sfRenderWindow_setVisible(sfRenderWindow* renderWindow, sfBool visible);








extern __declspec(dllimport)  void sfRenderWindow_setMouseCursorVisible(sfRenderWindow* renderWindow, sfBool show);








extern __declspec(dllimport)  void sfRenderWindow_setVerticalSyncEnabled(sfRenderWindow* renderWindow, sfBool enabled);










extern __declspec(dllimport)  void sfRenderWindow_setKeyRepeatEnabled(sfRenderWindow* renderWindow, sfBool enabled);










extern __declspec(dllimport)  sfBool sfRenderWindow_setActive(sfRenderWindow* renderWindow, sfBool active);







extern __declspec(dllimport)  void sfRenderWindow_display(sfRenderWindow* renderWindow);








extern __declspec(dllimport)  void sfRenderWindow_setFramerateLimit(sfRenderWindow* renderWindow, unsigned int limit);








extern __declspec(dllimport)  void sfRenderWindow_setJoystickThreshold(sfRenderWindow* renderWindow, float threshold);









extern __declspec(dllimport)  sfWindowHandle sfRenderWindow_getSystemHandle(const sfRenderWindow* renderWindow);








extern __declspec(dllimport)  void sfRenderWindow_clear(sfRenderWindow* renderWindow, sfColor color);








extern __declspec(dllimport)  void sfRenderWindow_setView(sfRenderWindow* renderWindow, const sfView* view);









extern __declspec(dllimport)  const sfView* sfRenderWindow_getView(const sfRenderWindow* renderWindow);









extern __declspec(dllimport)  const sfView* sfRenderWindow_getDefaultView(const sfRenderWindow* renderWindow);










extern __declspec(dllimport)  sfIntRect sfRenderWindow_getViewport(const sfRenderWindow* renderWindow, const sfView* view);
extern __declspec(dllimport)  sfVector2f sfRenderWindow_convertCoords(const sfRenderWindow* renderWindow, sfVector2i point, const sfView* targetView);









extern __declspec(dllimport)  void sfRenderWindow_drawSprite(sfRenderWindow* renderWindow, const sfSprite* object, const sfRenderStates* states);
extern __declspec(dllimport)  void sfRenderWindow_drawText(sfRenderWindow* renderWindow, const sfText* object, const sfRenderStates* states);
extern __declspec(dllimport)  void sfRenderWindow_drawShape(sfRenderWindow* renderWindow, const sfShape* object, const sfRenderStates* states);
extern __declspec(dllimport)  void sfRenderWindow_drawCircleShape(sfRenderWindow* renderWindow, const sfCircleShape* object, const sfRenderStates* states);
extern __declspec(dllimport)  void sfRenderWindow_drawConvexShape(sfRenderWindow* renderWindow, const sfConvexShape* object, const sfRenderStates* states);
extern __declspec(dllimport)  void sfRenderWindow_drawRectangleShape(sfRenderWindow* renderWindow, const sfRectangleShape* object, const sfRenderStates* states);
extern __declspec(dllimport)  void sfRenderWindow_drawVertexArray(sfRenderWindow* renderWindow, const sfVertexArray* object, const sfRenderStates* states);
extern __declspec(dllimport)  void sfRenderWindow_drawPrimitives(sfRenderWindow* renderWindow,
                                                      const sfVertex* vertices, unsigned int vertexCount,
                                                      sfPrimitiveType type, const sfRenderStates* states);
extern __declspec(dllimport)  void sfRenderWindow_pushGLStates(sfRenderWindow* renderWindow);










extern __declspec(dllimport)  void sfRenderWindow_popGLStates(sfRenderWindow* renderWindow);
extern __declspec(dllimport)  void sfRenderWindow_resetGLStates(sfRenderWindow* renderWindow);
extern __declspec(dllimport)  sfImage* sfRenderWindow_capture(const sfRenderWindow* renderWindow);
extern __declspec(dllimport)  sfRenderTexture* sfRenderTexture_create(unsigned int width, unsigned int height, sfBool depthBuffer);







extern __declspec(dllimport)  void sfRenderTexture_destroy(sfRenderTexture* renderTexture);









extern __declspec(dllimport)  sfVector2u sfRenderTexture_getSize(const sfRenderTexture* renderTexture);










extern __declspec(dllimport)  sfBool sfRenderTexture_setActive(sfRenderTexture* renderTexture, sfBool active);







extern __declspec(dllimport)  void sfRenderTexture_display(sfRenderTexture* renderTexture);








extern __declspec(dllimport)  void sfRenderTexture_clear(sfRenderTexture* renderTexture, sfColor color);








extern __declspec(dllimport)  void sfRenderTexture_setView(sfRenderTexture* renderTexture, const sfView* view);









extern __declspec(dllimport)  const sfView* sfRenderTexture_getView(const sfRenderTexture* renderTexture);









extern __declspec(dllimport)  const sfView* sfRenderTexture_getDefaultView(const sfRenderTexture* renderTexture);










extern __declspec(dllimport)  sfIntRect sfRenderTexture_getViewport(const sfRenderTexture* renderTexture, const sfView* view);
extern __declspec(dllimport)  sfVector2f sfRenderTexture_convertCoords(const sfRenderTexture* renderTexture, sfVector2i point, const sfView* targetView);









extern __declspec(dllimport)  void sfRenderTexture_drawSprite(sfRenderTexture* renderTexture, const sfSprite* object, const sfRenderStates* states);
extern __declspec(dllimport)  void sfRenderTexture_drawText(sfRenderTexture* renderTexture, const sfText* object, const sfRenderStates* states);
extern __declspec(dllimport)  void sfRenderTexture_drawShape(sfRenderTexture* renderTexture, const sfShape* object, const sfRenderStates* states);
extern __declspec(dllimport)  void sfRenderTexture_drawCircleShape(sfRenderTexture* renderTexture, const sfCircleShape* object, const sfRenderStates* states);
extern __declspec(dllimport)  void sfRenderTexture_drawConvexShape(sfRenderTexture* renderTexture, const sfConvexShape* object, const sfRenderStates* states);
extern __declspec(dllimport)  void sfRenderTexture_drawRectangleShape(sfRenderTexture* renderTexture, const sfRectangleShape* object, const sfRenderStates* states);
extern __declspec(dllimport)  void sfRenderTexture_drawVertexArray(sfRenderTexture* renderTexture, const sfVertexArray* object, const sfRenderStates* states);
extern __declspec(dllimport)  void sfRenderTexture_drawPrimitives(sfRenderTexture* renderTexture,
                                                       const sfVertex* vertices, unsigned int vertexCount,
                                                       sfPrimitiveType type, const sfRenderStates* states);
extern __declspec(dllimport)  void sfRenderTexture_pushGLStates(sfRenderTexture* renderTexture);










extern __declspec(dllimport)  void sfRenderTexture_popGLStates(sfRenderTexture* renderTexture);
extern __declspec(dllimport)  void sfRenderTexture_resetGLStates(sfRenderTexture* renderTexture);









extern __declspec(dllimport)  const sfTexture* sfRenderTexture_getTexture(const sfRenderTexture* renderTexture);








extern __declspec(dllimport)  void sfRenderTexture_setSmooth(sfRenderTexture* renderTexture, sfBool smooth);









extern __declspec(dllimport)  sfBool sfRenderTexture_isSmooth(const sfRenderTexture* renderTexture);
extern __declspec(dllimport)  sfShader* sfShader_createFromFile(const char* vertexShaderFilename, const char* fragmentShaderFilename);
extern __declspec(dllimport)  sfShader* sfShader_createFromMemory(const char* vertexShader, const char* fragmentShader);
extern __declspec(dllimport)  sfShader* sfShader_createFromStream(sfInputStream* vertexShaderStream, sfInputStream* fragmentShaderStream);







extern __declspec(dllimport)  void sfShader_destroy(sfShader* shader);
extern __declspec(dllimport)  void sfShader_setFloatParameter(sfShader* shader, const char* name, float x);
extern __declspec(dllimport)  void sfShader_setFloat2Parameter(sfShader* shader, const char* name, float x, float y);
extern __declspec(dllimport)  void sfShader_setFloat3Parameter(sfShader* shader, const char* name, float x, float y, float z);
extern __declspec(dllimport)  void sfShader_setFloat4Parameter(sfShader* shader, const char* name, float x, float y, float z, float w);
extern __declspec(dllimport)  void sfShader_setVector2Parameter(sfShader* shader, const char* name, sfVector2f vector);
extern __declspec(dllimport)  void sfShader_setVector3Parameter(sfShader* shader, const char* name, sfVector3f vector);
extern __declspec(dllimport)  void sfShader_setColorParameter(sfShader* shader, const char* name, sfColor color);
extern __declspec(dllimport)  void sfShader_setTransformParameter(sfShader* shader, const char* name, sfTransform transform);
extern __declspec(dllimport)  void sfShader_setTextureParameter(sfShader* shader, const char* name, const sfTexture* texture);
extern __declspec(dllimport)  void sfShader_setCurrentTextureParameter(sfShader* shader, const char* name);
extern __declspec(dllimport)  void sfShader_bind(const sfShader* shader);
extern __declspec(dllimport)  void sfShader_unbind(const sfShader* shader);
extern __declspec(dllimport)  sfBool sfShader_isAvailable(void);


typedef unsigned int (*sfShapeGetPointCountCallback)(void*);
typedef sfVector2f (*sfShapeGetPointCallback)(unsigned int, void*);
extern __declspec(dllimport)  sfShape* sfShape_create(sfShapeGetPointCountCallback getPointCount,
                                           sfShapeGetPointCallback getPoint,
                                           void* userData);







extern __declspec(dllimport)  void sfShape_destroy(sfShape* shape);
extern __declspec(dllimport)  void sfShape_setPosition(sfShape* shape, sfVector2f position);
extern __declspec(dllimport)  void sfShape_setRotation(sfShape* shape, float angle);
extern __declspec(dllimport)  void sfShape_setScale(sfShape* shape, sfVector2f scale);
extern __declspec(dllimport)  void sfShape_setOrigin(sfShape* shape, sfVector2f origin);









extern __declspec(dllimport)  sfVector2f sfShape_getPosition(const sfShape* shape);
extern __declspec(dllimport)  float sfShape_getRotation(const sfShape* shape);









extern __declspec(dllimport)  sfVector2f sfShape_getScale(const sfShape* shape);









extern __declspec(dllimport)  sfVector2f sfShape_getOrigin(const sfShape* shape);
extern __declspec(dllimport)  void sfShape_move(sfShape* shape, sfVector2f offset);
extern __declspec(dllimport)  void sfShape_rotate(sfShape* shape, float angle);
extern __declspec(dllimport)  void sfShape_scale(sfShape* shape, sfVector2f factors);









extern __declspec(dllimport)  sfTransform sfShape_getTransform(const sfShape* shape);









extern __declspec(dllimport)  sfTransform sfShape_getInverseTransform(const sfShape* shape);
extern __declspec(dllimport)  void sfShape_setTexture(sfShape* shape, const sfTexture* texture, sfBool resetRect);
extern __declspec(dllimport)  void sfShape_setTextureRect(sfShape* shape, sfIntRect rect);
extern __declspec(dllimport)  void sfShape_setFillColor(sfShape* shape, sfColor color);
extern __declspec(dllimport)  void sfShape_setOutlineColor(sfShape* shape, sfColor color);
extern __declspec(dllimport)  void sfShape_setOutlineThickness(sfShape* shape, float thickness);
extern __declspec(dllimport)  const sfTexture* sfShape_getTexture(const sfShape* shape);









extern __declspec(dllimport)  sfIntRect sfShape_getTextureRect(const sfShape* shape);









extern __declspec(dllimport)  sfColor sfShape_getFillColor(const sfShape* shape);









extern __declspec(dllimport)  sfColor sfShape_getOutlineColor(const sfShape* shape);









extern __declspec(dllimport)  float sfShape_getOutlineThickness(const sfShape* shape);









extern __declspec(dllimport)  unsigned int sfShape_getPointCount(const sfShape* shape);
extern __declspec(dllimport)  sfVector2f sfShape_getPoint(const sfShape* shape, unsigned int index);
extern __declspec(dllimport)  sfFloatRect sfShape_getLocalBounds(const sfShape* shape);
extern __declspec(dllimport)  sfFloatRect sfShape_getGlobalBounds(const sfShape* shape);









extern __declspec(dllimport)  void sfShape_update(sfShape* shape);








extern __declspec(dllimport)  sfSprite* sfSprite_create(void);









extern __declspec(dllimport)  sfSprite* sfSprite_copy(sfSprite* sprite);







extern __declspec(dllimport)  void sfSprite_destroy(sfSprite* sprite);
extern __declspec(dllimport)  void sfSprite_setPosition(sfSprite* sprite, sfVector2f position);
extern __declspec(dllimport)  void sfSprite_setRotation(sfSprite* sprite, float angle);
extern __declspec(dllimport)  void sfSprite_setScale(sfSprite* sprite, sfVector2f scale);
extern __declspec(dllimport)  void sfSprite_setOrigin(sfSprite* sprite, sfVector2f origin);









extern __declspec(dllimport)  sfVector2f sfSprite_getPosition(const sfSprite* sprite);
extern __declspec(dllimport)  float sfSprite_getRotation(const sfSprite* sprite);









extern __declspec(dllimport)  sfVector2f sfSprite_getScale(const sfSprite* sprite);









extern __declspec(dllimport)  sfVector2f sfSprite_getOrigin(const sfSprite* sprite);
extern __declspec(dllimport)  void sfSprite_move(sfSprite* sprite, sfVector2f offset);
extern __declspec(dllimport)  void sfSprite_rotate(sfSprite* sprite, float angle);
extern __declspec(dllimport)  void sfSprite_scale(sfSprite* sprite, sfVector2f factors);









extern __declspec(dllimport)  sfTransform sfSprite_getTransform(const sfSprite* sprite);









extern __declspec(dllimport)  sfTransform sfSprite_getInverseTransform(const sfSprite* sprite);
extern __declspec(dllimport)  void sfSprite_setTexture(sfSprite* sprite, const sfTexture* texture, sfBool resetRect);
extern __declspec(dllimport)  void sfSprite_setTextureRect(sfSprite* sprite, sfIntRect rectangle);
extern __declspec(dllimport)  void sfSprite_setColor(sfSprite* sprite, sfColor color);
extern __declspec(dllimport)  const sfTexture* sfSprite_getTexture(const sfSprite* sprite);









extern __declspec(dllimport)  sfIntRect sfSprite_getTextureRect(const sfSprite* sprite);









extern __declspec(dllimport)  sfColor sfSprite_getColor(const sfSprite* sprite);
extern __declspec(dllimport)  sfFloatRect sfSprite_getLocalBounds(const sfSprite* sprite);
extern __declspec(dllimport)  sfFloatRect sfSprite_getGlobalBounds(const sfSprite* sprite);





typedef enum
{
    sfTextRegular = 0,
    sfTextBold = 1 << 0,
    sfTextItalic = 1 << 1,
    sfTextUnderlined = 1 << 2
} sfTextStyle;








extern __declspec(dllimport)  sfText* sfText_create(void);









extern __declspec(dllimport)  sfText* sfText_copy(sfText* text);







extern __declspec(dllimport)  void sfText_destroy(sfText* text);
extern __declspec(dllimport)  void sfText_setPosition(sfText* text, sfVector2f position);
extern __declspec(dllimport)  void sfText_setRotation(sfText* text, float angle);
extern __declspec(dllimport)  void sfText_setScale(sfText* text, sfVector2f scale);
extern __declspec(dllimport)  void sfText_setOrigin(sfText* text, sfVector2f origin);









extern __declspec(dllimport)  sfVector2f sfText_getPosition(const sfText* text);
extern __declspec(dllimport)  float sfText_getRotation(const sfText* text);









extern __declspec(dllimport)  sfVector2f sfText_getScale(const sfText* text);









extern __declspec(dllimport)  sfVector2f sfText_getOrigin(const sfText* text);
extern __declspec(dllimport)  void sfText_move(sfText* text, sfVector2f offset);
extern __declspec(dllimport)  void sfText_rotate(sfText* text, float angle);
extern __declspec(dllimport)  void sfText_scale(sfText* text, sfVector2f factors);









extern __declspec(dllimport)  sfTransform sfText_getTransform(const sfText* text);









extern __declspec(dllimport)  sfTransform sfText_getInverseTransform(const sfText* text);










extern __declspec(dllimport)  void sfText_setString(sfText* text, const char* string);








extern __declspec(dllimport)  void sfText_setUnicodeString(sfText* text, const sfUint32* string);
extern __declspec(dllimport)  void sfText_setFont(sfText* text, const sfFont* font);










extern __declspec(dllimport)  void sfText_setCharacterSize(sfText* text, unsigned int size);
extern __declspec(dllimport)  void sfText_setStyle(sfText* text, sfUint32 style);










extern __declspec(dllimport)  void sfText_setColor(sfText* text, sfColor color);









extern __declspec(dllimport)  const char* sfText_getString(const sfText* text);









extern __declspec(dllimport)  const sfUint32* sfText_getUnicodeString(const sfText* text);
extern __declspec(dllimport)  const sfFont* sfText_getFont(const sfText* text);









extern __declspec(dllimport)  unsigned int sfText_getCharacterSize(const sfText* text);









extern __declspec(dllimport)  sfUint32 sfText_getStyle(const sfText* text);









extern __declspec(dllimport)  sfColor sfText_getColor(const sfText* text);
extern __declspec(dllimport)  sfVector2f sfText_findCharacterPos(const sfText* text, size_t index);
extern __declspec(dllimport)  sfFloatRect sfText_getLocalBounds(const sfText* text);
extern __declspec(dllimport)  sfFloatRect sfText_getGlobalBounds(const sfText* text);
extern __declspec(dllimport)  sfTexture* sfTexture_create(unsigned int width, unsigned int height);










extern __declspec(dllimport)  sfTexture* sfTexture_createFromFile(const char* filename, const sfIntRect* area);
extern __declspec(dllimport)  sfTexture* sfTexture_createFromMemory(const void* data, size_t sizeInBytes, const sfIntRect* area);










extern __declspec(dllimport)  sfTexture* sfTexture_createFromStream(sfInputStream* stream, const sfIntRect* area);










extern __declspec(dllimport)  sfTexture* sfTexture_createFromImage(const sfImage* image, const sfIntRect* area);









extern __declspec(dllimport)  sfTexture* sfTexture_copy(sfTexture* texture);







extern __declspec(dllimport)  void sfTexture_destroy(sfTexture* texture);









extern __declspec(dllimport)  sfVector2u sfTexture_getSize(const sfTexture* texture);









extern __declspec(dllimport)  sfImage* sfTexture_copyToImage(const sfTexture* texture);
extern __declspec(dllimport)  void sfTexture_updateFromPixels(sfTexture* texture, const sfUint8* pixels, unsigned int width, unsigned int height, unsigned int x, unsigned int y);










extern __declspec(dllimport)  void sfTexture_updateFromImage(sfTexture* texture, const sfImage* image, unsigned int x, unsigned int y);










extern __declspec(dllimport)  void sfTexture_updateFromWindow(sfTexture* texture, const sfWindow* window, unsigned int x, unsigned int y);










extern __declspec(dllimport)  void sfTexture_updateFromRenderWindow(sfTexture* texture, const sfRenderWindow* renderWindow, unsigned int x, unsigned int y);







extern __declspec(dllimport)  void sfTexture_bind(const sfTexture* texture);








extern __declspec(dllimport)  void sfTexture_setSmooth(sfTexture* texture, sfBool smooth);









extern __declspec(dllimport)  sfBool sfTexture_isSmooth(const sfTexture* texture);
extern __declspec(dllimport)  void sfTexture_setRepeated(sfTexture* texture, sfBool repeated);









extern __declspec(dllimport)  sfBool sfTexture_isRepeated(const sfTexture* texture);







extern __declspec(dllimport)  unsigned int sfTexture_getMaximumSize();








extern __declspec(dllimport)  sfTransformable* sfTransformable_create(void);









extern __declspec(dllimport)  sfTransformable* sfTransformable_copy(sfTransformable* transformable);







extern __declspec(dllimport)  void sfTransformable_destroy(sfTransformable* transformable);
extern __declspec(dllimport)  void sfTransformable_setPosition(sfTransformable* transformable, sfVector2f position);
extern __declspec(dllimport)  void sfTransformable_setRotation(sfTransformable* transformable, float angle);
extern __declspec(dllimport)  void sfTransformable_setScale(sfTransformable* transformable, sfVector2f scale);
extern __declspec(dllimport)  void sfTransformable_setOrigin(sfTransformable* transformable, sfVector2f origin);









extern __declspec(dllimport)  sfVector2f sfTransformable_getPosition(const sfTransformable* transformable);
extern __declspec(dllimport)  float sfTransformable_getRotation(const sfTransformable* transformable);









extern __declspec(dllimport)  sfVector2f sfTransformable_getScale(const sfTransformable* transformable);









extern __declspec(dllimport)  sfVector2f sfTransformable_getOrigin(const sfTransformable* transformable);
extern __declspec(dllimport)  void sfTransformable_move(sfTransformable* transformable, sfVector2f offset);
extern __declspec(dllimport)  void sfTransformable_rotate(sfTransformable* transformable, float angle);
extern __declspec(dllimport)  void sfTransformable_scale(sfTransformable* transformable, sfVector2f factors);









extern __declspec(dllimport)  sfTransform sfTransformable_getTransform(const sfTransformable* transformable);









extern __declspec(dllimport)  sfTransform sfTransformable_getInverseTransform(const sfTransformable* transformable);








extern __declspec(dllimport)  sfVertexArray* sfVertexArray_create(void);









extern __declspec(dllimport)  sfVertexArray* sfVertexArray_copy(sfVertexArray* vertexArray);







extern __declspec(dllimport)  void sfVertexArray_destroy(sfVertexArray* vertexArray);









extern __declspec(dllimport)  unsigned int sfVertexArray_getVertexCount(const sfVertexArray* vertexArray);
extern __declspec(dllimport)  sfVertex* sfVertexArray_getVertex(sfVertexArray* vertexArray, unsigned int index);
extern __declspec(dllimport)  void sfVertexArray_clear(sfVertexArray* vertexArray);
extern __declspec(dllimport)  void sfVertexArray_resize(sfVertexArray* vertexArray, unsigned int vertexCount);








extern __declspec(dllimport)  void sfVertexArray_append(sfVertexArray* vertexArray, sfVertex vertex);
extern __declspec(dllimport)  void sfVertexArray_setPrimitiveType(sfVertexArray* vertexArray, sfPrimitiveType type);









extern __declspec(dllimport)  sfPrimitiveType sfVertexArray_getPrimitiveType(sfVertexArray* vertexArray);
extern __declspec(dllimport)  sfFloatRect sfVertexArray_getBounds(sfVertexArray* vertexArray);










extern __declspec(dllimport)  sfView* sfView_create(void);









extern __declspec(dllimport)  sfView* sfView_createFromRect(sfFloatRect rectangle);









extern __declspec(dllimport)  sfView* sfView_copy(sfView* view);







extern __declspec(dllimport)  void sfView_destroy(sfView* view);








extern __declspec(dllimport)  void sfView_setCenter(sfView* view, sfVector2f center);








extern __declspec(dllimport)  void sfView_setSize(sfView* view, sfVector2f size);










extern __declspec(dllimport)  void sfView_setRotation(sfView* view, float angle);
extern __declspec(dllimport)  void sfView_setViewport(sfView* view, sfFloatRect viewport);










extern __declspec(dllimport)  void sfView_reset(sfView* view, sfFloatRect rectangle);









extern __declspec(dllimport)  sfVector2f sfView_getCenter(const sfView* view);









extern __declspec(dllimport)  sfVector2f sfView_getSize(const sfView* view);









extern __declspec(dllimport)  float sfView_getRotation(const sfView* view);









extern __declspec(dllimport)  sfFloatRect sfView_getViewport(const sfView* view);








extern __declspec(dllimport)  void sfView_move(sfView* view, sfVector2f offset);








extern __declspec(dllimport)  void sfView_rotate(sfView* view, float angle);
extern __declspec(dllimport)  void sfView_zoom(sfView* view, float factor);
typedef int (  * _onexit_t)(void);
typedef struct _div_t {
        int quot;
        int rem;
} div_t;

typedef struct _ldiv_t {
        long quot;
        long rem;
} ldiv_t;
typedef struct {
    unsigned char ld[10];
} _LDOUBLE;
typedef struct {
        double x;
} _CRT_DOUBLE;

typedef struct {
    float f;
} _CRT_FLOAT;


typedef struct {
        long double x;
} _LONGDOUBLE;
typedef struct {
    unsigned char ld12[12];
} _LDBL12;
 extern int __mb_cur_max;
 int   ___mb_cur_max_func(void);
 int   ___mb_cur_max_l_func(_locale_t);
typedef void (  *_purecall_handler)(void);


 _purecall_handler   _set_purecall_handler(   _purecall_handler _Handler);
 _purecall_handler   _get_purecall_handler();
typedef void (  *_invalid_parameter_handler)(const wchar_t *, const wchar_t *, const wchar_t *, unsigned int, uintptr_t);


 _invalid_parameter_handler   _set_invalid_parameter_handler(   _invalid_parameter_handler _Handler);
 _invalid_parameter_handler   _get_invalid_parameter_handler(void);
 unsigned long *   __doserrno(void);


errno_t   _set_doserrno(  unsigned long _Value);
errno_t   _get_doserrno(  unsigned long * _Value);


  __declspec(deprecated)  char **   __sys_errlist(void);


  __declspec(deprecated)  int *   __sys_nerr(void);
 extern int __argc;
 extern char ** __argv;
 extern wchar_t ** __wargv;
 extern char ** _environ;
 extern wchar_t ** _wenviron;


__declspec(deprecated)    extern char * _pgmptr;
__declspec(deprecated)    extern wchar_t * _wpgmptr;
errno_t   _get_pgmptr(     char ** _Value);
errno_t   _get_wpgmptr(     wchar_t ** _Value);



__declspec(deprecated)    extern int _fmode;
 errno_t   _set_fmode(  int _Mode);
 errno_t   _get_fmode(  int * _PMode);
 __declspec(noreturn) void   exit(  int _Code);
 __declspec(noreturn) void   _exit(  int _Code);
 void   abort(void);


 unsigned int   _set_abort_behavior(  unsigned int _Flags,   unsigned int _Mask);



        int   abs(  int _X);
        long   labs(  long _X);


        __int64   _abs64(__int64);
        int   atexit(void (  *)(void));



   double   atof(   const char *_String);
   double   _atof_l(   const char *_String,    _locale_t _Locale);

     int   atoi(   const char *_Str);
   int   _atoi_l(   const char *_Str,    _locale_t _Locale);
   long   atol(   const char *_Str);
   long   _atol_l(   const char *_Str,    _locale_t _Locale);



   void *   bsearch_s(  const void * _Key,    const void * _Base,
         rsize_t _NumOfElements,   rsize_t _SizeOfElements,
         int (  * _PtFuncCompare)(void *, const void *, const void *), void * _Context);

   void *   bsearch(  const void * _Key,    const void * _Base,
         size_t _NumOfElements,   size_t _SizeOfElements,
         int (  * _PtFuncCompare)(const void *, const void *));


 void   qsort_s(   void * _Base,
         rsize_t _NumOfElements,   rsize_t _SizeOfElements,
         int (  * _PtFuncCompare)(void *, const void *, const void *), void *_Context);

 void   qsort(   void * _Base,
	 size_t _NumOfElements,   size_t _SizeOfElements,
         int (  * _PtFuncCompare)(const void *, const void *));

         unsigned short   _byteswap_ushort(  unsigned short _Short);
         unsigned long   _byteswap_ulong (  unsigned long _Long);
         unsigned __int64   _byteswap_uint64(  unsigned __int64 _Int64);
   div_t   div(  int _Numerator,   int _Denominator);
    __declspec(deprecated)  char *   getenv(   const char * _VarName);

   errno_t   getenv_s(  size_t * _ReturnSize,     char * _DstBuf,   rsize_t _DstSize,    const char * _VarName);


   errno_t   _dupenv_s(    char **_PBuffer,   size_t * _PBufferSizeInBytes,    const char * _VarName);
   errno_t   _itoa_s(  int _Value,     char * _DstBuf,   size_t _Size,   int _Radix);

__declspec(deprecated)  char *  _itoa(int _Value,  char *_Dest, int _Radix);
   errno_t   _i64toa_s(  __int64 _Val,     char * _DstBuf,   size_t _Size,   int _Radix);
  __declspec(deprecated)  char *   _i64toa(  __int64 _Val,     char * _DstBuf,   int _Radix);
   errno_t   _ui64toa_s(  unsigned __int64 _Val,     char * _DstBuf,   size_t _Size,   int _Radix);
  __declspec(deprecated)  char *   _ui64toa(  unsigned __int64 _Val,     char * _DstBuf,   int _Radix);
   __int64   _atoi64(   const char * _String);
   __int64   _atoi64_l(   const char * _String,    _locale_t _Locale);
   __int64   _strtoi64(   const char * _String,     char ** _EndPtr,   int _Radix);
   __int64   _strtoi64_l(   const char * _String,     char ** _EndPtr,   int _Radix,    _locale_t _Locale);
   unsigned __int64   _strtoui64(   const char * _String,     char ** _EndPtr,   int _Radix);
   unsigned __int64   _strtoui64_l(   const char * _String,     char ** _EndPtr,   int _Radix,    _locale_t _Locale);
   ldiv_t   ldiv(  long _Numerator,   long _Denominator);
   errno_t   _ltoa_s(  long _Val,     char * _DstBuf,   size_t _Size,   int _Radix);

__declspec(deprecated)  char *  _ltoa(long _Value,  char *_Dest, int _Radix);
   int   mblen(     const char * _Ch,   size_t _MaxCount);
   int   _mblen_l(     const char * _Ch,   size_t _MaxCount,    _locale_t _Locale);
   size_t   _mbstrlen(   const char * _Str);
   size_t   _mbstrlen_l(   const char *_Str,    _locale_t _Locale);
   size_t   _mbstrnlen(   const char *_Str,   size_t _MaxCount);
   size_t   _mbstrnlen_l(   const char *_Str,   size_t _MaxCount,    _locale_t _Locale);
 int   mbtowc(    wchar_t * _DstCh,      const char * _SrcCh,   size_t _SrcSizeInBytes);
 int   _mbtowc_l(    wchar_t * _DstCh,      const char * _SrcCh,   size_t _SrcSizeInBytes,    _locale_t _Locale);
   errno_t   mbstowcs_s(  size_t * _PtNumOfCharConverted,     wchar_t * _DstBuf,   size_t _SizeInWords,      const char * _SrcBuf,   size_t _MaxCount );

__declspec(deprecated)  size_t  mbstowcs( wchar_t *_Dest, const char * _Source, size_t _MaxCount);

   errno_t   _mbstowcs_s_l(  size_t * _PtNumOfCharConverted,     wchar_t * _DstBuf,   size_t _SizeInWords,      const char * _SrcBuf,   size_t _MaxCount,    _locale_t _Locale);

__declspec(deprecated)  size_t  _mbstowcs_l(    wchar_t *_Dest,    const char * _Source,   size_t _MaxCount,    _locale_t _Locale);

   int   rand(void);
   int   _set_error_mode(  int _Mode);

 void   srand(  unsigned int _Seed);
   double   strtod(   const char * _Str,     char ** _EndPtr);
   double   _strtod_l(   const char * _Str,     char ** _EndPtr,    _locale_t _Locale);
   long   strtol(   const char * _Str,     char ** _EndPtr,   int _Radix );
   long   _strtol_l(   const char *_Str,     char **_EndPtr,   int _Radix,    _locale_t _Locale);
   unsigned long   strtoul(   const char * _Str,     char ** _EndPtr,   int _Radix);
   unsigned long   _strtoul_l(const char * _Str,     char **_EndPtr,   int _Radix,    _locale_t _Locale);


 int   system(   const char * _Command);

   errno_t   _ultoa_s(  unsigned long _Val,     char * _DstBuf,   size_t _Size,   int _Radix);

__declspec(deprecated)  char *  _ultoa(unsigned long _Value,  char *_Dest, int _Radix);
  __declspec(deprecated)  int   wctomb(    char * _MbCh,   wchar_t _WCh);
  __declspec(deprecated)  int   _wctomb_l(    char * _MbCh,   wchar_t _WCh,    _locale_t _Locale);

   errno_t   wctomb_s(  int * _SizeConverted,     char * _MbCh,   rsize_t _SizeInBytes,   wchar_t _WCh);

   errno_t   _wctomb_s_l(  int * _SizeConverted,     char * _MbCh,   size_t _SizeInBytes,   wchar_t _WCh,    _locale_t _Locale);
   errno_t   wcstombs_s(  size_t * _PtNumOfCharConverted,     char * _Dst,   size_t _DstSizeInBytes,    const wchar_t * _Src,   size_t _MaxCountInBytes);

__declspec(deprecated)  size_t  wcstombs( char *_Dest, const wchar_t * _Source, size_t _MaxCount);
   errno_t   _wcstombs_s_l(  size_t * _PtNumOfCharConverted,     char * _Dst,   size_t _DstSizeInBytes,    const wchar_t * _Src,   size_t _MaxCountInBytes,    _locale_t _Locale);

__declspec(deprecated)  size_t  _wcstombs_l(    char *_Dest,    const wchar_t * _Source,   size_t _MaxCount,    _locale_t _Locale);
           void *   calloc(  size_t _NumOfElements,   size_t _SizeOfElements);
   void   free(   void * _Memory);
           void *   malloc(  size_t _Size);
         void *   realloc(   void * _Memory,   size_t _NewSize);
         void *   _recalloc(   void * _Memory,   size_t _Count,   size_t _Size);
   void   _aligned_free(   void * _Memory);
         void *   _aligned_malloc(  size_t _Size,   size_t _Alignment);
         void *   _aligned_offset_malloc(  size_t _Size,   size_t _Alignment,   size_t _Offset);
         void *   _aligned_realloc(   void * _Memory,   size_t _NewSize,   size_t _Alignment);
         void *   _aligned_recalloc(   void * _Memory,   size_t _Count,   size_t _Size,   size_t _Alignment);
         void *   _aligned_offset_realloc(   void * _Memory,   size_t _NewSize,   size_t _Alignment,   size_t _Offset);
         void *   _aligned_offset_recalloc(   void * _Memory,   size_t _Count,   size_t _Size,   size_t _Alignment,   size_t _Offset);
   size_t   _aligned_msize(  void * _Memory,   size_t _Alignment,   size_t _Offset);
   errno_t   _itow_s (  int _Val,     wchar_t * _DstBuf,   size_t _SizeInWords,   int _Radix);

__declspec(deprecated)  wchar_t *  _itow(int _Value,  wchar_t *_Dest, int _Radix);
   errno_t   _ltow_s (  long _Val,     wchar_t * _DstBuf,   size_t _SizeInWords,   int _Radix);

__declspec(deprecated)  wchar_t *  _ltow(long _Value,  wchar_t *_Dest, int _Radix);
   errno_t   _ultow_s (  unsigned long _Val,     wchar_t * _DstBuf,   size_t _SizeInWords,   int _Radix);

__declspec(deprecated)  wchar_t *  _ultow(unsigned long _Value,  wchar_t *_Dest, int _Radix);
   double   wcstod(   const wchar_t * _Str,     wchar_t ** _EndPtr);
   double   _wcstod_l(   const wchar_t *_Str,     wchar_t ** _EndPtr,    _locale_t _Locale);
   long   wcstol(   const wchar_t *_Str,     wchar_t ** _EndPtr, int _Radix);
   long   _wcstol_l(   const wchar_t *_Str,     wchar_t **_EndPtr, int _Radix,    _locale_t _Locale);
   unsigned long   wcstoul(   const wchar_t *_Str,     wchar_t ** _EndPtr, int _Radix);
   unsigned long   _wcstoul_l(   const wchar_t *_Str,     wchar_t **_EndPtr, int _Radix,    _locale_t _Locale);
    __declspec(deprecated)  wchar_t *   _wgetenv(   const wchar_t * _VarName);
   errno_t   _wgetenv_s(  size_t * _ReturnSize,     wchar_t * _DstBuf,   size_t _DstSizeInWords,    const wchar_t * _VarName);

   errno_t   _wdupenv_s(    wchar_t **_Buffer,   size_t *_BufferSizeInWords,    const wchar_t *_VarName);
 int   _wsystem(   const wchar_t * _Command);

   double   _wtof(   const wchar_t *_Str);
   double   _wtof_l(   const wchar_t *_Str,    _locale_t _Locale);
   int   _wtoi(   const wchar_t *_Str);
   int   _wtoi_l(   const wchar_t *_Str,    _locale_t _Locale);
   long   _wtol(   const wchar_t *_Str);
   long   _wtol_l(   const wchar_t *_Str,    _locale_t _Locale);

   errno_t   _i64tow_s(  __int64 _Val,     wchar_t * _DstBuf,   size_t _SizeInWords,   int _Radix);
  __declspec(deprecated)  wchar_t *   _i64tow(  __int64 _Val,     wchar_t * _DstBuf,   int _Radix);
   errno_t   _ui64tow_s(  unsigned __int64 _Val,     wchar_t * _DstBuf,   size_t _SizeInWords,   int _Radix);
  __declspec(deprecated)  wchar_t *   _ui64tow(  unsigned __int64 _Val,     wchar_t * _DstBuf,   int _Radix);
   __int64   _wtoi64(   const wchar_t *_Str);
   __int64   _wtoi64_l(   const wchar_t *_Str,    _locale_t _Locale);
   __int64   _wcstoi64(   const wchar_t * _Str,     wchar_t ** _EndPtr,   int _Radix);
   __int64   _wcstoi64_l(   const wchar_t * _Str,     wchar_t ** _EndPtr,   int _Radix,    _locale_t _Locale);
   unsigned __int64   _wcstoui64(   const wchar_t * _Str,     wchar_t ** _EndPtr,   int _Radix);
   unsigned __int64   _wcstoui64_l(   const wchar_t *_Str ,     wchar_t ** _EndPtr,   int _Radix,    _locale_t _Locale);
   char *   _fullpath(    char * _FullPath,    const char * _Path,   size_t _SizeInBytes);
   errno_t   _ecvt_s(    char * _DstBuf,   size_t _Size,   double _Val,   int _NumOfDights,   int * _PtDec,   int * _PtSign);

    __declspec(deprecated)  char *   _ecvt(  double _Val,   int _NumOfDigits,   int * _PtDec,   int * _PtSign);
   errno_t   _fcvt_s(    char * _DstBuf,   size_t _Size,   double _Val,   int _NumOfDec,   int * _PtDec,   int * _PtSign);

    __declspec(deprecated)  char *   _fcvt(  double _Val,   int _NumOfDec,   int * _PtDec,   int * _PtSign);
 errno_t   _gcvt_s(    char * _DstBuf,   size_t _Size,   double _Val,   int _NumOfDigits);

  __declspec(deprecated)  char *   _gcvt(  double _Val,   int _NumOfDigits,     char * _DstBuf);

   int   _atodbl(  _CRT_DOUBLE * _Result,    char * _Str);
   int   _atoldbl(  _LDOUBLE * _Result,    char * _Str);
   int   _atoflt(  _CRT_FLOAT * _Result,    char * _Str);
   int   _atodbl_l(  _CRT_DOUBLE * _Result,    char * _Str,    _locale_t _Locale);
   int   _atoldbl_l(  _LDOUBLE * _Result,    char * _Str,    _locale_t _Locale);
   int   _atoflt_l(  _CRT_FLOAT * _Result,    char * _Str,    _locale_t _Locale);
         unsigned long   _lrotl(  unsigned long _Val,   int _Shift);
         unsigned long   _lrotr(  unsigned long _Val,   int _Shift);
   errno_t   _makepath_s(    char * _PathResult,   size_t _SizeInWords,    const char * _Drive,    const char * _Dir,    const char * _Filename,
         const char * _Ext);

__declspec(deprecated)  void  _makepath( char *_Path, const char * _Drive, const char * _Dir, const char * _Filename, const char * _Ext);
        _onexit_t   _onexit(   _onexit_t _Func);




 void   perror(   const char * _ErrMsg);
   int   _putenv(   const char * _EnvString);
   errno_t   _putenv_s(   const char * _Name,    const char * _Value);
         unsigned int   _rotl(  unsigned int _Val,   int _Shift);
         unsigned __int64   _rotl64(  unsigned __int64 _Val,   int _Shift);
         unsigned int   _rotr(  unsigned int _Val,   int _Shift);
         unsigned __int64   _rotr64(  unsigned __int64 _Val,   int _Shift);

 errno_t   _searchenv_s(   const char * _Filename,    const char * _EnvVar,     char * _ResultPath,   size_t _SizeInBytes);

__declspec(deprecated)  void  _searchenv(const char * _Filename, const char * _EnvVar,  char *_ResultPath);

__declspec(deprecated)    void   _splitpath(   const char * _FullPath,     char * _Drive,     char * _Dir,     char * _Filename,     char * _Ext);
   errno_t   _splitpath_s(   const char * _FullPath,
		 char * _Drive,   size_t _DriveSize,
		 char * _Dir,   size_t _DirSize,
		 char * _Filename,   size_t _FilenameSize,
		 char * _Ext,   size_t _ExtSize);


 void   _swab(     char * _Buf1,      char * _Buf2, int _SizeInBytes);
   wchar_t *   _wfullpath(    wchar_t * _FullPath,    const wchar_t * _Path,   size_t _SizeInWords);
   errno_t   _wmakepath_s(    wchar_t * _PathResult,   size_t _SIZE,    const wchar_t * _Drive,    const wchar_t * _Dir,    const wchar_t * _Filename,
         const wchar_t * _Ext);

__declspec(deprecated)  void  _wmakepath( wchar_t *_ResultPath, const wchar_t * _Drive, const wchar_t * _Dir, const wchar_t * _Filename, const wchar_t * _Ext);


 void   _wperror(   const wchar_t * _ErrMsg);

   int   _wputenv(   const wchar_t * _EnvString);
   errno_t   _wputenv_s(   const wchar_t * _Name,    const wchar_t * _Value);
 errno_t   _wsearchenv_s(   const wchar_t * _Filename,    const wchar_t * _EnvVar,     wchar_t * _ResultPath,   size_t _SizeInWords);

__declspec(deprecated)  void  _wsearchenv(const wchar_t * _Filename, const wchar_t * _EnvVar,  wchar_t *_ResultPath);
__declspec(deprecated)    void   _wsplitpath(   const wchar_t * _FullPath,     wchar_t * _Drive,     wchar_t * _Dir,     wchar_t * _Filename,     wchar_t * _Ext);
 errno_t   _wsplitpath_s(   const wchar_t * _FullPath,
		 wchar_t * _Drive,   size_t _DriveSize,
		 wchar_t * _Dir,   size_t _DirSize,
		 wchar_t * _Filename,   size_t _FilenameSize,
		 wchar_t * _Ext,   size_t _ExtSize);






__declspec(deprecated)    void   _seterrormode(  int _Mode);
__declspec(deprecated)    void   _beep(  unsigned _Frequency,   unsigned _Duration);
__declspec(deprecated)    void   _sleep(  unsigned long _Duration);
typedef unsigned int u_int;
typedef u_int SOCKET;

enum
{
    ENET_SOCKET_NULL = -1
};
typedef struct
{
    size_t dataLength;
    void * data;
} ENetBuffer;
typedef struct fd_set {
        u_int fd_count;
        SOCKET fd_array[64];
} fd_set;
typedef SOCKET ENetSocket;
typedef fd_set ENetSocketSet;
typedef unsigned char enet_uint8;
typedef unsigned short enet_uint16;
typedef unsigned int enet_uint32;

enum
{
   ENET_PROTOCOL_MINIMUM_MTU = 576,
   ENET_PROTOCOL_MAXIMUM_MTU = 4096,
   ENET_PROTOCOL_MAXIMUM_PACKET_COMMANDS = 32,
   ENET_PROTOCOL_MINIMUM_WINDOW_SIZE = 4096,
   ENET_PROTOCOL_MAXIMUM_WINDOW_SIZE = 32768,
   ENET_PROTOCOL_MINIMUM_CHANNEL_COUNT = 1,
   ENET_PROTOCOL_MAXIMUM_CHANNEL_COUNT = 255,
   ENET_PROTOCOL_MAXIMUM_PEER_ID = 0xFFF
};

typedef enum _ENetProtocolCommand
{
   ENET_PROTOCOL_COMMAND_NONE = 0,
   ENET_PROTOCOL_COMMAND_ACKNOWLEDGE = 1,
   ENET_PROTOCOL_COMMAND_CONNECT = 2,
   ENET_PROTOCOL_COMMAND_VERIFY_CONNECT = 3,
   ENET_PROTOCOL_COMMAND_DISCONNECT = 4,
   ENET_PROTOCOL_COMMAND_PING = 5,
   ENET_PROTOCOL_COMMAND_SEND_RELIABLE = 6,
   ENET_PROTOCOL_COMMAND_SEND_UNRELIABLE = 7,
   ENET_PROTOCOL_COMMAND_SEND_FRAGMENT = 8,
   ENET_PROTOCOL_COMMAND_SEND_UNSEQUENCED = 9,
   ENET_PROTOCOL_COMMAND_BANDWIDTH_LIMIT = 10,
   ENET_PROTOCOL_COMMAND_THROTTLE_CONFIGURE = 11,
   ENET_PROTOCOL_COMMAND_SEND_UNRELIABLE_FRAGMENT = 12,
   ENET_PROTOCOL_COMMAND_COUNT = 13,

   ENET_PROTOCOL_COMMAND_MASK = 0x0F
} ENetProtocolCommand;

typedef enum _ENetProtocolFlag
{
   ENET_PROTOCOL_COMMAND_FLAG_ACKNOWLEDGE = (1 << 7),
   ENET_PROTOCOL_COMMAND_FLAG_UNSEQUENCED = (1 << 6),

   ENET_PROTOCOL_HEADER_FLAG_COMPRESSED = (1 << 14),
   ENET_PROTOCOL_HEADER_FLAG_SENT_TIME = (1 << 15),
   ENET_PROTOCOL_HEADER_FLAG_MASK = ENET_PROTOCOL_HEADER_FLAG_COMPRESSED | ENET_PROTOCOL_HEADER_FLAG_SENT_TIME,

   ENET_PROTOCOL_HEADER_SESSION_MASK = (3 << 12),
   ENET_PROTOCOL_HEADER_SESSION_SHIFT = 12
} ENetProtocolFlag;










typedef struct _ENetProtocolHeader
{
   enet_uint16 peerID;
   enet_uint16 sentTime;
}   ENetProtocolHeader;

typedef struct _ENetProtocolCommandHeader
{
   enet_uint8 command;
   enet_uint8 channelID;
   enet_uint16 reliableSequenceNumber;
}   ENetProtocolCommandHeader;

typedef struct _ENetProtocolAcknowledge
{
   ENetProtocolCommandHeader header;
   enet_uint16 receivedReliableSequenceNumber;
   enet_uint16 receivedSentTime;
}   ENetProtocolAcknowledge;

typedef struct _ENetProtocolConnect
{
   ENetProtocolCommandHeader header;
   enet_uint16 outgoingPeerID;
   enet_uint8 incomingSessionID;
   enet_uint8 outgoingSessionID;
   enet_uint32 mtu;
   enet_uint32 windowSize;
   enet_uint32 channelCount;
   enet_uint32 incomingBandwidth;
   enet_uint32 outgoingBandwidth;
   enet_uint32 packetThrottleInterval;
   enet_uint32 packetThrottleAcceleration;
   enet_uint32 packetThrottleDeceleration;
   enet_uint32 connectID;
   enet_uint32 data;
}   ENetProtocolConnect;

typedef struct _ENetProtocolVerifyConnect
{
   ENetProtocolCommandHeader header;
   enet_uint16 outgoingPeerID;
   enet_uint8 incomingSessionID;
   enet_uint8 outgoingSessionID;
   enet_uint32 mtu;
   enet_uint32 windowSize;
   enet_uint32 channelCount;
   enet_uint32 incomingBandwidth;
   enet_uint32 outgoingBandwidth;
   enet_uint32 packetThrottleInterval;
   enet_uint32 packetThrottleAcceleration;
   enet_uint32 packetThrottleDeceleration;
   enet_uint32 connectID;
}   ENetProtocolVerifyConnect;

typedef struct _ENetProtocolBandwidthLimit
{
   ENetProtocolCommandHeader header;
   enet_uint32 incomingBandwidth;
   enet_uint32 outgoingBandwidth;
}   ENetProtocolBandwidthLimit;

typedef struct _ENetProtocolThrottleConfigure
{
   ENetProtocolCommandHeader header;
   enet_uint32 packetThrottleInterval;
   enet_uint32 packetThrottleAcceleration;
   enet_uint32 packetThrottleDeceleration;
}   ENetProtocolThrottleConfigure;

typedef struct _ENetProtocolDisconnect
{
   ENetProtocolCommandHeader header;
   enet_uint32 data;
}   ENetProtocolDisconnect;

typedef struct _ENetProtocolPing
{
   ENetProtocolCommandHeader header;
}   ENetProtocolPing;

typedef struct _ENetProtocolSendReliable
{
   ENetProtocolCommandHeader header;
   enet_uint16 dataLength;
}   ENetProtocolSendReliable;

typedef struct _ENetProtocolSendUnreliable
{
   ENetProtocolCommandHeader header;
   enet_uint16 unreliableSequenceNumber;
   enet_uint16 dataLength;
}   ENetProtocolSendUnreliable;

typedef struct _ENetProtocolSendUnsequenced
{
   ENetProtocolCommandHeader header;
   enet_uint16 unsequencedGroup;
   enet_uint16 dataLength;
}   ENetProtocolSendUnsequenced;

typedef struct _ENetProtocolSendFragment
{
   ENetProtocolCommandHeader header;
   enet_uint16 startSequenceNumber;
   enet_uint16 dataLength;
   enet_uint32 fragmentCount;
   enet_uint32 fragmentNumber;
   enet_uint32 totalLength;
   enet_uint32 fragmentOffset;
}   ENetProtocolSendFragment;

typedef union _ENetProtocol
{
   ENetProtocolCommandHeader header;
   ENetProtocolAcknowledge acknowledge;
   ENetProtocolConnect connect;
   ENetProtocolVerifyConnect verifyConnect;
   ENetProtocolDisconnect disconnect;
   ENetProtocolPing ping;
   ENetProtocolSendReliable sendReliable;
   ENetProtocolSendUnreliable sendUnreliable;
   ENetProtocolSendUnsequenced sendUnsequenced;
   ENetProtocolSendFragment sendFragment;
   ENetProtocolBandwidthLimit bandwidthLimit;
   ENetProtocolThrottleConfigure throttleConfigure;
}   ENetProtocol;

typedef struct _ENetListNode
{
   struct _ENetListNode * next;
   struct _ENetListNode * previous;
} ENetListNode;

typedef ENetListNode * ENetListIterator;

typedef struct _ENetList
{
   ENetListNode sentinel;
} ENetList;

extern void enet_list_clear (ENetList *);

extern ENetListIterator enet_list_insert (ENetListIterator, void *);
extern void * enet_list_remove (ENetListIterator);
extern ENetListIterator enet_list_move (ENetListIterator, void *, void *);

extern size_t enet_list_size (ENetList *);

typedef struct _ENetCallbacks
{
    void * (  * malloc) (size_t size);
    void (  * free) (void * memory);
    void (  * no_memory) (void);
} ENetCallbacks;
extern void * enet_malloc (size_t);
extern void enet_free (void *);







typedef enet_uint32 ENetVersion;

typedef enum _ENetSocketType
{
   ENET_SOCKET_TYPE_STREAM = 1,
   ENET_SOCKET_TYPE_DATAGRAM = 2
} ENetSocketType;

typedef enum _ENetSocketWait
{
   ENET_SOCKET_WAIT_NONE = 0,
   ENET_SOCKET_WAIT_SEND = (1 << 0),
   ENET_SOCKET_WAIT_RECEIVE = (1 << 1)
} ENetSocketWait;

typedef enum _ENetSocketOption
{
   ENET_SOCKOPT_NONBLOCK = 1,
   ENET_SOCKOPT_BROADCAST = 2,
   ENET_SOCKOPT_RCVBUF = 3,
   ENET_SOCKOPT_SNDBUF = 4,
   ENET_SOCKOPT_REUSEADDR = 5
} ENetSocketOption;

enum
{
   ENET_HOST_ANY = 0,
   ENET_HOST_BROADCAST = 0xFFFFFFFF,

   ENET_PORT_ANY = 0
};
typedef struct _ENetAddress
{
   enet_uint32 host;
   enet_uint16 port;
} ENetAddress;
typedef enum _ENetPacketFlag
{
   ENET_PACKET_FLAG_RELIABLE = (1 << 0),
   ENET_PACKET_FLAG_UNSEQUENCED = (1 << 1),

   ENET_PACKET_FLAG_NO_ALLOCATE = (1 << 2),
   ENET_PACKET_FLAG_UNRELIABLE_FRAGMENT = (1 << 3)
} ENetPacketFlag;

struct _ENetPacket;
typedef void (  * ENetPacketFreeCallback) (struct _ENetPacket *);
typedef struct _ENetPacket
{
   size_t referenceCount;
   enet_uint32 flags;
   enet_uint8 * data;
   size_t dataLength;
   ENetPacketFreeCallback freeCallback;
} ENetPacket;

typedef struct _ENetAcknowledgement
{
   ENetListNode acknowledgementList;
   enet_uint32 sentTime;
   ENetProtocol command;
} ENetAcknowledgement;

typedef struct _ENetOutgoingCommand
{
   ENetListNode outgoingCommandList;
   enet_uint16 reliableSequenceNumber;
   enet_uint16 unreliableSequenceNumber;
   enet_uint32 sentTime;
   enet_uint32 roundTripTimeout;
   enet_uint32 roundTripTimeoutLimit;
   enet_uint32 fragmentOffset;
   enet_uint16 fragmentLength;
   enet_uint16 sendAttempts;
   ENetProtocol command;
   ENetPacket * packet;
} ENetOutgoingCommand;

typedef struct _ENetIncomingCommand
{
   ENetListNode incomingCommandList;
   enet_uint16 reliableSequenceNumber;
   enet_uint16 unreliableSequenceNumber;
   ENetProtocol command;
   enet_uint32 fragmentCount;
   enet_uint32 fragmentsRemaining;
   enet_uint32 * fragments;
   ENetPacket * packet;
} ENetIncomingCommand;

typedef enum _ENetPeerState
{
   ENET_PEER_STATE_DISCONNECTED = 0,
   ENET_PEER_STATE_CONNECTING = 1,
   ENET_PEER_STATE_ACKNOWLEDGING_CONNECT = 2,
   ENET_PEER_STATE_CONNECTION_PENDING = 3,
   ENET_PEER_STATE_CONNECTION_SUCCEEDED = 4,
   ENET_PEER_STATE_CONNECTED = 5,
   ENET_PEER_STATE_DISCONNECT_LATER = 6,
   ENET_PEER_STATE_DISCONNECTING = 7,
   ENET_PEER_STATE_ACKNOWLEDGING_DISCONNECT = 8,
   ENET_PEER_STATE_ZOMBIE = 9
} ENetPeerState;





enum
{
   ENET_HOST_RECEIVE_BUFFER_SIZE = 256 * 1024,
   ENET_HOST_SEND_BUFFER_SIZE = 256 * 1024,
   ENET_HOST_BANDWIDTH_THROTTLE_INTERVAL = 1000,
   ENET_HOST_DEFAULT_MTU = 1400,

   ENET_PEER_DEFAULT_ROUND_TRIP_TIME = 500,
   ENET_PEER_DEFAULT_PACKET_THROTTLE = 32,
   ENET_PEER_PACKET_THROTTLE_SCALE = 32,
   ENET_PEER_PACKET_THROTTLE_COUNTER = 7,
   ENET_PEER_PACKET_THROTTLE_ACCELERATION = 2,
   ENET_PEER_PACKET_THROTTLE_DECELERATION = 2,
   ENET_PEER_PACKET_THROTTLE_INTERVAL = 5000,
   ENET_PEER_PACKET_LOSS_SCALE = (1 << 16),
   ENET_PEER_PACKET_LOSS_INTERVAL = 10000,
   ENET_PEER_WINDOW_SIZE_SCALE = 64 * 1024,
   ENET_PEER_TIMEOUT_LIMIT = 32,
   ENET_PEER_TIMEOUT_MINIMUM = 5000,
   ENET_PEER_TIMEOUT_MAXIMUM = 30000,
   ENET_PEER_PING_INTERVAL = 500,
   ENET_PEER_UNSEQUENCED_WINDOWS = 64,
   ENET_PEER_UNSEQUENCED_WINDOW_SIZE = 1024,
   ENET_PEER_FREE_UNSEQUENCED_WINDOWS = 32,
   ENET_PEER_RELIABLE_WINDOWS = 16,
   ENET_PEER_RELIABLE_WINDOW_SIZE = 0x1000,
   ENET_PEER_FREE_RELIABLE_WINDOWS = 8
};

typedef struct _ENetChannel
{
   enet_uint16 outgoingReliableSequenceNumber;
   enet_uint16 outgoingUnreliableSequenceNumber;
   enet_uint16 usedReliableWindows;
   enet_uint16 reliableWindows [ENET_PEER_RELIABLE_WINDOWS];
   enet_uint16 incomingReliableSequenceNumber;
   enet_uint16 incomingUnreliableSequenceNumber;
   ENetList incomingReliableCommands;
   ENetList incomingUnreliableCommands;
} ENetChannel;
typedef struct _ENetPeer
{
   ENetListNode dispatchList;
   struct _ENetHost * host;
   enet_uint16 outgoingPeerID;
   enet_uint16 incomingPeerID;
   enet_uint32 connectID;
   enet_uint8 outgoingSessionID;
   enet_uint8 incomingSessionID;
   ENetAddress address;
   void * data;
   ENetPeerState state;
   ENetChannel * channels;
   size_t channelCount;
   enet_uint32 incomingBandwidth;
   enet_uint32 outgoingBandwidth;
   enet_uint32 incomingBandwidthThrottleEpoch;
   enet_uint32 outgoingBandwidthThrottleEpoch;
   enet_uint32 incomingDataTotal;
   enet_uint32 outgoingDataTotal;
   enet_uint32 lastSendTime;
   enet_uint32 lastReceiveTime;
   enet_uint32 nextTimeout;
   enet_uint32 earliestTimeout;
   enet_uint32 packetLossEpoch;
   enet_uint32 packetsSent;
   enet_uint32 packetsLost;
   enet_uint32 packetLoss;
   enet_uint32 packetLossVariance;
   enet_uint32 packetThrottle;
   enet_uint32 packetThrottleLimit;
   enet_uint32 packetThrottleCounter;
   enet_uint32 packetThrottleEpoch;
   enet_uint32 packetThrottleAcceleration;
   enet_uint32 packetThrottleDeceleration;
   enet_uint32 packetThrottleInterval;
   enet_uint32 lastRoundTripTime;
   enet_uint32 lowestRoundTripTime;
   enet_uint32 lastRoundTripTimeVariance;
   enet_uint32 highestRoundTripTimeVariance;
   enet_uint32 roundTripTime;
   enet_uint32 roundTripTimeVariance;
   enet_uint32 mtu;
   enet_uint32 windowSize;
   enet_uint32 reliableDataInTransit;
   enet_uint16 outgoingReliableSequenceNumber;
   ENetList acknowledgements;
   ENetList sentReliableCommands;
   ENetList sentUnreliableCommands;
   ENetList outgoingReliableCommands;
   ENetList outgoingUnreliableCommands;
   ENetList dispatchedCommands;
   int needsDispatch;
   enet_uint16 incomingUnsequencedGroup;
   enet_uint16 outgoingUnsequencedGroup;
   enet_uint32 unsequencedWindow [ENET_PEER_UNSEQUENCED_WINDOW_SIZE / 32];
   enet_uint32 eventData;
} ENetPeer;
typedef struct _ENetCompressor
{

   void * context;

   size_t (  * compress) (void * context, const ENetBuffer * inBuffers, size_t inBufferCount, size_t inLimit, enet_uint8 * outData, size_t outLimit);

   size_t (  * decompress) (void * context, const enet_uint8 * inData, size_t inLimit, enet_uint8 * outData, size_t outLimit);

   void (  * destroy) (void * context);
} ENetCompressor;


typedef enet_uint32 (  * ENetChecksumCallback) (const ENetBuffer * buffers, size_t bufferCount);
typedef struct _ENetHost
{
   ENetSocket socket;
   ENetAddress address;
   enet_uint32 incomingBandwidth;
   enet_uint32 outgoingBandwidth;
   enet_uint32 bandwidthThrottleEpoch;
   enet_uint32 mtu;
   enet_uint32 randomSeed;
   int recalculateBandwidthLimits;
   ENetPeer * peers;
   size_t peerCount;
   size_t channelLimit;
   enet_uint32 serviceTime;
   ENetList dispatchQueue;
   int continueSending;
   size_t packetSize;
   enet_uint16 headerFlags;
   ENetProtocol commands [ENET_PROTOCOL_MAXIMUM_PACKET_COMMANDS];
   size_t commandCount;
   ENetBuffer buffers [ (1 + 2 * ENET_PROTOCOL_MAXIMUM_PACKET_COMMANDS) ];
   size_t bufferCount;
   ENetChecksumCallback checksum;
   ENetCompressor compressor;
   enet_uint8 packetData [2][ENET_PROTOCOL_MAXIMUM_MTU];
   ENetAddress receivedAddress;
   enet_uint8 * receivedData;
   size_t receivedDataLength;
   enet_uint32 totalSentData;
   enet_uint32 totalSentPackets;
   enet_uint32 totalReceivedData;
   enet_uint32 totalReceivedPackets;
} ENetHost;
typedef enum _ENetEventType
{

   ENET_EVENT_TYPE_NONE = 0,
   ENET_EVENT_TYPE_CONNECT = 1,
   ENET_EVENT_TYPE_DISCONNECT = 2,
   ENET_EVENT_TYPE_RECEIVE = 3
} ENetEventType;
typedef struct _ENetEvent
{
   ENetEventType type;
   ENetPeer * peer;
   enet_uint8 channelID;
   enet_uint32 data;
   ENetPacket * packet;
} ENetEvent;
extern  int enet_initialize (void);
extern  int enet_initialize_with_callbacks (ENetVersion version, const ENetCallbacks * inits);
extern  void enet_deinitialize (void);
extern  enet_uint32 enet_time_get (void);
extern  void enet_time_set (enet_uint32);
extern  ENetSocket enet_socket_create (ENetSocketType);
extern  int enet_socket_bind (ENetSocket, const ENetAddress *);
extern  int enet_socket_listen (ENetSocket, int);
extern  ENetSocket enet_socket_accept (ENetSocket, ENetAddress *);
extern  int enet_socket_connect (ENetSocket, const ENetAddress *);
extern  int enet_socket_send (ENetSocket, const ENetAddress *, const ENetBuffer *, size_t);
extern  int enet_socket_receive (ENetSocket, ENetAddress *, ENetBuffer *, size_t);
extern  int enet_socket_wait (ENetSocket, enet_uint32 *, enet_uint32);
extern  int enet_socket_set_option (ENetSocket, ENetSocketOption, int);
extern  void enet_socket_destroy (ENetSocket);
extern  int enet_socketset_select (ENetSocket, ENetSocketSet *, ENetSocketSet *, enet_uint32);
extern  int enet_address_set_host (ENetAddress * address, const char * hostName);
extern  int enet_address_get_host_ip (const ENetAddress * address, char * hostName, size_t nameLength);
extern  int enet_address_get_host (const ENetAddress * address, char * hostName, size_t nameLength);



extern  ENetPacket * enet_packet_create (const void *, size_t, enet_uint32);
extern  void enet_packet_destroy (ENetPacket *);
extern  int enet_packet_resize (ENetPacket *, size_t);
extern enet_uint32 enet_crc32 (const ENetBuffer *, size_t);

extern  ENetHost * enet_host_create (const ENetAddress *, size_t, size_t, enet_uint32, enet_uint32);
extern  void enet_host_destroy (ENetHost *);
extern  ENetPeer * enet_host_connect (ENetHost *, const ENetAddress *, size_t, enet_uint32);
extern  int enet_host_check_events (ENetHost *, ENetEvent *);
extern  int enet_host_service (ENetHost *, ENetEvent *, enet_uint32);
extern  void enet_host_flush (ENetHost *);
extern  void enet_host_broadcast (ENetHost *, enet_uint8, ENetPacket *);
extern  void enet_host_compress (ENetHost *, const ENetCompressor *);
extern  int enet_host_compress_with_range_coder (ENetHost * host);
extern  void enet_host_channel_limit (ENetHost *, size_t);
extern  void enet_host_bandwidth_limit (ENetHost *, enet_uint32, enet_uint32);
extern void enet_host_bandwidth_throttle (ENetHost *);

extern  int enet_peer_send (ENetPeer *, enet_uint8, ENetPacket *);
extern  ENetPacket * enet_peer_receive (ENetPeer *, enet_uint8 * channelID);
extern  void enet_peer_ping (ENetPeer *);
extern  void enet_peer_reset (ENetPeer *);
extern  void enet_peer_disconnect (ENetPeer *, enet_uint32);
extern  void enet_peer_disconnect_now (ENetPeer *, enet_uint32);
extern  void enet_peer_disconnect_later (ENetPeer *, enet_uint32);
extern  void enet_peer_throttle_configure (ENetPeer *, enet_uint32, enet_uint32, enet_uint32);
extern int enet_peer_throttle (ENetPeer *, enet_uint32);
extern void enet_peer_reset_queues (ENetPeer *);
extern void enet_peer_setup_outgoing_command (ENetPeer *, ENetOutgoingCommand *);
extern ENetOutgoingCommand * enet_peer_queue_outgoing_command (ENetPeer *, const ENetProtocol *, ENetPacket *, enet_uint32, enet_uint16);
extern ENetIncomingCommand * enet_peer_queue_incoming_command (ENetPeer *, const ENetProtocol *, ENetPacket *, enet_uint32);
extern ENetAcknowledgement * enet_peer_queue_acknowledgement (ENetPeer *, const ENetProtocol *, enet_uint16);
extern void enet_peer_dispatch_incoming_unreliable_commands (ENetPeer *, ENetChannel *);
extern void enet_peer_dispatch_incoming_reliable_commands (ENetPeer *, ENetChannel *);

extern  void * enet_range_coder_create (void);
extern  void enet_range_coder_destroy (void *);
extern  size_t enet_range_coder_compress (void *, const ENetBuffer *, size_t, size_t, enet_uint8 *, size_t);
extern  size_t enet_range_coder_decompress (void *, const enet_uint8 *, size_t, enet_uint8 *, size_t);

extern size_t enet_protocol_command_size (enet_uint8);
