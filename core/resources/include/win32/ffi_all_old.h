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
extern __declspec(dllimport)  void sfMusic_setPlayingOffset(sfMusic* music, sfUint32 timeOffset);









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
typedef struct sfTransform sfTransform;
typedef struct sfTransformable sfTransformable;
typedef struct sfVertexArray sfVertexArray;
typedef struct sfView sfView;








extern __declspec(dllimport)  sfCircleShape* sfCircleShape_create(void);









extern __declspec(dllimport)  sfCircleShape* sfCircleShape_copy(sfCircleShape* shape);







extern __declspec(dllimport)  void sfCircleShape_destroy(sfCircleShape* shape);
extern __declspec(dllimport)  void sfCircleShape_setPosition(sfCircleShape* shape, sfVector2f position);
extern __declspec(dllimport)  void sfCircleShape_setRotation(sfCircleShape* shape, float angle);
extern __declspec(dllimport)  void sfCircleShape_setScale(sfCircleShape* shape, sfVector2f scale);
extern __declspec(dllimport)  void sfCircleShape_setOrigin(sfCircleShape* shape, sfVector2f origin);









extern __declspec(dllimport)  sfVector2f sfCircleShape_getPosition(const sfCircleShape* shape);
extern __declspec(dllimport)  float sfCircleShape_getRotation(const sfCircleShape* shape);









extern __declspec(dllimport)  sfVector2f sfCircleShape_GetScale(const sfCircleShape* shape);









extern __declspec(dllimport)  sfVector2f sfCircleShape_GetOrigin(const sfCircleShape* shape);
extern __declspec(dllimport)  void sfCircleShape_move(sfCircleShape* shape, sfVector2f offset);
extern __declspec(dllimport)  void sfCircleShape_rotate(sfCircleShape* shape, float angle);
extern __declspec(dllimport)  void sfCircleShape_scale(sfCircleShape* shape, sfVector2f factors);









extern __declspec(dllimport)  const sfTransform* sfCircleShape_getTransform(const sfCircleShape* shape);









extern __declspec(dllimport)  const sfTransform* sfCircleShape_getInverseTransform(const sfCircleShape* shape);
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









extern __declspec(dllimport)  const sfTransform* sfConvexShape_getTransform(const sfConvexShape* shape);









extern __declspec(dllimport)  const sfTransform* sfConvexShape_getInverseTransform(const sfConvexShape* shape);
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







extern __declspec(dllimport)  const sfFont* sfFont_getDefaultFont(void);
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
extern __declspec(dllimport)  void sfImage_createMaskFromColor(sfColor color, sfUint8 alpha);
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








extern __declspec(dllimport)  sfRectangleShape* sfRectangleShape_Create(void);









extern __declspec(dllimport)  sfRectangleShape* sfRectangleShape_Copy(sfRectangleShape* shape);







extern __declspec(dllimport)  void sfRectangleShape_Destroy(sfRectangleShape* shape);
extern __declspec(dllimport)  void sfRectangleShape_SetPosition(sfRectangleShape* shape, sfVector2f position);
extern __declspec(dllimport)  void sfRectangleShape_SetRotation(sfRectangleShape* shape, float angle);
extern __declspec(dllimport)  void sfRectangleShape_SetScale(sfRectangleShape* shape, sfVector2f scale);
extern __declspec(dllimport)  void sfRectangleShape_SetOrigin(sfRectangleShape* shape, sfVector2f origin);









extern __declspec(dllimport)  sfVector2f sfRectangleShape_GetPosition(const sfRectangleShape* shape);
extern __declspec(dllimport)  float sfRectangleShape_GetRotation(const sfRectangleShape* shape);









extern __declspec(dllimport)  sfVector2f sfRectangleShape_GetScale(const sfRectangleShape* shape);









extern __declspec(dllimport)  sfVector2f sfRectangleShape_GetOrigin(const sfRectangleShape* shape);
extern __declspec(dllimport)  void sfRectangleShape_Move(sfRectangleShape* shape, sfVector2f offset);
extern __declspec(dllimport)  void sfRectangleShape_Rotate(sfRectangleShape* shape, float angle);
extern __declspec(dllimport)  void sfRectangleShape_Scale(sfRectangleShape* shape, sfVector2f factors);









extern __declspec(dllimport)  const sfTransform* sfRectangleShape_GetTransform(const sfRectangleShape* shape);









extern __declspec(dllimport)  const sfTransform* sfRectangleShape_GetInverseTransform(const sfRectangleShape* shape);
extern __declspec(dllimport)  void sfRectangleShape_SetTexture(sfRectangleShape* shape, const sfTexture* texture, sfBool resetRect);
extern __declspec(dllimport)  void sfRectangleShape_SetTextureRect(sfRectangleShape* shape, sfIntRect rect);
extern __declspec(dllimport)  void sfRectangleShape_SetFillColor(sfRectangleShape* shape, sfColor color);
extern __declspec(dllimport)  void sfRectangleShape_SetOutlineColor(sfRectangleShape* shape, sfColor color);
extern __declspec(dllimport)  void sfRectangleShape_SetOutlineThickness(sfRectangleShape* shape, float thickness);
extern __declspec(dllimport)  const sfTexture* sfRectangleShape_GetTexture(const sfRectangleShape* shape);









extern __declspec(dllimport)  sfIntRect sfRectangleShape_GetTextureRect(const sfRectangleShape* shape);









extern __declspec(dllimport)  sfColor sfRectangleShape_GetFillColor(const sfRectangleShape* shape);









extern __declspec(dllimport)  sfColor sfRectangleShape_GetOutlineColor(const sfRectangleShape* shape);









extern __declspec(dllimport)  float sfRectangleShape_GetOutlineThickness(const sfRectangleShape* shape);









extern __declspec(dllimport)  unsigned int sfRectangleShape_GetPointCount(const sfRectangleShape* shape);
extern __declspec(dllimport)  sfVector2f sfRectangleShape_GetPoint(const sfRectangleShape* shape, unsigned int index);








extern __declspec(dllimport)  void sfRectangleShape_SetSize(sfRectangleShape* shape, sfVector2f size);









extern __declspec(dllimport)  sfVector2f sfRectangleShape_GetSize(const sfRectangleShape* shape);
extern __declspec(dllimport)  sfFloatRect sfRectangleShape_GetLocalBounds(const sfRectangleShape* shape);
extern __declspec(dllimport)  sfFloatRect sfRectangleShape_GetGlobalBounds(const sfRectangleShape* shape);






typedef struct
{
    sfBlendMode blendMode;
    sfTransform* transform;
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
extern __declspec(dllimport)  void sfShader_setTransformParameter(sfShader* shader, const char* name, const sfTransform* transform);
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









extern __declspec(dllimport)  const sfTransform* sfShape_getTransform(const sfShape* shape);









extern __declspec(dllimport)  const sfTransform* sfShape_getInverseTransform(const sfShape* shape);
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









extern __declspec(dllimport)  const sfTransform* sfText_getTransform(const sfText* text);









extern __declspec(dllimport)  const sfTransform* sfText_getInverseTransform(const sfText* text);










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










extern __declspec(dllimport)  sfTransform* sfTransform_create(void);
extern __declspec(dllimport)  sfTransform* sfTransform_createFromMatrix(float a00, float a01, float a02,
                                                             float a10, float a11, float a12,
                                                             float a20, float a21, float a22);









extern __declspec(dllimport)  sfTransform* sfTransform_copy(sfTransform* transform);







extern __declspec(dllimport)  void sfTransform_destroy(sfTransform* transform);
extern __declspec(dllimport)  const float* sfTransform_getMatrix(const sfTransform* transform);
extern __declspec(dllimport)  void sfTransform_getInverse(const sfTransform* transform, sfTransform* result);










extern __declspec(dllimport)  sfVector2f sfTransform_transformPoint(const sfTransform* transform, sfVector2f point);
extern __declspec(dllimport)  sfFloatRect sfTransform_transformRect(const sfTransform* transform, sfFloatRect rectangle);
extern __declspec(dllimport)  void sfTransform_combine(sfTransform* transform, const sfTransform* other);









extern __declspec(dllimport)  void sfTransform_translate(sfTransform* transform, float x, float y);








extern __declspec(dllimport)  void sfTransform_rotate(sfTransform* transform, float angle);
extern __declspec(dllimport)  void sfTransform_rotateWithCenter(sfTransform* transform, float angle, float centerX, float centerY);









extern __declspec(dllimport)  void sfTransform_scale(sfTransform* transform, float scaleX, float scaleY);
extern __declspec(dllimport)  void sfTransform_scaleWithCenter(sfTransform* transform, float scaleX, float scaleY, float centerX, float centerY);








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









extern __declspec(dllimport)  const sfTransform* sfTransformable_getTransform(const sfTransformable* transformable);









extern __declspec(dllimport)  const sfTransform* sfTransformable_getInverseTransform(const sfTransformable* transformable);








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
typedef enum _EXCEPTION_DISPOSITION {
    ExceptionContinueExecution,
    ExceptionContinueSearch,
    ExceptionNestedException,
    ExceptionCollidedUnwind
} EXCEPTION_DISPOSITION;
struct _EXCEPTION_RECORD;
struct _CONTEXT;

EXCEPTION_DISPOSITION   _except_handler (
     struct _EXCEPTION_RECORD *_ExceptionRecord,
     void * _EstablisherFrame,
     struct _CONTEXT *_ContextRecord,
     void * _DispatcherContext
    );
typedef unsigned long ULONG;
typedef ULONG *PULONG;
typedef unsigned short USHORT;
typedef USHORT *PUSHORT;
typedef unsigned char UCHAR;
typedef UCHAR *PUCHAR;
typedef char *PSZ;
typedef unsigned long DWORD;
typedef int BOOL;
typedef unsigned char BYTE;
typedef unsigned short WORD;
typedef float FLOAT;
typedef FLOAT *PFLOAT;
typedef BOOL   *PBOOL;
typedef BOOL   *LPBOOL;
typedef BYTE   *PBYTE;
typedef BYTE   *LPBYTE;
typedef int   *PINT;
typedef int   *LPINT;
typedef WORD   *PWORD;
typedef WORD   *LPWORD;
typedef long   *LPLONG;
typedef DWORD   *PDWORD;
typedef DWORD   *LPDWORD;
typedef void   *LPVOID;
typedef  const  void   *LPCVOID;

typedef int INT;
typedef unsigned int UINT;
typedef unsigned int *PUINT;
 const unsigned short *   __pctype_func(void);

 extern const unsigned short *_pctype;
 extern const unsigned short _wctype[];


 const wctype_t *   __pwctype_func(void);

 extern const wctype_t *_pwctype;
   int   _isctype(  int _C,   int _Type);
   int   _isctype_l(  int _C,   int _Type,    _locale_t _Locale);
     int   isalpha(  int _C);
   int   _isalpha_l(  int _C,    _locale_t _Locale);
     int   isupper(  int _C);
   int   _isupper_l(  int _C,    _locale_t _Locale);
     int   islower(  int _C);
   int   _islower_l(  int _C,    _locale_t _Locale);
     int   isdigit(  int _C);
   int   _isdigit_l(  int _C,    _locale_t _Locale);
   int   isxdigit(  int _C);
   int   _isxdigit_l(  int _C,    _locale_t _Locale);
     int   isspace(  int _C);
   int   _isspace_l(  int _C,    _locale_t _Locale);
   int   ispunct(  int _C);
   int   _ispunct_l(  int _C,    _locale_t _Locale);
     int   isalnum(  int _C);
   int   _isalnum_l(  int _C,    _locale_t _Locale);
   int   isprint(  int _C);
   int   _isprint_l(  int _C,    _locale_t _Locale);
   int   isgraph(  int _C);
   int   _isgraph_l(  int _C,    _locale_t _Locale);
   int   iscntrl(  int _C);
   int   _iscntrl_l(  int _C,    _locale_t _Locale);
     int   toupper(  int _C);
     int   tolower(  int _C);
     int   _tolower(  int _C);
   int   _tolower_l(  int _C,    _locale_t _Locale);
     int   _toupper(  int _C);
   int   _toupper_l(  int _C,    _locale_t _Locale);
   int   __isascii(  int _C);
   int   __toascii(  int _C);
   int   __iscsymf(  int _C);
   int   __iscsym(  int _C);









   int   iswalpha(  wint_t _C);
   int   _iswalpha_l(  wint_t _C,    _locale_t _Locale);
   int   iswupper(  wint_t _C);
   int   _iswupper_l(  wint_t _C,    _locale_t _Locale);
   int   iswlower(  wint_t _C);
   int   _iswlower_l(  wint_t _C,    _locale_t _Locale);
   int   iswdigit(  wint_t _C);
   int   _iswdigit_l(  wint_t _C,    _locale_t _Locale);
   int   iswxdigit(  wint_t _C);
   int   _iswxdigit_l(  wint_t _C,    _locale_t _Locale);
   int   iswspace(  wint_t _C);
   int   _iswspace_l(  wint_t _C,    _locale_t _Locale);
   int   iswpunct(  wint_t _C);
   int   _iswpunct_l(  wint_t _C,    _locale_t _Locale);
   int   iswalnum(  wint_t _C);
   int   _iswalnum_l(  wint_t _C,    _locale_t _Locale);
   int   iswprint(  wint_t _C);
   int   _iswprint_l(  wint_t _C,    _locale_t _Locale);
   int   iswgraph(  wint_t _C);
   int   _iswgraph_l(  wint_t _C,    _locale_t _Locale);
   int   iswcntrl(  wint_t _C);
   int   _iswcntrl_l(  wint_t _C,    _locale_t _Locale);
   int   iswascii(  wint_t _C);
   int   isleadbyte(  int _C);
   int   _isleadbyte_l(  int _C,    _locale_t _Locale);

   wint_t   towupper(  wint_t _C);
   wint_t   _towupper_l(  wint_t _C,    _locale_t _Locale);
   wint_t   towlower(  wint_t _C);
   wint_t   _towlower_l(  wint_t _C,    _locale_t _Locale);
   int   iswctype(  wint_t _C,   wctype_t _Type);
   int   _iswctype_l(  wint_t _C,   wctype_t _Type,    _locale_t _Locale);

   int   __iswcsymf(  wint_t _C);
   int   _iswcsymf_l(  wint_t _C,    _locale_t _Locale);
   int   __iswcsym(  wint_t _C);
   int   _iswcsym_l(  wint_t _C,    _locale_t _Locale);

__declspec(deprecated)    int   is_wctype(  wint_t _C,   wctype_t _Type);


  typedef unsigned long POINTER_64_INT;
typedef signed char INT8, *PINT8;
typedef signed short INT16, *PINT16;
typedef signed int INT32, *PINT32;
typedef signed __int64 INT64, *PINT64;
typedef unsigned char UINT8, *PUINT8;
typedef unsigned short UINT16, *PUINT16;
typedef unsigned int UINT32, *PUINT32;
typedef unsigned __int64 UINT64, *PUINT64;





typedef signed int LONG32, *PLONG32;





typedef unsigned int ULONG32, *PULONG32;
typedef unsigned int DWORD32, *PDWORD32;
    typedef   int INT_PTR, *PINT_PTR;
    typedef   unsigned int UINT_PTR, *PUINT_PTR;

    typedef   long LONG_PTR, *PLONG_PTR;
    typedef   unsigned long ULONG_PTR, *PULONG_PTR;
typedef unsigned short UHALF_PTR, *PUHALF_PTR;
typedef short HALF_PTR, *PHALF_PTR;
typedef   long SHANDLE_PTR;
typedef   unsigned long HANDLE_PTR;
__inline
void *
PtrToPtr64(
    const void *p
    )
{
    return((void *  ) (unsigned __int64) (ULONG_PTR)p );
}

__inline
void *
Ptr64ToPtr(
    const void *   p
    )
{
    return((void *) (ULONG_PTR) (unsigned __int64) p);
}

__inline
void *
HandleToHandle64(
    const void *h
    )
{
    return((void *  )(__int64)(LONG_PTR)h );
}

__inline
void *
Handle64ToHandle(
    const void *   h
    )
{
    return((void *) (ULONG_PTR) (unsigned __int64) h );
}
typedef ULONG_PTR SIZE_T, *PSIZE_T;
typedef LONG_PTR SSIZE_T, *PSSIZE_T;
typedef ULONG_PTR DWORD_PTR, *PDWORD_PTR;





typedef __int64 LONG64, *PLONG64;






typedef unsigned __int64 ULONG64, *PULONG64;
typedef unsigned __int64 DWORD64, *PDWORD64;





typedef ULONG_PTR KAFFINITY;
typedef KAFFINITY *PKAFFINITY;
typedef void *PVOID;
typedef void *   PVOID64;
typedef char CHAR;
typedef short SHORT;
typedef long LONG;

typedef int INT;








typedef wchar_t WCHAR;
typedef WCHAR *PWCHAR, *LPWCH, *PWCH;
typedef  const  WCHAR *LPCWCH, *PCWCH;
typedef   WCHAR *NWPSTR, *LPWSTR, *PWSTR;
typedef   PWSTR *PZPWSTR;
typedef    const  PWSTR *PCZPWSTR;
typedef   WCHAR   *LPUWSTR, *PUWSTR;
typedef    const  WCHAR *LPCWSTR, *PCWSTR;
typedef   PCWSTR *PZPCWSTR;
typedef    const  WCHAR   *LPCUWSTR, *PCUWSTR;




typedef  const  WCHAR *LPCWCHAR, *PCWCHAR;
typedef  const  WCHAR   *LPCUWCHAR, *PCUWCHAR;





typedef unsigned long UCSCHAR;
typedef UCSCHAR *PUCSCHAR;
typedef const UCSCHAR *PCUCSCHAR;

typedef UCSCHAR *PUCSSTR;
typedef UCSCHAR   *PUUCSSTR;

typedef const UCSCHAR *PCUCSSTR;
typedef const UCSCHAR   *PCUUCSSTR;

typedef UCSCHAR   *PUUCSCHAR;
typedef const UCSCHAR   *PCUUCSCHAR;







typedef CHAR *PCHAR, *LPCH, *PCH;
typedef  const  CHAR *LPCCH, *PCCH;

typedef   CHAR *NPSTR, *LPSTR, *PSTR;
typedef   PSTR *PZPSTR;
typedef    const  PSTR *PCZPSTR;
typedef    const  CHAR *LPCSTR, *PCSTR;
typedef   PCSTR *PZPCSTR;
typedef char TCHAR, *PTCHAR;
typedef unsigned char TBYTE , *PTBYTE ;



typedef LPCH LPTCH, PTCH;
typedef LPSTR PTSTR, LPTSTR, PUTSTR, LPUTSTR;
typedef LPCSTR PCTSTR, LPCTSTR, PCUTSTR, LPCUTSTR;






typedef SHORT *PSHORT;
typedef LONG *PLONG;


typedef void *HANDLE;
typedef HANDLE *PHANDLE;





typedef BYTE FCHAR;
typedef WORD FSHORT;
typedef DWORD FLONG;








typedef   long HRESULT;
typedef char CCHAR;
typedef DWORD LCID;
typedef PDWORD PLCID;
typedef WORD LANGID;
typedef struct _FLOAT128 {
    __int64 LowPart;
    __int64 HighPart;
} FLOAT128;

typedef FLOAT128 *PFLOAT128;
typedef double LONGLONG;
typedef double ULONGLONG;




typedef LONGLONG *PLONGLONG;
typedef ULONGLONG *PULONGLONG;



typedef LONGLONG USN;




typedef union _LARGE_INTEGER {
    struct {
        DWORD LowPart;
        LONG HighPart;
    }  s ;
    struct {
        DWORD LowPart;
        LONG HighPart;
    } u;

    LONGLONG QuadPart;
} LARGE_INTEGER;

typedef LARGE_INTEGER *PLARGE_INTEGER;




typedef union _ULARGE_INTEGER {
    struct {
        DWORD LowPart;
        DWORD HighPart;
    }  s ;
    struct {
        DWORD LowPart;
        DWORD HighPart;
    } u;

    ULONGLONG QuadPart;
} ULARGE_INTEGER;

typedef ULARGE_INTEGER *PULARGE_INTEGER;








typedef struct _LUID {
    DWORD LowPart;
    LONG HighPart;
} LUID, *PLUID;


typedef ULONGLONG DWORDLONG;
typedef DWORDLONG *PDWORDLONG;
ULONGLONG

Int64ShllMod32 (
    ULONGLONG Value,
    DWORD ShiftCount
    );

LONGLONG

Int64ShraMod32 (
    LONGLONG Value,
    DWORD ShiftCount
    );

ULONGLONG

Int64ShrlMod32 (
    ULONGLONG Value,
    DWORD ShiftCount
    );

__inline ULONGLONG

Int64ShllMod32 (
    ULONGLONG Value,
    DWORD ShiftCount
    )
{
    __asm {
        mov ecx, ShiftCount
        mov eax, dword ptr [Value]
        mov edx, dword ptr [Value+4]
        shld edx, eax, cl
        shl eax, cl
    }
}

__inline LONGLONG

Int64ShraMod32 (
    LONGLONG Value,
    DWORD ShiftCount
    )
{
    __asm {
        mov ecx, ShiftCount
        mov eax, dword ptr [Value]
        mov edx, dword ptr [Value+4]
        shrd eax, edx, cl
        sar edx, cl
    }
}

__inline ULONGLONG

Int64ShrlMod32 (
    ULONGLONG Value,
    DWORD ShiftCount
    )
{
    __asm {
        mov ecx, ShiftCount
        mov eax, dword ptr [Value]
        mov edx, dword ptr [Value+4]
        shrd eax, edx, cl
        shr edx, cl
    }
}
typedef BYTE BOOLEAN;
typedef BOOLEAN *PBOOLEAN;





typedef struct _LIST_ENTRY {
   struct _LIST_ENTRY *Flink;
   struct _LIST_ENTRY *Blink;
} LIST_ENTRY, *PLIST_ENTRY, *  PRLIST_ENTRY;






typedef struct _SINGLE_LIST_ENTRY {
    struct _SINGLE_LIST_ENTRY *Next;
} SINGLE_LIST_ENTRY, *PSINGLE_LIST_ENTRY;





typedef struct LIST_ENTRY32 {
    DWORD Flink;
    DWORD Blink;
} LIST_ENTRY32;
typedef LIST_ENTRY32 *PLIST_ENTRY32;

typedef struct LIST_ENTRY64 {
    ULONGLONG Flink;
    ULONGLONG Blink;
} LIST_ENTRY64;
typedef LIST_ENTRY64 *PLIST_ENTRY64;
typedef struct _GUID {
    unsigned long Data1;
    unsigned short Data2;
    unsigned short Data3;
    unsigned char Data4[ 8 ];
} GUID;
typedef GUID *LPGUID;




typedef const GUID *LPCGUID;





typedef GUID IID;
typedef IID *LPIID;


typedef GUID CLSID;
typedef CLSID *LPCLSID;


typedef GUID FMTID;
typedef FMTID *LPFMTID;
 void *   _memccpy(   void * _Dst,   const void * _Src,   int _Val,   size_t _MaxCount);
     void *   memchr(    const void * _Buf ,   int _Val,   size_t _MaxCount);
   int   _memicmp(   const void * _Buf1,    const void * _Buf2,   size_t _Size);
   int   _memicmp_l(   const void * _Buf1,    const void * _Buf2,   size_t _Size,    _locale_t _Locale);
         int   memcmp(   const void * _Buf1,    const void * _Buf2,   size_t _Size);
         void *   memcpy(    void * _Dst,    const void * _Src,   size_t _Size);

 errno_t   memcpy_s(    void * _Dst,   rsize_t _DstSize,    const void * _Src,   rsize_t _MaxCount);

        void *   memset(    void * _Dst,   int _Val,   size_t _Size);
   errno_t   _strset_s(    char * _Dst,   size_t _DstSize,   int _Value);

__declspec(deprecated)  char *  _strset( char *_Dest, int _Value);

   errno_t   strcpy_s(    char * _Dst,   rsize_t _SizeInBytes,    const char * _Src);


__declspec(deprecated)  char *  strcpy( char *_Dest, const char * _Source);

   errno_t   strcat_s(    char * _Dst,   rsize_t _SizeInBytes,    const char * _Src);


__declspec(deprecated)  char *  strcat( char *_Dest, const char * _Source);
         int   strcmp(   const char * _Str1,    const char * _Str2);
         size_t   strlen(   const char * _Str);
   size_t   strnlen(   const char * _Str,   size_t _MaxCount);

 static __inline size_t   strnlen_s(   const char * _Str,   size_t _MaxCount)
{
    return (_Str==0) ? 0 : strnlen(_Str, _MaxCount);
}


   errno_t   memmove_s(    void * _Dst,   rsize_t _DstSize,    const void * _Src,   rsize_t _MaxCount);





   void *   memmove(    void * _Dst,    const void * _Src,   size_t _Size);
   char *   _strdup(   const char * _Src);
     char *   strchr(   const char * _Str,   int _Val);
   int   _stricmp(   const char * _Str1,    const char * _Str2);
   int   _strcmpi(   const char * _Str1,    const char * _Str2);
   int   _stricmp_l(   const char * _Str1,    const char * _Str2,    _locale_t _Locale);
   int   strcoll(   const char * _Str1,    const char * _Str2);
   int   _strcoll_l(   const char * _Str1,    const char * _Str2,    _locale_t _Locale);
   int   _stricoll(   const char * _Str1,    const char * _Str2);
   int   _stricoll_l(   const char * _Str1,    const char * _Str2,    _locale_t _Locale);
   int   _strncoll (   const char * _Str1,    const char * _Str2,   size_t _MaxCount);
   int   _strncoll_l(   const char * _Str1,    const char * _Str2,   size_t _MaxCount,    _locale_t _Locale);
   int   _strnicoll (   const char * _Str1,    const char * _Str2,   size_t _MaxCount);
   int   _strnicoll_l(   const char * _Str1,    const char * _Str2,   size_t _MaxCount,    _locale_t _Locale);
   size_t   strcspn(   const char * _Str,    const char * _Control);
  __declspec(deprecated)    char *   _strerror(   const char * _ErrMsg);
   errno_t   _strerror_s(    char * _Buf,   size_t _SizeInBytes,    const char * _ErrMsg);

  __declspec(deprecated)    char *   strerror(  int);

   errno_t   strerror_s(    char * _Buf,   size_t _SizeInBytes,   int _ErrNum);


   errno_t   _strlwr_s(    char * _Str,   size_t _Size);

__declspec(deprecated)  char *  _strlwr( char *_String);
   errno_t   _strlwr_s_l(    char * _Str,   size_t _Size,    _locale_t _Locale);

__declspec(deprecated)  char *  _strlwr_l(    char *_String,    _locale_t _Locale);

   errno_t   strncat_s(    char * _Dst,   rsize_t _SizeInBytes,    const char * _Src,   rsize_t _MaxCount);



__declspec(deprecated)  char *  strncat(    char *_Dest,    const char * _Source,   size_t _Count);



   int   strncmp(   const char * _Str1,    const char * _Str2,   size_t _MaxCount);

   int   _strnicmp(   const char * _Str1,    const char * _Str2,   size_t _MaxCount);
   int   _strnicmp_l(   const char * _Str1,    const char * _Str2,   size_t _MaxCount,    _locale_t _Locale);

   errno_t   strncpy_s(    char * _Dst,   rsize_t _SizeInBytes,    const char * _Src,   rsize_t _MaxCount);


__declspec(deprecated)  char *  strncpy(   char *_Dest,    const char * _Source,   size_t _Count);
   errno_t   _strnset_s(    char * _Str,   size_t _SizeInBytes,   int _Val,   size_t _MaxCount);

__declspec(deprecated)  char *  _strnset(    char *_Dest,   int _Val,   size_t _Count);
     char *   strpbrk(   const char * _Str,    const char * _Control);
     char *   strrchr(   const char * _Str,   int _Ch);
 char *   _strrev(    char * _Str);
   size_t   strspn(   const char * _Str,    const char * _Control);
     char *   strstr(   const char * _Str,    const char * _SubStr);
  __declspec(deprecated)    char *   strtok(    char * _Str,    const char * _Delim);

   char *   strtok_s(    char * _Str,    const char * _Delim,        char ** _Context);

   errno_t   _strupr_s(    char * _Str,   size_t _Size);

__declspec(deprecated)  char *  _strupr( char *_String);
   errno_t   _strupr_s_l(    char * _Str,   size_t _Size, _locale_t _Locale);

__declspec(deprecated)  char *  _strupr_l(    char *_String,    _locale_t _Locale);
   size_t   strxfrm (    char * _Dst,    const char * _Src,   size_t _MaxCount);
   size_t   _strxfrm_l(    char * _Dst,    const char * _Src,   size_t _MaxCount,    _locale_t _Locale);
   wchar_t *   _wcsdup(   const wchar_t * _Str);
   errno_t   wcscat_s(    wchar_t * _Dst,   rsize_t _SizeInWords,    const wchar_t * _Src);


__declspec(deprecated)  wchar_t *  wcscat( wchar_t *_Dest, const wchar_t * _Source);
     wchar_t *   wcschr(   const wchar_t * _Str, wchar_t _Ch);
   int   wcscmp(   const wchar_t * _Str1,    const wchar_t * _Str2);

   errno_t   wcscpy_s(    wchar_t * _Dst,   rsize_t _SizeInWords,    const wchar_t * _Src);


__declspec(deprecated)  wchar_t *  wcscpy( wchar_t *_Dest, const wchar_t * _Source);
   size_t   wcscspn(   const wchar_t * _Str,    const wchar_t * _Control);
   size_t   wcslen(   const wchar_t * _Str);
   size_t   wcsnlen(   const wchar_t * _Src,   size_t _MaxCount);

 static __inline size_t   wcsnlen_s(   const wchar_t * _Src,   size_t _MaxCount)
{
    return (_Src ==  ((void *)0) ) ? 0 : wcsnlen(_Src, _MaxCount);
}


   errno_t   wcsncat_s(    wchar_t * _Dst,   rsize_t _SizeInWords,    const wchar_t * _Src,   rsize_t _MaxCount);


__declspec(deprecated)  wchar_t *  wcsncat(    wchar_t *_Dest,    const wchar_t * _Source,   size_t _Count);
   int   wcsncmp(   const wchar_t * _Str1,    const wchar_t * _Str2,   size_t _MaxCount);

   errno_t   wcsncpy_s(    wchar_t * _Dst,   rsize_t _SizeInWords,    const wchar_t * _Src,   rsize_t _MaxCount);


__declspec(deprecated)  wchar_t *  wcsncpy(   wchar_t *_Dest,    const wchar_t * _Source,   size_t _Count);
     wchar_t *   wcspbrk(   const wchar_t * _Str,    const wchar_t * _Control);
     wchar_t *   wcsrchr(   const wchar_t * _Str,   wchar_t _Ch);
   size_t   wcsspn(   const wchar_t * _Str,    const wchar_t * _Control);
     wchar_t *   wcsstr(   const wchar_t * _Str,    const wchar_t * _SubStr);
  __declspec(deprecated)    wchar_t *   wcstok(    wchar_t * _Str,    const wchar_t * _Delim);

   wchar_t *   wcstok_s(    wchar_t * _Str,    const wchar_t * _Delim,        wchar_t ** _Context);

  __declspec(deprecated)    wchar_t *   _wcserror(  int _ErrNum);
   errno_t   _wcserror_s(    wchar_t * _Buf,   size_t _SizeInWords,   int _ErrNum);

  __declspec(deprecated)    wchar_t *   __wcserror(   const wchar_t * _Str);
   errno_t   __wcserror_s(    wchar_t * _Buffer,   size_t _SizeInWords,    const wchar_t * _ErrMsg);


   int   _wcsicmp(   const wchar_t * _Str1,    const wchar_t * _Str2);
   int   _wcsicmp_l(   const wchar_t * _Str1,    const wchar_t * _Str2,    _locale_t _Locale);
   int   _wcsnicmp(   const wchar_t * _Str1,    const wchar_t * _Str2,   size_t _MaxCount);
   int   _wcsnicmp_l(   const wchar_t * _Str1,    const wchar_t * _Str2,   size_t _MaxCount,    _locale_t _Locale);
   errno_t   _wcsnset_s(    wchar_t * _Dst,   size_t _SizeInWords,   wchar_t _Val,   size_t _MaxCount);

__declspec(deprecated)  wchar_t *  _wcsnset(    wchar_t *_Str, wchar_t _Val,   size_t _MaxCount);
 wchar_t *   _wcsrev(    wchar_t * _Str);
   errno_t   _wcsset_s(    wchar_t * _Dst,   size_t _SizeInWords,   wchar_t _Value);

__declspec(deprecated)  wchar_t *  _wcsset(    wchar_t *_Str, wchar_t _Val);

   errno_t   _wcslwr_s(    wchar_t * _Str,   size_t _SizeInWords);

__declspec(deprecated)  wchar_t *  _wcslwr( wchar_t *_String);
   errno_t   _wcslwr_s_l(    wchar_t * _Str,   size_t _SizeInWords,    _locale_t _Locale);

__declspec(deprecated)  wchar_t *  _wcslwr_l(    wchar_t *_String,    _locale_t _Locale);
   errno_t   _wcsupr_s(    wchar_t * _Str,   size_t _Size);

__declspec(deprecated)  wchar_t *  _wcsupr( wchar_t *_String);
   errno_t   _wcsupr_s_l(    wchar_t * _Str,   size_t _Size,    _locale_t _Locale);

__declspec(deprecated)  wchar_t *  _wcsupr_l(    wchar_t *_String,    _locale_t _Locale);
   size_t   wcsxfrm(    wchar_t * _Dst,    const wchar_t * _Src,   size_t _MaxCount);
   size_t   _wcsxfrm_l(    wchar_t * _Dst,    const wchar_t *_Src,   size_t _MaxCount,    _locale_t _Locale);
   int   wcscoll(   const wchar_t * _Str1,    const wchar_t * _Str2);
   int   _wcscoll_l(   const wchar_t * _Str1,    const wchar_t * _Str2,    _locale_t _Locale);
   int   _wcsicoll(   const wchar_t * _Str1,    const wchar_t * _Str2);
   int   _wcsicoll_l(   const wchar_t * _Str1,    const wchar_t *_Str2,    _locale_t _Locale);
   int   _wcsncoll(   const wchar_t * _Str1,    const wchar_t * _Str2,   size_t _MaxCount);
   int   _wcsncoll_l(   const wchar_t * _Str1,    const wchar_t * _Str2,   size_t _MaxCount,    _locale_t _Locale);
   int   _wcsnicoll(   const wchar_t * _Str1,    const wchar_t * _Str2,   size_t _MaxCount);
   int   _wcsnicoll_l(   const wchar_t * _Str1,    const wchar_t * _Str2,   size_t _MaxCount,    _locale_t _Locale);




typedef struct _OBJECTID {
    GUID Lineage;
    DWORD Uniquifier;
} OBJECTID;

typedef
EXCEPTION_DISPOSITION
(  *PEXCEPTION_ROUTINE) (
     struct _EXCEPTION_RECORD *ExceptionRecord,
     PVOID EstablisherFrame,
       struct _CONTEXT *ContextRecord,
       PVOID DispatcherContext
    );
typedef ULONG_PTR KSPIN_LOCK;
typedef KSPIN_LOCK *PKSPIN_LOCK;

__inline
BOOLEAN
InterlockedBitTestAndSet (
     LONG volatile *Base,
     LONG Bit
    )
{
    __asm {
           mov eax, Bit
           mov ecx, Base
           lock bts [ecx], eax
           setc al
    };
}

__inline
BOOLEAN
InterlockedBitTestAndReset (
     LONG volatile *Base,
     LONG Bit
    )
{
    __asm {
           mov eax, Bit
           mov ecx, Base
           lock btr [ecx], eax
           setc al
    };
}

__inline
BOOLEAN
InterlockedBitTestAndComplement (
     LONG volatile *Base,
     LONG Bit
    )
{
    __asm {
           mov eax, Bit
           mov ecx, Base
           lock btc [ecx], eax
           setc al
    };
}
__inline
void
MemoryBarrier (
    void
    )
{
    LONG Barrier;
    __asm {
        xchg Barrier, eax
    }
}
__inline
DWORD64
ReadPMC (
     DWORD Counter
    )

{

    __asm {
        mov ecx, Counter
        rdpmc
    };
}
__inline
DWORD64
ReadTimeStampCounter (
    void
    )

{

    __asm rdtsc
}

__inline
void
DbgRaiseAssertionFailure (
    void
    )

{
    __asm int 0x2c
}
__inline PVOID GetFiberData( void ) { __asm {
                                        mov eax, fs:[0x10]
                                        mov eax,[eax]
                                        }
                                     }
__inline PVOID GetCurrentFiber( void ) { __asm mov eax, fs:[0x10] }
typedef struct _FLOATING_SAVE_AREA {
    DWORD ControlWord;
    DWORD StatusWord;
    DWORD TagWord;
    DWORD ErrorOffset;
    DWORD ErrorSelector;
    DWORD DataOffset;
    DWORD DataSelector;
    BYTE RegisterArea[ 80 ];
    DWORD Cr0NpxState;
} FLOATING_SAVE_AREA;

typedef FLOATING_SAVE_AREA *PFLOATING_SAVE_AREA;
typedef struct _CONTEXT {
    DWORD ContextFlags;







    DWORD Dr0;
    DWORD Dr1;
    DWORD Dr2;
    DWORD Dr3;
    DWORD Dr6;
    DWORD Dr7;






    FLOATING_SAVE_AREA FloatSave;






    DWORD SegGs;
    DWORD SegFs;
    DWORD SegEs;
    DWORD SegDs;






    DWORD Edi;
    DWORD Esi;
    DWORD Ebx;
    DWORD Edx;
    DWORD Ecx;
    DWORD Eax;






    DWORD Ebp;
    DWORD Eip;
    DWORD SegCs;
    DWORD EFlags;
    DWORD Esp;
    DWORD SegSs;







    BYTE ExtendedRegisters[ 512 ];

} CONTEXT;



typedef CONTEXT *PCONTEXT;








typedef struct _LDT_ENTRY {
    WORD LimitLow;
    WORD BaseLow;
    union {
        struct {
            BYTE BaseMid;
            BYTE Flags1;
            BYTE Flags2;
            BYTE BaseHi;
        } Bytes;
        struct {
            DWORD BaseMid : 8;
            DWORD Type : 5;
            DWORD Dpl : 2;
            DWORD Pres : 1;
            DWORD LimitHi : 4;
            DWORD Sys : 1;
            DWORD Reserved_0 : 1;
            DWORD Default_Big : 1;
            DWORD Granularity : 1;
            DWORD BaseHi : 8;
        } Bits;
    } HighWord;
} LDT_ENTRY, *PLDT_ENTRY;
typedef struct _WOW64_FLOATING_SAVE_AREA {
    DWORD ControlWord;
    DWORD StatusWord;
    DWORD TagWord;
    DWORD ErrorOffset;
    DWORD ErrorSelector;
    DWORD DataOffset;
    DWORD DataSelector;
    BYTE RegisterArea[ 80 ];
    DWORD Cr0NpxState;
} WOW64_FLOATING_SAVE_AREA;

typedef WOW64_FLOATING_SAVE_AREA *PWOW64_FLOATING_SAVE_AREA;
typedef struct _WOW64_CONTEXT {
    DWORD ContextFlags;







    DWORD Dr0;
    DWORD Dr1;
    DWORD Dr2;
    DWORD Dr3;
    DWORD Dr6;
    DWORD Dr7;






    WOW64_FLOATING_SAVE_AREA FloatSave;






    DWORD SegGs;
    DWORD SegFs;
    DWORD SegEs;
    DWORD SegDs;






    DWORD Edi;
    DWORD Esi;
    DWORD Ebx;
    DWORD Edx;
    DWORD Ecx;
    DWORD Eax;






    DWORD Ebp;
    DWORD Eip;
    DWORD SegCs;
    DWORD EFlags;
    DWORD Esp;
    DWORD SegSs;







    BYTE ExtendedRegisters[ 512 ];

} WOW64_CONTEXT;

typedef WOW64_CONTEXT *PWOW64_CONTEXT;








typedef struct _EXCEPTION_RECORD {
    DWORD ExceptionCode;
    DWORD ExceptionFlags;
    struct _EXCEPTION_RECORD *ExceptionRecord;
    PVOID ExceptionAddress;
    DWORD NumberParameters;
    ULONG_PTR ExceptionInformation[ 15 ];
    } EXCEPTION_RECORD;

typedef EXCEPTION_RECORD *PEXCEPTION_RECORD;

typedef struct _EXCEPTION_RECORD32 {
    DWORD ExceptionCode;
    DWORD ExceptionFlags;
    DWORD ExceptionRecord;
    DWORD ExceptionAddress;
    DWORD NumberParameters;
    DWORD ExceptionInformation[ 15 ];
} EXCEPTION_RECORD32, *PEXCEPTION_RECORD32;

typedef struct _EXCEPTION_RECORD64 {
    DWORD ExceptionCode;
    DWORD ExceptionFlags;
    DWORD64 ExceptionRecord;
    DWORD64 ExceptionAddress;
    DWORD NumberParameters;
    DWORD __unusedAlignment;
    DWORD64 ExceptionInformation[ 15 ];
} EXCEPTION_RECORD64, *PEXCEPTION_RECORD64;





typedef struct _EXCEPTION_POINTERS {
    PEXCEPTION_RECORD ExceptionRecord;
    PCONTEXT ContextRecord;
} EXCEPTION_POINTERS, *PEXCEPTION_POINTERS;



__declspec(dllimport)
void

RtlUnwind (
     PVOID TargetFrame  ,
     PVOID TargetIp  ,
     PEXCEPTION_RECORD ExceptionRecord  ,
     PVOID ReturnValue
    );
typedef PVOID PACCESS_TOKEN;
typedef PVOID PSECURITY_DESCRIPTOR;
typedef PVOID PSID;
typedef DWORD ACCESS_MASK;
typedef ACCESS_MASK *PACCESS_MASK;
typedef struct _GENERIC_MAPPING {
    ACCESS_MASK GenericRead;
    ACCESS_MASK GenericWrite;
    ACCESS_MASK GenericExecute;
    ACCESS_MASK GenericAll;
} GENERIC_MAPPING;
typedef GENERIC_MAPPING *PGENERIC_MAPPING;

typedef struct _LUID_AND_ATTRIBUTES {
    LUID Luid;
    DWORD Attributes;
    } LUID_AND_ATTRIBUTES, * PLUID_AND_ATTRIBUTES;
typedef LUID_AND_ATTRIBUTES LUID_AND_ATTRIBUTES_ARRAY[ 1 ];
typedef LUID_AND_ATTRIBUTES_ARRAY *PLUID_AND_ATTRIBUTES_ARRAY;
typedef struct _SID_IDENTIFIER_AUTHORITY {
    BYTE Value[6];
} SID_IDENTIFIER_AUTHORITY, *PSID_IDENTIFIER_AUTHORITY;





typedef struct _SID {
   BYTE Revision;
   BYTE SubAuthorityCount;
   SID_IDENTIFIER_AUTHORITY IdentifierAuthority;



   DWORD SubAuthority[ 1 ];

} SID, *PISID;
typedef enum _SID_NAME_USE {
    SidTypeUser = 1,
    SidTypeGroup,
    SidTypeDomain,
    SidTypeAlias,
    SidTypeWellKnownGroup,
    SidTypeDeletedAccount,
    SidTypeInvalid,
    SidTypeUnknown,
    SidTypeComputer,
    SidTypeLabel
} SID_NAME_USE, *PSID_NAME_USE;

typedef struct _SID_AND_ATTRIBUTES {
    PSID Sid;
    DWORD Attributes;
    } SID_AND_ATTRIBUTES, * PSID_AND_ATTRIBUTES;

typedef SID_AND_ATTRIBUTES SID_AND_ATTRIBUTES_ARRAY[ 1 ];
typedef SID_AND_ATTRIBUTES_ARRAY *PSID_AND_ATTRIBUTES_ARRAY;


typedef ULONG_PTR SID_HASH_ENTRY, *PSID_HASH_ENTRY;

typedef struct _SID_AND_ATTRIBUTES_HASH {
    DWORD SidCount;
    PSID_AND_ATTRIBUTES SidAttr;
    SID_HASH_ENTRY Hash[ 32 ];
} SID_AND_ATTRIBUTES_HASH, *PSID_AND_ATTRIBUTES_HASH;
typedef enum {

    WinNullSid = 0,
    WinWorldSid = 1,
    WinLocalSid = 2,
    WinCreatorOwnerSid = 3,
    WinCreatorGroupSid = 4,
    WinCreatorOwnerServerSid = 5,
    WinCreatorGroupServerSid = 6,
    WinNtAuthoritySid = 7,
    WinDialupSid = 8,
    WinNetworkSid = 9,
    WinBatchSid = 10,
    WinInteractiveSid = 11,
    WinServiceSid = 12,
    WinAnonymousSid = 13,
    WinProxySid = 14,
    WinEnterpriseControllersSid = 15,
    WinSelfSid = 16,
    WinAuthenticatedUserSid = 17,
    WinRestrictedCodeSid = 18,
    WinTerminalServerSid = 19,
    WinRemoteLogonIdSid = 20,
    WinLogonIdsSid = 21,
    WinLocalSystemSid = 22,
    WinLocalServiceSid = 23,
    WinNetworkServiceSid = 24,
    WinBuiltinDomainSid = 25,
    WinBuiltinAdministratorsSid = 26,
    WinBuiltinUsersSid = 27,
    WinBuiltinGuestsSid = 28,
    WinBuiltinPowerUsersSid = 29,
    WinBuiltinAccountOperatorsSid = 30,
    WinBuiltinSystemOperatorsSid = 31,
    WinBuiltinPrintOperatorsSid = 32,
    WinBuiltinBackupOperatorsSid = 33,
    WinBuiltinReplicatorSid = 34,
    WinBuiltinPreWindows2000CompatibleAccessSid = 35,
    WinBuiltinRemoteDesktopUsersSid = 36,
    WinBuiltinNetworkConfigurationOperatorsSid = 37,
    WinAccountAdministratorSid = 38,
    WinAccountGuestSid = 39,
    WinAccountKrbtgtSid = 40,
    WinAccountDomainAdminsSid = 41,
    WinAccountDomainUsersSid = 42,
    WinAccountDomainGuestsSid = 43,
    WinAccountComputersSid = 44,
    WinAccountControllersSid = 45,
    WinAccountCertAdminsSid = 46,
    WinAccountSchemaAdminsSid = 47,
    WinAccountEnterpriseAdminsSid = 48,
    WinAccountPolicyAdminsSid = 49,
    WinAccountRasAndIasServersSid = 50,
    WinNTLMAuthenticationSid = 51,
    WinDigestAuthenticationSid = 52,
    WinSChannelAuthenticationSid = 53,
    WinThisOrganizationSid = 54,
    WinOtherOrganizationSid = 55,
    WinBuiltinIncomingForestTrustBuildersSid = 56,
    WinBuiltinPerfMonitoringUsersSid = 57,
    WinBuiltinPerfLoggingUsersSid = 58,
    WinBuiltinAuthorizationAccessSid = 59,
    WinBuiltinTerminalServerLicenseServersSid = 60,
    WinBuiltinDCOMUsersSid = 61,
    WinBuiltinIUsersSid = 62,
    WinIUserSid = 63,
    WinBuiltinCryptoOperatorsSid = 64,
    WinUntrustedLabelSid = 65,
    WinLowLabelSid = 66,
    WinMediumLabelSid = 67,
    WinHighLabelSid = 68,
    WinSystemLabelSid = 69,
    WinWriteRestrictedCodeSid = 70,
    WinCreatorOwnerRightsSid = 71,
    WinCacheablePrincipalsGroupSid = 72,
    WinNonCacheablePrincipalsGroupSid = 73,
    WinEnterpriseReadonlyControllersSid = 74,
    WinAccountReadonlyControllersSid = 75,
    WinBuiltinEventLogReadersGroup = 76,
    WinNewEnterpriseReadonlyControllersSid = 77,
    WinBuiltinCertSvcDComAccessGroup = 78,
} WELL_KNOWN_SID_TYPE;
typedef struct _ACL {
    BYTE AclRevision;
    BYTE Sbz1;
    WORD AclSize;
    WORD AceCount;
    WORD Sbz2;
} ACL;
typedef ACL *PACL;
typedef struct _ACE_HEADER {
    BYTE AceType;
    BYTE AceFlags;
    WORD AceSize;
} ACE_HEADER;
typedef ACE_HEADER *PACE_HEADER;
typedef struct _ACCESS_ALLOWED_ACE {
    ACE_HEADER Header;
    ACCESS_MASK Mask;
    DWORD SidStart;
} ACCESS_ALLOWED_ACE;

typedef ACCESS_ALLOWED_ACE *PACCESS_ALLOWED_ACE;

typedef struct _ACCESS_DENIED_ACE {
    ACE_HEADER Header;
    ACCESS_MASK Mask;
    DWORD SidStart;
} ACCESS_DENIED_ACE;
typedef ACCESS_DENIED_ACE *PACCESS_DENIED_ACE;

typedef struct _SYSTEM_AUDIT_ACE {
    ACE_HEADER Header;
    ACCESS_MASK Mask;
    DWORD SidStart;
} SYSTEM_AUDIT_ACE;
typedef SYSTEM_AUDIT_ACE *PSYSTEM_AUDIT_ACE;

typedef struct _SYSTEM_ALARM_ACE {
    ACE_HEADER Header;
    ACCESS_MASK Mask;
    DWORD SidStart;
} SYSTEM_ALARM_ACE;
typedef SYSTEM_ALARM_ACE *PSYSTEM_ALARM_ACE;

typedef struct _SYSTEM_MANDATORY_LABEL_ACE {
    ACE_HEADER Header;
    ACCESS_MASK Mask;
    DWORD SidStart;
} SYSTEM_MANDATORY_LABEL_ACE, *PSYSTEM_MANDATORY_LABEL_ACE;
typedef struct _ACCESS_ALLOWED_OBJECT_ACE {
    ACE_HEADER Header;
    ACCESS_MASK Mask;
    DWORD Flags;
    GUID ObjectType;
    GUID InheritedObjectType;
    DWORD SidStart;
} ACCESS_ALLOWED_OBJECT_ACE, *PACCESS_ALLOWED_OBJECT_ACE;

typedef struct _ACCESS_DENIED_OBJECT_ACE {
    ACE_HEADER Header;
    ACCESS_MASK Mask;
    DWORD Flags;
    GUID ObjectType;
    GUID InheritedObjectType;
    DWORD SidStart;
} ACCESS_DENIED_OBJECT_ACE, *PACCESS_DENIED_OBJECT_ACE;

typedef struct _SYSTEM_AUDIT_OBJECT_ACE {
    ACE_HEADER Header;
    ACCESS_MASK Mask;
    DWORD Flags;
    GUID ObjectType;
    GUID InheritedObjectType;
    DWORD SidStart;
} SYSTEM_AUDIT_OBJECT_ACE, *PSYSTEM_AUDIT_OBJECT_ACE;

typedef struct _SYSTEM_ALARM_OBJECT_ACE {
    ACE_HEADER Header;
    ACCESS_MASK Mask;
    DWORD Flags;
    GUID ObjectType;
    GUID InheritedObjectType;
    DWORD SidStart;
} SYSTEM_ALARM_OBJECT_ACE, *PSYSTEM_ALARM_OBJECT_ACE;






typedef struct _ACCESS_ALLOWED_CALLBACK_ACE {
    ACE_HEADER Header;
    ACCESS_MASK Mask;
    DWORD SidStart;

} ACCESS_ALLOWED_CALLBACK_ACE, *PACCESS_ALLOWED_CALLBACK_ACE;

typedef struct _ACCESS_DENIED_CALLBACK_ACE {
    ACE_HEADER Header;
    ACCESS_MASK Mask;
    DWORD SidStart;

} ACCESS_DENIED_CALLBACK_ACE, *PACCESS_DENIED_CALLBACK_ACE;

typedef struct _SYSTEM_AUDIT_CALLBACK_ACE {
    ACE_HEADER Header;
    ACCESS_MASK Mask;
    DWORD SidStart;

} SYSTEM_AUDIT_CALLBACK_ACE, *PSYSTEM_AUDIT_CALLBACK_ACE;

typedef struct _SYSTEM_ALARM_CALLBACK_ACE {
    ACE_HEADER Header;
    ACCESS_MASK Mask;
    DWORD SidStart;

} SYSTEM_ALARM_CALLBACK_ACE, *PSYSTEM_ALARM_CALLBACK_ACE;

typedef struct _ACCESS_ALLOWED_CALLBACK_OBJECT_ACE {
    ACE_HEADER Header;
    ACCESS_MASK Mask;
    DWORD Flags;
    GUID ObjectType;
    GUID InheritedObjectType;
    DWORD SidStart;

} ACCESS_ALLOWED_CALLBACK_OBJECT_ACE, *PACCESS_ALLOWED_CALLBACK_OBJECT_ACE;

typedef struct _ACCESS_DENIED_CALLBACK_OBJECT_ACE {
    ACE_HEADER Header;
    ACCESS_MASK Mask;
    DWORD Flags;
    GUID ObjectType;
    GUID InheritedObjectType;
    DWORD SidStart;

} ACCESS_DENIED_CALLBACK_OBJECT_ACE, *PACCESS_DENIED_CALLBACK_OBJECT_ACE;

typedef struct _SYSTEM_AUDIT_CALLBACK_OBJECT_ACE {
    ACE_HEADER Header;
    ACCESS_MASK Mask;
    DWORD Flags;
    GUID ObjectType;
    GUID InheritedObjectType;
    DWORD SidStart;

} SYSTEM_AUDIT_CALLBACK_OBJECT_ACE, *PSYSTEM_AUDIT_CALLBACK_OBJECT_ACE;

typedef struct _SYSTEM_ALARM_CALLBACK_OBJECT_ACE {
    ACE_HEADER Header;
    ACCESS_MASK Mask;
    DWORD Flags;
    GUID ObjectType;
    GUID InheritedObjectType;
    DWORD SidStart;

} SYSTEM_ALARM_CALLBACK_OBJECT_ACE, *PSYSTEM_ALARM_CALLBACK_OBJECT_ACE;
typedef enum _ACL_INFORMATION_CLASS {
    AclRevisionInformation = 1,
    AclSizeInformation
} ACL_INFORMATION_CLASS;






typedef struct _ACL_REVISION_INFORMATION {
    DWORD AclRevision;
} ACL_REVISION_INFORMATION;
typedef ACL_REVISION_INFORMATION *PACL_REVISION_INFORMATION;





typedef struct _ACL_SIZE_INFORMATION {
    DWORD AceCount;
    DWORD AclBytesInUse;
    DWORD AclBytesFree;
} ACL_SIZE_INFORMATION;
typedef ACL_SIZE_INFORMATION *PACL_SIZE_INFORMATION;
typedef WORD SECURITY_DESCRIPTOR_CONTROL, *PSECURITY_DESCRIPTOR_CONTROL;
typedef struct _SECURITY_DESCRIPTOR_RELATIVE {
    BYTE Revision;
    BYTE Sbz1;
    SECURITY_DESCRIPTOR_CONTROL Control;
    DWORD Owner;
    DWORD Group;
    DWORD Sacl;
    DWORD Dacl;
    } SECURITY_DESCRIPTOR_RELATIVE, *PISECURITY_DESCRIPTOR_RELATIVE;

typedef struct _SECURITY_DESCRIPTOR {
   BYTE Revision;
   BYTE Sbz1;
   SECURITY_DESCRIPTOR_CONTROL Control;
   PSID Owner;
   PSID Group;
   PACL Sacl;
   PACL Dacl;

   } SECURITY_DESCRIPTOR, *PISECURITY_DESCRIPTOR;
typedef struct _OBJECT_TYPE_LIST {
    WORD Level;
    WORD Sbz;
    GUID *ObjectType;
} OBJECT_TYPE_LIST, *POBJECT_TYPE_LIST;
typedef enum _AUDIT_EVENT_TYPE {
    AuditEventObjectAccess,
    AuditEventDirectoryServiceAccess
} AUDIT_EVENT_TYPE, *PAUDIT_EVENT_TYPE;
typedef struct _PRIVILEGE_SET {
    DWORD PrivilegeCount;
    DWORD Control;
    LUID_AND_ATTRIBUTES Privilege[ 1 ];
    } PRIVILEGE_SET, * PPRIVILEGE_SET;
typedef enum _SECURITY_IMPERSONATION_LEVEL {
    SecurityAnonymous,
    SecurityIdentification,
    SecurityImpersonation,
    SecurityDelegation
    } SECURITY_IMPERSONATION_LEVEL, * PSECURITY_IMPERSONATION_LEVEL;
typedef enum _TOKEN_TYPE {
    TokenPrimary = 1,
    TokenImpersonation
    } TOKEN_TYPE;
typedef TOKEN_TYPE *PTOKEN_TYPE;







typedef enum _TOKEN_ELEVATION_TYPE {
    TokenElevationTypeDefault = 1,
    TokenElevationTypeFull,
    TokenElevationTypeLimited,
} TOKEN_ELEVATION_TYPE, *PTOKEN_ELEVATION_TYPE;






typedef enum _TOKEN_INFORMATION_CLASS {
    TokenUser = 1,
    TokenGroups,
    TokenPrivileges,
    TokenOwner,
    TokenPrimaryGroup,
    TokenDefaultDacl,
    TokenSource,
    TokenType,
    TokenImpersonationLevel,
    TokenStatistics,
    TokenRestrictedSids,
    TokenSessionId,
    TokenGroupsAndPrivileges,
    TokenSessionReference,
    TokenSandBoxInert,
    TokenAuditPolicy,
    TokenOrigin,
    TokenElevationType,
    TokenLinkedToken,
    TokenElevation,
    TokenHasRestrictions,
    TokenAccessInformation,
    TokenVirtualizationAllowed,
    TokenVirtualizationEnabled,
    TokenIntegrityLevel,
    TokenUIAccess,
    TokenMandatoryPolicy,
    TokenLogonSid,
    MaxTokenInfoClass
} TOKEN_INFORMATION_CLASS, *PTOKEN_INFORMATION_CLASS;






typedef struct _TOKEN_USER {
    SID_AND_ATTRIBUTES User;
} TOKEN_USER, *PTOKEN_USER;

typedef struct _TOKEN_GROUPS {
    DWORD GroupCount;
    SID_AND_ATTRIBUTES Groups[ 1 ];
} TOKEN_GROUPS, *PTOKEN_GROUPS;


typedef struct _TOKEN_PRIVILEGES {
    DWORD PrivilegeCount;
    LUID_AND_ATTRIBUTES Privileges[ 1 ];
} TOKEN_PRIVILEGES, *PTOKEN_PRIVILEGES;


typedef struct _TOKEN_OWNER {
    PSID Owner;
} TOKEN_OWNER, *PTOKEN_OWNER;


typedef struct _TOKEN_PRIMARY_GROUP {
    PSID PrimaryGroup;
} TOKEN_PRIMARY_GROUP, *PTOKEN_PRIMARY_GROUP;


typedef struct _TOKEN_DEFAULT_DACL {
    PACL DefaultDacl;
} TOKEN_DEFAULT_DACL, *PTOKEN_DEFAULT_DACL;

typedef struct _TOKEN_GROUPS_AND_PRIVILEGES {
    DWORD SidCount;
    DWORD SidLength;
    PSID_AND_ATTRIBUTES Sids;
    DWORD RestrictedSidCount;
    DWORD RestrictedSidLength;
    PSID_AND_ATTRIBUTES RestrictedSids;
    DWORD PrivilegeCount;
    DWORD PrivilegeLength;
    PLUID_AND_ATTRIBUTES Privileges;
    LUID AuthenticationId;
} TOKEN_GROUPS_AND_PRIVILEGES, *PTOKEN_GROUPS_AND_PRIVILEGES;

typedef struct _TOKEN_LINKED_TOKEN {
    HANDLE LinkedToken;
} TOKEN_LINKED_TOKEN, *PTOKEN_LINKED_TOKEN;

typedef struct _TOKEN_ELEVATION {
    DWORD TokenIsElevated;
} TOKEN_ELEVATION, *PTOKEN_ELEVATION;

typedef struct _TOKEN_MANDATORY_LABEL {
    SID_AND_ATTRIBUTES Label;
} TOKEN_MANDATORY_LABEL, *PTOKEN_MANDATORY_LABEL;
typedef struct _TOKEN_MANDATORY_POLICY {
    DWORD Policy;
} TOKEN_MANDATORY_POLICY, *PTOKEN_MANDATORY_POLICY;

typedef struct _TOKEN_ACCESS_INFORMATION {
    PSID_AND_ATTRIBUTES_HASH SidHash;
    PSID_AND_ATTRIBUTES_HASH RestrictedSidHash;
    PTOKEN_PRIVILEGES Privileges;
    LUID AuthenticationId;
    TOKEN_TYPE TokenType;
    SECURITY_IMPERSONATION_LEVEL ImpersonationLevel;
    TOKEN_MANDATORY_POLICY MandatoryPolicy;
    DWORD Flags;
} TOKEN_ACCESS_INFORMATION, *PTOKEN_ACCESS_INFORMATION;







typedef struct _TOKEN_AUDIT_POLICY {
    BYTE PerUserPolicy[(( (52) ) >> 1) + 1];
} TOKEN_AUDIT_POLICY, *PTOKEN_AUDIT_POLICY;



typedef struct _TOKEN_SOURCE {
    CHAR SourceName[ 8 ];
    LUID SourceIdentifier;
} TOKEN_SOURCE, *PTOKEN_SOURCE;


typedef struct _TOKEN_STATISTICS {
    LUID TokenId;
    LUID AuthenticationId;
    LARGE_INTEGER ExpirationTime;
    TOKEN_TYPE TokenType;
    SECURITY_IMPERSONATION_LEVEL ImpersonationLevel;
    DWORD DynamicCharged;
    DWORD DynamicAvailable;
    DWORD GroupCount;
    DWORD PrivilegeCount;
    LUID ModifiedId;
} TOKEN_STATISTICS, *PTOKEN_STATISTICS;



typedef struct _TOKEN_CONTROL {
    LUID TokenId;
    LUID AuthenticationId;
    LUID ModifiedId;
    TOKEN_SOURCE TokenSource;
} TOKEN_CONTROL, *PTOKEN_CONTROL;

typedef struct _TOKEN_ORIGIN {
    LUID OriginatingLogonSession ;
} TOKEN_ORIGIN, * PTOKEN_ORIGIN ;

typedef enum _MANDATORY_LEVEL {
    MandatoryLevelUntrusted = 0,
    MandatoryLevelLow,
    MandatoryLevelMedium,
    MandatoryLevelHigh,
    MandatoryLevelSystem,
    MandatoryLevelSecureProcess,
    MandatoryLevelCount
} MANDATORY_LEVEL, *PMANDATORY_LEVEL;








typedef BOOLEAN SECURITY_CONTEXT_TRACKING_MODE,
                    * PSECURITY_CONTEXT_TRACKING_MODE;







typedef struct _SECURITY_QUALITY_OF_SERVICE {
    DWORD Length;
    SECURITY_IMPERSONATION_LEVEL ImpersonationLevel;
    SECURITY_CONTEXT_TRACKING_MODE ContextTrackingMode;
    BOOLEAN EffectiveOnly;
    } SECURITY_QUALITY_OF_SERVICE, * PSECURITY_QUALITY_OF_SERVICE;






typedef struct _SE_IMPERSONATION_STATE {
    PACCESS_TOKEN Token;
    BOOLEAN CopyOnOpen;
    BOOLEAN EffectiveOnly;
    SECURITY_IMPERSONATION_LEVEL Level;
} SE_IMPERSONATION_STATE, *PSE_IMPERSONATION_STATE;






typedef DWORD SECURITY_INFORMATION, *PSECURITY_INFORMATION;
typedef struct _JOB_SET_ARRAY {
    HANDLE JobHandle;
    DWORD MemberLevel;
    DWORD Flags;
} JOB_SET_ARRAY, *PJOB_SET_ARRAY;




typedef struct _NT_TIB {
    struct _EXCEPTION_REGISTRATION_RECORD *ExceptionList;
    PVOID StackBase;
    PVOID StackLimit;
    PVOID SubSystemTib;






    PVOID FiberData;

    PVOID ArbitraryUserPointer;
    struct _NT_TIB *Self;
} NT_TIB;
typedef NT_TIB *PNT_TIB;




typedef struct _NT_TIB32 {
    DWORD ExceptionList;
    DWORD StackBase;
    DWORD StackLimit;
    DWORD SubSystemTib;






    DWORD FiberData;

    DWORD ArbitraryUserPointer;
    DWORD Self;
} NT_TIB32, *PNT_TIB32;

typedef struct _NT_TIB64 {
    DWORD64 ExceptionList;
    DWORD64 StackBase;
    DWORD64 StackLimit;
    DWORD64 SubSystemTib;






    DWORD64 FiberData;

    DWORD64 ArbitraryUserPointer;
    DWORD64 Self;
} NT_TIB64, *PNT_TIB64;









typedef struct _QUOTA_LIMITS {
    SIZE_T PagedPoolLimit;
    SIZE_T NonPagedPoolLimit;
    SIZE_T MinimumWorkingSetSize;
    SIZE_T MaximumWorkingSetSize;
    SIZE_T PagefileLimit;
    LARGE_INTEGER TimeLimit;
} QUOTA_LIMITS, *PQUOTA_LIMITS;







typedef union _RATE_QUOTA_LIMIT {
    DWORD RateData;
    struct {
        DWORD RatePercent : 7;
        DWORD Reserved0 : 25;
    }  s ;
} RATE_QUOTA_LIMIT, *PRATE_QUOTA_LIMIT;

typedef struct _QUOTA_LIMITS_EX {
    SIZE_T PagedPoolLimit;
    SIZE_T NonPagedPoolLimit;
    SIZE_T MinimumWorkingSetSize;
    SIZE_T MaximumWorkingSetSize;
    SIZE_T PagefileLimit;
    LARGE_INTEGER TimeLimit;
    SIZE_T WorkingSetLimit;
    SIZE_T Reserved2;
    SIZE_T Reserved3;
    SIZE_T Reserved4;
    DWORD Flags;
    RATE_QUOTA_LIMIT CpuRateLimit;
} QUOTA_LIMITS_EX, *PQUOTA_LIMITS_EX;

typedef struct _IO_COUNTERS {
    ULONGLONG ReadOperationCount;
    ULONGLONG WriteOperationCount;
    ULONGLONG OtherOperationCount;
    ULONGLONG ReadTransferCount;
    ULONGLONG WriteTransferCount;
    ULONGLONG OtherTransferCount;
} IO_COUNTERS;
typedef IO_COUNTERS *PIO_COUNTERS;


typedef struct _JOBOBJECT_BASIC_ACCOUNTING_INFORMATION {
    LARGE_INTEGER TotalUserTime;
    LARGE_INTEGER TotalKernelTime;
    LARGE_INTEGER ThisPeriodTotalUserTime;
    LARGE_INTEGER ThisPeriodTotalKernelTime;
    DWORD TotalPageFaultCount;
    DWORD TotalProcesses;
    DWORD ActiveProcesses;
    DWORD TotalTerminatedProcesses;
} JOBOBJECT_BASIC_ACCOUNTING_INFORMATION, *PJOBOBJECT_BASIC_ACCOUNTING_INFORMATION;

typedef struct _JOBOBJECT_BASIC_LIMIT_INFORMATION {
    LARGE_INTEGER PerProcessUserTimeLimit;
    LARGE_INTEGER PerJobUserTimeLimit;
    DWORD LimitFlags;
    SIZE_T MinimumWorkingSetSize;
    SIZE_T MaximumWorkingSetSize;
    DWORD ActiveProcessLimit;
    ULONG_PTR Affinity;
    DWORD PriorityClass;
    DWORD SchedulingClass;
} JOBOBJECT_BASIC_LIMIT_INFORMATION, *PJOBOBJECT_BASIC_LIMIT_INFORMATION;

typedef struct _JOBOBJECT_EXTENDED_LIMIT_INFORMATION {
    JOBOBJECT_BASIC_LIMIT_INFORMATION BasicLimitInformation;
    IO_COUNTERS IoInfo;
    SIZE_T ProcessMemoryLimit;
    SIZE_T JobMemoryLimit;
    SIZE_T PeakProcessMemoryUsed;
    SIZE_T PeakJobMemoryUsed;
} JOBOBJECT_EXTENDED_LIMIT_INFORMATION, *PJOBOBJECT_EXTENDED_LIMIT_INFORMATION;

typedef struct _JOBOBJECT_BASIC_PROCESS_ID_LIST {
    DWORD NumberOfAssignedProcesses;
    DWORD NumberOfProcessIdsInList;
    ULONG_PTR ProcessIdList[1];
} JOBOBJECT_BASIC_PROCESS_ID_LIST, *PJOBOBJECT_BASIC_PROCESS_ID_LIST;

typedef struct _JOBOBJECT_BASIC_UI_RESTRICTIONS {
    DWORD UIRestrictionsClass;
} JOBOBJECT_BASIC_UI_RESTRICTIONS, *PJOBOBJECT_BASIC_UI_RESTRICTIONS;





typedef struct _JOBOBJECT_SECURITY_LIMIT_INFORMATION {
    DWORD SecurityLimitFlags ;
    HANDLE JobToken ;
    PTOKEN_GROUPS SidsToDisable ;
    PTOKEN_PRIVILEGES PrivilegesToDelete ;
    PTOKEN_GROUPS RestrictedSids ;
} JOBOBJECT_SECURITY_LIMIT_INFORMATION, *PJOBOBJECT_SECURITY_LIMIT_INFORMATION ;

typedef struct _JOBOBJECT_END_OF_JOB_TIME_INFORMATION {
    DWORD EndOfJobTimeAction;
} JOBOBJECT_END_OF_JOB_TIME_INFORMATION, *PJOBOBJECT_END_OF_JOB_TIME_INFORMATION;

typedef struct _JOBOBJECT_ASSOCIATE_COMPLETION_PORT {
    PVOID CompletionKey;
    HANDLE CompletionPort;
} JOBOBJECT_ASSOCIATE_COMPLETION_PORT, *PJOBOBJECT_ASSOCIATE_COMPLETION_PORT;

typedef struct _JOBOBJECT_BASIC_AND_IO_ACCOUNTING_INFORMATION {
    JOBOBJECT_BASIC_ACCOUNTING_INFORMATION BasicInfo;
    IO_COUNTERS IoInfo;
} JOBOBJECT_BASIC_AND_IO_ACCOUNTING_INFORMATION, *PJOBOBJECT_BASIC_AND_IO_ACCOUNTING_INFORMATION;

typedef struct _JOBOBJECT_JOBSET_INFORMATION {
    DWORD MemberLevel;
} JOBOBJECT_JOBSET_INFORMATION, *PJOBOBJECT_JOBSET_INFORMATION;
typedef enum _JOBOBJECTINFOCLASS {
    JobObjectBasicAccountingInformation = 1,
    JobObjectBasicLimitInformation,
    JobObjectBasicProcessIdList,
    JobObjectBasicUIRestrictions,
    JobObjectSecurityLimitInformation,
    JobObjectEndOfJobTimeInformation,
    JobObjectAssociateCompletionPortInformation,
    JobObjectBasicAndIoAccountingInformation,
    JobObjectExtendedLimitInformation,
    JobObjectJobSetInformation,
    MaxJobObjectInfoClass
    } JOBOBJECTINFOCLASS;
typedef enum _LOGICAL_PROCESSOR_RELATIONSHIP {
    RelationProcessorCore,
    RelationNumaNode,
    RelationCache,
    RelationProcessorPackage
} LOGICAL_PROCESSOR_RELATIONSHIP;



typedef enum _PROCESSOR_CACHE_TYPE {
    CacheUnified,
    CacheInstruction,
    CacheData,
    CacheTrace
} PROCESSOR_CACHE_TYPE;



typedef struct _CACHE_DESCRIPTOR {
    BYTE Level;
    BYTE Associativity;
    WORD LineSize;
    DWORD Size;
    PROCESSOR_CACHE_TYPE Type;
} CACHE_DESCRIPTOR, *PCACHE_DESCRIPTOR;

typedef struct _SYSTEM_LOGICAL_PROCESSOR_INFORMATION {
    ULONG_PTR ProcessorMask;
    LOGICAL_PROCESSOR_RELATIONSHIP Relationship;
    union {
        struct {
            BYTE Flags;
        } ProcessorCore;
        struct {
            DWORD NodeNumber;
        } NumaNode;
        CACHE_DESCRIPTOR Cache;
        ULONGLONG Reserved[2];
    }  u ;
} SYSTEM_LOGICAL_PROCESSOR_INFORMATION, *PSYSTEM_LOGICAL_PROCESSOR_INFORMATION;
typedef struct _MEMORY_BASIC_INFORMATION {
    PVOID BaseAddress;
    PVOID AllocationBase;
    DWORD AllocationProtect;
    SIZE_T RegionSize;
    DWORD State;
    DWORD Protect;
    DWORD Type;
} MEMORY_BASIC_INFORMATION, *PMEMORY_BASIC_INFORMATION;

typedef struct _MEMORY_BASIC_INFORMATION32 {
    DWORD BaseAddress;
    DWORD AllocationBase;
    DWORD AllocationProtect;
    DWORD RegionSize;
    DWORD State;
    DWORD Protect;
    DWORD Type;
} MEMORY_BASIC_INFORMATION32, *PMEMORY_BASIC_INFORMATION32;

typedef struct   _MEMORY_BASIC_INFORMATION64 {
    ULONGLONG BaseAddress;
    ULONGLONG AllocationBase;
    DWORD AllocationProtect;
    DWORD __alignment1;
    ULONGLONG RegionSize;
    DWORD State;
    DWORD Protect;
    DWORD Type;
    DWORD __alignment2;
} MEMORY_BASIC_INFORMATION64, *PMEMORY_BASIC_INFORMATION64;
typedef struct _FILE_NOTIFY_INFORMATION {
    DWORD NextEntryOffset;
    DWORD Action;
    DWORD FileNameLength;
    WCHAR FileName[1];
} FILE_NOTIFY_INFORMATION, *PFILE_NOTIFY_INFORMATION;






typedef union _FILE_SEGMENT_ELEMENT {
    PVOID64 Buffer;
    ULONGLONG Alignment;
}FILE_SEGMENT_ELEMENT, *PFILE_SEGMENT_ELEMENT;









typedef struct _REPARSE_GUID_DATA_BUFFER {
    DWORD ReparseTag;
    WORD ReparseDataLength;
    WORD Reserved;
    GUID ReparseGuid;
    struct {
        BYTE DataBuffer[1];
    } GenericReparseBuffer;
} REPARSE_GUID_DATA_BUFFER, *PREPARSE_GUID_DATA_BUFFER;
extern const GUID  GUID_MAX_POWER_SAVINGS ;






extern const GUID  GUID_MIN_POWER_SAVINGS ;






extern const GUID  GUID_TYPICAL_POWER_SAVINGS ;







extern const GUID  NO_SUBGROUP_GUID ;







extern const GUID  ALL_POWERSCHEMES_GUID ;
extern const GUID  GUID_POWERSCHEME_PERSONALITY ;








extern const GUID  GUID_ACTIVE_POWERSCHEME ;
extern const GUID  GUID_VIDEO_SUBGROUP ;





extern const GUID  GUID_VIDEO_POWERDOWN_TIMEOUT ;





extern const GUID  GUID_VIDEO_ADAPTIVE_POWERDOWN ;





extern const GUID  GUID_MONITOR_POWER_ON ;







extern const GUID  GUID_DISK_SUBGROUP ;





extern const GUID  GUID_DISK_POWERDOWN_TIMEOUT ;








extern const GUID  GUID_DISK_BURST_IGNORE_THRESHOLD ;





extern const GUID  GUID_DISK_ADAPTIVE_POWERDOWN ;








extern const GUID  GUID_SLEEP_SUBGROUP ;





extern const GUID  GUID_SLEEP_IDLE_THRESHOLD ;





extern const GUID  GUID_STANDBY_TIMEOUT ;








extern const GUID  GUID_UNATTEND_SLEEP_TIMEOUT ;





extern const GUID  GUID_HIBERNATE_TIMEOUT ;





extern const GUID  GUID_HIBERNATE_FASTS4_POLICY ;








extern const GUID  GUID_CRITICAL_POWER_TRANSITION ;





extern const GUID  GUID_SYSTEM_AWAYMODE ;





extern const GUID  GUID_ALLOW_AWAYMODE ;







extern const GUID  GUID_ALLOW_STANDBY_STATES ;






extern const GUID  GUID_ALLOW_RTC_WAKE ;








extern const GUID  GUID_SYSTEM_BUTTON_SUBGROUP ;




extern const GUID  GUID_POWERBUTTON_ACTION ;
extern const GUID  GUID_POWERBUTTON_ACTION_FLAGS ;





extern const GUID  GUID_SLEEPBUTTON_ACTION ;
extern const GUID  GUID_SLEEPBUTTON_ACTION_FLAGS ;






extern const GUID  GUID_USERINTERFACEBUTTON_ACTION ;





extern const GUID  GUID_LIDCLOSE_ACTION ;
extern const GUID  GUID_LIDCLOSE_ACTION_FLAGS ;
extern const GUID  GUID_LIDOPEN_POWERSTATE ;








extern const GUID  GUID_BATTERY_SUBGROUP ;
extern const GUID  GUID_BATTERY_DISCHARGE_ACTION_0 ;
extern const GUID  GUID_BATTERY_DISCHARGE_LEVEL_0 ;
extern const GUID  GUID_BATTERY_DISCHARGE_FLAGS_0 ;

extern const GUID  GUID_BATTERY_DISCHARGE_ACTION_1 ;
extern const GUID  GUID_BATTERY_DISCHARGE_LEVEL_1 ;
extern const GUID  GUID_BATTERY_DISCHARGE_FLAGS_1 ;

extern const GUID  GUID_BATTERY_DISCHARGE_ACTION_2 ;
extern const GUID  GUID_BATTERY_DISCHARGE_LEVEL_2 ;
extern const GUID  GUID_BATTERY_DISCHARGE_FLAGS_2 ;

extern const GUID  GUID_BATTERY_DISCHARGE_ACTION_3 ;
extern const GUID  GUID_BATTERY_DISCHARGE_LEVEL_3 ;
extern const GUID  GUID_BATTERY_DISCHARGE_FLAGS_3 ;








extern const GUID  GUID_PROCESSOR_SETTINGS_SUBGROUP ;


extern const GUID  GUID_PROCESSOR_THROTTLE_POLICY ;







extern const GUID  GUID_PROCESSOR_THROTTLE_MAXIMUM ;







extern const GUID  GUID_PROCESSOR_THROTTLE_MINIMUM ;







extern const GUID  GUID_PROCESSOR_ALLOW_THROTTLING ;





extern const GUID  GUID_PROCESSOR_IDLESTATE_POLICY ;





extern const GUID  GUID_PROCESSOR_PERFSTATE_POLICY ;







extern const GUID  GUID_SYSTEM_COOLING_POLICY ;









extern const GUID  GUID_LOCK_CONSOLE_ON_WAKE ;









extern const GUID  GUID_DEVICE_IDLE_POLICY ;
extern const GUID  GUID_ACDC_POWER_SOURCE ;
extern const GUID  GUID_LIDSWITCH_STATE_CHANGE ;
extern const GUID  GUID_BATTERY_PERCENTAGE_REMAINING ;






extern const GUID  GUID_IDLE_BACKGROUND_TASK ;






extern const GUID  GUID_BACKGROUND_TASK_NOTIFICATION ;







extern const GUID  GUID_APPLAUNCH_BUTTON ;










extern const GUID  GUID_PCIEXPRESS_SETTINGS_SUBGROUP ;





extern const GUID  GUID_PCIEXPRESS_ASPM_POLICY ;


typedef enum _SYSTEM_POWER_STATE {
    PowerSystemUnspecified = 0,
    PowerSystemWorking = 1,
    PowerSystemSleeping1 = 2,
    PowerSystemSleeping2 = 3,
    PowerSystemSleeping3 = 4,
    PowerSystemHibernate = 5,
    PowerSystemShutdown = 6,
    PowerSystemMaximum = 7
} SYSTEM_POWER_STATE, *PSYSTEM_POWER_STATE;



typedef enum {
    PowerActionNone = 0,
    PowerActionReserved,
    PowerActionSleep,
    PowerActionHibernate,
    PowerActionShutdown,
    PowerActionShutdownReset,
    PowerActionShutdownOff,
    PowerActionWarmEject
} POWER_ACTION, *PPOWER_ACTION;

typedef enum _DEVICE_POWER_STATE {
    PowerDeviceUnspecified = 0,
    PowerDeviceD0,
    PowerDeviceD1,
    PowerDeviceD2,
    PowerDeviceD3,
    PowerDeviceMaximum
} DEVICE_POWER_STATE, *PDEVICE_POWER_STATE;









typedef DWORD EXECUTION_STATE;

typedef enum {
    LT_DONT_CARE,
    LT_LOWEST_LATENCY
} LATENCY_TIME;
typedef struct CM_Power_Data_s {
    DWORD PD_Size;
    DEVICE_POWER_STATE PD_MostRecentPowerState;
    DWORD PD_Capabilities;
    DWORD PD_D1Latency;
    DWORD PD_D2Latency;
    DWORD PD_D3Latency;
    DEVICE_POWER_STATE PD_PowerStateMapping[ 7 ];
    SYSTEM_POWER_STATE PD_DeepestSystemWake;
} CM_POWER_DATA, *PCM_POWER_DATA;





typedef enum {
    SystemPowerPolicyAc,
    SystemPowerPolicyDc,
    VerifySystemPolicyAc,
    VerifySystemPolicyDc,
    SystemPowerCapabilities,
    SystemBatteryState,
    SystemPowerStateHandler,
    ProcessorStateHandler,
    SystemPowerPolicyCurrent,
    AdministratorPowerPolicy,
    SystemReserveHiberFile,
    ProcessorInformation,
    SystemPowerInformation,
    ProcessorStateHandler2,
    LastWakeTime,
    LastSleepTime,
    SystemExecutionState,
    SystemPowerStateNotifyHandler,
    ProcessorPowerPolicyAc,
    ProcessorPowerPolicyDc,
    VerifyProcessorPowerPolicyAc,
    VerifyProcessorPowerPolicyDc,
    ProcessorPowerPolicyCurrent,
    SystemPowerStateLogging,
    SystemPowerLoggingEntry,
    SetPowerSettingValue,
    NotifyUserPowerSetting,
    GetPowerTransitionVetoes,
    SetPowerTransitionVeto,
    SystemVideoState,
    TraceApplicationPowerMessage,
    TraceApplicationPowerMessageEnd,
    ProcessorPerfStates,
    ProcessorIdleStates,
    ProcessorThrottleStates,
    SystemWakeSource,
    SystemHiberFileInformation,
    TraceServicePowerMessage,
    ProcessorLoad,
    PowerShutdownNotification,
    MonitorCapabilities
} POWER_INFORMATION_LEVEL;
typedef struct _PO_TRANSITION_VETO_REASON {
    DWORD ResourceId;
    DWORD ModuleNameOffset;
} PO_TRANSITION_VETO_REASON, *PPO_TRANSITION_VETO_REASON;

typedef struct _PO_TRANSITION_VETO_WINDOW {
    HANDLE Handle;
} PO_TRANSITION_VETO_WINDOW, *PPO_TRANSITION_VETO_WINDOW;

typedef struct _PO_TRANSITION_VETO_SERVICE {
    DWORD ServiceNameOffset;
} PO_TRANSITION_VETO_SERVICE, *PPO_TRANSITION_VETO_SERVICE;
typedef struct _PO_TRANSITION_VETO {
    DWORD Type;
    PO_TRANSITION_VETO_REASON Reason;
    DWORD ProcessId;

    union {
        PO_TRANSITION_VETO_WINDOW Window;
        PO_TRANSITION_VETO_SERVICE Service;

    }  u ;
} PO_TRANSITION_VETO, *PPO_TRANSITION_VETO;

typedef struct _PO_TRANSITION_VETOES {
    DWORD Count;
    PO_TRANSITION_VETO Vetoes[ 1 ];
} PO_TRANSITION_VETOES, *PPO_TRANSITION_VETOES;





typedef enum {
    PoAc,
    PoDc,
    PoHot,
    PoConditionMaximum
} SYSTEM_POWER_CONDITION;

typedef struct {





    DWORD Version;





    GUID Guid;






    SYSTEM_POWER_CONDITION PowerCondition;




    DWORD DataLength;




    BYTE Data[ 1 ];
} SET_POWER_SETTING_VALUE, *PSET_POWER_SETTING_VALUE;



typedef struct {
    GUID Guid;
} NOTIFY_USER_POWER_SETTING, *PNOTIFY_USER_POWER_SETTING;






typedef struct _APPLICATIONLAUNCH_SETTING_VALUE {





    LARGE_INTEGER ActivationTime;




    DWORD Flags;




    DWORD ButtonInstanceID;


} APPLICATIONLAUNCH_SETTING_VALUE, *PAPPLICATIONLAUNCH_SETTING_VALUE;





typedef enum {
    PlatformRoleUnspecified = 0,
    PlatformRoleDesktop,
    PlatformRoleMobile,
    PlatformRoleWorkstation,
    PlatformRoleEnterpriseServer,
    PlatformRoleSOHOServer,
    PlatformRoleAppliancePC,
    PlatformRolePerformanceServer,
    PlatformRoleMaximum
} POWER_PLATFORM_ROLE;





typedef enum {
    DeviceWakeSourceType,
    FixedWakeSourceType
} PO_WAKE_SOURCE_TYPE, *PPO_WAKE_SOURCE_TYPE;

typedef enum {
    FixedWakeSourcePowerButton,
    FixedWakeSourceSleepButton,
    FixedWakeSourceRtc
} PO_FIXED_WAKE_SOURCE_TYPE, *PPO_FIXED_WAKE_SOURCE_TYPE;

typedef struct _PO_WAKE_SOURCE_HEADER {
    PO_WAKE_SOURCE_TYPE Type;
    DWORD Size;
} PO_WAKE_SOURCE_HEADER, *PPO_WAKE_SOURCE_HEADER;

typedef struct _PO_WAKE_SOURCE_DEVICE {
    PO_WAKE_SOURCE_HEADER Header;
    WCHAR InstancePath[ 1 ];
} PO_WAKE_SOURCE_DEVICE, *PPO_WAKE_SOURCE_DEVICE;

typedef struct _PO_WAKE_SOURCE_FIXED {
    PO_WAKE_SOURCE_HEADER Header;
    PO_FIXED_WAKE_SOURCE_TYPE FixedWakeSourceType;
} PO_WAKE_SOURCE_FIXED, *PPO_WAKE_SOURCE_FIXED;

typedef struct _PO_WAKE_SOURCE_INFO {
    DWORD Count;
    DWORD Offsets[ 1 ];
} PO_WAKE_SOURCE_INFO, *PPO_WAKE_SOURCE_INFO;

typedef struct _PO_WAKE_SOURCE_HISTORY {
    DWORD Count;
    DWORD Offsets[ 1 ];
} PO_WAKE_SOURCE_HISTORY, *PPO_WAKE_SOURCE_HISTORY;






typedef struct {
    DWORD Granularity;
    DWORD Capacity;
} BATTERY_REPORTING_SCALE, *PBATTERY_REPORTING_SCALE;




typedef struct {
    BOOLEAN Enabled;
    BYTE PercentBusy[ 32 ];
} PPM_SIMULATED_PROCESSOR_LOAD, *PPPM_SIMULATED_PROCESSOR_LOAD;

typedef struct {
    DWORD Frequency;
    DWORD Flags;
    DWORD PercentFrequency;
} PPM_WMI_LEGACY_PERFSTATE, *PPPM_WMI_LEGACY_PERFSTATE;

typedef struct {
    DWORD Latency;
    DWORD Power;
    DWORD TimeCheck;
    BYTE PromotePercent;
    BYTE DemotePercent;
    BYTE StateType;
    BYTE Reserved;
    DWORD StateFlags;
    DWORD Context;
    DWORD IdleHandler;
    DWORD Reserved1;
} PPM_WMI_IDLE_STATE, *PPPM_WMI_IDLE_STATE;

typedef struct {
    DWORD Type;
    DWORD Count;
    DWORD TargetState;
    DWORD OldState;
    DWORD64 TargetProcessors;
    PPM_WMI_IDLE_STATE State[ 1 ];
} PPM_WMI_IDLE_STATES, *PPPM_WMI_IDLE_STATES;

typedef struct {
    DWORD Frequency;
    DWORD Power;
    BYTE PercentFrequency;
    BYTE IncreaseLevel;
    BYTE DecreaseLevel;
    BYTE Type;
    DWORD IncreaseTime;
    DWORD DecreaseTime;
    DWORD64 Control;
    DWORD64 Status;
    DWORD HitCount;
    DWORD Reserved1;
    DWORD64 Reserved2;
    DWORD64 Reserved3;
} PPM_WMI_PERF_STATE, *PPPM_WMI_PERF_STATE;

typedef struct {
    DWORD Count;
    DWORD MaxFrequency;
    DWORD CurrentState;
    DWORD MaxPerfState;
    DWORD MinPerfState;
    DWORD LowestPerfState;
    DWORD ThermalConstraint;
    BYTE BusyAdjThreshold;
    BYTE PolicyType;
    BYTE Type;
    BYTE Reserved;
    DWORD TimerInterval;
    DWORD64 TargetProcessors;
    DWORD PStateHandler;
    DWORD PStateContext;
    DWORD TStateHandler;
    DWORD TStateContext;
    DWORD FeedbackHandler;
    DWORD Reserved1;
    DWORD64 Reserved2;
    PPM_WMI_PERF_STATE State[ 1 ];
} PPM_WMI_PERF_STATES, *PPPM_WMI_PERF_STATES;







typedef struct {
    DWORD IdleTransitions;
    DWORD FailedTransitions;
    DWORD InvalidBucketIndex;
    DWORD64 TotalTime;
    DWORD IdleTimeBuckets[ 6 ];
} PPM_IDLE_STATE_ACCOUNTING, *PPPM_IDLE_STATE_ACCOUNTING;

typedef struct {
    DWORD StateCount;
    DWORD TotalTransitions;
    DWORD ResetCount;
    DWORD64 StartTime;
    PPM_IDLE_STATE_ACCOUNTING State[ 1 ];
} PPM_IDLE_ACCOUNTING, *PPPM_IDLE_ACCOUNTING;
extern const GUID  PPM_PERFSTATE_CHANGE_GUID ;
extern const GUID  PPM_PERFSTATE_DOMAIN_CHANGE_GUID ;
extern const GUID  PPM_IDLESTATE_CHANGE_GUID ;
extern const GUID  PPM_PERFSTATES_DATA_GUID ;
extern const GUID  PPM_IDLESTATES_DATA_GUID ;
extern const GUID  PPM_IDLE_ACCOUNTING_GUID ;
extern const GUID  PPM_THERMALCONSTRAINT_GUID ;
extern const GUID  PPM_PERFMON_PERFSTATE_GUID ;
extern const GUID  PPM_THERMAL_POLICY_CHANGE_GUID ;
typedef struct {
    DWORD State;
    DWORD Status;
    DWORD Latency;
    DWORD Speed;
    DWORD Processor;
} PPM_PERFSTATE_EVENT, *PPPM_PERFSTATE_EVENT;

typedef struct {
    DWORD State;
    DWORD Latency;
    DWORD Speed;
    DWORD64 Processors;
} PPM_PERFSTATE_DOMAIN_EVENT, *PPPM_PERFSTATE_DOMAIN_EVENT;

typedef struct {
    DWORD NewState;
    DWORD OldState;
    DWORD64 Processors;
} PPM_IDLESTATE_EVENT, *PPPM_IDLESTATE_EVENT;

typedef struct {
    DWORD ThermalConstraint;
    DWORD64 Processors;
} PPM_THERMALCHANGE_EVENT, *PPPM_THERMALCHANGE_EVENT;

typedef struct {
    BYTE Mode;
    DWORD64 Processors;
} PPM_THERMAL_POLICY_EVENT, *PPPM_THERMAL_POLICY_EVENT;




typedef struct {
    POWER_ACTION Action;
    DWORD Flags;
    DWORD EventCode;
} POWER_ACTION_POLICY, *PPOWER_ACTION_POLICY;
typedef struct {
    BOOLEAN Enable;
    BYTE Spare[3];
    DWORD BatteryLevel;
    POWER_ACTION_POLICY PowerPolicy;
    SYSTEM_POWER_STATE MinSystemState;
} SYSTEM_POWER_LEVEL, *PSYSTEM_POWER_LEVEL;








typedef struct _SYSTEM_POWER_POLICY {
    DWORD Revision;


    POWER_ACTION_POLICY PowerButton;
    POWER_ACTION_POLICY SleepButton;
    POWER_ACTION_POLICY LidClose;
    SYSTEM_POWER_STATE LidOpenWake;
    DWORD Reserved;


    POWER_ACTION_POLICY Idle;
    DWORD IdleTimeout;
    BYTE IdleSensitivity;

    BYTE DynamicThrottle;
    BYTE Spare2[2];


    SYSTEM_POWER_STATE MinSleep;
    SYSTEM_POWER_STATE MaxSleep;
    SYSTEM_POWER_STATE ReducedLatencySleep;
    DWORD WinLogonFlags;

    DWORD Spare3;



    DWORD DozeS4Timeout;


    DWORD BroadcastCapacityResolution;
    SYSTEM_POWER_LEVEL DischargePolicy[ 4 ];


    DWORD VideoTimeout;
    BOOLEAN VideoDimDisplay;
    DWORD VideoReserved[3];


    DWORD SpindownTimeout;


    BOOLEAN OptimizeForPower;
    BYTE FanThrottleTolerance;
    BYTE ForcedThrottle;
    BYTE MinThrottle;
    POWER_ACTION_POLICY OverThrottled;

} SYSTEM_POWER_POLICY, *PSYSTEM_POWER_POLICY;










typedef struct {
    DWORD TimeCheck;
    BYTE DemotePercent;
    BYTE PromotePercent;
    BYTE Spare[2];
} PROCESSOR_IDLESTATE_INFO, *PPROCESSOR_IDLESTATE_INFO;

typedef struct {
    WORD Revision;
    union {
        WORD AsWORD ;
        struct {
            WORD AllowScaling : 1;
            WORD Disabled : 1;
            WORD Reserved : 14;
        }  s ;
    } Flags;

    DWORD PolicyCount;
    PROCESSOR_IDLESTATE_INFO Policy[ 0x3 ];
} PROCESSOR_IDLESTATE_POLICY, *PPROCESSOR_IDLESTATE_POLICY;
typedef struct _PROCESSOR_POWER_POLICY_INFO {


    DWORD TimeCheck;
    DWORD DemoteLimit;
    DWORD PromoteLimit;


    BYTE DemotePercent;
    BYTE PromotePercent;
    BYTE Spare[2];


    DWORD AllowDemotion:1;
    DWORD AllowPromotion:1;
    DWORD Reserved:30;

} PROCESSOR_POWER_POLICY_INFO, *PPROCESSOR_POWER_POLICY_INFO;


typedef struct _PROCESSOR_POWER_POLICY {
    DWORD Revision;


    BYTE DynamicThrottle;
    BYTE Spare[3];


    DWORD DisableCStates:1;
    DWORD Reserved:31;




    DWORD PolicyCount;
    PROCESSOR_POWER_POLICY_INFO Policy[3];

} PROCESSOR_POWER_POLICY, *PPROCESSOR_POWER_POLICY;










typedef struct {
    DWORD Revision;
    BYTE MaxThrottle;
    BYTE MinThrottle;
    BYTE BusyAdjThreshold;
    union {
        BYTE Spare;
        union {
            BYTE AsBYTE ;
            struct {
                BYTE NoDomainAccounting : 1;
                BYTE IncreasePolicy: 2;
                BYTE DecreasePolicy: 2;
                BYTE Reserved : 3;
            }  s ;
        } Flags;
    }  u ;

    DWORD TimeCheck;
    DWORD IncreaseTime;
    DWORD DecreaseTime;
    DWORD IncreasePercent;
    DWORD DecreasePercent;
} PROCESSOR_PERFSTATE_POLICY, *PPROCESSOR_PERFSTATE_POLICY;


typedef struct _ADMINISTRATOR_POWER_POLICY {


    SYSTEM_POWER_STATE MinSleep;
    SYSTEM_POWER_STATE MaxSleep;


    DWORD MinVideoTimeout;
    DWORD MaxVideoTimeout;


    DWORD MinSpindownTimeout;
    DWORD MaxSpindownTimeout;
} ADMINISTRATOR_POWER_POLICY, *PADMINISTRATOR_POWER_POLICY;




typedef struct {

    BOOLEAN PowerButtonPresent;
    BOOLEAN SleepButtonPresent;
    BOOLEAN LidPresent;
    BOOLEAN SystemS1;
    BOOLEAN SystemS2;
    BOOLEAN SystemS3;
    BOOLEAN SystemS4;
    BOOLEAN SystemS5;
    BOOLEAN HiberFilePresent;
    BOOLEAN FullWake;
    BOOLEAN VideoDimPresent;
    BOOLEAN ApmPresent;
    BOOLEAN UpsPresent;


    BOOLEAN ThermalControl;
    BOOLEAN ProcessorThrottle;
    BYTE ProcessorMinThrottle;





    BYTE ProcessorMaxThrottle;
    BOOLEAN FastSystemS4;
    BYTE spare2[3];



    BOOLEAN DiskSpinDown;
    BYTE spare3[8];


    BOOLEAN SystemBatteriesPresent;
    BOOLEAN BatteriesAreShortTerm;
    BATTERY_REPORTING_SCALE BatteryScale[3];


    SYSTEM_POWER_STATE AcOnLineWake;
    SYSTEM_POWER_STATE SoftLidWake;
    SYSTEM_POWER_STATE RtcWake;
    SYSTEM_POWER_STATE MinDeviceWakeState;
    SYSTEM_POWER_STATE DefaultLowLatencyWake;
} SYSTEM_POWER_CAPABILITIES, *PSYSTEM_POWER_CAPABILITIES;

typedef struct {
    BOOLEAN AcOnLine;
    BOOLEAN BatteryPresent;
    BOOLEAN Charging;
    BOOLEAN Discharging;
    BOOLEAN Spare1[4];

    DWORD MaxCapacity;
    DWORD RemainingCapacity;
    DWORD Rate;
    DWORD EstimatedTime;

    DWORD DefaultAlert1;
    DWORD DefaultAlert2;
} SYSTEM_BATTERY_STATE, *PSYSTEM_BATTERY_STATE;
typedef struct _IMAGE_DOS_HEADER {
    WORD e_magic;
    WORD e_cblp;
    WORD e_cp;
    WORD e_crlc;
    WORD e_cparhdr;
    WORD e_minalloc;
    WORD e_maxalloc;
    WORD e_ss;
    WORD e_sp;
    WORD e_csum;
    WORD e_ip;
    WORD e_cs;
    WORD e_lfarlc;
    WORD e_ovno;
    WORD e_res[4];
    WORD e_oemid;
    WORD e_oeminfo;
    WORD e_res2[10];
    LONG e_lfanew;
  } IMAGE_DOS_HEADER, *PIMAGE_DOS_HEADER;

typedef struct _IMAGE_OS2_HEADER {
    WORD ne_magic;
    CHAR ne_ver;
    CHAR ne_rev;
    WORD ne_enttab;
    WORD ne_cbenttab;
    LONG ne_crc;
    WORD ne_flags;
    WORD ne_autodata;
    WORD ne_heap;
    WORD ne_stack;
    LONG ne_csip;
    LONG ne_sssp;
    WORD ne_cseg;
    WORD ne_cmod;
    WORD ne_cbnrestab;
    WORD ne_segtab;
    WORD ne_rsrctab;
    WORD ne_restab;
    WORD ne_modtab;
    WORD ne_imptab;
    LONG ne_nrestab;
    WORD ne_cmovent;
    WORD ne_align;
    WORD ne_cres;
    BYTE ne_exetyp;
    BYTE ne_flagsothers;
    WORD ne_pretthunks;
    WORD ne_psegrefbytes;
    WORD ne_swaparea;
    WORD ne_expver;
  } IMAGE_OS2_HEADER, *PIMAGE_OS2_HEADER;

typedef struct _IMAGE_VXD_HEADER {
    WORD e32_magic;
    BYTE e32_border;
    BYTE e32_worder;
    DWORD e32_level;
    WORD e32_cpu;
    WORD e32_os;
    DWORD e32_ver;
    DWORD e32_mflags;
    DWORD e32_mpages;
    DWORD e32_startobj;
    DWORD e32_eip;
    DWORD e32_stackobj;
    DWORD e32_esp;
    DWORD e32_pagesize;
    DWORD e32_lastpagesize;
    DWORD e32_fixupsize;
    DWORD e32_fixupsum;
    DWORD e32_ldrsize;
    DWORD e32_ldrsum;
    DWORD e32_objtab;
    DWORD e32_objcnt;
    DWORD e32_objmap;
    DWORD e32_itermap;
    DWORD e32_rsrctab;
    DWORD e32_rsrccnt;
    DWORD e32_restab;
    DWORD e32_enttab;
    DWORD e32_dirtab;
    DWORD e32_dircnt;
    DWORD e32_fpagetab;
    DWORD e32_frectab;
    DWORD e32_impmod;
    DWORD e32_impmodcnt;
    DWORD e32_impproc;
    DWORD e32_pagesum;
    DWORD e32_datapage;
    DWORD e32_preload;
    DWORD e32_nrestab;
    DWORD e32_cbnrestab;
    DWORD e32_nressum;
    DWORD e32_autodata;
    DWORD e32_debuginfo;
    DWORD e32_debuglen;
    DWORD e32_instpreload;
    DWORD e32_instdemand;
    DWORD e32_heapsize;
    BYTE e32_res3[12];
    DWORD e32_winresoff;
    DWORD e32_winreslen;
    WORD e32_devid;
    WORD e32_ddkver;
  } IMAGE_VXD_HEADER, *PIMAGE_VXD_HEADER;






typedef struct _IMAGE_FILE_HEADER {
    WORD Machine;
    WORD NumberOfSections;
    DWORD TimeDateStamp;
    DWORD PointerToSymbolTable;
    DWORD NumberOfSymbols;
    WORD SizeOfOptionalHeader;
    WORD Characteristics;
} IMAGE_FILE_HEADER, *PIMAGE_FILE_HEADER;
typedef struct _IMAGE_DATA_DIRECTORY {
    DWORD VirtualAddress;
    DWORD Size;
} IMAGE_DATA_DIRECTORY, *PIMAGE_DATA_DIRECTORY;







typedef struct _IMAGE_OPTIONAL_HEADER {




    WORD Magic;
    BYTE MajorLinkerVersion;
    BYTE MinorLinkerVersion;
    DWORD SizeOfCode;
    DWORD SizeOfInitializedData;
    DWORD SizeOfUninitializedData;
    DWORD AddressOfEntryPoint;
    DWORD BaseOfCode;
    DWORD BaseOfData;





    DWORD ImageBase;
    DWORD SectionAlignment;
    DWORD FileAlignment;
    WORD MajorOperatingSystemVersion;
    WORD MinorOperatingSystemVersion;
    WORD MajorImageVersion;
    WORD MinorImageVersion;
    WORD MajorSubsystemVersion;
    WORD MinorSubsystemVersion;
    DWORD Win32VersionValue;
    DWORD SizeOfImage;
    DWORD SizeOfHeaders;
    DWORD CheckSum;
    WORD Subsystem;
    WORD DllCharacteristics;
    DWORD SizeOfStackReserve;
    DWORD SizeOfStackCommit;
    DWORD SizeOfHeapReserve;
    DWORD SizeOfHeapCommit;
    DWORD LoaderFlags;
    DWORD NumberOfRvaAndSizes;
    IMAGE_DATA_DIRECTORY DataDirectory[ 16 ];
} IMAGE_OPTIONAL_HEADER32, *PIMAGE_OPTIONAL_HEADER32;

typedef struct _IMAGE_ROM_OPTIONAL_HEADER {
    WORD Magic;
    BYTE MajorLinkerVersion;
    BYTE MinorLinkerVersion;
    DWORD SizeOfCode;
    DWORD SizeOfInitializedData;
    DWORD SizeOfUninitializedData;
    DWORD AddressOfEntryPoint;
    DWORD BaseOfCode;
    DWORD BaseOfData;
    DWORD BaseOfBss;
    DWORD GprMask;
    DWORD CprMask[4];
    DWORD GpValue;
} IMAGE_ROM_OPTIONAL_HEADER, *PIMAGE_ROM_OPTIONAL_HEADER;

typedef struct _IMAGE_OPTIONAL_HEADER64 {
    WORD Magic;
    BYTE MajorLinkerVersion;
    BYTE MinorLinkerVersion;
    DWORD SizeOfCode;
    DWORD SizeOfInitializedData;
    DWORD SizeOfUninitializedData;
    DWORD AddressOfEntryPoint;
    DWORD BaseOfCode;
    ULONGLONG ImageBase;
    DWORD SectionAlignment;
    DWORD FileAlignment;
    WORD MajorOperatingSystemVersion;
    WORD MinorOperatingSystemVersion;
    WORD MajorImageVersion;
    WORD MinorImageVersion;
    WORD MajorSubsystemVersion;
    WORD MinorSubsystemVersion;
    DWORD Win32VersionValue;
    DWORD SizeOfImage;
    DWORD SizeOfHeaders;
    DWORD CheckSum;
    WORD Subsystem;
    WORD DllCharacteristics;
    ULONGLONG SizeOfStackReserve;
    ULONGLONG SizeOfStackCommit;
    ULONGLONG SizeOfHeapReserve;
    ULONGLONG SizeOfHeapCommit;
    DWORD LoaderFlags;
    DWORD NumberOfRvaAndSizes;
    IMAGE_DATA_DIRECTORY DataDirectory[ 16 ];
} IMAGE_OPTIONAL_HEADER64, *PIMAGE_OPTIONAL_HEADER64;










typedef IMAGE_OPTIONAL_HEADER32 IMAGE_OPTIONAL_HEADER;
typedef PIMAGE_OPTIONAL_HEADER32 PIMAGE_OPTIONAL_HEADER;



typedef struct _IMAGE_NT_HEADERS64 {
    DWORD Signature;
    IMAGE_FILE_HEADER FileHeader;
    IMAGE_OPTIONAL_HEADER64 OptionalHeader;
} IMAGE_NT_HEADERS64, *PIMAGE_NT_HEADERS64;

typedef struct _IMAGE_NT_HEADERS {
    DWORD Signature;
    IMAGE_FILE_HEADER FileHeader;
    IMAGE_OPTIONAL_HEADER32 OptionalHeader;
} IMAGE_NT_HEADERS32, *PIMAGE_NT_HEADERS32;

typedef struct _IMAGE_ROM_HEADERS {
    IMAGE_FILE_HEADER FileHeader;
    IMAGE_ROM_OPTIONAL_HEADER OptionalHeader;
} IMAGE_ROM_HEADERS, *PIMAGE_ROM_HEADERS;





typedef IMAGE_NT_HEADERS32 IMAGE_NT_HEADERS;
typedef PIMAGE_NT_HEADERS32 PIMAGE_NT_HEADERS;
typedef struct ANON_OBJECT_HEADER {
    WORD Sig1;
    WORD Sig2;
    WORD Version;
    WORD Machine;
    DWORD TimeDateStamp;
    CLSID ClassID;
    DWORD SizeOfData;
} ANON_OBJECT_HEADER;

typedef struct ANON_OBJECT_HEADER_V2 {
    WORD Sig1;
    WORD Sig2;
    WORD Version;
    WORD Machine;
    DWORD TimeDateStamp;
    CLSID ClassID;
    DWORD SizeOfData;
    DWORD Flags;
    DWORD MetaDataSize;
    DWORD MetaDataOffset;
} ANON_OBJECT_HEADER_V2;






typedef struct _IMAGE_SECTION_HEADER {
    BYTE Name[ 8 ];
    union {
            DWORD PhysicalAddress;
            DWORD VirtualSize;
    } Misc;
    DWORD VirtualAddress;
    DWORD SizeOfRawData;
    DWORD PointerToRawData;
    DWORD PointerToRelocations;
    DWORD PointerToLinenumbers;
    WORD NumberOfRelocations;
    WORD NumberOfLinenumbers;
    DWORD Characteristics;
} IMAGE_SECTION_HEADER, *PIMAGE_SECTION_HEADER;






typedef struct _IMAGE_SYMBOL {
    union {
        BYTE ShortName[8];
        struct {
            DWORD Short;
            DWORD Long;
        } Name;
        DWORD LongName[2];
    } N;
    DWORD Value;
    SHORT SectionNumber;
    WORD Type;
    BYTE StorageClass;
    BYTE NumberOfAuxSymbols;
} IMAGE_SYMBOL;
typedef IMAGE_SYMBOL   *PIMAGE_SYMBOL;
typedef union _IMAGE_AUX_SYMBOL {
    struct {
        DWORD TagIndex;
        union {
            struct {
                WORD Linenumber;
                WORD Size;
            } LnSz;
           DWORD TotalSize;
        } Misc;
        union {
            struct {
                DWORD PointerToLinenumber;
                DWORD PointerToNextFunction;
            } Function;
            struct {
                WORD Dimension[4];
            } Array;
        } FcnAry;
        WORD TvIndex;
    } Sym;
    struct {
        BYTE Name[ 18 ];
    } File;
    struct {
        DWORD Length;
        WORD NumberOfRelocations;
        WORD NumberOfLinenumbers;
        DWORD CheckSum;
        SHORT Number;
        BYTE Selection;
    } Section;
} IMAGE_AUX_SYMBOL;
typedef IMAGE_AUX_SYMBOL   *PIMAGE_AUX_SYMBOL;

typedef enum IMAGE_AUX_SYMBOL_TYPE {
    IMAGE_AUX_SYMBOL_TYPE_TOKEN_DEF = 1,
} IMAGE_AUX_SYMBOL_TYPE;

typedef struct IMAGE_AUX_SYMBOL_TOKEN_DEF {
    BYTE bAuxType;
    BYTE bReserved;
    DWORD SymbolTableIndex;
    BYTE rgbReserved[12];
} IMAGE_AUX_SYMBOL_TOKEN_DEF;

typedef IMAGE_AUX_SYMBOL_TOKEN_DEF   *PIMAGE_AUX_SYMBOL_TOKEN_DEF;
typedef struct _IMAGE_RELOCATION {
    union {
        DWORD VirtualAddress;
        DWORD RelocCount;
    }  u ;
    DWORD SymbolTableIndex;
    WORD Type;
} IMAGE_RELOCATION;
typedef IMAGE_RELOCATION   *PIMAGE_RELOCATION;
typedef struct _IMAGE_LINENUMBER {
    union {
        DWORD SymbolTableIndex;
        DWORD VirtualAddress;
    } Type;
    WORD Linenumber;
} IMAGE_LINENUMBER;
typedef IMAGE_LINENUMBER   *PIMAGE_LINENUMBER;






typedef struct _IMAGE_BASE_RELOCATION {
    DWORD VirtualAddress;
    DWORD SizeOfBlock;

} IMAGE_BASE_RELOCATION;
typedef IMAGE_BASE_RELOCATION   * PIMAGE_BASE_RELOCATION;
typedef struct _IMAGE_ARCHIVE_MEMBER_HEADER {
    BYTE Name[16];
    BYTE Date[12];
    BYTE UserID[6];
    BYTE GroupID[6];
    BYTE Mode[8];
    BYTE Size[10];
    BYTE EndHeader[2];
} IMAGE_ARCHIVE_MEMBER_HEADER, *PIMAGE_ARCHIVE_MEMBER_HEADER;
typedef struct _IMAGE_EXPORT_DIRECTORY {
    DWORD Characteristics;
    DWORD TimeDateStamp;
    WORD MajorVersion;
    WORD MinorVersion;
    DWORD Name;
    DWORD Base;
    DWORD NumberOfFunctions;
    DWORD NumberOfNames;
    DWORD AddressOfFunctions;
    DWORD AddressOfNames;
    DWORD AddressOfNameOrdinals;
} IMAGE_EXPORT_DIRECTORY, *PIMAGE_EXPORT_DIRECTORY;





typedef struct _IMAGE_IMPORT_BY_NAME {
    WORD Hint;
    BYTE Name[1];
} IMAGE_IMPORT_BY_NAME, *PIMAGE_IMPORT_BY_NAME;

typedef struct _IMAGE_THUNK_DATA64 {
    union {
        ULONGLONG ForwarderString;
        ULONGLONG Function;
        ULONGLONG Ordinal;
        ULONGLONG AddressOfData;
    } u1;
} IMAGE_THUNK_DATA64;
typedef IMAGE_THUNK_DATA64 * PIMAGE_THUNK_DATA64;

typedef struct _IMAGE_THUNK_DATA32 {
    union {
        DWORD ForwarderString;
        DWORD Function;
        DWORD Ordinal;
        DWORD AddressOfData;
    } u1;
} IMAGE_THUNK_DATA32;
typedef IMAGE_THUNK_DATA32 * PIMAGE_THUNK_DATA32;
typedef  void
(  *PIMAGE_TLS_CALLBACK) (
    PVOID DllHandle,
    DWORD Reason,
    PVOID Reserved
    );

typedef struct _IMAGE_TLS_DIRECTORY64 {
    ULONGLONG StartAddressOfRawData;
    ULONGLONG EndAddressOfRawData;
    ULONGLONG AddressOfIndex;
    ULONGLONG AddressOfCallBacks;
    DWORD SizeOfZeroFill;
    DWORD Characteristics;
} IMAGE_TLS_DIRECTORY64;
typedef IMAGE_TLS_DIRECTORY64 * PIMAGE_TLS_DIRECTORY64;

typedef struct _IMAGE_TLS_DIRECTORY32 {
    DWORD StartAddressOfRawData;
    DWORD EndAddressOfRawData;
    DWORD AddressOfIndex;
    DWORD AddressOfCallBacks;
    DWORD SizeOfZeroFill;
    DWORD Characteristics;
} IMAGE_TLS_DIRECTORY32;
typedef IMAGE_TLS_DIRECTORY32 * PIMAGE_TLS_DIRECTORY32;
typedef IMAGE_THUNK_DATA32 IMAGE_THUNK_DATA;
typedef PIMAGE_THUNK_DATA32 PIMAGE_THUNK_DATA;

typedef IMAGE_TLS_DIRECTORY32 IMAGE_TLS_DIRECTORY;
typedef PIMAGE_TLS_DIRECTORY32 PIMAGE_TLS_DIRECTORY;


typedef struct _IMAGE_IMPORT_DESCRIPTOR {
    union {
        DWORD Characteristics;
        DWORD OriginalFirstThunk;
    }  u ;
    DWORD TimeDateStamp;




    DWORD ForwarderChain;
    DWORD Name;
    DWORD FirstThunk;
} IMAGE_IMPORT_DESCRIPTOR;
typedef IMAGE_IMPORT_DESCRIPTOR   *PIMAGE_IMPORT_DESCRIPTOR;





typedef struct _IMAGE_BOUND_IMPORT_DESCRIPTOR {
    DWORD TimeDateStamp;
    WORD OffsetModuleName;
    WORD NumberOfModuleForwarderRefs;

} IMAGE_BOUND_IMPORT_DESCRIPTOR, *PIMAGE_BOUND_IMPORT_DESCRIPTOR;

typedef struct _IMAGE_BOUND_FORWARDER_REF {
    DWORD TimeDateStamp;
    WORD OffsetModuleName;
    WORD Reserved;
} IMAGE_BOUND_FORWARDER_REF, *PIMAGE_BOUND_FORWARDER_REF;
typedef struct _IMAGE_RESOURCE_DIRECTORY {
    DWORD Characteristics;
    DWORD TimeDateStamp;
    WORD MajorVersion;
    WORD MinorVersion;
    WORD NumberOfNamedEntries;
    WORD NumberOfIdEntries;

} IMAGE_RESOURCE_DIRECTORY, *PIMAGE_RESOURCE_DIRECTORY;
typedef struct _IMAGE_RESOURCE_DIRECTORY_ENTRY {
    union {
        struct {
            DWORD NameOffset:31;
            DWORD NameIsString:1;
        }  s ;
        DWORD Name;
        WORD Id;
    }  u ;
    union {
        DWORD OffsetToData;
        struct {
            DWORD OffsetToDirectory:31;
            DWORD DataIsDirectory:1;
        }  s2 ;
    }  u2 ;
} IMAGE_RESOURCE_DIRECTORY_ENTRY, *PIMAGE_RESOURCE_DIRECTORY_ENTRY;










typedef struct _IMAGE_RESOURCE_DIRECTORY_STRING {
    WORD Length;
    CHAR NameString[ 1 ];
} IMAGE_RESOURCE_DIRECTORY_STRING, *PIMAGE_RESOURCE_DIRECTORY_STRING;


typedef struct _IMAGE_RESOURCE_DIR_STRING_U {
    WORD Length;
    WCHAR NameString[ 1 ];
} IMAGE_RESOURCE_DIR_STRING_U, *PIMAGE_RESOURCE_DIR_STRING_U;
typedef struct _IMAGE_RESOURCE_DATA_ENTRY {
    DWORD OffsetToData;
    DWORD Size;
    DWORD CodePage;
    DWORD Reserved;
} IMAGE_RESOURCE_DATA_ENTRY, *PIMAGE_RESOURCE_DATA_ENTRY;





typedef struct {
    DWORD Size;
    DWORD TimeDateStamp;
    WORD MajorVersion;
    WORD MinorVersion;
    DWORD GlobalFlagsClear;
    DWORD GlobalFlagsSet;
    DWORD CriticalSectionDefaultTimeout;
    DWORD DeCommitFreeBlockThreshold;
    DWORD DeCommitTotalFreeThreshold;
    DWORD LockPrefixTable;
    DWORD MaximumAllocationSize;
    DWORD VirtualMemoryThreshold;
    DWORD ProcessHeapFlags;
    DWORD ProcessAffinityMask;
    WORD CSDVersion;
    WORD Reserved1;
    DWORD EditList;
    DWORD SecurityCookie;
    DWORD SEHandlerTable;
    DWORD SEHandlerCount;
} IMAGE_LOAD_CONFIG_DIRECTORY32, *PIMAGE_LOAD_CONFIG_DIRECTORY32;

typedef struct {
    DWORD Size;
    DWORD TimeDateStamp;
    WORD MajorVersion;
    WORD MinorVersion;
    DWORD GlobalFlagsClear;
    DWORD GlobalFlagsSet;
    DWORD CriticalSectionDefaultTimeout;
    ULONGLONG DeCommitFreeBlockThreshold;
    ULONGLONG DeCommitTotalFreeThreshold;
    ULONGLONG LockPrefixTable;
    ULONGLONG MaximumAllocationSize;
    ULONGLONG VirtualMemoryThreshold;
    ULONGLONG ProcessAffinityMask;
    DWORD ProcessHeapFlags;
    WORD CSDVersion;
    WORD Reserved1;
    ULONGLONG EditList;
    ULONGLONG SecurityCookie;
    ULONGLONG SEHandlerTable;
    ULONGLONG SEHandlerCount;
} IMAGE_LOAD_CONFIG_DIRECTORY64, *PIMAGE_LOAD_CONFIG_DIRECTORY64;





typedef IMAGE_LOAD_CONFIG_DIRECTORY32 IMAGE_LOAD_CONFIG_DIRECTORY;
typedef PIMAGE_LOAD_CONFIG_DIRECTORY32 PIMAGE_LOAD_CONFIG_DIRECTORY;
typedef struct _IMAGE_CE_RUNTIME_FUNCTION_ENTRY {
    DWORD FuncStart;
    DWORD PrologLen : 8;
    DWORD FuncLen : 22;
    DWORD ThirtyTwoBit : 1;
    DWORD ExceptionFlag : 1;
} IMAGE_CE_RUNTIME_FUNCTION_ENTRY, * PIMAGE_CE_RUNTIME_FUNCTION_ENTRY;

typedef struct _IMAGE_ALPHA64_RUNTIME_FUNCTION_ENTRY {
    ULONGLONG BeginAddress;
    ULONGLONG EndAddress;
    ULONGLONG ExceptionHandler;
    ULONGLONG HandlerData;
    ULONGLONG PrologEndAddress;
} IMAGE_ALPHA64_RUNTIME_FUNCTION_ENTRY, *PIMAGE_ALPHA64_RUNTIME_FUNCTION_ENTRY;

typedef struct _IMAGE_ALPHA_RUNTIME_FUNCTION_ENTRY {
    DWORD BeginAddress;
    DWORD EndAddress;
    DWORD ExceptionHandler;
    DWORD HandlerData;
    DWORD PrologEndAddress;
} IMAGE_ALPHA_RUNTIME_FUNCTION_ENTRY, *PIMAGE_ALPHA_RUNTIME_FUNCTION_ENTRY;

typedef struct _IMAGE_RUNTIME_FUNCTION_ENTRY {
    DWORD BeginAddress;
    DWORD EndAddress;
    DWORD UnwindInfoAddress;
} _IMAGE_RUNTIME_FUNCTION_ENTRY, *_PIMAGE_RUNTIME_FUNCTION_ENTRY;

typedef _IMAGE_RUNTIME_FUNCTION_ENTRY IMAGE_IA64_RUNTIME_FUNCTION_ENTRY;
typedef _PIMAGE_RUNTIME_FUNCTION_ENTRY PIMAGE_IA64_RUNTIME_FUNCTION_ENTRY;
typedef _IMAGE_RUNTIME_FUNCTION_ENTRY IMAGE_RUNTIME_FUNCTION_ENTRY;
typedef _PIMAGE_RUNTIME_FUNCTION_ENTRY PIMAGE_RUNTIME_FUNCTION_ENTRY;







typedef struct _IMAGE_DEBUG_DIRECTORY {
    DWORD Characteristics;
    DWORD TimeDateStamp;
    WORD MajorVersion;
    WORD MinorVersion;
    DWORD Type;
    DWORD SizeOfData;
    DWORD AddressOfRawData;
    DWORD PointerToRawData;
} IMAGE_DEBUG_DIRECTORY, *PIMAGE_DEBUG_DIRECTORY;
typedef struct _IMAGE_COFF_SYMBOLS_HEADER {
    DWORD NumberOfSymbols;
    DWORD LvaToFirstSymbol;
    DWORD NumberOfLinenumbers;
    DWORD LvaToFirstLinenumber;
    DWORD RvaToFirstByteOfCode;
    DWORD RvaToLastByteOfCode;
    DWORD RvaToFirstByteOfData;
    DWORD RvaToLastByteOfData;
} IMAGE_COFF_SYMBOLS_HEADER, *PIMAGE_COFF_SYMBOLS_HEADER;






typedef struct _FPO_DATA {
    DWORD ulOffStart;
    DWORD cbProcSize;
    DWORD cdwLocals;
    WORD cdwParams;
    WORD cbProlog : 8;
    WORD cbRegs : 3;
    WORD fHasSEH : 1;
    WORD fUseBP : 1;
    WORD reserved : 1;
    WORD cbFrame : 2;
} FPO_DATA, *PFPO_DATA;





typedef struct _IMAGE_DEBUG_MISC {
    DWORD DataType;
    DWORD Length;

    BOOLEAN Unicode;
    BYTE Reserved[ 3 ];
    BYTE Data[ 1 ];
} IMAGE_DEBUG_MISC, *PIMAGE_DEBUG_MISC;








typedef struct _IMAGE_FUNCTION_ENTRY {
    DWORD StartingAddress;
    DWORD EndingAddress;
    DWORD EndOfPrologue;
} IMAGE_FUNCTION_ENTRY, *PIMAGE_FUNCTION_ENTRY;

typedef struct _IMAGE_FUNCTION_ENTRY64 {
    ULONGLONG StartingAddress;
    ULONGLONG EndingAddress;
    union {
        ULONGLONG EndOfPrologue;
        ULONGLONG UnwindInfoAddress;
    }  u ;
} IMAGE_FUNCTION_ENTRY64, *PIMAGE_FUNCTION_ENTRY64;
typedef struct _IMAGE_SEPARATE_DEBUG_HEADER {
    WORD Signature;
    WORD Flags;
    WORD Machine;
    WORD Characteristics;
    DWORD TimeDateStamp;
    DWORD CheckSum;
    DWORD ImageBase;
    DWORD SizeOfImage;
    DWORD NumberOfSections;
    DWORD ExportedNamesSize;
    DWORD DebugDirectorySize;
    DWORD SectionAlignment;
    DWORD Reserved[2];
} IMAGE_SEPARATE_DEBUG_HEADER, *PIMAGE_SEPARATE_DEBUG_HEADER;

typedef struct _NON_PAGED_DEBUG_INFO {
    WORD Signature;
    WORD Flags;
    DWORD Size;
    WORD Machine;
    WORD Characteristics;
    DWORD TimeDateStamp;
    DWORD CheckSum;
    DWORD SizeOfImage;
    ULONGLONG ImageBase;


} NON_PAGED_DEBUG_INFO, *PNON_PAGED_DEBUG_INFO;
typedef struct _ImageArchitectureHeader {
    unsigned int AmaskValue: 1;

    int :7;
    unsigned int AmaskShift: 8;
    int :16;
    DWORD FirstEntryRVA;
} IMAGE_ARCHITECTURE_HEADER, *PIMAGE_ARCHITECTURE_HEADER;

typedef struct _ImageArchitectureEntry {
    DWORD FixupInstRVA;
    DWORD NewInst;
} IMAGE_ARCHITECTURE_ENTRY, *PIMAGE_ARCHITECTURE_ENTRY;








typedef struct IMPORT_OBJECT_HEADER {
    WORD Sig1;
    WORD Sig2;
    WORD Version;
    WORD Machine;
    DWORD TimeDateStamp;
    DWORD SizeOfData;

    union {
        WORD Ordinal;
        WORD Hint;
    }  u ;

    WORD Type : 2;
    WORD NameType : 3;
    WORD Reserved : 11;
} IMPORT_OBJECT_HEADER;

typedef enum IMPORT_OBJECT_TYPE
{
    IMPORT_OBJECT_CODE = 0,
    IMPORT_OBJECT_DATA = 1,
    IMPORT_OBJECT_CONST = 2,
} IMPORT_OBJECT_TYPE;

typedef enum IMPORT_OBJECT_NAME_TYPE
{
    IMPORT_OBJECT_ORDINAL = 0,
    IMPORT_OBJECT_NAME = 1,
    IMPORT_OBJECT_NAME_NO_PREFIX = 2,
    IMPORT_OBJECT_NAME_UNDECORATE = 3,

} IMPORT_OBJECT_NAME_TYPE;





typedef enum ReplacesCorHdrNumericDefines
{

    COMIMAGE_FLAGS_ILONLY =0x00000001,
    COMIMAGE_FLAGS_32BITREQUIRED =0x00000002,
    COMIMAGE_FLAGS_IL_LIBRARY =0x00000004,
    COMIMAGE_FLAGS_STRONGNAMESIGNED =0x00000008,
    COMIMAGE_FLAGS_NATIVE_ENTRYPOINT =0x00000010,
    COMIMAGE_FLAGS_TRACKDEBUGDATA =0x00010000,


    COR_VERSION_MAJOR_V2 =2,
    COR_VERSION_MAJOR =COR_VERSION_MAJOR_V2,
    COR_VERSION_MINOR =0,
    COR_DELETED_NAME_LENGTH =8,
    COR_VTABLEGAP_NAME_LENGTH =8,


    NATIVE_TYPE_MAX_CB =1,
    COR_ILMETHOD_SECT_SMALL_MAX_DATASIZE=0xFF,


    IMAGE_COR_MIH_METHODRVA =0x01,
    IMAGE_COR_MIH_EHRVA =0x02,
    IMAGE_COR_MIH_BASICBLOCK =0x08,


    COR_VTABLE_32BIT =0x01,
    COR_VTABLE_64BIT =0x02,
    COR_VTABLE_FROM_UNMANAGED =0x04,
    COR_VTABLE_FROM_UNMANAGED_RETAIN_APPDOMAIN =0x08,
    COR_VTABLE_CALL_MOST_DERIVED =0x10,


    IMAGE_COR_EATJ_THUNK_SIZE =32,



    MAX_CLASS_NAME =1024,
    MAX_PACKAGE_NAME =1024,
} ReplacesCorHdrNumericDefines;


typedef struct IMAGE_COR20_HEADER
{

    DWORD cb;
    WORD MajorRuntimeVersion;
    WORD MinorRuntimeVersion;


    IMAGE_DATA_DIRECTORY MetaData;
    DWORD Flags;



    union {
        DWORD EntryPointToken;
        DWORD EntryPointRVA;
    }  u ;


    IMAGE_DATA_DIRECTORY Resources;
    IMAGE_DATA_DIRECTORY StrongNameSignature;


    IMAGE_DATA_DIRECTORY CodeManagerTable;
    IMAGE_DATA_DIRECTORY VTableFixups;
    IMAGE_DATA_DIRECTORY ExportAddressTableJumps;


    IMAGE_DATA_DIRECTORY ManagedNativeHeader;

} IMAGE_COR20_HEADER, *PIMAGE_COR20_HEADER;
typedef union _SLIST_HEADER {
    ULONGLONG Alignment;
    struct {
        SINGLE_LIST_ENTRY  Next;
        WORD Depth;
        WORD Sequence;
    }  s ;
} SLIST_HEADER, *PSLIST_HEADER;






__declspec(dllimport)
void

RtlInitializeSListHead (
     PSLIST_HEADER ListHead
    );

__declspec(dllimport)
PSINGLE_LIST_ENTRY

RtlFirstEntrySList (
     const SLIST_HEADER *ListHead
    );

__declspec(dllimport)
PSINGLE_LIST_ENTRY

RtlInterlockedPopEntrySList (
     PSLIST_HEADER ListHead
    );

__declspec(dllimport)
PSINGLE_LIST_ENTRY

RtlInterlockedPushEntrySList (
     PSLIST_HEADER ListHead,
      PSINGLE_LIST_ENTRY  ListEntry
    );

__declspec(dllimport)
PSINGLE_LIST_ENTRY

RtlInterlockedFlushSList (
     PSLIST_HEADER ListHead
    );

__declspec(dllimport)
WORD

RtlQueryDepthSList (
     PSLIST_HEADER ListHead
    );
typedef union _RTL_RUN_ONCE {
    PVOID Ptr;
} RTL_RUN_ONCE, *PRTL_RUN_ONCE;

typedef
DWORD
(  *PRTL_RUN_ONCE_INIT_FN) (
     PRTL_RUN_ONCE RunOnce,
     PVOID Parameter,
     PVOID *Context
    );





__declspec(dllimport)
void

RtlRunOnceInitialize (
     PRTL_RUN_ONCE RunOnce
    );

__declspec(dllimport)
DWORD

RtlRunOnceExecuteOnce (
     PRTL_RUN_ONCE RunOnce,
       PRTL_RUN_ONCE_INIT_FN InitFn,
     PVOID Parameter,
     PVOID *Context
    );

__declspec(dllimport)
DWORD

RtlRunOnceBeginInitialize (
     PRTL_RUN_ONCE RunOnce,
     DWORD Flags,
     PVOID *Context
    );

__declspec(dllimport)
DWORD

RtlRunOnceComplete (
     PRTL_RUN_ONCE RunOnce,
     DWORD Flags,
     PVOID Context
    );
__inline
DWORD
HEAP_MAKE_TAG_FLAGS (
     DWORD TagBase,
     DWORD Tag
    )

{
    ;
    return ((DWORD)((TagBase) + ((Tag) <<  18 )));
}



__declspec(dllimport)
WORD

RtlCaptureStackBackTrace(
     DWORD FramesToSkip,
     DWORD FramesToCapture,
     PVOID *BackTrace,
     PDWORD BackTraceHash
   );



__declspec(dllimport)
void

RtlCaptureContext (
     PCONTEXT ContextRecord
    );
__declspec(dllimport)
SIZE_T

RtlCompareMemory (
    const  void  *Source1,
    const  void  *Source2,
    SIZE_T Length
    );
__inline
PVOID
RtlSecureZeroMemory(
     PVOID ptr,
     SIZE_T cnt
    )
{
    volatile char *vptr = (volatile char *)ptr;







    while (cnt) {
        *vptr = 0;
        vptr++;
        cnt--;
    }



    return ptr;
}
typedef struct _MESSAGE_RESOURCE_ENTRY {
    WORD Length;
    WORD Flags;
    BYTE Text[ 1 ];
} MESSAGE_RESOURCE_ENTRY, *PMESSAGE_RESOURCE_ENTRY;



typedef struct _MESSAGE_RESOURCE_BLOCK {
    DWORD LowId;
    DWORD HighId;
    DWORD OffsetToEntries;
} MESSAGE_RESOURCE_BLOCK, *PMESSAGE_RESOURCE_BLOCK;

typedef struct _MESSAGE_RESOURCE_DATA {
    DWORD NumberOfBlocks;
    MESSAGE_RESOURCE_BLOCK Blocks[ 1 ];
} MESSAGE_RESOURCE_DATA, *PMESSAGE_RESOURCE_DATA;


__declspec(dllimport)
PVOID

RtlPcToFileHeader(
    PVOID PcValue,
    PVOID *BaseOfImage
    );

typedef struct _OSVERSIONINFOA {
    DWORD dwOSVersionInfoSize;
    DWORD dwMajorVersion;
    DWORD dwMinorVersion;
    DWORD dwBuildNumber;
    DWORD dwPlatformId;
    CHAR szCSDVersion[ 128 ];
} OSVERSIONINFOA, *POSVERSIONINFOA, *LPOSVERSIONINFOA;

typedef struct _OSVERSIONINFOW {
    DWORD dwOSVersionInfoSize;
    DWORD dwMajorVersion;
    DWORD dwMinorVersion;
    DWORD dwBuildNumber;
    DWORD dwPlatformId;
    WCHAR szCSDVersion[ 128 ];
} OSVERSIONINFOW, *POSVERSIONINFOW, *LPOSVERSIONINFOW, RTL_OSVERSIONINFOW, *PRTL_OSVERSIONINFOW;





typedef OSVERSIONINFOA OSVERSIONINFO;
typedef POSVERSIONINFOA POSVERSIONINFO;
typedef LPOSVERSIONINFOA LPOSVERSIONINFO;


typedef struct _OSVERSIONINFOEXA {
    DWORD dwOSVersionInfoSize;
    DWORD dwMajorVersion;
    DWORD dwMinorVersion;
    DWORD dwBuildNumber;
    DWORD dwPlatformId;
    CHAR szCSDVersion[ 128 ];
    WORD wServicePackMajor;
    WORD wServicePackMinor;
    WORD wSuiteMask;
    BYTE wProductType;
    BYTE wReserved;
} OSVERSIONINFOEXA, *POSVERSIONINFOEXA, *LPOSVERSIONINFOEXA;
typedef struct _OSVERSIONINFOEXW {
    DWORD dwOSVersionInfoSize;
    DWORD dwMajorVersion;
    DWORD dwMinorVersion;
    DWORD dwBuildNumber;
    DWORD dwPlatformId;
    WCHAR szCSDVersion[ 128 ];
    WORD wServicePackMajor;
    WORD wServicePackMinor;
    WORD wSuiteMask;
    BYTE wProductType;
    BYTE wReserved;
} OSVERSIONINFOEXW, *POSVERSIONINFOEXW, *LPOSVERSIONINFOEXW, RTL_OSVERSIONINFOEXW, *PRTL_OSVERSIONINFOEXW;





typedef OSVERSIONINFOEXA OSVERSIONINFOEX;
typedef POSVERSIONINFOEXA POSVERSIONINFOEX;
typedef LPOSVERSIONINFOEXA LPOSVERSIONINFOEX;
__declspec(dllimport)
ULONGLONG

VerSetConditionMask(
         ULONGLONG ConditionMask,
         DWORD TypeMask,
         BYTE Condition
        );






__declspec(dllimport)
BOOLEAN

RtlGetProductInfo(
     DWORD OSMajorVersion,
     DWORD OSMinorVersion,
     DWORD SpMajorVersion,
     DWORD SpMinorVersion,
     PDWORD ReturnedProductType
    );




typedef struct _RTL_CRITICAL_SECTION_DEBUG {
    WORD Type;
    WORD CreatorBackTraceIndex;
    struct _RTL_CRITICAL_SECTION *CriticalSection;
    LIST_ENTRY ProcessLocksList;
    DWORD EntryCount;
    DWORD ContentionCount;
    DWORD Flags;
    WORD CreatorBackTraceIndexHigh;
    WORD SpareWORD ;
} RTL_CRITICAL_SECTION_DEBUG, *PRTL_CRITICAL_SECTION_DEBUG, RTL_RESOURCE_DEBUG, *PRTL_RESOURCE_DEBUG;

typedef struct _RTL_CRITICAL_SECTION {
    PRTL_CRITICAL_SECTION_DEBUG DebugInfo;






    LONG LockCount;
    LONG RecursionCount;
    HANDLE OwningThread;
    HANDLE LockSemaphore;
    ULONG_PTR SpinCount;
} RTL_CRITICAL_SECTION, *PRTL_CRITICAL_SECTION;

typedef struct _RTL_SRWLOCK {
        PVOID Ptr;
} RTL_SRWLOCK, *PRTL_SRWLOCK;

typedef struct _RTL_CONDITION_VARIABLE {
        PVOID Ptr;
} RTL_CONDITION_VARIABLE, *PRTL_CONDITION_VARIABLE;


typedef LONG (  *PVECTORED_EXCEPTION_HANDLER)(
    struct _EXCEPTION_POINTERS *ExceptionInfo
    );

typedef enum _HEAP_INFORMATION_CLASS {

    HeapCompatibilityInformation,
    HeapEnableTerminationOnCorruption


} HEAP_INFORMATION_CLASS;
typedef  void  (  * WAITORTIMERCALLBACKFUNC) (PVOID, BOOLEAN );
typedef  void  (  * WORKERCALLBACKFUNC) (PVOID );
typedef  void  (  * APC_CALLBACK_FUNCTION) (DWORD , PVOID, PVOID);
typedef
void
(  *PFLS_CALLBACK_FUNCTION) (
     PVOID lpFlsData
    );

typedef
BOOLEAN
(  *PSECURE_MEMORY_CACHE_CALLBACK) (
     PVOID Addr,
     SIZE_T Range
    );




typedef enum _ACTIVATION_CONTEXT_INFO_CLASS {
    ActivationContextBasicInformation = 1,
    ActivationContextDetailedInformation = 2,
    AssemblyDetailedInformationInActivationContext = 3,
    FileInformationInAssemblyOfAssemblyInActivationContext = 4,
    RunlevelInformationInActivationContext = 5,
    MaxActivationContextInfoClass,




    AssemblyDetailedInformationInActivationContxt = 3,
    FileInformationInAssemblyOfAssemblyInActivationContxt = 4
} ACTIVATION_CONTEXT_INFO_CLASS;




typedef struct _ACTIVATION_CONTEXT_QUERY_INDEX {
    DWORD ulAssemblyIndex;
    DWORD ulFileIndexInAssembly;
} ACTIVATION_CONTEXT_QUERY_INDEX, * PACTIVATION_CONTEXT_QUERY_INDEX;

typedef const struct _ACTIVATION_CONTEXT_QUERY_INDEX * PCACTIVATION_CONTEXT_QUERY_INDEX;







typedef struct _ASSEMBLY_FILE_DETAILED_INFORMATION {
    DWORD ulFlags;
    DWORD ulFilenameLength;
    DWORD ulPathLength;

    PCWSTR lpFileName;
    PCWSTR lpFilePath;
} ASSEMBLY_FILE_DETAILED_INFORMATION, *PASSEMBLY_FILE_DETAILED_INFORMATION;
typedef const ASSEMBLY_FILE_DETAILED_INFORMATION *PCASSEMBLY_FILE_DETAILED_INFORMATION;










typedef struct _ACTIVATION_CONTEXT_ASSEMBLY_DETAILED_INFORMATION {
    DWORD ulFlags;
    DWORD ulEncodedAssemblyIdentityLength;
    DWORD ulManifestPathType;
    DWORD ulManifestPathLength;
    LARGE_INTEGER liManifestLastWriteTime;
    DWORD ulPolicyPathType;
    DWORD ulPolicyPathLength;
    LARGE_INTEGER liPolicyLastWriteTime;
    DWORD ulMetadataSatelliteRosterIndex;

    DWORD ulManifestVersionMajor;
    DWORD ulManifestVersionMinor;
    DWORD ulPolicyVersionMajor;
    DWORD ulPolicyVersionMinor;
    DWORD ulAssemblyDirectoryNameLength;

    PCWSTR lpAssemblyEncodedAssemblyIdentity;
    PCWSTR lpAssemblyManifestPath;
    PCWSTR lpAssemblyPolicyPath;
    PCWSTR lpAssemblyDirectoryName;

    DWORD ulFileCount;
} ACTIVATION_CONTEXT_ASSEMBLY_DETAILED_INFORMATION, * PACTIVATION_CONTEXT_ASSEMBLY_DETAILED_INFORMATION;

typedef const struct _ACTIVATION_CONTEXT_ASSEMBLY_DETAILED_INFORMATION * PCACTIVATION_CONTEXT_ASSEMBLY_DETAILED_INFORMATION ;

typedef enum
{
    ACTCTX_RUN_LEVEL_UNSPECIFIED = 0,
    ACTCTX_RUN_LEVEL_AS_INVOKER,
    ACTCTX_RUN_LEVEL_HIGHEST_AVAILABLE,
    ACTCTX_RUN_LEVEL_REQUIRE_ADMIN,
    ACTCTX_RUN_LEVEL_NUMBERS
} ACTCTX_REQUESTED_RUN_LEVEL;

typedef struct _ACTIVATION_CONTEXT_RUN_LEVEL_INFORMATION {
    DWORD ulFlags;
    ACTCTX_REQUESTED_RUN_LEVEL RunLevel;
    DWORD UiAccess;
} ACTIVATION_CONTEXT_RUN_LEVEL_INFORMATION, * PACTIVATION_CONTEXT_RUN_LEVEL_INFORMATION;

typedef const struct _ACTIVATION_CONTEXT_RUN_LEVEL_INFORMATION * PCACTIVATION_CONTEXT_RUN_LEVEL_INFORMATION ;

typedef struct _ACTIVATION_CONTEXT_DETAILED_INFORMATION {
    DWORD dwFlags;
    DWORD ulFormatVersion;
    DWORD ulAssemblyCount;
    DWORD ulRootManifestPathType;
    DWORD ulRootManifestPathChars;
    DWORD ulRootConfigurationPathType;
    DWORD ulRootConfigurationPathChars;
    DWORD ulAppDirPathType;
    DWORD ulAppDirPathChars;
    PCWSTR lpRootManifestPath;
    PCWSTR lpRootConfigurationPath;
    PCWSTR lpAppDirPath;
} ACTIVATION_CONTEXT_DETAILED_INFORMATION, *PACTIVATION_CONTEXT_DETAILED_INFORMATION;

typedef const struct _ACTIVATION_CONTEXT_DETAILED_INFORMATION *PCACTIVATION_CONTEXT_DETAILED_INFORMATION;
typedef struct _EVENTLOGRECORD {
    DWORD Length;
    DWORD Reserved;
    DWORD RecordNumber;
    DWORD TimeGenerated;
    DWORD TimeWritten;
    DWORD EventID;
    WORD EventType;
    WORD NumStrings;
    WORD EventCategory;
    WORD ReservedFlags;
    DWORD ClosingRecordNumber;
    DWORD StringOffset;
    DWORD UserSidLength;
    DWORD UserSidOffset;
    DWORD DataLength;
    DWORD DataOffset;
} EVENTLOGRECORD, *PEVENTLOGRECORD;

struct _EVENTSFORLOGFILE;
typedef struct _EVENTSFORLOGFILE EVENTSFORLOGFILE, *PEVENTSFORLOGFILE;

struct _PACKEDEVENTINFO;
typedef struct _PACKEDEVENTINFO PACKEDEVENTINFO, *PPACKEDEVENTINFO;
typedef enum _CM_SERVICE_NODE_TYPE {
    DriverType =  0x00000001 ,
    FileSystemType =  0x00000002 ,
    Win32ServiceOwnProcess =  0x00000010 ,
    Win32ServiceShareProcess =  0x00000020 ,
    AdapterType =  0x00000004 ,
    RecognizerType =  0x00000008
} SERVICE_NODE_TYPE;

typedef enum _CM_SERVICE_LOAD_TYPE {
    BootLoad =  0x00000000 ,
    SystemLoad =  0x00000001 ,
    AutoLoad =  0x00000002 ,
    DemandLoad =  0x00000003 ,
    DisableLoad =  0x00000004
} SERVICE_LOAD_TYPE;

typedef enum _CM_ERROR_CONTROL_TYPE {
    IgnoreError =  0x00000000 ,
    NormalError =  0x00000001 ,
    SevereError =  0x00000002 ,
    CriticalError =  0x00000003
} SERVICE_ERROR_TYPE;
typedef struct _TAPE_ERASE {
    DWORD Type;
    BOOLEAN Immediate;
} TAPE_ERASE, *PTAPE_ERASE;
typedef struct _TAPE_PREPARE {
    DWORD Operation;
    BOOLEAN Immediate;
} TAPE_PREPARE, *PTAPE_PREPARE;










typedef struct _TAPE_WRITE_MARKS {
    DWORD Type;
    DWORD Count;
    BOOLEAN Immediate;
} TAPE_WRITE_MARKS, *PTAPE_WRITE_MARKS;









typedef struct _TAPE_GET_POSITION {
    DWORD Type;
    DWORD Partition;
    LARGE_INTEGER Offset;
} TAPE_GET_POSITION, *PTAPE_GET_POSITION;
typedef struct _TAPE_SET_POSITION {
    DWORD Method;
    DWORD Partition;
    LARGE_INTEGER Offset;
    BOOLEAN Immediate;
} TAPE_SET_POSITION, *PTAPE_SET_POSITION;
typedef struct _TAPE_GET_DRIVE_PARAMETERS {
    BOOLEAN ECC;
    BOOLEAN Compression;
    BOOLEAN DataPadding;
    BOOLEAN ReportSetmarks;
    DWORD DefaultBlockSize;
    DWORD MaximumBlockSize;
    DWORD MinimumBlockSize;
    DWORD MaximumPartitionCount;
    DWORD FeaturesLow;
    DWORD FeaturesHigh;
    DWORD EOTWarningZoneSize;
} TAPE_GET_DRIVE_PARAMETERS, *PTAPE_GET_DRIVE_PARAMETERS;





typedef struct _TAPE_SET_DRIVE_PARAMETERS {
    BOOLEAN ECC;
    BOOLEAN Compression;
    BOOLEAN DataPadding;
    BOOLEAN ReportSetmarks;
    DWORD EOTWarningZoneSize;
} TAPE_SET_DRIVE_PARAMETERS, *PTAPE_SET_DRIVE_PARAMETERS;





typedef struct _TAPE_GET_MEDIA_PARAMETERS {
    LARGE_INTEGER Capacity;
    LARGE_INTEGER Remaining;
    DWORD BlockSize;
    DWORD PartitionCount;
    BOOLEAN WriteProtected;
} TAPE_GET_MEDIA_PARAMETERS, *PTAPE_GET_MEDIA_PARAMETERS;





typedef struct _TAPE_SET_MEDIA_PARAMETERS {
    DWORD BlockSize;
} TAPE_SET_MEDIA_PARAMETERS, *PTAPE_SET_MEDIA_PARAMETERS;









typedef struct _TAPE_CREATE_PARTITION {
    DWORD Method;
    DWORD Count;
    DWORD Size;
} TAPE_CREATE_PARTITION, *PTAPE_CREATE_PARTITION;
typedef struct _TAPE_WMI_OPERATIONS {
   DWORD Method;
   DWORD DataBufferSize;
   PVOID DataBuffer;
} TAPE_WMI_OPERATIONS, *PTAPE_WMI_OPERATIONS;




typedef enum _TAPE_DRIVE_PROBLEM_TYPE {
   TapeDriveProblemNone, TapeDriveReadWriteWarning,
   TapeDriveReadWriteError, TapeDriveReadWarning,
   TapeDriveWriteWarning, TapeDriveReadError,
   TapeDriveWriteError, TapeDriveHardwareError,
   TapeDriveUnsupportedMedia, TapeDriveScsiConnectionError,
   TapeDriveTimetoClean, TapeDriveCleanDriveNow,
   TapeDriveMediaLifeExpired, TapeDriveSnappedTape
} TAPE_DRIVE_PROBLEM_TYPE;
typedef GUID UOW, *PUOW;
typedef GUID CRM_PROTOCOL_ID, *PCRM_PROTOCOL_ID;
typedef ULONG NOTIFICATION_MASK;
typedef struct _TRANSACTION_NOTIFICATION {
    PVOID TransactionKey;
    ULONG TransactionNotification;
    LARGE_INTEGER TmVirtualClock;
    ULONG ArgumentLength;
} TRANSACTION_NOTIFICATION, *PTRANSACTION_NOTIFICATION;

typedef struct _TRANSACTION_NOTIFICATION_RECOVERY_ARGUMENT {
    GUID EnlistmentId;
    UOW UOW;
} TRANSACTION_NOTIFICATION_RECOVERY_ARGUMENT, *PTRANSACTION_NOTIFICATION_RECOVERY_ARGUMENT;



typedef struct _TRANSACTION_NOTIFICATION_TM_ONLINE_ARGUMENT {
    GUID TmIdentity;
    ULONG Flags;
} TRANSACTION_NOTIFICATION_TM_ONLINE_ARGUMENT, *PTRANSACTION_NOTIFICATION_TM_ONLINE_ARGUMENT;

typedef ULONG SAVEPOINT_ID, *PSAVEPOINT_ID;

typedef struct _TRANSACTION_NOTIFICATION_SAVEPOINT_ARGUMENT {
    SAVEPOINT_ID SavepointId;
} TRANSACTION_NOTIFICATION_SAVEPOINT_ARGUMENT, *PTRANSACTION_NOTIFICATION_SAVEPOINT_ARGUMENT;

typedef struct _TRANSACTION_NOTIFICATION_PROPAGATE_ARGUMENT {
    ULONG PropagationCookie;
    GUID UOW;
    GUID TmIdentity;
    ULONG BufferLength;

} TRANSACTION_NOTIFICATION_PROPAGATE_ARGUMENT, *PTRANSACTION_NOTIFICATION_PROPAGATE_ARGUMENT;

typedef struct _TRANSACTION_NOTIFICATION_MARSHAL_ARGUMENT {
    ULONG MarshalCookie;
    GUID UOW;
} TRANSACTION_NOTIFICATION_MARSHAL_ARGUMENT, *PTRANSACTION_NOTIFICATION_MARSHAL_ARGUMENT;

typedef TRANSACTION_NOTIFICATION_PROPAGATE_ARGUMENT TRANSACTION_NOTIFICATION_PROMOTE_ARGUMENT, *PTRANSACTION_NOTIFICATION_PROMOTE_ARGUMENT;







typedef struct _KCRM_MARSHAL_HEADER {
    ULONG VersionMajor;
    ULONG VersionMinor;
    ULONG NumProtocols;
    ULONG Unused;
} KCRM_MARSHAL_HEADER, *PKCRM_MARSHAL_HEADER, *  PRKCRM_MARSHAL_HEADER;

typedef struct _KCRM_TRANSACTION_BLOB {
    UOW UOW;
    GUID TmIdentity;
    ULONG IsolationLevel;
    ULONG IsolationFlags;
    ULONG Timeout;
    WCHAR Description[ 64 ];
} KCRM_TRANSACTION_BLOB, *PKCRM_TRANSACTION_BLOB, *  PRKCRM_TRANSACTION_BLOB;

typedef struct _KCRM_PROTOCOL_BLOB {
    CRM_PROTOCOL_ID ProtocolId;
     ULONG StaticInfoLength;
    ULONG TransactionIdInfoLength;
    ULONG Unused1;
    ULONG Unused2;
} KCRM_PROTOCOL_BLOB, *PKCRM_PROTOCOL_BLOB, *  PRKCRM_PROTOCOL_BLOB;
typedef enum _TRANSACTION_OUTCOME {
    TransactionOutcomeUndetermined = 1,
    TransactionOutcomeCommitted,
    TransactionOutcomeAborted,
} TRANSACTION_OUTCOME;


typedef enum _TRANSACTION_STATE {
    TransactionStateNormal = 1,
    TransactionStateIndoubt,
    TransactionStateCommittedNotify,
} TRANSACTION_STATE;


typedef struct _TRANSACTION_BASIC_INFORMATION {
    GUID TransactionId;
    DWORD State;
    DWORD Outcome;
} TRANSACTION_BASIC_INFORMATION, *PTRANSACTION_BASIC_INFORMATION;

typedef struct _TRANSACTIONMANAGER_BASIC_INFORMATION {
    GUID TmIdentity;
    LARGE_INTEGER VirtualClock;
} TRANSACTIONMANAGER_BASIC_INFORMATION, *PTRANSACTIONMANAGER_BASIC_INFORMATION;

typedef struct _TRANSACTIONMANAGER_LOG_INFORMATION {
    GUID LogIdentity;
} TRANSACTIONMANAGER_LOG_INFORMATION, *PTRANSACTIONMANAGER_LOG_INFORMATION;

typedef struct _TRANSACTIONMANAGER_LOGPATH_INFORMATION {
    DWORD LogPathLength;
     WCHAR LogPath[1];

} TRANSACTIONMANAGER_LOGPATH_INFORMATION, *PTRANSACTIONMANAGER_LOGPATH_INFORMATION;

typedef struct _TRANSACTIONMANAGER_RECOVERY_INFORMATION {
    ULONGLONG LastRecoveredLsn;
} TRANSACTIONMANAGER_RECOVERY_INFORMATION, *PTRANSACTIONMANAGER_RECOVERY_INFORMATION;



typedef struct _TRANSACTIONMANAGER_OLDEST_INFORMATION {
    GUID OldestTransactionGuid;
} TRANSACTIONMANAGER_OLDEST_INFORMATION, *PTRANSACTIONMANAGER_OLDEST_INFORMATION;



typedef struct _TRANSACTION_PROPERTIES_INFORMATION {
    DWORD IsolationLevel;
    DWORD IsolationFlags;
    LARGE_INTEGER Timeout;
    DWORD Outcome;
    DWORD DescriptionLength;
    WCHAR Description[1];

} TRANSACTION_PROPERTIES_INFORMATION, *PTRANSACTION_PROPERTIES_INFORMATION;



typedef struct _TRANSACTION_BIND_INFORMATION {
    HANDLE TmHandle;
} TRANSACTION_BIND_INFORMATION, *PTRANSACTION_BIND_INFORMATION;

typedef struct _TRANSACTION_ENLISTMENT_PAIR {
    GUID EnlistmentId;
    GUID ResourceManagerId;
} TRANSACTION_ENLISTMENT_PAIR, *PTRANSACTION_ENLISTMENT_PAIR;

typedef struct _TRANSACTION_ENLISTMENTS_INFORMATION {
    DWORD NumberOfEnlistments;
    TRANSACTION_ENLISTMENT_PAIR EnlistmentPair[1];
} TRANSACTION_ENLISTMENTS_INFORMATION, *PTRANSACTION_ENLISTMENTS_INFORMATION;

typedef struct _TRANSACTION_SUPERIOR_ENLISTMENT_INFORMATION {
    TRANSACTION_ENLISTMENT_PAIR SuperiorEnlistmentPair;
} TRANSACTION_SUPERIOR_ENLISTMENT_INFORMATION, *PTRANSACTION_SUPERIOR_ENLISTMENT_INFORMATION;


typedef struct _RESOURCEMANAGER_BASIC_INFORMATION {
    GUID ResourceManagerId;
    DWORD DescriptionLength;
    WCHAR Description[1];
} RESOURCEMANAGER_BASIC_INFORMATION, *PRESOURCEMANAGER_BASIC_INFORMATION;

typedef struct _RESOURCEMANAGER_COMPLETION_INFORMATION {
    HANDLE IoCompletionPortHandle;
    ULONG_PTR CompletionKey;
} RESOURCEMANAGER_COMPLETION_INFORMATION, *PRESOURCEMANAGER_COMPLETION_INFORMATION;




typedef enum _TRANSACTION_INFORMATION_CLASS {
    TransactionBasicInformation,
    TransactionPropertiesInformation,
    TransactionEnlistmentInformation,
    TransactionSuperiorEnlistmentInformation

    ,


    TransactionBindInformation,
    TransactionDTCPrivateInformation
    ,

} TRANSACTION_INFORMATION_CLASS;


typedef enum _TRANSACTIONMANAGER_INFORMATION_CLASS {
    TransactionManagerBasicInformation,
    TransactionManagerLogInformation,
    TransactionManagerLogPathInformation,
    TransactionManagerRecoveryInformation = 4

    ,



    TransactionManagerOnlineProbeInformation = 3,
    TransactionManagerOldestTransactionInformation = 5



} TRANSACTIONMANAGER_INFORMATION_CLASS;



typedef enum _RESOURCEMANAGER_INFORMATION_CLASS {
    ResourceManagerBasicInformation,
    ResourceManagerCompletionInformation,
} RESOURCEMANAGER_INFORMATION_CLASS;


typedef struct _ENLISTMENT_BASIC_INFORMATION {
    GUID EnlistmentId;
    GUID TransactionId;
    GUID ResourceManagerId;
} ENLISTMENT_BASIC_INFORMATION, *PENLISTMENT_BASIC_INFORMATION;

typedef struct _ENLISTMENT_CRM_INFORMATION {
    GUID CrmTransactionManagerId;
    GUID CrmResourceManagerId;
    GUID CrmEnlistmentId;
} ENLISTMENT_CRM_INFORMATION, *PENLISTMENT_CRM_INFORMATION;



typedef enum _ENLISTMENT_INFORMATION_CLASS {
    EnlistmentBasicInformation,
    EnlistmentRecoveryInformation,
    EnlistmentCrmInformation
} ENLISTMENT_INFORMATION_CLASS;

typedef struct _TRANSACTION_LIST_ENTRY {
    UOW UOW;
} TRANSACTION_LIST_ENTRY, *PTRANSACTION_LIST_ENTRY;

typedef struct _TRANSACTION_LIST_INFORMATION {
    DWORD NumberOfTransactions;
    TRANSACTION_LIST_ENTRY TransactionInformation[1];
} TRANSACTION_LIST_INFORMATION, *PTRANSACTION_LIST_INFORMATION;






typedef enum _KTMOBJECT_TYPE {

    KTMOBJECT_TRANSACTION,
    KTMOBJECT_TRANSACTION_MANAGER,
    KTMOBJECT_RESOURCE_MANAGER,
    KTMOBJECT_ENLISTMENT,
    KTMOBJECT_INVALID

} KTMOBJECT_TYPE, *PKTMOBJECT_TYPE;









typedef struct _KTMOBJECT_CURSOR {





    GUID LastQuery;





    DWORD ObjectIdCount;





    GUID ObjectIds[1];

} KTMOBJECT_CURSOR, *PKTMOBJECT_CURSOR;
typedef DWORD TP_VERSION, *PTP_VERSION;

typedef struct _TP_CALLBACK_INSTANCE TP_CALLBACK_INSTANCE, *PTP_CALLBACK_INSTANCE;

typedef  void  (  *PTP_SIMPLE_CALLBACK)(
     PTP_CALLBACK_INSTANCE Instance,
     PVOID Context
    );

typedef struct _TP_POOL TP_POOL, *PTP_POOL;
typedef struct _TP_CLEANUP_GROUP TP_CLEANUP_GROUP, *PTP_CLEANUP_GROUP;

typedef  void  (  *PTP_CLEANUP_GROUP_CANCEL_CALLBACK)(
     PVOID ObjectContext,
     PVOID CleanupContext
    );






typedef struct _TP_CALLBACK_ENVIRON {
    TP_VERSION Version;
    PTP_POOL Pool;
    PTP_CLEANUP_GROUP CleanupGroup;
    PTP_CLEANUP_GROUP_CANCEL_CALLBACK CleanupGroupCancelCallback;
    PVOID RaceDll;
    struct _ACTIVATION_CONTEXT *ActivationContext;
    PTP_SIMPLE_CALLBACK FinalizationCallback;
    union {
        DWORD Flags;
        struct {
            DWORD LongFunction : 1;
            DWORD Private : 31;
        } s;
    } u;
} TP_CALLBACK_ENVIRON, *PTP_CALLBACK_ENVIRON;



__inline
void
TpInitializeCallbackEnviron(
     PTP_CALLBACK_ENVIRON CallbackEnviron
    )
{
    CallbackEnviron->Version = 1;
    CallbackEnviron->Pool =  ((void *)0) ;
    CallbackEnviron->CleanupGroup =  ((void *)0) ;
    CallbackEnviron->CleanupGroupCancelCallback =  ((void *)0) ;
    CallbackEnviron->RaceDll =  ((void *)0) ;
    CallbackEnviron->ActivationContext =  ((void *)0) ;
    CallbackEnviron->FinalizationCallback =  ((void *)0) ;
    CallbackEnviron->u.Flags = 0;
}

__inline
void
TpSetCallbackThreadpool(
     PTP_CALLBACK_ENVIRON CallbackEnviron,
     PTP_POOL Pool
    )
{
    CallbackEnviron->Pool = Pool;
}

__inline
void
TpSetCallbackCleanupGroup(
     PTP_CALLBACK_ENVIRON CallbackEnviron,
     PTP_CLEANUP_GROUP CleanupGroup,
     PTP_CLEANUP_GROUP_CANCEL_CALLBACK CleanupGroupCancelCallback
    )
{
    CallbackEnviron->CleanupGroup = CleanupGroup;
    CallbackEnviron->CleanupGroupCancelCallback = CleanupGroupCancelCallback;
}

__inline
void
TpSetCallbackActivationContext(
     PTP_CALLBACK_ENVIRON CallbackEnviron,
     struct _ACTIVATION_CONTEXT *ActivationContext
    )
{
    CallbackEnviron->ActivationContext = ActivationContext;
}

__inline
void
TpSetCallbackNoActivationContext(
     PTP_CALLBACK_ENVIRON CallbackEnviron
    )
{
    CallbackEnviron->ActivationContext = (struct _ACTIVATION_CONTEXT *)(LONG_PTR) -1;
}

__inline
void
TpSetCallbackLongFunction(
     PTP_CALLBACK_ENVIRON CallbackEnviron
    )
{
    CallbackEnviron->u.s.LongFunction = 1;
}

__inline
void
TpSetCallbackRaceWithDll(
     PTP_CALLBACK_ENVIRON CallbackEnviron,
     PVOID DllHandle
    )
{
    CallbackEnviron->RaceDll = DllHandle;
}

__inline
void
TpSetCallbackFinalizationCallback(
     PTP_CALLBACK_ENVIRON CallbackEnviron,
     PTP_SIMPLE_CALLBACK FinalizationCallback
    )
{
    CallbackEnviron->FinalizationCallback = FinalizationCallback;
}

__inline
void
TpDestroyCallbackEnviron(
     PTP_CALLBACK_ENVIRON CallbackEnviron
    )
{






    (CallbackEnviron) ;
}




typedef struct _TP_WORK TP_WORK, *PTP_WORK;

typedef  void  (  *PTP_WORK_CALLBACK)(
     PTP_CALLBACK_INSTANCE Instance,
     PVOID Context,
     PTP_WORK Work
    );

typedef struct _TP_TIMER TP_TIMER, *PTP_TIMER;

typedef  void  (  *PTP_TIMER_CALLBACK)(
     PTP_CALLBACK_INSTANCE Instance,
     PVOID Context,
     PTP_TIMER Timer
    );

typedef DWORD TP_WAIT_RESULT;

typedef struct _TP_WAIT TP_WAIT, *PTP_WAIT;

typedef  void  (  *PTP_WAIT_CALLBACK)(
     PTP_CALLBACK_INSTANCE Instance,
     PVOID Context,
     PTP_WAIT Wait,
     TP_WAIT_RESULT WaitResult
    );

typedef struct _TP_IO TP_IO, *PTP_IO;

__inline struct _TEB * NtCurrentTeb( void ) { __asm mov eax, fs:[ 0x18 ] }


typedef UINT_PTR WPARAM;
typedef LONG_PTR LPARAM;
typedef LONG_PTR LRESULT;
struct HWND__ {int unused;}; typedef struct HWND__ *HWND ;
struct HHOOK__ {int unused;}; typedef struct HHOOK__ *HHOOK ;
typedef WORD ATOM;

typedef HANDLE   *SPHANDLE;
typedef HANDLE   *LPHANDLE;
typedef HANDLE HGLOBAL;
typedef HANDLE HLOCAL;
typedef HANDLE GLOBALHANDLE;
typedef HANDLE LOCALHANDLE;







typedef int (    *FARPROC)();
typedef int (    *NEARPROC)();
typedef int (  *PROC)();
typedef void  * HGDIOBJ;
struct HKEY__ {int unused;}; typedef struct HKEY__ *HKEY ;
typedef HKEY *PHKEY;


struct HACCEL__ {int unused;}; typedef struct HACCEL__ *HACCEL ;


struct HBITMAP__ {int unused;}; typedef struct HBITMAP__ *HBITMAP ;
struct HBRUSH__ {int unused;}; typedef struct HBRUSH__ *HBRUSH ;


struct HCOLORSPACE__ {int unused;}; typedef struct HCOLORSPACE__ *HCOLORSPACE ;


struct HDC__ {int unused;}; typedef struct HDC__ *HDC ;

struct HGLRC__ {int unused;}; typedef struct HGLRC__ *HGLRC ;
struct HDESK__ {int unused;}; typedef struct HDESK__ *HDESK ;
struct HENHMETAFILE__ {int unused;}; typedef struct HENHMETAFILE__ *HENHMETAFILE ;

struct HFONT__ {int unused;}; typedef struct HFONT__ *HFONT ;

struct HICON__ {int unused;}; typedef struct HICON__ *HICON ;

struct HMENU__ {int unused;}; typedef struct HMENU__ *HMENU ;

struct HMETAFILE__ {int unused;}; typedef struct HMETAFILE__ *HMETAFILE ;
struct HINSTANCE__ {int unused;}; typedef struct HINSTANCE__ *HINSTANCE ;
typedef HINSTANCE HMODULE;

struct HPALETTE__ {int unused;}; typedef struct HPALETTE__ *HPALETTE ;
struct HPEN__ {int unused;}; typedef struct HPEN__ *HPEN ;

struct HRGN__ {int unused;}; typedef struct HRGN__ *HRGN ;
struct HRSRC__ {int unused;}; typedef struct HRSRC__ *HRSRC ;
struct HSPRITE__ {int unused;}; typedef struct HSPRITE__ *HSPRITE ;
struct HSTR__ {int unused;}; typedef struct HSTR__ *HSTR ;
struct HTASK__ {int unused;}; typedef struct HTASK__ *HTASK ;
struct HWINSTA__ {int unused;}; typedef struct HWINSTA__ *HWINSTA ;
struct HKL__ {int unused;}; typedef struct HKL__ *HKL ;


struct HWINEVENTHOOK__ {int unused;}; typedef struct HWINEVENTHOOK__ *HWINEVENTHOOK ;




struct HMONITOR__ {int unused;}; typedef struct HMONITOR__ *HMONITOR ;

struct HUMPD__ {int unused;}; typedef struct HUMPD__ *HUMPD ;



typedef int HFILE;
typedef HICON HCURSOR;
typedef DWORD COLORREF;
typedef DWORD *LPCOLORREF;



typedef struct tagRECT
{
    LONG left;
    LONG top;
    LONG right;
    LONG bottom;
} RECT, *PRECT,   *NPRECT,   *LPRECT;

typedef const RECT  * LPCRECT;

typedef struct _RECTL
{
    LONG left;
    LONG top;
    LONG right;
    LONG bottom;
} RECTL, *PRECTL, *LPRECTL;

typedef const RECTL  * LPCRECTL;

typedef struct tagPOINT
{
    LONG x;
    LONG y;
} POINT, *PPOINT,   *NPPOINT,   *LPPOINT;

typedef struct _POINTL
{
    LONG x;
    LONG y;
} POINTL, *PPOINTL;

typedef struct tagSIZE
{
    LONG cx;
    LONG cy;
} SIZE, *PSIZE, *LPSIZE;

typedef SIZE SIZEL;
typedef SIZE *PSIZEL, *LPSIZEL;

typedef struct tagPOINTS
{

    SHORT x;
    SHORT y;
} POINTS, *PPOINTS, *LPPOINTS;





typedef struct _FILETIME {
    DWORD dwLowDateTime;
    DWORD dwHighDateTime;
} FILETIME, *PFILETIME, *LPFILETIME;
typedef struct _OVERLAPPED {
    ULONG_PTR Internal;
    ULONG_PTR InternalHigh;
    union {
        struct {
            DWORD Offset;
            DWORD OffsetHigh;
        }  s ;
        PVOID Pointer;
    }  u ;

    HANDLE hEvent;
} OVERLAPPED, *LPOVERLAPPED;

typedef struct _OVERLAPPED_ENTRY {
    ULONG_PTR lpCompletionKey;
    LPOVERLAPPED lpOverlapped;
    ULONG_PTR Internal;
    DWORD dwNumberOfBytesTransferred;
} OVERLAPPED_ENTRY, *LPOVERLAPPED_ENTRY;

typedef struct _SECURITY_ATTRIBUTES {
    DWORD nLength;
    LPVOID lpSecurityDescriptor;
    BOOL bInheritHandle;
} SECURITY_ATTRIBUTES, *PSECURITY_ATTRIBUTES, *LPSECURITY_ATTRIBUTES;

typedef struct _PROCESS_INFORMATION {
    HANDLE hProcess;
    HANDLE hThread;
    DWORD dwProcessId;
    DWORD dwThreadId;
} PROCESS_INFORMATION, *PPROCESS_INFORMATION, *LPPROCESS_INFORMATION;
typedef struct _SYSTEMTIME {
    WORD wYear;
    WORD wMonth;
    WORD wDayOfWeek;
    WORD wDay;
    WORD wHour;
    WORD wMinute;
    WORD wSecond;
    WORD wMilliseconds;
} SYSTEMTIME, *PSYSTEMTIME, *LPSYSTEMTIME;


typedef DWORD (  *PTHREAD_START_ROUTINE)(
    LPVOID lpThreadParameter
    );
typedef PTHREAD_START_ROUTINE LPTHREAD_START_ROUTINE;


typedef  void  (  *PFIBER_START_ROUTINE)(
    LPVOID lpFiberParameter
    );
typedef PFIBER_START_ROUTINE LPFIBER_START_ROUTINE;


typedef RTL_CRITICAL_SECTION CRITICAL_SECTION;
typedef PRTL_CRITICAL_SECTION PCRITICAL_SECTION;
typedef PRTL_CRITICAL_SECTION LPCRITICAL_SECTION;

typedef RTL_CRITICAL_SECTION_DEBUG CRITICAL_SECTION_DEBUG;
typedef PRTL_CRITICAL_SECTION_DEBUG PCRITICAL_SECTION_DEBUG;
typedef PRTL_CRITICAL_SECTION_DEBUG LPCRITICAL_SECTION_DEBUG;







typedef RTL_RUN_ONCE INIT_ONCE;
typedef PRTL_RUN_ONCE PINIT_ONCE;
typedef PRTL_RUN_ONCE LPINIT_ONCE;
typedef
BOOL
(  *PINIT_ONCE_FN) (
     PINIT_ONCE InitOnce,
     PVOID Parameter,
     PVOID *Context
    );

__declspec(dllimport)
void

InitOnceInitialize (
     PINIT_ONCE InitOnce
    );

__declspec(dllimport)
BOOL

InitOnceExecuteOnce (
     PINIT_ONCE InitOnce,
       PINIT_ONCE_FN InitFn,
     PVOID Parameter,
     LPVOID *Context
    );

__declspec(dllimport)
BOOL

InitOnceBeginInitialize (
     LPINIT_ONCE lpInitOnce,
     DWORD dwFlags,
     PBOOL fPending,
     LPVOID *lpContext
    );

__declspec(dllimport)
BOOL

InitOnceComplete (
     LPINIT_ONCE lpInitOnce,
     DWORD dwFlags,
     LPVOID lpContext
    );







typedef RTL_SRWLOCK SRWLOCK, *PSRWLOCK;



__declspec(dllimport)
void

InitializeSRWLock (
      PSRWLOCK SRWLock
     );

__declspec(dllimport)
void

ReleaseSRWLockExclusive (
      PSRWLOCK SRWLock
     );

__declspec(dllimport)
void

ReleaseSRWLockShared (
      PSRWLOCK SRWLock
     );

__declspec(dllimport)
void

AcquireSRWLockExclusive (
      PSRWLOCK SRWLock
     );

__declspec(dllimport)
void

AcquireSRWLockShared (
      PSRWLOCK SRWLock
     );





typedef RTL_CONDITION_VARIABLE CONDITION_VARIABLE, *PCONDITION_VARIABLE;

__declspec(dllimport)
void

InitializeConditionVariable (
     PCONDITION_VARIABLE ConditionVariable
    );

__declspec(dllimport)
void

WakeConditionVariable (
     PCONDITION_VARIABLE ConditionVariable
    );

__declspec(dllimport)
void

WakeAllConditionVariable (
     PCONDITION_VARIABLE ConditionVariable
    );

__declspec(dllimport)
BOOL

SleepConditionVariableCS (
     PCONDITION_VARIABLE ConditionVariable,
     PCRITICAL_SECTION CriticalSection,
     DWORD dwMilliseconds
    );

__declspec(dllimport)
BOOL

SleepConditionVariableSRW (
     PCONDITION_VARIABLE ConditionVariable,
     PSRWLOCK SRWLock,
     DWORD dwMilliseconds,
     ULONG Flags
    );
__declspec(dllimport)

PVOID

EncodePointer (
     PVOID Ptr
    );

__declspec(dllimport)

PVOID

DecodePointer (
     PVOID Ptr
    );

__declspec(dllimport)

PVOID

EncodeSystemPointer (
     PVOID Ptr
    );

__declspec(dllimport)

PVOID

DecodeSystemPointer (
     PVOID Ptr
    );


typedef PLDT_ENTRY LPLDT_ENTRY;
typedef struct _COMMPROP {
    WORD wPacketLength;
    WORD wPacketVersion;
    DWORD dwServiceMask;
    DWORD dwReserved1;
    DWORD dwMaxTxQueue;
    DWORD dwMaxRxQueue;
    DWORD dwMaxBaud;
    DWORD dwProvSubType;
    DWORD dwProvCapabilities;
    DWORD dwSettableParams;
    DWORD dwSettableBaud;
    WORD wSettableData;
    WORD wSettableStopParity;
    DWORD dwCurrentTxQueue;
    DWORD dwCurrentRxQueue;
    DWORD dwProvSpec1;
    DWORD dwProvSpec2;
    WCHAR wcProvChar[1];
} COMMPROP,*LPCOMMPROP;







typedef struct _COMSTAT {
    DWORD fCtsHold : 1;
    DWORD fDsrHold : 1;
    DWORD fRlsdHold : 1;
    DWORD fXoffHold : 1;
    DWORD fXoffSent : 1;
    DWORD fEof : 1;
    DWORD fTxim : 1;
    DWORD fReserved : 25;
    DWORD cbInQue;
    DWORD cbOutQue;
} COMSTAT, *LPCOMSTAT;
typedef struct _DCB {
    DWORD DCBlength;
    DWORD BaudRate;
    DWORD fBinary: 1;
    DWORD fParity: 1;
    DWORD fOutxCtsFlow:1;
    DWORD fOutxDsrFlow:1;
    DWORD fDtrControl:2;
    DWORD fDsrSensitivity:1;
    DWORD fTXContinueOnXoff: 1;
    DWORD fOutX: 1;
    DWORD fInX: 1;
    DWORD fErrorChar: 1;
    DWORD fNull: 1;
    DWORD fRtsControl:2;
    DWORD fAbortOnError:1;
    DWORD fDummy2:17;
    WORD wReserved;
    WORD XonLim;
    WORD XoffLim;
    BYTE ByteSize;
    BYTE Parity;
    BYTE StopBits;
    char XonChar;
    char XoffChar;
    char ErrorChar;
    char EofChar;
    char EvtChar;
    WORD wReserved1;
} DCB, *LPDCB;

typedef struct _COMMTIMEOUTS {
    DWORD ReadIntervalTimeout;
    DWORD ReadTotalTimeoutMultiplier;
    DWORD ReadTotalTimeoutConstant;
    DWORD WriteTotalTimeoutMultiplier;
    DWORD WriteTotalTimeoutConstant;
} COMMTIMEOUTS,*LPCOMMTIMEOUTS;

typedef struct _COMMCONFIG {
    DWORD dwSize;
    WORD wVersion;
    WORD wReserved;
    DCB dcb;
    DWORD dwProviderSubType;
    DWORD dwProviderOffset;
    DWORD dwProviderSize;
    WCHAR wcProviderData[1];
} COMMCONFIG,*LPCOMMCONFIG;

typedef struct _SYSTEM_INFO {
    union {
        DWORD dwOemId;
        struct {
            WORD wProcessorArchitecture;
            WORD wReserved;
        }  s ;
    }  u ;
    DWORD dwPageSize;
    LPVOID lpMinimumApplicationAddress;
    LPVOID lpMaximumApplicationAddress;
    DWORD_PTR dwActiveProcessorMask;
    DWORD dwNumberOfProcessors;
    DWORD dwProcessorType;
    DWORD dwAllocationGranularity;
    WORD wProcessorLevel;
    WORD wProcessorRevision;
} SYSTEM_INFO, *LPSYSTEM_INFO;
typedef struct _MEMORYSTATUS {
    DWORD dwLength;
    DWORD dwMemoryLoad;
    SIZE_T dwTotalPhys;
    SIZE_T dwAvailPhys;
    SIZE_T dwTotalPageFile;
    SIZE_T dwAvailPageFile;
    SIZE_T dwTotalVirtual;
    SIZE_T dwAvailVirtual;
} MEMORYSTATUS, *LPMEMORYSTATUS;
typedef struct _EXCEPTION_DEBUG_INFO {
    EXCEPTION_RECORD ExceptionRecord;
    DWORD dwFirstChance;
} EXCEPTION_DEBUG_INFO, *LPEXCEPTION_DEBUG_INFO;

typedef struct _CREATE_THREAD_DEBUG_INFO {
    HANDLE hThread;
    LPVOID lpThreadLocalBase;
    LPTHREAD_START_ROUTINE lpStartAddress;
} CREATE_THREAD_DEBUG_INFO, *LPCREATE_THREAD_DEBUG_INFO;

typedef struct _CREATE_PROCESS_DEBUG_INFO {
    HANDLE hFile;
    HANDLE hProcess;
    HANDLE hThread;
    LPVOID lpBaseOfImage;
    DWORD dwDebugInfoFileOffset;
    DWORD nDebugInfoSize;
    LPVOID lpThreadLocalBase;
    LPTHREAD_START_ROUTINE lpStartAddress;
    LPVOID lpImageName;
    WORD fUnicode;
} CREATE_PROCESS_DEBUG_INFO, *LPCREATE_PROCESS_DEBUG_INFO;

typedef struct _EXIT_THREAD_DEBUG_INFO {
    DWORD dwExitCode;
} EXIT_THREAD_DEBUG_INFO, *LPEXIT_THREAD_DEBUG_INFO;

typedef struct _EXIT_PROCESS_DEBUG_INFO {
    DWORD dwExitCode;
} EXIT_PROCESS_DEBUG_INFO, *LPEXIT_PROCESS_DEBUG_INFO;

typedef struct _LOAD_DLL_DEBUG_INFO {
    HANDLE hFile;
    LPVOID lpBaseOfDll;
    DWORD dwDebugInfoFileOffset;
    DWORD nDebugInfoSize;
    LPVOID lpImageName;
    WORD fUnicode;
} LOAD_DLL_DEBUG_INFO, *LPLOAD_DLL_DEBUG_INFO;

typedef struct _UNLOAD_DLL_DEBUG_INFO {
    LPVOID lpBaseOfDll;
} UNLOAD_DLL_DEBUG_INFO, *LPUNLOAD_DLL_DEBUG_INFO;

typedef struct _OUTPUT_DEBUG_STRING_INFO {
    LPSTR lpDebugStringData;
    WORD fUnicode;
    WORD nDebugStringLength;
} OUTPUT_DEBUG_STRING_INFO, *LPOUTPUT_DEBUG_STRING_INFO;

typedef struct _RIP_INFO {
    DWORD dwError;
    DWORD dwType;
} RIP_INFO, *LPRIP_INFO;


typedef struct _DEBUG_EVENT {
    DWORD dwDebugEventCode;
    DWORD dwProcessId;
    DWORD dwThreadId;
    union {
        EXCEPTION_DEBUG_INFO Exception;
        CREATE_THREAD_DEBUG_INFO CreateThread;
        CREATE_PROCESS_DEBUG_INFO CreateProcessInfo;
        EXIT_THREAD_DEBUG_INFO ExitThread;
        EXIT_PROCESS_DEBUG_INFO ExitProcess;
        LOAD_DLL_DEBUG_INFO LoadDll;
        UNLOAD_DLL_DEBUG_INFO UnloadDll;
        OUTPUT_DEBUG_STRING_INFO DebugString;
        RIP_INFO RipInfo;
    } u;
} DEBUG_EVENT, *LPDEBUG_EVENT;






typedef struct _JIT_DEBUG_INFO {
    DWORD dwSize;
    DWORD dwProcessorArchitecture;
    DWORD dwThreadID;
    DWORD dwReserved0;
    ULONG64 lpExceptionAddress;
    ULONG64 lpExceptionRecord;
    ULONG64 lpContextRecord;
} JIT_DEBUG_INFO, *LPJIT_DEBUG_INFO;

typedef JIT_DEBUG_INFO JIT_DEBUG_INFO32, *LPJIT_DEBUG_INFO32;
typedef JIT_DEBUG_INFO JIT_DEBUG_INFO64, *LPJIT_DEBUG_INFO64;


typedef PCONTEXT LPCONTEXT;
typedef PEXCEPTION_RECORD LPEXCEPTION_RECORD;
typedef PEXCEPTION_POINTERS LPEXCEPTION_POINTERS;
typedef struct _OFSTRUCT {
    BYTE cBytes;
    BYTE fFixedDisk;
    WORD nErrCode;
    WORD Reserved1;
    WORD Reserved2;
    CHAR szPathName[ 128 ];
} OFSTRUCT, *LPOFSTRUCT, *POFSTRUCT;
__declspec(dllimport)
LONG

InterlockedIncrement (
     LONG volatile *lpAddend
    );

__declspec(dllimport)
LONG

InterlockedDecrement (
     LONG volatile *lpAddend
    );

__declspec(dllimport)
LONG

InterlockedExchange (
     LONG volatile *Target,
     LONG Value
    );
__declspec(dllimport)
LONG

InterlockedExchangeAdd (
     LONG volatile *Addend,
     LONG Value
    );

__declspec(dllimport)
LONG

InterlockedCompareExchange (
     LONG volatile *Destination,
     LONG Exchange,
     LONG Comperand
    );



__declspec(dllimport)
LONGLONG

InterlockedCompareExchange64 (
     LONGLONG volatile *Destination,
     LONGLONG Exchange,
     LONGLONG Comperand
    );







__inline
LONGLONG
InterlockedAnd64 (
     LONGLONG volatile *Destination,
     LONGLONG Value
    )
{
    LONGLONG Old;

    do {
        Old = *Destination;
    } while (InterlockedCompareExchange64(Destination,
                                          Old & Value,
                                          Old) != Old);

    return Old;
}

__inline
LONGLONG
InterlockedOr64 (
     LONGLONG volatile *Destination,
     LONGLONG Value
    )
{
    LONGLONG Old;

    do {
        Old = *Destination;
    } while (InterlockedCompareExchange64(Destination,
                                          Old | Value,
                                          Old) != Old);

    return Old;
}

__inline
LONGLONG
InterlockedXor64 (
     LONGLONG volatile *Destination,
     LONGLONG Value
    )
{
    LONGLONG Old;

    do {
        Old = *Destination;
    } while (InterlockedCompareExchange64(Destination,
                                          Old ^ Value,
                                          Old) != Old);

    return Old;
}

__inline
LONGLONG
InterlockedIncrement64 (
     LONGLONG volatile *Addend
    )
{
    LONGLONG Old;

    do {
        Old = *Addend;
    } while (InterlockedCompareExchange64(Addend,
                                          Old + 1,
                                          Old) != Old);

    return Old + 1;
}

__inline
LONGLONG
InterlockedDecrement64 (
     LONGLONG volatile *Addend
    )
{
    LONGLONG Old;

    do {
        Old = *Addend;
    } while (InterlockedCompareExchange64(Addend,
                                          Old - 1,
                                          Old) != Old);

    return Old - 1;
}

__inline
LONGLONG
InterlockedExchange64 (
     LONGLONG volatile *Target,
     LONGLONG Value
    )
{
    LONGLONG Old;

    do {
        Old = *Target;
    } while (InterlockedCompareExchange64(Target,
                                          Value,
                                          Old) != Old);

    return Old;
}

__inline
LONGLONG
InterlockedExchangeAdd64(
     LONGLONG volatile *Addend,
     LONGLONG Value
    )
{
    LONGLONG Old;

    do {
        Old = *Addend;
    } while (InterlockedCompareExchange64(Addend,
                                          Old + Value,
                                          Old) != Old);

    return Old;
}
__declspec(dllimport)
void

InitializeSListHead (
     PSLIST_HEADER ListHead
    );

__declspec(dllimport)
PSINGLE_LIST_ENTRY

InterlockedPopEntrySList (
     PSLIST_HEADER ListHead
    );

__declspec(dllimport)
PSINGLE_LIST_ENTRY

InterlockedPushEntrySList (
     PSLIST_HEADER ListHead,
      PSINGLE_LIST_ENTRY  ListEntry
    );

__declspec(dllimport)
PSINGLE_LIST_ENTRY

InterlockedFlushSList (
     PSLIST_HEADER ListHead
    );

__declspec(dllimport)
USHORT

QueryDepthSList (
     PSLIST_HEADER ListHead
    );







__declspec(dllimport)
BOOL

FreeResource(
     HGLOBAL hResData
    );

__declspec(dllimport)
LPVOID

LockResource(
     HGLOBAL hResData
    );






int





WinMain (
     HINSTANCE hInstance,
     HINSTANCE hPrevInstance,
     LPSTR lpCmdLine,
     int nShowCmd
    );

int





wWinMain(
     HINSTANCE hInstance,
     HINSTANCE hPrevInstance,
     LPWSTR lpCmdLine,
     int nShowCmd
    );

__declspec(dllimport)
BOOL

FreeLibrary (
     HMODULE hLibModule
    );


__declspec(dllimport)

void

FreeLibraryAndExitThread (
     HMODULE hLibModule,
     DWORD dwExitCode
    );

__declspec(dllimport)
BOOL

DisableThreadLibraryCalls (
     HMODULE hLibModule
    );

__declspec(dllimport)
FARPROC

GetProcAddress (
     HMODULE hModule,
     LPCSTR lpProcName
    );

__declspec(dllimport)
DWORD

GetVersion (
    void
    );

__declspec(dllimport)

HGLOBAL

GlobalAlloc (
     UINT uFlags,
     SIZE_T dwBytes
    );

__declspec(dllimport)

HGLOBAL

GlobalReAlloc (
     HGLOBAL hMem,
     SIZE_T dwBytes,
     UINT uFlags
    );

__declspec(dllimport)
SIZE_T

GlobalSize (
     HGLOBAL hMem
    );

__declspec(dllimport)
UINT

GlobalFlags (
     HGLOBAL hMem
    );

__declspec(dllimport)

LPVOID

GlobalLock (
     HGLOBAL hMem
    );

__declspec(dllimport)

HGLOBAL

GlobalHandle (
     LPCVOID pMem
    );

__declspec(dllimport)
BOOL

GlobalUnlock(
     HGLOBAL hMem
    );

__declspec(dllimport)

HGLOBAL

GlobalFree(
     HGLOBAL hMem
    );

__declspec(dllimport)
SIZE_T

GlobalCompact(
     DWORD dwMinFree
    );

__declspec(dllimport)
void

GlobalFix(
     HGLOBAL hMem
    );

__declspec(dllimport)
void

GlobalUnfix(
     HGLOBAL hMem
    );

__declspec(dllimport)

LPVOID

GlobalWire(
     HGLOBAL hMem
    );

__declspec(dllimport)
BOOL

GlobalUnWire(
     HGLOBAL hMem
    );

__declspec(dllimport)
void

GlobalMemoryStatus(
     LPMEMORYSTATUS lpBuffer
    );

typedef struct _MEMORYSTATUSEX {
    DWORD dwLength;
    DWORD dwMemoryLoad;
    DWORDLONG ullTotalPhys;
    DWORDLONG ullAvailPhys;
    DWORDLONG ullTotalPageFile;
    DWORDLONG ullAvailPageFile;
    DWORDLONG ullTotalVirtual;
    DWORDLONG ullAvailVirtual;
    DWORDLONG ullAvailExtendedVirtual;
} MEMORYSTATUSEX, *LPMEMORYSTATUSEX;

__declspec(dllimport)
BOOL

GlobalMemoryStatusEx(
     LPMEMORYSTATUSEX lpBuffer
    );

__declspec(dllimport)

HLOCAL

LocalAlloc(
     UINT uFlags,
     SIZE_T uBytes
    );

__declspec(dllimport)

HLOCAL

LocalReAlloc(
     HLOCAL hMem,
     SIZE_T uBytes,
     UINT uFlags
    );

__declspec(dllimport)

LPVOID

LocalLock(
     HLOCAL hMem
    );

__declspec(dllimport)

HLOCAL

LocalHandle(
     LPCVOID pMem
    );

__declspec(dllimport)
BOOL

LocalUnlock(
     HLOCAL hMem
    );

__declspec(dllimport)
SIZE_T

LocalSize(
     HLOCAL hMem
    );

__declspec(dllimport)
UINT

LocalFlags(
     HLOCAL hMem
    );

__declspec(dllimport)
HLOCAL

LocalFree(
     HLOCAL hMem
    );

__declspec(dllimport)
SIZE_T

LocalShrink(
     HLOCAL hMem,
     UINT cbNewSize
    );

__declspec(dllimport)
SIZE_T

LocalCompact(
     UINT uMinFree
    );

__declspec(dllimport)
BOOL

FlushInstructionCache(
     HANDLE hProcess,
     LPCVOID lpBaseAddress,
     SIZE_T dwSize
    );



__declspec(dllimport)
void

FlushProcessWriteBuffers(
    void
    );

__declspec(dllimport)
BOOL

QueryThreadCycleTime (
     HANDLE ThreadHandle,
     PULONG64 CycleTime
    );

__declspec(dllimport)
BOOL

QueryProcessCycleTime (
     HANDLE ProcessHandle,
     PULONG64 CycleTime
    );

__declspec(dllimport)
BOOL

QueryIdleProcessorCycleTime (
     PULONG BufferLength,
     PULONG64 ProcessorIdleCycleTime
    );



__declspec(dllimport)

LPVOID

VirtualAlloc(
     LPVOID lpAddress,
     SIZE_T dwSize,
     DWORD flAllocationType,
     DWORD flProtect
    );

__declspec(dllimport)
BOOL

VirtualFree(
     LPVOID lpAddress,
     SIZE_T dwSize,
     DWORD dwFreeType
    );

__declspec(dllimport)
BOOL

VirtualProtect(
     LPVOID lpAddress,
     SIZE_T dwSize,
     DWORD flNewProtect,
     PDWORD lpflOldProtect
    );

__declspec(dllimport)
SIZE_T

VirtualQuery(
     LPCVOID lpAddress,
     PMEMORY_BASIC_INFORMATION lpBuffer,
     SIZE_T dwLength
    );

__declspec(dllimport)

LPVOID

VirtualAllocEx(
     HANDLE hProcess,
     LPVOID lpAddress,
     SIZE_T dwSize,
     DWORD flAllocationType,
     DWORD flProtect
    );



__declspec(dllimport)

LPVOID

VirtualAllocExNuma(
     HANDLE hProcess,
     LPVOID lpAddress,
     SIZE_T dwSize,
     DWORD flAllocationType,
     DWORD flProtect,
     DWORD nndPreferred
    );



__declspec(dllimport)
UINT

GetWriteWatch(
     DWORD dwFlags,
     PVOID lpBaseAddress,
     SIZE_T dwRegionSize,
     PVOID *lpAddresses,
     ULONG_PTR *lpdwCount,
     PULONG lpdwGranularity
    );

__declspec(dllimport)
UINT

ResetWriteWatch(
     LPVOID lpBaseAddress,
     SIZE_T dwRegionSize
    );

__declspec(dllimport)
SIZE_T

GetLargePageMinimum(
    void
    );

__declspec(dllimport)
UINT

EnumSystemFirmwareTables(
     DWORD FirmwareTableProviderSignature,
     PVOID pFirmwareTableEnumBuffer,
     DWORD BufferSize
    );

__declspec(dllimport)
UINT

GetSystemFirmwareTable(
     DWORD FirmwareTableProviderSignature,
     DWORD FirmwareTableID,
     PVOID pFirmwareTableBuffer,
     DWORD BufferSize
    );

__declspec(dllimport)
BOOL

GetPhysicallyInstalledSystemMemory(
     PULONGLONG TotalMemoryInKilobytes
    );

__declspec(dllimport)
BOOL

VirtualFreeEx(
     HANDLE hProcess,
     LPVOID lpAddress,
     SIZE_T dwSize,
     DWORD dwFreeType
    );

__declspec(dllimport)
BOOL

VirtualProtectEx(
     HANDLE hProcess,
     LPVOID lpAddress,
     SIZE_T dwSize,
     DWORD flNewProtect,
     PDWORD lpflOldProtect
    );

__declspec(dllimport)
SIZE_T

VirtualQueryEx(
     HANDLE hProcess,
     LPCVOID lpAddress,
     PMEMORY_BASIC_INFORMATION lpBuffer,
     SIZE_T dwLength
    );

__declspec(dllimport)

HANDLE

HeapCreate(
     DWORD flOptions,
     SIZE_T dwInitialSize,
     SIZE_T dwMaximumSize
    );

__declspec(dllimport)
BOOL

HeapDestroy(
     HANDLE hHeap
    );

__declspec(dllimport)

LPVOID

HeapAlloc(
     HANDLE hHeap,
     DWORD dwFlags,
     SIZE_T dwBytes
    );

__declspec(dllimport)

LPVOID

HeapReAlloc(
     HANDLE hHeap,
     DWORD dwFlags,
     LPVOID lpMem,
     SIZE_T dwBytes
    );

__declspec(dllimport)
BOOL

HeapFree(
     HANDLE hHeap,
     DWORD dwFlags,
     LPVOID lpMem
    );

__declspec(dllimport)
SIZE_T

HeapSize(
     HANDLE hHeap,
     DWORD dwFlags,
     LPCVOID lpMem
    );

__declspec(dllimport)
BOOL

HeapValidate(
     HANDLE hHeap,
     DWORD dwFlags,
     LPCVOID lpMem
    );

__declspec(dllimport)
SIZE_T

HeapCompact(
     HANDLE hHeap,
     DWORD dwFlags
    );

__declspec(dllimport)

HANDLE

GetProcessHeap(  void  );

__declspec(dllimport)
DWORD

GetProcessHeaps(
     DWORD NumberOfHeaps,
     PHANDLE ProcessHeaps
    );

typedef struct _PROCESS_HEAP_ENTRY {
    PVOID lpData;
    DWORD cbData;
    BYTE cbOverhead;
    BYTE iRegionIndex;
    WORD wFlags;
    union {
        struct {
            HANDLE hMem;
            DWORD dwReserved[ 3 ];
        } Block;
        struct {
            DWORD dwCommittedSize;
            DWORD dwUnCommittedSize;
            LPVOID lpFirstBlock;
            LPVOID lpLastBlock;
        } Region;
    }  u ;
} PROCESS_HEAP_ENTRY, *LPPROCESS_HEAP_ENTRY, *PPROCESS_HEAP_ENTRY;







__declspec(dllimport)
BOOL

HeapLock(
     HANDLE hHeap
    );

__declspec(dllimport)
BOOL

HeapUnlock(
     HANDLE hHeap
    );


__declspec(dllimport)
BOOL

HeapWalk(
     HANDLE hHeap,
     LPPROCESS_HEAP_ENTRY lpEntry
    );

__declspec(dllimport)
BOOL

HeapSetInformation (
     HANDLE HeapHandle,
     HEAP_INFORMATION_CLASS HeapInformationClass,
     PVOID HeapInformation,
     SIZE_T HeapInformationLength
    );

__declspec(dllimport)
BOOL

HeapQueryInformation (
     HANDLE HeapHandle,
     HEAP_INFORMATION_CLASS HeapInformationClass,
     PVOID HeapInformation,
     SIZE_T HeapInformationLength,
     PSIZE_T ReturnLength
    );
__declspec(dllimport)
BOOL

GetBinaryTypeA(
     LPCSTR lpApplicationName,
     LPDWORD lpBinaryType
    );
__declspec(dllimport)
BOOL

GetBinaryTypeW(
     LPCWSTR lpApplicationName,
     LPDWORD lpBinaryType
    );






__declspec(dllimport)
DWORD

GetShortPathNameA(
     LPCSTR lpszLongPath,
     LPSTR lpszShortPath,
     DWORD cchBuffer
    );
__declspec(dllimport)
DWORD

GetShortPathNameW(
     LPCWSTR lpszLongPath,
     LPWSTR lpszShortPath,
     DWORD cchBuffer
    );






__declspec(dllimport)
DWORD

GetLongPathNameA(
     LPCSTR lpszShortPath,
     LPSTR lpszLongPath,
     DWORD cchBuffer
    );
__declspec(dllimport)
DWORD

GetLongPathNameW(
     LPCWSTR lpszShortPath,
     LPWSTR lpszLongPath,
     DWORD cchBuffer
    );








__declspec(dllimport)
DWORD

GetLongPathNameTransactedA(
     LPCSTR lpszShortPath,
     LPSTR lpszLongPath,
     DWORD cchBuffer,
     HANDLE hTransaction
    );
__declspec(dllimport)
DWORD

GetLongPathNameTransactedW(
     LPCWSTR lpszShortPath,
     LPWSTR lpszLongPath,
     DWORD cchBuffer,
     HANDLE hTransaction
    );








__declspec(dllimport)
BOOL

GetProcessAffinityMask(
     HANDLE hProcess,
     PDWORD_PTR lpProcessAffinityMask,
     PDWORD_PTR lpSystemAffinityMask
    );

__declspec(dllimport)
BOOL

SetProcessAffinityMask(
     HANDLE hProcess,
     DWORD_PTR dwProcessAffinityMask
    );



__declspec(dllimport)
BOOL

GetProcessHandleCount(
     HANDLE hProcess,
     PDWORD pdwHandleCount
    );



__declspec(dllimport)
BOOL

GetProcessTimes(
     HANDLE hProcess,
     LPFILETIME lpCreationTime,
     LPFILETIME lpExitTime,
     LPFILETIME lpKernelTime,
     LPFILETIME lpUserTime
    );

__declspec(dllimport)
BOOL

GetProcessIoCounters(
     HANDLE hProcess,
     PIO_COUNTERS lpIoCounters
    );

__declspec(dllimport)
BOOL

GetProcessWorkingSetSize(
     HANDLE hProcess,
     PSIZE_T lpMinimumWorkingSetSize,
     PSIZE_T lpMaximumWorkingSetSize
    );

__declspec(dllimport)
BOOL

GetProcessWorkingSetSizeEx(
     HANDLE hProcess,
     PSIZE_T lpMinimumWorkingSetSize,
     PSIZE_T lpMaximumWorkingSetSize,
     PDWORD Flags
    );

__declspec(dllimport)
BOOL

SetProcessWorkingSetSize(
     HANDLE hProcess,
     SIZE_T dwMinimumWorkingSetSize,
     SIZE_T dwMaximumWorkingSetSize
    );

__declspec(dllimport)
BOOL

SetProcessWorkingSetSizeEx(
     HANDLE hProcess,
     SIZE_T dwMinimumWorkingSetSize,
     SIZE_T dwMaximumWorkingSetSize,
     DWORD Flags
    );





__declspec(dllimport)
BOOL

SetProcessAffinityUpdateMode(
     HANDLE hProcess,
     DWORD dwFlags
    );

__declspec(dllimport)
BOOL

QueryProcessAffinityUpdateMode(
     HANDLE hProcess,
     LPDWORD lpdwFlags
    );



__declspec(dllimport)
HANDLE

OpenProcess(
     DWORD dwDesiredAccess,
     BOOL bInheritHandle,
     DWORD dwProcessId
    );

__declspec(dllimport)

HANDLE

GetCurrentProcess(
    void
    );

__declspec(dllimport)
DWORD

GetCurrentProcessId(
    void
    );

__declspec(dllimport)

void

ExitProcess(
     UINT uExitCode
    );

__declspec(dllimport)
BOOL

TerminateProcess(
     HANDLE hProcess,
     UINT uExitCode
    );

__declspec(dllimport)
BOOL

GetExitCodeProcess(
     HANDLE hProcess,
     LPDWORD lpExitCode
    );

__declspec(dllimport)
void

FatalExit(
     int ExitCode
    );

__declspec(dllimport)


LPCH

GetEnvironmentStrings(
    void
    );

__declspec(dllimport)


LPWCH

GetEnvironmentStringsW(
    void
    );







__declspec(dllimport)
BOOL

SetEnvironmentStringsA(
       LPCH NewEnvironment
    );
__declspec(dllimport)
BOOL

SetEnvironmentStringsW(
       LPWCH NewEnvironment
    );






__declspec(dllimport)
BOOL

FreeEnvironmentStringsA(
       LPCH
    );
__declspec(dllimport)
BOOL

FreeEnvironmentStringsW(
       LPWCH
    );






__declspec(dllimport)
void

RaiseException(
     DWORD dwExceptionCode,
     DWORD dwExceptionFlags,
     DWORD nNumberOfArguments,
      const  ULONG_PTR *lpArguments
    );


__declspec(dllimport)
LONG

UnhandledExceptionFilter(
     struct _EXCEPTION_POINTERS *ExceptionInfo
    );

typedef LONG (  *PTOP_LEVEL_EXCEPTION_FILTER)(
     struct _EXCEPTION_POINTERS *ExceptionInfo
    );
typedef PTOP_LEVEL_EXCEPTION_FILTER LPTOP_LEVEL_EXCEPTION_FILTER;

__declspec(dllimport)
LPTOP_LEVEL_EXCEPTION_FILTER

SetUnhandledExceptionFilter(
     LPTOP_LEVEL_EXCEPTION_FILTER lpTopLevelExceptionFilter
    );









__declspec(dllimport)

LPVOID

CreateFiber(
     SIZE_T dwStackSize,
     LPFIBER_START_ROUTINE lpStartAddress,
     LPVOID lpParameter
    );

__declspec(dllimport)

LPVOID

CreateFiberEx(
     SIZE_T dwStackCommitSize,
     SIZE_T dwStackReserveSize,
     DWORD dwFlags,
     LPFIBER_START_ROUTINE lpStartAddress,
     LPVOID lpParameter
    );

__declspec(dllimport)
void

DeleteFiber(
     LPVOID lpFiber
    );

__declspec(dllimport)

LPVOID

ConvertThreadToFiber(
     LPVOID lpParameter
    );

__declspec(dllimport)

LPVOID

ConvertThreadToFiberEx(
     LPVOID lpParameter,
     DWORD dwFlags
    );



__declspec(dllimport)
BOOL

ConvertFiberToThread(
    void
    );





__declspec(dllimport)
BOOL

IsThreadAFiber(
    void
    );



__declspec(dllimport)
void

SwitchToFiber(
     LPVOID lpFiber
    );

__declspec(dllimport)
BOOL

SwitchToThread(
    void
    );



__declspec(dllimport)

HANDLE

CreateThread(
     LPSECURITY_ATTRIBUTES lpThreadAttributes,
     SIZE_T dwStackSize,
     LPTHREAD_START_ROUTINE lpStartAddress,
     LPVOID lpParameter,
     DWORD dwCreationFlags,
     LPDWORD lpThreadId
    );

__declspec(dllimport)

HANDLE

CreateRemoteThread(
     HANDLE hProcess,
     LPSECURITY_ATTRIBUTES lpThreadAttributes,
     SIZE_T dwStackSize,
     LPTHREAD_START_ROUTINE lpStartAddress,
     LPVOID lpParameter,
     DWORD dwCreationFlags,
     LPDWORD lpThreadId
    );

__declspec(dllimport)

HANDLE

GetCurrentThread(
    void
    );

__declspec(dllimport)
DWORD

GetCurrentThreadId(
    void
    );

__declspec(dllimport)
BOOL

SetThreadStackGuarantee (
     PULONG StackSizeInBytes
    );

__declspec(dllimport)
DWORD

GetProcessIdOfThread(
     HANDLE Thread
    );



__declspec(dllimport)
DWORD

GetThreadId(
     HANDLE Thread
    );



__declspec(dllimport)
DWORD

GetProcessId(
     HANDLE Process
    );

__declspec(dllimport)
DWORD

GetCurrentProcessorNumber(
    void
    );

__declspec(dllimport)
DWORD_PTR

SetThreadAffinityMask(
     HANDLE hThread,
     DWORD_PTR dwThreadAffinityMask
    );


__declspec(dllimport)
DWORD

SetThreadIdealProcessor(
     HANDLE hThread,
     DWORD dwIdealProcessor
    );







__declspec(dllimport)
BOOL

SetProcessDEPPolicy(
     DWORD dwFlags
    );

__declspec(dllimport)
BOOL

GetProcessDEPPolicy(
     HANDLE hProcess,
     LPDWORD lpFlags,
     PBOOL lpPermanent
    );



__declspec(dllimport)
BOOL

SetProcessPriorityBoost(
     HANDLE hProcess,
     BOOL bDisablePriorityBoost
    );

__declspec(dllimport)
BOOL

GetProcessPriorityBoost(
     HANDLE hProcess,
     PBOOL pDisablePriorityBoost
    );

__declspec(dllimport)
BOOL

RequestWakeupLatency(
     LATENCY_TIME latency
    );

__declspec(dllimport)
BOOL

IsSystemResumeAutomatic(
    void
    );

__declspec(dllimport)

HANDLE

OpenThread(
     DWORD dwDesiredAccess,
     BOOL bInheritHandle,
     DWORD dwThreadId
    );

__declspec(dllimport)
BOOL

SetThreadPriority(
     HANDLE hThread,
     int nPriority
    );

__declspec(dllimport)
BOOL

SetThreadPriorityBoost(
     HANDLE hThread,
     BOOL bDisablePriorityBoost
    );

__declspec(dllimport)
BOOL

GetThreadPriorityBoost(
     HANDLE hThread,
     PBOOL pDisablePriorityBoost
    );

__declspec(dllimport)
int

GetThreadPriority(
     HANDLE hThread
    );

__declspec(dllimport)
BOOL

GetThreadTimes(
     HANDLE hThread,
     LPFILETIME lpCreationTime,
     LPFILETIME lpExitTime,
     LPFILETIME lpKernelTime,
     LPFILETIME lpUserTime
    );



__declspec(dllimport)
BOOL

GetThreadIOPendingFlag(
     HANDLE hThread,
     PBOOL lpIOIsPending
    );



__declspec(dllimport)

void

ExitThread(
     DWORD dwExitCode
    );

__declspec(dllimport)
BOOL

TerminateThread(
     HANDLE hThread,
     DWORD dwExitCode
    );

__declspec(dllimport)
BOOL

GetExitCodeThread(
     HANDLE hThread,
     LPDWORD lpExitCode
    );

__declspec(dllimport)
BOOL

GetThreadSelectorEntry(
     HANDLE hThread,
     DWORD dwSelector,
     LPLDT_ENTRY lpSelectorEntry
    );

__declspec(dllimport)
EXECUTION_STATE

SetThreadExecutionState(
     EXECUTION_STATE esFlags
    );




__declspec(dllimport)

DWORD

GetLastError(
    void
    );


__declspec(dllimport)
void

SetLastError(
     DWORD dwErrCode
    );
__declspec(dllimport)
BOOL

GetOverlappedResult(
     HANDLE hFile,
     LPOVERLAPPED lpOverlapped,
     LPDWORD lpNumberOfBytesTransferred,
     BOOL bWait
    );

__declspec(dllimport)

HANDLE

CreateIoCompletionPort(
     HANDLE FileHandle,
     HANDLE ExistingCompletionPort,
     ULONG_PTR CompletionKey,
     DWORD NumberOfConcurrentThreads
    );

__declspec(dllimport)
BOOL

GetQueuedCompletionStatus(
     HANDLE CompletionPort,
     LPDWORD lpNumberOfBytesTransferred,
     PULONG_PTR lpCompletionKey,
     LPOVERLAPPED *lpOverlapped,
     DWORD dwMilliseconds
    );



__declspec(dllimport)
BOOL

GetQueuedCompletionStatusEx(
     HANDLE CompletionPort,
     LPOVERLAPPED_ENTRY lpCompletionPortEntries,
     ULONG ulCount,
     PULONG ulNumEntriesRemoved,
     DWORD dwMilliseconds,
     BOOL fAlertable
    );



__declspec(dllimport)
BOOL

PostQueuedCompletionStatus(
     HANDLE CompletionPort,
     DWORD dwNumberOfBytesTransferred,
     ULONG_PTR dwCompletionKey,
     LPOVERLAPPED lpOverlapped
    );
__declspec(dllimport)
BOOL

SetFileCompletionNotificationModes(
     HANDLE FileHandle,
     UCHAR Flags
    );

__declspec(dllimport)
BOOL

SetFileIoOverlappedRange(
     HANDLE FileHandle,
     PUCHAR OverlappedRangeStart,
     ULONG Length
    );








__declspec(dllimport)
UINT

GetErrorMode(
    void
    );

__declspec(dllimport)
UINT

SetErrorMode(
     UINT uMode
    );

__declspec(dllimport)
BOOL

ReadProcessMemory(
     HANDLE hProcess,
     LPCVOID lpBaseAddress,
     LPVOID lpBuffer,
     SIZE_T nSize,
     SIZE_T * lpNumberOfBytesRead
    );

__declspec(dllimport)
BOOL

WriteProcessMemory(
     HANDLE hProcess,
     LPVOID lpBaseAddress,
     LPCVOID lpBuffer,
     SIZE_T nSize,
     SIZE_T * lpNumberOfBytesWritten
    );


__declspec(dllimport)
BOOL

GetThreadContext(
     HANDLE hThread,
     LPCONTEXT lpContext
    );

__declspec(dllimport)
BOOL

SetThreadContext(
     HANDLE hThread,
      const  CONTEXT *lpContext
    );

__declspec(dllimport)
BOOL

Wow64GetThreadContext(
     HANDLE hThread,
     PWOW64_CONTEXT lpContext
    );

__declspec(dllimport)
BOOL

Wow64SetThreadContext(
     HANDLE hThread,
      const  WOW64_CONTEXT *lpContext
    );



__declspec(dllimport)
DWORD

SuspendThread(
     HANDLE hThread
    );

__declspec(dllimport)
DWORD

Wow64SuspendThread(
     HANDLE hThread
    );

__declspec(dllimport)
DWORD

ResumeThread(
     HANDLE hThread
    );




typedef
void
(  *PAPCFUNC)(
     ULONG_PTR dwParam
    );

__declspec(dllimport)
DWORD

QueueUserAPC(
     PAPCFUNC pfnAPC,
     HANDLE hThread,
     ULONG_PTR dwData
    );




__declspec(dllimport)
BOOL

IsDebuggerPresent(
    void
    );




__declspec(dllimport)
BOOL

CheckRemoteDebuggerPresent(
     HANDLE hProcess,
     PBOOL pbDebuggerPresent
    );



__declspec(dllimport)
void

DebugBreak(
    void
    );

__declspec(dllimport)
BOOL

WaitForDebugEvent(
     LPDEBUG_EVENT lpDebugEvent,
     DWORD dwMilliseconds
    );

__declspec(dllimport)
BOOL

ContinueDebugEvent(
     DWORD dwProcessId,
     DWORD dwThreadId,
     DWORD dwContinueStatus
    );

__declspec(dllimport)
BOOL

DebugActiveProcess(
     DWORD dwProcessId
    );

__declspec(dllimport)
BOOL

DebugActiveProcessStop(
     DWORD dwProcessId
    );

__declspec(dllimport)
BOOL

DebugSetProcessKillOnExit(
     BOOL KillOnExit
    );

__declspec(dllimport)
BOOL

DebugBreakProcess (
     HANDLE Process
    );

__declspec(dllimport)
void

InitializeCriticalSection(
     LPCRITICAL_SECTION lpCriticalSection
    );

__declspec(dllimport)
void

EnterCriticalSection(
     LPCRITICAL_SECTION lpCriticalSection
    );

__declspec(dllimport)
void

LeaveCriticalSection(
     LPCRITICAL_SECTION lpCriticalSection
    );




__declspec(dllimport)
BOOL

InitializeCriticalSectionAndSpinCount(
     LPCRITICAL_SECTION lpCriticalSection,
     DWORD dwSpinCount
    );

__declspec(dllimport)
BOOL

InitializeCriticalSectionEx(
     LPCRITICAL_SECTION lpCriticalSection,
     DWORD dwSpinCount,
     DWORD Flags
    );

__declspec(dllimport)
DWORD

SetCriticalSectionSpinCount(
     LPCRITICAL_SECTION lpCriticalSection,
     DWORD dwSpinCount
    );



__declspec(dllimport)
BOOL

TryEnterCriticalSection(
     LPCRITICAL_SECTION lpCriticalSection
    );


__declspec(dllimport)
void

DeleteCriticalSection(
     LPCRITICAL_SECTION lpCriticalSection
    );

__declspec(dllimport)
BOOL

SetEvent(
     HANDLE hEvent
    );

__declspec(dllimport)
BOOL

ResetEvent(
     HANDLE hEvent
    );

__declspec(dllimport)
BOOL

PulseEvent(
     HANDLE hEvent
    );

__declspec(dllimport)
BOOL

ReleaseSemaphore(
     HANDLE hSemaphore,
     LONG lReleaseCount,
     LPLONG lpPreviousCount
    );

__declspec(dllimport)
BOOL

ReleaseMutex(
     HANDLE hMutex
    );

__declspec(dllimport)
DWORD

WaitForSingleObject(
     HANDLE hHandle,
     DWORD dwMilliseconds
    );

__declspec(dllimport)
DWORD

WaitForMultipleObjects(
     DWORD nCount,
      const  HANDLE *lpHandles,
     BOOL bWaitAll,
     DWORD dwMilliseconds
    );

__declspec(dllimport)
void

Sleep(
     DWORD dwMilliseconds
    );

__declspec(dllimport)

HGLOBAL

LoadResource(
     HMODULE hModule,
     HRSRC hResInfo
    );

__declspec(dllimport)
DWORD

SizeofResource(
     HMODULE hModule,
     HRSRC hResInfo
    );


__declspec(dllimport)
ATOM

GlobalDeleteAtom(
     ATOM nAtom
    );

__declspec(dllimport)
BOOL

InitAtomTable(
     DWORD nSize
    );

__declspec(dllimport)
ATOM

DeleteAtom(
     ATOM nAtom
    );

__declspec(dllimport)
UINT

SetHandleCount(
     UINT uNumber
    );

__declspec(dllimport)
DWORD

GetLogicalDrives(
    void
    );

__declspec(dllimport)
BOOL

LockFile(
     HANDLE hFile,
     DWORD dwFileOffsetLow,
     DWORD dwFileOffsetHigh,
     DWORD nNumberOfBytesToLockLow,
     DWORD nNumberOfBytesToLockHigh
    );

__declspec(dllimport)
BOOL

UnlockFile(
     HANDLE hFile,
     DWORD dwFileOffsetLow,
     DWORD dwFileOffsetHigh,
     DWORD nNumberOfBytesToUnlockLow,
     DWORD nNumberOfBytesToUnlockHigh
    );

__declspec(dllimport)
BOOL

LockFileEx(
     HANDLE hFile,
     DWORD dwFlags,
     DWORD dwReserved,
     DWORD nNumberOfBytesToLockLow,
     DWORD nNumberOfBytesToLockHigh,
     LPOVERLAPPED lpOverlapped
    );




__declspec(dllimport)
BOOL

UnlockFileEx(
     HANDLE hFile,
     DWORD dwReserved,
     DWORD nNumberOfBytesToUnlockLow,
     DWORD nNumberOfBytesToUnlockHigh,
     LPOVERLAPPED lpOverlapped
    );

typedef struct _BY_HANDLE_FILE_INFORMATION {
    DWORD dwFileAttributes;
    FILETIME ftCreationTime;
    FILETIME ftLastAccessTime;
    FILETIME ftLastWriteTime;
    DWORD dwVolumeSerialNumber;
    DWORD nFileSizeHigh;
    DWORD nFileSizeLow;
    DWORD nNumberOfLinks;
    DWORD nFileIndexHigh;
    DWORD nFileIndexLow;
} BY_HANDLE_FILE_INFORMATION, *PBY_HANDLE_FILE_INFORMATION, *LPBY_HANDLE_FILE_INFORMATION;

__declspec(dllimport)
BOOL

GetFileInformationByHandle(
     HANDLE hFile,
     LPBY_HANDLE_FILE_INFORMATION lpFileInformation
    );

__declspec(dllimport)
DWORD

GetFileType(
     HANDLE hFile
    );

__declspec(dllimport)
DWORD

GetFileSize(
     HANDLE hFile,
     LPDWORD lpFileSizeHigh
    );

__declspec(dllimport)
BOOL

GetFileSizeEx(
     HANDLE hFile,
     PLARGE_INTEGER lpFileSize
    );


__declspec(dllimport)
HANDLE

GetStdHandle(
     DWORD nStdHandle
    );

__declspec(dllimport)
BOOL

SetStdHandle(
     DWORD nStdHandle,
     HANDLE hHandle
    );



__declspec(dllimport)
BOOL

SetStdHandleEx(
     DWORD nStdHandle,
     HANDLE hHandle,
     PHANDLE phPrevValue
    );



__declspec(dllimport)
BOOL

WriteFile(
     HANDLE hFile,
     LPCVOID lpBuffer,
     DWORD nNumberOfBytesToWrite,
     LPDWORD lpNumberOfBytesWritten,
     LPOVERLAPPED lpOverlapped
    );

__declspec(dllimport)
BOOL

ReadFile(
     HANDLE hFile,
       LPVOID lpBuffer,
     DWORD nNumberOfBytesToRead,
     LPDWORD lpNumberOfBytesRead,
     LPOVERLAPPED lpOverlapped
    );

__declspec(dllimport)
BOOL

FlushFileBuffers(
     HANDLE hFile
    );

__declspec(dllimport)
BOOL

DeviceIoControl(
     HANDLE hDevice,
     DWORD dwIoControlCode,
     LPVOID lpInBuffer,
     DWORD nInBufferSize,
     LPVOID lpOutBuffer,
     DWORD nOutBufferSize,
     LPDWORD lpBytesReturned,
     LPOVERLAPPED lpOverlapped
    );

__declspec(dllimport)
BOOL

RequestDeviceWakeup(
     HANDLE hDevice
    );

__declspec(dllimport)
BOOL

CancelDeviceWakeupRequest(
     HANDLE hDevice
    );

__declspec(dllimport)
BOOL

GetDevicePowerState(
     HANDLE hDevice,
     BOOL *pfOn
    );

__declspec(dllimport)
BOOL

SetMessageWaitingIndicator(
     HANDLE hMsgIndicator,
     ULONG ulMsgCount
    );

__declspec(dllimport)
BOOL

SetEndOfFile(
     HANDLE hFile
    );

__declspec(dllimport)
DWORD

SetFilePointer(
     HANDLE hFile,
     LONG lDistanceToMove,
     PLONG lpDistanceToMoveHigh,
     DWORD dwMoveMethod
    );

__declspec(dllimport)
BOOL

SetFilePointerEx(
     HANDLE hFile,
     LARGE_INTEGER liDistanceToMove,
     PLARGE_INTEGER lpNewFilePointer,
     DWORD dwMoveMethod
    );

__declspec(dllimport)
BOOL

FindClose(
     HANDLE hFindFile
    );

__declspec(dllimport)
BOOL

GetFileTime(
     HANDLE hFile,
     LPFILETIME lpCreationTime,
     LPFILETIME lpLastAccessTime,
     LPFILETIME lpLastWriteTime
    );

__declspec(dllimport)
BOOL

SetFileTime(
     HANDLE hFile,
      const  FILETIME *lpCreationTime,
      const  FILETIME *lpLastAccessTime,
      const  FILETIME *lpLastWriteTime
    );




__declspec(dllimport)
BOOL

SetFileValidData(
     HANDLE hFile,
     LONGLONG ValidDataLength
    );




__declspec(dllimport)
BOOL

SetFileShortNameA(
     HANDLE hFile,
     LPCSTR lpShortName
    );
__declspec(dllimport)
BOOL

SetFileShortNameW(
     HANDLE hFile,
     LPCWSTR lpShortName
    );






__declspec(dllimport)
BOOL

CloseHandle(
     HANDLE hObject
    );

__declspec(dllimport)
BOOL

DuplicateHandle(
     HANDLE hSourceProcessHandle,
     HANDLE hSourceHandle,
     HANDLE hTargetProcessHandle,
     LPHANDLE lpTargetHandle,
     DWORD dwDesiredAccess,
     BOOL bInheritHandle,
     DWORD dwOptions
    );

__declspec(dllimport)
BOOL

GetHandleInformation(
     HANDLE hObject,
     LPDWORD lpdwFlags
    );

__declspec(dllimport)
BOOL

SetHandleInformation(
     HANDLE hObject,
     DWORD dwMask,
     DWORD dwFlags
    );






__declspec(dllimport)
DWORD

LoadModule(
     LPCSTR lpModuleName,
     LPVOID lpParameterBlock
    );


__declspec(dllimport)
UINT

WinExec(
     LPCSTR lpCmdLine,
     UINT uCmdShow
    );

__declspec(dllimport)
BOOL

ClearCommBreak(
     HANDLE hFile
    );

__declspec(dllimport)
BOOL

ClearCommError(
     HANDLE hFile,
     LPDWORD lpErrors,
     LPCOMSTAT lpStat
    );

__declspec(dllimport)
BOOL

SetupComm(
     HANDLE hFile,
     DWORD dwInQueue,
     DWORD dwOutQueue
    );

__declspec(dllimport)
BOOL

EscapeCommFunction(
     HANDLE hFile,
     DWORD dwFunc
    );

__declspec(dllimport)

BOOL

GetCommConfig(
     HANDLE hCommDev,
     LPCOMMCONFIG lpCC,
     LPDWORD lpdwSize
    );

__declspec(dllimport)
BOOL

GetCommMask(
     HANDLE hFile,
     LPDWORD lpEvtMask
    );

__declspec(dllimport)
BOOL

GetCommProperties(
     HANDLE hFile,
     LPCOMMPROP lpCommProp
    );

__declspec(dllimport)
BOOL

GetCommModemStatus(
     HANDLE hFile,
     LPDWORD lpModemStat
    );

__declspec(dllimport)
BOOL

GetCommState(
     HANDLE hFile,
     LPDCB lpDCB
    );

__declspec(dllimport)
BOOL

GetCommTimeouts(
     HANDLE hFile,
     LPCOMMTIMEOUTS lpCommTimeouts
    );

__declspec(dllimport)
BOOL

PurgeComm(
     HANDLE hFile,
     DWORD dwFlags
    );

__declspec(dllimport)
BOOL

SetCommBreak(
     HANDLE hFile
    );

__declspec(dllimport)
BOOL

SetCommConfig(
     HANDLE hCommDev,
     LPCOMMCONFIG lpCC,
     DWORD dwSize
    );

__declspec(dllimport)
BOOL

SetCommMask(
     HANDLE hFile,
     DWORD dwEvtMask
    );

__declspec(dllimport)
BOOL

SetCommState(
     HANDLE hFile,
     LPDCB lpDCB
    );

__declspec(dllimport)
BOOL

SetCommTimeouts(
     HANDLE hFile,
     LPCOMMTIMEOUTS lpCommTimeouts
    );

__declspec(dllimport)
BOOL

TransmitCommChar(
     HANDLE hFile,
     char cChar
    );

__declspec(dllimport)
BOOL

WaitCommEvent(
     HANDLE hFile,
     LPDWORD lpEvtMask,
     LPOVERLAPPED lpOverlapped
    );


__declspec(dllimport)
DWORD

SetTapePosition(
     HANDLE hDevice,
     DWORD dwPositionMethod,
     DWORD dwPartition,
     DWORD dwOffsetLow,
     DWORD dwOffsetHigh,
     BOOL bImmediate
    );

__declspec(dllimport)
DWORD

GetTapePosition(
     HANDLE hDevice,
     DWORD dwPositionType,
     LPDWORD lpdwPartition,
     LPDWORD lpdwOffsetLow,
     LPDWORD lpdwOffsetHigh
    );

__declspec(dllimport)
DWORD

PrepareTape(
     HANDLE hDevice,
     DWORD dwOperation,
     BOOL bImmediate
    );

__declspec(dllimport)
DWORD

EraseTape(
     HANDLE hDevice,
     DWORD dwEraseType,
     BOOL bImmediate
    );

__declspec(dllimport)
DWORD

CreateTapePartition(
     HANDLE hDevice,
     DWORD dwPartitionMethod,
     DWORD dwCount,
     DWORD dwSize
    );

__declspec(dllimport)
DWORD

WriteTapemark(
     HANDLE hDevice,
     DWORD dwTapemarkType,
     DWORD dwTapemarkCount,
     BOOL bImmediate
    );

__declspec(dllimport)
DWORD

GetTapeStatus(
     HANDLE hDevice
    );

__declspec(dllimport)
DWORD

GetTapeParameters(
     HANDLE hDevice,
     DWORD dwOperation,
     LPDWORD lpdwSize,
     LPVOID lpTapeInformation
    );




__declspec(dllimport)
DWORD

SetTapeParameters(
     HANDLE hDevice,
     DWORD dwOperation,
     LPVOID lpTapeInformation
    );




__declspec(dllimport)
BOOL

Beep(
     DWORD dwFreq,
     DWORD dwDuration
    );

__declspec(dllimport)
int

MulDiv(
     int nNumber,
     int nNumerator,
     int nDenominator
    );

__declspec(dllimport)
void

GetSystemTime(
     LPSYSTEMTIME lpSystemTime
    );

__declspec(dllimport)
void

GetSystemTimeAsFileTime(
     LPFILETIME lpSystemTimeAsFileTime
    );

__declspec(dllimport)
BOOL

SetSystemTime(
      const  SYSTEMTIME *lpSystemTime
    );

__declspec(dllimport)
void

GetLocalTime(
     LPSYSTEMTIME lpSystemTime
    );

__declspec(dllimport)
BOOL

SetLocalTime(
      const  SYSTEMTIME *lpSystemTime
    );

__declspec(dllimport)
void

GetSystemInfo(
     LPSYSTEM_INFO lpSystemInfo
    );

typedef enum _DEP_SYSTEM_POLICY_TYPE {
    DEPPolicyAlwaysOff = 0,
    DEPPolicyAlwaysOn,
    DEPPolicyOptIn,
    DEPPolicyOptOut,
    DEPTotalPolicyCount
} DEP_SYSTEM_POLICY_TYPE;

__declspec(dllimport)
DEP_SYSTEM_POLICY_TYPE

GetSystemDEPPolicy(
    void
    );










__declspec(dllimport)
BOOL

SetSystemFileCacheSize (
     SIZE_T MinimumFileCacheSize,
     SIZE_T MaximumFileCacheSize,
     DWORD Flags
    );

__declspec(dllimport)
BOOL

GetSystemFileCacheSize (
     PSIZE_T lpMinimumFileCacheSize,
     PSIZE_T lpMaximumFileCacheSize,
     PDWORD lpFlags
    );





__declspec(dllimport)
BOOL

GetSystemRegistryQuota(
     PDWORD pdwQuotaAllowed,
     PDWORD pdwQuotaUsed
    );

BOOL

GetSystemTimes(
     LPFILETIME lpIdleTime,
     LPFILETIME lpKernelTime,
     LPFILETIME lpUserTime
    );




__declspec(dllimport)
void

GetNativeSystemInfo(
     LPSYSTEM_INFO lpSystemInfo
    );


__declspec(dllimport)
BOOL

IsProcessorFeaturePresent(
     DWORD ProcessorFeature
    );

typedef struct _TIME_ZONE_INFORMATION {
    LONG Bias;
    WCHAR StandardName[ 32 ];
    SYSTEMTIME StandardDate;
    LONG StandardBias;
    WCHAR DaylightName[ 32 ];
    SYSTEMTIME DaylightDate;
    LONG DaylightBias;
} TIME_ZONE_INFORMATION, *PTIME_ZONE_INFORMATION, *LPTIME_ZONE_INFORMATION;

typedef struct _TIME_DYNAMIC_ZONE_INFORMATION {
    LONG Bias;
    WCHAR StandardName[ 32 ];
    SYSTEMTIME StandardDate;
    LONG StandardBias;
    WCHAR DaylightName[ 32 ];
    SYSTEMTIME DaylightDate;
    LONG DaylightBias;
    WCHAR TimeZoneKeyName[ 128 ];
    BOOLEAN DynamicDaylightTimeDisabled;
} DYNAMIC_TIME_ZONE_INFORMATION, *PDYNAMIC_TIME_ZONE_INFORMATION;


__declspec(dllimport)
BOOL

SystemTimeToTzSpecificLocalTime(
      const  TIME_ZONE_INFORMATION *lpTimeZoneInformation,
      const  SYSTEMTIME *lpUniversalTime,
     LPSYSTEMTIME lpLocalTime
    );

__declspec(dllimport)
BOOL

TzSpecificLocalTimeToSystemTime(
      const  TIME_ZONE_INFORMATION *lpTimeZoneInformation,
      const  SYSTEMTIME *lpLocalTime,
     LPSYSTEMTIME lpUniversalTime
    );

BOOL

GetTimeZoneInformationForYear(
     USHORT wYear,
     PDYNAMIC_TIME_ZONE_INFORMATION pdtzi,
     LPTIME_ZONE_INFORMATION ptzi
    );

__declspec(dllimport)
DWORD

GetTimeZoneInformation(
     LPTIME_ZONE_INFORMATION lpTimeZoneInformation
    );

__declspec(dllimport)
BOOL

SetTimeZoneInformation(
      const  TIME_ZONE_INFORMATION *lpTimeZoneInformation
    );

__declspec(dllimport)
DWORD

GetDynamicTimeZoneInformation(
     PDYNAMIC_TIME_ZONE_INFORMATION pTimeZoneInformation
    );

__declspec(dllimport)
BOOL

SetDynamicTimeZoneInformation(
      const  DYNAMIC_TIME_ZONE_INFORMATION *lpTimeZoneInformation
    );







__declspec(dllimport)
BOOL

SystemTimeToFileTime(
      const  SYSTEMTIME *lpSystemTime,
     LPFILETIME lpFileTime
    );

__declspec(dllimport)
BOOL

FileTimeToLocalFileTime(
      const  FILETIME *lpFileTime,
     LPFILETIME lpLocalFileTime
    );

__declspec(dllimport)
BOOL

LocalFileTimeToFileTime(
      const  FILETIME *lpLocalFileTime,
     LPFILETIME lpFileTime
    );

__declspec(dllimport)
BOOL

FileTimeToSystemTime(
      const  FILETIME *lpFileTime,
     LPSYSTEMTIME lpSystemTime
    );

__declspec(dllimport)
LONG

CompareFileTime(
      const  FILETIME *lpFileTime1,
      const  FILETIME *lpFileTime2
    );

__declspec(dllimport)
BOOL

FileTimeToDosDateTime(
      const  FILETIME *lpFileTime,
     LPWORD lpFatDate,
     LPWORD lpFatTime
    );

__declspec(dllimport)
BOOL

DosDateTimeToFileTime(
     WORD wFatDate,
     WORD wFatTime,
     LPFILETIME lpFileTime
    );

__declspec(dllimport)
DWORD

GetTickCount(
    void
    );



__declspec(dllimport)
ULONGLONG

GetTickCount64(
    void
    );



__declspec(dllimport)
BOOL

SetSystemTimeAdjustment(
     DWORD dwTimeAdjustment,
     BOOL bTimeAdjustmentDisabled
    );

__declspec(dllimport)
BOOL

GetSystemTimeAdjustment(
     PDWORD lpTimeAdjustment,
     PDWORD lpTimeIncrement,
     PBOOL lpTimeAdjustmentDisabled
    );


__declspec(dllimport)
DWORD

FormatMessageA(
     DWORD dwFlags,
     LPCVOID lpSource,
     DWORD dwMessageId,
     DWORD dwLanguageId,
     LPSTR lpBuffer,
     DWORD nSize,
     va_list *Arguments
    );
__declspec(dllimport)
DWORD

FormatMessageW(
     DWORD dwFlags,
     LPCVOID lpSource,
     DWORD dwMessageId,
     DWORD dwLanguageId,
     LPWSTR lpBuffer,
     DWORD nSize,
     va_list *Arguments
    );
__declspec(dllimport)
BOOL

CreatePipe(
     PHANDLE hReadPipe,
     PHANDLE hWritePipe,
     LPSECURITY_ATTRIBUTES lpPipeAttributes,
     DWORD nSize
    );

__declspec(dllimport)
BOOL

ConnectNamedPipe(
     HANDLE hNamedPipe,
     LPOVERLAPPED lpOverlapped
    );

__declspec(dllimport)
BOOL

DisconnectNamedPipe(
     HANDLE hNamedPipe
    );

__declspec(dllimport)
BOOL

SetNamedPipeHandleState(
     HANDLE hNamedPipe,
     LPDWORD lpMode,
     LPDWORD lpMaxCollectionCount,
     LPDWORD lpCollectDataTimeout
    );

__declspec(dllimport)
BOOL

GetNamedPipeInfo(
     HANDLE hNamedPipe,
     LPDWORD lpFlags,
     LPDWORD lpOutBufferSize,
     LPDWORD lpInBufferSize,
     LPDWORD lpMaxInstances
    );

__declspec(dllimport)
BOOL

PeekNamedPipe(
     HANDLE hNamedPipe,
     LPVOID lpBuffer,
     DWORD nBufferSize,
     LPDWORD lpBytesRead,
     LPDWORD lpTotalBytesAvail,
     LPDWORD lpBytesLeftThisMessage
    );

__declspec(dllimport)
BOOL

TransactNamedPipe(
     HANDLE hNamedPipe,
     LPVOID lpInBuffer,
     DWORD nInBufferSize,
     LPVOID lpOutBuffer,
     DWORD nOutBufferSize,
     LPDWORD lpBytesRead,
     LPOVERLAPPED lpOverlapped
    );

__declspec(dllimport)

HANDLE

CreateMailslotA(
     LPCSTR lpName,
     DWORD nMaxMessageSize,
     DWORD lReadTimeout,
     LPSECURITY_ATTRIBUTES lpSecurityAttributes
    );
__declspec(dllimport)

HANDLE

CreateMailslotW(
     LPCWSTR lpName,
     DWORD nMaxMessageSize,
     DWORD lReadTimeout,
     LPSECURITY_ATTRIBUTES lpSecurityAttributes
    );






__declspec(dllimport)
BOOL

GetMailslotInfo(
     HANDLE hMailslot,
     LPDWORD lpMaxMessageSize,
     LPDWORD lpNextSize,
     LPDWORD lpMessageCount,
     LPDWORD lpReadTimeout
    );

__declspec(dllimport)
BOOL

SetMailslotInfo(
     HANDLE hMailslot,
     DWORD lReadTimeout
    );

__declspec(dllimport)

LPVOID

MapViewOfFile(
     HANDLE hFileMappingObject,
     DWORD dwDesiredAccess,
     DWORD dwFileOffsetHigh,
     DWORD dwFileOffsetLow,
     SIZE_T dwNumberOfBytesToMap
    );

__declspec(dllimport)
BOOL

FlushViewOfFile(
     LPCVOID lpBaseAddress,
     SIZE_T dwNumberOfBytesToFlush
    );

__declspec(dllimport)
BOOL

UnmapViewOfFile(
     LPCVOID lpBaseAddress
    );





__declspec(dllimport)
BOOL

EncryptFileA(
     LPCSTR lpFileName
    );
__declspec(dllimport)
BOOL

EncryptFileW(
     LPCWSTR lpFileName
    );






__declspec(dllimport)
BOOL

DecryptFileA(
     LPCSTR lpFileName,
     DWORD dwReserved
    );
__declspec(dllimport)
BOOL

DecryptFileW(
     LPCWSTR lpFileName,
     DWORD dwReserved
    );
__declspec(dllimport)
BOOL

FileEncryptionStatusA(
     LPCSTR lpFileName,
     LPDWORD lpStatus
    );
__declspec(dllimport)
BOOL

FileEncryptionStatusW(
     LPCWSTR lpFileName,
     LPDWORD lpStatus
    );
typedef
DWORD
(  *PFE_EXPORT_FUNC)(
     PBYTE pbData,
     PVOID pvCallbackContext,
     ULONG ulLength
    );

typedef
DWORD
(  *PFE_IMPORT_FUNC)(
     PBYTE pbData,
     PVOID pvCallbackContext,
     PULONG ulLength
    );
__declspec(dllimport)
DWORD

OpenEncryptedFileRawA(
     LPCSTR lpFileName,
     ULONG ulFlags,
     PVOID *pvContext
    );
__declspec(dllimport)
DWORD

OpenEncryptedFileRawW(
     LPCWSTR lpFileName,
     ULONG ulFlags,
     PVOID *pvContext
    );






__declspec(dllimport)
DWORD

ReadEncryptedFileRaw(
     PFE_EXPORT_FUNC pfExportCallback,
     PVOID pvCallbackContext,
     PVOID pvContext
    );

__declspec(dllimport)
DWORD

WriteEncryptedFileRaw(
     PFE_IMPORT_FUNC pfImportCallback,
     PVOID pvCallbackContext,
     PVOID pvContext
    );

__declspec(dllimport)
void

CloseEncryptedFileRaw(
     PVOID pvContext
    );





__declspec(dllimport)
int

lstrcmpA(
     LPCSTR lpString1,
     LPCSTR lpString2
    );
__declspec(dllimport)
int

lstrcmpW(
     LPCWSTR lpString1,
     LPCWSTR lpString2
    );






__declspec(dllimport)
int

lstrcmpiA(
     LPCSTR lpString1,
     LPCSTR lpString2
    );
__declspec(dllimport)
int

lstrcmpiW(
     LPCWSTR lpString1,
     LPCWSTR lpString2
    );






__declspec(dllimport)

LPSTR

lstrcpynA(
     LPSTR lpString1,
     LPCSTR lpString2,
     int iMaxLength
    );
__declspec(dllimport)

LPWSTR

lstrcpynW(
     LPWSTR lpString1,
     LPCWSTR lpString2,
     int iMaxLength
    );
__declspec(dllimport)

LPSTR

lstrcpyA(
     LPSTR lpString1,
     LPCSTR lpString2
    );
__declspec(dllimport)

LPWSTR

lstrcpyW(
     LPWSTR lpString1,
     LPCWSTR lpString2
    );






__declspec(dllimport)

LPSTR

lstrcatA(
     LPSTR lpString1,
     LPCSTR lpString2
    );
__declspec(dllimport)

LPWSTR

lstrcatW(
     LPWSTR lpString1,
     LPCWSTR lpString2
    );
__declspec(dllimport)
int

lstrlenA(
     LPCSTR lpString
    );
__declspec(dllimport)
int

lstrlenW(
     LPCWSTR lpString
    );






__declspec(dllimport)
HFILE

OpenFile(
     LPCSTR lpFileName,
     LPOFSTRUCT lpReOpenBuff,
     UINT uStyle
    );

__declspec(dllimport)
HFILE

_lopen(
     LPCSTR lpPathName,
     int iReadWrite
    );

__declspec(dllimport)
HFILE

_lcreat(
     LPCSTR lpPathName,
     int iAttribute
    );

__declspec(dllimport)
UINT

_lread(
     HFILE hFile,
     LPVOID lpBuffer,
     UINT uBytes
    );

__declspec(dllimport)
UINT

_lwrite(
     HFILE hFile,
     LPCCH lpBuffer,
     UINT uBytes
    );

__declspec(dllimport)
long

_hread(
     HFILE hFile,
     LPVOID lpBuffer,
     long lBytes
    );

__declspec(dllimport)
long

_hwrite(
     HFILE hFile,
     LPCCH lpBuffer,
     long lBytes
    );

__declspec(dllimport)
HFILE

_lclose(
     HFILE hFile
    );

__declspec(dllimport)
LONG

_llseek(
     HFILE hFile,
     LONG lOffset,
     int iOrigin
    );

__declspec(dllimport)
BOOL

IsTextUnicode(
      const   void * lpv,
     int iSize,
     LPINT lpiResult
    );



__declspec(dllimport)
DWORD

FlsAlloc(
     PFLS_CALLBACK_FUNCTION lpCallback
    );

__declspec(dllimport)
PVOID

FlsGetValue(
     DWORD dwFlsIndex
    );

__declspec(dllimport)
BOOL

FlsSetValue(
     DWORD dwFlsIndex,
     PVOID lpFlsData
    );

__declspec(dllimport)
BOOL

FlsFree(
     DWORD dwFlsIndex
    );



__declspec(dllimport)
DWORD

TlsAlloc(
    void
    );

__declspec(dllimport)
LPVOID

TlsGetValue(
     DWORD dwTlsIndex
    );

__declspec(dllimport)
BOOL

TlsSetValue(
     DWORD dwTlsIndex,
     LPVOID lpTlsValue
    );

__declspec(dllimport)
BOOL

TlsFree(
     DWORD dwTlsIndex
    );

typedef
void
(  *LPOVERLAPPED_COMPLETION_ROUTINE)(
     DWORD dwErrorCode,
     DWORD dwNumberOfBytesTransfered,
     LPOVERLAPPED lpOverlapped
    );

__declspec(dllimport)
DWORD

SleepEx(
     DWORD dwMilliseconds,
     BOOL bAlertable
    );

__declspec(dllimport)
DWORD

WaitForSingleObjectEx(
     HANDLE hHandle,
     DWORD dwMilliseconds,
     BOOL bAlertable
    );

__declspec(dllimport)
DWORD

WaitForMultipleObjectsEx(
     DWORD nCount,
      const  HANDLE *lpHandles,
     BOOL bWaitAll,
     DWORD dwMilliseconds,
     BOOL bAlertable
    );


__declspec(dllimport)
DWORD

SignalObjectAndWait(
     HANDLE hObjectToSignal,
     HANDLE hObjectToWaitOn,
     DWORD dwMilliseconds,
     BOOL bAlertable
    );


__declspec(dllimport)
BOOL

ReadFileEx(
     HANDLE hFile,
       LPVOID lpBuffer,
     DWORD nNumberOfBytesToRead,
     LPOVERLAPPED lpOverlapped,
     LPOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine
    );

__declspec(dllimport)
BOOL

WriteFileEx(
     HANDLE hFile,
     LPCVOID lpBuffer,
     DWORD nNumberOfBytesToWrite,
     LPOVERLAPPED lpOverlapped,
     LPOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine
    );

__declspec(dllimport)
BOOL

BackupRead(
     HANDLE hFile,
     LPBYTE lpBuffer,
     DWORD nNumberOfBytesToRead,
     LPDWORD lpNumberOfBytesRead,
     BOOL bAbort,
     BOOL bProcessSecurity,
     LPVOID *lpContext
    );

__declspec(dllimport)
BOOL

BackupSeek(
     HANDLE hFile,
     DWORD dwLowBytesToSeek,
     DWORD dwHighBytesToSeek,
     LPDWORD lpdwLowByteSeeked,
     LPDWORD lpdwHighByteSeeked,
     LPVOID *lpContext
    );

__declspec(dllimport)
BOOL

BackupWrite(
     HANDLE hFile,
     LPBYTE lpBuffer,
     DWORD nNumberOfBytesToWrite,
     LPDWORD lpNumberOfBytesWritten,
     BOOL bAbort,
     BOOL bProcessSecurity,
     LPVOID *lpContext
    );




typedef struct _WIN32_STREAM_ID {
        DWORD dwStreamId ;
        DWORD dwStreamAttributes ;
        LARGE_INTEGER Size ;
        DWORD dwStreamNameSize ;
        WCHAR cStreamName[  1  ] ;
} WIN32_STREAM_ID, *LPWIN32_STREAM_ID ;
__declspec(dllimport)
BOOL

ReadFileScatter(
     HANDLE hFile,
     FILE_SEGMENT_ELEMENT aSegmentArray[],
     DWORD nNumberOfBytesToRead,
     LPDWORD lpReserved,
     LPOVERLAPPED lpOverlapped
    );

__declspec(dllimport)
BOOL

WriteFileGather(
     HANDLE hFile,
     FILE_SEGMENT_ELEMENT aSegmentArray[],
     DWORD nNumberOfBytesToWrite,
     LPDWORD lpReserved,
     LPOVERLAPPED lpOverlapped
    );
typedef struct _STARTUPINFOA {
    DWORD cb;
    LPSTR lpReserved;
    LPSTR lpDesktop;
    LPSTR lpTitle;
    DWORD dwX;
    DWORD dwY;
    DWORD dwXSize;
    DWORD dwYSize;
    DWORD dwXCountChars;
    DWORD dwYCountChars;
    DWORD dwFillAttribute;
    DWORD dwFlags;
    WORD wShowWindow;
    WORD cbReserved2;
    LPBYTE lpReserved2;
    HANDLE hStdInput;
    HANDLE hStdOutput;
    HANDLE hStdError;
} STARTUPINFOA, *LPSTARTUPINFOA;
typedef struct _STARTUPINFOW {
    DWORD cb;
    LPWSTR lpReserved;
    LPWSTR lpDesktop;
    LPWSTR lpTitle;
    DWORD dwX;
    DWORD dwY;
    DWORD dwXSize;
    DWORD dwYSize;
    DWORD dwXCountChars;
    DWORD dwYCountChars;
    DWORD dwFillAttribute;
    DWORD dwFlags;
    WORD wShowWindow;
    WORD cbReserved2;
    LPBYTE lpReserved2;
    HANDLE hStdInput;
    HANDLE hStdOutput;
    HANDLE hStdError;
} STARTUPINFOW, *LPSTARTUPINFOW;




typedef STARTUPINFOA STARTUPINFO;
typedef LPSTARTUPINFOA LPSTARTUPINFO;


typedef struct _STARTUPINFOEXA {
    STARTUPINFOA StartupInfo;
    struct _PROC_THREAD_ATTRIBUTE_LIST *lpAttributeList;
} STARTUPINFOEXA, *LPSTARTUPINFOEXA;
typedef struct _STARTUPINFOEXW {
    STARTUPINFOW StartupInfo;
    struct _PROC_THREAD_ATTRIBUTE_LIST *lpAttributeList;
} STARTUPINFOEXW, *LPSTARTUPINFOEXW;




typedef STARTUPINFOEXA STARTUPINFOEX;
typedef LPSTARTUPINFOEXA LPSTARTUPINFOEX;




typedef struct _WIN32_FIND_DATAA {
    DWORD dwFileAttributes;
    FILETIME ftCreationTime;
    FILETIME ftLastAccessTime;
    FILETIME ftLastWriteTime;
    DWORD nFileSizeHigh;
    DWORD nFileSizeLow;
    DWORD dwReserved0;
    DWORD dwReserved1;
    CHAR cFileName[  260  ];
    CHAR cAlternateFileName[ 14 ];
} WIN32_FIND_DATAA, *PWIN32_FIND_DATAA, *LPWIN32_FIND_DATAA;
typedef struct _WIN32_FIND_DATAW {
    DWORD dwFileAttributes;
    FILETIME ftCreationTime;
    FILETIME ftLastAccessTime;
    FILETIME ftLastWriteTime;
    DWORD nFileSizeHigh;
    DWORD nFileSizeLow;
    DWORD dwReserved0;
    DWORD dwReserved1;
    WCHAR cFileName[  260  ];
    WCHAR cAlternateFileName[ 14 ];
} WIN32_FIND_DATAW, *PWIN32_FIND_DATAW, *LPWIN32_FIND_DATAW;





typedef WIN32_FIND_DATAA WIN32_FIND_DATA;
typedef PWIN32_FIND_DATAA PWIN32_FIND_DATA;
typedef LPWIN32_FIND_DATAA LPWIN32_FIND_DATA;


typedef struct _WIN32_FILE_ATTRIBUTE_DATA {
    DWORD dwFileAttributes;
    FILETIME ftCreationTime;
    FILETIME ftLastAccessTime;
    FILETIME ftLastWriteTime;
    DWORD nFileSizeHigh;
    DWORD nFileSizeLow;
} WIN32_FILE_ATTRIBUTE_DATA, *LPWIN32_FILE_ATTRIBUTE_DATA;





__declspec(dllimport)

HANDLE

CreateMutexA(
     LPSECURITY_ATTRIBUTES lpMutexAttributes,
     BOOL bInitialOwner,
     LPCSTR lpName
    );
__declspec(dllimport)

HANDLE

CreateMutexW(
     LPSECURITY_ATTRIBUTES lpMutexAttributes,
     BOOL bInitialOwner,
     LPCWSTR lpName
    );






__declspec(dllimport)

HANDLE

OpenMutexA(
     DWORD dwDesiredAccess,
     BOOL bInheritHandle,
     LPCSTR lpName
    );
__declspec(dllimport)

HANDLE

OpenMutexW(
     DWORD dwDesiredAccess,
     BOOL bInheritHandle,
     LPCWSTR lpName
    );






__declspec(dllimport)

HANDLE

CreateEventA(
     LPSECURITY_ATTRIBUTES lpEventAttributes,
     BOOL bManualReset,
     BOOL bInitialState,
     LPCSTR lpName
    );
__declspec(dllimport)

HANDLE

CreateEventW(
     LPSECURITY_ATTRIBUTES lpEventAttributes,
     BOOL bManualReset,
     BOOL bInitialState,
     LPCWSTR lpName
    );






__declspec(dllimport)

HANDLE

OpenEventA(
     DWORD dwDesiredAccess,
     BOOL bInheritHandle,
     LPCSTR lpName
    );
__declspec(dllimport)

HANDLE

OpenEventW(
     DWORD dwDesiredAccess,
     BOOL bInheritHandle,
     LPCWSTR lpName
    );






__declspec(dllimport)

HANDLE

CreateSemaphoreA(
     LPSECURITY_ATTRIBUTES lpSemaphoreAttributes,
     LONG lInitialCount,
     LONG lMaximumCount,
     LPCSTR lpName
    );
__declspec(dllimport)

HANDLE

CreateSemaphoreW(
     LPSECURITY_ATTRIBUTES lpSemaphoreAttributes,
     LONG lInitialCount,
     LONG lMaximumCount,
     LPCWSTR lpName
    );






__declspec(dllimport)

HANDLE

OpenSemaphoreA(
     DWORD dwDesiredAccess,
     BOOL bInheritHandle,
     LPCSTR lpName
    );
__declspec(dllimport)

HANDLE

OpenSemaphoreW(
     DWORD dwDesiredAccess,
     BOOL bInheritHandle,
     LPCWSTR lpName
    );







typedef
void
(  *PTIMERAPCROUTINE)(
     LPVOID lpArgToCompletionRoutine,
     DWORD dwTimerLowValue,
     DWORD dwTimerHighValue
    );

__declspec(dllimport)

HANDLE

CreateWaitableTimerA(
     LPSECURITY_ATTRIBUTES lpTimerAttributes,
     BOOL bManualReset,
     LPCSTR lpTimerName
    );
__declspec(dllimport)

HANDLE

CreateWaitableTimerW(
     LPSECURITY_ATTRIBUTES lpTimerAttributes,
     BOOL bManualReset,
     LPCWSTR lpTimerName
    );






__declspec(dllimport)

HANDLE

OpenWaitableTimerA(
     DWORD dwDesiredAccess,
     BOOL bInheritHandle,
     LPCSTR lpTimerName
    );
__declspec(dllimport)

HANDLE

OpenWaitableTimerW(
     DWORD dwDesiredAccess,
     BOOL bInheritHandle,
     LPCWSTR lpTimerName
    );






__declspec(dllimport)
BOOL

SetWaitableTimer(
     HANDLE hTimer,
     const LARGE_INTEGER *lpDueTime,
     LONG lPeriod,
     PTIMERAPCROUTINE pfnCompletionRoutine,
     LPVOID lpArgToCompletionRoutine,
     BOOL fResume
    );

__declspec(dllimport)
BOOL

CancelWaitableTimer(
     HANDLE hTimer
    );





__declspec(dllimport)

HANDLE

CreateMutexExA(
     LPSECURITY_ATTRIBUTES lpMutexAttributes,
     LPCSTR lpName,
     DWORD dwFlags,
     DWORD dwDesiredAccess
    );
__declspec(dllimport)

HANDLE

CreateMutexExW(
     LPSECURITY_ATTRIBUTES lpMutexAttributes,
     LPCWSTR lpName,
     DWORD dwFlags,
     DWORD dwDesiredAccess
    );









__declspec(dllimport)

HANDLE

CreateEventExA(
     LPSECURITY_ATTRIBUTES lpEventAttributes,
     LPCSTR lpName,
     DWORD dwFlags,
     DWORD dwDesiredAccess
    );
__declspec(dllimport)

HANDLE

CreateEventExW(
     LPSECURITY_ATTRIBUTES lpEventAttributes,
     LPCWSTR lpName,
     DWORD dwFlags,
     DWORD dwDesiredAccess
    );






__declspec(dllimport)

HANDLE

CreateSemaphoreExA(
     LPSECURITY_ATTRIBUTES lpSemaphoreAttributes,
     LONG lInitialCount,
     LONG lMaximumCount,
     LPCSTR lpName,
     DWORD dwFlags,
     DWORD dwDesiredAccess
    );
__declspec(dllimport)

HANDLE

CreateSemaphoreExW(
     LPSECURITY_ATTRIBUTES lpSemaphoreAttributes,
     LONG lInitialCount,
     LONG lMaximumCount,
     LPCWSTR lpName,
     DWORD dwFlags,
     DWORD dwDesiredAccess
    );








__declspec(dllimport)

HANDLE

CreateWaitableTimerExA(
     LPSECURITY_ATTRIBUTES lpTimerAttributes,
     LPCSTR lpTimerName,
     DWORD dwFlags,
     DWORD dwDesiredAccess
    );
__declspec(dllimport)

HANDLE

CreateWaitableTimerExW(
     LPSECURITY_ATTRIBUTES lpTimerAttributes,
     LPCWSTR lpTimerName,
     DWORD dwFlags,
     DWORD dwDesiredAccess
    );










__declspec(dllimport)

HANDLE

CreateFileMappingA(
     HANDLE hFile,
     LPSECURITY_ATTRIBUTES lpFileMappingAttributes,
     DWORD flProtect,
     DWORD dwMaximumSizeHigh,
     DWORD dwMaximumSizeLow,
     LPCSTR lpName
    );
__declspec(dllimport)

HANDLE

CreateFileMappingW(
     HANDLE hFile,
     LPSECURITY_ATTRIBUTES lpFileMappingAttributes,
     DWORD flProtect,
     DWORD dwMaximumSizeHigh,
     DWORD dwMaximumSizeLow,
     LPCWSTR lpName
    );








__declspec(dllimport)

HANDLE

CreateFileMappingNumaA(
     HANDLE hFile,
     LPSECURITY_ATTRIBUTES lpFileMappingAttributes,
     DWORD flProtect,
     DWORD dwMaximumSizeHigh,
     DWORD dwMaximumSizeLow,
     LPCSTR lpName,
     DWORD nndPreferred
    );
__declspec(dllimport)

HANDLE

CreateFileMappingNumaW(
     HANDLE hFile,
     LPSECURITY_ATTRIBUTES lpFileMappingAttributes,
     DWORD flProtect,
     DWORD dwMaximumSizeHigh,
     DWORD dwMaximumSizeLow,
     LPCWSTR lpName,
     DWORD nndPreferred
    );








__declspec(dllimport)

HANDLE

OpenFileMappingA(
     DWORD dwDesiredAccess,
     BOOL bInheritHandle,
     LPCSTR lpName
    );
__declspec(dllimport)

HANDLE

OpenFileMappingW(
     DWORD dwDesiredAccess,
     BOOL bInheritHandle,
     LPCWSTR lpName
    );






__declspec(dllimport)
DWORD

GetLogicalDriveStringsA(
     DWORD nBufferLength,
     LPSTR lpBuffer
    );
__declspec(dllimport)
DWORD

GetLogicalDriveStringsW(
     DWORD nBufferLength,
     LPWSTR lpBuffer
    );








typedef enum _MEMORY_RESOURCE_NOTIFICATION_TYPE {
    LowMemoryResourceNotification,
    HighMemoryResourceNotification
} MEMORY_RESOURCE_NOTIFICATION_TYPE;

__declspec(dllimport)

HANDLE

CreateMemoryResourceNotification(
     MEMORY_RESOURCE_NOTIFICATION_TYPE NotificationType
    );

__declspec(dllimport)
BOOL

QueryMemoryResourceNotification(
     HANDLE ResourceNotificationHandle,
     PBOOL ResourceState
    );




__declspec(dllimport)

HMODULE

LoadLibraryA(
     LPCSTR lpLibFileName
    );
__declspec(dllimport)

HMODULE

LoadLibraryW(
     LPCWSTR lpLibFileName
    );






__declspec(dllimport)

HMODULE

LoadLibraryExA(
     LPCSTR lpLibFileName,
     HANDLE hFile,
     DWORD dwFlags
    );
__declspec(dllimport)

HMODULE

LoadLibraryExW(
     LPCWSTR lpLibFileName,
     HANDLE hFile,
     DWORD dwFlags
    );
__declspec(dllimport)
DWORD

GetModuleFileNameA(
     HMODULE hModule,
     LPCH lpFilename,
     DWORD nSize
    );
__declspec(dllimport)
DWORD

GetModuleFileNameW(
     HMODULE hModule,
     LPWCH lpFilename,
     DWORD nSize
    );






__declspec(dllimport)

HMODULE

GetModuleHandleA(
     LPCSTR lpModuleName
    );
__declspec(dllimport)

HMODULE

GetModuleHandleW(
     LPCWSTR lpModuleName
    );
typedef
BOOL
( *
PGET_MODULE_HANDLE_EXA)(
     DWORD dwFlags,
     LPCSTR lpModuleName,
     HMODULE* phModule
    );
typedef
BOOL
( *
PGET_MODULE_HANDLE_EXW)(
     DWORD dwFlags,
     LPCWSTR lpModuleName,
     HMODULE* phModule
    );






__declspec(dllimport)
BOOL

GetModuleHandleExA(
     DWORD dwFlags,
     LPCSTR lpModuleName,
     HMODULE* phModule
    );
__declspec(dllimport)
BOOL

GetModuleHandleExW(
     DWORD dwFlags,
     LPCWSTR lpModuleName,
     HMODULE* phModule
    );
__declspec(dllimport)
BOOL

NeedCurrentDirectoryForExePathA(
     LPCSTR ExeName
    );
__declspec(dllimport)
BOOL

NeedCurrentDirectoryForExePathW(
     LPCWSTR ExeName
    );
__declspec(dllimport)
BOOL

QueryFullProcessImageNameA(
     HANDLE hProcess,
     DWORD dwFlags,
     LPSTR lpExeName,
     PDWORD lpdwSize
    );
__declspec(dllimport)
BOOL

QueryFullProcessImageNameW(
     HANDLE hProcess,
     DWORD dwFlags,
     LPWSTR lpExeName,
     PDWORD lpdwSize
    );
typedef enum _PROC_THREAD_ATTRIBUTE_NUM {
    ProcThreadAttributeParentProcess = 0,
    ProcThreadAttributeExtendedFlags,
    ProcThreadAttributeHandleList,
    ProcThreadAttributeMax
} PROC_THREAD_ATTRIBUTE_NUM;
typedef struct _PROC_THREAD_ATTRIBUTE_LIST *PPROC_THREAD_ATTRIBUTE_LIST, *LPPROC_THREAD_ATTRIBUTE_LIST;


__declspec(dllimport)
BOOL

InitializeProcThreadAttributeList(
     LPPROC_THREAD_ATTRIBUTE_LIST lpAttributeList,
     DWORD dwAttributeCount,
       DWORD dwFlags,
     PSIZE_T lpSize
    );

__declspec(dllimport)
void

DeleteProcThreadAttributeList(
     LPPROC_THREAD_ATTRIBUTE_LIST lpAttributeList
    );



__declspec(dllimport)
BOOL

UpdateProcThreadAttribute(
     LPPROC_THREAD_ATTRIBUTE_LIST lpAttributeList,
     DWORD dwFlags,
     DWORD_PTR Attribute,
     PVOID lpValue,
     SIZE_T cbSize,
     PVOID lpPreviousValue,
     PSIZE_T lpReturnSize
    );


__declspec(dllimport)
BOOL

CreateProcessA(
     LPCSTR lpApplicationName,
     LPSTR lpCommandLine,
     LPSECURITY_ATTRIBUTES lpProcessAttributes,
     LPSECURITY_ATTRIBUTES lpThreadAttributes,
     BOOL bInheritHandles,
     DWORD dwCreationFlags,
     LPVOID lpEnvironment,
     LPCSTR lpCurrentDirectory,
     LPSTARTUPINFOA lpStartupInfo,
     LPPROCESS_INFORMATION lpProcessInformation
    );
__declspec(dllimport)
BOOL

CreateProcessW(
     LPCWSTR lpApplicationName,
     LPWSTR lpCommandLine,
     LPSECURITY_ATTRIBUTES lpProcessAttributes,
     LPSECURITY_ATTRIBUTES lpThreadAttributes,
     BOOL bInheritHandles,
     DWORD dwCreationFlags,
     LPVOID lpEnvironment,
     LPCWSTR lpCurrentDirectory,
     LPSTARTUPINFOW lpStartupInfo,
     LPPROCESS_INFORMATION lpProcessInformation
    );








__declspec(dllimport)
BOOL

SetProcessShutdownParameters(
     DWORD dwLevel,
     DWORD dwFlags
    );

__declspec(dllimport)
BOOL

GetProcessShutdownParameters(
     LPDWORD lpdwLevel,
     LPDWORD lpdwFlags
    );

__declspec(dllimport)
DWORD

GetProcessVersion(
     DWORD ProcessId
    );

__declspec(dllimport)
void

FatalAppExitA(
     UINT uAction,
     LPCSTR lpMessageText
    );
__declspec(dllimport)
void

FatalAppExitW(
     UINT uAction,
     LPCWSTR lpMessageText
    );






__declspec(dllimport)
void

GetStartupInfoA(
     LPSTARTUPINFOA lpStartupInfo
    );
__declspec(dllimport)
void

GetStartupInfoW(
     LPSTARTUPINFOW lpStartupInfo
    );






__declspec(dllimport)

LPSTR

GetCommandLineA(
    void
    );
__declspec(dllimport)

LPWSTR

GetCommandLineW(
    void
    );






__declspec(dllimport)


DWORD

GetEnvironmentVariableA(
     LPCSTR lpName,
     LPSTR lpBuffer,
     DWORD nSize
    );
__declspec(dllimport)


DWORD

GetEnvironmentVariableW(
     LPCWSTR lpName,
     LPWSTR lpBuffer,
     DWORD nSize
    );
__declspec(dllimport)
BOOL

SetEnvironmentVariableA(
     LPCSTR lpName,
     LPCSTR lpValue
    );
__declspec(dllimport)
BOOL

SetEnvironmentVariableW(
     LPCWSTR lpName,
     LPCWSTR lpValue
    );
__declspec(dllimport)


DWORD

ExpandEnvironmentStringsA(
     LPCSTR lpSrc,
     LPSTR lpDst,
     DWORD nSize
    );
__declspec(dllimport)


DWORD

ExpandEnvironmentStringsW(
     LPCWSTR lpSrc,
     LPWSTR lpDst,
     DWORD nSize
    );






__declspec(dllimport)
DWORD

GetFirmwareEnvironmentVariableA(
     LPCSTR lpName,
     LPCSTR lpGuid,
     PVOID pBuffer,
     DWORD nSize
    );
__declspec(dllimport)
DWORD

GetFirmwareEnvironmentVariableW(
     LPCWSTR lpName,
     LPCWSTR lpGuid,
     PVOID pBuffer,
     DWORD nSize
    );






__declspec(dllimport)
BOOL

SetFirmwareEnvironmentVariableA(
     LPCSTR lpName,
     LPCSTR lpGuid,
     PVOID pValue,
     DWORD nSize
    );
__declspec(dllimport)
BOOL

SetFirmwareEnvironmentVariableW(
     LPCWSTR lpName,
     LPCWSTR lpGuid,
     PVOID pValue,
     DWORD nSize
    );







__declspec(dllimport)
void

OutputDebugStringA(
     LPCSTR lpOutputString
    );
__declspec(dllimport)
void

OutputDebugStringW(
     LPCWSTR lpOutputString
    );






__declspec(dllimport)

HRSRC

FindResourceA(
     HMODULE hModule,
     LPCSTR lpName,
     LPCSTR lpType
    );
__declspec(dllimport)

HRSRC

FindResourceW(
     HMODULE hModule,
     LPCWSTR lpName,
     LPCWSTR lpType
    );






__declspec(dllimport)

HRSRC

FindResourceExA(
     HMODULE hModule,
     LPCSTR lpType,
     LPCSTR lpName,
     WORD wLanguage
    );
__declspec(dllimport)

HRSRC

FindResourceExW(
     HMODULE hModule,
     LPCWSTR lpType,
     LPCWSTR lpName,
     WORD wLanguage
    );







typedef BOOL ( * ENUMRESTYPEPROCA)(       HMODULE hModule,      LPSTR lpType,
 LONG_PTR lParam);
typedef BOOL ( * ENUMRESTYPEPROCW)(       HMODULE hModule,      LPWSTR lpType,
 LONG_PTR lParam);





typedef BOOL ( * ENUMRESNAMEPROCA)(       HMODULE hModule,      LPCSTR lpType,
 LPSTR lpName,      LONG_PTR lParam);
typedef BOOL ( * ENUMRESNAMEPROCW)(       HMODULE hModule,      LPCWSTR lpType,
 LPWSTR lpName,      LONG_PTR lParam);





typedef BOOL ( * ENUMRESLANGPROCA)(       HMODULE hModule,      LPCSTR lpType,
 LPCSTR lpName,      WORD wLanguage,      LONG_PTR lParam);
typedef BOOL ( * ENUMRESLANGPROCW)(       HMODULE hModule,      LPCWSTR lpType,
 LPCWSTR lpName,      WORD wLanguage,      LONG_PTR lParam);
__declspec(dllimport)
BOOL

EnumResourceTypesA(
     HMODULE hModule,
     ENUMRESTYPEPROCA lpEnumFunc,
     LONG_PTR lParam
    );
__declspec(dllimport)
BOOL

EnumResourceTypesW(
     HMODULE hModule,
     ENUMRESTYPEPROCW lpEnumFunc,
     LONG_PTR lParam
    );






__declspec(dllimport)
BOOL

EnumResourceNamesA(
     HMODULE hModule,
     LPCSTR lpType,
     ENUMRESNAMEPROCA lpEnumFunc,
     LONG_PTR lParam
    );
__declspec(dllimport)
BOOL

EnumResourceNamesW(
     HMODULE hModule,
     LPCWSTR lpType,
     ENUMRESNAMEPROCW lpEnumFunc,
     LONG_PTR lParam
    );






__declspec(dllimport)
BOOL

EnumResourceLanguagesA(
     HMODULE hModule,
     LPCSTR lpType,
     LPCSTR lpName,
     ENUMRESLANGPROCA lpEnumFunc,
     LONG_PTR lParam
    );
__declspec(dllimport)
BOOL

EnumResourceLanguagesW(
     HMODULE hModule,
     LPCWSTR lpType,
     LPCWSTR lpName,
     ENUMRESLANGPROCW lpEnumFunc,
     LONG_PTR lParam
    );
__declspec(dllimport)
BOOL

EnumResourceTypesExA(
     HMODULE hModule,
     ENUMRESTYPEPROCA lpEnumFunc,
     LONG_PTR lParam,
    DWORD dwFlags,
    LANGID LangId
    );
__declspec(dllimport)
BOOL

EnumResourceTypesExW(
     HMODULE hModule,
     ENUMRESTYPEPROCW lpEnumFunc,
     LONG_PTR lParam,
    DWORD dwFlags,
    LANGID LangId
    );







__declspec(dllimport)
BOOL

EnumResourceNamesExA(
     HMODULE hModule,
     LPCSTR lpType,
     ENUMRESNAMEPROCA lpEnumFunc,
     LONG_PTR lParam,
    DWORD dwFlags,
    LANGID LangId
    );
__declspec(dllimport)
BOOL

EnumResourceNamesExW(
     HMODULE hModule,
     LPCWSTR lpType,
     ENUMRESNAMEPROCW lpEnumFunc,
     LONG_PTR lParam,
    DWORD dwFlags,
    LANGID LangId
    );






__declspec(dllimport)
BOOL

EnumResourceLanguagesExA(
     HMODULE hModule,
     LPCSTR lpType,
     LPCSTR lpName,
     ENUMRESLANGPROCA lpEnumFunc,
     LONG_PTR lParam,
    DWORD dwFlags,
    LANGID LangId
    );
__declspec(dllimport)
BOOL

EnumResourceLanguagesExW(
     HMODULE hModule,
     LPCWSTR lpType,
     LPCWSTR lpName,
     ENUMRESLANGPROCW lpEnumFunc,
     LONG_PTR lParam,
    DWORD dwFlags,
    LANGID LangId
    );






__declspec(dllimport)
HANDLE

BeginUpdateResourceA(
     LPCSTR pFileName,
     BOOL bDeleteExistingResources
    );
__declspec(dllimport)
HANDLE

BeginUpdateResourceW(
     LPCWSTR pFileName,
     BOOL bDeleteExistingResources
    );






__declspec(dllimport)
BOOL

UpdateResourceA(
     HANDLE hUpdate,
     LPCSTR lpType,
     LPCSTR lpName,
     WORD wLanguage,
     LPVOID lpData,
     DWORD cb
    );
__declspec(dllimport)
BOOL

UpdateResourceW(
     HANDLE hUpdate,
     LPCWSTR lpType,
     LPCWSTR lpName,
     WORD wLanguage,
     LPVOID lpData,
     DWORD cb
    );






__declspec(dllimport)
BOOL

EndUpdateResourceA(
     HANDLE hUpdate,
     BOOL fDiscard
    );
__declspec(dllimport)
BOOL

EndUpdateResourceW(
     HANDLE hUpdate,
     BOOL fDiscard
    );







__declspec(dllimport)
ATOM

GlobalAddAtomA(
     LPCSTR lpString
    );
__declspec(dllimport)
ATOM

GlobalAddAtomW(
     LPCWSTR lpString
    );






__declspec(dllimport)
ATOM

GlobalFindAtomA(
     LPCSTR lpString
    );
__declspec(dllimport)
ATOM

GlobalFindAtomW(
     LPCWSTR lpString
    );






__declspec(dllimport)
UINT

GlobalGetAtomNameA(
     ATOM nAtom,
     LPSTR lpBuffer,
     int nSize
    );
__declspec(dllimport)
UINT

GlobalGetAtomNameW(
     ATOM nAtom,
     LPWSTR lpBuffer,
     int nSize
    );






__declspec(dllimport)
ATOM

AddAtomA(
     LPCSTR lpString
    );
__declspec(dllimport)
ATOM

AddAtomW(
     LPCWSTR lpString
    );






__declspec(dllimport)
ATOM

FindAtomA(
     LPCSTR lpString
    );
__declspec(dllimport)
ATOM

FindAtomW(
     LPCWSTR lpString
    );






__declspec(dllimport)
UINT

GetAtomNameA(
     ATOM nAtom,
     LPSTR lpBuffer,
     int nSize
    );
__declspec(dllimport)
UINT

GetAtomNameW(
     ATOM nAtom,
     LPWSTR lpBuffer,
     int nSize
    );






__declspec(dllimport)
UINT

GetProfileIntA(
     LPCSTR lpAppName,
     LPCSTR lpKeyName,
     INT nDefault
    );
__declspec(dllimport)
UINT

GetProfileIntW(
     LPCWSTR lpAppName,
     LPCWSTR lpKeyName,
     INT nDefault
    );






__declspec(dllimport)
DWORD

GetProfileStringA(
     LPCSTR lpAppName,
     LPCSTR lpKeyName,
     LPCSTR lpDefault,
     LPSTR lpReturnedString,
     DWORD nSize
    );
__declspec(dllimport)
DWORD

GetProfileStringW(
     LPCWSTR lpAppName,
     LPCWSTR lpKeyName,
     LPCWSTR lpDefault,
     LPWSTR lpReturnedString,
     DWORD nSize
    );






__declspec(dllimport)
BOOL

WriteProfileStringA(
     LPCSTR lpAppName,
     LPCSTR lpKeyName,
     LPCSTR lpString
    );
__declspec(dllimport)
BOOL

WriteProfileStringW(
     LPCWSTR lpAppName,
     LPCWSTR lpKeyName,
     LPCWSTR lpString
    );






__declspec(dllimport)
DWORD

GetProfileSectionA(
     LPCSTR lpAppName,
     LPSTR lpReturnedString,
     DWORD nSize
    );
__declspec(dllimport)
DWORD

GetProfileSectionW(
     LPCWSTR lpAppName,
     LPWSTR lpReturnedString,
     DWORD nSize
    );






__declspec(dllimport)
BOOL

WriteProfileSectionA(
     LPCSTR lpAppName,
     LPCSTR lpString
    );
__declspec(dllimport)
BOOL

WriteProfileSectionW(
     LPCWSTR lpAppName,
     LPCWSTR lpString
    );






__declspec(dllimport)
UINT

GetPrivateProfileIntA(
     LPCSTR lpAppName,
     LPCSTR lpKeyName,
     INT nDefault,
     LPCSTR lpFileName
    );
__declspec(dllimport)
UINT

GetPrivateProfileIntW(
     LPCWSTR lpAppName,
     LPCWSTR lpKeyName,
     INT nDefault,
     LPCWSTR lpFileName
    );






__declspec(dllimport)
DWORD

GetPrivateProfileStringA(
     LPCSTR lpAppName,
     LPCSTR lpKeyName,
     LPCSTR lpDefault,
     LPSTR lpReturnedString,
     DWORD nSize,
     LPCSTR lpFileName
    );
__declspec(dllimport)
DWORD

GetPrivateProfileStringW(
     LPCWSTR lpAppName,
     LPCWSTR lpKeyName,
     LPCWSTR lpDefault,
     LPWSTR lpReturnedString,
     DWORD nSize,
     LPCWSTR lpFileName
    );






__declspec(dllimport)
BOOL

WritePrivateProfileStringA(
     LPCSTR lpAppName,
     LPCSTR lpKeyName,
     LPCSTR lpString,
     LPCSTR lpFileName
    );
__declspec(dllimport)
BOOL

WritePrivateProfileStringW(
     LPCWSTR lpAppName,
     LPCWSTR lpKeyName,
     LPCWSTR lpString,
     LPCWSTR lpFileName
    );






__declspec(dllimport)
DWORD

GetPrivateProfileSectionA(
     LPCSTR lpAppName,
     LPSTR lpReturnedString,
     DWORD nSize,
     LPCSTR lpFileName
    );
__declspec(dllimport)
DWORD

GetPrivateProfileSectionW(
     LPCWSTR lpAppName,
     LPWSTR lpReturnedString,
     DWORD nSize,
     LPCWSTR lpFileName
    );






__declspec(dllimport)
BOOL

WritePrivateProfileSectionA(
     LPCSTR lpAppName,
     LPCSTR lpString,
     LPCSTR lpFileName
    );
__declspec(dllimport)
BOOL

WritePrivateProfileSectionW(
     LPCWSTR lpAppName,
     LPCWSTR lpString,
     LPCWSTR lpFileName
    );







__declspec(dllimport)
DWORD

GetPrivateProfileSectionNamesA(
     LPSTR lpszReturnBuffer,
     DWORD nSize,
     LPCSTR lpFileName
    );
__declspec(dllimport)
DWORD

GetPrivateProfileSectionNamesW(
     LPWSTR lpszReturnBuffer,
     DWORD nSize,
     LPCWSTR lpFileName
    );






__declspec(dllimport)
BOOL

GetPrivateProfileStructA(
     LPCSTR lpszSection,
     LPCSTR lpszKey,
     LPVOID lpStruct,
     UINT uSizeStruct,
     LPCSTR szFile
    );
__declspec(dllimport)
BOOL

GetPrivateProfileStructW(
     LPCWSTR lpszSection,
     LPCWSTR lpszKey,
     LPVOID lpStruct,
     UINT uSizeStruct,
     LPCWSTR szFile
    );






__declspec(dllimport)
BOOL

WritePrivateProfileStructA(
     LPCSTR lpszSection,
     LPCSTR lpszKey,
     LPVOID lpStruct,
     UINT uSizeStruct,
     LPCSTR szFile
    );
__declspec(dllimport)
BOOL

WritePrivateProfileStructW(
     LPCWSTR lpszSection,
     LPCWSTR lpszKey,
     LPVOID lpStruct,
     UINT uSizeStruct,
     LPCWSTR szFile
    );







__declspec(dllimport)
UINT

GetDriveTypeA(
     LPCSTR lpRootPathName
    );
__declspec(dllimport)
UINT

GetDriveTypeW(
     LPCWSTR lpRootPathName
    );






__declspec(dllimport)
UINT

GetSystemDirectoryA(
     LPSTR lpBuffer,
     UINT uSize
    );
__declspec(dllimport)
UINT

GetSystemDirectoryW(
     LPWSTR lpBuffer,
     UINT uSize
    );






__declspec(dllimport)
DWORD

GetTempPathA(
     DWORD nBufferLength,
     LPSTR lpBuffer
    );
__declspec(dllimport)
DWORD

GetTempPathW(
     DWORD nBufferLength,
     LPWSTR lpBuffer
    );






__declspec(dllimport)
UINT

GetTempFileNameA(
     LPCSTR lpPathName,
     LPCSTR lpPrefixString,
     UINT uUnique,
     LPSTR lpTempFileName
    );
__declspec(dllimport)
UINT

GetTempFileNameW(
     LPCWSTR lpPathName,
     LPCWSTR lpPrefixString,
     UINT uUnique,
     LPWSTR lpTempFileName
    );
__declspec(dllimport)
UINT

GetWindowsDirectoryA(
     LPSTR lpBuffer,
     UINT uSize
    );
__declspec(dllimport)
UINT

GetWindowsDirectoryW(
     LPWSTR lpBuffer,
     UINT uSize
    );






__declspec(dllimport)
UINT

GetSystemWindowsDirectoryA(
     LPSTR lpBuffer,
     UINT uSize
    );
__declspec(dllimport)
UINT

GetSystemWindowsDirectoryW(
     LPWSTR lpBuffer,
     UINT uSize
    );









__declspec(dllimport)
UINT

GetSystemWow64DirectoryA(
     LPSTR lpBuffer,
     UINT uSize
    );
__declspec(dllimport)
UINT

GetSystemWow64DirectoryW(
     LPWSTR lpBuffer,
     UINT uSize
    );






__declspec(dllimport)
BOOLEAN

Wow64EnableWow64FsRedirection (
     BOOLEAN Wow64FsEnableRedirection
    );

__declspec(dllimport)
BOOL

Wow64DisableWow64FsRedirection (
     PVOID *OldValue
    );

__declspec(dllimport)
BOOL

Wow64RevertWow64FsRedirection (
     PVOID OlValue
    );





typedef UINT ( * PGET_SYSTEM_WOW64_DIRECTORY_A)(         LPSTR lpBuffer,      UINT uSize);
typedef UINT ( * PGET_SYSTEM_WOW64_DIRECTORY_W)(         LPWSTR lpBuffer,      UINT uSize);
__declspec(dllimport)
BOOL

SetCurrentDirectoryA(
     LPCSTR lpPathName
    );
__declspec(dllimport)
BOOL

SetCurrentDirectoryW(
     LPCWSTR lpPathName
    );
__declspec(dllimport)
DWORD

GetCurrentDirectoryA(
     DWORD nBufferLength,
     LPSTR lpBuffer
    );
__declspec(dllimport)
DWORD

GetCurrentDirectoryW(
     DWORD nBufferLength,
     LPWSTR lpBuffer
    );








__declspec(dllimport)
BOOL

SetDllDirectoryA(
     LPCSTR lpPathName
    );
__declspec(dllimport)
BOOL

SetDllDirectoryW(
     LPCWSTR lpPathName
    );






__declspec(dllimport)
DWORD

GetDllDirectoryA(
     DWORD nBufferLength,
     LPSTR lpBuffer
    );
__declspec(dllimport)
DWORD

GetDllDirectoryW(
     DWORD nBufferLength,
     LPWSTR lpBuffer
    );








__declspec(dllimport)
BOOL

GetDiskFreeSpaceA(
     LPCSTR lpRootPathName,
     LPDWORD lpSectorsPerCluster,
     LPDWORD lpBytesPerSector,
     LPDWORD lpNumberOfFreeClusters,
     LPDWORD lpTotalNumberOfClusters
    );
__declspec(dllimport)
BOOL

GetDiskFreeSpaceW(
     LPCWSTR lpRootPathName,
     LPDWORD lpSectorsPerCluster,
     LPDWORD lpBytesPerSector,
     LPDWORD lpNumberOfFreeClusters,
     LPDWORD lpTotalNumberOfClusters
    );






__declspec(dllimport)
BOOL

GetDiskFreeSpaceExA(
     LPCSTR lpDirectoryName,
     PULARGE_INTEGER lpFreeBytesAvailableToCaller,
     PULARGE_INTEGER lpTotalNumberOfBytes,
     PULARGE_INTEGER lpTotalNumberOfFreeBytes
    );
__declspec(dllimport)
BOOL

GetDiskFreeSpaceExW(
     LPCWSTR lpDirectoryName,
     PULARGE_INTEGER lpFreeBytesAvailableToCaller,
     PULARGE_INTEGER lpTotalNumberOfBytes,
     PULARGE_INTEGER lpTotalNumberOfFreeBytes
    );






__declspec(dllimport)
BOOL

CreateDirectoryA(
     LPCSTR lpPathName,
     LPSECURITY_ATTRIBUTES lpSecurityAttributes
    );
__declspec(dllimport)
BOOL

CreateDirectoryW(
     LPCWSTR lpPathName,
     LPSECURITY_ATTRIBUTES lpSecurityAttributes
    );
__declspec(dllimport)
BOOL

CreateDirectoryExA(
     LPCSTR lpTemplateDirectory,
     LPCSTR lpNewDirectory,
     LPSECURITY_ATTRIBUTES lpSecurityAttributes
    );
__declspec(dllimport)
BOOL

CreateDirectoryExW(
     LPCWSTR lpTemplateDirectory,
     LPCWSTR lpNewDirectory,
     LPSECURITY_ATTRIBUTES lpSecurityAttributes
    );








__declspec(dllimport)
BOOL

CreateDirectoryTransactedA(
     LPCSTR lpTemplateDirectory,
     LPCSTR lpNewDirectory,
     LPSECURITY_ATTRIBUTES lpSecurityAttributes,
     HANDLE hTransaction
    );
__declspec(dllimport)
BOOL

CreateDirectoryTransactedW(
     LPCWSTR lpTemplateDirectory,
     LPCWSTR lpNewDirectory,
     LPSECURITY_ATTRIBUTES lpSecurityAttributes,
     HANDLE hTransaction
    );








__declspec(dllimport)
BOOL

RemoveDirectoryA(
     LPCSTR lpPathName
    );
__declspec(dllimport)
BOOL

RemoveDirectoryW(
     LPCWSTR lpPathName
    );








__declspec(dllimport)
BOOL

RemoveDirectoryTransactedA(
     LPCSTR lpPathName,
     HANDLE hTransaction
    );
__declspec(dllimport)
BOOL

RemoveDirectoryTransactedW(
     LPCWSTR lpPathName,
     HANDLE hTransaction
    );








__declspec(dllimport)
DWORD

GetFullPathNameA(
     LPCSTR lpFileName,
     DWORD nBufferLength,
     LPSTR lpBuffer,
     LPSTR *lpFilePart
    );
__declspec(dllimport)
DWORD

GetFullPathNameW(
     LPCWSTR lpFileName,
     DWORD nBufferLength,
     LPWSTR lpBuffer,
     LPWSTR *lpFilePart
    );







__declspec(dllimport)
DWORD

GetFullPathNameTransactedA(
     LPCSTR lpFileName,
     DWORD nBufferLength,
     LPSTR lpBuffer,
     LPSTR *lpFilePart,
     HANDLE hTransaction
    );
__declspec(dllimport)
DWORD

GetFullPathNameTransactedW(
     LPCWSTR lpFileName,
     DWORD nBufferLength,
     LPWSTR lpBuffer,
     LPWSTR *lpFilePart,
     HANDLE hTransaction
    );
__declspec(dllimport)
BOOL

DefineDosDeviceA(
     DWORD dwFlags,
     LPCSTR lpDeviceName,
     LPCSTR lpTargetPath
    );
__declspec(dllimport)
BOOL

DefineDosDeviceW(
     DWORD dwFlags,
     LPCWSTR lpDeviceName,
     LPCWSTR lpTargetPath
    );






__declspec(dllimport)
DWORD

QueryDosDeviceA(
     LPCSTR lpDeviceName,
     LPSTR lpTargetPath,
     DWORD ucchMax
    );
__declspec(dllimport)
DWORD

QueryDosDeviceW(
     LPCWSTR lpDeviceName,
     LPWSTR lpTargetPath,
     DWORD ucchMax
    );








__declspec(dllimport)

HANDLE

CreateFileA(
     LPCSTR lpFileName,
     DWORD dwDesiredAccess,
     DWORD dwShareMode,
     LPSECURITY_ATTRIBUTES lpSecurityAttributes,
     DWORD dwCreationDisposition,
     DWORD dwFlagsAndAttributes,
     HANDLE hTemplateFile
    );
__declspec(dllimport)

HANDLE

CreateFileW(
     LPCWSTR lpFileName,
     DWORD dwDesiredAccess,
     DWORD dwShareMode,
     LPSECURITY_ATTRIBUTES lpSecurityAttributes,
     DWORD dwCreationDisposition,
     DWORD dwFlagsAndAttributes,
     HANDLE hTemplateFile
    );








__declspec(dllimport)

HANDLE

CreateFileTransactedA(
     LPCSTR lpFileName,
     DWORD dwDesiredAccess,
     DWORD dwShareMode,
     LPSECURITY_ATTRIBUTES lpSecurityAttributes,
     DWORD dwCreationDisposition,
     DWORD dwFlagsAndAttributes,
     HANDLE hTemplateFile,
     HANDLE hTransaction,
     PUSHORT pusMiniVersion,
     PVOID lpExtendedParameter
    );
__declspec(dllimport)

HANDLE

CreateFileTransactedW(
     LPCWSTR lpFileName,
     DWORD dwDesiredAccess,
     DWORD dwShareMode,
     LPSECURITY_ATTRIBUTES lpSecurityAttributes,
     DWORD dwCreationDisposition,
     DWORD dwFlagsAndAttributes,
     HANDLE hTemplateFile,
     HANDLE hTransaction,
     PUSHORT pusMiniVersion,
     PVOID lpExtendedParameter
    );
__declspec(dllimport)

HANDLE

ReOpenFile(
     HANDLE hOriginalFile,
     DWORD dwDesiredAccess,
     DWORD dwShareMode,
     DWORD dwFlagsAndAttributes
    );



__declspec(dllimport)
BOOL

SetFileAttributesA(
     LPCSTR lpFileName,
     DWORD dwFileAttributes
    );
__declspec(dllimport)
BOOL

SetFileAttributesW(
     LPCWSTR lpFileName,
     DWORD dwFileAttributes
    );






__declspec(dllimport)
DWORD

GetFileAttributesA(
     LPCSTR lpFileName
    );
__declspec(dllimport)
DWORD

GetFileAttributesW(
     LPCWSTR lpFileName
    );








__declspec(dllimport)
BOOL

SetFileAttributesTransactedA(
     LPCSTR lpFileName,
     DWORD dwFileAttributes,
     HANDLE hTransaction
    );
__declspec(dllimport)
BOOL

SetFileAttributesTransactedW(
     LPCWSTR lpFileName,
     DWORD dwFileAttributes,
     HANDLE hTransaction
    );








typedef enum _GET_FILEEX_INFO_LEVELS {
    GetFileExInfoStandard,
    GetFileExMaxInfoLevel
} GET_FILEEX_INFO_LEVELS;



__declspec(dllimport)
BOOL

GetFileAttributesTransactedA(
     LPCSTR lpFileName,
     GET_FILEEX_INFO_LEVELS fInfoLevelId,
     LPVOID lpFileInformation,
     HANDLE hTransaction
    );
__declspec(dllimport)
BOOL

GetFileAttributesTransactedW(
     LPCWSTR lpFileName,
     GET_FILEEX_INFO_LEVELS fInfoLevelId,
     LPVOID lpFileInformation,
     HANDLE hTransaction
    );








__declspec(dllimport)
BOOL

GetFileAttributesExA(
     LPCSTR lpFileName,
     GET_FILEEX_INFO_LEVELS fInfoLevelId,
     LPVOID lpFileInformation
    );
__declspec(dllimport)
BOOL

GetFileAttributesExW(
     LPCWSTR lpFileName,
     GET_FILEEX_INFO_LEVELS fInfoLevelId,
     LPVOID lpFileInformation
    );






__declspec(dllimport)
DWORD

GetCompressedFileSizeA(
     LPCSTR lpFileName,
     LPDWORD lpFileSizeHigh
    );
__declspec(dllimport)
DWORD

GetCompressedFileSizeW(
     LPCWSTR lpFileName,
     LPDWORD lpFileSizeHigh
    );








__declspec(dllimport)
DWORD

GetCompressedFileSizeTransactedA(
     LPCSTR lpFileName,
     LPDWORD lpFileSizeHigh,
     HANDLE hTransaction
    );
__declspec(dllimport)
DWORD

GetCompressedFileSizeTransactedW(
     LPCWSTR lpFileName,
     LPDWORD lpFileSizeHigh,
     HANDLE hTransaction
    );








__declspec(dllimport)
BOOL

DeleteFileA(
     LPCSTR lpFileName
    );
__declspec(dllimport)
BOOL

DeleteFileW(
     LPCWSTR lpFileName
    );








__declspec(dllimport)
BOOL

DeleteFileTransactedA(
     LPCSTR lpFileName,
     HANDLE hTransaction
    );
__declspec(dllimport)
BOOL

DeleteFileTransactedW(
     LPCWSTR lpFileName,
     HANDLE hTransaction
    );
__declspec(dllimport)
BOOL

CheckNameLegalDOS8Dot3A(
     LPCSTR lpName,
     LPSTR lpOemName,
     DWORD OemNameSize,
     PBOOL pbNameContainsSpaces  ,
     PBOOL pbNameLegal
    );
__declspec(dllimport)
BOOL

CheckNameLegalDOS8Dot3W(
     LPCWSTR lpName,
     LPSTR lpOemName,
     DWORD OemNameSize,
     PBOOL pbNameContainsSpaces  ,
     PBOOL pbNameLegal
    );









typedef enum _FINDEX_INFO_LEVELS {
    FindExInfoStandard,
    FindExInfoMaxInfoLevel
} FINDEX_INFO_LEVELS;

typedef enum _FINDEX_SEARCH_OPS {
    FindExSearchNameMatch,
    FindExSearchLimitToDirectories,
    FindExSearchLimitToDevices,
    FindExSearchMaxSearchOp
} FINDEX_SEARCH_OPS;



__declspec(dllimport)

HANDLE

FindFirstFileExA(
     LPCSTR lpFileName,
     FINDEX_INFO_LEVELS fInfoLevelId,
     LPVOID lpFindFileData,
     FINDEX_SEARCH_OPS fSearchOp,
     LPVOID lpSearchFilter,
     DWORD dwAdditionalFlags
    );
__declspec(dllimport)

HANDLE

FindFirstFileExW(
     LPCWSTR lpFileName,
     FINDEX_INFO_LEVELS fInfoLevelId,
     LPVOID lpFindFileData,
     FINDEX_SEARCH_OPS fSearchOp,
     LPVOID lpSearchFilter,
     DWORD dwAdditionalFlags
    );








__declspec(dllimport)

HANDLE

FindFirstFileTransactedA(
     LPCSTR lpFileName,
     FINDEX_INFO_LEVELS fInfoLevelId,
     LPVOID lpFindFileData,
     FINDEX_SEARCH_OPS fSearchOp,
     LPVOID lpSearchFilter,
     DWORD dwAdditionalFlags,
     HANDLE hTransaction
    );
__declspec(dllimport)

HANDLE

FindFirstFileTransactedW(
     LPCWSTR lpFileName,
     FINDEX_INFO_LEVELS fInfoLevelId,
     LPVOID lpFindFileData,
     FINDEX_SEARCH_OPS fSearchOp,
     LPVOID lpSearchFilter,
     DWORD dwAdditionalFlags,
     HANDLE hTransaction
    );










__declspec(dllimport)

HANDLE

FindFirstFileA(
     LPCSTR lpFileName,
     LPWIN32_FIND_DATAA lpFindFileData
    );
__declspec(dllimport)

HANDLE

FindFirstFileW(
     LPCWSTR lpFileName,
     LPWIN32_FIND_DATAW lpFindFileData
    );






__declspec(dllimport)
BOOL

FindNextFileA(
     HANDLE hFindFile,
     LPWIN32_FIND_DATAA lpFindFileData
    );
__declspec(dllimport)
BOOL

FindNextFileW(
     HANDLE hFindFile,
     LPWIN32_FIND_DATAW lpFindFileData
    );







__declspec(dllimport)
DWORD

SearchPathA(
     LPCSTR lpPath,
     LPCSTR lpFileName,
     LPCSTR lpExtension,
     DWORD nBufferLength,
     LPSTR lpBuffer,
     LPSTR *lpFilePart
    );
__declspec(dllimport)
DWORD

SearchPathW(
     LPCWSTR lpPath,
     LPCWSTR lpFileName,
     LPCWSTR lpExtension,
     DWORD nBufferLength,
     LPWSTR lpBuffer,
     LPWSTR *lpFilePart
    );






__declspec(dllimport)
BOOL

CopyFileA(
     LPCSTR lpExistingFileName,
     LPCSTR lpNewFileName,
     BOOL bFailIfExists
    );
__declspec(dllimport)
BOOL

CopyFileW(
     LPCWSTR lpExistingFileName,
     LPCWSTR lpNewFileName,
     BOOL bFailIfExists
    );
typedef
DWORD
(  *LPPROGRESS_ROUTINE)(
     LARGE_INTEGER TotalFileSize,
     LARGE_INTEGER TotalBytesTransferred,
     LARGE_INTEGER StreamSize,
     LARGE_INTEGER StreamBytesTransferred,
     DWORD dwStreamNumber,
     DWORD dwCallbackReason,
     HANDLE hSourceFile,
     HANDLE hDestinationFile,
     LPVOID lpData
    );

__declspec(dllimport)
BOOL

CopyFileExA(
     LPCSTR lpExistingFileName,
     LPCSTR lpNewFileName,
     LPPROGRESS_ROUTINE lpProgressRoutine,
     LPVOID lpData,
     LPBOOL pbCancel,
     DWORD dwCopyFlags
    );
__declspec(dllimport)
BOOL

CopyFileExW(
     LPCWSTR lpExistingFileName,
     LPCWSTR lpNewFileName,
     LPPROGRESS_ROUTINE lpProgressRoutine,
     LPVOID lpData,
     LPBOOL pbCancel,
     DWORD dwCopyFlags
    );








__declspec(dllimport)
BOOL

CopyFileTransactedA(
     LPCSTR lpExistingFileName,
     LPCSTR lpNewFileName,
     LPPROGRESS_ROUTINE lpProgressRoutine,
     LPVOID lpData,
     LPBOOL pbCancel,
     DWORD dwCopyFlags,
     HANDLE hTransaction
    );
__declspec(dllimport)
BOOL

CopyFileTransactedW(
     LPCWSTR lpExistingFileName,
     LPCWSTR lpNewFileName,
     LPPROGRESS_ROUTINE lpProgressRoutine,
     LPVOID lpData,
     LPBOOL pbCancel,
     DWORD dwCopyFlags,
     HANDLE hTransaction
    );









__declspec(dllimport)
BOOL

MoveFileA(
     LPCSTR lpExistingFileName,
     LPCSTR lpNewFileName
    );
__declspec(dllimport)
BOOL

MoveFileW(
     LPCWSTR lpExistingFileName,
     LPCWSTR lpNewFileName
    );
__declspec(dllimport)
BOOL

MoveFileExA(
     LPCSTR lpExistingFileName,
     LPCSTR lpNewFileName,
     DWORD dwFlags
    );
__declspec(dllimport)
BOOL

MoveFileExW(
     LPCWSTR lpExistingFileName,
     LPCWSTR lpNewFileName,
     DWORD dwFlags
    );







__declspec(dllimport)
BOOL

MoveFileWithProgressA(
     LPCSTR lpExistingFileName,
     LPCSTR lpNewFileName,
     LPPROGRESS_ROUTINE lpProgressRoutine,
     LPVOID lpData,
     DWORD dwFlags
    );
__declspec(dllimport)
BOOL

MoveFileWithProgressW(
     LPCWSTR lpExistingFileName,
     LPCWSTR lpNewFileName,
     LPPROGRESS_ROUTINE lpProgressRoutine,
     LPVOID lpData,
     DWORD dwFlags
    );








__declspec(dllimport)
BOOL

MoveFileTransactedA(
     LPCSTR lpExistingFileName,
     LPCSTR lpNewFileName,
     LPPROGRESS_ROUTINE lpProgressRoutine,
     LPVOID lpData,
     DWORD dwFlags,
     HANDLE hTransaction
    );
__declspec(dllimport)
BOOL

MoveFileTransactedW(
     LPCWSTR lpExistingFileName,
     LPCWSTR lpNewFileName,
     LPPROGRESS_ROUTINE lpProgressRoutine,
     LPVOID lpData,
     DWORD dwFlags,
     HANDLE hTransaction
    );
__declspec(dllimport)
BOOL

ReplaceFileA(
     LPCSTR lpReplacedFileName,
     LPCSTR lpReplacementFileName,
     LPCSTR lpBackupFileName,
     DWORD dwReplaceFlags,
     LPVOID lpExclude,
     LPVOID lpReserved
    );
__declspec(dllimport)
BOOL

ReplaceFileW(
     LPCWSTR lpReplacedFileName,
     LPCWSTR lpReplacementFileName,
     LPCWSTR lpBackupFileName,
     DWORD dwReplaceFlags,
     LPVOID lpExclude,
     LPVOID lpReserved
    );
__declspec(dllimport)
BOOL

CreateHardLinkA(
     LPCSTR lpFileName,
     LPCSTR lpExistingFileName,
     LPSECURITY_ATTRIBUTES lpSecurityAttributes
    );
__declspec(dllimport)
BOOL

CreateHardLinkW(
     LPCWSTR lpFileName,
     LPCWSTR lpExistingFileName,
     LPSECURITY_ATTRIBUTES lpSecurityAttributes
    );
__declspec(dllimport)
BOOL

CreateHardLinkTransactedA(
     LPCSTR lpFileName,
     LPCSTR lpExistingFileName,
     LPSECURITY_ATTRIBUTES lpSecurityAttributes,
     HANDLE hTransaction
    );
__declspec(dllimport)
BOOL

CreateHardLinkTransactedW(
     LPCWSTR lpFileName,
     LPCWSTR lpExistingFileName,
     LPSECURITY_ATTRIBUTES lpSecurityAttributes,
     HANDLE hTransaction
    );
typedef enum _STREAM_INFO_LEVELS {

    FindStreamInfoStandard,
    FindStreamInfoMaxInfoLevel

} STREAM_INFO_LEVELS;

typedef struct _WIN32_FIND_STREAM_DATA {

    LARGE_INTEGER StreamSize;
    WCHAR cStreamName[  260  + 36 ];

} WIN32_FIND_STREAM_DATA, *PWIN32_FIND_STREAM_DATA;


HANDLE

FindFirstStreamW(
     LPCWSTR lpFileName,
     STREAM_INFO_LEVELS InfoLevel,
     LPVOID lpFindStreamData,
     DWORD dwFlags
    );


HANDLE

FindFirstStreamTransactedW (
     LPCWSTR lpFileName,
     STREAM_INFO_LEVELS InfoLevel,
     LPVOID lpFindStreamData,
     DWORD dwFlags,
     HANDLE hTransaction
    );


BOOL

FindNextStreamW(
     HANDLE hFindStream,
     LPVOID lpFindStreamData
    );




HANDLE

FindFirstFileNameW (
     LPCWSTR lpFileName,
     DWORD dwFlags,
     LPDWORD StringLength,
     PWCHAR LinkName
    );

BOOL

FindNextFileNameW (
     HANDLE hFindStream,
     LPDWORD StringLength,
     PWCHAR LinkName
    );

HANDLE

FindFirstFileNameTransactedW (
     LPCWSTR lpFileName,
     DWORD dwFlags,
     LPDWORD StringLength,
     PWCHAR LinkName,
     HANDLE hTransaction
    );




__declspec(dllimport)

HANDLE

CreateNamedPipeA(
     LPCSTR lpName,
     DWORD dwOpenMode,
     DWORD dwPipeMode,
     DWORD nMaxInstances,
     DWORD nOutBufferSize,
     DWORD nInBufferSize,
     DWORD nDefaultTimeOut,
     LPSECURITY_ATTRIBUTES lpSecurityAttributes
    );
__declspec(dllimport)

HANDLE

CreateNamedPipeW(
     LPCWSTR lpName,
     DWORD dwOpenMode,
     DWORD dwPipeMode,
     DWORD nMaxInstances,
     DWORD nOutBufferSize,
     DWORD nInBufferSize,
     DWORD nDefaultTimeOut,
     LPSECURITY_ATTRIBUTES lpSecurityAttributes
    );






__declspec(dllimport)
BOOL

GetNamedPipeHandleStateA(
     HANDLE hNamedPipe,
     LPDWORD lpState,
     LPDWORD lpCurInstances,
     LPDWORD lpMaxCollectionCount,
     LPDWORD lpCollectDataTimeout,
     LPSTR lpUserName,
     DWORD nMaxUserNameSize
    );
__declspec(dllimport)
BOOL

GetNamedPipeHandleStateW(
     HANDLE hNamedPipe,
     LPDWORD lpState,
     LPDWORD lpCurInstances,
     LPDWORD lpMaxCollectionCount,
     LPDWORD lpCollectDataTimeout,
     LPWSTR lpUserName,
     DWORD nMaxUserNameSize
    );






__declspec(dllimport)
BOOL

CallNamedPipeA(
     LPCSTR lpNamedPipeName,
     LPVOID lpInBuffer,
     DWORD nInBufferSize,
     LPVOID lpOutBuffer,
     DWORD nOutBufferSize,
     LPDWORD lpBytesRead,
     DWORD nTimeOut
    );
__declspec(dllimport)
BOOL

CallNamedPipeW(
     LPCWSTR lpNamedPipeName,
     LPVOID lpInBuffer,
     DWORD nInBufferSize,
     LPVOID lpOutBuffer,
     DWORD nOutBufferSize,
     LPDWORD lpBytesRead,
     DWORD nTimeOut
    );






__declspec(dllimport)
BOOL

WaitNamedPipeA(
     LPCSTR lpNamedPipeName,
     DWORD nTimeOut
    );
__declspec(dllimport)
BOOL

WaitNamedPipeW(
     LPCWSTR lpNamedPipeName,
     DWORD nTimeOut
    );






typedef enum {
    PipeAttribute,
    PipeConnectionAttribute,
    PipeHandleAttribute
} PIPE_ATTRIBUTE_TYPE;

__declspec(dllimport)
BOOL

GetNamedPipeAttribute(
     HANDLE Pipe,
     PIPE_ATTRIBUTE_TYPE AttributeType,
     PSTR AttributeName,
     PVOID AttributeValue,
     PSIZE_T AttributeValueLength
    );

__declspec(dllimport)
BOOL

SetNamedPipeAttribute(
     HANDLE Pipe,
     PIPE_ATTRIBUTE_TYPE AttributeType,
     PSTR AttributeName,
     PVOID AttributeValue,
     SIZE_T AttributeValueLength
    );

__declspec(dllimport)
BOOL

GetNamedPipeClientComputerNameA(
     HANDLE Pipe,
     LPSTR ClientComputerName,
     ULONG ClientComputerNameLength
    );
__declspec(dllimport)
BOOL

GetNamedPipeClientComputerNameW(
     HANDLE Pipe,
     LPWSTR ClientComputerName,
     ULONG ClientComputerNameLength
    );






__declspec(dllimport)
BOOL

GetNamedPipeClientProcessId(
     HANDLE Pipe,
     PULONG ClientProcessId
    );

__declspec(dllimport)
BOOL

GetNamedPipeClientSessionId(
     HANDLE Pipe,
     PULONG ClientSessionId
    );

__declspec(dllimport)
BOOL

GetNamedPipeServerProcessId(
     HANDLE Pipe,
     PULONG ServerProcessId
    );

__declspec(dllimport)
BOOL

GetNamedPipeServerSessionId(
     HANDLE Pipe,
     PULONG ServerSessionId
    );

__declspec(dllimport)
BOOL

SetVolumeLabelA(
     LPCSTR lpRootPathName,
     LPCSTR lpVolumeName
    );
__declspec(dllimport)
BOOL

SetVolumeLabelW(
     LPCWSTR lpRootPathName,
     LPCWSTR lpVolumeName
    );






__declspec(dllimport)
void

SetFileApisToOEM(  void  );

__declspec(dllimport)
void

SetFileApisToANSI(  void  );

__declspec(dllimport)
BOOL

AreFileApisANSI(  void  );

__declspec(dllimport)
BOOL

GetVolumeInformationA(
     LPCSTR lpRootPathName,
     LPSTR lpVolumeNameBuffer,
     DWORD nVolumeNameSize,
     LPDWORD lpVolumeSerialNumber,
     LPDWORD lpMaximumComponentLength,
     LPDWORD lpFileSystemFlags,
     LPSTR lpFileSystemNameBuffer,
     DWORD nFileSystemNameSize
    );
__declspec(dllimport)
BOOL

GetVolumeInformationW(
     LPCWSTR lpRootPathName,
     LPWSTR lpVolumeNameBuffer,
     DWORD nVolumeNameSize,
     LPDWORD lpVolumeSerialNumber,
     LPDWORD lpMaximumComponentLength,
     LPDWORD lpFileSystemFlags,
     LPWSTR lpFileSystemNameBuffer,
     DWORD nFileSystemNameSize
    );







__declspec(dllimport)
BOOL

GetVolumeInformationByHandleW(
     HANDLE hFile,
     LPWSTR lpVolumeNameBuffer,
     DWORD nVolumeNameSize,
     LPDWORD lpVolumeSerialNumber,
     LPDWORD lpMaximumComponentLength,
     LPDWORD lpFileSystemFlags,
     LPWSTR lpFileSystemNameBuffer,
     DWORD nFileSystemNameSize
    );


__declspec(dllimport)
BOOL

CancelSynchronousIo(
     HANDLE hThread
    );

__declspec(dllimport)
BOOL

CancelIoEx(
     HANDLE hFile,
     LPOVERLAPPED lpOverlapped
    );

__declspec(dllimport)
BOOL

CancelIo(
     HANDLE hFile
    );

__declspec(dllimport)
BOOL

SetFileBandwidthReservation(
     HANDLE hFile,
     DWORD nPeriodMilliseconds,
     DWORD nBytesPerPeriod,
     BOOL bDiscardable,
     LPDWORD lpTransferSize,
     LPDWORD lpNumOutstandingRequests
    );

__declspec(dllimport)
BOOL

GetFileBandwidthReservation(
     HANDLE hFile,
     LPDWORD lpPeriodMilliseconds,
     LPDWORD lpBytesPerPeriod,
     LPBOOL pDiscardable,
     LPDWORD lpTransferSize,
     LPDWORD lpNumOutstandingRequests
    );





__declspec(dllimport)
BOOL

ClearEventLogA (
     HANDLE hEventLog,
     LPCSTR lpBackupFileName
    );
__declspec(dllimport)
BOOL

ClearEventLogW (
     HANDLE hEventLog,
     LPCWSTR lpBackupFileName
    );






__declspec(dllimport)
BOOL

BackupEventLogA (
     HANDLE hEventLog,
     LPCSTR lpBackupFileName
    );
__declspec(dllimport)
BOOL

BackupEventLogW (
     HANDLE hEventLog,
     LPCWSTR lpBackupFileName
    );






__declspec(dllimport)
BOOL

CloseEventLog (
     HANDLE hEventLog
    );

__declspec(dllimport)
BOOL

DeregisterEventSource (
     HANDLE hEventLog
    );

__declspec(dllimport)
BOOL

NotifyChangeEventLog(
     HANDLE hEventLog,
     HANDLE hEvent
    );

__declspec(dllimport)
BOOL

GetNumberOfEventLogRecords (
     HANDLE hEventLog,
     PDWORD NumberOfRecords
    );

__declspec(dllimport)
BOOL

GetOldestEventLogRecord (
     HANDLE hEventLog,
     PDWORD OldestRecord
    );

__declspec(dllimport)

HANDLE

OpenEventLogA (
     LPCSTR lpUNCServerName,
     LPCSTR lpSourceName
    );
__declspec(dllimport)

HANDLE

OpenEventLogW (
     LPCWSTR lpUNCServerName,
     LPCWSTR lpSourceName
    );






__declspec(dllimport)

HANDLE

RegisterEventSourceA (
     LPCSTR lpUNCServerName,
     LPCSTR lpSourceName
    );
__declspec(dllimport)

HANDLE

RegisterEventSourceW (
     LPCWSTR lpUNCServerName,
     LPCWSTR lpSourceName
    );






__declspec(dllimport)

HANDLE

OpenBackupEventLogA (
     LPCSTR lpUNCServerName,
     LPCSTR lpFileName
    );
__declspec(dllimport)

HANDLE

OpenBackupEventLogW (
     LPCWSTR lpUNCServerName,
     LPCWSTR lpFileName
    );






__declspec(dllimport)
BOOL

ReadEventLogA (
     HANDLE hEventLog,
     DWORD dwReadFlags,
     DWORD dwRecordOffset,
     LPVOID lpBuffer,
     DWORD nNumberOfBytesToRead,
     DWORD *pnBytesRead,
     DWORD *pnMinNumberOfBytesNeeded
    );
__declspec(dllimport)
BOOL

ReadEventLogW (
     HANDLE hEventLog,
     DWORD dwReadFlags,
     DWORD dwRecordOffset,
     LPVOID lpBuffer,
     DWORD nNumberOfBytesToRead,
     DWORD *pnBytesRead,
     DWORD *pnMinNumberOfBytesNeeded
    );






__declspec(dllimport)
BOOL

ReportEventA (
     HANDLE hEventLog,
     WORD wType,
     WORD wCategory,
     DWORD dwEventID,
     PSID lpUserSid,
     WORD wNumStrings,
     DWORD dwDataSize,
     LPCSTR *lpStrings,
     LPVOID lpRawData
    );
__declspec(dllimport)
BOOL

ReportEventW (
     HANDLE hEventLog,
     WORD wType,
     WORD wCategory,
     DWORD dwEventID,
     PSID lpUserSid,
     WORD wNumStrings,
     DWORD dwDataSize,
     LPCWSTR *lpStrings,
     LPVOID lpRawData
    );









typedef struct _EVENTLOG_FULL_INFORMATION
{
    DWORD dwFull;
}
EVENTLOG_FULL_INFORMATION, *LPEVENTLOG_FULL_INFORMATION;

__declspec(dllimport)
BOOL

GetEventLogInformation (
     HANDLE hEventLog,
     DWORD dwInfoLevel,
     LPVOID lpBuffer,
     DWORD cbBufSize,
     LPDWORD pcbBytesNeeded
    );







__declspec(dllimport)
BOOL

DuplicateToken(
     HANDLE ExistingTokenHandle,
     SECURITY_IMPERSONATION_LEVEL ImpersonationLevel,
     PHANDLE DuplicateTokenHandle
    );

__declspec(dllimport)
BOOL

GetKernelObjectSecurity (
     HANDLE Handle,
     SECURITY_INFORMATION RequestedInformation,
     PSECURITY_DESCRIPTOR pSecurityDescriptor,
     DWORD nLength,
     LPDWORD lpnLengthNeeded
    );

__declspec(dllimport)
BOOL

ImpersonateNamedPipeClient(
     HANDLE hNamedPipe
    );

__declspec(dllimport)
BOOL

ImpersonateSelf(
     SECURITY_IMPERSONATION_LEVEL ImpersonationLevel
    );


__declspec(dllimport)
BOOL

RevertToSelf (
    void
    );

__declspec(dllimport)
BOOL

SetThreadToken (
     PHANDLE Thread,
     HANDLE Token
    );

__declspec(dllimport)
BOOL

AccessCheck (
     PSECURITY_DESCRIPTOR pSecurityDescriptor,
     HANDLE ClientToken,
     DWORD DesiredAccess,
     PGENERIC_MAPPING GenericMapping,
     PPRIVILEGE_SET PrivilegeSet,
     LPDWORD PrivilegeSetLength,
     LPDWORD GrantedAccess,
     LPBOOL AccessStatus
    );


__declspec(dllimport)
BOOL

AccessCheckByType (
     PSECURITY_DESCRIPTOR pSecurityDescriptor,
     PSID PrincipalSelfSid,
     HANDLE ClientToken,
     DWORD DesiredAccess,
     POBJECT_TYPE_LIST ObjectTypeList,
     DWORD ObjectTypeListLength,
     PGENERIC_MAPPING GenericMapping,
     PPRIVILEGE_SET PrivilegeSet,
     LPDWORD PrivilegeSetLength,
     LPDWORD GrantedAccess,
     LPBOOL AccessStatus
    );

__declspec(dllimport)
BOOL

AccessCheckByTypeResultList (
     PSECURITY_DESCRIPTOR pSecurityDescriptor,
     PSID PrincipalSelfSid,
     HANDLE ClientToken,
     DWORD DesiredAccess,
     POBJECT_TYPE_LIST ObjectTypeList,
     DWORD ObjectTypeListLength,
     PGENERIC_MAPPING GenericMapping,
     PPRIVILEGE_SET PrivilegeSet,
     LPDWORD PrivilegeSetLength,
     LPDWORD GrantedAccessList,
     LPDWORD AccessStatusList
    );



__declspec(dllimport)
BOOL

OpenProcessToken (
     HANDLE ProcessHandle,
     DWORD DesiredAccess,
     PHANDLE TokenHandle
    );


__declspec(dllimport)
BOOL

OpenThreadToken (
     HANDLE ThreadHandle,
     DWORD DesiredAccess,
     BOOL OpenAsSelf,
     PHANDLE TokenHandle
    );


__declspec(dllimport)
BOOL

GetTokenInformation (
     HANDLE TokenHandle,
     TOKEN_INFORMATION_CLASS TokenInformationClass,
     LPVOID TokenInformation,
     DWORD TokenInformationLength,
     PDWORD ReturnLength
    );


__declspec(dllimport)
BOOL

SetTokenInformation (
     HANDLE TokenHandle,
     TOKEN_INFORMATION_CLASS TokenInformationClass,
     LPVOID TokenInformation,
     DWORD TokenInformationLength
    );


__declspec(dllimport)
BOOL

AdjustTokenPrivileges (
     HANDLE TokenHandle,
     BOOL DisableAllPrivileges,
     PTOKEN_PRIVILEGES NewState,
     DWORD BufferLength,
     PTOKEN_PRIVILEGES PreviousState,
     PDWORD ReturnLength
    );


__declspec(dllimport)
BOOL

AdjustTokenGroups (
     HANDLE TokenHandle,
     BOOL ResetToDefault,
     PTOKEN_GROUPS NewState,
     DWORD BufferLength,
     PTOKEN_GROUPS PreviousState,
     PDWORD ReturnLength
    );


__declspec(dllimport)
BOOL

PrivilegeCheck (
     HANDLE ClientToken,
     PPRIVILEGE_SET RequiredPrivileges,
     LPBOOL pfResult
    );


__declspec(dllimport)
BOOL

AccessCheckAndAuditAlarmA (
     LPCSTR SubsystemName,
     LPVOID HandleId,
     LPSTR ObjectTypeName,
     LPSTR ObjectName,
     PSECURITY_DESCRIPTOR SecurityDescriptor,
     DWORD DesiredAccess,
     PGENERIC_MAPPING GenericMapping,
     BOOL ObjectCreation,
     LPDWORD GrantedAccess,
     LPBOOL AccessStatus,
     LPBOOL pfGenerateOnClose
    );
__declspec(dllimport)
BOOL

AccessCheckAndAuditAlarmW (
     LPCWSTR SubsystemName,
     LPVOID HandleId,
     LPWSTR ObjectTypeName,
     LPWSTR ObjectName,
     PSECURITY_DESCRIPTOR SecurityDescriptor,
     DWORD DesiredAccess,
     PGENERIC_MAPPING GenericMapping,
     BOOL ObjectCreation,
     LPDWORD GrantedAccess,
     LPBOOL AccessStatus,
     LPBOOL pfGenerateOnClose
    );








__declspec(dllimport)
BOOL

AccessCheckByTypeAndAuditAlarmA (
     LPCSTR SubsystemName,
     LPVOID HandleId,
     LPCSTR ObjectTypeName,
     LPCSTR ObjectName,
     PSECURITY_DESCRIPTOR SecurityDescriptor,
     PSID PrincipalSelfSid,
     DWORD DesiredAccess,
     AUDIT_EVENT_TYPE AuditType,
     DWORD Flags,
     POBJECT_TYPE_LIST ObjectTypeList,
     DWORD ObjectTypeListLength,
     PGENERIC_MAPPING GenericMapping,
     BOOL ObjectCreation,
     LPDWORD GrantedAccess,
     LPBOOL AccessStatus,
     LPBOOL pfGenerateOnClose
    );
__declspec(dllimport)
BOOL

AccessCheckByTypeAndAuditAlarmW (
     LPCWSTR SubsystemName,
     LPVOID HandleId,
     LPCWSTR ObjectTypeName,
     LPCWSTR ObjectName,
     PSECURITY_DESCRIPTOR SecurityDescriptor,
     PSID PrincipalSelfSid,
     DWORD DesiredAccess,
     AUDIT_EVENT_TYPE AuditType,
     DWORD Flags,
     POBJECT_TYPE_LIST ObjectTypeList,
     DWORD ObjectTypeListLength,
     PGENERIC_MAPPING GenericMapping,
     BOOL ObjectCreation,
     LPDWORD GrantedAccess,
     LPBOOL AccessStatus,
     LPBOOL pfGenerateOnClose
    );






__declspec(dllimport)
BOOL

AccessCheckByTypeResultListAndAuditAlarmA (
     LPCSTR SubsystemName,
     LPVOID HandleId,
     LPCSTR ObjectTypeName,
     LPCSTR ObjectName,
     PSECURITY_DESCRIPTOR SecurityDescriptor,
     PSID PrincipalSelfSid,
     DWORD DesiredAccess,
     AUDIT_EVENT_TYPE AuditType,
     DWORD Flags,
     POBJECT_TYPE_LIST ObjectTypeList,
     DWORD ObjectTypeListLength,
     PGENERIC_MAPPING GenericMapping,
     BOOL ObjectCreation,
     LPDWORD GrantedAccess,
     LPDWORD AccessStatusList,
     LPBOOL pfGenerateOnClose
    );
__declspec(dllimport)
BOOL

AccessCheckByTypeResultListAndAuditAlarmW (
     LPCWSTR SubsystemName,
     LPVOID HandleId,
     LPCWSTR ObjectTypeName,
     LPCWSTR ObjectName,
     PSECURITY_DESCRIPTOR SecurityDescriptor,
     PSID PrincipalSelfSid,
     DWORD DesiredAccess,
     AUDIT_EVENT_TYPE AuditType,
     DWORD Flags,
     POBJECT_TYPE_LIST ObjectTypeList,
     DWORD ObjectTypeListLength,
     PGENERIC_MAPPING GenericMapping,
     BOOL ObjectCreation,
     LPDWORD GrantedAccess,
     LPDWORD AccessStatusList,
     LPBOOL pfGenerateOnClose
    );






__declspec(dllimport)
BOOL

AccessCheckByTypeResultListAndAuditAlarmByHandleA (
     LPCSTR SubsystemName,
     LPVOID HandleId,
     HANDLE ClientToken,
     LPCSTR ObjectTypeName,
     LPCSTR ObjectName,
     PSECURITY_DESCRIPTOR SecurityDescriptor,
     PSID PrincipalSelfSid,
     DWORD DesiredAccess,
     AUDIT_EVENT_TYPE AuditType,
     DWORD Flags,
     POBJECT_TYPE_LIST ObjectTypeList,
     DWORD ObjectTypeListLength,
     PGENERIC_MAPPING GenericMapping,
     BOOL ObjectCreation,
     LPDWORD GrantedAccess,
     LPDWORD AccessStatusList,
     LPBOOL pfGenerateOnClose
    );
__declspec(dllimport)
BOOL

AccessCheckByTypeResultListAndAuditAlarmByHandleW (
     LPCWSTR SubsystemName,
     LPVOID HandleId,
     HANDLE ClientToken,
     LPCWSTR ObjectTypeName,
     LPCWSTR ObjectName,
     PSECURITY_DESCRIPTOR SecurityDescriptor,
     PSID PrincipalSelfSid,
     DWORD DesiredAccess,
     AUDIT_EVENT_TYPE AuditType,
     DWORD Flags,
     POBJECT_TYPE_LIST ObjectTypeList,
     DWORD ObjectTypeListLength,
     PGENERIC_MAPPING GenericMapping,
     BOOL ObjectCreation,
     LPDWORD GrantedAccess,
     LPDWORD AccessStatusList,
     LPBOOL pfGenerateOnClose
    );








__declspec(dllimport)
BOOL

ObjectOpenAuditAlarmA (
     LPCSTR SubsystemName,
     LPVOID HandleId,
     LPSTR ObjectTypeName,
     LPSTR ObjectName,
     PSECURITY_DESCRIPTOR pSecurityDescriptor,
     HANDLE ClientToken,
     DWORD DesiredAccess,
     DWORD GrantedAccess,
     PPRIVILEGE_SET Privileges,
     BOOL ObjectCreation,
     BOOL AccessGranted,
     LPBOOL GenerateOnClose
    );
__declspec(dllimport)
BOOL

ObjectOpenAuditAlarmW (
     LPCWSTR SubsystemName,
     LPVOID HandleId,
     LPWSTR ObjectTypeName,
     LPWSTR ObjectName,
     PSECURITY_DESCRIPTOR pSecurityDescriptor,
     HANDLE ClientToken,
     DWORD DesiredAccess,
     DWORD GrantedAccess,
     PPRIVILEGE_SET Privileges,
     BOOL ObjectCreation,
     BOOL AccessGranted,
     LPBOOL GenerateOnClose
    );







__declspec(dllimport)
BOOL

ObjectPrivilegeAuditAlarmA (
     LPCSTR SubsystemName,
     LPVOID HandleId,
     HANDLE ClientToken,
     DWORD DesiredAccess,
     PPRIVILEGE_SET Privileges,
     BOOL AccessGranted
    );
__declspec(dllimport)
BOOL

ObjectPrivilegeAuditAlarmW (
     LPCWSTR SubsystemName,
     LPVOID HandleId,
     HANDLE ClientToken,
     DWORD DesiredAccess,
     PPRIVILEGE_SET Privileges,
     BOOL AccessGranted
    );







__declspec(dllimport)
BOOL

ObjectCloseAuditAlarmA (
     LPCSTR SubsystemName,
     LPVOID HandleId,
     BOOL GenerateOnClose
    );
__declspec(dllimport)
BOOL

ObjectCloseAuditAlarmW (
     LPCWSTR SubsystemName,
     LPVOID HandleId,
     BOOL GenerateOnClose
    );







__declspec(dllimport)
BOOL

ObjectDeleteAuditAlarmA (
     LPCSTR SubsystemName,
     LPVOID HandleId,
     BOOL GenerateOnClose
    );
__declspec(dllimport)
BOOL

ObjectDeleteAuditAlarmW (
     LPCWSTR SubsystemName,
     LPVOID HandleId,
     BOOL GenerateOnClose
    );







__declspec(dllimport)
BOOL

PrivilegedServiceAuditAlarmA (
     LPCSTR SubsystemName,
     LPCSTR ServiceName,
     HANDLE ClientToken,
     PPRIVILEGE_SET Privileges,
     BOOL AccessGranted
    );
__declspec(dllimport)
BOOL

PrivilegedServiceAuditAlarmW (
     LPCWSTR SubsystemName,
     LPCWSTR ServiceName,
     HANDLE ClientToken,
     PPRIVILEGE_SET Privileges,
     BOOL AccessGranted
    );
__declspec(dllimport)
BOOL

IsWellKnownSid (
     PSID pSid,
     WELL_KNOWN_SID_TYPE WellKnownSidType
    );

__declspec(dllimport)
BOOL

CreateWellKnownSid(
     WELL_KNOWN_SID_TYPE WellKnownSidType,
     PSID DomainSid,
     PSID pSid,
     DWORD *cbSid
    );

__declspec(dllimport)
BOOL

EqualDomainSid(
     PSID pSid1,
     PSID pSid2,
     BOOL *pfEqual
    );

__declspec(dllimport)
BOOL

GetWindowsAccountDomainSid(
     PSID pSid,
     PSID pDomainSid,
     DWORD* cbDomainSid
    );



__declspec(dllimport)
BOOL

IsValidSid (
     PSID pSid
    );


__declspec(dllimport)
BOOL

EqualSid (
     PSID pSid1,
     PSID pSid2
    );


__declspec(dllimport)
BOOL

EqualPrefixSid (
     PSID pSid1,
     PSID pSid2
    );


__declspec(dllimport)
DWORD

GetSidLengthRequired (
     UCHAR nSubAuthorityCount
    );


__declspec(dllimport)
BOOL

AllocateAndInitializeSid (
     PSID_IDENTIFIER_AUTHORITY pIdentifierAuthority,
     BYTE nSubAuthorityCount,
     DWORD nSubAuthority0,
     DWORD nSubAuthority1,
     DWORD nSubAuthority2,
     DWORD nSubAuthority3,
     DWORD nSubAuthority4,
     DWORD nSubAuthority5,
     DWORD nSubAuthority6,
     DWORD nSubAuthority7,
     PSID *pSid
    );

__declspec(dllimport)
PVOID

FreeSid(
     PSID pSid
    );

__declspec(dllimport)
BOOL

InitializeSid (
     PSID Sid,
     PSID_IDENTIFIER_AUTHORITY pIdentifierAuthority,
     BYTE nSubAuthorityCount
    );


__declspec(dllimport)

PSID_IDENTIFIER_AUTHORITY

GetSidIdentifierAuthority (
     PSID pSid
    );


__declspec(dllimport)

PDWORD

GetSidSubAuthority (
     PSID pSid,
     DWORD nSubAuthority
    );


__declspec(dllimport)

PUCHAR

GetSidSubAuthorityCount (
     PSID pSid
    );


__declspec(dllimport)
DWORD

GetLengthSid (
     PSID pSid
    );


__declspec(dllimport)
BOOL

CopySid (
     DWORD nDestinationSidLength,
     PSID pDestinationSid,
     PSID pSourceSid
    );


__declspec(dllimport)
BOOL

AreAllAccessesGranted (
     DWORD GrantedAccess,
     DWORD DesiredAccess
    );


__declspec(dllimport)
BOOL

AreAnyAccessesGranted (
     DWORD GrantedAccess,
     DWORD DesiredAccess
    );


__declspec(dllimport)
void

MapGenericMask (
     PDWORD AccessMask,
     PGENERIC_MAPPING GenericMapping
    );


__declspec(dllimport)
BOOL

IsValidAcl (
     PACL pAcl
    );


__declspec(dllimport)
BOOL

InitializeAcl (
     PACL pAcl,
     DWORD nAclLength,
     DWORD dwAclRevision
    );


__declspec(dllimport)
BOOL

GetAclInformation (
     PACL pAcl,
     LPVOID pAclInformation,
     DWORD nAclInformationLength,
     ACL_INFORMATION_CLASS dwAclInformationClass
    );


__declspec(dllimport)
BOOL

SetAclInformation (
     PACL pAcl,
     LPVOID pAclInformation,
     DWORD nAclInformationLength,
     ACL_INFORMATION_CLASS dwAclInformationClass
    );


__declspec(dllimport)
BOOL

AddAce (
     PACL pAcl,
     DWORD dwAceRevision,
     DWORD dwStartingAceIndex,
     LPVOID pAceList,
     DWORD nAceListLength
    );


__declspec(dllimport)
BOOL

DeleteAce (
     PACL pAcl,
     DWORD dwAceIndex
    );


__declspec(dllimport)
BOOL

GetAce (
     PACL pAcl,
     DWORD dwAceIndex,
     LPVOID *pAce
    );


__declspec(dllimport)
BOOL

AddAccessAllowedAce (
     PACL pAcl,
     DWORD dwAceRevision,
     DWORD AccessMask,
     PSID pSid
    );


__declspec(dllimport)
BOOL

AddAccessAllowedAceEx (
     PACL pAcl,
     DWORD dwAceRevision,
     DWORD AceFlags,
     DWORD AccessMask,
     PSID pSid
    );



__declspec(dllimport)
BOOL

AddMandatoryAce (
     PACL pAcl,
     DWORD dwAceRevision,
     DWORD AceFlags,
     DWORD MandatoryPolicy,
     PSID pLabelSid
    );


__declspec(dllimport)
BOOL

AddAccessDeniedAce (
     PACL pAcl,
     DWORD dwAceRevision,
     DWORD AccessMask,
     PSID pSid
    );


__declspec(dllimport)
BOOL

AddAccessDeniedAceEx (
     PACL pAcl,
     DWORD dwAceRevision,
     DWORD AceFlags,
     DWORD AccessMask,
     PSID pSid
    );


__declspec(dllimport)
BOOL

AddAuditAccessAce(
     PACL pAcl,
     DWORD dwAceRevision,
     DWORD dwAccessMask,
     PSID pSid,
     BOOL bAuditSuccess,
     BOOL bAuditFailure
    );


__declspec(dllimport)
BOOL

AddAuditAccessAceEx(
     PACL pAcl,
     DWORD dwAceRevision,
     DWORD AceFlags,
     DWORD dwAccessMask,
     PSID pSid,
     BOOL bAuditSuccess,
     BOOL bAuditFailure
    );

__declspec(dllimport)
BOOL

AddAccessAllowedObjectAce (
     PACL pAcl,
     DWORD dwAceRevision,
     DWORD AceFlags,
     DWORD AccessMask,
     GUID *ObjectTypeGuid,
     GUID *InheritedObjectTypeGuid,
     PSID pSid
    );

__declspec(dllimport)
BOOL

AddAccessDeniedObjectAce (
     PACL pAcl,
     DWORD dwAceRevision,
     DWORD AceFlags,
     DWORD AccessMask,
     GUID *ObjectTypeGuid,
     GUID *InheritedObjectTypeGuid,
     PSID pSid
    );

__declspec(dllimport)
BOOL

AddAuditAccessObjectAce (
     PACL pAcl,
     DWORD dwAceRevision,
     DWORD AceFlags,
     DWORD AccessMask,
     GUID *ObjectTypeGuid,
     GUID *InheritedObjectTypeGuid,
     PSID pSid,
     BOOL bAuditSuccess,
     BOOL bAuditFailure
    );


__declspec(dllimport)
BOOL

FindFirstFreeAce (
     PACL pAcl,
     LPVOID *pAce
    );


__declspec(dllimport)
BOOL

InitializeSecurityDescriptor (
     PSECURITY_DESCRIPTOR pSecurityDescriptor,
     DWORD dwRevision
    );


__declspec(dllimport)
BOOL

IsValidSecurityDescriptor (
     PSECURITY_DESCRIPTOR pSecurityDescriptor
    );

__declspec(dllimport)
BOOL

IsValidRelativeSecurityDescriptor (
     PSECURITY_DESCRIPTOR pSecurityDescriptor,
     ULONG SecurityDescriptorLength,
     SECURITY_INFORMATION RequiredInformation
    );

__declspec(dllimport)
DWORD

GetSecurityDescriptorLength (
     PSECURITY_DESCRIPTOR pSecurityDescriptor
    );


__declspec(dllimport)
BOOL

GetSecurityDescriptorControl (
     PSECURITY_DESCRIPTOR pSecurityDescriptor,
     PSECURITY_DESCRIPTOR_CONTROL pControl,
     LPDWORD lpdwRevision
    );


__declspec(dllimport)
BOOL

SetSecurityDescriptorControl (
     PSECURITY_DESCRIPTOR pSecurityDescriptor,
     SECURITY_DESCRIPTOR_CONTROL ControlBitsOfInterest,
     SECURITY_DESCRIPTOR_CONTROL ControlBitsToSet
    );


__declspec(dllimport)
BOOL

SetSecurityDescriptorDacl (
     PSECURITY_DESCRIPTOR pSecurityDescriptor,
     BOOL bDaclPresent,
     PACL pDacl,
     BOOL bDaclDefaulted
    );


__declspec(dllimport)
BOOL

GetSecurityDescriptorDacl (
     PSECURITY_DESCRIPTOR pSecurityDescriptor,
     LPBOOL lpbDaclPresent,
     PACL *pDacl,
     LPBOOL lpbDaclDefaulted
    );


__declspec(dllimport)
BOOL

SetSecurityDescriptorSacl (
     PSECURITY_DESCRIPTOR pSecurityDescriptor,
     BOOL bSaclPresent,
     PACL pSacl,
     BOOL bSaclDefaulted
    );


__declspec(dllimport)
BOOL

GetSecurityDescriptorSacl (
     PSECURITY_DESCRIPTOR pSecurityDescriptor,
     LPBOOL lpbSaclPresent,
     PACL *pSacl,
     LPBOOL lpbSaclDefaulted
    );


__declspec(dllimport)
BOOL

SetSecurityDescriptorOwner (
     PSECURITY_DESCRIPTOR pSecurityDescriptor,
     PSID pOwner,
     BOOL bOwnerDefaulted
    );


__declspec(dllimport)
BOOL

GetSecurityDescriptorOwner (
     PSECURITY_DESCRIPTOR pSecurityDescriptor,
     PSID *pOwner,
     LPBOOL lpbOwnerDefaulted
    );


__declspec(dllimport)
BOOL

SetSecurityDescriptorGroup (
     PSECURITY_DESCRIPTOR pSecurityDescriptor,
     PSID pGroup,
     BOOL bGroupDefaulted
    );


__declspec(dllimport)
BOOL

GetSecurityDescriptorGroup (
     PSECURITY_DESCRIPTOR pSecurityDescriptor,
     PSID *pGroup,
     LPBOOL lpbGroupDefaulted
    );


__declspec(dllimport)
DWORD

SetSecurityDescriptorRMControl(
     PSECURITY_DESCRIPTOR SecurityDescriptor,
     PUCHAR RMControl
    );

__declspec(dllimport)
DWORD

GetSecurityDescriptorRMControl(
     PSECURITY_DESCRIPTOR SecurityDescriptor,
     PUCHAR RMControl
    );

__declspec(dllimport)
BOOL

CreatePrivateObjectSecurity (
     PSECURITY_DESCRIPTOR ParentDescriptor,
     PSECURITY_DESCRIPTOR CreatorDescriptor,
     PSECURITY_DESCRIPTOR * NewDescriptor,
     BOOL IsDirectoryObject,
     HANDLE Token,
     PGENERIC_MAPPING GenericMapping
    );


__declspec(dllimport)
BOOL

ConvertToAutoInheritPrivateObjectSecurity(
     PSECURITY_DESCRIPTOR ParentDescriptor,
     PSECURITY_DESCRIPTOR CurrentSecurityDescriptor,
     PSECURITY_DESCRIPTOR *NewSecurityDescriptor,
     GUID *ObjectType,
     BOOLEAN IsDirectoryObject,
     PGENERIC_MAPPING GenericMapping
    );

__declspec(dllimport)
BOOL

CreatePrivateObjectSecurityEx (
     PSECURITY_DESCRIPTOR ParentDescriptor,
     PSECURITY_DESCRIPTOR CreatorDescriptor,
     PSECURITY_DESCRIPTOR * NewDescriptor,
     GUID *ObjectType,
     BOOL IsContainerObject,
     ULONG AutoInheritFlags,
     HANDLE Token,
     PGENERIC_MAPPING GenericMapping
    );

__declspec(dllimport)
BOOL

CreatePrivateObjectSecurityWithMultipleInheritance (
     PSECURITY_DESCRIPTOR ParentDescriptor,
     PSECURITY_DESCRIPTOR CreatorDescriptor,
     PSECURITY_DESCRIPTOR * NewDescriptor,
     GUID **ObjectTypes,
     ULONG GuidCount,
     BOOL IsContainerObject,
     ULONG AutoInheritFlags,
     HANDLE Token,
     PGENERIC_MAPPING GenericMapping
    );


__declspec(dllimport)
BOOL

SetPrivateObjectSecurity (
     SECURITY_INFORMATION SecurityInformation,
     PSECURITY_DESCRIPTOR ModificationDescriptor,
     PSECURITY_DESCRIPTOR *ObjectsSecurityDescriptor,
     PGENERIC_MAPPING GenericMapping,
     HANDLE Token
    );


__declspec(dllimport)
BOOL

SetPrivateObjectSecurityEx (
     SECURITY_INFORMATION SecurityInformation,
     PSECURITY_DESCRIPTOR ModificationDescriptor,
     PSECURITY_DESCRIPTOR *ObjectsSecurityDescriptor,
     ULONG AutoInheritFlags,
     PGENERIC_MAPPING GenericMapping,
     HANDLE Token
    );


__declspec(dllimport)
BOOL

GetPrivateObjectSecurity (
     PSECURITY_DESCRIPTOR ObjectDescriptor,
     SECURITY_INFORMATION SecurityInformation,
     PSECURITY_DESCRIPTOR ResultantDescriptor,
     DWORD DescriptorLength,
     PDWORD ReturnLength
    );


__declspec(dllimport)
BOOL

DestroyPrivateObjectSecurity (
     PSECURITY_DESCRIPTOR * ObjectDescriptor
    );


__declspec(dllimport)
BOOL

MakeSelfRelativeSD (
     PSECURITY_DESCRIPTOR pAbsoluteSecurityDescriptor,
     PSECURITY_DESCRIPTOR pSelfRelativeSecurityDescriptor,
     LPDWORD lpdwBufferLength
    );


__declspec(dllimport)
BOOL

MakeAbsoluteSD (
     PSECURITY_DESCRIPTOR pSelfRelativeSecurityDescriptor,
     PSECURITY_DESCRIPTOR pAbsoluteSecurityDescriptor,
     LPDWORD lpdwAbsoluteSecurityDescriptorSize,
     PACL pDacl,
     LPDWORD lpdwDaclSize,
     PACL pSacl,
     LPDWORD lpdwSaclSize,
     PSID pOwner,
     LPDWORD lpdwOwnerSize,
     PSID pPrimaryGroup,
     LPDWORD lpdwPrimaryGroupSize
    );


__declspec(dllimport)
BOOL

MakeAbsoluteSD2 (
     PSECURITY_DESCRIPTOR pSelfRelativeSecurityDescriptor,
     LPDWORD lpdwBufferSize
    );

__declspec(dllimport)
void

QuerySecurityAccessMask(
     SECURITY_INFORMATION SecurityInformation,
     LPDWORD DesiredAccess
    );

__declspec(dllimport)
void

SetSecurityAccessMask(
     SECURITY_INFORMATION SecurityInformation,
     LPDWORD DesiredAccess
    );

__declspec(dllimport)
BOOL

SetFileSecurityA (
     LPCSTR lpFileName,
     SECURITY_INFORMATION SecurityInformation,
     PSECURITY_DESCRIPTOR pSecurityDescriptor
    );
__declspec(dllimport)
BOOL

SetFileSecurityW (
     LPCWSTR lpFileName,
     SECURITY_INFORMATION SecurityInformation,
     PSECURITY_DESCRIPTOR pSecurityDescriptor
    );







__declspec(dllimport)
BOOL

GetFileSecurityA (
     LPCSTR lpFileName,
     SECURITY_INFORMATION RequestedInformation,
     PSECURITY_DESCRIPTOR pSecurityDescriptor,
     DWORD nLength,
     LPDWORD lpnLengthNeeded
    );
__declspec(dllimport)
BOOL

GetFileSecurityW (
     LPCWSTR lpFileName,
     SECURITY_INFORMATION RequestedInformation,
     PSECURITY_DESCRIPTOR pSecurityDescriptor,
     DWORD nLength,
     LPDWORD lpnLengthNeeded
    );







__declspec(dllimport)
BOOL

SetKernelObjectSecurity (
     HANDLE Handle,
     SECURITY_INFORMATION SecurityInformation,
     PSECURITY_DESCRIPTOR SecurityDescriptor
    );

__declspec(dllimport)

HANDLE

FindFirstChangeNotificationA(
     LPCSTR lpPathName,
     BOOL bWatchSubtree,
     DWORD dwNotifyFilter
    );
__declspec(dllimport)

HANDLE

FindFirstChangeNotificationW(
     LPCWSTR lpPathName,
     BOOL bWatchSubtree,
     DWORD dwNotifyFilter
    );






__declspec(dllimport)
BOOL

FindNextChangeNotification(
     HANDLE hChangeHandle
    );

__declspec(dllimport)
BOOL

FindCloseChangeNotification(
     HANDLE hChangeHandle
    );


__declspec(dllimport)
BOOL

ReadDirectoryChangesW(
     HANDLE hDirectory,
     LPVOID lpBuffer,
     DWORD nBufferLength,
     BOOL bWatchSubtree,
     DWORD dwNotifyFilter,
     LPDWORD lpBytesReturned,
     LPOVERLAPPED lpOverlapped,
     LPOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine
    );


__declspec(dllimport)
BOOL

VirtualLock(
     LPVOID lpAddress,
     SIZE_T dwSize
    );

__declspec(dllimport)
BOOL

VirtualUnlock(
     LPVOID lpAddress,
     SIZE_T dwSize
    );

__declspec(dllimport)

LPVOID

MapViewOfFileEx(
     HANDLE hFileMappingObject,
     DWORD dwDesiredAccess,
     DWORD dwFileOffsetHigh,
     DWORD dwFileOffsetLow,
     SIZE_T dwNumberOfBytesToMap,
     LPVOID lpBaseAddress
    );



__declspec(dllimport)

LPVOID

MapViewOfFileExNuma(
     HANDLE hFileMappingObject,
     DWORD dwDesiredAccess,
     DWORD dwFileOffsetHigh,
     DWORD dwFileOffsetLow,
     SIZE_T dwNumberOfBytesToMap,
     LPVOID lpBaseAddress,
     DWORD nndPreferred
    );



__declspec(dllimport)
BOOL

SetPriorityClass(
     HANDLE hProcess,
     DWORD dwPriorityClass
    );

__declspec(dllimport)
DWORD

GetPriorityClass(
     HANDLE hProcess
    );

__declspec(dllimport)
BOOL

IsBadReadPtr(
      const   void  *lp,
     UINT_PTR ucb
    );

__declspec(dllimport)
BOOL

IsBadWritePtr(
     LPVOID lp,
     UINT_PTR ucb
    );

__declspec(dllimport)
BOOL

IsBadHugeReadPtr(
      const   void  *lp,
     UINT_PTR ucb
    );

__declspec(dllimport)
BOOL

IsBadHugeWritePtr(
     LPVOID lp,
     UINT_PTR ucb
    );

__declspec(dllimport)
BOOL

IsBadCodePtr(
     FARPROC lpfn
    );

__declspec(dllimport)
BOOL

IsBadStringPtrA(
     LPCSTR lpsz,
     UINT_PTR ucchMax
    );
__declspec(dllimport)
BOOL

IsBadStringPtrW(
     LPCWSTR lpsz,
     UINT_PTR ucchMax
    );






__declspec(dllimport)
BOOL

LookupAccountSidA(
     LPCSTR lpSystemName,
     PSID Sid,
     LPSTR Name,
     LPDWORD cchName,
     LPSTR ReferencedDomainName,
     LPDWORD cchReferencedDomainName,
     PSID_NAME_USE peUse
    );
__declspec(dllimport)
BOOL

LookupAccountSidW(
     LPCWSTR lpSystemName,
     PSID Sid,
     LPWSTR Name,
     LPDWORD cchName,
     LPWSTR ReferencedDomainName,
     LPDWORD cchReferencedDomainName,
     PSID_NAME_USE peUse
    );






__declspec(dllimport)
BOOL

LookupAccountNameA(
     LPCSTR lpSystemName,
     LPCSTR lpAccountName,
     PSID Sid,
     LPDWORD cbSid,
     LPSTR ReferencedDomainName,
     LPDWORD cchReferencedDomainName,
     PSID_NAME_USE peUse
    );
__declspec(dllimport)
BOOL

LookupAccountNameW(
     LPCWSTR lpSystemName,
     LPCWSTR lpAccountName,
     PSID Sid,
     LPDWORD cbSid,
     LPWSTR ReferencedDomainName,
     LPDWORD cchReferencedDomainName,
     PSID_NAME_USE peUse
    );






__declspec(dllimport)
BOOL

LookupPrivilegeValueA(
     LPCSTR lpSystemName,
     LPCSTR lpName,
     PLUID lpLuid
    );
__declspec(dllimport)
BOOL

LookupPrivilegeValueW(
     LPCWSTR lpSystemName,
     LPCWSTR lpName,
     PLUID lpLuid
    );






__declspec(dllimport)
BOOL

LookupPrivilegeNameA(
     LPCSTR lpSystemName,
     PLUID lpLuid,
     LPSTR lpName,
     LPDWORD cchName
    );
__declspec(dllimport)
BOOL

LookupPrivilegeNameW(
     LPCWSTR lpSystemName,
     PLUID lpLuid,
     LPWSTR lpName,
     LPDWORD cchName
    );






__declspec(dllimport)
BOOL

LookupPrivilegeDisplayNameA(
     LPCSTR lpSystemName,
     LPCSTR lpName,
     LPSTR lpDisplayName,
     LPDWORD cchDisplayName,
     LPDWORD lpLanguageId
    );
__declspec(dllimport)
BOOL

LookupPrivilegeDisplayNameW(
     LPCWSTR lpSystemName,
     LPCWSTR lpName,
     LPWSTR lpDisplayName,
     LPDWORD cchDisplayName,
     LPDWORD lpLanguageId
    );






__declspec(dllimport)
BOOL

AllocateLocallyUniqueId(
     PLUID Luid
    );

__declspec(dllimport)
BOOL

BuildCommDCBA(
     LPCSTR lpDef,
     LPDCB lpDCB
    );
__declspec(dllimport)
BOOL

BuildCommDCBW(
     LPCWSTR lpDef,
     LPDCB lpDCB
    );






__declspec(dllimport)
BOOL

BuildCommDCBAndTimeoutsA(
     LPCSTR lpDef,
     LPDCB lpDCB,
     LPCOMMTIMEOUTS lpCommTimeouts
    );
__declspec(dllimport)
BOOL

BuildCommDCBAndTimeoutsW(
     LPCWSTR lpDef,
     LPDCB lpDCB,
     LPCOMMTIMEOUTS lpCommTimeouts
    );






__declspec(dllimport)
BOOL

CommConfigDialogA(
     LPCSTR lpszName,
     HWND hWnd,
     LPCOMMCONFIG lpCC
    );
__declspec(dllimport)
BOOL

CommConfigDialogW(
     LPCWSTR lpszName,
     HWND hWnd,
     LPCOMMCONFIG lpCC
    );






__declspec(dllimport)
BOOL

GetDefaultCommConfigA(
     LPCSTR lpszName,
     LPCOMMCONFIG lpCC,
     LPDWORD lpdwSize
    );
__declspec(dllimport)
BOOL

GetDefaultCommConfigW(
     LPCWSTR lpszName,
     LPCOMMCONFIG lpCC,
     LPDWORD lpdwSize
    );






__declspec(dllimport)
BOOL

SetDefaultCommConfigA(
     LPCSTR lpszName,
     LPCOMMCONFIG lpCC,
     DWORD dwSize
    );
__declspec(dllimport)
BOOL

SetDefaultCommConfigW(
     LPCWSTR lpszName,
     LPCOMMCONFIG lpCC,
     DWORD dwSize
    );
__declspec(dllimport)

BOOL

GetComputerNameA (
       LPSTR lpBuffer,
     LPDWORD nSize
    );
__declspec(dllimport)

BOOL

GetComputerNameW (
       LPWSTR lpBuffer,
     LPDWORD nSize
    );






__declspec(dllimport)
BOOL

SetComputerNameA (
     LPCSTR lpComputerName
    );
__declspec(dllimport)
BOOL

SetComputerNameW (
     LPCWSTR lpComputerName
    );









typedef enum _COMPUTER_NAME_FORMAT {
    ComputerNameNetBIOS,
    ComputerNameDnsHostname,
    ComputerNameDnsDomain,
    ComputerNameDnsFullyQualified,
    ComputerNamePhysicalNetBIOS,
    ComputerNamePhysicalDnsHostname,
    ComputerNamePhysicalDnsDomain,
    ComputerNamePhysicalDnsFullyQualified,
    ComputerNameMax
} COMPUTER_NAME_FORMAT ;

__declspec(dllimport)

BOOL

GetComputerNameExA (
     COMPUTER_NAME_FORMAT NameType,
     LPSTR lpBuffer,
     LPDWORD nSize
    );
__declspec(dllimport)

BOOL

GetComputerNameExW (
     COMPUTER_NAME_FORMAT NameType,
     LPWSTR lpBuffer,
     LPDWORD nSize
    );






__declspec(dllimport)
BOOL

SetComputerNameExA (
     COMPUTER_NAME_FORMAT NameType,
     LPCSTR lpBuffer
    );
__declspec(dllimport)
BOOL

SetComputerNameExW (
     COMPUTER_NAME_FORMAT NameType,
     LPCWSTR lpBuffer
    );







__declspec(dllimport)

BOOL

DnsHostnameToComputerNameA (
     LPCSTR Hostname,
       LPSTR ComputerName,
     LPDWORD nSize
    );
__declspec(dllimport)

BOOL

DnsHostnameToComputerNameW (
     LPCWSTR Hostname,
       LPWSTR ComputerName,
     LPDWORD nSize
    );








__declspec(dllimport)
BOOL

GetUserNameA (
     LPSTR lpBuffer,
     LPDWORD pcbBuffer
    );
__declspec(dllimport)
BOOL

GetUserNameW (
     LPWSTR lpBuffer,
     LPDWORD pcbBuffer
    );
__declspec(dllimport)
BOOL

LogonUserA (
     LPCSTR lpszUsername,
     LPCSTR lpszDomain,
     LPCSTR lpszPassword,
     DWORD dwLogonType,
     DWORD dwLogonProvider,
     PHANDLE phToken
    );
__declspec(dllimport)
BOOL

LogonUserW (
     LPCWSTR lpszUsername,
     LPCWSTR lpszDomain,
     LPCWSTR lpszPassword,
     DWORD dwLogonType,
     DWORD dwLogonProvider,
     PHANDLE phToken
    );






__declspec(dllimport)
BOOL

LogonUserExA (
     LPCSTR lpszUsername,
     LPCSTR lpszDomain,
     LPCSTR lpszPassword,
     DWORD dwLogonType,
     DWORD dwLogonProvider,
     PHANDLE phToken,
     PSID *ppLogonSid,
     PVOID *ppProfileBuffer,
     LPDWORD pdwProfileLength,
     PQUOTA_LIMITS pQuotaLimits
    );
__declspec(dllimport)
BOOL

LogonUserExW (
     LPCWSTR lpszUsername,
     LPCWSTR lpszDomain,
     LPCWSTR lpszPassword,
     DWORD dwLogonType,
     DWORD dwLogonProvider,
     PHANDLE phToken,
     PSID *ppLogonSid,
     PVOID *ppProfileBuffer,
     LPDWORD pdwProfileLength,
     PQUOTA_LIMITS pQuotaLimits
    );
__declspec(dllimport)
BOOL

ImpersonateLoggedOnUser(
     HANDLE hToken
    );

__declspec(dllimport)
BOOL

CreateProcessAsUserA (
     HANDLE hToken,
     LPCSTR lpApplicationName,
     LPSTR lpCommandLine,
     LPSECURITY_ATTRIBUTES lpProcessAttributes,
     LPSECURITY_ATTRIBUTES lpThreadAttributes,
     BOOL bInheritHandles,
     DWORD dwCreationFlags,
     LPVOID lpEnvironment,
     LPCSTR lpCurrentDirectory,
     LPSTARTUPINFOA lpStartupInfo,
     LPPROCESS_INFORMATION lpProcessInformation
    );
__declspec(dllimport)
BOOL

CreateProcessAsUserW (
     HANDLE hToken,
     LPCWSTR lpApplicationName,
     LPWSTR lpCommandLine,
     LPSECURITY_ATTRIBUTES lpProcessAttributes,
     LPSECURITY_ATTRIBUTES lpThreadAttributes,
     BOOL bInheritHandles,
     DWORD dwCreationFlags,
     LPVOID lpEnvironment,
     LPCWSTR lpCurrentDirectory,
     LPSTARTUPINFOW lpStartupInfo,
     LPPROCESS_INFORMATION lpProcessInformation
    );
__declspec(dllimport)
BOOL

CreateProcessWithLogonW(
     LPCWSTR lpUsername,
     LPCWSTR lpDomain,
     LPCWSTR lpPassword,
     DWORD dwLogonFlags,
     LPCWSTR lpApplicationName,
     LPWSTR lpCommandLine,
     DWORD dwCreationFlags,
     LPVOID lpEnvironment,
     LPCWSTR lpCurrentDirectory,
     LPSTARTUPINFOW lpStartupInfo,
     LPPROCESS_INFORMATION lpProcessInformation
      );

__declspec(dllimport)
BOOL

CreateProcessWithTokenW(
     HANDLE hToken,
     DWORD dwLogonFlags,
     LPCWSTR lpApplicationName,
     LPWSTR lpCommandLine,
     DWORD dwCreationFlags,
     LPVOID lpEnvironment,
     LPCWSTR lpCurrentDirectory,
     LPSTARTUPINFOW lpStartupInfo,
     LPPROCESS_INFORMATION lpProcessInformation
      );



__declspec(dllimport)
BOOL

ImpersonateAnonymousToken(
     HANDLE ThreadHandle
    );

__declspec(dllimport)
BOOL

DuplicateTokenEx(
     HANDLE hExistingToken,
     DWORD dwDesiredAccess,
     LPSECURITY_ATTRIBUTES lpTokenAttributes,
     SECURITY_IMPERSONATION_LEVEL ImpersonationLevel,
     TOKEN_TYPE TokenType,
     PHANDLE phNewToken);

__declspec(dllimport)
BOOL

CreateRestrictedToken(
     HANDLE ExistingTokenHandle,
     DWORD Flags,
     DWORD DisableSidCount,
     PSID_AND_ATTRIBUTES SidsToDisable,
     DWORD DeletePrivilegeCount,
     PLUID_AND_ATTRIBUTES PrivilegesToDelete,
     DWORD RestrictedSidCount,
     PSID_AND_ATTRIBUTES SidsToRestrict,
     PHANDLE NewTokenHandle
    );


__declspec(dllimport)
BOOL

IsTokenRestricted(
     HANDLE TokenHandle
    );

__declspec(dllimport)
BOOL

IsTokenUntrusted(
     HANDLE TokenHandle
    );

__declspec(dllimport)
BOOL

CheckTokenMembership(
     HANDLE TokenHandle,
     PSID SidToCheck,
     PBOOL IsMember
    );







typedef WAITORTIMERCALLBACKFUNC WAITORTIMERCALLBACK ;

__declspec(dllimport)
BOOL

RegisterWaitForSingleObject(
     PHANDLE phNewWaitObject,
     HANDLE hObject,
     WAITORTIMERCALLBACK Callback,
     PVOID Context,
     ULONG dwMilliseconds,
     ULONG dwFlags
    );

__declspec(dllimport)
HANDLE

RegisterWaitForSingleObjectEx(
     HANDLE hObject,
     WAITORTIMERCALLBACK Callback,
     PVOID Context,
     ULONG dwMilliseconds,
     ULONG dwFlags
    );

__declspec(dllimport)

BOOL

UnregisterWait(
     HANDLE WaitHandle
    );

__declspec(dllimport)

BOOL

UnregisterWaitEx(
     HANDLE WaitHandle,
     HANDLE CompletionEvent
    );

__declspec(dllimport)
BOOL

QueueUserWorkItem(
     LPTHREAD_START_ROUTINE Function,
     PVOID Context,
     ULONG Flags
    );

__declspec(dllimport)
BOOL

BindIoCompletionCallback (
     HANDLE FileHandle,
     LPOVERLAPPED_COMPLETION_ROUTINE Function,
     ULONG Flags
    );

__declspec(dllimport)

HANDLE

CreateTimerQueue(
    void
    );

__declspec(dllimport)
BOOL

CreateTimerQueueTimer(
     PHANDLE phNewTimer,
     HANDLE TimerQueue,
     WAITORTIMERCALLBACK Callback,
     PVOID Parameter,
     DWORD DueTime,
     DWORD Period,
     ULONG Flags
    ) ;

__declspec(dllimport)

BOOL

ChangeTimerQueueTimer(
     HANDLE TimerQueue,
     HANDLE Timer,
     ULONG DueTime,
     ULONG Period
    );

__declspec(dllimport)

BOOL

DeleteTimerQueueTimer(
     HANDLE TimerQueue,
     HANDLE Timer,
     HANDLE CompletionEvent
    );

__declspec(dllimport)

BOOL

DeleteTimerQueueEx(
     HANDLE TimerQueue,
     HANDLE CompletionEvent
    );

__declspec(dllimport)
HANDLE

SetTimerQueueTimer(
     HANDLE TimerQueue,
     WAITORTIMERCALLBACK Callback,
     PVOID Parameter,
     DWORD DueTime,
     DWORD Period,
     BOOL PreferIo
    );

__declspec(dllimport)

BOOL

CancelTimerQueueTimer(
     HANDLE TimerQueue,
     HANDLE Timer
    );

__declspec(dllimport)

BOOL

DeleteTimerQueue(
     HANDLE TimerQueue
    );



typedef  void  (  *PTP_WIN32_IO_CALLBACK)(
     PTP_CALLBACK_INSTANCE Instance,
     PVOID Context,
     PVOID Overlapped,
     ULONG IoResult,
     ULONG_PTR NumberOfBytesTransferred,
     PTP_IO Io
    );

__declspec(dllimport)


PTP_POOL

CreateThreadpool(
     PVOID reserved
    );

__declspec(dllimport)
void

SetThreadpoolThreadMaximum(
     PTP_POOL ptpp,
     DWORD cthrdMost
    );

__declspec(dllimport)
BOOL

SetThreadpoolThreadMinimum(
     PTP_POOL ptpp,
     DWORD cthrdMic
    );

__declspec(dllimport)
void

CloseThreadpool(
     PTP_POOL ptpp
    );

__declspec(dllimport)


PTP_CLEANUP_GROUP

CreateThreadpoolCleanupGroup(
    void
    );

__declspec(dllimport)
void

CloseThreadpoolCleanupGroupMembers(
     PTP_CLEANUP_GROUP ptpcg,
     BOOL fCancelPendingCallbacks,
     PVOID pvCleanupContext
    );

__declspec(dllimport)
void

CloseThreadpoolCleanupGroup(
     PTP_CLEANUP_GROUP ptpcg
    );



__inline
void
InitializeThreadpoolEnvironment(
     PTP_CALLBACK_ENVIRON pcbe
    )
{
    TpInitializeCallbackEnviron(pcbe);
}

__inline
void
SetThreadpoolCallbackPool(
     PTP_CALLBACK_ENVIRON pcbe,
     PTP_POOL ptpp
    )
{
    TpSetCallbackThreadpool(pcbe, ptpp);
}

__inline
void
SetThreadpoolCallbackCleanupGroup(
     PTP_CALLBACK_ENVIRON pcbe,
     PTP_CLEANUP_GROUP ptpcg,
     PTP_CLEANUP_GROUP_CANCEL_CALLBACK pfng
    )
{
    TpSetCallbackCleanupGroup(pcbe, ptpcg, pfng);
}

__inline
void
SetThreadpoolCallbackRunsLong(
     PTP_CALLBACK_ENVIRON pcbe
    )
{
    TpSetCallbackLongFunction(pcbe);
}

__inline
void
SetThreadpoolCallbackLibrary(
     PTP_CALLBACK_ENVIRON pcbe,
     PVOID mod
    )
{
    TpSetCallbackRaceWithDll(pcbe, mod);
}

__inline
void
DestroyThreadpoolEnvironment(
     PTP_CALLBACK_ENVIRON pcbe
    )
{
    TpDestroyCallbackEnviron(pcbe);
}



__declspec(dllimport)
void

SetEventWhenCallbackReturns(
     PTP_CALLBACK_INSTANCE pci,
     HANDLE evt
    );

__declspec(dllimport)
void

ReleaseSemaphoreWhenCallbackReturns(
     PTP_CALLBACK_INSTANCE pci,
     HANDLE sem,
     DWORD crel
    );

__declspec(dllimport)
void

ReleaseMutexWhenCallbackReturns(
     PTP_CALLBACK_INSTANCE pci,
     HANDLE mut
    );

__declspec(dllimport)
void

LeaveCriticalSectionWhenCallbackReturns(
     PTP_CALLBACK_INSTANCE pci,
     PCRITICAL_SECTION pcs
    );

__declspec(dllimport)
void

FreeLibraryWhenCallbackReturns(
     PTP_CALLBACK_INSTANCE pci,
     HMODULE mod
    );

__declspec(dllimport)
BOOL

CallbackMayRunLong(
     PTP_CALLBACK_INSTANCE pci
    );

__declspec(dllimport)
void

DisassociateCurrentThreadFromCallback(
     PTP_CALLBACK_INSTANCE pci
    );

__declspec(dllimport)

BOOL

TrySubmitThreadpoolCallback(
     PTP_SIMPLE_CALLBACK pfns,
     PVOID pv,
     PTP_CALLBACK_ENVIRON pcbe
    );

__declspec(dllimport)


PTP_WORK

CreateThreadpoolWork(
     PTP_WORK_CALLBACK pfnwk,
     PVOID pv,
     PTP_CALLBACK_ENVIRON pcbe
    );

__declspec(dllimport)
void

SubmitThreadpoolWork(
     PTP_WORK pwk
    );

__declspec(dllimport)
void

WaitForThreadpoolWorkCallbacks(
     PTP_WORK pwk,
     BOOL fCancelPendingCallbacks
    );

__declspec(dllimport)
void

CloseThreadpoolWork(
     PTP_WORK pwk
    );

__declspec(dllimport)


PTP_TIMER

CreateThreadpoolTimer(
     PTP_TIMER_CALLBACK pfnti,
     PVOID pv,
     PTP_CALLBACK_ENVIRON pcbe
    );

__declspec(dllimport)
void

SetThreadpoolTimer(
     PTP_TIMER pti,
     PFILETIME pftDueTime,
     DWORD msPeriod,
     DWORD msWindowLength
    );

__declspec(dllimport)
BOOL

IsThreadpoolTimerSet(
     PTP_TIMER pti
    );

__declspec(dllimport)
void

WaitForThreadpoolTimerCallbacks(
     PTP_TIMER pti,
     BOOL fCancelPendingCallbacks
    );

__declspec(dllimport)
void

CloseThreadpoolTimer(
     PTP_TIMER pti
    );

__declspec(dllimport)


PTP_WAIT

CreateThreadpoolWait(
     PTP_WAIT_CALLBACK pfnwa,
     PVOID pv,
     PTP_CALLBACK_ENVIRON pcbe
    );

__declspec(dllimport)
void

SetThreadpoolWait(
     PTP_WAIT pwa,
     HANDLE h,
     PFILETIME pftTimeout
    );

__declspec(dllimport)
void

WaitForThreadpoolWaitCallbacks(
     PTP_WAIT pwa,
     BOOL fCancelPendingCallbacks
    );

__declspec(dllimport)
void

CloseThreadpoolWait(
     PTP_WAIT pwa
    );

__declspec(dllimport)


PTP_IO

CreateThreadpoolIo(
     HANDLE fl,
     PTP_WIN32_IO_CALLBACK pfnio,
     PVOID pv,
     PTP_CALLBACK_ENVIRON pcbe
    );

__declspec(dllimport)
void

StartThreadpoolIo(
     PTP_IO pio
    );

__declspec(dllimport)
void

CancelThreadpoolIo(
     PTP_IO pio
    );

__declspec(dllimport)
void

WaitForThreadpoolIoCallbacks(
     PTP_IO pio,
     BOOL fCancelPendingCallbacks
    );

__declspec(dllimport)
void

CloseThreadpoolIo(
     PTP_IO pio
    );





__declspec(dllimport)

HANDLE

CreatePrivateNamespaceA(
     LPSECURITY_ATTRIBUTES lpPrivateNamespaceAttributes,
     LPVOID lpBoundaryDescriptor,
     LPCSTR lpAliasPrefix
    );
__declspec(dllimport)

HANDLE

CreatePrivateNamespaceW(
     LPSECURITY_ATTRIBUTES lpPrivateNamespaceAttributes,
     LPVOID lpBoundaryDescriptor,
     LPCWSTR lpAliasPrefix
    );






__declspec(dllimport)

HANDLE

OpenPrivateNamespaceA(
     LPVOID lpBoundaryDescriptor,
     LPCSTR lpAliasPrefix
    );
__declspec(dllimport)

HANDLE

OpenPrivateNamespaceW(
     LPVOID lpBoundaryDescriptor,
     LPCWSTR lpAliasPrefix
    );









__declspec(dllimport)
BOOLEAN

ClosePrivateNamespace(
     HANDLE Handle,
     ULONG Flags
    );







HANDLE

CreateBoundaryDescriptorA(
     LPCSTR Name,
     ULONG Flags
    );

HANDLE

CreateBoundaryDescriptorW(
     LPCWSTR Name,
     ULONG Flags
    );






__declspec(dllimport)
BOOL

AddSIDToBoundaryDescriptor(
     HANDLE * BoundaryDescriptor,
     PSID RequiredSid
    );


__declspec(dllimport)
void

DeleteBoundaryDescriptor(
     HANDLE BoundaryDescriptor
    );
typedef struct tagHW_PROFILE_INFOA {
    DWORD dwDockInfo;
    CHAR szHwProfileGuid[ 39 ];
    CHAR szHwProfileName[ 80 ];
} HW_PROFILE_INFOA, *LPHW_PROFILE_INFOA;
typedef struct tagHW_PROFILE_INFOW {
    DWORD dwDockInfo;
    WCHAR szHwProfileGuid[ 39 ];
    WCHAR szHwProfileName[ 80 ];
} HW_PROFILE_INFOW, *LPHW_PROFILE_INFOW;




typedef HW_PROFILE_INFOA HW_PROFILE_INFO;
typedef LPHW_PROFILE_INFOA LPHW_PROFILE_INFO;



__declspec(dllimport)
BOOL

GetCurrentHwProfileA (
     LPHW_PROFILE_INFOA lpHwProfileInfo
    );
__declspec(dllimport)
BOOL

GetCurrentHwProfileW (
     LPHW_PROFILE_INFOW lpHwProfileInfo
    );
__declspec(dllimport)
BOOL

QueryPerformanceCounter(
     LARGE_INTEGER *lpPerformanceCount
    );

__declspec(dllimport)
BOOL

QueryPerformanceFrequency(
     LARGE_INTEGER *lpFrequency
    );



__declspec(dllimport)
BOOL

GetVersionExA(
     LPOSVERSIONINFOA lpVersionInformation
    );
__declspec(dllimport)
BOOL

GetVersionExW(
     LPOSVERSIONINFOW lpVersionInformation
    );








__declspec(dllimport)
BOOL

VerifyVersionInfoA(
     LPOSVERSIONINFOEXA lpVersionInformation,
     DWORD dwTypeMask,
     DWORDLONG dwlConditionMask
    );
__declspec(dllimport)
BOOL

VerifyVersionInfoW(
     LPOSVERSIONINFOEXW lpVersionInformation,
     DWORD dwTypeMask,
     DWORDLONG dwlConditionMask
    );








__declspec(dllimport)
BOOL

GetProductInfo(
     DWORD dwOSMajorVersion,
     DWORD dwOSMinorVersion,
     DWORD dwSpMajorVersion,
     DWORD dwSpMinorVersion,
     PDWORD pdwReturnedProductType
    );
__inline  HRESULT HRESULT_FROM_WIN32(unsigned long x) { return (HRESULT)(x) <= 0 ? (HRESULT)(x) : (HRESULT) (((x) & 0x0000FFFF) | ( 7  << 16) | 0x80000000);}
typedef struct _SYSTEM_POWER_STATUS {
    BYTE ACLineStatus;
    BYTE BatteryFlag;
    BYTE BatteryLifePercent;
    BYTE Reserved1;
    DWORD BatteryLifeTime;
    DWORD BatteryFullLifeTime;
} SYSTEM_POWER_STATUS, *LPSYSTEM_POWER_STATUS;

BOOL

GetSystemPowerStatus(
     LPSYSTEM_POWER_STATUS lpSystemPowerStatus
    );

BOOL

SetSystemPowerState(
     BOOL fSuspend,
     BOOL fForce
    );








__declspec(dllimport)
BOOL

AllocateUserPhysicalPages(
     HANDLE hProcess,
     PULONG_PTR NumberOfPages,
     PULONG_PTR PageArray
    );



__declspec(dllimport)
BOOL

AllocateUserPhysicalPagesNuma(
     HANDLE hProcess,
     PULONG_PTR NumberOfPages,
     PULONG_PTR PageArray,
     DWORD nndPreferred
    );



__declspec(dllimport)
BOOL

FreeUserPhysicalPages(
     HANDLE hProcess,
     PULONG_PTR NumberOfPages,
     PULONG_PTR PageArray
    );

__declspec(dllimport)
BOOL

MapUserPhysicalPages(
     PVOID VirtualAddress,
     ULONG_PTR NumberOfPages,
     PULONG_PTR PageArray
    );

__declspec(dllimport)
BOOL

MapUserPhysicalPagesScatter(
     PVOID *VirtualAddresses,
     ULONG_PTR NumberOfPages,
     PULONG_PTR PageArray
    );

__declspec(dllimport)

HANDLE

CreateJobObjectA(
     LPSECURITY_ATTRIBUTES lpJobAttributes,
     LPCSTR lpName
    );
__declspec(dllimport)

HANDLE

CreateJobObjectW(
     LPSECURITY_ATTRIBUTES lpJobAttributes,
     LPCWSTR lpName
    );






__declspec(dllimport)

HANDLE

OpenJobObjectA(
     DWORD dwDesiredAccess,
     BOOL bInheritHandle,
     LPCSTR lpName
    );
__declspec(dllimport)

HANDLE

OpenJobObjectW(
     DWORD dwDesiredAccess,
     BOOL bInheritHandle,
     LPCWSTR lpName
    );






__declspec(dllimport)
BOOL

AssignProcessToJobObject(
     HANDLE hJob,
     HANDLE hProcess
    );

__declspec(dllimport)
BOOL

TerminateJobObject(
     HANDLE hJob,
     UINT uExitCode
    );

__declspec(dllimport)
BOOL

QueryInformationJobObject(
     HANDLE hJob,
     JOBOBJECTINFOCLASS JobObjectInformationClass,
     LPVOID lpJobObjectInformation,
     DWORD cbJobObjectInformationLength,
     LPDWORD lpReturnLength
    );

__declspec(dllimport)
BOOL

SetInformationJobObject(
     HANDLE hJob,
     JOBOBJECTINFOCLASS JobObjectInformationClass,
     LPVOID lpJobObjectInformation,
     DWORD cbJobObjectInformationLength
    );



__declspec(dllimport)
BOOL

IsProcessInJob (
     HANDLE ProcessHandle,
     HANDLE JobHandle,
     PBOOL Result
    );



__declspec(dllimport)
BOOL

CreateJobSet (
     ULONG NumJob,
     PJOB_SET_ARRAY UserJobSet,
     ULONG Flags);

__declspec(dllimport)

PVOID

AddVectoredExceptionHandler (
     ULONG First,
     PVECTORED_EXCEPTION_HANDLER Handler
    );

__declspec(dllimport)
ULONG

RemoveVectoredExceptionHandler (
     PVOID Handle
    );

__declspec(dllimport)

PVOID

AddVectoredContinueHandler (
     ULONG First,
     PVECTORED_EXCEPTION_HANDLER Handler
    );

__declspec(dllimport)
ULONG

RemoveVectoredContinueHandler (
     PVOID Handle
    );





__declspec(dllimport)

HANDLE

FindFirstVolumeA(
     LPSTR lpszVolumeName,
     DWORD cchBufferLength
    );
__declspec(dllimport)

HANDLE

FindFirstVolumeW(
     LPWSTR lpszVolumeName,
     DWORD cchBufferLength
    );






__declspec(dllimport)
BOOL

FindNextVolumeA(
     HANDLE hFindVolume,
     LPSTR lpszVolumeName,
     DWORD cchBufferLength
    );
__declspec(dllimport)
BOOL

FindNextVolumeW(
     HANDLE hFindVolume,
     LPWSTR lpszVolumeName,
     DWORD cchBufferLength
    );






__declspec(dllimport)
BOOL

FindVolumeClose(
     HANDLE hFindVolume
    );

__declspec(dllimport)

HANDLE

FindFirstVolumeMountPointA(
     LPCSTR lpszRootPathName,
     LPSTR lpszVolumeMountPoint,
     DWORD cchBufferLength
    );
__declspec(dllimport)

HANDLE

FindFirstVolumeMountPointW(
     LPCWSTR lpszRootPathName,
     LPWSTR lpszVolumeMountPoint,
     DWORD cchBufferLength
    );






__declspec(dllimport)
BOOL

FindNextVolumeMountPointA(
     HANDLE hFindVolumeMountPoint,
     LPSTR lpszVolumeMountPoint,
     DWORD cchBufferLength
    );
__declspec(dllimport)
BOOL

FindNextVolumeMountPointW(
     HANDLE hFindVolumeMountPoint,
     LPWSTR lpszVolumeMountPoint,
     DWORD cchBufferLength
    );






__declspec(dllimport)
BOOL

FindVolumeMountPointClose(
     HANDLE hFindVolumeMountPoint
    );

__declspec(dllimport)
BOOL

SetVolumeMountPointA(
     LPCSTR lpszVolumeMountPoint,
     LPCSTR lpszVolumeName
    );
__declspec(dllimport)
BOOL

SetVolumeMountPointW(
     LPCWSTR lpszVolumeMountPoint,
     LPCWSTR lpszVolumeName
    );






__declspec(dllimport)
BOOL

DeleteVolumeMountPointA(
     LPCSTR lpszVolumeMountPoint
    );
__declspec(dllimport)
BOOL

DeleteVolumeMountPointW(
     LPCWSTR lpszVolumeMountPoint
    );






__declspec(dllimport)
BOOL

GetVolumeNameForVolumeMountPointA(
     LPCSTR lpszVolumeMountPoint,
     LPSTR lpszVolumeName,
     DWORD cchBufferLength
    );
__declspec(dllimport)
BOOL

GetVolumeNameForVolumeMountPointW(
     LPCWSTR lpszVolumeMountPoint,
     LPWSTR lpszVolumeName,
     DWORD cchBufferLength
    );






__declspec(dllimport)
BOOL

GetVolumePathNameA(
     LPCSTR lpszFileName,
     LPSTR lpszVolumePathName,
     DWORD cchBufferLength
    );
__declspec(dllimport)
BOOL

GetVolumePathNameW(
     LPCWSTR lpszFileName,
     LPWSTR lpszVolumePathName,
     DWORD cchBufferLength
    );






__declspec(dllimport)
BOOL

GetVolumePathNamesForVolumeNameA(
     LPCSTR lpszVolumeName,
       LPCH lpszVolumePathNames,
     DWORD cchBufferLength,
     PDWORD lpcchReturnLength
    );
__declspec(dllimport)
BOOL

GetVolumePathNamesForVolumeNameW(
     LPCWSTR lpszVolumeName,
       LPWCH lpszVolumePathNames,
     DWORD cchBufferLength,
     PDWORD lpcchReturnLength
    );
typedef struct tagACTCTXA {
    ULONG cbSize;
    DWORD dwFlags;
    LPCSTR lpSource;
    USHORT wProcessorArchitecture;
    LANGID wLangId;
    LPCSTR lpAssemblyDirectory;
    LPCSTR lpResourceName;
    LPCSTR lpApplicationName;
    HMODULE hModule;
} ACTCTXA, *PACTCTXA;
typedef struct tagACTCTXW {
    ULONG cbSize;
    DWORD dwFlags;
    LPCWSTR lpSource;
    USHORT wProcessorArchitecture;
    LANGID wLangId;
    LPCWSTR lpAssemblyDirectory;
    LPCWSTR lpResourceName;
    LPCWSTR lpApplicationName;
    HMODULE hModule;
} ACTCTXW, *PACTCTXW;




typedef ACTCTXA ACTCTX;
typedef PACTCTXA PACTCTX;


typedef const ACTCTXA *PCACTCTXA;
typedef const ACTCTXW *PCACTCTXW;



typedef PCACTCTXA PCACTCTX;




__declspec(dllimport)

HANDLE

CreateActCtxA(
     PCACTCTXA pActCtx
    );
__declspec(dllimport)

HANDLE

CreateActCtxW(
     PCACTCTXW pActCtx
    );






__declspec(dllimport)
void

AddRefActCtx(
     HANDLE hActCtx
    );


__declspec(dllimport)
void

ReleaseActCtx(
     HANDLE hActCtx
    );

__declspec(dllimport)
BOOL

ZombifyActCtx(
     HANDLE hActCtx
    );


__declspec(dllimport)
BOOL

ActivateActCtx(
     HANDLE hActCtx,
     ULONG_PTR *lpCookie
    );




__declspec(dllimport)
BOOL

DeactivateActCtx(
     DWORD dwFlags,
     ULONG_PTR ulCookie
    );

__declspec(dllimport)
BOOL

GetCurrentActCtx(
     HANDLE *lphActCtx);


typedef struct tagACTCTX_SECTION_KEYED_DATA_2600 {
    ULONG cbSize;
    ULONG ulDataFormatVersion;
    PVOID lpData;
    ULONG ulLength;
    PVOID lpSectionGlobalData;
    ULONG ulSectionGlobalDataLength;
    PVOID lpSectionBase;
    ULONG ulSectionTotalLength;
    HANDLE hActCtx;
    ULONG ulAssemblyRosterIndex;
} ACTCTX_SECTION_KEYED_DATA_2600, *PACTCTX_SECTION_KEYED_DATA_2600;
typedef const ACTCTX_SECTION_KEYED_DATA_2600 * PCACTCTX_SECTION_KEYED_DATA_2600;

typedef struct tagACTCTX_SECTION_KEYED_DATA_ASSEMBLY_METADATA {
    PVOID lpInformation;
    PVOID lpSectionBase;
    ULONG ulSectionLength;
    PVOID lpSectionGlobalDataBase;
    ULONG ulSectionGlobalDataLength;
} ACTCTX_SECTION_KEYED_DATA_ASSEMBLY_METADATA, *PACTCTX_SECTION_KEYED_DATA_ASSEMBLY_METADATA;
typedef const ACTCTX_SECTION_KEYED_DATA_ASSEMBLY_METADATA *PCACTCTX_SECTION_KEYED_DATA_ASSEMBLY_METADATA;

typedef struct tagACTCTX_SECTION_KEYED_DATA {
    ULONG cbSize;
    ULONG ulDataFormatVersion;
    PVOID lpData;
    ULONG ulLength;
    PVOID lpSectionGlobalData;
    ULONG ulSectionGlobalDataLength;
    PVOID lpSectionBase;
    ULONG ulSectionTotalLength;
    HANDLE hActCtx;
    ULONG ulAssemblyRosterIndex;

    ULONG ulFlags;
    ACTCTX_SECTION_KEYED_DATA_ASSEMBLY_METADATA AssemblyMetadata;
} ACTCTX_SECTION_KEYED_DATA, *PACTCTX_SECTION_KEYED_DATA;
typedef const ACTCTX_SECTION_KEYED_DATA * PCACTCTX_SECTION_KEYED_DATA;







__declspec(dllimport)
BOOL

FindActCtxSectionStringA(
     DWORD dwFlags,
     const GUID *lpExtensionGuid,
     ULONG ulSectionId,
     LPCSTR lpStringToFind,
     PACTCTX_SECTION_KEYED_DATA ReturnedData
    );
__declspec(dllimport)
BOOL

FindActCtxSectionStringW(
     DWORD dwFlags,
     const GUID *lpExtensionGuid,
     ULONG ulSectionId,
     LPCWSTR lpStringToFind,
     PACTCTX_SECTION_KEYED_DATA ReturnedData
    );






__declspec(dllimport)
BOOL

FindActCtxSectionGuid(
     DWORD dwFlags,
     const GUID *lpExtensionGuid,
     ULONG ulSectionId,
     const GUID *lpGuidToFind,
     PACTCTX_SECTION_KEYED_DATA ReturnedData
    );





typedef struct _ACTIVATION_CONTEXT_BASIC_INFORMATION {
    HANDLE hActCtx;
    DWORD dwFlags;
} ACTIVATION_CONTEXT_BASIC_INFORMATION, *PACTIVATION_CONTEXT_BASIC_INFORMATION;

typedef const struct _ACTIVATION_CONTEXT_BASIC_INFORMATION *PCACTIVATION_CONTEXT_BASIC_INFORMATION;
__declspec(dllimport)
BOOL

QueryActCtxW(
     DWORD dwFlags,
     HANDLE hActCtx,
     PVOID pvSubInstance,
     ULONG ulInfoClass,
     PVOID pvBuffer,
     SIZE_T cbBuffer,
     SIZE_T *pcbWrittenOrRequired
    );

typedef BOOL (  * PQUERYACTCTXW_FUNC)(
     DWORD dwFlags,
     HANDLE hActCtx,
     PVOID pvSubInstance,
     ULONG ulInfoClass,
     PVOID pvBuffer,
     SIZE_T cbBuffer,
     SIZE_T *pcbWrittenOrRequired
    );




__declspec(dllimport)
BOOL

ProcessIdToSessionId(
     DWORD dwProcessId,
     DWORD *pSessionId
    );



__declspec(dllimport)
DWORD

WTSGetActiveConsoleSessionId(
    void
    );

__declspec(dllimport)
BOOL

IsWow64Process(
     HANDLE hProcess,
     PBOOL Wow64Process
    );



__declspec(dllimport)
BOOL

GetLogicalProcessorInformation(
     PSYSTEM_LOGICAL_PROCESSOR_INFORMATION Buffer,
     PDWORD ReturnedLength
    );





__declspec(dllimport)
BOOL

GetNumaHighestNodeNumber(
     PULONG HighestNodeNumber
    );

__declspec(dllimport)
BOOL

GetNumaProcessorNode(
     UCHAR Processor,
     PUCHAR NodeNumber
    );

__declspec(dllimport)
BOOL

GetNumaNodeProcessorMask(
     UCHAR Node,
     PULONGLONG ProcessorMask
    );

__declspec(dllimport)
BOOL

GetNumaAvailableMemoryNode(
     UCHAR Node,
     PULONGLONG AvailableBytes
    );



__declspec(dllimport)
BOOL

GetNumaProximityNode(
     ULONG ProximityId,
     PUCHAR NodeNumber
    );






typedef DWORD (  *APPLICATION_RECOVERY_CALLBACK)(PVOID pvParameter);
__declspec(dllimport)
HRESULT

RegisterApplicationRecoveryCallback(
     APPLICATION_RECOVERY_CALLBACK pRecoveyCallback,
     PVOID pvParameter,
     DWORD dwPingInterval,
     DWORD dwFlags
    );

__declspec(dllimport)
HRESULT

UnregisterApplicationRecoveryCallback(void);

__declspec(dllimport)
HRESULT

RegisterApplicationRestart(
     PCWSTR pwzCommandline,
     DWORD dwFlags
    );

__declspec(dllimport)
HRESULT

UnregisterApplicationRestart(void);





__declspec(dllimport)
HRESULT

GetApplicationRecoveryCallback(
     HANDLE hProcess,
     APPLICATION_RECOVERY_CALLBACK* pRecoveryCallback,
     PVOID* ppvParameter,
     PDWORD pdwPingInterval,
     PDWORD pdwFlags
    );

__declspec(dllimport)
HRESULT

GetApplicationRestartSettings(
     HANDLE hProcess,
     PWSTR pwzCommandline,
     PDWORD pcchSize,
     PDWORD pdwFlags
    );

__declspec(dllimport)
HRESULT

ApplicationRecoveryInProgress(
     PBOOL pbCancelled
    );

__declspec(dllimport)
void

ApplicationRecoveryFinished(
     BOOL bSuccess
    );


typedef enum _FILE_INFO_BY_HANDLE_CLASS {
    FileBasicInfo,
    FileStandardInfo,
    FileNameInfo,
    FileRenameInfo,
    FileDispositionInfo,
    FileAllocationInfo,
    FileEndOfFileInfo,
    FileStreamInfo,
    FileCompressionInfo,
    FileAttributeTagInfo,
    FileIdBothDirectoryInfo,
    FileIdBothDirectoryRestartInfo,
    FileIoPriorityHintInfo,
    MaximumFileInfoByHandleClass
} FILE_INFO_BY_HANDLE_CLASS, *PFILE_INFO_BY_HANDLE_CLASS;

typedef struct _FILE_BASIC_INFO {
    LARGE_INTEGER CreationTime;
    LARGE_INTEGER LastAccessTime;
    LARGE_INTEGER LastWriteTime;
    LARGE_INTEGER ChangeTime;
    DWORD FileAttributes;
} FILE_BASIC_INFO, *PFILE_BASIC_INFO;

typedef struct _FILE_STANDARD_INFO {
    LARGE_INTEGER AllocationSize;
    LARGE_INTEGER EndOfFile;
    DWORD NumberOfLinks;
    BOOLEAN DeletePending;
    BOOLEAN Directory;
} FILE_STANDARD_INFO, *PFILE_STANDARD_INFO;

typedef struct _FILE_NAME_INFO {
    DWORD FileNameLength;
    WCHAR FileName[1];
} FILE_NAME_INFO, *PFILE_NAME_INFO;

typedef struct _FILE_RENAME_INFO {
    BOOLEAN ReplaceIfExists;
    HANDLE RootDirectory;
    DWORD FileNameLength;
    WCHAR FileName[1];
} FILE_RENAME_INFO, *PFILE_RENAME_INFO;

typedef struct _FILE_ALLOCATION_INFO {
    LARGE_INTEGER AllocationSize;
} FILE_ALLOCATION_INFO, *PFILE_ALLOCATION_INFO;

typedef struct _FILE_END_OF_FILE_INFO {
    LARGE_INTEGER EndOfFile;
} FILE_END_OF_FILE_INFO, *PFILE_END_OF_FILE_INFO;

typedef struct _FILE_STREAM_INFO {
    DWORD NextEntryOffset;
    DWORD StreamNameLength;
    LARGE_INTEGER StreamSize;
    LARGE_INTEGER StreamAllocationSize;
    WCHAR StreamName[1];
} FILE_STREAM_INFO, *PFILE_STREAM_INFO;

typedef struct _FILE_COMPRESSION_INFO {
    LARGE_INTEGER CompressedFileSize;
    WORD CompressionFormat;
    UCHAR CompressionUnitShift;
    UCHAR ChunkShift;
    UCHAR ClusterShift;
    UCHAR Reserved[3];
} FILE_COMPRESSION_INFO, *PFILE_COMPRESSION_INFO;

typedef struct _FILE_ATTRIBUTE_TAG_INFO {
    DWORD FileAttributes;
    DWORD ReparseTag;
} FILE_ATTRIBUTE_TAG_INFO, *PFILE_ATTRIBUTE_TAG_INFO;

typedef struct _FILE_DISPOSITION_INFO {
    BOOLEAN  DeleteFileA ;
} FILE_DISPOSITION_INFO, *PFILE_DISPOSITION_INFO;

typedef struct _FILE_ID_BOTH_DIR_INFO {
    DWORD NextEntryOffset;
    DWORD FileIndex;
    LARGE_INTEGER CreationTime;
    LARGE_INTEGER LastAccessTime;
    LARGE_INTEGER LastWriteTime;
    LARGE_INTEGER ChangeTime;
    LARGE_INTEGER EndOfFile;
    LARGE_INTEGER AllocationSize;
    DWORD FileAttributes;
    DWORD FileNameLength;
    DWORD EaSize;
    CCHAR ShortNameLength;
    WCHAR ShortName[12];
    LARGE_INTEGER FileId;
    WCHAR FileName[1];
} FILE_ID_BOTH_DIR_INFO, *PFILE_ID_BOTH_DIR_INFO;

typedef enum _PRIORITY_HINT {
      IoPriorityHintVeryLow = 0,
      IoPriorityHintLow,
      IoPriorityHintNormal,
      MaximumIoPriorityHintType
} PRIORITY_HINT;

typedef struct _FILE_IO_PRIORITY_HINT_INFO {
    PRIORITY_HINT PriorityHint;
} FILE_IO_PRIORITY_HINT_INFO, *PFILE_IO_PRIORITY_HINT_INFO;

BOOL

SetFileInformationByHandle(
     HANDLE hFile,
     FILE_INFO_BY_HANDLE_CLASS FileInformationClass,
     LPVOID lpFileInformation,
     DWORD dwBufferSize
);

BOOL

GetFileInformationByHandleEx(
     HANDLE hFile,
     FILE_INFO_BY_HANDLE_CLASS FileInformationClass,
     LPVOID lpFileInformation,
     DWORD dwBufferSize
);

typedef enum _FILE_ID_TYPE {
      FileIdType,
      ObjectIdType,
      MaximumFileIdType
} FILE_ID_TYPE, *PFILE_ID_TYPE;

typedef struct FILE_ID_DESCRIPTOR {
    DWORD dwSize;
    FILE_ID_TYPE Type;
    union {
        LARGE_INTEGER FileId;
        GUID ObjectId;
    }  u ;
} FILE_ID_DESCRIPTOR, *LPFILE_ID_DESCRIPTOR;


HANDLE

OpenFileById (
     HANDLE hVolumeHint,
     LPFILE_ID_DESCRIPTOR lpFileId,
     DWORD dwDesiredAccess,
     DWORD dwShareMode,
     LPSECURITY_ATTRIBUTES lpSecurityAttributes,
     DWORD dwFlagsAndAttributes
    );
BOOLEAN

CreateSymbolicLinkA (
     LPCSTR lpSymlinkFileName,
     LPCSTR lpTargetFileName,
     DWORD dwFlags
    );
BOOLEAN

CreateSymbolicLinkW (
     LPCWSTR lpSymlinkFileName,
     LPCWSTR lpTargetFileName,
     DWORD dwFlags
    );






BOOLEAN

CreateSymbolicLinkTransactedA (
     LPCSTR lpSymlinkFileName,
     LPCSTR lpTargetFileName,
     DWORD dwFlags,
     HANDLE hTransaction
    );
BOOLEAN

CreateSymbolicLinkTransactedW (
     LPCWSTR lpSymlinkFileName,
     LPCWSTR lpTargetFileName,
     DWORD dwFlags,
     HANDLE hTransaction
    );






DWORD

GetFinalPathNameByHandleA (
     HANDLE hFile,
     LPSTR lpszFilePath,
     DWORD cchFilePath,
     DWORD dwFlags
);
DWORD

GetFinalPathNameByHandleW (
     HANDLE hFile,
     LPWSTR lpszFilePath,
     DWORD cchFilePath,
     DWORD dwFlags
);
__declspec(dllimport)
BOOL

QueryActCtxSettingsW(
     DWORD dwFlags,
     HANDLE hActCtx,
     PCWSTR settingsNameSpace,
     PCWSTR settingName,
     PWSTR pvBuffer,
     SIZE_T dwBuffer,
     SIZE_T *pdwWrittenOrRequired
    );





__declspec(dllimport)
BOOL

ReplacePartitionUnit (
     PWSTR TargetPartition,
     PWSTR SparePartition,
     ULONG Flags
    );






__declspec(dllimport)
BOOL

AddSecureMemoryCacheCallback(
       PSECURE_MEMORY_CACHE_CALLBACK pfnCallBack
    );

__declspec(dllimport)
BOOL

RemoveSecureMemoryCacheCallback(
       PSECURE_MEMORY_CACHE_CALLBACK pfnCallBack
    );
typedef struct _DRAWPATRECT {
        POINT ptPosition;
        POINT ptSize;
        WORD wStyle;
        WORD wPattern;
} DRAWPATRECT, *PDRAWPATRECT;
typedef struct _PSINJECTDATA {

    DWORD DataBytes;
    WORD InjectionPoint;
    WORD PageNumber;



} PSINJECTDATA, *PPSINJECTDATA;
typedef struct _PSFEATURE_OUTPUT {

    BOOL bPageIndependent;
    BOOL bSetPageDevice;

} PSFEATURE_OUTPUT, *PPSFEATURE_OUTPUT;
typedef struct _PSFEATURE_CUSTPAPER {

    LONG lOrientation;
    LONG lWidth;
    LONG lHeight;
    LONG lWidthOffset;
    LONG lHeightOffset;

} PSFEATURE_CUSTPAPER, *PPSFEATURE_CUSTPAPER;
typedef struct tagXFORM
  {
    FLOAT eM11;
    FLOAT eM12;
    FLOAT eM21;
    FLOAT eM22;
    FLOAT eDx;
    FLOAT eDy;
  } XFORM, *PXFORM,   *LPXFORM;


typedef struct tagBITMAP
  {
    LONG bmType;
    LONG bmWidth;
    LONG bmHeight;
    LONG bmWidthBytes;
    WORD bmPlanes;
    WORD bmBitsPixel;
    LPVOID bmBits;
  } BITMAP, *PBITMAP,   *NPBITMAP,   *LPBITMAP;
typedef struct tagRGBTRIPLE {
        BYTE rgbtBlue;
        BYTE rgbtGreen;
        BYTE rgbtRed;
} RGBTRIPLE, *PRGBTRIPLE,   *NPRGBTRIPLE,   *LPRGBTRIPLE;

typedef struct tagRGBQUAD {
        BYTE rgbBlue;
        BYTE rgbGreen;
        BYTE rgbRed;
        BYTE rgbReserved;
} RGBQUAD;
typedef RGBQUAD  * LPRGBQUAD;
typedef LONG LCSCSTYPE;


typedef LONG LCSGAMUTMATCH;
typedef long FXPT16DOT16,   *LPFXPT16DOT16;
typedef long FXPT2DOT30,   *LPFXPT2DOT30;




typedef struct tagCIEXYZ
{
        FXPT2DOT30 ciexyzX;
        FXPT2DOT30 ciexyzY;
        FXPT2DOT30 ciexyzZ;
} CIEXYZ;
typedef CIEXYZ   *LPCIEXYZ;

typedef struct tagICEXYZTRIPLE
{
        CIEXYZ ciexyzRed;
        CIEXYZ ciexyzGreen;
        CIEXYZ ciexyzBlue;
} CIEXYZTRIPLE;
typedef CIEXYZTRIPLE   *LPCIEXYZTRIPLE;






typedef struct tagLOGCOLORSPACEA {
    DWORD lcsSignature;
    DWORD lcsVersion;
    DWORD lcsSize;
    LCSCSTYPE lcsCSType;
    LCSGAMUTMATCH lcsIntent;
    CIEXYZTRIPLE lcsEndpoints;
    DWORD lcsGammaRed;
    DWORD lcsGammaGreen;
    DWORD lcsGammaBlue;
    CHAR lcsFilename[ 260 ];
} LOGCOLORSPACEA, *LPLOGCOLORSPACEA;
typedef struct tagLOGCOLORSPACEW {
    DWORD lcsSignature;
    DWORD lcsVersion;
    DWORD lcsSize;
    LCSCSTYPE lcsCSType;
    LCSGAMUTMATCH lcsIntent;
    CIEXYZTRIPLE lcsEndpoints;
    DWORD lcsGammaRed;
    DWORD lcsGammaGreen;
    DWORD lcsGammaBlue;
    WCHAR lcsFilename[ 260 ];
} LOGCOLORSPACEW, *LPLOGCOLORSPACEW;




typedef LOGCOLORSPACEA LOGCOLORSPACE;
typedef LPLOGCOLORSPACEA LPLOGCOLORSPACE;





typedef struct tagBITMAPCOREHEADER {
        DWORD bcSize;
        WORD bcWidth;
        WORD bcHeight;
        WORD bcPlanes;
        WORD bcBitCount;
} BITMAPCOREHEADER,   *LPBITMAPCOREHEADER, *PBITMAPCOREHEADER;

typedef struct tagBITMAPINFOHEADER{
        DWORD biSize;
        LONG biWidth;
        LONG biHeight;
        WORD biPlanes;
        WORD biBitCount;
        DWORD biCompression;
        DWORD biSizeImage;
        LONG biXPelsPerMeter;
        LONG biYPelsPerMeter;
        DWORD biClrUsed;
        DWORD biClrImportant;
} BITMAPINFOHEADER,   *LPBITMAPINFOHEADER, *PBITMAPINFOHEADER;


typedef struct {
        DWORD bV4Size;
        LONG bV4Width;
        LONG bV4Height;
        WORD bV4Planes;
        WORD bV4BitCount;
        DWORD bV4V4Compression;
        DWORD bV4SizeImage;
        LONG bV4XPelsPerMeter;
        LONG bV4YPelsPerMeter;
        DWORD bV4ClrUsed;
        DWORD bV4ClrImportant;
        DWORD bV4RedMask;
        DWORD bV4GreenMask;
        DWORD bV4BlueMask;
        DWORD bV4AlphaMask;
        DWORD bV4CSType;
        CIEXYZTRIPLE bV4Endpoints;
        DWORD bV4GammaRed;
        DWORD bV4GammaGreen;
        DWORD bV4GammaBlue;
} BITMAPV4HEADER,   *LPBITMAPV4HEADER, *PBITMAPV4HEADER;



typedef struct {
        DWORD bV5Size;
        LONG bV5Width;
        LONG bV5Height;
        WORD bV5Planes;
        WORD bV5BitCount;
        DWORD bV5Compression;
        DWORD bV5SizeImage;
        LONG bV5XPelsPerMeter;
        LONG bV5YPelsPerMeter;
        DWORD bV5ClrUsed;
        DWORD bV5ClrImportant;
        DWORD bV5RedMask;
        DWORD bV5GreenMask;
        DWORD bV5BlueMask;
        DWORD bV5AlphaMask;
        DWORD bV5CSType;
        CIEXYZTRIPLE bV5Endpoints;
        DWORD bV5GammaRed;
        DWORD bV5GammaGreen;
        DWORD bV5GammaBlue;
        DWORD bV5Intent;
        DWORD bV5ProfileData;
        DWORD bV5ProfileSize;
        DWORD bV5Reserved;
} BITMAPV5HEADER,   *LPBITMAPV5HEADER, *PBITMAPV5HEADER;
typedef struct tagBITMAPINFO {
    BITMAPINFOHEADER bmiHeader;
    RGBQUAD bmiColors[1];
} BITMAPINFO,   *LPBITMAPINFO, *PBITMAPINFO;

typedef struct tagBITMAPCOREINFO {
    BITMAPCOREHEADER bmciHeader;
    RGBTRIPLE bmciColors[1];
} BITMAPCOREINFO,   *LPBITMAPCOREINFO, *PBITMAPCOREINFO;
typedef struct tagBITMAPFILEHEADER {
        WORD bfType;
        DWORD bfSize;
        WORD bfReserved1;
        WORD bfReserved2;
        DWORD bfOffBits;
} BITMAPFILEHEADER,   *LPBITMAPFILEHEADER, *PBITMAPFILEHEADER;





typedef struct tagFONTSIGNATURE
{
    DWORD fsUsb[4];
    DWORD fsCsb[2];
} FONTSIGNATURE, *PFONTSIGNATURE,  *LPFONTSIGNATURE;

typedef struct tagCHARSETINFO
{
    UINT ciCharset;
    UINT ciACP;
    FONTSIGNATURE fs;
} CHARSETINFO, *PCHARSETINFO,   *NPCHARSETINFO,   *LPCHARSETINFO;








typedef struct tagLOCALESIGNATURE
{
    DWORD lsUsb[4];
    DWORD lsCsbDefault[2];
    DWORD lsCsbSupported[2];
} LOCALESIGNATURE, *PLOCALESIGNATURE,  *LPLOCALESIGNATURE;








typedef struct tagHANDLETABLE
  {
    HGDIOBJ objectHandle[1];
  } HANDLETABLE, *PHANDLETABLE,   *LPHANDLETABLE;

typedef struct tagMETARECORD
  {
    DWORD rdSize;
    WORD rdFunction;
    WORD rdParm[1];
  } METARECORD;
typedef struct tagMETARECORD   *PMETARECORD;
typedef struct tagMETARECORD     *LPMETARECORD;

typedef struct tagMETAFILEPICT
  {
    LONG mm;
    LONG xExt;
    LONG yExt;
    HMETAFILE hMF;
  } METAFILEPICT,   *LPMETAFILEPICT;
typedef struct tagMETAHEADER
{
    WORD mtType;
    WORD mtHeaderSize;
    WORD mtVersion;
    DWORD mtSize;
    WORD mtNoObjects;
    DWORD mtMaxRecord;
    WORD mtNoParameters;
} METAHEADER;
typedef struct tagMETAHEADER   *PMETAHEADER;
typedef struct tagMETAHEADER     *LPMETAHEADER;


typedef struct tagENHMETARECORD
{
    DWORD iType;
    DWORD nSize;
    DWORD dParm[1];
} ENHMETARECORD, *PENHMETARECORD, *LPENHMETARECORD;

typedef struct tagENHMETAHEADER
{
    DWORD iType;
    DWORD nSize;

    RECTL rclBounds;
    RECTL rclFrame;
    DWORD dSignature;
    DWORD nVersion;
    DWORD nBytes;
    DWORD nRecords;
    WORD nHandles;

    WORD sReserved;
    DWORD nDescription;

    DWORD offDescription;

    DWORD nPalEntries;
    SIZEL szlDevice;
    SIZEL szlMillimeters;

    DWORD cbPixelFormat;

    DWORD offPixelFormat;

    DWORD bOpenGL;



    SIZEL szlMicrometers;


} ENHMETAHEADER, *PENHMETAHEADER, *LPENHMETAHEADER;
    typedef BYTE BCHAR;
typedef struct tagTEXTMETRICA
{
    LONG tmHeight;
    LONG tmAscent;
    LONG tmDescent;
    LONG tmInternalLeading;
    LONG tmExternalLeading;
    LONG tmAveCharWidth;
    LONG tmMaxCharWidth;
    LONG tmWeight;
    LONG tmOverhang;
    LONG tmDigitizedAspectX;
    LONG tmDigitizedAspectY;
    BYTE tmFirstChar;
    BYTE tmLastChar;
    BYTE tmDefaultChar;
    BYTE tmBreakChar;
    BYTE tmItalic;
    BYTE tmUnderlined;
    BYTE tmStruckOut;
    BYTE tmPitchAndFamily;
    BYTE tmCharSet;
} TEXTMETRICA, *PTEXTMETRICA,   *NPTEXTMETRICA,   *LPTEXTMETRICA;
typedef struct tagTEXTMETRICW
{
    LONG tmHeight;
    LONG tmAscent;
    LONG tmDescent;
    LONG tmInternalLeading;
    LONG tmExternalLeading;
    LONG tmAveCharWidth;
    LONG tmMaxCharWidth;
    LONG tmWeight;
    LONG tmOverhang;
    LONG tmDigitizedAspectX;
    LONG tmDigitizedAspectY;
    WCHAR tmFirstChar;
    WCHAR tmLastChar;
    WCHAR tmDefaultChar;
    WCHAR tmBreakChar;
    BYTE tmItalic;
    BYTE tmUnderlined;
    BYTE tmStruckOut;
    BYTE tmPitchAndFamily;
    BYTE tmCharSet;
} TEXTMETRICW, *PTEXTMETRICW,   *NPTEXTMETRICW,   *LPTEXTMETRICW;






typedef TEXTMETRICA TEXTMETRIC;
typedef PTEXTMETRICA PTEXTMETRIC;
typedef NPTEXTMETRICA NPTEXTMETRIC;
typedef LPTEXTMETRICA LPTEXTMETRIC;
typedef struct tagNEWTEXTMETRICA
{
    LONG tmHeight;
    LONG tmAscent;
    LONG tmDescent;
    LONG tmInternalLeading;
    LONG tmExternalLeading;
    LONG tmAveCharWidth;
    LONG tmMaxCharWidth;
    LONG tmWeight;
    LONG tmOverhang;
    LONG tmDigitizedAspectX;
    LONG tmDigitizedAspectY;
    BYTE tmFirstChar;
    BYTE tmLastChar;
    BYTE tmDefaultChar;
    BYTE tmBreakChar;
    BYTE tmItalic;
    BYTE tmUnderlined;
    BYTE tmStruckOut;
    BYTE tmPitchAndFamily;
    BYTE tmCharSet;
    DWORD ntmFlags;
    UINT ntmSizeEM;
    UINT ntmCellHeight;
    UINT ntmAvgWidth;
} NEWTEXTMETRICA, *PNEWTEXTMETRICA,   *NPNEWTEXTMETRICA,   *LPNEWTEXTMETRICA;
typedef struct tagNEWTEXTMETRICW
{
    LONG tmHeight;
    LONG tmAscent;
    LONG tmDescent;
    LONG tmInternalLeading;
    LONG tmExternalLeading;
    LONG tmAveCharWidth;
    LONG tmMaxCharWidth;
    LONG tmWeight;
    LONG tmOverhang;
    LONG tmDigitizedAspectX;
    LONG tmDigitizedAspectY;
    WCHAR tmFirstChar;
    WCHAR tmLastChar;
    WCHAR tmDefaultChar;
    WCHAR tmBreakChar;
    BYTE tmItalic;
    BYTE tmUnderlined;
    BYTE tmStruckOut;
    BYTE tmPitchAndFamily;
    BYTE tmCharSet;
    DWORD ntmFlags;
    UINT ntmSizeEM;
    UINT ntmCellHeight;
    UINT ntmAvgWidth;
} NEWTEXTMETRICW, *PNEWTEXTMETRICW,   *NPNEWTEXTMETRICW,   *LPNEWTEXTMETRICW;






typedef NEWTEXTMETRICA NEWTEXTMETRIC;
typedef PNEWTEXTMETRICA PNEWTEXTMETRIC;
typedef NPNEWTEXTMETRICA NPNEWTEXTMETRIC;
typedef LPNEWTEXTMETRICA LPNEWTEXTMETRIC;


typedef struct tagNEWTEXTMETRICEXA
{
    NEWTEXTMETRICA ntmTm;
    FONTSIGNATURE ntmFontSig;
}NEWTEXTMETRICEXA;
typedef struct tagNEWTEXTMETRICEXW
{
    NEWTEXTMETRICW ntmTm;
    FONTSIGNATURE ntmFontSig;
}NEWTEXTMETRICEXW;



typedef NEWTEXTMETRICEXA NEWTEXTMETRICEX;







typedef struct tagPELARRAY
  {
    LONG paXCount;
    LONG paYCount;
    LONG paXExt;
    LONG paYExt;
    BYTE paRGBs;
  } PELARRAY, *PPELARRAY,   *NPPELARRAY,   *LPPELARRAY;


typedef struct tagLOGBRUSH
  {
    UINT lbStyle;
    COLORREF lbColor;
    ULONG_PTR lbHatch;
  } LOGBRUSH, *PLOGBRUSH,   *NPLOGBRUSH,   *LPLOGBRUSH;

typedef struct tagLOGBRUSH32
  {
    UINT lbStyle;
    COLORREF lbColor;
    ULONG lbHatch;
  } LOGBRUSH32, *PLOGBRUSH32,   *NPLOGBRUSH32,   *LPLOGBRUSH32;

typedef LOGBRUSH PATTERN;
typedef PATTERN *PPATTERN;
typedef PATTERN   *NPPATTERN;
typedef PATTERN   *LPPATTERN;


typedef struct tagLOGPEN
  {
    UINT lopnStyle;
    POINT lopnWidth;
    COLORREF lopnColor;
  } LOGPEN, *PLOGPEN,   *NPLOGPEN,   *LPLOGPEN;

typedef struct tagEXTLOGPEN {
    DWORD elpPenStyle;
    DWORD elpWidth;
    UINT elpBrushStyle;
    COLORREF elpColor;
    ULONG_PTR elpHatch;
    DWORD elpNumEntries;
    DWORD elpStyleEntry[1];
} EXTLOGPEN, *PEXTLOGPEN,   *NPEXTLOGPEN,   *LPEXTLOGPEN;



typedef struct tagPALETTEENTRY {
    BYTE peRed;
    BYTE peGreen;
    BYTE peBlue;
    BYTE peFlags;
} PALETTEENTRY, *PPALETTEENTRY,   *LPPALETTEENTRY;





typedef struct tagLOGPALETTE {
    WORD palVersion;
    WORD palNumEntries;
     PALETTEENTRY palPalEntry[1];
} LOGPALETTE, *PLOGPALETTE,   *NPLOGPALETTE,   *LPLOGPALETTE;






typedef struct tagLOGFONTA
{
    LONG lfHeight;
    LONG lfWidth;
    LONG lfEscapement;
    LONG lfOrientation;
    LONG lfWeight;
    BYTE lfItalic;
    BYTE lfUnderline;
    BYTE lfStrikeOut;
    BYTE lfCharSet;
    BYTE lfOutPrecision;
    BYTE lfClipPrecision;
    BYTE lfQuality;
    BYTE lfPitchAndFamily;
    CHAR lfFaceName[ 32 ];
} LOGFONTA, *PLOGFONTA,   *NPLOGFONTA,   *LPLOGFONTA;
typedef struct tagLOGFONTW
{
    LONG lfHeight;
    LONG lfWidth;
    LONG lfEscapement;
    LONG lfOrientation;
    LONG lfWeight;
    BYTE lfItalic;
    BYTE lfUnderline;
    BYTE lfStrikeOut;
    BYTE lfCharSet;
    BYTE lfOutPrecision;
    BYTE lfClipPrecision;
    BYTE lfQuality;
    BYTE lfPitchAndFamily;
    WCHAR lfFaceName[ 32 ];
} LOGFONTW, *PLOGFONTW,   *NPLOGFONTW,   *LPLOGFONTW;






typedef LOGFONTA LOGFONT;
typedef PLOGFONTA PLOGFONT;
typedef NPLOGFONTA NPLOGFONT;
typedef LPLOGFONTA LPLOGFONT;





typedef struct tagENUMLOGFONTA
{
    LOGFONTA elfLogFont;
    BYTE elfFullName[ 64 ];
    BYTE elfStyle[ 32 ];
} ENUMLOGFONTA,  * LPENUMLOGFONTA;

typedef struct tagENUMLOGFONTW
{
    LOGFONTW elfLogFont;
    WCHAR elfFullName[ 64 ];
    WCHAR elfStyle[ 32 ];
} ENUMLOGFONTW,  * LPENUMLOGFONTW;




typedef ENUMLOGFONTA ENUMLOGFONT;
typedef LPENUMLOGFONTA LPENUMLOGFONT;



typedef struct tagENUMLOGFONTEXA
{
    LOGFONTA elfLogFont;
    BYTE elfFullName[ 64 ];
    BYTE elfStyle[ 32 ];
    BYTE elfScript[ 32 ];
} ENUMLOGFONTEXA,   *LPENUMLOGFONTEXA;
typedef struct tagENUMLOGFONTEXW
{
    LOGFONTW elfLogFont;
    WCHAR elfFullName[ 64 ];
    WCHAR elfStyle[ 32 ];
    WCHAR elfScript[ 32 ];
} ENUMLOGFONTEXW,   *LPENUMLOGFONTEXW;




typedef ENUMLOGFONTEXA ENUMLOGFONTEX;
typedef LPENUMLOGFONTEXA LPENUMLOGFONTEX;
typedef struct tagPANOSE
{
    BYTE bFamilyType;
    BYTE bSerifStyle;
    BYTE bWeight;
    BYTE bProportion;
    BYTE bContrast;
    BYTE bStrokeVariation;
    BYTE bArmStyle;
    BYTE bLetterform;
    BYTE bMidline;
    BYTE bXHeight;
} PANOSE, * LPPANOSE;
typedef struct tagEXTLOGFONTA {
    LOGFONTA elfLogFont;
    BYTE elfFullName[ 64 ];
    BYTE elfStyle[ 32 ];
    DWORD elfVersion;
    DWORD elfStyleSize;
    DWORD elfMatch;
    DWORD elfReserved;
    BYTE elfVendorId[ 4 ];
    DWORD elfCulture;
    PANOSE elfPanose;
} EXTLOGFONTA, *PEXTLOGFONTA,   *NPEXTLOGFONTA,   *LPEXTLOGFONTA;
typedef struct tagEXTLOGFONTW {
    LOGFONTW elfLogFont;
    WCHAR elfFullName[ 64 ];
    WCHAR elfStyle[ 32 ];
    DWORD elfVersion;
    DWORD elfStyleSize;
    DWORD elfMatch;
    DWORD elfReserved;
    BYTE elfVendorId[ 4 ];
    DWORD elfCulture;
    PANOSE elfPanose;
} EXTLOGFONTW, *PEXTLOGFONTW,   *NPEXTLOGFONTW,   *LPEXTLOGFONTW;






typedef EXTLOGFONTA EXTLOGFONT;
typedef PEXTLOGFONTA PEXTLOGFONT;
typedef NPEXTLOGFONTA NPEXTLOGFONT;
typedef LPEXTLOGFONTA LPEXTLOGFONT;
typedef struct _devicemodeA {
    BYTE dmDeviceName[ 32 ];
    WORD dmSpecVersion;
    WORD dmDriverVersion;
    WORD dmSize;
    WORD dmDriverExtra;
    DWORD dmFields;
    union {

      struct {
        short dmOrientation;
        short dmPaperSize;
        short dmPaperLength;
        short dmPaperWidth;
        short dmScale;
        short dmCopies;
        short dmDefaultSource;
        short dmPrintQuality;
      }  s ;

      struct {
        POINTL dmPosition;
        DWORD dmDisplayOrientation;
        DWORD dmDisplayFixedOutput;
      }  s2 ;
    }  u ;
    short dmColor;
    short dmDuplex;
    short dmYResolution;
    short dmTTOption;
    short dmCollate;
    BYTE dmFormName[ 32 ];
    WORD dmLogPixels;
    DWORD dmBitsPerPel;
    DWORD dmPelsWidth;
    DWORD dmPelsHeight;
    union {
        DWORD dmDisplayFlags;
        DWORD dmNup;
    }  u2 ;
    DWORD dmDisplayFrequency;

    DWORD dmICMMethod;
    DWORD dmICMIntent;
    DWORD dmMediaType;
    DWORD dmDitherType;
    DWORD dmReserved1;
    DWORD dmReserved2;

    DWORD dmPanningWidth;
    DWORD dmPanningHeight;


} DEVMODEA, *PDEVMODEA, *NPDEVMODEA, *LPDEVMODEA;
typedef struct _devicemodeW {
    WCHAR dmDeviceName[ 32 ];
    WORD dmSpecVersion;
    WORD dmDriverVersion;
    WORD dmSize;
    WORD dmDriverExtra;
    DWORD dmFields;
    union {

      struct {
        short dmOrientation;
        short dmPaperSize;
        short dmPaperLength;
        short dmPaperWidth;
        short dmScale;
        short dmCopies;
        short dmDefaultSource;
        short dmPrintQuality;
      }  s ;

      struct {
        POINTL dmPosition;
        DWORD dmDisplayOrientation;
        DWORD dmDisplayFixedOutput;
      }  s2 ;
    }  u ;
    short dmColor;
    short dmDuplex;
    short dmYResolution;
    short dmTTOption;
    short dmCollate;
    WCHAR dmFormName[ 32 ];
    WORD dmLogPixels;
    DWORD dmBitsPerPel;
    DWORD dmPelsWidth;
    DWORD dmPelsHeight;
    union {
        DWORD dmDisplayFlags;
        DWORD dmNup;
    }  u2 ;
    DWORD dmDisplayFrequency;

    DWORD dmICMMethod;
    DWORD dmICMIntent;
    DWORD dmMediaType;
    DWORD dmDitherType;
    DWORD dmReserved1;
    DWORD dmReserved2;

    DWORD dmPanningWidth;
    DWORD dmPanningHeight;


} DEVMODEW, *PDEVMODEW, *NPDEVMODEW, *LPDEVMODEW;






typedef DEVMODEA DEVMODE;
typedef PDEVMODEA PDEVMODE;
typedef NPDEVMODEA NPDEVMODE;
typedef LPDEVMODEA LPDEVMODE;
typedef struct _DISPLAY_DEVICEA {
    DWORD cb;
    CHAR DeviceName[32];
    CHAR DeviceString[128];
    DWORD StateFlags;
    CHAR DeviceID[128];
    CHAR DeviceKey[128];
} DISPLAY_DEVICEA, *PDISPLAY_DEVICEA, *LPDISPLAY_DEVICEA;
typedef struct _DISPLAY_DEVICEW {
    DWORD cb;
    WCHAR DeviceName[32];
    WCHAR DeviceString[128];
    DWORD StateFlags;
    WCHAR DeviceID[128];
    WCHAR DeviceKey[128];
} DISPLAY_DEVICEW, *PDISPLAY_DEVICEW, *LPDISPLAY_DEVICEW;





typedef DISPLAY_DEVICEA DISPLAY_DEVICE;
typedef PDISPLAY_DEVICEA PDISPLAY_DEVICE;
typedef LPDISPLAY_DEVICEA LPDISPLAY_DEVICE;
typedef struct _RGNDATAHEADER {
    DWORD dwSize;
    DWORD iType;
    DWORD nCount;
    DWORD nRgnSize;
    RECT rcBound;
} RGNDATAHEADER, *PRGNDATAHEADER;

typedef struct _RGNDATA {
    RGNDATAHEADER rdh;
    char Buffer[1];
} RGNDATA, *PRGNDATA,   *NPRGNDATA,   *LPRGNDATA;





typedef struct _ABC {
    int abcA;
    UINT abcB;
    int abcC;
} ABC, *PABC,   *NPABC,   *LPABC;

typedef struct _ABCFLOAT {
    FLOAT abcfA;
    FLOAT abcfB;
    FLOAT abcfC;
} ABCFLOAT, *PABCFLOAT,   *NPABCFLOAT,   *LPABCFLOAT;
typedef struct _OUTLINETEXTMETRICA {
    UINT otmSize;
    TEXTMETRICA otmTextMetrics;
    BYTE otmFiller;
    PANOSE otmPanoseNumber;
    UINT otmfsSelection;
    UINT otmfsType;
     int otmsCharSlopeRise;
     int otmsCharSlopeRun;
     int otmItalicAngle;
    UINT otmEMSquare;
     int otmAscent;
     int otmDescent;
    UINT otmLineGap;
    UINT otmsCapEmHeight;
    UINT otmsXHeight;
    RECT otmrcFontBox;
     int otmMacAscent;
     int otmMacDescent;
    UINT otmMacLineGap;
    UINT otmusMinimumPPEM;
    POINT otmptSubscriptSize;
    POINT otmptSubscriptOffset;
    POINT otmptSuperscriptSize;
    POINT otmptSuperscriptOffset;
    UINT otmsStrikeoutSize;
     int otmsStrikeoutPosition;
     int otmsUnderscoreSize;
     int otmsUnderscorePosition;
    PSTR otmpFamilyName;
    PSTR otmpFaceName;
    PSTR otmpStyleName;
    PSTR otmpFullName;
} OUTLINETEXTMETRICA, *POUTLINETEXTMETRICA,   *NPOUTLINETEXTMETRICA,   *LPOUTLINETEXTMETRICA;
typedef struct _OUTLINETEXTMETRICW {
    UINT otmSize;
    TEXTMETRICW otmTextMetrics;
    BYTE otmFiller;
    PANOSE otmPanoseNumber;
    UINT otmfsSelection;
    UINT otmfsType;
     int otmsCharSlopeRise;
     int otmsCharSlopeRun;
     int otmItalicAngle;
    UINT otmEMSquare;
     int otmAscent;
     int otmDescent;
    UINT otmLineGap;
    UINT otmsCapEmHeight;
    UINT otmsXHeight;
    RECT otmrcFontBox;
     int otmMacAscent;
     int otmMacDescent;
    UINT otmMacLineGap;
    UINT otmusMinimumPPEM;
    POINT otmptSubscriptSize;
    POINT otmptSubscriptOffset;
    POINT otmptSuperscriptSize;
    POINT otmptSuperscriptOffset;
    UINT otmsStrikeoutSize;
     int otmsStrikeoutPosition;
     int otmsUnderscoreSize;
     int otmsUnderscorePosition;
    PSTR otmpFamilyName;
    PSTR otmpFaceName;
    PSTR otmpStyleName;
    PSTR otmpFullName;
} OUTLINETEXTMETRICW, *POUTLINETEXTMETRICW,   *NPOUTLINETEXTMETRICW,   *LPOUTLINETEXTMETRICW;






typedef OUTLINETEXTMETRICA OUTLINETEXTMETRIC;
typedef POUTLINETEXTMETRICA POUTLINETEXTMETRIC;
typedef NPOUTLINETEXTMETRICA NPOUTLINETEXTMETRIC;
typedef LPOUTLINETEXTMETRICA LPOUTLINETEXTMETRIC;
typedef struct tagPOLYTEXTA
{
    int x;
    int y;
    UINT n;
    LPCSTR lpstr;
    UINT uiFlags;
    RECT rcl;
    int *pdx;
} POLYTEXTA, *PPOLYTEXTA,   *NPPOLYTEXTA,   *LPPOLYTEXTA;
typedef struct tagPOLYTEXTW
{
    int x;
    int y;
    UINT n;
    LPCWSTR lpstr;
    UINT uiFlags;
    RECT rcl;
    int *pdx;
} POLYTEXTW, *PPOLYTEXTW,   *NPPOLYTEXTW,   *LPPOLYTEXTW;






typedef POLYTEXTA POLYTEXT;
typedef PPOLYTEXTA PPOLYTEXT;
typedef NPPOLYTEXTA NPPOLYTEXT;
typedef LPPOLYTEXTA LPPOLYTEXT;


typedef struct _FIXED {

    WORD fract;
    short value;
} FIXED;


typedef struct _MAT2 {
     FIXED eM11;
     FIXED eM12;
     FIXED eM21;
     FIXED eM22;
} MAT2,   *LPMAT2;



typedef struct _GLYPHMETRICS {
    UINT gmBlackBoxX;
    UINT gmBlackBoxY;
    POINT gmptGlyphOrigin;
    short gmCellIncX;
    short gmCellIncY;
} GLYPHMETRICS,   *LPGLYPHMETRICS;
typedef struct tagPOINTFX
{
    FIXED x;
    FIXED y;
} POINTFX,  * LPPOINTFX;

typedef struct tagTTPOLYCURVE
{
    WORD wType;
    WORD cpfx;
    POINTFX apfx[1];
} TTPOLYCURVE,  * LPTTPOLYCURVE;

typedef struct tagTTPOLYGONHEADER
{
    DWORD cb;
    DWORD dwType;
    POINTFX pfxStart;
} TTPOLYGONHEADER,  * LPTTPOLYGONHEADER;
typedef struct tagGCP_RESULTSA
    {
    DWORD lStructSize;
    LPSTR lpOutString;
    UINT   *lpOrder;
    int   *lpDx;
    int   *lpCaretPos;
    LPSTR lpClass;
    LPWSTR lpGlyphs;
    UINT nGlyphs;
    int nMaxFit;
    } GCP_RESULTSA,  * LPGCP_RESULTSA;
typedef struct tagGCP_RESULTSW
    {
    DWORD lStructSize;
    LPWSTR lpOutString;
    UINT   *lpOrder;
    int   *lpDx;
    int   *lpCaretPos;
    LPSTR lpClass;
    LPWSTR lpGlyphs;
    UINT nGlyphs;
    int nMaxFit;
    } GCP_RESULTSW,  * LPGCP_RESULTSW;




typedef GCP_RESULTSA GCP_RESULTS;
typedef LPGCP_RESULTSA LPGCP_RESULTS;



typedef struct _RASTERIZER_STATUS {
    short nSize;
    short wFlags;
    short nLanguageID;
} RASTERIZER_STATUS,   *LPRASTERIZER_STATUS;






typedef struct tagPIXELFORMATDESCRIPTOR
{
    WORD nSize;
    WORD nVersion;
    DWORD dwFlags;
    BYTE iPixelType;
    BYTE cColorBits;
    BYTE cRedBits;
    BYTE cRedShift;
    BYTE cGreenBits;
    BYTE cGreenShift;
    BYTE cBlueBits;
    BYTE cBlueShift;
    BYTE cAlphaBits;
    BYTE cAlphaShift;
    BYTE cAccumBits;
    BYTE cAccumRedBits;
    BYTE cAccumGreenBits;
    BYTE cAccumBlueBits;
    BYTE cAccumAlphaBits;
    BYTE cDepthBits;
    BYTE cStencilBits;
    BYTE cAuxBuffers;
    BYTE iLayerType;
    BYTE bReserved;
    DWORD dwLayerMask;
    DWORD dwVisibleMask;
    DWORD dwDamageMask;
} PIXELFORMATDESCRIPTOR, *PPIXELFORMATDESCRIPTOR,   *LPPIXELFORMATDESCRIPTOR;
typedef int ( * OLDFONTENUMPROCA)( const  LOGFONTA *,  const  TEXTMETRICA *, DWORD, LPARAM);
typedef int ( * OLDFONTENUMPROCW)( const  LOGFONTW *,  const  TEXTMETRICW *, DWORD, LPARAM);
typedef OLDFONTENUMPROCA FONTENUMPROCA;
typedef OLDFONTENUMPROCW FONTENUMPROCW;



typedef FONTENUMPROCA FONTENUMPROC;


typedef int ( * GOBJENUMPROC)(LPVOID, LPARAM);
typedef  void  ( * LINEDDAPROC)(int, int, LPARAM);
__declspec(dllimport)  int   AddFontResourceA(     LPCSTR);
__declspec(dllimport)  int   AddFontResourceW(     LPCWSTR);






  __declspec(dllimport)  BOOL   AnimatePalette(      HPALETTE hPal,      UINT iStartIndex,      UINT cEntries,         const  PALETTEENTRY * ppe);
  __declspec(dllimport)  BOOL   Arc(      HDC hdc,      int x1,      int y1,      int x2,      int y2,      int x3,      int y3,      int x4,      int y4);
  __declspec(dllimport)  BOOL   BitBlt(      HDC hdc,      int x,      int y,      int cx,      int cy,        HDC hdcSrc,      int x1,      int y1,      DWORD rop);
__declspec(dllimport)  BOOL   CancelDC(      HDC hdc);
  __declspec(dllimport)  BOOL   Chord(      HDC hdc,      int x1,      int y1,      int x2,      int y2,      int x3,      int y3,      int x4,      int y4);
__declspec(dllimport)  int   ChoosePixelFormat(      HDC hdc,       const  PIXELFORMATDESCRIPTOR *ppfd);
__declspec(dllimport)  HMETAFILE   CloseMetaFile(      HDC hdc);
__declspec(dllimport)  int   CombineRgn(        HRGN hrgnDst,        HRGN hrgnSrc1,        HRGN hrgnSrc2,      int iMode);
__declspec(dllimport)  HMETAFILE   CopyMetaFileA(      HMETAFILE,        LPCSTR);
__declspec(dllimport)  HMETAFILE   CopyMetaFileW(      HMETAFILE,        LPCWSTR);





  __declspec(dllimport)  HBITMAP   CreateBitmap(      int nWidth,      int nHeight,      UINT nPlanes,      UINT nBitCount,         const   void  *lpBits);
  __declspec(dllimport)  HBITMAP   CreateBitmapIndirect(       const  BITMAP *pbm);
  __declspec(dllimport)  HBRUSH   CreateBrushIndirect(       const  LOGBRUSH *plbrush);
__declspec(dllimport)  HBITMAP   CreateCompatibleBitmap(      HDC hdc,      int cx,      int cy);
__declspec(dllimport)  HBITMAP   CreateDiscardableBitmap(      HDC hdc,      int cx,      int cy);
__declspec(dllimport)  HDC   CreateCompatibleDC(        HDC hdc);
__declspec(dllimport)  HDC   CreateDCA(        LPCSTR pwszDriver,        LPCSTR pwszDevice,        LPCSTR pszPort,         const  DEVMODEA * pdm);
__declspec(dllimport)  HDC   CreateDCW(        LPCWSTR pwszDriver,        LPCWSTR pwszDevice,        LPCWSTR pszPort,         const  DEVMODEW * pdm);





__declspec(dllimport)  HBITMAP   CreateDIBitmap(      HDC hdc,         const  BITMAPINFOHEADER *pbmih,      DWORD flInit,         const   void  *pjBits,         const  BITMAPINFO *pbmi,      UINT iUsage);
__declspec(dllimport)  HBRUSH   CreateDIBPatternBrush(      HGLOBAL h,      UINT iUsage);
  __declspec(dllimport)  HBRUSH   CreateDIBPatternBrushPt(       const   void  *lpPackedDIB,      UINT iUsage);
__declspec(dllimport)  HRGN   CreateEllipticRgn(      int x1,      int y1,      int x2,      int y2);
__declspec(dllimport)  HRGN   CreateEllipticRgnIndirect(       const  RECT *lprect);
  __declspec(dllimport)  HFONT   CreateFontIndirectA(       const  LOGFONTA *lplf);
  __declspec(dllimport)  HFONT   CreateFontIndirectW(       const  LOGFONTW *lplf);





__declspec(dllimport)  HFONT   CreateFontA(      int cHeight,      int cWidth,      int cEscapement,      int cOrientation,      int cWeight,      DWORD bItalic,
                              DWORD bUnderline,      DWORD bStrikeOut,      DWORD iCharSet,      DWORD iOutPrecision,      DWORD iClipPrecision,
                              DWORD iQuality,      DWORD iPitchAndFamily,        LPCSTR pszFaceName);
__declspec(dllimport)  HFONT   CreateFontW(      int cHeight,      int cWidth,      int cEscapement,      int cOrientation,      int cWeight,      DWORD bItalic,
                              DWORD bUnderline,      DWORD bStrikeOut,      DWORD iCharSet,      DWORD iOutPrecision,      DWORD iClipPrecision,
                              DWORD iQuality,      DWORD iPitchAndFamily,        LPCWSTR pszFaceName);






__declspec(dllimport)  HBRUSH   CreateHatchBrush(      int iHatch,      COLORREF color);
__declspec(dllimport)  HDC   CreateICA(        LPCSTR pszDriver,        LPCSTR pszDevice,        LPCSTR pszPort,         const  DEVMODEA * pdm);
__declspec(dllimport)  HDC   CreateICW(        LPCWSTR pszDriver,        LPCWSTR pszDevice,        LPCWSTR pszPort,         const  DEVMODEW * pdm);





__declspec(dllimport)  HDC   CreateMetaFileA(        LPCSTR pszFile);
__declspec(dllimport)  HDC   CreateMetaFileW(        LPCWSTR pszFile);





  __declspec(dllimport)  HPALETTE   CreatePalette(         const  LOGPALETTE * plpal);
__declspec(dllimport)  HPEN   CreatePen(      int iStyle,      int cWidth,      COLORREF color);
  __declspec(dllimport)  HPEN   CreatePenIndirect(       const  LOGPEN *plpen);
__declspec(dllimport)  HRGN   CreatePolyPolygonRgn(       const  POINT *pptl,
                                                  const  INT *pc,
                                                 int cPoly,
                                                 int iMode);
  __declspec(dllimport)  HBRUSH   CreatePatternBrush(      HBITMAP hbm);
__declspec(dllimport)  HRGN   CreateRectRgn(      int x1,      int y1,      int x2,      int y2);
__declspec(dllimport)  HRGN   CreateRectRgnIndirect(       const  RECT *lprect);
__declspec(dllimport)  HRGN   CreateRoundRectRgn(      int x1,      int y1,      int x2,      int y2,      int w,      int h);
__declspec(dllimport)  BOOL   CreateScalableFontResourceA(      DWORD fdwHidden,      LPCSTR lpszFont,      LPCSTR lpszFile,        LPCSTR lpszPath);
__declspec(dllimport)  BOOL   CreateScalableFontResourceW(      DWORD fdwHidden,      LPCWSTR lpszFont,      LPCWSTR lpszFile,        LPCWSTR lpszPath);





__declspec(dllimport)  HBRUSH   CreateSolidBrush(      COLORREF color);

__declspec(dllimport)  BOOL   DeleteDC(      HDC hdc);
__declspec(dllimport)  BOOL   DeleteMetaFile(      HMETAFILE hmf);
  __declspec(dllimport)  BOOL   DeleteObject(      HGDIOBJ ho);
__declspec(dllimport)  int   DescribePixelFormat(      HDC hdc,
                                             int iPixelFormat,
                                             UINT nBytes,
                                             LPPIXELFORMATDESCRIPTOR ppfd);
typedef UINT ( * LPFNDEVMODE)(HWND, HMODULE, LPDEVMODE, LPSTR, LPSTR, LPDEVMODE, LPSTR, UINT);

typedef DWORD ( * LPFNDEVCAPS)(LPSTR, LPSTR, UINT, LPSTR, LPDEVMODE);
__declspec(dllimport)
int

DeviceCapabilitiesA(
     LPCSTR pDevice,
     LPCSTR pPort,
     WORD fwCapability,
     LPSTR pOutput,
      const  DEVMODEA *pDevMode
    );
__declspec(dllimport)
int

DeviceCapabilitiesW(
     LPCWSTR pDevice,
     LPCWSTR pPort,
     WORD fwCapability,
     LPWSTR pOutput,
      const  DEVMODEW *pDevMode
    );






__declspec(dllimport)  int   DrawEscape(      HDC hdc,
                                     int iEscape,
                                     int cjIn,
                                     LPCSTR lpIn);

  __declspec(dllimport)  BOOL   Ellipse(      HDC hdc,      int left,      int top,      int right,      int bottom);


__declspec(dllimport)  int   EnumFontFamiliesExA(      HDC hdc,      LPLOGFONTA lpLogfont,      FONTENUMPROCA lpProc,      LPARAM lParam,      DWORD dwFlags);
__declspec(dllimport)  int   EnumFontFamiliesExW(      HDC hdc,      LPLOGFONTW lpLogfont,      FONTENUMPROCW lpProc,      LPARAM lParam,      DWORD dwFlags);







__declspec(dllimport)  int   EnumFontFamiliesA(      HDC hdc,        LPCSTR lpLogfont,      FONTENUMPROCA lpProc,      LPARAM lParam);
__declspec(dllimport)  int   EnumFontFamiliesW(      HDC hdc,        LPCWSTR lpLogfont,      FONTENUMPROCW lpProc,      LPARAM lParam);





__declspec(dllimport)  int   EnumFontsA(      HDC hdc,        LPCSTR lpLogfont,      FONTENUMPROCA lpProc,      LPARAM lParam);
__declspec(dllimport)  int   EnumFontsW(      HDC hdc,        LPCWSTR lpLogfont,      FONTENUMPROCW lpProc,      LPARAM lParam);







__declspec(dllimport)  int   EnumObjects(      HDC hdc,      int nType,      GOBJENUMPROC lpFunc,      LPARAM lParam);
__declspec(dllimport)  BOOL   EqualRgn(      HRGN hrgn1,      HRGN hrgn2);
  __declspec(dllimport)  int   Escape(      HDC hdc,
                                 int iEscape,
                                 int cjIn,
                                 LPCSTR pvIn,
                                 LPVOID pvOut);
__declspec(dllimport)  int   ExtEscape(      HDC hdc,
                                     int iEscape,
                                     int cjInput,
                                     LPCSTR lpInData,
                                     int cjOutput,
                                     LPSTR lpOutData);
  __declspec(dllimport)  int   ExcludeClipRect(      HDC hdc,      int left,      int top,      int right,      int bottom);
  __declspec(dllimport)  HRGN   ExtCreateRegion(         const  XFORM * lpx,      DWORD nCount,         const  RGNDATA * lpData);
  __declspec(dllimport)  BOOL   ExtFloodFill(      HDC hdc,      int x,      int y,      COLORREF color,      UINT type);
  __declspec(dllimport)  BOOL   FillRgn(      HDC hdc,      HRGN hrgn,      HBRUSH hbr);
  __declspec(dllimport)  BOOL   FloodFill(      HDC hdc,      int x,      int y,      COLORREF color);
  __declspec(dllimport)  BOOL   FrameRgn(      HDC hdc,      HRGN hrgn,      HBRUSH hbr,      int w,      int h);
__declspec(dllimport)  int   GetROP2(      HDC hdc);
__declspec(dllimport)  BOOL   GetAspectRatioFilterEx(      HDC hdc,      LPSIZE lpsize);
__declspec(dllimport)  COLORREF   GetBkColor(      HDC hdc);


__declspec(dllimport)  COLORREF   GetDCBrushColor(      HDC hdc);
__declspec(dllimport)  COLORREF   GetDCPenColor(      HDC hdc);


__declspec(dllimport)
int

GetBkMode(
     HDC hdc
    );

__declspec(dllimport)
LONG

GetBitmapBits(
     HBITMAP hbit,
     LONG cb,
     LPVOID lpvBits
    );

__declspec(dllimport)  BOOL   GetBitmapDimensionEx(      HBITMAP hbit,      LPSIZE lpsize);
__declspec(dllimport)  UINT   GetBoundsRect(      HDC hdc,      LPRECT lprect,      UINT flags);

__declspec(dllimport)  BOOL   GetBrushOrgEx(      HDC hdc,      LPPOINT lppt);

__declspec(dllimport)  BOOL   GetCharWidthA(      HDC hdc,      UINT iFirst,      UINT iLast,      LPINT lpBuffer);
__declspec(dllimport)  BOOL   GetCharWidthW(      HDC hdc,      UINT iFirst,      UINT iLast,      LPINT lpBuffer);





__declspec(dllimport)  BOOL   GetCharWidth32A(      HDC hdc,      UINT iFirst,      UINT iLast,      LPINT lpBuffer);
__declspec(dllimport)  BOOL   GetCharWidth32W(      HDC hdc,      UINT iFirst,      UINT iLast,      LPINT lpBuffer);





__declspec(dllimport)  BOOL   GetCharWidthFloatA(      HDC hdc,      UINT iFirst,      UINT iLast,      PFLOAT lpBuffer);
__declspec(dllimport)  BOOL   GetCharWidthFloatW(      HDC hdc,      UINT iFirst,      UINT iLast,      PFLOAT lpBuffer);






__declspec(dllimport)  BOOL   GetCharABCWidthsA(      HDC hdc,
                                             UINT wFirst,
                                             UINT wLast,
                                             LPABC lpABC);
__declspec(dllimport)  BOOL   GetCharABCWidthsW(      HDC hdc,
                                             UINT wFirst,
                                             UINT wLast,
                                             LPABC lpABC);






__declspec(dllimport)  BOOL   GetCharABCWidthsFloatA(      HDC hdc,      UINT iFirst,      UINT iLast,      LPABCFLOAT lpABC);
__declspec(dllimport)  BOOL   GetCharABCWidthsFloatW(      HDC hdc,      UINT iFirst,      UINT iLast,      LPABCFLOAT lpABC);





__declspec(dllimport)  int   GetClipBox(      HDC hdc,      LPRECT lprect);
__declspec(dllimport)  int   GetClipRgn(      HDC hdc,      HRGN hrgn);
__declspec(dllimport)  int   GetMetaRgn(      HDC hdc,      HRGN hrgn);
__declspec(dllimport)  HGDIOBJ   GetCurrentObject(      HDC hdc,      UINT type);
__declspec(dllimport)  BOOL   GetCurrentPositionEx(      HDC hdc,      LPPOINT lppt);
__declspec(dllimport)  int   GetDeviceCaps(        HDC hdc,      int index);
__declspec(dllimport)  int   GetDIBits(      HDC hdc,      HBITMAP hbm,      UINT start,      UINT cLines,        LPVOID lpvBits,        LPBITMAPINFO lpbmi,      UINT usage);


__declspec(dllimport)  DWORD   GetFontData (      HDC hdc,
                                         DWORD dwTable,
                                         DWORD dwOffset,
                                         PVOID pvBuffer,
                                         DWORD cjBuffer
                                        );

__declspec(dllimport)  DWORD   GetGlyphOutlineA(      HDC hdc,
                                             UINT uChar,
                                             UINT fuFormat,
                                             LPGLYPHMETRICS lpgm,
                                             DWORD cjBuffer,
                                             LPVOID pvBuffer,
                                              const  MAT2 *lpmat2
                                        );
__declspec(dllimport)  DWORD   GetGlyphOutlineW(      HDC hdc,
                                             UINT uChar,
                                             UINT fuFormat,
                                             LPGLYPHMETRICS lpgm,
                                             DWORD cjBuffer,
                                             LPVOID pvBuffer,
                                              const  MAT2 *lpmat2
                                        );






__declspec(dllimport)  int   GetGraphicsMode(      HDC hdc);
__declspec(dllimport)  int   GetMapMode(      HDC hdc);
__declspec(dllimport)  UINT   GetMetaFileBitsEx(     HMETAFILE hMF,      UINT cbBuffer,        LPVOID lpData);
__declspec(dllimport)  HMETAFILE   GetMetaFileA(      LPCSTR lpName);
__declspec(dllimport)  HMETAFILE   GetMetaFileW(      LPCWSTR lpName);





__declspec(dllimport)  COLORREF   GetNearestColor(      HDC hdc,      COLORREF color);
__declspec(dllimport)  UINT   GetNearestPaletteIndex(      HPALETTE h,      COLORREF color);
__declspec(dllimport)  DWORD   GetObjectType(      HGDIOBJ h);



__declspec(dllimport)  UINT   GetOutlineTextMetricsA(      HDC hdc,
                                                 UINT cjCopy,
                                                 LPOUTLINETEXTMETRICA potm);
__declspec(dllimport)  UINT   GetOutlineTextMetricsW(      HDC hdc,
                                                 UINT cjCopy,
                                                 LPOUTLINETEXTMETRICW potm);








__declspec(dllimport)  UINT   GetPaletteEntries(      HPALETTE hpal,
                                             UINT iStart,
                                             UINT cEntries,
                                             LPPALETTEENTRY pPalEntries);
__declspec(dllimport)  COLORREF   GetPixel(      HDC hdc,      int x,      int y);
__declspec(dllimport)  int   GetPixelFormat(      HDC hdc);
__declspec(dllimport)  int   GetPolyFillMode(      HDC hdc);
__declspec(dllimport)  BOOL   GetRasterizerCaps(      LPRASTERIZER_STATUS lpraststat,
                                             UINT cjBytes);

__declspec(dllimport)  int   GetRandomRgn (     HDC hdc,      HRGN hrgn,      INT i);
__declspec(dllimport)  DWORD   GetRegionData(      HRGN hrgn,
                                         DWORD nCount,
                                         LPRGNDATA lpRgnData);
__declspec(dllimport)  int   GetRgnBox(      HRGN hrgn,      LPRECT lprc);
__declspec(dllimport)  HGDIOBJ   GetStockObject(      int i);
__declspec(dllimport)  int   GetStretchBltMode(     HDC hdc);
__declspec(dllimport)
UINT

GetSystemPaletteEntries(
     HDC hdc,
     UINT iStart,
     UINT cEntries,
     LPPALETTEENTRY pPalEntries
    );

__declspec(dllimport)  UINT   GetSystemPaletteUse(     HDC hdc);
__declspec(dllimport)  int   GetTextCharacterExtra(     HDC hdc);
__declspec(dllimport)  UINT   GetTextAlign(     HDC hdc);
__declspec(dllimport)  COLORREF   GetTextColor(     HDC hdc);

__declspec(dllimport)
BOOL

GetTextExtentPointA(
     HDC hdc,
     LPCSTR lpString,
     int c,
     LPSIZE lpsz
    );
__declspec(dllimport)
BOOL

GetTextExtentPointW(
     HDC hdc,
     LPCWSTR lpString,
     int c,
     LPSIZE lpsz
    );






__declspec(dllimport)
BOOL

GetTextExtentPoint32A(
     HDC hdc,
     LPCSTR lpString,
     int c,
     LPSIZE psizl
    );
__declspec(dllimport)
BOOL

GetTextExtentPoint32W(
     HDC hdc,
     LPCWSTR lpString,
     int c,
     LPSIZE psizl
    );






__declspec(dllimport)
BOOL

GetTextExtentExPointA(
     HDC hdc,
     LPCSTR lpszString,
     int cchString,
     int nMaxExtent,
     LPINT lpnFit,
     LPINT lpnDx,
     LPSIZE lpSize
    );
__declspec(dllimport)
BOOL

GetTextExtentExPointW(
     HDC hdc,
     LPCWSTR lpszString,
     int cchString,
     int nMaxExtent,
     LPINT lpnFit,
     LPINT lpnDx,
     LPSIZE lpSize
    );







__declspec(dllimport)  int   GetTextCharset(      HDC hdc);
__declspec(dllimport)  int   GetTextCharsetInfo(      HDC hdc,        LPFONTSIGNATURE lpSig,      DWORD dwFlags);
__declspec(dllimport)  BOOL   TranslateCharsetInfo(      DWORD   *lpSrc,      LPCHARSETINFO lpCs,      DWORD dwFlags);
__declspec(dllimport)  DWORD   GetFontLanguageInfo(      HDC hdc);
__declspec(dllimport)  DWORD   GetCharacterPlacementA(      HDC hdc,        LPCSTR lpString,      int nCount,      int nMexExtent,      LPGCP_RESULTSA lpResults,      DWORD dwFlags);
__declspec(dllimport)  DWORD   GetCharacterPlacementW(      HDC hdc,        LPCWSTR lpString,      int nCount,      int nMexExtent,      LPGCP_RESULTSW lpResults,      DWORD dwFlags);









typedef struct tagWCRANGE
{
    WCHAR wcLow;
    USHORT cGlyphs;
} WCRANGE, *PWCRANGE,  *LPWCRANGE;


typedef struct tagGLYPHSET
{
    DWORD cbThis;
    DWORD flAccel;
    DWORD cGlyphsSupported;
    DWORD cRanges;
    WCRANGE ranges[1];
} GLYPHSET, *PGLYPHSET,   *LPGLYPHSET;









__declspec(dllimport)  DWORD   GetFontUnicodeRanges(      HDC hdc,        LPGLYPHSET lpgs);
__declspec(dllimport)  DWORD   GetGlyphIndicesA(      HDC hdc,        LPCSTR lpstr,      int c,      LPWORD pgi,      DWORD fl);
__declspec(dllimport)  DWORD   GetGlyphIndicesW(      HDC hdc,        LPCWSTR lpstr,      int c,      LPWORD pgi,      DWORD fl);





__declspec(dllimport)  BOOL   GetTextExtentPointI(     HDC hdc,        LPWORD pgiIn,      int cgi,      LPSIZE psize);
__declspec(dllimport)  BOOL   GetTextExtentExPointI (      HDC hdc,
                                                 LPWORD lpwszString,
                                                 int cwchString,
                                                 int nMaxExtent,
                                                 LPINT lpnFit,
                                                 LPINT lpnDx,
                                                 LPSIZE lpSize
                                                );

__declspec(dllimport)  BOOL   GetCharWidthI(      HDC hdc,
                                         UINT giFirst,
                                         UINT cgi,
                                         LPWORD pgi,
                                         LPINT piWidths
                                        );

__declspec(dllimport)  BOOL   GetCharABCWidthsI(      HDC hdc,
                                             UINT giFirst,
                                             UINT cgi,
                                             LPWORD pgi,
                                             LPABC pabc
                                        );








typedef struct tagDESIGNVECTOR
{
    DWORD dvReserved;
    DWORD dvNumAxes;
    LONG dvValues[ 16 ];
} DESIGNVECTOR, *PDESIGNVECTOR,   *LPDESIGNVECTOR;

__declspec(dllimport)  int   AddFontResourceExA(      LPCSTR name,      DWORD fl,   PVOID res);
__declspec(dllimport)  int   AddFontResourceExW(      LPCWSTR name,      DWORD fl,   PVOID res);





__declspec(dllimport)  BOOL   RemoveFontResourceExA(      LPCSTR name,      DWORD fl,   PVOID pdv);
__declspec(dllimport)  BOOL   RemoveFontResourceExW(      LPCWSTR name,      DWORD fl,   PVOID pdv);





__declspec(dllimport)  HANDLE   AddFontMemResourceEx(        PVOID pFileView,
                                                 DWORD cjSize,
                                                 PVOID pvResrved,
                                                 DWORD* pNumFonts);

__declspec(dllimport)  BOOL   RemoveFontMemResourceEx(      HANDLE h);









typedef struct tagAXISINFOA
{
    LONG axMinValue;
    LONG axMaxValue;
    BYTE axAxisName[ 16 ];
} AXISINFOA, *PAXISINFOA,   *LPAXISINFOA;
typedef struct tagAXISINFOW
{
    LONG axMinValue;
    LONG axMaxValue;
    WCHAR axAxisName[ 16 ];
} AXISINFOW, *PAXISINFOW,   *LPAXISINFOW;





typedef AXISINFOA AXISINFO;
typedef PAXISINFOA PAXISINFO;
typedef LPAXISINFOA LPAXISINFO;


typedef struct tagAXESLISTA
{
    DWORD axlReserved;
    DWORD axlNumAxes;
    AXISINFOA axlAxisInfo[ 16 ];
} AXESLISTA, *PAXESLISTA,   *LPAXESLISTA;
typedef struct tagAXESLISTW
{
    DWORD axlReserved;
    DWORD axlNumAxes;
    AXISINFOW axlAxisInfo[ 16 ];
} AXESLISTW, *PAXESLISTW,   *LPAXESLISTW;





typedef AXESLISTA AXESLIST;
typedef PAXESLISTA PAXESLIST;
typedef LPAXESLISTA LPAXESLIST;






typedef struct tagENUMLOGFONTEXDVA
{
    ENUMLOGFONTEXA elfEnumLogfontEx;
    DESIGNVECTOR elfDesignVector;
} ENUMLOGFONTEXDVA, *PENUMLOGFONTEXDVA,   *LPENUMLOGFONTEXDVA;
typedef struct tagENUMLOGFONTEXDVW
{
    ENUMLOGFONTEXW elfEnumLogfontEx;
    DESIGNVECTOR elfDesignVector;
} ENUMLOGFONTEXDVW, *PENUMLOGFONTEXDVW,   *LPENUMLOGFONTEXDVW;





typedef ENUMLOGFONTEXDVA ENUMLOGFONTEXDV;
typedef PENUMLOGFONTEXDVA PENUMLOGFONTEXDV;
typedef LPENUMLOGFONTEXDVA LPENUMLOGFONTEXDV;


__declspec(dllimport)  HFONT   CreateFontIndirectExA(       const  ENUMLOGFONTEXDVA *);
__declspec(dllimport)  HFONT   CreateFontIndirectExW(       const  ENUMLOGFONTEXDVW *);







typedef struct tagENUMTEXTMETRICA
{
    NEWTEXTMETRICEXA etmNewTextMetricEx;
    AXESLISTA etmAxesList;
} ENUMTEXTMETRICA, *PENUMTEXTMETRICA,   *LPENUMTEXTMETRICA;
typedef struct tagENUMTEXTMETRICW
{
    NEWTEXTMETRICEXW etmNewTextMetricEx;
    AXESLISTW etmAxesList;
} ENUMTEXTMETRICW, *PENUMTEXTMETRICW,   *LPENUMTEXTMETRICW;





typedef ENUMTEXTMETRICA ENUMTEXTMETRIC;
typedef PENUMTEXTMETRICA PENUMTEXTMETRIC;
typedef LPENUMTEXTMETRICA LPENUMTEXTMETRIC;





__declspec(dllimport)  BOOL   GetViewportExtEx(      HDC hdc,      LPSIZE lpsize);
__declspec(dllimport)  BOOL   GetViewportOrgEx(      HDC hdc,      LPPOINT lppoint);
__declspec(dllimport)  BOOL   GetWindowExtEx(      HDC hdc,      LPSIZE lpsize);
__declspec(dllimport)  BOOL   GetWindowOrgEx(      HDC hdc,      LPPOINT lppoint);

  __declspec(dllimport)  int   IntersectClipRect(      HDC hdc,      int left,      int top,      int right,      int bottom);
  __declspec(dllimport)  BOOL   InvertRgn(      HDC hdc,      HRGN hrgn);
__declspec(dllimport)  BOOL   LineDDA(      int xStart,      int yStart,      int xEnd,      int yEnd,      LINEDDAPROC lpProc,        LPARAM data);
  __declspec(dllimport)  BOOL   LineTo(      HDC hdc,      int x,      int y);
__declspec(dllimport)  BOOL   MaskBlt(      HDC hdcDest,      int xDest,      int yDest,      int width,      int height,
               HDC hdcSrc,      int xSrc,      int ySrc,      HBITMAP hbmMask,      int xMask,      int yMask,      DWORD rop);
__declspec(dllimport)  BOOL   PlgBlt(      HDC hdcDest,         const  POINT * lpPoint,      HDC hdcSrc,      int xSrc,      int ySrc,      int width,
                      int height,        HBITMAP hbmMask,      int xMask,      int yMask);

  __declspec(dllimport)  int   OffsetClipRgn(     HDC hdc,      int x,      int y);
__declspec(dllimport)  int   OffsetRgn(     HRGN hrgn,      int x,      int y);
  __declspec(dllimport)  BOOL   PatBlt(     HDC hdc,      int x,      int y,      int w,      int h,      DWORD rop);
  __declspec(dllimport)  BOOL   Pie(     HDC hdc,      int left,      int top,      int right,      int bottom,      int xr1,      int yr1,      int xr2,      int yr2);
__declspec(dllimport)  BOOL   PlayMetaFile(     HDC hdc,      HMETAFILE hmf);
  __declspec(dllimport)  BOOL   PaintRgn(     HDC hdc,      HRGN hrgn);
  __declspec(dllimport)  BOOL   PolyPolygon(     HDC hdc,       const  POINT *apt,         const  INT *asz,      int csz);
__declspec(dllimport)  BOOL   PtInRegion(     HRGN hrgn,      int x,      int y);
__declspec(dllimport)  BOOL   PtVisible(     HDC hdc,      int x,      int y);
__declspec(dllimport)  BOOL   RectInRegion(     HRGN hrgn,       const  RECT * lprect);
__declspec(dllimport)  BOOL   RectVisible(     HDC hdc,       const  RECT * lprect);
  __declspec(dllimport)  BOOL   Rectangle(     HDC hdc,      int left,      int top,      int right,      int bottom);
  __declspec(dllimport)  BOOL   RestoreDC(     HDC hdc,      int nSavedDC);
  __declspec(dllimport)  HDC   ResetDCA(     HDC hdc,       const  DEVMODEA * lpdm);
  __declspec(dllimport)  HDC   ResetDCW(     HDC hdc,       const  DEVMODEW * lpdm);





  __declspec(dllimport)  UINT   RealizePalette(     HDC hdc);
__declspec(dllimport)  BOOL   RemoveFontResourceA(     LPCSTR lpFileName);
__declspec(dllimport)  BOOL   RemoveFontResourceW(     LPCWSTR lpFileName);





  __declspec(dllimport)  BOOL   RoundRect(     HDC hdc,      int left,      int top,      int right,      int bottom,      int width,      int height);
  __declspec(dllimport)  BOOL   ResizePalette(     HPALETTE hpal,      UINT n);

  __declspec(dllimport)  int   SaveDC(     HDC hdc);
  __declspec(dllimport)  int   SelectClipRgn(     HDC hdc,        HRGN hrgn);
__declspec(dllimport)  int   ExtSelectClipRgn(     HDC hdc,        HRGN hrgn,      int mode);
__declspec(dllimport)  int   SetMetaRgn(     HDC hdc);
  __declspec(dllimport)  HGDIOBJ   SelectObject(     HDC hdc,      HGDIOBJ h);
  __declspec(dllimport)  HPALETTE   SelectPalette(     HDC hdc,      HPALETTE hPal,      BOOL bForceBkgd);
  __declspec(dllimport)  COLORREF   SetBkColor(     HDC hdc,      COLORREF color);


__declspec(dllimport)  COLORREF   SetDCBrushColor(     HDC hdc,      COLORREF color);
__declspec(dllimport)  COLORREF   SetDCPenColor(     HDC hdc,      COLORREF color);


  __declspec(dllimport)  int   SetBkMode(     HDC hdc,      int mode);

__declspec(dllimport)
LONG
SetBitmapBits(
     HBITMAP hbm,
     DWORD cb,
      const   void  *pvBits);

__declspec(dllimport)  UINT   SetBoundsRect(     HDC hdc,         const  RECT * lprect,      UINT flags);
__declspec(dllimport)  int   SetDIBits(       HDC hdc,      HBITMAP hbm,      UINT start,      UINT cLines,       const   void  *lpBits,       const  BITMAPINFO * lpbmi,      UINT ColorUse);
  __declspec(dllimport)  int   SetDIBitsToDevice(     HDC hdc,      int xDest,      int yDest,      DWORD w,      DWORD h,      int xSrc,
         int ySrc,      UINT StartScan,      UINT cLines,       const   void  * lpvBits,       const  BITMAPINFO * lpbmi,      UINT ColorUse);
  __declspec(dllimport)  DWORD   SetMapperFlags(     HDC hdc,      DWORD flags);
__declspec(dllimport)  int   SetGraphicsMode(     HDC hdc,      int iMode);
  __declspec(dllimport)  int   SetMapMode(     HDC hdc,      int iMode);


  __declspec(dllimport)  DWORD   SetLayout(     HDC hdc,      DWORD l);
__declspec(dllimport)  DWORD   GetLayout(     HDC hdc);


__declspec(dllimport)  HMETAFILE   SetMetaFileBitsEx(     UINT cbBuffer,         const  BYTE *lpData);
  __declspec(dllimport)  UINT   SetPaletteEntries(      HPALETTE hpal,
                                             UINT iStart,
                                             UINT cEntries,
                                              const  PALETTEENTRY *pPalEntries);
  __declspec(dllimport)  COLORREF   SetPixel(     HDC hdc,      int x,      int y,      COLORREF color);
__declspec(dllimport)  BOOL   SetPixelV(     HDC hdc,      int x,      int y,      COLORREF color);
__declspec(dllimport)  BOOL   SetPixelFormat(     HDC hdc,      int format,       const  PIXELFORMATDESCRIPTOR * ppfd);
  __declspec(dllimport)  int   SetPolyFillMode(     HDC hdc,      int mode);
  __declspec(dllimport)  BOOL   StretchBlt(     HDC hdcDest,      int xDest,      int yDest,      int wDest,      int hDest,        HDC hdcSrc,      int xSrc,      int ySrc,      int wSrc,      int hSrc,      DWORD rop);
__declspec(dllimport)  BOOL   SetRectRgn(     HRGN hrgn,      int left,      int top,      int right,      int bottom);
  __declspec(dllimport)  int   StretchDIBits(     HDC hdc,      int xDest,      int yDest,      int DestWidth,      int DestHeight,      int xSrc,      int ySrc,      int SrcWidth,      int SrcHeight,
          const   void  * lpBits,       const  BITMAPINFO * lpbmi,      UINT iUsage,      DWORD rop);
  __declspec(dllimport)  int   SetROP2(     HDC hdc,      int rop2);
  __declspec(dllimport)  int   SetStretchBltMode(     HDC hdc,      int mode);
__declspec(dllimport)  UINT   SetSystemPaletteUse(     HDC hdc,      UINT use);
  __declspec(dllimport)  int   SetTextCharacterExtra(     HDC hdc,      int extra);
  __declspec(dllimport)  COLORREF   SetTextColor(     HDC hdc,      COLORREF color);
  __declspec(dllimport)  UINT   SetTextAlign(     HDC hdc,      UINT align);
  __declspec(dllimport)  BOOL   SetTextJustification(     HDC hdc,      int extra,      int count);
__declspec(dllimport)  BOOL   UpdateColors(     HDC hdc);
typedef USHORT COLOR16;

typedef struct _TRIVERTEX
{
    LONG x;
    LONG y;
    COLOR16 Red;
    COLOR16 Green;
    COLOR16 Blue;
    COLOR16 Alpha;
}TRIVERTEX,*PTRIVERTEX,*LPTRIVERTEX;

typedef struct _GRADIENT_TRIANGLE
{
    ULONG Vertex1;
    ULONG Vertex2;
    ULONG Vertex3;
} GRADIENT_TRIANGLE,*PGRADIENT_TRIANGLE,*LPGRADIENT_TRIANGLE;

typedef struct _GRADIENT_RECT
{
    ULONG UpperLeft;
    ULONG LowerRight;
}GRADIENT_RECT,*PGRADIENT_RECT,*LPGRADIENT_RECT;

typedef struct _BLENDFUNCTION
{
    BYTE BlendOp;
    BYTE BlendFlags;
    BYTE SourceConstantAlpha;
    BYTE AlphaFormat;
}BLENDFUNCTION,*PBLENDFUNCTION;
__declspec(dllimport)  BOOL   AlphaBlend(      HDC hdcDest,      int xoriginDest,      int yoriginDest,      int wDest,      int hDest,      HDC hdcSrc,      int xoriginSrc,      int yoriginSrc,      int wSrc,      int hSrc,      BLENDFUNCTION ftn);

__declspec(dllimport)  BOOL   TransparentBlt(     HDC hdcDest,     int xoriginDest,      int yoriginDest,      int wDest,      int hDest,      HDC hdcSrc,
                                            int xoriginSrc,      int yoriginSrc,      int wSrc,      int hSrc,      UINT crTransparent);
__declspec(dllimport)
BOOL

GradientFill(
     HDC hdc,
     PTRIVERTEX pVertex,
     ULONG nVertex,
     PVOID pMesh,
     ULONG nMesh,
     ULONG ulMode
    );






__declspec(dllimport)  BOOL   GdiAlphaBlend(     HDC hdcDest,      int xoriginDest,      int yoriginDest,      int wDest,      int hDest,      HDC hdcSrc,      int xoriginSrc,      int yoriginSrc,      int wSrc,      int hSrc,      BLENDFUNCTION ftn);

__declspec(dllimport)  BOOL   GdiTransparentBlt(     HDC hdcDest,     int xoriginDest,      int yoriginDest,      int wDest,      int hDest,      HDC hdcSrc,
                                            int xoriginSrc,      int yoriginSrc,      int wSrc,      int hSrc,      UINT crTransparent);

__declspec(dllimport)  BOOL   GdiGradientFill(      HDC hdc,
                                         PTRIVERTEX pVertex,
                                         ULONG nVertex,
                                         PVOID pMesh,
                                         ULONG nCount,
                                         ULONG ulMode);






__declspec(dllimport)  BOOL   PlayMetaFileRecord(      HDC hdc,
                                             LPHANDLETABLE lpHandleTable,
                                             LPMETARECORD lpMR,
                                             UINT noObjs);

typedef int ( * MFENUMPROC)(      HDC hdc,        HANDLETABLE  * lpht,      METARECORD  * lpMR,      int nObj,        LPARAM param);
__declspec(dllimport)  BOOL   EnumMetaFile(      HDC hdc,      HMETAFILE hmf,      MFENUMPROC proc,        LPARAM param);

typedef int ( * ENHMFENUMPROC)(     HDC hdc,        HANDLETABLE  * lpht,       const  ENHMETARECORD * lpmr,      int hHandles,        LPARAM data);



__declspec(dllimport)  HENHMETAFILE   CloseEnhMetaFile(      HDC hdc);
__declspec(dllimport)  HENHMETAFILE   CopyEnhMetaFileA(      HENHMETAFILE hEnh,        LPCSTR lpFileName);
__declspec(dllimport)  HENHMETAFILE   CopyEnhMetaFileW(      HENHMETAFILE hEnh,        LPCWSTR lpFileName);





__declspec(dllimport)  HDC   CreateEnhMetaFileA(        HDC hdc,        LPCSTR lpFilename,         const  RECT *lprc,        LPCSTR lpDesc);
__declspec(dllimport)  HDC   CreateEnhMetaFileW(        HDC hdc,        LPCWSTR lpFilename,         const  RECT *lprc,        LPCWSTR lpDesc);





__declspec(dllimport)  BOOL   DeleteEnhMetaFile(        HENHMETAFILE hmf);
__declspec(dllimport)  BOOL   EnumEnhMetaFile(        HDC hdc,      HENHMETAFILE hmf,      ENHMFENUMPROC proc,
                                         LPVOID param,         const  RECT * lpRect);
__declspec(dllimport)  HENHMETAFILE   GetEnhMetaFileA(      LPCSTR lpName);
__declspec(dllimport)  HENHMETAFILE   GetEnhMetaFileW(      LPCWSTR lpName);





__declspec(dllimport)  UINT   GetEnhMetaFileBits(      HENHMETAFILE hEMF,
                                             UINT nSize,
                                             LPBYTE lpData);
__declspec(dllimport)  UINT   GetEnhMetaFileDescriptionA(      HENHMETAFILE hemf,
                                                     UINT cchBuffer,
                                                     LPSTR lpDescription);
__declspec(dllimport)  UINT   GetEnhMetaFileDescriptionW(      HENHMETAFILE hemf,
                                                     UINT cchBuffer,
                                                     LPWSTR lpDescription);





__declspec(dllimport)  UINT   GetEnhMetaFileHeader(      HENHMETAFILE hemf,
                                                 UINT nSize,
                                                 LPENHMETAHEADER lpEnhMetaHeader);
__declspec(dllimport)  UINT   GetEnhMetaFilePaletteEntries(     HENHMETAFILE hemf,
                                                     UINT nNumEntries,
                                                     LPPALETTEENTRY lpPaletteEntries);

__declspec(dllimport)  UINT   GetEnhMetaFilePixelFormat(      HENHMETAFILE hemf,
                                                     UINT cbBuffer,
                                                     PIXELFORMATDESCRIPTOR *ppfd);
__declspec(dllimport)  UINT   GetWinMetaFileBits(      HENHMETAFILE hemf,
                                             UINT cbData16,
                                             LPBYTE pData16,
                                             INT iMapMode,
                                             HDC hdcRef);
__declspec(dllimport)  BOOL   PlayEnhMetaFile(      HDC hdc,      HENHMETAFILE hmf,       const  RECT * lprect);
__declspec(dllimport)  BOOL   PlayEnhMetaFileRecord(      HDC hdc,
                                                 LPHANDLETABLE pht,
                                                  const  ENHMETARECORD *pmr,
                                                 UINT cht);

__declspec(dllimport)  HENHMETAFILE   SetEnhMetaFileBits(      UINT nSize,
                                                      const  BYTE * pb);

__declspec(dllimport)  HENHMETAFILE   SetWinMetaFileBits(      UINT nSize,
                                                      const  BYTE *lpMeta16Data,
                                                     HDC hdcRef,
                                                      const  METAFILEPICT *lpMFP);
__declspec(dllimport)  BOOL   GdiComment(     HDC hdc,      UINT nSize,         const  BYTE *lpData);





__declspec(dllimport)  BOOL   GetTextMetricsA(      HDC hdc,      LPTEXTMETRICA lptm);
__declspec(dllimport)  BOOL   GetTextMetricsW(      HDC hdc,      LPTEXTMETRICW lptm);
typedef struct tagDIBSECTION {
    BITMAP dsBm;
    BITMAPINFOHEADER dsBmih;
    DWORD dsBitfields[3];
    HANDLE dshSection;
    DWORD dsOffset;
} DIBSECTION,   *LPDIBSECTION, *PDIBSECTION;


__declspec(dllimport)  BOOL   AngleArc(      HDC hdc,      int x,      int y,      DWORD r,      FLOAT StartAngle,      FLOAT SweepAngle);
__declspec(dllimport)  BOOL   PolyPolyline(     HDC hdc,       const  POINT *apt,         const  DWORD *asz,      DWORD csz);
__declspec(dllimport)  BOOL   GetWorldTransform(      HDC hdc,      LPXFORM lpxf);
__declspec(dllimport)  BOOL   SetWorldTransform(      HDC hdc,       const  XFORM * lpxf);
__declspec(dllimport)  BOOL   ModifyWorldTransform(      HDC hdc,         const  XFORM * lpxf,      DWORD mode);
__declspec(dllimport)  BOOL   CombineTransform(      LPXFORM lpxfOut,       const  XFORM *lpxf1,       const  XFORM *lpxf2);
__declspec(dllimport)  HBITMAP   CreateDIBSection(       HDC hdc,       const  BITMAPINFO *lpbmi,      UINT usage,                  void  **ppvBits,        HANDLE hSection,      DWORD offset);
__declspec(dllimport)  UINT   GetDIBColorTable(      HDC hdc,
                                         UINT iStart,
                                         UINT cEntries,
                                         RGBQUAD *prgbq);
__declspec(dllimport)  UINT   SetDIBColorTable(      HDC hdc,
                                         UINT iStart,
                                         UINT cEntries,
                                          const  RGBQUAD *prgbq);
typedef struct tagCOLORADJUSTMENT {
    WORD caSize;
    WORD caFlags;
    WORD caIlluminantIndex;
    WORD caRedGamma;
    WORD caGreenGamma;
    WORD caBlueGamma;
    WORD caReferenceBlack;
    WORD caReferenceWhite;
    SHORT caContrast;
    SHORT caBrightness;
    SHORT caColorfulness;
    SHORT caRedGreenTint;
} COLORADJUSTMENT, *PCOLORADJUSTMENT,   *LPCOLORADJUSTMENT;

__declspec(dllimport)  BOOL   SetColorAdjustment(      HDC hdc,       const  COLORADJUSTMENT *lpca);
__declspec(dllimport)  BOOL   GetColorAdjustment(      HDC hdc,      LPCOLORADJUSTMENT lpca);
__declspec(dllimport)  HPALETTE   CreateHalftonePalette(        HDC hdc);


typedef BOOL ( * ABORTPROC)(      HDC,      int);
typedef struct _DOCINFOA {
    int cbSize;
    LPCSTR lpszDocName;
    LPCSTR lpszOutput;

    LPCSTR lpszDatatype;
    DWORD fwType;

} DOCINFOA, *LPDOCINFOA;
typedef struct _DOCINFOW {
    int cbSize;
    LPCWSTR lpszDocName;
    LPCWSTR lpszOutput;

    LPCWSTR lpszDatatype;
    DWORD fwType;

} DOCINFOW, *LPDOCINFOW;




typedef DOCINFOA DOCINFO;
typedef LPDOCINFOA LPDOCINFO;







  __declspec(dllimport)  int   StartDocA(     HDC hdc,       const  DOCINFOA *lpdi);
  __declspec(dllimport)  int   StartDocW(     HDC hdc,       const  DOCINFOW *lpdi);





  __declspec(dllimport)  int   EndDoc(     HDC hdc);
  __declspec(dllimport)  int   StartPage(     HDC hdc);
  __declspec(dllimport)  int   EndPage(     HDC hdc);
  __declspec(dllimport)  int   AbortDoc(     HDC hdc);
__declspec(dllimport)  int   SetAbortProc(     HDC hdc,      ABORTPROC proc);

__declspec(dllimport)  BOOL   AbortPath(     HDC hdc);
__declspec(dllimport)  BOOL   ArcTo(     HDC hdc,      int left,      int top,      int right,      int bottom,      int xr1,      int yr1,      int xr2,      int yr2);
__declspec(dllimport)  BOOL   BeginPath(     HDC hdc);
__declspec(dllimport)  BOOL   CloseFigure(     HDC hdc);
__declspec(dllimport)  BOOL   EndPath(     HDC hdc);
__declspec(dllimport)  BOOL   FillPath(     HDC hdc);
__declspec(dllimport)  BOOL   FlattenPath(     HDC hdc);
__declspec(dllimport)  int   GetPath(     HDC hdc,      LPPOINT apt,      LPBYTE aj, int cpt);
__declspec(dllimport)  HRGN   PathToRegion(     HDC hdc);
__declspec(dllimport)  BOOL   PolyDraw(     HDC hdc,         const  POINT * apt,         const  BYTE * aj,      int cpt);
__declspec(dllimport)  BOOL   SelectClipPath(     HDC hdc,      int mode);
__declspec(dllimport)  int   SetArcDirection(     HDC hdc,      int dir);
__declspec(dllimport)  BOOL   SetMiterLimit(     HDC hdc,      FLOAT limit,        PFLOAT old);
__declspec(dllimport)  BOOL   StrokeAndFillPath(     HDC hdc);
__declspec(dllimport)  BOOL   StrokePath(     HDC hdc);
__declspec(dllimport)  BOOL   WidenPath(     HDC hdc);
__declspec(dllimport)  HPEN   ExtCreatePen(      DWORD iPenStyle,
                                     DWORD cWidth,
                                      const  LOGBRUSH *plbrush,
                                     DWORD cStyle,
                                      const  DWORD *pstyle);
__declspec(dllimport)  BOOL   GetMiterLimit(     HDC hdc,      PFLOAT plimit);
__declspec(dllimport)  int   GetArcDirection(     HDC hdc);

__declspec(dllimport)  int   GetObjectA(     HANDLE h,      int c,        LPVOID pv);
__declspec(dllimport)  int   GetObjectW(     HANDLE h,      int c,        LPVOID pv);
  __declspec(dllimport)  BOOL   MoveToEx(      HDC hdc,      int x,      int y,        LPPOINT lppt);
  __declspec(dllimport)  BOOL   TextOutA(      HDC hdc,      int x,      int y,        LPCSTR lpString,      int c);
  __declspec(dllimport)  BOOL   TextOutW(      HDC hdc,      int x,      int y,        LPCWSTR lpString,      int c);





  __declspec(dllimport)  BOOL   ExtTextOutA(      HDC hdc,      int x,      int y,      UINT options,         const  RECT * lprect,          LPCSTR lpString,      UINT c,           const  INT * lpDx);
  __declspec(dllimport)  BOOL   ExtTextOutW(      HDC hdc,      int x,      int y,      UINT options,         const  RECT * lprect,          LPCWSTR lpString,      UINT c,           const  INT * lpDx);





__declspec(dllimport)  BOOL   PolyTextOutA(     HDC hdc,         const  POLYTEXTA * ppt,      int nstrings);
__declspec(dllimport)  BOOL   PolyTextOutW(     HDC hdc,         const  POLYTEXTW * ppt,      int nstrings);






__declspec(dllimport)  HRGN   CreatePolygonRgn(         const  POINT *pptl,
                                             int cPoint,
                                             int iMode);
__declspec(dllimport)  BOOL   DPtoLP(      HDC hdc,        LPPOINT lppt,      int c);
__declspec(dllimport)  BOOL   LPtoDP(      HDC hdc,        LPPOINT lppt,      int c);
  __declspec(dllimport)  BOOL   Polygon(     HDC hdc,         const  POINT *apt,      int cpt);
  __declspec(dllimport)  BOOL   Polyline(     HDC hdc,         const  POINT *apt,      int cpt);

__declspec(dllimport)  BOOL   PolyBezier(     HDC hdc,         const  POINT * apt,      DWORD cpt);
__declspec(dllimport)  BOOL   PolyBezierTo(     HDC hdc,         const  POINT * apt,      DWORD cpt);
__declspec(dllimport)  BOOL   PolylineTo(     HDC hdc,         const  POINT * apt,      DWORD cpt);

  __declspec(dllimport)  BOOL   SetViewportExtEx(      HDC hdc,      int x,      int y,        LPSIZE lpsz);
  __declspec(dllimport)  BOOL   SetViewportOrgEx(      HDC hdc,      int x,      int y,        LPPOINT lppt);
  __declspec(dllimport)  BOOL   SetWindowExtEx(      HDC hdc,      int x,      int y,        LPSIZE lpsz);
  __declspec(dllimport)  BOOL   SetWindowOrgEx(      HDC hdc,      int x,      int y,        LPPOINT lppt);

  __declspec(dllimport)  BOOL   OffsetViewportOrgEx(      HDC hdc,      int x,      int y,        LPPOINT lppt);
  __declspec(dllimport)  BOOL   OffsetWindowOrgEx(      HDC hdc,      int x,      int y,        LPPOINT lppt);
  __declspec(dllimport)  BOOL   ScaleViewportExtEx(      HDC hdc,      int xn,      int dx,      int yn,      int yd,        LPSIZE lpsz);
  __declspec(dllimport)  BOOL   ScaleWindowExtEx(      HDC hdc,      int xn,      int xd,      int yn,      int yd,        LPSIZE lpsz);
__declspec(dllimport)  BOOL   SetBitmapDimensionEx(      HBITMAP hbm,      int w,      int h,        LPSIZE lpsz);
__declspec(dllimport)  BOOL   SetBrushOrgEx(      HDC hdc,      int x,      int y,        LPPOINT lppt);

__declspec(dllimport)  int   GetTextFaceA(      HDC hdc,      int c,          LPSTR lpName);
__declspec(dllimport)  int   GetTextFaceW(      HDC hdc,      int c,          LPWSTR lpName);








typedef struct tagKERNINGPAIR {
   WORD wFirst;
   WORD wSecond;
   int iKernAmount;
} KERNINGPAIR, *LPKERNINGPAIR;

__declspec(dllimport)  DWORD   GetKerningPairsA(      HDC hdc,
                                             DWORD nPairs,
                                             LPKERNINGPAIR lpKernPair);
__declspec(dllimport)  DWORD   GetKerningPairsW(      HDC hdc,
                                             DWORD nPairs,
                                             LPKERNINGPAIR lpKernPair);







__declspec(dllimport)  BOOL   GetDCOrgEx(      HDC hdc,      LPPOINT lppt);
__declspec(dllimport)  BOOL   FixBrushOrgEx(      HDC hdc,      int x,      int y,        LPPOINT ptl);
__declspec(dllimport)  BOOL   UnrealizeObject(      HGDIOBJ h);

__declspec(dllimport)  BOOL   GdiFlush(void);
__declspec(dllimport)  DWORD   GdiSetBatchLimit(      DWORD dw);
__declspec(dllimport)  DWORD   GdiGetBatchLimit(void);








typedef int ( * ICMENUMPROCA)(LPSTR, LPARAM);
typedef int ( * ICMENUMPROCW)(LPWSTR, LPARAM);






__declspec(dllimport)  int   SetICMMode(      HDC hdc,      int mode);
__declspec(dllimport)  BOOL   CheckColorsInGamut(      HDC hdc,
                                                     LPRGBTRIPLE lpRGBTriple,
                                                     LPVOID dlpBuffer,
                                                     DWORD nCount);

__declspec(dllimport)  HCOLORSPACE   GetColorSpace(      HDC hdc);
__declspec(dllimport)  BOOL   GetLogColorSpaceA(      HCOLORSPACE hColorSpace,
                                                 LPLOGCOLORSPACEA lpBuffer,
                                                 DWORD nSize);
__declspec(dllimport)  BOOL   GetLogColorSpaceW(      HCOLORSPACE hColorSpace,
                                                 LPLOGCOLORSPACEW lpBuffer,
                                                 DWORD nSize);






__declspec(dllimport)  HCOLORSPACE   CreateColorSpaceA(      LPLOGCOLORSPACEA lplcs);
__declspec(dllimport)  HCOLORSPACE   CreateColorSpaceW(      LPLOGCOLORSPACEW lplcs);





__declspec(dllimport)  HCOLORSPACE   SetColorSpace(      HDC hdc,      HCOLORSPACE hcs);
__declspec(dllimport)  BOOL   DeleteColorSpace(      HCOLORSPACE hcs);
__declspec(dllimport)  BOOL   GetICMProfileA(      HDC hdc,
                                                 LPDWORD pBufSize,
                                                 LPSTR pszFilename);
__declspec(dllimport)  BOOL   GetICMProfileW(      HDC hdc,
                                                 LPDWORD pBufSize,
                                                 LPWSTR pszFilename);






__declspec(dllimport)  BOOL   SetICMProfileA(      HDC hdc,      LPSTR lpFileName);
__declspec(dllimport)  BOOL   SetICMProfileW(      HDC hdc,      LPWSTR lpFileName);





__declspec(dllimport)  BOOL   GetDeviceGammaRamp(      HDC hdc,      LPVOID lpRamp);
__declspec(dllimport)  BOOL   SetDeviceGammaRamp(      HDC hdc,        LPVOID lpRamp);
__declspec(dllimport)  BOOL   ColorMatchToTarget(      HDC hdc,      HDC hdcTarget,      DWORD action);
__declspec(dllimport)  int   EnumICMProfilesA(      HDC hdc,      ICMENUMPROCA proc,        LPARAM param);
__declspec(dllimport)  int   EnumICMProfilesW(      HDC hdc,      ICMENUMPROCW proc,        LPARAM param);






__declspec(dllimport)  BOOL   UpdateICMRegKeyA(   DWORD reserved,      LPSTR lpszCMID,      LPSTR lpszFileName,      UINT command);

__declspec(dllimport)  BOOL   UpdateICMRegKeyW(   DWORD reserved,      LPWSTR lpszCMID,      LPWSTR lpszFileName,      UINT command);




__declspec(dllimport)  BOOL   ColorCorrectPalette(      HDC hdc,      HPALETTE hPal,      DWORD deFirst,      DWORD num);
typedef struct tagEMR
{
    DWORD iType;
    DWORD nSize;

} EMR, *PEMR;



typedef struct tagEMRTEXT
{
    POINTL ptlReference;
    DWORD nChars;
    DWORD offString;
    DWORD fOptions;
    RECTL rcl;
    DWORD offDx;

} EMRTEXT, *PEMRTEXT;



typedef struct tagABORTPATH
{
    EMR emr;
} EMRABORTPATH, *PEMRABORTPATH,
  EMRBEGINPATH, *PEMRBEGINPATH,
  EMRENDPATH, *PEMRENDPATH,
  EMRCLOSEFIGURE, *PEMRCLOSEFIGURE,
  EMRFLATTENPATH, *PEMRFLATTENPATH,
  EMRWIDENPATH, *PEMRWIDENPATH,
  EMRSETMETARGN, *PEMRSETMETARGN,
  EMRSAVEDC, *PEMRSAVEDC,
  EMRREALIZEPALETTE, *PEMRREALIZEPALETTE;

typedef struct tagEMRSELECTCLIPPATH
{
    EMR emr;
    DWORD iMode;
} EMRSELECTCLIPPATH, *PEMRSELECTCLIPPATH,
  EMRSETBKMODE, *PEMRSETBKMODE,
  EMRSETMAPMODE, *PEMRSETMAPMODE,

  EMRSETLAYOUT, *PEMRSETLAYOUT,

  EMRSETPOLYFILLMODE, *PEMRSETPOLYFILLMODE,
  EMRSETROP2, *PEMRSETROP2,
  EMRSETSTRETCHBLTMODE, *PEMRSETSTRETCHBLTMODE,
  EMRSETICMMODE, *PEMRSETICMMODE,
  EMRSETTEXTALIGN, *PEMRSETTEXTALIGN;

typedef struct tagEMRSETMITERLIMIT
{
    EMR emr;
    FLOAT eMiterLimit;
} EMRSETMITERLIMIT, *PEMRSETMITERLIMIT;

typedef struct tagEMRRESTOREDC
{
    EMR emr;
    LONG iRelative;
} EMRRESTOREDC, *PEMRRESTOREDC;

typedef struct tagEMRSETARCDIRECTION
{
    EMR emr;
    DWORD iArcDirection;

} EMRSETARCDIRECTION, *PEMRSETARCDIRECTION;

typedef struct tagEMRSETMAPPERFLAGS
{
    EMR emr;
    DWORD dwFlags;
} EMRSETMAPPERFLAGS, *PEMRSETMAPPERFLAGS;

typedef struct tagEMRSETTEXTCOLOR
{
    EMR emr;
    COLORREF crColor;
} EMRSETBKCOLOR, *PEMRSETBKCOLOR,
  EMRSETTEXTCOLOR, *PEMRSETTEXTCOLOR;

typedef struct tagEMRSELECTOBJECT
{
    EMR emr;
    DWORD ihObject;
} EMRSELECTOBJECT, *PEMRSELECTOBJECT,
  EMRDELETEOBJECT, *PEMRDELETEOBJECT;

typedef struct tagEMRSELECTPALETTE
{
    EMR emr;
    DWORD ihPal;
} EMRSELECTPALETTE, *PEMRSELECTPALETTE;

typedef struct tagEMRRESIZEPALETTE
{
    EMR emr;
    DWORD ihPal;
    DWORD cEntries;
} EMRRESIZEPALETTE, *PEMRRESIZEPALETTE;

typedef struct tagEMRSETPALETTEENTRIES
{
    EMR emr;
    DWORD ihPal;
    DWORD iStart;
    DWORD cEntries;
    PALETTEENTRY aPalEntries[1];
} EMRSETPALETTEENTRIES, *PEMRSETPALETTEENTRIES;

typedef struct tagEMRSETCOLORADJUSTMENT
{
    EMR emr;
    COLORADJUSTMENT ColorAdjustment;
} EMRSETCOLORADJUSTMENT, *PEMRSETCOLORADJUSTMENT;

typedef struct tagEMRGDICOMMENT
{
    EMR emr;
    DWORD cbData;
    BYTE Data[1];
} EMRGDICOMMENT, *PEMRGDICOMMENT;

typedef struct tagEMREOF
{
    EMR emr;
    DWORD nPalEntries;
    DWORD offPalEntries;
    DWORD nSizeLast;


} EMREOF, *PEMREOF;

typedef struct tagEMRLINETO
{
    EMR emr;
    POINTL ptl;
} EMRLINETO, *PEMRLINETO,
  EMRMOVETOEX, *PEMRMOVETOEX;

typedef struct tagEMROFFSETCLIPRGN
{
    EMR emr;
    POINTL ptlOffset;
} EMROFFSETCLIPRGN, *PEMROFFSETCLIPRGN;

typedef struct tagEMRFILLPATH
{
    EMR emr;
    RECTL rclBounds;
} EMRFILLPATH, *PEMRFILLPATH,
  EMRSTROKEANDFILLPATH, *PEMRSTROKEANDFILLPATH,
  EMRSTROKEPATH, *PEMRSTROKEPATH;

typedef struct tagEMREXCLUDECLIPRECT
{
    EMR emr;
    RECTL rclClip;
} EMREXCLUDECLIPRECT, *PEMREXCLUDECLIPRECT,
  EMRINTERSECTCLIPRECT, *PEMRINTERSECTCLIPRECT;

typedef struct tagEMRSETVIEWPORTORGEX
{
    EMR emr;
    POINTL ptlOrigin;
} EMRSETVIEWPORTORGEX, *PEMRSETVIEWPORTORGEX,
  EMRSETWINDOWORGEX, *PEMRSETWINDOWORGEX,
  EMRSETBRUSHORGEX, *PEMRSETBRUSHORGEX;

typedef struct tagEMRSETVIEWPORTEXTEX
{
    EMR emr;
    SIZEL szlExtent;
} EMRSETVIEWPORTEXTEX, *PEMRSETVIEWPORTEXTEX,
  EMRSETWINDOWEXTEX, *PEMRSETWINDOWEXTEX;

typedef struct tagEMRSCALEVIEWPORTEXTEX
{
    EMR emr;
    LONG xNum;
    LONG xDenom;
    LONG yNum;
    LONG yDenom;
} EMRSCALEVIEWPORTEXTEX, *PEMRSCALEVIEWPORTEXTEX,
  EMRSCALEWINDOWEXTEX, *PEMRSCALEWINDOWEXTEX;

typedef struct tagEMRSETWORLDTRANSFORM
{
    EMR emr;
    XFORM xform;
} EMRSETWORLDTRANSFORM, *PEMRSETWORLDTRANSFORM;

typedef struct tagEMRMODIFYWORLDTRANSFORM
{
    EMR emr;
    XFORM xform;
    DWORD iMode;
} EMRMODIFYWORLDTRANSFORM, *PEMRMODIFYWORLDTRANSFORM;

typedef struct tagEMRSETPIXELV
{
    EMR emr;
    POINTL ptlPixel;
    COLORREF crColor;
} EMRSETPIXELV, *PEMRSETPIXELV;

typedef struct tagEMREXTFLOODFILL
{
    EMR emr;
    POINTL ptlStart;
    COLORREF crColor;
    DWORD iMode;
} EMREXTFLOODFILL, *PEMREXTFLOODFILL;

typedef struct tagEMRELLIPSE
{
    EMR emr;
    RECTL rclBox;
} EMRELLIPSE, *PEMRELLIPSE,
  EMRRECTANGLE, *PEMRRECTANGLE;


typedef struct tagEMRROUNDRECT
{
    EMR emr;
    RECTL rclBox;
    SIZEL szlCorner;
} EMRROUNDRECT, *PEMRROUNDRECT;

typedef struct tagEMRARC
{
    EMR emr;
    RECTL rclBox;
    POINTL ptlStart;
    POINTL ptlEnd;
} EMRARC, *PEMRARC,
  EMRARCTO, *PEMRARCTO,
  EMRCHORD, *PEMRCHORD,
  EMRPIE, *PEMRPIE;

typedef struct tagEMRANGLEARC
{
    EMR emr;
    POINTL ptlCenter;
    DWORD nRadius;
    FLOAT eStartAngle;
    FLOAT eSweepAngle;
} EMRANGLEARC, *PEMRANGLEARC;

typedef struct tagEMRPOLYLINE
{
    EMR emr;
    RECTL rclBounds;
    DWORD cptl;
    POINTL aptl[1];
} EMRPOLYLINE, *PEMRPOLYLINE,
  EMRPOLYBEZIER, *PEMRPOLYBEZIER,
  EMRPOLYGON, *PEMRPOLYGON,
  EMRPOLYBEZIERTO, *PEMRPOLYBEZIERTO,
  EMRPOLYLINETO, *PEMRPOLYLINETO;

typedef struct tagEMRPOLYLINE16
{
    EMR emr;
    RECTL rclBounds;
    DWORD cpts;
    POINTS apts[1];
} EMRPOLYLINE16, *PEMRPOLYLINE16,
  EMRPOLYBEZIER16, *PEMRPOLYBEZIER16,
  EMRPOLYGON16, *PEMRPOLYGON16,
  EMRPOLYBEZIERTO16, *PEMRPOLYBEZIERTO16,
  EMRPOLYLINETO16, *PEMRPOLYLINETO16;

typedef struct tagEMRPOLYDRAW
{
    EMR emr;
    RECTL rclBounds;
    DWORD cptl;
    POINTL aptl[1];
    BYTE abTypes[1];
} EMRPOLYDRAW, *PEMRPOLYDRAW;

typedef struct tagEMRPOLYDRAW16
{
    EMR emr;
    RECTL rclBounds;
    DWORD cpts;
    POINTS apts[1];
    BYTE abTypes[1];
} EMRPOLYDRAW16, *PEMRPOLYDRAW16;

typedef struct tagEMRPOLYPOLYLINE
{
    EMR emr;
    RECTL rclBounds;
    DWORD nPolys;
    DWORD cptl;
    DWORD aPolyCounts[1];
    POINTL aptl[1];
} EMRPOLYPOLYLINE, *PEMRPOLYPOLYLINE,
  EMRPOLYPOLYGON, *PEMRPOLYPOLYGON;

typedef struct tagEMRPOLYPOLYLINE16
{
    EMR emr;
    RECTL rclBounds;
    DWORD nPolys;
    DWORD cpts;
    DWORD aPolyCounts[1];
    POINTS apts[1];
} EMRPOLYPOLYLINE16, *PEMRPOLYPOLYLINE16,
  EMRPOLYPOLYGON16, *PEMRPOLYPOLYGON16;

typedef struct tagEMRINVERTRGN
{
    EMR emr;
    RECTL rclBounds;
    DWORD cbRgnData;
    BYTE RgnData[1];
} EMRINVERTRGN, *PEMRINVERTRGN,
  EMRPAINTRGN, *PEMRPAINTRGN;

typedef struct tagEMRFILLRGN
{
    EMR emr;
    RECTL rclBounds;
    DWORD cbRgnData;
    DWORD ihBrush;
    BYTE RgnData[1];
} EMRFILLRGN, *PEMRFILLRGN;

typedef struct tagEMRFRAMERGN
{
    EMR emr;
    RECTL rclBounds;
    DWORD cbRgnData;
    DWORD ihBrush;
    SIZEL szlStroke;
    BYTE RgnData[1];
} EMRFRAMERGN, *PEMRFRAMERGN;

typedef struct tagEMREXTSELECTCLIPRGN
{
    EMR emr;
    DWORD cbRgnData;
    DWORD iMode;
    BYTE RgnData[1];
} EMREXTSELECTCLIPRGN, *PEMREXTSELECTCLIPRGN;

typedef struct tagEMREXTTEXTOUTA
{
    EMR emr;
    RECTL rclBounds;
    DWORD iGraphicsMode;
    FLOAT exScale;
    FLOAT eyScale;
    EMRTEXT emrtext;

} EMREXTTEXTOUTA, *PEMREXTTEXTOUTA,
  EMREXTTEXTOUTW, *PEMREXTTEXTOUTW;

typedef struct tagEMRPOLYTEXTOUTA
{
    EMR emr;
    RECTL rclBounds;
    DWORD iGraphicsMode;
    FLOAT exScale;
    FLOAT eyScale;
    LONG cStrings;
    EMRTEXT aemrtext[1];

} EMRPOLYTEXTOUTA, *PEMRPOLYTEXTOUTA,
  EMRPOLYTEXTOUTW, *PEMRPOLYTEXTOUTW;

typedef struct tagEMRBITBLT
{
    EMR emr;
    RECTL rclBounds;
    LONG xDest;
    LONG yDest;
    LONG cxDest;
    LONG cyDest;
    DWORD dwRop;
    LONG xSrc;
    LONG ySrc;
    XFORM xformSrc;
    COLORREF crBkColorSrc;
    DWORD iUsageSrc;

    DWORD offBmiSrc;
    DWORD cbBmiSrc;
    DWORD offBitsSrc;
    DWORD cbBitsSrc;
} EMRBITBLT, *PEMRBITBLT;

typedef struct tagEMRSTRETCHBLT
{
    EMR emr;
    RECTL rclBounds;
    LONG xDest;
    LONG yDest;
    LONG cxDest;
    LONG cyDest;
    DWORD dwRop;
    LONG xSrc;
    LONG ySrc;
    XFORM xformSrc;
    COLORREF crBkColorSrc;
    DWORD iUsageSrc;

    DWORD offBmiSrc;
    DWORD cbBmiSrc;
    DWORD offBitsSrc;
    DWORD cbBitsSrc;
    LONG cxSrc;
    LONG cySrc;
} EMRSTRETCHBLT, *PEMRSTRETCHBLT;

typedef struct tagEMRMASKBLT
{
    EMR emr;
    RECTL rclBounds;
    LONG xDest;
    LONG yDest;
    LONG cxDest;
    LONG cyDest;
    DWORD dwRop;
    LONG xSrc;
    LONG ySrc;
    XFORM xformSrc;
    COLORREF crBkColorSrc;
    DWORD iUsageSrc;

    DWORD offBmiSrc;
    DWORD cbBmiSrc;
    DWORD offBitsSrc;
    DWORD cbBitsSrc;
    LONG xMask;
    LONG yMask;
    DWORD iUsageMask;
    DWORD offBmiMask;
    DWORD cbBmiMask;
    DWORD offBitsMask;
    DWORD cbBitsMask;
} EMRMASKBLT, *PEMRMASKBLT;

typedef struct tagEMRPLGBLT
{
    EMR emr;
    RECTL rclBounds;
    POINTL aptlDest[3];
    LONG xSrc;
    LONG ySrc;
    LONG cxSrc;
    LONG cySrc;
    XFORM xformSrc;
    COLORREF crBkColorSrc;
    DWORD iUsageSrc;

    DWORD offBmiSrc;
    DWORD cbBmiSrc;
    DWORD offBitsSrc;
    DWORD cbBitsSrc;
    LONG xMask;
    LONG yMask;
    DWORD iUsageMask;
    DWORD offBmiMask;
    DWORD cbBmiMask;
    DWORD offBitsMask;
    DWORD cbBitsMask;
} EMRPLGBLT, *PEMRPLGBLT;

typedef struct tagEMRSETDIBITSTODEVICE
{
    EMR emr;
    RECTL rclBounds;
    LONG xDest;
    LONG yDest;
    LONG xSrc;
    LONG ySrc;
    LONG cxSrc;
    LONG cySrc;
    DWORD offBmiSrc;
    DWORD cbBmiSrc;
    DWORD offBitsSrc;
    DWORD cbBitsSrc;
    DWORD iUsageSrc;
    DWORD iStartScan;
    DWORD cScans;
} EMRSETDIBITSTODEVICE, *PEMRSETDIBITSTODEVICE;

typedef struct tagEMRSTRETCHDIBITS
{
    EMR emr;
    RECTL rclBounds;
    LONG xDest;
    LONG yDest;
    LONG xSrc;
    LONG ySrc;
    LONG cxSrc;
    LONG cySrc;
    DWORD offBmiSrc;
    DWORD cbBmiSrc;
    DWORD offBitsSrc;
    DWORD cbBitsSrc;
    DWORD iUsageSrc;
    DWORD dwRop;
    LONG cxDest;
    LONG cyDest;
} EMRSTRETCHDIBITS, *PEMRSTRETCHDIBITS;

typedef struct tagEMREXTCREATEFONTINDIRECTW
{
    EMR emr;
    DWORD ihFont;
    EXTLOGFONTW elfw;
} EMREXTCREATEFONTINDIRECTW, *PEMREXTCREATEFONTINDIRECTW;

typedef struct tagEMRCREATEPALETTE
{
    EMR emr;
    DWORD ihPal;
    LOGPALETTE lgpl;

} EMRCREATEPALETTE, *PEMRCREATEPALETTE;

typedef struct tagEMRCREATEPEN
{
    EMR emr;
    DWORD ihPen;
    LOGPEN lopn;
} EMRCREATEPEN, *PEMRCREATEPEN;

typedef struct tagEMREXTCREATEPEN
{
    EMR emr;
    DWORD ihPen;
    DWORD offBmi;
    DWORD cbBmi;


    DWORD offBits;
    DWORD cbBits;
    EXTLOGPEN elp;
} EMREXTCREATEPEN, *PEMREXTCREATEPEN;

typedef struct tagEMRCREATEBRUSHINDIRECT
{
    EMR emr;
    DWORD ihBrush;
    LOGBRUSH32 lb;

} EMRCREATEBRUSHINDIRECT, *PEMRCREATEBRUSHINDIRECT;

typedef struct tagEMRCREATEMONOBRUSH
{
    EMR emr;
    DWORD ihBrush;
    DWORD iUsage;
    DWORD offBmi;
    DWORD cbBmi;
    DWORD offBits;
    DWORD cbBits;
} EMRCREATEMONOBRUSH, *PEMRCREATEMONOBRUSH;

typedef struct tagEMRCREATEDIBPATTERNBRUSHPT
{
    EMR emr;
    DWORD ihBrush;
    DWORD iUsage;
    DWORD offBmi;
    DWORD cbBmi;


    DWORD offBits;
    DWORD cbBits;
} EMRCREATEDIBPATTERNBRUSHPT, *PEMRCREATEDIBPATTERNBRUSHPT;

typedef struct tagEMRFORMAT
{
    DWORD dSignature;
    DWORD nVersion;
    DWORD cbData;
    DWORD offData;

} EMRFORMAT, *PEMRFORMAT;



typedef struct tagEMRGLSRECORD
{
    EMR emr;
    DWORD cbData;
    BYTE Data[1];
} EMRGLSRECORD, *PEMRGLSRECORD;

typedef struct tagEMRGLSBOUNDEDRECORD
{
    EMR emr;
    RECTL rclBounds;
    DWORD cbData;
    BYTE Data[1];
} EMRGLSBOUNDEDRECORD, *PEMRGLSBOUNDEDRECORD;

typedef struct tagEMRPIXELFORMAT
{
    EMR emr;
    PIXELFORMATDESCRIPTOR pfd;
} EMRPIXELFORMAT, *PEMRPIXELFORMAT;

typedef struct tagEMRCREATECOLORSPACE
{
    EMR emr;
    DWORD ihCS;
    LOGCOLORSPACEA lcs;
} EMRCREATECOLORSPACE, *PEMRCREATECOLORSPACE;

typedef struct tagEMRSETCOLORSPACE
{
    EMR emr;
    DWORD ihCS;
} EMRSETCOLORSPACE, *PEMRSETCOLORSPACE,
  EMRSELECTCOLORSPACE, *PEMRSELECTCOLORSPACE,
  EMRDELETECOLORSPACE, *PEMRDELETECOLORSPACE;





typedef struct tagEMREXTESCAPE
{
    EMR emr;
    INT iEscape;
    INT cbEscData;
    BYTE EscData[1];
} EMREXTESCAPE, *PEMREXTESCAPE,
  EMRDRAWESCAPE, *PEMRDRAWESCAPE;

typedef struct tagEMRNAMEDESCAPE
{
    EMR emr;
    INT iEscape;
    INT cbDriver;
    INT cbEscData;
    BYTE EscData[1];
} EMRNAMEDESCAPE, *PEMRNAMEDESCAPE;



typedef struct tagEMRSETICMPROFILE
{
    EMR emr;
    DWORD dwFlags;
    DWORD cbName;
    DWORD cbData;
    BYTE Data[1];
} EMRSETICMPROFILE, *PEMRSETICMPROFILE,
  EMRSETICMPROFILEA, *PEMRSETICMPROFILEA,
  EMRSETICMPROFILEW, *PEMRSETICMPROFILEW;



typedef struct tagEMRCREATECOLORSPACEW
{
    EMR emr;
    DWORD ihCS;
    LOGCOLORSPACEW lcs;
    DWORD dwFlags;
    DWORD cbData;
    BYTE Data[1];
} EMRCREATECOLORSPACEW, *PEMRCREATECOLORSPACEW;



typedef struct tagCOLORMATCHTOTARGET
{
    EMR emr;
    DWORD dwAction;
    DWORD dwFlags;
    DWORD cbName;
    DWORD cbData;
    BYTE Data[1];
} EMRCOLORMATCHTOTARGET, *PEMRCOLORMATCHTOTARGET;

typedef struct tagCOLORCORRECTPALETTE
{
    EMR emr;
    DWORD ihPalette;
    DWORD nFirstEntry;
    DWORD nPalEntries;
    DWORD nReserved;
} EMRCOLORCORRECTPALETTE, *PEMRCOLORCORRECTPALETTE;

typedef struct tagEMRALPHABLEND
{
    EMR emr;
    RECTL rclBounds;
    LONG xDest;
    LONG yDest;
    LONG cxDest;
    LONG cyDest;
    DWORD dwRop;
    LONG xSrc;
    LONG ySrc;
    XFORM xformSrc;
    COLORREF crBkColorSrc;
    DWORD iUsageSrc;

    DWORD offBmiSrc;
    DWORD cbBmiSrc;
    DWORD offBitsSrc;
    DWORD cbBitsSrc;
    LONG cxSrc;
    LONG cySrc;
} EMRALPHABLEND, *PEMRALPHABLEND;

typedef struct tagEMRGRADIENTFILL
{
    EMR emr;
    RECTL rclBounds;
    DWORD nVer;
    DWORD nTri;
    ULONG ulMode;
    TRIVERTEX Ver[1];
}EMRGRADIENTFILL,*PEMRGRADIENTFILL;

typedef struct tagEMRTRANSPARENTBLT
{
    EMR emr;
    RECTL rclBounds;
    LONG xDest;
    LONG yDest;
    LONG cxDest;
    LONG cyDest;
    DWORD dwRop;
    LONG xSrc;
    LONG ySrc;
    XFORM xformSrc;
    COLORREF crBkColorSrc;
    DWORD iUsageSrc;

    DWORD offBmiSrc;
    DWORD cbBmiSrc;
    DWORD offBitsSrc;
    DWORD cbBitsSrc;
    LONG cxSrc;
    LONG cySrc;
} EMRTRANSPARENTBLT, *PEMRTRANSPARENTBLT;
__declspec(dllimport)  BOOL   wglCopyContext(HGLRC, HGLRC, UINT);
__declspec(dllimport)  HGLRC   wglCreateContext(HDC);
__declspec(dllimport)  HGLRC   wglCreateLayerContext(HDC, int);
__declspec(dllimport)  BOOL   wglDeleteContext(HGLRC);
__declspec(dllimport)  HGLRC   wglGetCurrentContext( void );
__declspec(dllimport)  HDC   wglGetCurrentDC( void );
__declspec(dllimport)  PROC   wglGetProcAddress(LPCSTR);
__declspec(dllimport)  BOOL   wglMakeCurrent(HDC, HGLRC);
__declspec(dllimport)  BOOL   wglShareLists(HGLRC, HGLRC);
__declspec(dllimport)  BOOL   wglUseFontBitmapsA(HDC, DWORD, DWORD, DWORD);
__declspec(dllimport)  BOOL   wglUseFontBitmapsW(HDC, DWORD, DWORD, DWORD);





__declspec(dllimport)  BOOL   SwapBuffers(HDC);

typedef struct _POINTFLOAT {
    FLOAT x;
    FLOAT y;
} POINTFLOAT, *PPOINTFLOAT;

typedef struct _GLYPHMETRICSFLOAT {
    FLOAT gmfBlackBoxX;
    FLOAT gmfBlackBoxY;
    POINTFLOAT gmfptGlyphOrigin;
    FLOAT gmfCellIncX;
    FLOAT gmfCellIncY;
} GLYPHMETRICSFLOAT, *PGLYPHMETRICSFLOAT,   *LPGLYPHMETRICSFLOAT;



__declspec(dllimport)  BOOL   wglUseFontOutlinesA(HDC, DWORD, DWORD, DWORD, FLOAT,
                                           FLOAT, int, LPGLYPHMETRICSFLOAT);
__declspec(dllimport)  BOOL   wglUseFontOutlinesW(HDC, DWORD, DWORD, DWORD, FLOAT,
                                           FLOAT, int, LPGLYPHMETRICSFLOAT);







typedef struct tagLAYERPLANEDESCRIPTOR {
    WORD nSize;
    WORD nVersion;
    DWORD dwFlags;
    BYTE iPixelType;
    BYTE cColorBits;
    BYTE cRedBits;
    BYTE cRedShift;
    BYTE cGreenBits;
    BYTE cGreenShift;
    BYTE cBlueBits;
    BYTE cBlueShift;
    BYTE cAlphaBits;
    BYTE cAlphaShift;
    BYTE cAccumBits;
    BYTE cAccumRedBits;
    BYTE cAccumGreenBits;
    BYTE cAccumBlueBits;
    BYTE cAccumAlphaBits;
    BYTE cDepthBits;
    BYTE cStencilBits;
    BYTE cAuxBuffers;
    BYTE iLayerPlane;
    BYTE bReserved;
    COLORREF crTransparent;
} LAYERPLANEDESCRIPTOR, *PLAYERPLANEDESCRIPTOR,   *LPLAYERPLANEDESCRIPTOR;
__declspec(dllimport)  BOOL   wglDescribeLayerPlane(HDC, int, int, UINT,
                                             LPLAYERPLANEDESCRIPTOR);
__declspec(dllimport)  int   wglSetLayerPaletteEntries(HDC, int, int, int,
                                                 const  COLORREF *);
__declspec(dllimport)  int   wglGetLayerPaletteEntries(HDC, int, int, int,
                                                 COLORREF *);
__declspec(dllimport)  BOOL   wglRealizeLayerPalette(HDC, int, BOOL);
__declspec(dllimport)  BOOL   wglSwapLayerBuffers(HDC, UINT);



typedef struct _WGLSWAP
{
    HDC hdc;
    UINT uiFlags;
} WGLSWAP, *PWGLSWAP,   *LPWGLSWAP;



__declspec(dllimport)  DWORD   wglSwapMultipleBuffers(UINT,  const  WGLSWAP *);



typedef HANDLE HDWP;
typedef  void  MENUTEMPLATEA;
typedef  void  MENUTEMPLATEW;



typedef MENUTEMPLATEA MENUTEMPLATE;

typedef PVOID LPMENUTEMPLATEA;
typedef PVOID LPMENUTEMPLATEW;



typedef LPMENUTEMPLATEA LPMENUTEMPLATE;


typedef LRESULT ( * WNDPROC)(HWND, UINT, WPARAM, LPARAM);



typedef INT_PTR ( * DLGPROC)(HWND, UINT, WPARAM, LPARAM);
typedef  void  ( * TIMERPROC)(HWND, UINT, UINT_PTR, DWORD);
typedef BOOL ( * GRAYSTRINGPROC)(HDC, LPARAM, int);
typedef BOOL ( * WNDENUMPROC)(HWND, LPARAM);
typedef LRESULT ( * HOOKPROC)(int code, WPARAM wParam, LPARAM lParam);
typedef  void  ( * SENDASYNCPROC)(HWND, UINT, ULONG_PTR, LRESULT);

typedef BOOL ( * PROPENUMPROCA)(HWND, LPCSTR, HANDLE);
typedef BOOL ( * PROPENUMPROCW)(HWND, LPCWSTR, HANDLE);

typedef BOOL ( * PROPENUMPROCEXA)(HWND, LPSTR, HANDLE, ULONG_PTR);
typedef BOOL ( * PROPENUMPROCEXW)(HWND, LPWSTR, HANDLE, ULONG_PTR);

typedef int ( * EDITWORDBREAKPROCA)(LPSTR lpch, int ichCurrent, int cch, int code);
typedef int ( * EDITWORDBREAKPROCW)(LPWSTR lpch, int ichCurrent, int cch, int code);


typedef BOOL ( * DRAWSTATEPROC)(HDC hdc, LPARAM lData, WPARAM wData, int cx, int cy);
typedef PROPENUMPROCA PROPENUMPROC;
typedef PROPENUMPROCEXA PROPENUMPROCEX;
typedef EDITWORDBREAKPROCA EDITWORDBREAKPROC;




typedef BOOL ( * NAMEENUMPROCA)(LPSTR, LPARAM);
typedef BOOL ( * NAMEENUMPROCW)(LPWSTR, LPARAM);

typedef NAMEENUMPROCA WINSTAENUMPROCA;
typedef NAMEENUMPROCA DESKTOPENUMPROCA;
typedef NAMEENUMPROCW WINSTAENUMPROCW;
typedef NAMEENUMPROCW DESKTOPENUMPROCW;
typedef WINSTAENUMPROCA WINSTAENUMPROC;
typedef DESKTOPENUMPROCA DESKTOPENUMPROC;
__declspec(dllimport)
int

wvsprintfA(
     LPSTR,
       LPCSTR,
     va_list arglist);
__declspec(dllimport)
int

wvsprintfW(
     LPWSTR,
       LPCWSTR,
     va_list arglist);






__declspec(dllimport)
int

wsprintfA(
     LPSTR,
       LPCSTR,
    ...);
__declspec(dllimport)
int

wsprintfW(
     LPWSTR,
       LPCWSTR,
    ...);
typedef struct tagCBT_CREATEWNDA
{
    struct tagCREATESTRUCTA *lpcs;
    HWND hwndInsertAfter;
} CBT_CREATEWNDA, *LPCBT_CREATEWNDA;
typedef struct tagCBT_CREATEWNDW
{
    struct tagCREATESTRUCTW *lpcs;
    HWND hwndInsertAfter;
} CBT_CREATEWNDW, *LPCBT_CREATEWNDW;




typedef CBT_CREATEWNDA CBT_CREATEWND;
typedef LPCBT_CREATEWNDA LPCBT_CREATEWND;
typedef struct tagCBTACTIVATESTRUCT
{
    BOOL fMouse;
    HWND hWndActive;
} CBTACTIVATESTRUCT, *LPCBTACTIVATESTRUCT;
typedef struct tagWTSSESSION_NOTIFICATION
{
    DWORD cbSize;
    DWORD dwSessionId;

} WTSSESSION_NOTIFICATION, *PWTSSESSION_NOTIFICATION;
typedef struct
{
    HWND hwnd;
    RECT rc;
} SHELLHOOKINFO, *LPSHELLHOOKINFO;
typedef struct tagEVENTMSG {
    UINT message;
    UINT paramL;
    UINT paramH;
    DWORD time;
    HWND hwnd;
} EVENTMSG, *PEVENTMSGMSG,   *NPEVENTMSGMSG,   *LPEVENTMSGMSG;

typedef struct tagEVENTMSG *PEVENTMSG,   *NPEVENTMSG,   *LPEVENTMSG;
typedef struct tagCWPSTRUCT {
    LPARAM lParam;
    WPARAM wParam;
    UINT message;
    HWND hwnd;
} CWPSTRUCT, *PCWPSTRUCT,   *NPCWPSTRUCT,   *LPCWPSTRUCT;
typedef struct tagCWPRETSTRUCT {
    LRESULT lResult;
    LPARAM lParam;
    WPARAM wParam;
    UINT message;
    HWND hwnd;
} CWPRETSTRUCT, *PCWPRETSTRUCT,   *NPCWPRETSTRUCT,   *LPCWPRETSTRUCT;
typedef struct tagKBDLLHOOKSTRUCT {
    DWORD vkCode;
    DWORD scanCode;
    DWORD flags;
    DWORD time;
    ULONG_PTR dwExtraInfo;
} KBDLLHOOKSTRUCT,   *LPKBDLLHOOKSTRUCT, *PKBDLLHOOKSTRUCT;
typedef struct tagMSLLHOOKSTRUCT {
    POINT pt;
    DWORD mouseData;
    DWORD flags;
    DWORD time;
    ULONG_PTR dwExtraInfo;
} MSLLHOOKSTRUCT,   *LPMSLLHOOKSTRUCT, *PMSLLHOOKSTRUCT;
typedef struct tagDEBUGHOOKINFO
{
    DWORD idThread;
    DWORD idThreadInstaller;
    LPARAM lParam;
    WPARAM wParam;
    int code;
} DEBUGHOOKINFO, *PDEBUGHOOKINFO,   *NPDEBUGHOOKINFO,  * LPDEBUGHOOKINFO;
typedef struct tagMOUSEHOOKSTRUCT {
    POINT pt;
    HWND hwnd;
    UINT wHitTestCode;
    ULONG_PTR dwExtraInfo;
} MOUSEHOOKSTRUCT,   *LPMOUSEHOOKSTRUCT, *PMOUSEHOOKSTRUCT;








typedef struct tagMOUSEHOOKSTRUCTEX
{
    MOUSEHOOKSTRUCT  s ;
    DWORD mouseData;
} MOUSEHOOKSTRUCTEX, *LPMOUSEHOOKSTRUCTEX, *PMOUSEHOOKSTRUCTEX;
typedef struct tagHARDWAREHOOKSTRUCT {
    HWND hwnd;
    UINT message;
    WPARAM wParam;
    LPARAM lParam;
} HARDWAREHOOKSTRUCT,   *LPHARDWAREHOOKSTRUCT, *PHARDWAREHOOKSTRUCT;
__declspec(dllimport)
HKL

LoadKeyboardLayoutA(
     LPCSTR pwszKLID,
     UINT Flags);
__declspec(dllimport)
HKL

LoadKeyboardLayoutW(
     LPCWSTR pwszKLID,
     UINT Flags);








__declspec(dllimport)
HKL

ActivateKeyboardLayout(
     HKL hkl,
     UINT Flags);
__declspec(dllimport)
int

ToUnicodeEx(
     UINT wVirtKey,
     UINT wScanCode,
      const  BYTE *lpKeyState,
     LPWSTR pwszBuff,
     int cchBuff,
     UINT wFlags,
     HKL dwhkl);


__declspec(dllimport)
BOOL

UnloadKeyboardLayout(
     HKL hkl);

__declspec(dllimport)
BOOL

GetKeyboardLayoutNameA(
     LPSTR pwszKLID);
__declspec(dllimport)
BOOL

GetKeyboardLayoutNameW(
     LPWSTR pwszKLID);







__declspec(dllimport)
int

GetKeyboardLayoutList(
     int nBuff,
     HKL   *lpList);

__declspec(dllimport)
HKL

GetKeyboardLayout(
     DWORD idThread);





typedef struct tagMOUSEMOVEPOINT {
    int x;
    int y;
    DWORD time;
    ULONG_PTR dwExtraInfo;
} MOUSEMOVEPOINT, *PMOUSEMOVEPOINT,  * LPMOUSEMOVEPOINT;
__declspec(dllimport)
int

GetMouseMovePointsEx(
     UINT cbSize,
     LPMOUSEMOVEPOINT lppt,
     LPMOUSEMOVEPOINT lpptBuf,
     int nBufPoints,
     DWORD resolution);
__declspec(dllimport)
HDESK

CreateDesktopA(
     LPCSTR lpszDesktop,
     LPCSTR lpszDevice,
     LPDEVMODEA pDevmode,
     DWORD dwFlags,
     ACCESS_MASK dwDesiredAccess,
     LPSECURITY_ATTRIBUTES lpsa);
__declspec(dllimport)
HDESK

CreateDesktopW(
     LPCWSTR lpszDesktop,
     LPCWSTR lpszDevice,
     LPDEVMODEW pDevmode,
     DWORD dwFlags,
     ACCESS_MASK dwDesiredAccess,
     LPSECURITY_ATTRIBUTES lpsa);






__declspec(dllimport)
HDESK

CreateDesktopExA(
     LPCSTR lpszDesktop,
     LPCSTR lpszDevice,
     LPDEVMODEA pDevmode,
     DWORD dwFlags,
     ACCESS_MASK dwDesiredAccess,
     LPSECURITY_ATTRIBUTES lpsa,
     ULONG ulHeapSize,
     PVOID pvoid);
__declspec(dllimport)
HDESK

CreateDesktopExW(
     LPCWSTR lpszDesktop,
     LPCWSTR lpszDevice,
     LPDEVMODEW pDevmode,
     DWORD dwFlags,
     ACCESS_MASK dwDesiredAccess,
     LPSECURITY_ATTRIBUTES lpsa,
     ULONG ulHeapSize,
     PVOID pvoid);









__declspec(dllimport)
HDESK

OpenDesktopA(
     LPCSTR lpszDesktop,
     DWORD dwFlags,
     BOOL fInherit,
     ACCESS_MASK dwDesiredAccess);
__declspec(dllimport)
HDESK

OpenDesktopW(
     LPCWSTR lpszDesktop,
     DWORD dwFlags,
     BOOL fInherit,
     ACCESS_MASK dwDesiredAccess);






__declspec(dllimport)
HDESK

OpenInputDesktop(
     DWORD dwFlags,
     BOOL fInherit,
     ACCESS_MASK dwDesiredAccess);


__declspec(dllimport)
BOOL

EnumDesktopsA(
     HWINSTA hwinsta,
     DESKTOPENUMPROCA lpEnumFunc,
     LPARAM lParam);
__declspec(dllimport)
BOOL

EnumDesktopsW(
     HWINSTA hwinsta,
     DESKTOPENUMPROCW lpEnumFunc,
     LPARAM lParam);






__declspec(dllimport)
BOOL

EnumDesktopWindows(
     HDESK hDesktop,
     WNDENUMPROC lpfn,
     LPARAM lParam);

__declspec(dllimport)
BOOL

SwitchDesktop(
     HDESK hDesktop);


__declspec(dllimport)
BOOL

SetThreadDesktop(
      HDESK hDesktop);

__declspec(dllimport)
BOOL

CloseDesktop(
     HDESK hDesktop);

__declspec(dllimport)
HDESK

GetThreadDesktop(
     DWORD dwThreadId);
__declspec(dllimport)
HWINSTA

CreateWindowStationA(
     LPCSTR lpwinsta,
     DWORD dwFlags,
     ACCESS_MASK dwDesiredAccess,
     LPSECURITY_ATTRIBUTES lpsa);
__declspec(dllimport)
HWINSTA

CreateWindowStationW(
     LPCWSTR lpwinsta,
     DWORD dwFlags,
     ACCESS_MASK dwDesiredAccess,
     LPSECURITY_ATTRIBUTES lpsa);






__declspec(dllimport)
HWINSTA

OpenWindowStationA(
     LPCSTR lpszWinSta,
     BOOL fInherit,
     ACCESS_MASK dwDesiredAccess);
__declspec(dllimport)
HWINSTA

OpenWindowStationW(
     LPCWSTR lpszWinSta,
     BOOL fInherit,
     ACCESS_MASK dwDesiredAccess);






__declspec(dllimport)
BOOL

EnumWindowStationsA(
     WINSTAENUMPROCA lpEnumFunc,
     LPARAM lParam);
__declspec(dllimport)
BOOL

EnumWindowStationsW(
     WINSTAENUMPROCW lpEnumFunc,
     LPARAM lParam);






__declspec(dllimport)
BOOL

CloseWindowStation(
     HWINSTA hWinSta);

__declspec(dllimport)
BOOL

SetProcessWindowStation(
     HWINSTA hWinSta);

__declspec(dllimport)
HWINSTA

GetProcessWindowStation(
    void );




__declspec(dllimport)
BOOL

SetUserObjectSecurity(
     HANDLE hObj,
     PSECURITY_INFORMATION pSIRequested,
     PSECURITY_DESCRIPTOR pSID);

__declspec(dllimport)
BOOL

GetUserObjectSecurity(
     HANDLE hObj,
     PSECURITY_INFORMATION pSIRequested,
     PSECURITY_DESCRIPTOR pSID,
     DWORD nLength,
     LPDWORD lpnLengthNeeded);










typedef struct tagUSEROBJECTFLAGS {
    BOOL fInherit;
    BOOL fReserved;
    DWORD dwFlags;
} USEROBJECTFLAGS, *PUSEROBJECTFLAGS;

__declspec(dllimport)
BOOL

GetUserObjectInformationA(
     HANDLE hObj,
     int nIndex,
     PVOID pvInfo,
     DWORD nLength,
     LPDWORD lpnLengthNeeded);
__declspec(dllimport)
BOOL

GetUserObjectInformationW(
     HANDLE hObj,
     int nIndex,
     PVOID pvInfo,
     DWORD nLength,
     LPDWORD lpnLengthNeeded);






__declspec(dllimport)
BOOL

SetUserObjectInformationA(
     HANDLE hObj,
     int nIndex,
     PVOID pvInfo,
     DWORD nLength);
__declspec(dllimport)
BOOL

SetUserObjectInformationW(
     HANDLE hObj,
     int nIndex,
     PVOID pvInfo,
     DWORD nLength);









typedef struct tagWNDCLASSEXA {
    UINT cbSize;

    UINT style;
    WNDPROC lpfnWndProc;
    int cbClsExtra;
    int cbWndExtra;
    HINSTANCE hInstance;
    HICON hIcon;
    HCURSOR hCursor;
    HBRUSH hbrBackground;
    LPCSTR lpszMenuName;
    LPCSTR lpszClassName;

    HICON hIconSm;
} WNDCLASSEXA, *PWNDCLASSEXA,   *NPWNDCLASSEXA,   *LPWNDCLASSEXA;
typedef struct tagWNDCLASSEXW {
    UINT cbSize;

    UINT style;
    WNDPROC lpfnWndProc;
    int cbClsExtra;
    int cbWndExtra;
    HINSTANCE hInstance;
    HICON hIcon;
    HCURSOR hCursor;
    HBRUSH hbrBackground;
    LPCWSTR lpszMenuName;
    LPCWSTR lpszClassName;

    HICON hIconSm;
} WNDCLASSEXW, *PWNDCLASSEXW,   *NPWNDCLASSEXW,   *LPWNDCLASSEXW;






typedef WNDCLASSEXA WNDCLASSEX;
typedef PWNDCLASSEXA PWNDCLASSEX;
typedef NPWNDCLASSEXA NPWNDCLASSEX;
typedef LPWNDCLASSEXA LPWNDCLASSEX;



typedef struct tagWNDCLASSA {
    UINT style;
    WNDPROC lpfnWndProc;
    int cbClsExtra;
    int cbWndExtra;
    HINSTANCE hInstance;
    HICON hIcon;
    HCURSOR hCursor;
    HBRUSH hbrBackground;
    LPCSTR lpszMenuName;
    LPCSTR lpszClassName;
} WNDCLASSA, *PWNDCLASSA,   *NPWNDCLASSA,   *LPWNDCLASSA;
typedef struct tagWNDCLASSW {
    UINT style;
    WNDPROC lpfnWndProc;
    int cbClsExtra;
    int cbWndExtra;
    HINSTANCE hInstance;
    HICON hIcon;
    HCURSOR hCursor;
    HBRUSH hbrBackground;
    LPCWSTR lpszMenuName;
    LPCWSTR lpszClassName;
} WNDCLASSW, *PWNDCLASSW,   *NPWNDCLASSW,   *LPWNDCLASSW;






typedef WNDCLASSA WNDCLASS;
typedef PWNDCLASSA PWNDCLASS;
typedef NPWNDCLASSA NPWNDCLASS;
typedef LPWNDCLASSA LPWNDCLASS;


__declspec(dllimport)
BOOL

IsHungAppWindow(
     HWND hwnd);



__declspec(dllimport)
void

DisableProcessWindowsGhosting(
    void );
typedef struct tagMSG {
    HWND hwnd;
    UINT message;
    WPARAM wParam;
    LPARAM lParam;
    DWORD time;
    POINT pt;
} MSG, *PMSG,   *NPMSG,   *LPMSG;
typedef struct tagMINMAXINFO {
    POINT ptReserved;
    POINT ptMaxSize;
    POINT ptMaxPosition;
    POINT ptMinTrackSize;
    POINT ptMaxTrackSize;
} MINMAXINFO, *PMINMAXINFO, *LPMINMAXINFO;
typedef struct tagCOPYDATASTRUCT {
    ULONG_PTR dwData;
    DWORD cbData;
     PVOID lpData;
} COPYDATASTRUCT, *PCOPYDATASTRUCT;


typedef struct tagMDINEXTMENU
{
    HMENU hmenuIn;
    HMENU hmenuNext;
    HWND hwndNext;
} MDINEXTMENU, * PMDINEXTMENU,   * LPMDINEXTMENU;
typedef struct {
    GUID PowerSetting;
    DWORD DataLength;
    UCHAR Data[1];
} POWERBROADCAST_SETTING, *PPOWERBROADCAST_SETTING;
__declspec(dllimport)
UINT

RegisterWindowMessageA(
     LPCSTR lpString);
__declspec(dllimport)
UINT

RegisterWindowMessageW(
     LPCWSTR lpString);
typedef struct tagWINDOWPOS {
    HWND hwnd;
    HWND hwndInsertAfter;
    int x;
    int y;
    int cx;
    int cy;
    UINT flags;
} WINDOWPOS, *LPWINDOWPOS, *PWINDOWPOS;
typedef struct tagNCCALCSIZE_PARAMS {
    RECT rgrc[3];
    PWINDOWPOS lppos;
} NCCALCSIZE_PARAMS, *LPNCCALCSIZE_PARAMS;
typedef struct tagTRACKMOUSEEVENT {
    DWORD cbSize;
    DWORD dwFlags;
    HWND hwndTrack;
    DWORD dwHoverTime;
} TRACKMOUSEEVENT, *LPTRACKMOUSEEVENT;

__declspec(dllimport)
BOOL

TrackMouseEvent(
     LPTRACKMOUSEEVENT lpEventTrack);
__declspec(dllimport)
BOOL

DrawEdge(
     HDC hdc,
     LPRECT qrc,
     UINT edge,
     UINT grfFlags);
__declspec(dllimport)
BOOL

DrawFrameControl(
     HDC,
     LPRECT,
     UINT,
     UINT);
__declspec(dllimport)
BOOL

DrawCaption(
     HWND hwnd,
     HDC hdc,
      const  RECT * lprect,
     UINT flags);





__declspec(dllimport)
BOOL

DrawAnimatedRects(
     HWND hwnd,
     int idAni,
      const  RECT *lprcFrom,
      const  RECT *lprcTo);
typedef struct tagACCEL {

    BYTE fVirt;
    WORD key;
    WORD cmd;
} ACCEL, *LPACCEL;

typedef struct tagPAINTSTRUCT {
    HDC hdc;
    BOOL fErase;
    RECT rcPaint;
    BOOL fRestore;
    BOOL fIncUpdate;
    BYTE rgbReserved[32];
} PAINTSTRUCT, *PPAINTSTRUCT, *NPPAINTSTRUCT, *LPPAINTSTRUCT;

typedef struct tagCREATESTRUCTA {
    LPVOID lpCreateParams;
    HINSTANCE hInstance;
    HMENU hMenu;
    HWND hwndParent;
    int cy;
    int cx;
    int y;
    int x;
    LONG style;
    LPCSTR lpszName;
    LPCSTR lpszClass;
    DWORD dwExStyle;
} CREATESTRUCTA, *LPCREATESTRUCTA;
typedef struct tagCREATESTRUCTW {
    LPVOID lpCreateParams;
    HINSTANCE hInstance;
    HMENU hMenu;
    HWND hwndParent;
    int cy;
    int cx;
    int y;
    int x;
    LONG style;
    LPCWSTR lpszName;
    LPCWSTR lpszClass;
    DWORD dwExStyle;
} CREATESTRUCTW, *LPCREATESTRUCTW;




typedef CREATESTRUCTA CREATESTRUCT;
typedef LPCREATESTRUCTA LPCREATESTRUCT;


typedef struct tagWINDOWPLACEMENT {
    UINT length;
    UINT flags;
    UINT showCmd;
    POINT ptMinPosition;
    POINT ptMaxPosition;
    RECT rcNormalPosition;
} WINDOWPLACEMENT;
typedef WINDOWPLACEMENT *PWINDOWPLACEMENT, *LPWINDOWPLACEMENT;








typedef struct tagNMHDR
{
    HWND hwndFrom;
    UINT_PTR idFrom;
    UINT code;
} NMHDR;
typedef NMHDR   * LPNMHDR;

typedef struct tagSTYLESTRUCT
{
    DWORD styleOld;
    DWORD styleNew;
} STYLESTRUCT, * LPSTYLESTRUCT;
typedef struct tagMEASUREITEMSTRUCT {
    UINT CtlType;
    UINT CtlID;
    UINT itemID;
    UINT itemWidth;
    UINT itemHeight;
    ULONG_PTR itemData;
} MEASUREITEMSTRUCT,   *PMEASUREITEMSTRUCT,   *LPMEASUREITEMSTRUCT;
typedef struct tagDRAWITEMSTRUCT {
    UINT CtlType;
    UINT CtlID;
    UINT itemID;
    UINT itemAction;
    UINT itemState;
    HWND hwndItem;
    HDC hDC;
    RECT rcItem;
    ULONG_PTR itemData;
} DRAWITEMSTRUCT,   *PDRAWITEMSTRUCT,   *LPDRAWITEMSTRUCT;
typedef struct tagDELETEITEMSTRUCT {
    UINT CtlType;
    UINT CtlID;
    UINT itemID;
    HWND hwndItem;
    ULONG_PTR itemData;
} DELETEITEMSTRUCT,   *PDELETEITEMSTRUCT,   *LPDELETEITEMSTRUCT;
typedef struct tagCOMPAREITEMSTRUCT {
    UINT CtlType;
    UINT CtlID;
    HWND hwndItem;
    UINT itemID1;
    ULONG_PTR itemData1;
    UINT itemID2;
    ULONG_PTR itemData2;
    DWORD dwLocaleId;
} COMPAREITEMSTRUCT,   *PCOMPAREITEMSTRUCT,   *LPCOMPAREITEMSTRUCT;
__declspec(dllimport)
BOOL

GetMessageA(
     LPMSG lpMsg,
     HWND hWnd,
     UINT wMsgFilterMin,
     UINT wMsgFilterMax);
__declspec(dllimport)
BOOL

GetMessageW(
     LPMSG lpMsg,
     HWND hWnd,
     UINT wMsgFilterMin,
     UINT wMsgFilterMax);
__declspec(dllimport)
BOOL

TranslateMessage(
      const  MSG *lpMsg);

__declspec(dllimport)
LRESULT

DispatchMessageA(
      const  MSG *lpMsg);
__declspec(dllimport)
LRESULT

DispatchMessageW(
      const  MSG *lpMsg);
__declspec(dllimport)
BOOL

SetMessageQueue(
     int cMessagesMax);

__declspec(dllimport)
BOOL

PeekMessageA(
     LPMSG lpMsg,
     HWND hWnd,
     UINT wMsgFilterMin,
     UINT wMsgFilterMax,
     UINT wRemoveMsg);
__declspec(dllimport)
BOOL

PeekMessageW(
     LPMSG lpMsg,
     HWND hWnd,
     UINT wMsgFilterMin,
     UINT wMsgFilterMax,
     UINT wRemoveMsg);
__declspec(dllimport)
BOOL

RegisterHotKey(
     HWND hWnd,
     int id,
     UINT fsModifiers,
     UINT vk);

__declspec(dllimport)
BOOL

UnregisterHotKey(
     HWND hWnd,
     int id);
__declspec(dllimport)
BOOL

ExitWindowsEx(
     UINT uFlags,
     DWORD dwReason);

__declspec(dllimport)
BOOL

SwapMouseButton(
     BOOL fSwap);

__declspec(dllimport)
DWORD

GetMessagePos(
    void );

__declspec(dllimport)
LONG

GetMessageTime(
    void );

__declspec(dllimport)
LPARAM

GetMessageExtraInfo(
    void );


__declspec(dllimport)
BOOL

IsWow64Message(
    void );



__declspec(dllimport)
LPARAM

SetMessageExtraInfo(
     LPARAM lParam);


__declspec(dllimport)
LRESULT

SendMessageA(
     HWND hWnd,
     UINT Msg,
     WPARAM wParam,
     LPARAM lParam);
__declspec(dllimport)
LRESULT

SendMessageW(
     HWND hWnd,
     UINT Msg,
     WPARAM wParam,
     LPARAM lParam);
__declspec(dllimport)
LRESULT

SendMessageTimeoutA(
     HWND hWnd,
     UINT Msg,
     WPARAM wParam,
     LPARAM lParam,
     UINT fuFlags,
     UINT uTimeout,
     PDWORD_PTR lpdwResult);
__declspec(dllimport)
LRESULT

SendMessageTimeoutW(
     HWND hWnd,
     UINT Msg,
     WPARAM wParam,
     LPARAM lParam,
     UINT fuFlags,
     UINT uTimeout,
     PDWORD_PTR lpdwResult);






__declspec(dllimport)
BOOL

SendNotifyMessageA(
     HWND hWnd,
     UINT Msg,
     WPARAM wParam,
     LPARAM lParam);
__declspec(dllimport)
BOOL

SendNotifyMessageW(
     HWND hWnd,
     UINT Msg,
     WPARAM wParam,
     LPARAM lParam);






__declspec(dllimport)
BOOL

SendMessageCallbackA(
     HWND hWnd,
     UINT Msg,
     WPARAM wParam,
     LPARAM lParam,
     SENDASYNCPROC lpResultCallBack,
     ULONG_PTR dwData);
__declspec(dllimport)
BOOL

SendMessageCallbackW(
     HWND hWnd,
     UINT Msg,
     WPARAM wParam,
     LPARAM lParam,
     SENDASYNCPROC lpResultCallBack,
     ULONG_PTR dwData);







typedef struct {
    UINT cbSize;
    HDESK hdesk;
    HWND hwnd;
    LUID luid;
} BSMINFO, *PBSMINFO;

__declspec(dllimport)
long

BroadcastSystemMessageExA(
     DWORD flags,
     LPDWORD lpInfo,
     UINT Msg,
     WPARAM wParam,
     LPARAM lParam,
     PBSMINFO pbsmInfo);
__declspec(dllimport)
long

BroadcastSystemMessageExW(
     DWORD flags,
     LPDWORD lpInfo,
     UINT Msg,
     WPARAM wParam,
     LPARAM lParam,
     PBSMINFO pbsmInfo);










__declspec(dllimport)
long

BroadcastSystemMessageA(
     DWORD flags,
     LPDWORD lpInfo,
     UINT Msg,
     WPARAM wParam,
     LPARAM lParam);
__declspec(dllimport)
long

BroadcastSystemMessageW(
     DWORD flags,
     LPDWORD lpInfo,
     UINT Msg,
     WPARAM wParam,
     LPARAM lParam);
typedef PVOID HDEVNOTIFY;
typedef HDEVNOTIFY *PHDEVNOTIFY;







__declspec(dllimport)
HDEVNOTIFY

RegisterDeviceNotificationA(
     HANDLE hRecipient,
     LPVOID NotificationFilter,
     DWORD Flags);
__declspec(dllimport)
HDEVNOTIFY

RegisterDeviceNotificationW(
     HANDLE hRecipient,
     LPVOID NotificationFilter,
     DWORD Flags);






__declspec(dllimport)
BOOL

UnregisterDeviceNotification(
     HDEVNOTIFY Handle
    );


typedef PVOID HPOWERNOTIFY;
typedef HPOWERNOTIFY *PHPOWERNOTIFY;

__declspec(dllimport)
HPOWERNOTIFY

RegisterPowerSettingNotification(
     HANDLE hRecipient,
     LPCGUID PowerSettingGuid,
     DWORD Flags
    );

__declspec(dllimport)
BOOL

UnregisterPowerSettingNotification(
     HPOWERNOTIFY Handle
    );




__declspec(dllimport)
BOOL

PostMessageA(
     HWND hWnd,
     UINT Msg,
     WPARAM wParam,
     LPARAM lParam);
__declspec(dllimport)
BOOL

PostMessageW(
     HWND hWnd,
     UINT Msg,
     WPARAM wParam,
     LPARAM lParam);






__declspec(dllimport)
BOOL

PostThreadMessageA(
     DWORD idThread,
     UINT Msg,
     WPARAM wParam,
     LPARAM lParam);
__declspec(dllimport)
BOOL

PostThreadMessageW(
     DWORD idThread,
     UINT Msg,
     WPARAM wParam,
     LPARAM lParam);
__declspec(dllimport)
BOOL

AttachThreadInput(
     DWORD idAttach,
     DWORD idAttachTo,
     BOOL fAttach);


__declspec(dllimport)
BOOL

ReplyMessage(
     LRESULT lResult);

__declspec(dllimport)
BOOL

WaitMessage(
    void );


__declspec(dllimport)
DWORD

WaitForInputIdle(
     HANDLE hProcess,
     DWORD dwMilliseconds);

__declspec(dllimport)

LRESULT

DefWindowProcA(
     HWND hWnd,
     UINT Msg,
     WPARAM wParam,
     LPARAM lParam);
__declspec(dllimport)

LRESULT

DefWindowProcW(
     HWND hWnd,
     UINT Msg,
     WPARAM wParam,
     LPARAM lParam);






__declspec(dllimport)
void

PostQuitMessage(
     int nExitCode);



__declspec(dllimport)
LRESULT

CallWindowProcA(
     WNDPROC lpPrevWndFunc,
     HWND hWnd,
     UINT Msg,
     WPARAM wParam,
     LPARAM lParam);
__declspec(dllimport)
LRESULT

CallWindowProcW(
     WNDPROC lpPrevWndFunc,
     HWND hWnd,
     UINT Msg,
     WPARAM wParam,
     LPARAM lParam);
__declspec(dllimport)
BOOL

InSendMessage(
    void );


__declspec(dllimport)
DWORD

InSendMessageEx(
     LPVOID lpReserved);
__declspec(dllimport)
UINT

GetDoubleClickTime(
    void );

__declspec(dllimport)
BOOL

SetDoubleClickTime(
     UINT);

__declspec(dllimport)
ATOM

RegisterClassA(
      const  WNDCLASSA *lpWndClass);
__declspec(dllimport)
ATOM

RegisterClassW(
      const  WNDCLASSW *lpWndClass);






__declspec(dllimport)
BOOL

UnregisterClassA(
     LPCSTR lpClassName,
     HINSTANCE hInstance);
__declspec(dllimport)
BOOL

UnregisterClassW(
     LPCWSTR lpClassName,
     HINSTANCE hInstance);






__declspec(dllimport)
BOOL

GetClassInfoA(
     HINSTANCE hInstance,
     LPCSTR lpClassName,
     LPWNDCLASSA lpWndClass);
__declspec(dllimport)
BOOL

GetClassInfoW(
     HINSTANCE hInstance,
     LPCWSTR lpClassName,
     LPWNDCLASSW lpWndClass);







__declspec(dllimport)
ATOM

RegisterClassExA(
      const  WNDCLASSEXA *);
__declspec(dllimport)
ATOM

RegisterClassExW(
      const  WNDCLASSEXW *);






__declspec(dllimport)
BOOL

GetClassInfoExA(
     HINSTANCE hInstance,
     LPCSTR lpszClass,
     LPWNDCLASSEXA lpwcx);
__declspec(dllimport)
BOOL

GetClassInfoExW(
     HINSTANCE hInstance,
     LPCWSTR lpszClass,
     LPWNDCLASSEXW lpwcx);
typedef BOOLEAN (  * PREGISTERCLASSNAMEW)(LPCWSTR);


__declspec(dllimport)
HWND

CreateWindowExA(
     DWORD dwExStyle,
     LPCSTR lpClassName,
     LPCSTR lpWindowName,
     DWORD dwStyle,
     int X,
     int Y,
     int nWidth,
     int nHeight,
     HWND hWndParent,
     HMENU hMenu,
     HINSTANCE hInstance,
     LPVOID lpParam);
__declspec(dllimport)
HWND

CreateWindowExW(
     DWORD dwExStyle,
     LPCWSTR lpClassName,
     LPCWSTR lpWindowName,
     DWORD dwStyle,
     int X,
     int Y,
     int nWidth,
     int nHeight,
     HWND hWndParent,
     HMENU hMenu,
     HINSTANCE hInstance,
     LPVOID lpParam);
__declspec(dllimport)
BOOL

IsWindow(
     HWND hWnd);

__declspec(dllimport)
BOOL

IsMenu(
     HMENU hMenu);

__declspec(dllimport)
BOOL

IsChild(
     HWND hWndParent,
     HWND hWnd);

__declspec(dllimport)
BOOL

DestroyWindow(
     HWND hWnd);

__declspec(dllimport)
BOOL

ShowWindow(
     HWND hWnd,
     int nCmdShow);


__declspec(dllimport)
BOOL

AnimateWindow(
     HWND hWnd,
     DWORD dwTime,
     DWORD dwFlags);





__declspec(dllimport)
BOOL

UpdateLayeredWindow(
     HWND hWnd,
     HDC hdcDst,
     POINT *pptDst,
     SIZE *psize,
     HDC hdcSrc,
     POINT *pptSrc,
     COLORREF crKey,
     BLENDFUNCTION *pblend,
     DWORD dwFlags);
typedef struct tagUPDATELAYEREDWINDOWINFO
{
     DWORD cbSize;
     HDC hdcDst;
     POINT  const  *pptDst;
     SIZE  const  *psize;
     HDC hdcSrc;
     POINT  const  *pptSrc;
     COLORREF crKey;
     BLENDFUNCTION  const  *pblend;
     DWORD dwFlags;
     RECT  const  *prcDirty;
} UPDATELAYEREDWINDOWINFO, *PUPDATELAYEREDWINDOWINFO;
__declspec(dllimport)
BOOL

UpdateLayeredWindowIndirect(
     HWND hWnd,
     UPDATELAYEREDWINDOWINFO  const  *pULWInfo);




__declspec(dllimport)
BOOL

GetLayeredWindowAttributes(
     HWND hwnd,
     COLORREF *pcrKey,
     BYTE *pbAlpha,
     DWORD *pdwFlags);




__declspec(dllimport)
BOOL

PrintWindow(
     HWND hwnd,
     HDC hdcBlt,
     UINT nFlags);



__declspec(dllimport)
BOOL

SetLayeredWindowAttributes(
     HWND hwnd,
     COLORREF crKey,
     BYTE bAlpha,
     DWORD dwFlags);
__declspec(dllimport)
BOOL

ShowWindowAsync(
     HWND hWnd,
     int nCmdShow);


__declspec(dllimport)
BOOL

FlashWindow(
     HWND hWnd,
     BOOL bInvert);


typedef struct {
    UINT cbSize;
    HWND hwnd;
    DWORD dwFlags;
    UINT uCount;
    DWORD dwTimeout;
} FLASHWINFO, *PFLASHWINFO;

__declspec(dllimport)
BOOL

FlashWindowEx(
     PFLASHWINFO pfwi);










__declspec(dllimport)
BOOL

ShowOwnedPopups(
     HWND hWnd,
     BOOL fShow);

__declspec(dllimport)
BOOL

OpenIcon(
     HWND hWnd);

__declspec(dllimport)
BOOL

CloseWindow(
     HWND hWnd);

__declspec(dllimport)
BOOL

MoveWindow(
     HWND hWnd,
     int X,
     int Y,
     int nWidth,
     int nHeight,
     BOOL bRepaint);

__declspec(dllimport)
BOOL

SetWindowPos(
     HWND hWnd,
     HWND hWndInsertAfter,
     int X,
     int Y,
     int cx,
     int cy,
     UINT uFlags);

__declspec(dllimport)
BOOL

GetWindowPlacement(
     HWND hWnd,
     WINDOWPLACEMENT *lpwndpl);

__declspec(dllimport)
BOOL

SetWindowPlacement(
     HWND hWnd,
      const  WINDOWPLACEMENT *lpwndpl);




__declspec(dllimport)
HDWP

BeginDeferWindowPos(
     int nNumWindows);

__declspec(dllimport)
HDWP

DeferWindowPos(
     HDWP hWinPosInfo,
     HWND hWnd,
     HWND hWndInsertAfter,
     int x,
     int y,
     int cx,
     int cy,
     UINT uFlags);

__declspec(dllimport)
BOOL

EndDeferWindowPos(
     HDWP hWinPosInfo);



__declspec(dllimport)
BOOL

IsWindowVisible(
     HWND hWnd);

__declspec(dllimport)
BOOL

IsIconic(
     HWND hWnd);

__declspec(dllimport)
BOOL

AnyPopup(
    void );

__declspec(dllimport)
BOOL

BringWindowToTop(
     HWND hWnd);

__declspec(dllimport)
BOOL

IsZoomed(
     HWND hWnd);
typedef struct {
    DWORD style;
    DWORD dwExtendedStyle;
    WORD cdit;
    short x;
    short y;
    short cx;
    short cy;
} DLGTEMPLATE;
typedef DLGTEMPLATE *LPDLGTEMPLATEA;
typedef DLGTEMPLATE *LPDLGTEMPLATEW;



typedef LPDLGTEMPLATEA LPDLGTEMPLATE;

typedef  const  DLGTEMPLATE *LPCDLGTEMPLATEA;
typedef  const  DLGTEMPLATE *LPCDLGTEMPLATEW;



typedef LPCDLGTEMPLATEA LPCDLGTEMPLATE;
typedef struct {
    DWORD style;
    DWORD dwExtendedStyle;
    short x;
    short y;
    short cx;
    short cy;
    WORD id;
} DLGITEMTEMPLATE;
typedef DLGITEMTEMPLATE *PDLGITEMTEMPLATEA;
typedef DLGITEMTEMPLATE *PDLGITEMTEMPLATEW;



typedef PDLGITEMTEMPLATEA PDLGITEMTEMPLATE;

typedef DLGITEMTEMPLATE *LPDLGITEMTEMPLATEA;
typedef DLGITEMTEMPLATE *LPDLGITEMTEMPLATEW;



typedef LPDLGITEMTEMPLATEA LPDLGITEMTEMPLATE;

__declspec(dllimport)
HWND

CreateDialogParamA(
     HINSTANCE hInstance,
     LPCSTR lpTemplateName,
     HWND hWndParent,
     DLGPROC lpDialogFunc,
     LPARAM dwInitParam);
__declspec(dllimport)
HWND

CreateDialogParamW(
     HINSTANCE hInstance,
     LPCWSTR lpTemplateName,
     HWND hWndParent,
     DLGPROC lpDialogFunc,
     LPARAM dwInitParam);






__declspec(dllimport)
HWND

CreateDialogIndirectParamA(
     HINSTANCE hInstance,
     LPCDLGTEMPLATEA lpTemplate,
     HWND hWndParent,
     DLGPROC lpDialogFunc,
     LPARAM dwInitParam);
__declspec(dllimport)
HWND

CreateDialogIndirectParamW(
     HINSTANCE hInstance,
     LPCDLGTEMPLATEW lpTemplate,
     HWND hWndParent,
     DLGPROC lpDialogFunc,
     LPARAM dwInitParam);
__declspec(dllimport)
INT_PTR

DialogBoxParamA(
     HINSTANCE hInstance,
     LPCSTR lpTemplateName,
     HWND hWndParent,
     DLGPROC lpDialogFunc,
     LPARAM dwInitParam);
__declspec(dllimport)
INT_PTR

DialogBoxParamW(
     HINSTANCE hInstance,
     LPCWSTR lpTemplateName,
     HWND hWndParent,
     DLGPROC lpDialogFunc,
     LPARAM dwInitParam);






__declspec(dllimport)
INT_PTR

DialogBoxIndirectParamA(
     HINSTANCE hInstance,
     LPCDLGTEMPLATEA hDialogTemplate,
     HWND hWndParent,
     DLGPROC lpDialogFunc,
     LPARAM dwInitParam);
__declspec(dllimport)
INT_PTR

DialogBoxIndirectParamW(
     HINSTANCE hInstance,
     LPCDLGTEMPLATEW hDialogTemplate,
     HWND hWndParent,
     DLGPROC lpDialogFunc,
     LPARAM dwInitParam);
__declspec(dllimport)
BOOL

EndDialog(
     HWND hDlg,
     INT_PTR nResult);

__declspec(dllimport)
HWND

GetDlgItem(
     HWND hDlg,
     int nIDDlgItem);

__declspec(dllimport)
BOOL

SetDlgItemInt(
     HWND hDlg,
     int nIDDlgItem,
     UINT uValue,
     BOOL bSigned);

__declspec(dllimport)
UINT

GetDlgItemInt(
     HWND hDlg,
     int nIDDlgItem,
     BOOL *lpTranslated,
     BOOL bSigned);

__declspec(dllimport)
BOOL

SetDlgItemTextA(
     HWND hDlg,
     int nIDDlgItem,
     LPCSTR lpString);
__declspec(dllimport)
BOOL

SetDlgItemTextW(
     HWND hDlg,
     int nIDDlgItem,
     LPCWSTR lpString);






__declspec(dllimport)
UINT

GetDlgItemTextA(
     HWND hDlg,
     int nIDDlgItem,
     LPSTR lpString,
     int cchMax);
__declspec(dllimport)
UINT

GetDlgItemTextW(
     HWND hDlg,
     int nIDDlgItem,
     LPWSTR lpString,
     int cchMax);






__declspec(dllimport)
BOOL

CheckDlgButton(
     HWND hDlg,
     int nIDButton,
     UINT uCheck);

__declspec(dllimport)
BOOL

CheckRadioButton(
     HWND hDlg,
     int nIDFirstButton,
     int nIDLastButton,
     int nIDCheckButton);

__declspec(dllimport)
UINT

IsDlgButtonChecked(
     HWND hDlg,
     int nIDButton);

__declspec(dllimport)
LRESULT

SendDlgItemMessageA(
     HWND hDlg,
     int nIDDlgItem,
     UINT Msg,
     WPARAM wParam,
     LPARAM lParam);
__declspec(dllimport)
LRESULT

SendDlgItemMessageW(
     HWND hDlg,
     int nIDDlgItem,
     UINT Msg,
     WPARAM wParam,
     LPARAM lParam);






__declspec(dllimport)
HWND

GetNextDlgGroupItem(
     HWND hDlg,
     HWND hCtl,
     BOOL bPrevious);

__declspec(dllimport)
HWND

GetNextDlgTabItem(
     HWND hDlg,
     HWND hCtl,
     BOOL bPrevious);

__declspec(dllimport)
int

GetDlgCtrlID(
     HWND hWnd);

__declspec(dllimport)
long

GetDialogBaseUnits( void );

__declspec(dllimport)

LRESULT

DefDlgProcA(
     HWND hDlg,
     UINT Msg,
     WPARAM wParam,
     LPARAM lParam);
__declspec(dllimport)

LRESULT

DefDlgProcW(
     HWND hDlg,
     UINT Msg,
     WPARAM wParam,
     LPARAM lParam);
__declspec(dllimport)
BOOL

CallMsgFilterA(
     LPMSG lpMsg,
     int nCode);
__declspec(dllimport)
BOOL

CallMsgFilterW(
     LPMSG lpMsg,
     int nCode);
__declspec(dllimport)
BOOL

OpenClipboard(
     HWND hWndNewOwner);

__declspec(dllimport)
BOOL

CloseClipboard(
    void );




__declspec(dllimport)
DWORD

GetClipboardSequenceNumber(
    void );



__declspec(dllimport)
HWND

GetClipboardOwner(
    void );

__declspec(dllimport)
HWND

SetClipboardViewer(
     HWND hWndNewViewer);

__declspec(dllimport)
HWND

GetClipboardViewer(
    void );

__declspec(dllimport)
BOOL

ChangeClipboardChain(
     HWND hWndRemove,
     HWND hWndNewNext);

__declspec(dllimport)
HANDLE

SetClipboardData(
     UINT uFormat,
     HANDLE hMem);

__declspec(dllimport)
HANDLE

GetClipboardData(
     UINT uFormat);

__declspec(dllimport)
UINT

RegisterClipboardFormatA(
     LPCSTR lpszFormat);
__declspec(dllimport)
UINT

RegisterClipboardFormatW(
     LPCWSTR lpszFormat);






__declspec(dllimport)
int

CountClipboardFormats(
    void );

__declspec(dllimport)
UINT

EnumClipboardFormats(
     UINT format);

__declspec(dllimport)
int

GetClipboardFormatNameA(
     UINT format,
     LPSTR lpszFormatName,
     int cchMaxCount);
__declspec(dllimport)
int

GetClipboardFormatNameW(
     UINT format,
     LPWSTR lpszFormatName,
     int cchMaxCount);






__declspec(dllimport)
BOOL

EmptyClipboard(
    void );

__declspec(dllimport)
BOOL

IsClipboardFormatAvailable(
     UINT format);

__declspec(dllimport)
int

GetPriorityClipboardFormat(
     UINT *paFormatPriorityList,
     int cFormats);

__declspec(dllimport)
HWND

GetOpenClipboardWindow(
    void );


__declspec(dllimport)
BOOL

AddClipboardFormatListener(
     HWND hwnd);

__declspec(dllimport)
BOOL

RemoveClipboardFormatListener(
     HWND hwnd);

__declspec(dllimport)
BOOL

GetUpdatedClipboardFormats(
       PUINT lpuiFormats,
     UINT cFormats,
       PUINT pcFormatsOut);
__declspec(dllimport)
BOOL

CharToOemA(
     LPCSTR pSrc,
     LPSTR pDst);
__declspec(dllimport)
BOOL

CharToOemW(
     LPCWSTR pSrc,
     LPSTR pDst);






__declspec(dllimport)
BOOL

OemToCharA(
     LPCSTR pSrc,
     LPSTR pDst);
__declspec(dllimport)
BOOL

OemToCharW(
     LPCSTR pSrc,
     LPWSTR pDst);






__declspec(dllimport)
BOOL

CharToOemBuffA(
     LPCSTR lpszSrc,
     LPSTR lpszDst,
     DWORD cchDstLength);
__declspec(dllimport)
BOOL

CharToOemBuffW(
     LPCWSTR lpszSrc,
     LPSTR lpszDst,
     DWORD cchDstLength);






__declspec(dllimport)
BOOL

OemToCharBuffA(
     LPCSTR lpszSrc,
     LPSTR lpszDst,
     DWORD cchDstLength);
__declspec(dllimport)
BOOL

OemToCharBuffW(
     LPCSTR lpszSrc,
     LPWSTR lpszDst,
     DWORD cchDstLength);






__declspec(dllimport)
LPSTR

CharUpperA(
     LPSTR lpsz);
__declspec(dllimport)
LPWSTR

CharUpperW(
     LPWSTR lpsz);






__declspec(dllimport)
DWORD

CharUpperBuffA(
     LPSTR lpsz,
     DWORD cchLength);
__declspec(dllimport)
DWORD

CharUpperBuffW(
     LPWSTR lpsz,
     DWORD cchLength);






__declspec(dllimport)
LPSTR

CharLowerA(
     LPSTR lpsz);
__declspec(dllimport)
LPWSTR

CharLowerW(
     LPWSTR lpsz);






__declspec(dllimport)
DWORD

CharLowerBuffA(
     LPSTR lpsz,
     DWORD cchLength);
__declspec(dllimport)
DWORD

CharLowerBuffW(
     LPWSTR lpsz,
     DWORD cchLength);






__declspec(dllimport)
LPSTR

CharNextA(
     LPCSTR lpsz);
__declspec(dllimport)
LPWSTR

CharNextW(
     LPCWSTR lpsz);






__declspec(dllimport)
LPSTR

CharPrevA(
     LPCSTR lpszStart,
     LPCSTR lpszCurrent);
__declspec(dllimport)
LPWSTR

CharPrevW(
     LPCWSTR lpszStart,
     LPCWSTR lpszCurrent);







__declspec(dllimport)
LPSTR

CharNextExA(
      WORD CodePage,
      LPCSTR lpCurrentChar,
      DWORD dwFlags);

__declspec(dllimport)
LPSTR

CharPrevExA(
      WORD CodePage,
      LPCSTR lpStart,
      LPCSTR lpCurrentChar,
      DWORD dwFlags);
__declspec(dllimport)
BOOL

IsCharAlphaA(
     CHAR ch);
__declspec(dllimport)
BOOL

IsCharAlphaW(
     WCHAR ch);






__declspec(dllimport)
BOOL

IsCharAlphaNumericA(
     CHAR ch);
__declspec(dllimport)
BOOL

IsCharAlphaNumericW(
     WCHAR ch);






__declspec(dllimport)
BOOL

IsCharUpperA(
     CHAR ch);
__declspec(dllimport)
BOOL

IsCharUpperW(
     WCHAR ch);






__declspec(dllimport)
BOOL

IsCharLowerA(
     CHAR ch);
__declspec(dllimport)
BOOL

IsCharLowerW(
     WCHAR ch);








__declspec(dllimport)
HWND

SetFocus(
     HWND hWnd);

__declspec(dllimport)
HWND

GetActiveWindow(
    void );

__declspec(dllimport)
HWND

GetFocus(
    void );

__declspec(dllimport)
UINT

GetKBCodePage(
    void );

__declspec(dllimport)
SHORT

GetKeyState(
     int nVirtKey);

__declspec(dllimport)
SHORT

GetAsyncKeyState(
     int vKey);

__declspec(dllimport)
BOOL

GetKeyboardState(
     PBYTE lpKeyState);

__declspec(dllimport)
BOOL

SetKeyboardState(
     LPBYTE lpKeyState);

__declspec(dllimport)
int

GetKeyNameTextA(
     LONG lParam,
     LPSTR lpString,
     int cchSize);
__declspec(dllimport)
int

GetKeyNameTextW(
     LONG lParam,
     LPWSTR lpString,
     int cchSize);






__declspec(dllimport)
int

GetKeyboardType(
     int nTypeFlag);

__declspec(dllimport)
int

ToAscii(
     UINT uVirtKey,
     UINT uScanCode,
      const  BYTE *lpKeyState,
     LPWORD lpChar,
     UINT uFlags);


__declspec(dllimport)
int

ToAsciiEx(
     UINT uVirtKey,
     UINT uScanCode,
      const  BYTE *lpKeyState,
     LPWORD lpChar,
     UINT uFlags,
     HKL dwhkl);


__declspec(dllimport)
int

ToUnicode(
     UINT wVirtKey,
     UINT wScanCode,
      const  BYTE *lpKeyState,
     LPWSTR pwszBuff,
     int cchBuff,
     UINT wFlags);

__declspec(dllimport)
DWORD

OemKeyScan(
     WORD wOemChar);

__declspec(dllimport)
SHORT

VkKeyScanA(
     CHAR ch);
__declspec(dllimport)
SHORT

VkKeyScanW(
     WCHAR ch);







__declspec(dllimport)
SHORT

VkKeyScanExA(
     CHAR ch,
     HKL dwhkl);
__declspec(dllimport)
SHORT

VkKeyScanExW(
     WCHAR ch,
     HKL dwhkl);
__declspec(dllimport)
void

keybd_event(
     BYTE bVk,
     BYTE bScan,
     DWORD dwFlags,
     ULONG_PTR dwExtraInfo);
__declspec(dllimport)
void

mouse_event(
     DWORD dwFlags,
     DWORD dx,
     DWORD dy,
     DWORD dwData,
     ULONG_PTR dwExtraInfo);



typedef struct tagMOUSEINPUT {
    LONG dx;
    LONG dy;
    DWORD mouseData;
    DWORD dwFlags;
    DWORD time;
    ULONG_PTR dwExtraInfo;
} MOUSEINPUT, *PMOUSEINPUT,  * LPMOUSEINPUT;

typedef struct tagKEYBDINPUT {
    WORD wVk;
    WORD wScan;
    DWORD dwFlags;
    DWORD time;
    ULONG_PTR dwExtraInfo;
} KEYBDINPUT, *PKEYBDINPUT,  * LPKEYBDINPUT;

typedef struct tagHARDWAREINPUT {
    DWORD uMsg;
    WORD wParamL;
    WORD wParamH;
} HARDWAREINPUT, *PHARDWAREINPUT,  * LPHARDWAREINPUT;





typedef struct tagINPUT {
    DWORD type;

    union
    {
        MOUSEINPUT mi;
        KEYBDINPUT ki;
        HARDWAREINPUT hi;
    }  u ;
} INPUT, *PINPUT,  * LPINPUT;

__declspec(dllimport)
UINT

SendInput(
     UINT cInputs,
     LPINPUT pInputs,
     int cbSize);




typedef struct tagLASTINPUTINFO {
    UINT cbSize;
    DWORD dwTime;
} LASTINPUTINFO, * PLASTINPUTINFO;

__declspec(dllimport)
BOOL

GetLastInputInfo(
     PLASTINPUTINFO plii);


__declspec(dllimport)
UINT

MapVirtualKeyA(
     UINT uCode,
     UINT uMapType);
__declspec(dllimport)
UINT

MapVirtualKeyW(
     UINT uCode,
     UINT uMapType);







__declspec(dllimport)
UINT

MapVirtualKeyExA(
     UINT uCode,
     UINT uMapType,
     HKL dwhkl);
__declspec(dllimport)
UINT

MapVirtualKeyExW(
     UINT uCode,
     UINT uMapType,
     HKL dwhkl);
__declspec(dllimport)
BOOL

GetInputState(
    void );

__declspec(dllimport)
DWORD

GetQueueStatus(
     UINT flags);


__declspec(dllimport)
HWND

GetCapture(
    void );

__declspec(dllimport)
HWND

SetCapture(
     HWND hWnd);

__declspec(dllimport)
BOOL

ReleaseCapture(
    void );

__declspec(dllimport)
DWORD

MsgWaitForMultipleObjects(
     DWORD nCount,
      const  HANDLE *pHandles,
     BOOL fWaitAll,
     DWORD dwMilliseconds,
     DWORD dwWakeMask);

__declspec(dllimport)
DWORD

MsgWaitForMultipleObjectsEx(
     DWORD nCount,
      const  HANDLE *pHandles,
     DWORD dwMilliseconds,
     DWORD dwWakeMask,
     DWORD dwFlags);
__declspec(dllimport)
UINT_PTR

SetTimer(
     HWND hWnd,
     UINT_PTR nIDEvent,
     UINT uElapse,
     TIMERPROC lpTimerFunc);

__declspec(dllimport)
BOOL

KillTimer(
     HWND hWnd,
     UINT_PTR uIDEvent);

__declspec(dllimport)
BOOL

IsWindowUnicode(
     HWND hWnd);

__declspec(dllimport)
BOOL

EnableWindow(
     HWND hWnd,
     BOOL bEnable);

__declspec(dllimport)
BOOL

IsWindowEnabled(
     HWND hWnd);

__declspec(dllimport)
HACCEL

LoadAcceleratorsA(
     HINSTANCE hInstance,
     LPCSTR lpTableName);
__declspec(dllimport)
HACCEL

LoadAcceleratorsW(
     HINSTANCE hInstance,
     LPCWSTR lpTableName);






__declspec(dllimport)
HACCEL

CreateAcceleratorTableA(
     LPACCEL paccel,
     int cAccel);
__declspec(dllimport)
HACCEL

CreateAcceleratorTableW(
     LPACCEL paccel,
     int cAccel);






__declspec(dllimport)
BOOL

DestroyAcceleratorTable(
     HACCEL hAccel);

__declspec(dllimport)
int

CopyAcceleratorTableA(
     HACCEL hAccelSrc,
     LPACCEL lpAccelDst,
     int cAccelEntries);
__declspec(dllimport)
int

CopyAcceleratorTableW(
     HACCEL hAccelSrc,
     LPACCEL lpAccelDst,
     int cAccelEntries);








__declspec(dllimport)
int

TranslateAcceleratorA(
     HWND hWnd,
     HACCEL hAccTable,
     LPMSG lpMsg);
__declspec(dllimport)
int

TranslateAcceleratorW(
     HWND hWnd,
     HACCEL hAccTable,
     LPMSG lpMsg);
__declspec(dllimport)
int

GetSystemMetrics(
     int nIndex);






__declspec(dllimport)
HMENU

LoadMenuA(
     HINSTANCE hInstance,
     LPCSTR lpMenuName);
__declspec(dllimport)
HMENU

LoadMenuW(
     HINSTANCE hInstance,
     LPCWSTR lpMenuName);






__declspec(dllimport)
HMENU

LoadMenuIndirectA(
      const  MENUTEMPLATEA *lpMenuTemplate);
__declspec(dllimport)
HMENU

LoadMenuIndirectW(
      const  MENUTEMPLATEW *lpMenuTemplate);






__declspec(dllimport)
HMENU

GetMenu(
     HWND hWnd);

__declspec(dllimport)
BOOL

SetMenu(
     HWND hWnd,
     HMENU hMenu);

__declspec(dllimport)
BOOL

ChangeMenuA(
     HMENU hMenu,
     UINT cmd,
     LPCSTR lpszNewItem,
     UINT cmdInsert,
     UINT flags);
__declspec(dllimport)
BOOL

ChangeMenuW(
     HMENU hMenu,
     UINT cmd,
     LPCWSTR lpszNewItem,
     UINT cmdInsert,
     UINT flags);






__declspec(dllimport)
BOOL

HiliteMenuItem(
     HWND hWnd,
     HMENU hMenu,
     UINT uIDHiliteItem,
     UINT uHilite);

__declspec(dllimport)
int

GetMenuStringA(
     HMENU hMenu,
     UINT uIDItem,
     LPSTR lpString,
     int cchMax,
     UINT flags);
__declspec(dllimport)
int

GetMenuStringW(
     HMENU hMenu,
     UINT uIDItem,
     LPWSTR lpString,
     int cchMax,
     UINT flags);






__declspec(dllimport)
UINT

GetMenuState(
     HMENU hMenu,
     UINT uId,
     UINT uFlags);

__declspec(dllimport)
BOOL

DrawMenuBar(
     HWND hWnd);







__declspec(dllimport)
HMENU

GetSystemMenu(
     HWND hWnd,
     BOOL bRevert);


__declspec(dllimport)
HMENU

CreateMenu(
    void );

__declspec(dllimport)
HMENU

CreatePopupMenu(
    void );

__declspec(dllimport)
BOOL

DestroyMenu(
     HMENU hMenu);

__declspec(dllimport)
DWORD

CheckMenuItem(
     HMENU hMenu,
     UINT uIDCheckItem,
     UINT uCheck);

__declspec(dllimport)
BOOL

EnableMenuItem(
     HMENU hMenu,
     UINT uIDEnableItem,
     UINT uEnable);

__declspec(dllimport)
HMENU

GetSubMenu(
     HMENU hMenu,
     int nPos);

__declspec(dllimport)
UINT

GetMenuItemID(
     HMENU hMenu,
     int nPos);

__declspec(dllimport)
int

GetMenuItemCount(
     HMENU hMenu);

__declspec(dllimport)
BOOL

InsertMenuA(
     HMENU hMenu,
     UINT uPosition,
     UINT uFlags,
     UINT_PTR uIDNewItem,
     LPCSTR lpNewItem);
__declspec(dllimport)
BOOL

InsertMenuW(
     HMENU hMenu,
     UINT uPosition,
     UINT uFlags,
     UINT_PTR uIDNewItem,
     LPCWSTR lpNewItem);






__declspec(dllimport)
BOOL

AppendMenuA(
     HMENU hMenu,
     UINT uFlags,
     UINT_PTR uIDNewItem,
     LPCSTR lpNewItem);
__declspec(dllimport)
BOOL

AppendMenuW(
     HMENU hMenu,
     UINT uFlags,
     UINT_PTR uIDNewItem,
     LPCWSTR lpNewItem);






__declspec(dllimport)
BOOL

ModifyMenuA(
     HMENU hMnu,
     UINT uPosition,
     UINT uFlags,
     UINT_PTR uIDNewItem,
     LPCSTR lpNewItem);
__declspec(dllimport)
BOOL

ModifyMenuW(
     HMENU hMnu,
     UINT uPosition,
     UINT uFlags,
     UINT_PTR uIDNewItem,
     LPCWSTR lpNewItem);






__declspec(dllimport)
BOOL
 RemoveMenu(
     HMENU hMenu,
     UINT uPosition,
     UINT uFlags);

__declspec(dllimport)
BOOL

DeleteMenu(
     HMENU hMenu,
     UINT uPosition,
     UINT uFlags);

__declspec(dllimport)
BOOL

SetMenuItemBitmaps(
     HMENU hMenu,
     UINT uPosition,
     UINT uFlags,
     HBITMAP hBitmapUnchecked,
     HBITMAP hBitmapChecked);

__declspec(dllimport)
LONG

GetMenuCheckMarkDimensions(
    void );

__declspec(dllimport)
BOOL

TrackPopupMenu(
     HMENU hMenu,
     UINT uFlags,
     int x,
     int y,
     int nReserved,
     HWND hWnd,
      const  RECT *prcRect);








typedef struct tagTPMPARAMS
{
    UINT cbSize;
    RECT rcExclude;
} TPMPARAMS;
typedef TPMPARAMS   *LPTPMPARAMS;

__declspec(dllimport)
BOOL

TrackPopupMenuEx(
     HMENU,
     UINT,
     int,
     int,
     HWND,
     LPTPMPARAMS);
typedef struct tagMENUINFO
{
    DWORD cbSize;
    DWORD fMask;
    DWORD dwStyle;
    UINT cyMax;
    HBRUSH hbrBack;
    DWORD dwContextHelpID;
    ULONG_PTR dwMenuData;
} MENUINFO,   *LPMENUINFO;
typedef MENUINFO  const    *LPCMENUINFO;

__declspec(dllimport)
BOOL

GetMenuInfo(
     HMENU,
     LPMENUINFO);

__declspec(dllimport)
BOOL

SetMenuInfo(
     HMENU,
     LPCMENUINFO);

__declspec(dllimport)
BOOL

EndMenu(
        void );
typedef struct tagMENUGETOBJECTINFO
{
    DWORD dwFlags;
    UINT uPos;
    HMENU hmenu;
    PVOID riid;
    PVOID pvObj;
} MENUGETOBJECTINFO, * PMENUGETOBJECTINFO;
typedef struct tagMENUITEMINFOA
{
    UINT cbSize;
    UINT fMask;
    UINT fType;
    UINT fState;
    UINT wID;
    HMENU hSubMenu;
    HBITMAP hbmpChecked;
    HBITMAP hbmpUnchecked;
    ULONG_PTR dwItemData;
     LPSTR dwTypeData;
    UINT cch;

    HBITMAP hbmpItem;

} MENUITEMINFOA,   *LPMENUITEMINFOA;
typedef struct tagMENUITEMINFOW
{
    UINT cbSize;
    UINT fMask;
    UINT fType;
    UINT fState;
    UINT wID;
    HMENU hSubMenu;
    HBITMAP hbmpChecked;
    HBITMAP hbmpUnchecked;
    ULONG_PTR dwItemData;
     LPWSTR dwTypeData;
    UINT cch;

    HBITMAP hbmpItem;

} MENUITEMINFOW,   *LPMENUITEMINFOW;




typedef MENUITEMINFOA MENUITEMINFO;
typedef LPMENUITEMINFOA LPMENUITEMINFO;

typedef MENUITEMINFOA  const    *LPCMENUITEMINFOA;
typedef MENUITEMINFOW  const    *LPCMENUITEMINFOW;



typedef LPCMENUITEMINFOA LPCMENUITEMINFO;



__declspec(dllimport)
BOOL

InsertMenuItemA(
     HMENU hmenu,
     UINT item,
     BOOL fByPosition,
     LPCMENUITEMINFOA lpmi);
__declspec(dllimport)
BOOL

InsertMenuItemW(
     HMENU hmenu,
     UINT item,
     BOOL fByPosition,
     LPCMENUITEMINFOW lpmi);






__declspec(dllimport)
BOOL

GetMenuItemInfoA(
     HMENU hmenu,
     UINT item,
     BOOL fByPosition,
     LPMENUITEMINFOA lpmii);
__declspec(dllimport)
BOOL

GetMenuItemInfoW(
     HMENU hmenu,
     UINT item,
     BOOL fByPosition,
     LPMENUITEMINFOW lpmii);






__declspec(dllimport)
BOOL

SetMenuItemInfoA(
     HMENU hmenu,
     UINT item,
     BOOL fByPositon,
     LPCMENUITEMINFOA lpmii);
__declspec(dllimport)
BOOL

SetMenuItemInfoW(
     HMENU hmenu,
     UINT item,
     BOOL fByPositon,
     LPCMENUITEMINFOW lpmii);










__declspec(dllimport)
UINT

GetMenuDefaultItem(
     HMENU hMenu,
     UINT fByPos,
     UINT gmdiFlags);

__declspec(dllimport)
BOOL

SetMenuDefaultItem(
     HMENU hMenu,
     UINT uItem,
     UINT fByPos);

__declspec(dllimport)
BOOL

GetMenuItemRect(
     HWND hWnd,
     HMENU hMenu,
     UINT uItem,
     LPRECT lprcItem);

__declspec(dllimport)
int

MenuItemFromPoint(
     HWND hWnd,
     HMENU hMenu,
     POINT ptScreen);
typedef struct tagDROPSTRUCT
{
    HWND hwndSource;
    HWND hwndSink;
    DWORD wFmt;
    ULONG_PTR dwData;
    POINT ptDrop;
    DWORD dwControlData;
} DROPSTRUCT, *PDROPSTRUCT, *LPDROPSTRUCT;
__declspec(dllimport)
DWORD

DragObject(
     HWND hwndParent,
     HWND hwndFrom,
     UINT fmt,
     ULONG_PTR data,
     HCURSOR hcur);

__declspec(dllimport)
BOOL

DragDetect(
     HWND hwnd,
     POINT pt);


__declspec(dllimport)
BOOL

DrawIcon(
     HDC hDC,
     int X,
     int Y,
     HICON hIcon);
typedef struct tagDRAWTEXTPARAMS
{
    UINT cbSize;
    int iTabLength;
    int iLeftMargin;
    int iRightMargin;
    UINT uiLengthDrawn;
} DRAWTEXTPARAMS,   *LPDRAWTEXTPARAMS;



__declspec(dllimport)
int

DrawTextA(
     HDC hdc,
     LPCSTR lpchText,
     int cchText,
     LPRECT lprc,
     UINT format);
__declspec(dllimport)
int

DrawTextW(
     HDC hdc,
     LPCWSTR lpchText,
     int cchText,
     LPRECT lprc,
     UINT format);
__declspec(dllimport)
int

DrawTextExA(
     HDC hdc,
     LPSTR lpchText,
     int cchText,
     LPRECT lprc,
     UINT format,
     LPDRAWTEXTPARAMS lpdtp);
__declspec(dllimport)
int

DrawTextExW(
     HDC hdc,
     LPWSTR lpchText,
     int cchText,
     LPRECT lprc,
     UINT format,
     LPDRAWTEXTPARAMS lpdtp);









__declspec(dllimport)
BOOL

GrayStringA(
     HDC hDC,
     HBRUSH hBrush,
     GRAYSTRINGPROC lpOutputFunc,
     LPARAM lpData,
     int nCount,
     int X,
     int Y,
     int nWidth,
     int nHeight);
__declspec(dllimport)
BOOL

GrayStringW(
     HDC hDC,
     HBRUSH hBrush,
     GRAYSTRINGPROC lpOutputFunc,
     LPARAM lpData,
     int nCount,
     int X,
     int Y,
     int nWidth,
     int nHeight);
__declspec(dllimport)
BOOL

DrawStateA(
     HDC hdc,
     HBRUSH hbrFore,
     DRAWSTATEPROC qfnCallBack,
     LPARAM lData,
     WPARAM wData,
     int x,
     int y,
     int cx,
     int cy,
     UINT uFlags);
__declspec(dllimport)
BOOL

DrawStateW(
     HDC hdc,
     HBRUSH hbrFore,
     DRAWSTATEPROC qfnCallBack,
     LPARAM lData,
     WPARAM wData,
     int x,
     int y,
     int cx,
     int cy,
     UINT uFlags);







__declspec(dllimport)
LONG

TabbedTextOutA(
     HDC hdc,
     int x,
     int y,
     LPCSTR lpString,
     int chCount,
     int nTabPositions,
      const  INT *lpnTabStopPositions,
     int nTabOrigin);
__declspec(dllimport)
LONG

TabbedTextOutW(
     HDC hdc,
     int x,
     int y,
     LPCWSTR lpString,
     int chCount,
     int nTabPositions,
      const  INT *lpnTabStopPositions,
     int nTabOrigin);






__declspec(dllimport)
DWORD

GetTabbedTextExtentA(
     HDC hdc,
     LPCSTR lpString,
     int chCount,
     int nTabPositions,
      const  INT *lpnTabStopPositions);
__declspec(dllimport)
DWORD

GetTabbedTextExtentW(
     HDC hdc,
     LPCWSTR lpString,
     int chCount,
     int nTabPositions,
      const  INT *lpnTabStopPositions);






__declspec(dllimport)
BOOL

UpdateWindow(
     HWND hWnd);

__declspec(dllimport)
HWND

SetActiveWindow(
     HWND hWnd);

__declspec(dllimport)
HWND

GetForegroundWindow(
    void );


__declspec(dllimport)
BOOL

PaintDesktop(
     HDC hdc);

__declspec(dllimport)
void

SwitchToThisWindow(
     HWND hwnd,
     BOOL fUnknown);



__declspec(dllimport)
BOOL

SetForegroundWindow(
     HWND hWnd);


__declspec(dllimport)
BOOL

AllowSetForegroundWindow(
     DWORD dwProcessId);



__declspec(dllimport)
BOOL

LockSetForegroundWindow(
     UINT uLockCode);






__declspec(dllimport)
HWND

WindowFromDC(
     HDC hDC);

__declspec(dllimport)
HDC

GetDC(
     HWND hWnd);

__declspec(dllimport)
HDC

GetDCEx(
     HWND hWnd,
     HRGN hrgnClip,
     DWORD flags);
__declspec(dllimport)
HDC

GetWindowDC(
     HWND hWnd);

__declspec(dllimport)
int

ReleaseDC(
     HWND hWnd,
     HDC hDC);

__declspec(dllimport)
HDC

BeginPaint(
     HWND hWnd,
     LPPAINTSTRUCT lpPaint);

__declspec(dllimport)
BOOL

EndPaint(
     HWND hWnd,
      const  PAINTSTRUCT *lpPaint);

__declspec(dllimport)
BOOL

GetUpdateRect(
     HWND hWnd,
     LPRECT lpRect,
     BOOL bErase);

__declspec(dllimport)
int

GetUpdateRgn(
     HWND hWnd,
     HRGN hRgn,
     BOOL bErase);

__declspec(dllimport)
int

SetWindowRgn(
     HWND hWnd,
     HRGN hRgn,
     BOOL bRedraw);


__declspec(dllimport)
int

GetWindowRgn(
     HWND hWnd,
     HRGN hRgn);



__declspec(dllimport)
int

GetWindowRgnBox(
     HWND hWnd,
     LPRECT lprc);



__declspec(dllimport)
int

ExcludeUpdateRgn(
     HDC hDC,
     HWND hWnd);

__declspec(dllimport)
BOOL

InvalidateRect(
     HWND hWnd,
      const  RECT *lpRect,
     BOOL bErase);

__declspec(dllimport)
BOOL

ValidateRect(
     HWND hWnd,
      const  RECT *lpRect);

__declspec(dllimport)
BOOL

InvalidateRgn(
     HWND hWnd,
     HRGN hRgn,
     BOOL bErase);

__declspec(dllimport)
BOOL

ValidateRgn(
     HWND hWnd,
     HRGN hRgn);


__declspec(dllimport)
BOOL

RedrawWindow(
     HWND hWnd,
      const  RECT *lprcUpdate,
     HRGN hrgnUpdate,
     UINT flags);
__declspec(dllimport)
BOOL

LockWindowUpdate(
     HWND hWndLock);

__declspec(dllimport)
BOOL

ScrollWindow(
     HWND hWnd,
     int XAmount,
     int YAmount,
      const  RECT *lpRect,
      const  RECT *lpClipRect);

__declspec(dllimport)
BOOL

ScrollDC(
     HDC hDC,
     int dx,
     int dy,
      const  RECT *lprcScroll,
      const  RECT *lprcClip,
     HRGN hrgnUpdate,
     LPRECT lprcUpdate);

__declspec(dllimport)
int

ScrollWindowEx(
     HWND hWnd,
     int dx,
     int dy,
      const  RECT *prcScroll,
      const  RECT *prcClip,
     HRGN hrgnUpdate,
     LPRECT prcUpdate,
     UINT flags);










__declspec(dllimport)
int

SetScrollPos(
     HWND hWnd,
     int nBar,
     int nPos,
     BOOL bRedraw);

__declspec(dllimport)
int

GetScrollPos(
     HWND hWnd,
     int nBar);

__declspec(dllimport)
BOOL

SetScrollRange(
     HWND hWnd,
     int nBar,
     int nMinPos,
     int nMaxPos,
     BOOL bRedraw);

__declspec(dllimport)
BOOL

GetScrollRange(
     HWND hWnd,
     int nBar,
     LPINT lpMinPos,
     LPINT lpMaxPos);

__declspec(dllimport)
BOOL

ShowScrollBar(
     HWND hWnd,
     int wBar,
     BOOL bShow);

__declspec(dllimport)
BOOL

EnableScrollBar(
     HWND hWnd,
     UINT wSBflags,
     UINT wArrows);
__declspec(dllimport)
BOOL

SetPropA(
     HWND hWnd,
     LPCSTR lpString,
     HANDLE hData);
__declspec(dllimport)
BOOL

SetPropW(
     HWND hWnd,
     LPCWSTR lpString,
     HANDLE hData);






__declspec(dllimport)
HANDLE

GetPropA(
     HWND hWnd,
     LPCSTR lpString);
__declspec(dllimport)
HANDLE

GetPropW(
     HWND hWnd,
     LPCWSTR lpString);






__declspec(dllimport)
HANDLE

RemovePropA(
     HWND hWnd,
     LPCSTR lpString);
__declspec(dllimport)
HANDLE

RemovePropW(
     HWND hWnd,
     LPCWSTR lpString);






__declspec(dllimport)
int

EnumPropsExA(
     HWND hWnd,
     PROPENUMPROCEXA lpEnumFunc,
     LPARAM lParam);
__declspec(dllimport)
int

EnumPropsExW(
     HWND hWnd,
     PROPENUMPROCEXW lpEnumFunc,
     LPARAM lParam);






__declspec(dllimport)
int

EnumPropsA(
     HWND hWnd,
     PROPENUMPROCA lpEnumFunc);
__declspec(dllimport)
int

EnumPropsW(
     HWND hWnd,
     PROPENUMPROCW lpEnumFunc);






__declspec(dllimport)
BOOL

SetWindowTextA(
     HWND hWnd,
     LPCSTR lpString);
__declspec(dllimport)
BOOL

SetWindowTextW(
     HWND hWnd,
     LPCWSTR lpString);






__declspec(dllimport)
int

GetWindowTextA(
     HWND hWnd,
     LPSTR lpString,
     int nMaxCount);
__declspec(dllimport)
int

GetWindowTextW(
     HWND hWnd,
     LPWSTR lpString,
     int nMaxCount);






__declspec(dllimport)
int

GetWindowTextLengthA(
     HWND hWnd);
__declspec(dllimport)
int

GetWindowTextLengthW(
     HWND hWnd);






__declspec(dllimport)
BOOL

GetClientRect(
     HWND hWnd,
     LPRECT lpRect);

__declspec(dllimport)
BOOL

GetWindowRect(
     HWND hWnd,
     LPRECT lpRect);

__declspec(dllimport)
BOOL

AdjustWindowRect(
     LPRECT lpRect,
     DWORD dwStyle,
     BOOL bMenu);

__declspec(dllimport)
BOOL

AdjustWindowRectEx(
     LPRECT lpRect,
     DWORD dwStyle,
     BOOL bMenu,
     DWORD dwExStyle);





typedef struct tagHELPINFO
{
    UINT cbSize;
    int iContextType;
    int iCtrlId;
    HANDLE hItemHandle;
    DWORD_PTR dwContextId;
    POINT MousePos;
} HELPINFO,   *LPHELPINFO;

__declspec(dllimport)
BOOL

SetWindowContextHelpId(
     HWND,
     DWORD);

__declspec(dllimport)
DWORD

GetWindowContextHelpId(
     HWND);

__declspec(dllimport)
BOOL

SetMenuContextHelpId(
     HMENU,
     DWORD);

__declspec(dllimport)
DWORD

GetMenuContextHelpId(
     HMENU);
__declspec(dllimport)
int

MessageBoxA(
     HWND hWnd,
     LPCSTR lpText,
     LPCSTR lpCaption,
     UINT uType);
__declspec(dllimport)
int

MessageBoxW(
     HWND hWnd,
     LPCWSTR lpText,
     LPCWSTR lpCaption,
     UINT uType);
__declspec(dllimport)
int

MessageBoxExA(
     HWND hWnd,
     LPCSTR lpText,
     LPCSTR lpCaption,
     UINT uType,
     WORD wLanguageId);
__declspec(dllimport)
int

MessageBoxExW(
     HWND hWnd,
     LPCWSTR lpText,
     LPCWSTR lpCaption,
     UINT uType,
     WORD wLanguageId);








typedef  void  (  *MSGBOXCALLBACK)(LPHELPINFO lpHelpInfo);

typedef struct tagMSGBOXPARAMSA
{
    UINT cbSize;
    HWND hwndOwner;
    HINSTANCE hInstance;
    LPCSTR lpszText;
    LPCSTR lpszCaption;
    DWORD dwStyle;
    LPCSTR lpszIcon;
    DWORD_PTR dwContextHelpId;
    MSGBOXCALLBACK lpfnMsgBoxCallback;
    DWORD dwLanguageId;
} MSGBOXPARAMSA, *PMSGBOXPARAMSA, *LPMSGBOXPARAMSA;
typedef struct tagMSGBOXPARAMSW
{
    UINT cbSize;
    HWND hwndOwner;
    HINSTANCE hInstance;
    LPCWSTR lpszText;
    LPCWSTR lpszCaption;
    DWORD dwStyle;
    LPCWSTR lpszIcon;
    DWORD_PTR dwContextHelpId;
    MSGBOXCALLBACK lpfnMsgBoxCallback;
    DWORD dwLanguageId;
} MSGBOXPARAMSW, *PMSGBOXPARAMSW, *LPMSGBOXPARAMSW;





typedef MSGBOXPARAMSA MSGBOXPARAMS;
typedef PMSGBOXPARAMSA PMSGBOXPARAMS;
typedef LPMSGBOXPARAMSA LPMSGBOXPARAMS;


__declspec(dllimport)
int

MessageBoxIndirectA(
      const  MSGBOXPARAMSA * lpmbp);
__declspec(dllimport)
int

MessageBoxIndirectW(
      const  MSGBOXPARAMSW * lpmbp);








__declspec(dllimport)
BOOL

MessageBeep(
     UINT uType);



__declspec(dllimport)
int

ShowCursor(
     BOOL bShow);

__declspec(dllimport)
BOOL

SetCursorPos(
     int X,
     int Y);


__declspec(dllimport)
BOOL

SetPhysicalCursorPos(
     int X,
     int Y);

__declspec(dllimport)
HCURSOR

SetCursor(
     HCURSOR hCursor);

__declspec(dllimport)
BOOL

GetCursorPos(
     LPPOINT lpPoint);

__declspec(dllimport)
BOOL

GetPhysicalCursorPos(
     LPPOINT lpPoint);

__declspec(dllimport)
BOOL

ClipCursor(
      const  RECT *lpRect);

__declspec(dllimport)
BOOL

GetClipCursor(
     LPRECT lpRect);

__declspec(dllimport)
HCURSOR

GetCursor(
    void );

__declspec(dllimport)
BOOL

CreateCaret(
     HWND hWnd,
     HBITMAP hBitmap,
     int nWidth,
     int nHeight);

__declspec(dllimport)
UINT

GetCaretBlinkTime(
    void );

__declspec(dllimport)
BOOL

SetCaretBlinkTime(
     UINT uMSeconds);

__declspec(dllimport)
BOOL

DestroyCaret(
    void );

__declspec(dllimport)
BOOL

HideCaret(
     HWND hWnd);

__declspec(dllimport)
BOOL

ShowCaret(
     HWND hWnd);

__declspec(dllimport)
BOOL

SetCaretPos(
     int X,
     int Y);

__declspec(dllimport)
BOOL

GetCaretPos(
     LPPOINT lpPoint);

__declspec(dllimport)
BOOL

ClientToScreen(
     HWND hWnd,
     LPPOINT lpPoint);

__declspec(dllimport)
BOOL

ScreenToClient(
     HWND hWnd,
     LPPOINT lpPoint);


__declspec(dllimport)
BOOL

LogicalToPhysicalPoint(
     HWND hWnd,
     LPPOINT lpPoint);

__declspec(dllimport)
BOOL

PhysicalToLogicalPoint(
     HWND hWnd,
     LPPOINT lpPoint);



__declspec(dllimport)
int

MapWindowPoints(
     HWND hWndFrom,
     HWND hWndTo,
     LPPOINT lpPoints,
     UINT cPoints);

__declspec(dllimport)
HWND

WindowFromPoint(
     POINT Point);


__declspec(dllimport)
HWND

WindowFromPhysicalPoint(
     POINT Point);


__declspec(dllimport)
HWND

ChildWindowFromPoint(
     HWND hWndParent,
     POINT Point);







__declspec(dllimport)
HWND

ChildWindowFromPointEx(
     HWND hwnd,
     POINT pt,
     UINT flags);
__declspec(dllimport)
DWORD

GetSysColor(
     int nIndex);


__declspec(dllimport)
HBRUSH

GetSysColorBrush(
     int nIndex);




__declspec(dllimport)
BOOL

SetSysColors(
     int cElements,
      const  INT * lpaElements,
      const  COLORREF * lpaRgbValues);



__declspec(dllimport)
BOOL

DrawFocusRect(
     HDC hDC,
      const  RECT * lprc);

__declspec(dllimport)
int

FillRect(
     HDC hDC,
      const  RECT *lprc,
     HBRUSH hbr);

__declspec(dllimport)
int

FrameRect(
     HDC hDC,
      const  RECT *lprc,
     HBRUSH hbr);

__declspec(dllimport)
BOOL

InvertRect(
     HDC hDC,
      const  RECT *lprc);

__declspec(dllimport)
BOOL

SetRect(
     LPRECT lprc,
     int xLeft,
     int yTop,
     int xRight,
     int yBottom);

__declspec(dllimport)
BOOL

SetRectEmpty(
     LPRECT lprc);

__declspec(dllimport)
BOOL

CopyRect(
     LPRECT lprcDst,
      const  RECT *lprcSrc);

__declspec(dllimport)
BOOL

InflateRect(
     LPRECT lprc,
     int dx,
     int dy);

__declspec(dllimport)
BOOL

IntersectRect(
     LPRECT lprcDst,
      const  RECT *lprcSrc1,
      const  RECT *lprcSrc2);

__declspec(dllimport)
BOOL

UnionRect(
     LPRECT lprcDst,
      const  RECT *lprcSrc1,
      const  RECT *lprcSrc2);

__declspec(dllimport)
BOOL

SubtractRect(
     LPRECT lprcDst,
      const  RECT *lprcSrc1,
      const  RECT *lprcSrc2);

__declspec(dllimport)
BOOL

OffsetRect(
     LPRECT lprc,
     int dx,
     int dy);

__declspec(dllimport)
BOOL

IsRectEmpty(
      const  RECT *lprc);

__declspec(dllimport)
BOOL

EqualRect(
      const  RECT *lprc1,
      const  RECT *lprc2);

__declspec(dllimport)
BOOL

PtInRect(
      const  RECT *lprc,
     POINT pt);



__declspec(dllimport)
WORD

GetWindowWord(
     HWND hWnd,
     int nIndex);

__declspec(dllimport)
WORD

SetWindowWord(
     HWND hWnd,
     int nIndex,
     WORD wNewWord);

__declspec(dllimport)
LONG

GetWindowLongA(
     HWND hWnd,
     int nIndex);
__declspec(dllimport)
LONG

GetWindowLongW(
     HWND hWnd,
     int nIndex);






__declspec(dllimport)
LONG

SetWindowLongA(
     HWND hWnd,
     int nIndex,
     LONG dwNewLong);
__declspec(dllimport)
LONG

SetWindowLongW(
     HWND hWnd,
     int nIndex,
     LONG dwNewLong);
__declspec(dllimport)
WORD

GetClassWord(
     HWND hWnd,
     int nIndex);

__declspec(dllimport)
WORD

SetClassWord(
     HWND hWnd,
     int nIndex,
     WORD wNewWord);

__declspec(dllimport)
DWORD

GetClassLongA(
     HWND hWnd,
     int nIndex);
__declspec(dllimport)
DWORD

GetClassLongW(
     HWND hWnd,
     int nIndex);






__declspec(dllimport)
DWORD

SetClassLongA(
     HWND hWnd,
     int nIndex,
     LONG dwNewLong);
__declspec(dllimport)
DWORD

SetClassLongW(
     HWND hWnd,
     int nIndex,
     LONG dwNewLong);
__declspec(dllimport)
BOOL

GetProcessDefaultLayout(
     DWORD *pdwDefaultLayout);

__declspec(dllimport)
BOOL

SetProcessDefaultLayout(
     DWORD dwDefaultLayout);


__declspec(dllimport)
HWND

GetDesktopWindow(
    void );


__declspec(dllimport)
HWND

GetParent(
     HWND hWnd);

__declspec(dllimport)
HWND

SetParent(
     HWND hWndChild,
     HWND hWndNewParent);

__declspec(dllimport)
BOOL

EnumChildWindows(
     HWND hWndParent,
     WNDENUMPROC lpEnumFunc,
     LPARAM lParam);

__declspec(dllimport)
HWND

FindWindowA(
     LPCSTR lpClassName,
     LPCSTR lpWindowName);
__declspec(dllimport)
HWND

FindWindowW(
     LPCWSTR lpClassName,
     LPCWSTR lpWindowName);







__declspec(dllimport)
HWND

FindWindowExA(
     HWND hWndParent,
     HWND hWndChildAfter,
     LPCSTR lpszClass,
     LPCSTR lpszWindow);
__declspec(dllimport)
HWND

FindWindowExW(
     HWND hWndParent,
     HWND hWndChildAfter,
     LPCWSTR lpszClass,
     LPCWSTR lpszWindow);






__declspec(dllimport)
HWND

GetShellWindow(
    void );




__declspec(dllimport)
BOOL

RegisterShellHookWindow(
     HWND hwnd);

__declspec(dllimport)
BOOL

DeregisterShellHookWindow(
     HWND hwnd);

__declspec(dllimport)
BOOL

EnumWindows(
     WNDENUMPROC lpEnumFunc,
     LPARAM lParam);

__declspec(dllimport)
BOOL

EnumThreadWindows(
     DWORD dwThreadId,
     WNDENUMPROC lpfn,
     LPARAM lParam);



__declspec(dllimport)
int

GetClassNameA(
     HWND hWnd,
     LPSTR lpClassName,
     int nMaxCount
    );
__declspec(dllimport)
int

GetClassNameW(
     HWND hWnd,
     LPWSTR lpClassName,
     int nMaxCount
    );
__declspec(dllimport)
HWND

GetTopWindow(
     HWND hWnd);





__declspec(dllimport)
DWORD

GetWindowThreadProcessId(
     HWND hWnd,
     LPDWORD lpdwProcessId);


__declspec(dllimport)
BOOL

IsGUIThread(
     BOOL bConvert);
__declspec(dllimport)
HWND

GetLastActivePopup(
     HWND hWnd);
__declspec(dllimport)
HWND

GetWindow(
     HWND hWnd,
     UINT uCmd);






__declspec(dllimport)
HHOOK

SetWindowsHookA(
     int nFilterType,
     HOOKPROC pfnFilterProc);
__declspec(dllimport)
HHOOK

SetWindowsHookW(
     int nFilterType,
     HOOKPROC pfnFilterProc);
__declspec(dllimport)
BOOL

UnhookWindowsHook(
     int nCode,
     HOOKPROC pfnFilterProc);

__declspec(dllimport)
HHOOK

SetWindowsHookExA(
     int idHook,
     HOOKPROC lpfn,
     HINSTANCE hmod,
     DWORD dwThreadId);
__declspec(dllimport)
HHOOK

SetWindowsHookExW(
     int idHook,
     HOOKPROC lpfn,
     HINSTANCE hmod,
     DWORD dwThreadId);






__declspec(dllimport)
BOOL

UnhookWindowsHookEx(
     HHOOK hhk);

__declspec(dllimport)
LRESULT

CallNextHookEx(
     HHOOK hhk,
     int nCode,
     WPARAM wParam,
     LPARAM lParam);
__declspec(dllimport)
BOOL

CheckMenuRadioItem(
     HMENU hmenu,
     UINT first,
     UINT last,
     UINT check,
     UINT flags);
typedef struct {
    WORD versionNumber;
    WORD offset;
} MENUITEMTEMPLATEHEADER, *PMENUITEMTEMPLATEHEADER;

typedef struct {
    WORD mtOption;
    WORD mtID;
    WCHAR mtString[1];
} MENUITEMTEMPLATE, *PMENUITEMTEMPLATE;
__declspec(dllimport)
HBITMAP

LoadBitmapA(
     HINSTANCE hInstance,
     LPCSTR lpBitmapName);
__declspec(dllimport)
HBITMAP

LoadBitmapW(
     HINSTANCE hInstance,
     LPCWSTR lpBitmapName);






__declspec(dllimport)
HCURSOR

LoadCursorA(
     HINSTANCE hInstance,
     LPCSTR lpCursorName);
__declspec(dllimport)
HCURSOR

LoadCursorW(
     HINSTANCE hInstance,
     LPCWSTR lpCursorName);






__declspec(dllimport)
HCURSOR

LoadCursorFromFileA(
     LPCSTR lpFileName);
__declspec(dllimport)
HCURSOR

LoadCursorFromFileW(
     LPCWSTR lpFileName);






__declspec(dllimport)
HCURSOR

CreateCursor(
     HINSTANCE hInst,
     int xHotSpot,
     int yHotSpot,
     int nWidth,
     int nHeight,
      const   void  *pvANDPlane,
      const   void  *pvXORPlane);

__declspec(dllimport)
BOOL

DestroyCursor(
     HCURSOR hCursor);
__declspec(dllimport)
BOOL

SetSystemCursor(
     HCURSOR hcur,
     DWORD id);

typedef struct _ICONINFO {
    BOOL fIcon;
    DWORD xHotspot;
    DWORD yHotspot;
    HBITMAP hbmMask;
    HBITMAP hbmColor;
} ICONINFO;
typedef ICONINFO *PICONINFO;

__declspec(dllimport)
HICON

LoadIconA(
     HINSTANCE hInstance,
     LPCSTR lpIconName);
__declspec(dllimport)
HICON

LoadIconW(
     HINSTANCE hInstance,
     LPCWSTR lpIconName);







__declspec(dllimport)
UINT

PrivateExtractIconsA(
     LPCSTR szFileName,
     int nIconIndex,
     int cxIcon,
     int cyIcon,
     HICON *phicon,
     UINT *piconid,
     UINT nIcons,
     UINT flags);
__declspec(dllimport)
UINT

PrivateExtractIconsW(
     LPCWSTR szFileName,
     int nIconIndex,
     int cxIcon,
     int cyIcon,
     HICON *phicon,
     UINT *piconid,
     UINT nIcons,
     UINT flags);






__declspec(dllimport)
HICON

CreateIcon(
     HINSTANCE hInstance,
     int nWidth,
     int nHeight,
     BYTE cPlanes,
     BYTE cBitsPixel,
      const  BYTE *lpbANDbits,
      const  BYTE *lpbXORbits);

__declspec(dllimport)
BOOL

DestroyIcon(
     HICON hIcon);

__declspec(dllimport)
int

LookupIconIdFromDirectory(
     PBYTE presbits,
     BOOL fIcon);


__declspec(dllimport)
int

LookupIconIdFromDirectoryEx(
     PBYTE presbits,
     BOOL fIcon,
     int cxDesired,
     int cyDesired,
     UINT Flags);


__declspec(dllimport)
HICON

CreateIconFromResource(
     PBYTE presbits,
     DWORD dwResSize,
     BOOL fIcon,
     DWORD dwVer);


__declspec(dllimport)
HICON

CreateIconFromResourceEx(
     PBYTE presbits,
     DWORD dwResSize,
     BOOL fIcon,
     DWORD dwVer,
     int cxDesired,
     int cyDesired,
     UINT Flags);


typedef struct tagCURSORSHAPE
{
    int xHotSpot;
    int yHotSpot;
    int cx;
    int cy;
    int cbWidth;
    BYTE Planes;
    BYTE BitsPixel;
} CURSORSHAPE,   *LPCURSORSHAPE;
__declspec(dllimport)
HANDLE

LoadImageA(
     HINSTANCE hInst,
     LPCSTR name,
     UINT type,
     int cx,
     int cy,
     UINT fuLoad);
__declspec(dllimport)
HANDLE

LoadImageW(
     HINSTANCE hInst,
     LPCWSTR name,
     UINT type,
     int cx,
     int cy,
     UINT fuLoad);






__declspec(dllimport)
HANDLE

CopyImage(
     HANDLE h,
     UINT type,
     int cx,
     int cy,
     UINT flags);










__declspec(dllimport)  BOOL   DrawIconEx(
     HDC hdc,
     int xLeft,
     int yTop,
     HICON hIcon,
     int cxWidth,
     int cyWidth,
     UINT istepIfAniCur,
     HBRUSH hbrFlickerFreeDraw,
     UINT diFlags);



__declspec(dllimport)
HICON

CreateIconIndirect(
     PICONINFO piconinfo);

__declspec(dllimport)
HICON

CopyIcon(
     HICON hIcon);

__declspec(dllimport)
BOOL

GetIconInfo(
     HICON hIcon,
     PICONINFO piconinfo);


typedef struct _ICONINFOEXA {
    DWORD cbSize;
    BOOL fIcon;
    DWORD xHotspot;
    DWORD yHotspot;
    HBITMAP hbmMask;
    HBITMAP hbmColor;
    WORD wResID;
    CHAR szModName[ 260 ];
    CHAR szResName[ 260 ];
} ICONINFOEXA, *PICONINFOEXA;
typedef struct _ICONINFOEXW {
    DWORD cbSize;
    BOOL fIcon;
    DWORD xHotspot;
    DWORD yHotspot;
    HBITMAP hbmMask;
    HBITMAP hbmColor;
    WORD wResID;
    WCHAR szModName[ 260 ];
    WCHAR szResName[ 260 ];
} ICONINFOEXW, *PICONINFOEXW;




typedef ICONINFOEXA ICONINFOEX;
typedef PICONINFOEXA PICONINFOEX;


__declspec(dllimport)
BOOL

GetIconInfoExA(
     HICON hicon,
     PICONINFOEXA piconinfo);
__declspec(dllimport)
BOOL

GetIconInfoExW(
     HICON hicon,
     PICONINFOEXW piconinfo);
__declspec(dllimport)
int

LoadStringA(
     HINSTANCE hInstance,
     UINT uID,
     LPSTR lpBuffer,
     int cchBufferMax);
__declspec(dllimport)
int

LoadStringW(
     HINSTANCE hInstance,
     UINT uID,
     LPWSTR lpBuffer,
     int cchBufferMax);
__declspec(dllimport)
BOOL

IsDialogMessageA(
     HWND hDlg,
     LPMSG lpMsg);
__declspec(dllimport)
BOOL

IsDialogMessageW(
     HWND hDlg,
     LPMSG lpMsg);








__declspec(dllimport)
BOOL

MapDialogRect(
     HWND hDlg,
     LPRECT lpRect);

__declspec(dllimport)
int

DlgDirListA(
     HWND hDlg,
     LPSTR lpPathSpec,
     int nIDListBox,
     int nIDStaticPath,
     UINT uFileType);
__declspec(dllimport)
int

DlgDirListW(
     HWND hDlg,
     LPWSTR lpPathSpec,
     int nIDListBox,
     int nIDStaticPath,
     UINT uFileType);
__declspec(dllimport)
BOOL

DlgDirSelectExA(
     HWND hwndDlg,
     LPSTR lpString,
     int chCount,
     int idListBox);
__declspec(dllimport)
BOOL

DlgDirSelectExW(
     HWND hwndDlg,
     LPWSTR lpString,
     int chCount,
     int idListBox);






__declspec(dllimport)
int

DlgDirListComboBoxA(
     HWND hDlg,
     LPSTR lpPathSpec,
     int nIDComboBox,
     int nIDStaticPath,
     UINT uFiletype);
__declspec(dllimport)
int

DlgDirListComboBoxW(
     HWND hDlg,
     LPWSTR lpPathSpec,
     int nIDComboBox,
     int nIDStaticPath,
     UINT uFiletype);






__declspec(dllimport)
BOOL

DlgDirSelectComboBoxExA(
     HWND hwndDlg,
     LPSTR lpString,
     int cchOut,
     int idComboBox);
__declspec(dllimport)
BOOL

DlgDirSelectComboBoxExW(
     HWND hwndDlg,
     LPWSTR lpString,
     int cchOut,
     int idComboBox);
typedef struct tagSCROLLINFO
{
    UINT cbSize;
    UINT fMask;
    int nMin;
    int nMax;
    UINT nPage;
    int nPos;
    int nTrackPos;
} SCROLLINFO,   *LPSCROLLINFO;
typedef SCROLLINFO  const    *LPCSCROLLINFO;

__declspec(dllimport)
int

SetScrollInfo(
     HWND hwnd,
     int nBar,
     LPCSCROLLINFO lpsi,
     BOOL redraw);

__declspec(dllimport)
BOOL

GetScrollInfo(
     HWND hwnd,
     int nBar,
     LPSCROLLINFO lpsi);
typedef struct tagMDICREATESTRUCTA {
    LPCSTR szClass;
    LPCSTR szTitle;
    HANDLE hOwner;
    int x;
    int y;
    int cx;
    int cy;
    DWORD style;
    LPARAM lParam;
} MDICREATESTRUCTA, *LPMDICREATESTRUCTA;
typedef struct tagMDICREATESTRUCTW {
    LPCWSTR szClass;
    LPCWSTR szTitle;
    HANDLE hOwner;
    int x;
    int y;
    int cx;
    int cy;
    DWORD style;
    LPARAM lParam;
} MDICREATESTRUCTW, *LPMDICREATESTRUCTW;




typedef MDICREATESTRUCTA MDICREATESTRUCT;
typedef LPMDICREATESTRUCTA LPMDICREATESTRUCT;


typedef struct tagCLIENTCREATESTRUCT {
    HANDLE hWindowMenu;
    UINT idFirstChild;
} CLIENTCREATESTRUCT, *LPCLIENTCREATESTRUCT;

__declspec(dllimport)
LRESULT

DefFrameProcA(
     HWND hWnd,
     HWND hWndMDIClient,
     UINT uMsg,
     WPARAM wParam,
     LPARAM lParam);
__declspec(dllimport)
LRESULT

DefFrameProcW(
     HWND hWnd,
     HWND hWndMDIClient,
     UINT uMsg,
     WPARAM wParam,
     LPARAM lParam);






__declspec(dllimport)

LRESULT

DefMDIChildProcA(
     HWND hWnd,
     UINT uMsg,
     WPARAM wParam,
     LPARAM lParam);
__declspec(dllimport)

LRESULT

DefMDIChildProcW(
     HWND hWnd,
     UINT uMsg,
     WPARAM wParam,
     LPARAM lParam);








__declspec(dllimport)
BOOL

TranslateMDISysAccel(
     HWND hWndClient,
     LPMSG lpMsg);



__declspec(dllimport)
UINT

ArrangeIconicWindows(
     HWND hWnd);

__declspec(dllimport)
HWND

CreateMDIWindowA(
     LPCSTR lpClassName,
     LPCSTR lpWindowName,
     DWORD dwStyle,
     int X,
     int Y,
     int nWidth,
     int nHeight,
     HWND hWndParent,
     HINSTANCE hInstance,
     LPARAM lParam);
__declspec(dllimport)
HWND

CreateMDIWindowW(
     LPCWSTR lpClassName,
     LPCWSTR lpWindowName,
     DWORD dwStyle,
     int X,
     int Y,
     int nWidth,
     int nHeight,
     HWND hWndParent,
     HINSTANCE hInstance,
     LPARAM lParam);







__declspec(dllimport)
WORD

TileWindows(
     HWND hwndParent,
     UINT wHow,
      const  RECT * lpRect,
     UINT cKids,
     const HWND   * lpKids);

__declspec(dllimport)
WORD
 CascadeWindows(
     HWND hwndParent,
     UINT wHow,
      const  RECT * lpRect,
     UINT cKids,
     const HWND   * lpKids);










typedef DWORD HELPPOLY;
typedef struct tagMULTIKEYHELPA {

    DWORD mkSize;
    CHAR mkKeylist;
    CHAR szKeyphrase[1];
} MULTIKEYHELPA, *PMULTIKEYHELPA, *LPMULTIKEYHELPA;
typedef struct tagMULTIKEYHELPW {

    DWORD mkSize;
    WCHAR mkKeylist;
    WCHAR szKeyphrase[1];
} MULTIKEYHELPW, *PMULTIKEYHELPW, *LPMULTIKEYHELPW;





typedef MULTIKEYHELPA MULTIKEYHELP;
typedef PMULTIKEYHELPA PMULTIKEYHELP;
typedef LPMULTIKEYHELPA LPMULTIKEYHELP;


typedef struct tagHELPWININFOA {
    int wStructSize;
    int x;
    int y;
    int dx;
    int dy;
    int wMax;
    CHAR rgchMember[2];
} HELPWININFOA, *PHELPWININFOA, *LPHELPWININFOA;
typedef struct tagHELPWININFOW {
    int wStructSize;
    int x;
    int y;
    int dx;
    int dy;
    int wMax;
    WCHAR rgchMember[2];
} HELPWININFOW, *PHELPWININFOW, *LPHELPWININFOW;





typedef HELPWININFOA HELPWININFO;
typedef PHELPWININFOA PHELPWININFO;
typedef LPHELPWININFOA LPHELPWININFO;
__declspec(dllimport)
BOOL

WinHelpA(
     HWND hWndMain,
     LPCSTR lpszHelp,
     UINT uCommand,
     ULONG_PTR dwData);
__declspec(dllimport)
BOOL

WinHelpW(
     HWND hWndMain,
     LPCWSTR lpszHelp,
     UINT uCommand,
     ULONG_PTR dwData);
__declspec(dllimport)
DWORD

GetGuiResources(
     HANDLE hProcess,
     DWORD uiFlags);
typedef struct tagNONCLIENTMETRICSA
{
    UINT cbSize;
    int iBorderWidth;
    int iScrollWidth;
    int iScrollHeight;
    int iCaptionWidth;
    int iCaptionHeight;
    LOGFONTA lfCaptionFont;
    int iSmCaptionWidth;
    int iSmCaptionHeight;
    LOGFONTA lfSmCaptionFont;
    int iMenuWidth;
    int iMenuHeight;
    LOGFONTA lfMenuFont;
    LOGFONTA lfStatusFont;
    LOGFONTA lfMessageFont;

    int iPaddedBorderWidth;

} NONCLIENTMETRICSA, *PNONCLIENTMETRICSA,  * LPNONCLIENTMETRICSA;
typedef struct tagNONCLIENTMETRICSW
{
    UINT cbSize;
    int iBorderWidth;
    int iScrollWidth;
    int iScrollHeight;
    int iCaptionWidth;
    int iCaptionHeight;
    LOGFONTW lfCaptionFont;
    int iSmCaptionWidth;
    int iSmCaptionHeight;
    LOGFONTW lfSmCaptionFont;
    int iMenuWidth;
    int iMenuHeight;
    LOGFONTW lfMenuFont;
    LOGFONTW lfStatusFont;
    LOGFONTW lfMessageFont;

    int iPaddedBorderWidth;

} NONCLIENTMETRICSW, *PNONCLIENTMETRICSW,  * LPNONCLIENTMETRICSW;





typedef NONCLIENTMETRICSA NONCLIENTMETRICS;
typedef PNONCLIENTMETRICSA PNONCLIENTMETRICS;
typedef LPNONCLIENTMETRICSA LPNONCLIENTMETRICS;
typedef struct tagMINIMIZEDMETRICS
{
    UINT cbSize;
    int iWidth;
    int iHorzGap;
    int iVertGap;
    int iArrange;
} MINIMIZEDMETRICS, *PMINIMIZEDMETRICS, *LPMINIMIZEDMETRICS;



typedef struct tagICONMETRICSA
{
    UINT cbSize;
    int iHorzSpacing;
    int iVertSpacing;
    int iTitleWrap;
    LOGFONTA lfFont;
} ICONMETRICSA, *PICONMETRICSA, *LPICONMETRICSA;
typedef struct tagICONMETRICSW
{
    UINT cbSize;
    int iHorzSpacing;
    int iVertSpacing;
    int iTitleWrap;
    LOGFONTW lfFont;
} ICONMETRICSW, *PICONMETRICSW, *LPICONMETRICSW;





typedef ICONMETRICSA ICONMETRICS;
typedef PICONMETRICSA PICONMETRICS;
typedef LPICONMETRICSA LPICONMETRICS;




typedef struct tagANIMATIONINFO
{
    UINT cbSize;
    int iMinAnimate;
} ANIMATIONINFO, *LPANIMATIONINFO;

typedef struct tagSERIALKEYSA
{
    UINT cbSize;
    DWORD dwFlags;
    LPSTR lpszActivePort;
    LPSTR lpszPort;
    UINT iBaudRate;
    UINT iPortState;
    UINT iActive;
} SERIALKEYSA, *LPSERIALKEYSA;
typedef struct tagSERIALKEYSW
{
    UINT cbSize;
    DWORD dwFlags;
    LPWSTR lpszActivePort;
    LPWSTR lpszPort;
    UINT iBaudRate;
    UINT iPortState;
    UINT iActive;
} SERIALKEYSW, *LPSERIALKEYSW;




typedef SERIALKEYSA SERIALKEYS;
typedef LPSERIALKEYSA LPSERIALKEYS;








typedef struct tagHIGHCONTRASTA
{
    UINT cbSize;
    DWORD dwFlags;
    LPSTR lpszDefaultScheme;
} HIGHCONTRASTA, *LPHIGHCONTRASTA;
typedef struct tagHIGHCONTRASTW
{
    UINT cbSize;
    DWORD dwFlags;
    LPWSTR lpszDefaultScheme;
} HIGHCONTRASTW, *LPHIGHCONTRASTW;




typedef HIGHCONTRASTA HIGHCONTRAST;
typedef LPHIGHCONTRASTA LPHIGHCONTRAST;
typedef struct _VIDEOPARAMETERS {
    GUID Guid;
    ULONG dwOffset;
    ULONG dwCommand;
    ULONG dwFlags;
    ULONG dwMode;
    ULONG dwTVStandard;
    ULONG dwAvailableModes;
    ULONG dwAvailableTVStandard;
    ULONG dwFlickerFilter;
    ULONG dwOverScanX;
    ULONG dwOverScanY;
    ULONG dwMaxUnscaledX;
    ULONG dwMaxUnscaledY;
    ULONG dwPositionX;
    ULONG dwPositionY;
    ULONG dwBrightness;
    ULONG dwContrast;
    ULONG dwCPType;
    ULONG dwCPCommand;
    ULONG dwCPStandard;
    ULONG dwCPKey;
    ULONG bCP_APSTriggerBits;
    UCHAR bOEMCopyProtection[256];
} VIDEOPARAMETERS, *PVIDEOPARAMETERS, *LPVIDEOPARAMETERS;
__declspec(dllimport)
LONG

ChangeDisplaySettingsA(
     LPDEVMODEA lpDevMode,
     DWORD dwFlags);
__declspec(dllimport)
LONG

ChangeDisplaySettingsW(
     LPDEVMODEW lpDevMode,
     DWORD dwFlags);






__declspec(dllimport)
LONG

ChangeDisplaySettingsExA(
     LPCSTR lpszDeviceName,
     LPDEVMODEA lpDevMode,
     HWND hwnd,
     DWORD dwflags,
     LPVOID lParam);
__declspec(dllimport)
LONG

ChangeDisplaySettingsExW(
     LPCWSTR lpszDeviceName,
     LPDEVMODEW lpDevMode,
     HWND hwnd,
     DWORD dwflags,
     LPVOID lParam);









__declspec(dllimport)
BOOL

EnumDisplaySettingsA(
     LPCSTR lpszDeviceName,
     DWORD iModeNum,
     LPDEVMODEA lpDevMode);
__declspec(dllimport)
BOOL

EnumDisplaySettingsW(
     LPCWSTR lpszDeviceName,
     DWORD iModeNum,
     LPDEVMODEW lpDevMode);








__declspec(dllimport)
BOOL

EnumDisplaySettingsExA(
     LPCSTR lpszDeviceName,
     DWORD iModeNum,
     LPDEVMODEA lpDevMode,
     DWORD dwFlags);
__declspec(dllimport)
BOOL

EnumDisplaySettingsExW(
     LPCWSTR lpszDeviceName,
     DWORD iModeNum,
     LPDEVMODEW lpDevMode,
     DWORD dwFlags);










__declspec(dllimport)
BOOL

EnumDisplayDevicesA(
     LPCSTR lpDevice,
     DWORD iDevNum,
     PDISPLAY_DEVICEA lpDisplayDevice,
     DWORD dwFlags);
__declspec(dllimport)
BOOL

EnumDisplayDevicesW(
     LPCWSTR lpDevice,
     DWORD iDevNum,
     PDISPLAY_DEVICEW lpDisplayDevice,
     DWORD dwFlags);
__declspec(dllimport)
BOOL

SystemParametersInfoA(
     UINT uiAction,
     UINT uiParam,
     PVOID pvParam,
     UINT fWinIni);
__declspec(dllimport)
BOOL

SystemParametersInfoW(
     UINT uiAction,
     UINT uiParam,
     PVOID pvParam,
     UINT fWinIni);
typedef struct tagFILTERKEYS
{
    UINT cbSize;
    DWORD dwFlags;
    DWORD iWaitMSec;
    DWORD iDelayMSec;
    DWORD iRepeatMSec;
    DWORD iBounceMSec;
} FILTERKEYS, *LPFILTERKEYS;
typedef struct tagSTICKYKEYS
{
    UINT cbSize;
    DWORD dwFlags;
} STICKYKEYS, *LPSTICKYKEYS;
typedef struct tagMOUSEKEYS
{
    UINT cbSize;
    DWORD dwFlags;
    DWORD iMaxSpeed;
    DWORD iTimeToMaxSpeed;
    DWORD iCtrlSpeed;
    DWORD dwReserved1;
    DWORD dwReserved2;
} MOUSEKEYS, *LPMOUSEKEYS;
typedef struct tagACCESSTIMEOUT
{
    UINT cbSize;
    DWORD dwFlags;
    DWORD iTimeOutMSec;
} ACCESSTIMEOUT, *LPACCESSTIMEOUT;
typedef struct tagSOUNDSENTRYA
{
    UINT cbSize;
    DWORD dwFlags;
    DWORD iFSTextEffect;
    DWORD iFSTextEffectMSec;
    DWORD iFSTextEffectColorBits;
    DWORD iFSGrafEffect;
    DWORD iFSGrafEffectMSec;
    DWORD iFSGrafEffectColor;
    DWORD iWindowsEffect;
    DWORD iWindowsEffectMSec;
    LPSTR lpszWindowsEffectDLL;
    DWORD iWindowsEffectOrdinal;
} SOUNDSENTRYA, *LPSOUNDSENTRYA;
typedef struct tagSOUNDSENTRYW
{
    UINT cbSize;
    DWORD dwFlags;
    DWORD iFSTextEffect;
    DWORD iFSTextEffectMSec;
    DWORD iFSTextEffectColorBits;
    DWORD iFSGrafEffect;
    DWORD iFSGrafEffectMSec;
    DWORD iFSGrafEffectColor;
    DWORD iWindowsEffect;
    DWORD iWindowsEffectMSec;
    LPWSTR lpszWindowsEffectDLL;
    DWORD iWindowsEffectOrdinal;
} SOUNDSENTRYW, *LPSOUNDSENTRYW;




typedef SOUNDSENTRYA SOUNDSENTRY;
typedef LPSOUNDSENTRYA LPSOUNDSENTRY;
__declspec(dllimport)
BOOL

SoundSentry( void );


typedef struct tagTOGGLEKEYS
{
    UINT cbSize;
    DWORD dwFlags;
} TOGGLEKEYS, *LPTOGGLEKEYS;
typedef struct tagAUDIODESCRIPTION {
    UINT cbSize;
    BOOL Enabled;
    LCID Locale;
} AUDIODESCRIPTION, *LPAUDIODESCRIPTION;
__declspec(dllimport)
void

SetDebugErrorLevel(
     DWORD dwLevel);
__declspec(dllimport)
void

SetLastErrorEx(
     DWORD dwErrCode,
     DWORD dwType);

__declspec(dllimport)
int

InternalGetWindowText(
     HWND hWnd,
     LPWSTR pString,
     int cchMaxCount);
__declspec(dllimport)
BOOL

CancelShutdown(
    void );
__declspec(dllimport)
HMONITOR

MonitorFromPoint(
     POINT pt,
     DWORD dwFlags);

__declspec(dllimport)
HMONITOR

MonitorFromRect(
     LPCRECT lprc,
     DWORD dwFlags);

__declspec(dllimport)
HMONITOR

MonitorFromWindow(
     HWND hwnd,
     DWORD dwFlags);
typedef struct tagMONITORINFO
{
    DWORD cbSize;
    RECT rcMonitor;
    RECT rcWork;
    DWORD dwFlags;
} MONITORINFO, *LPMONITORINFO;
typedef struct tagMONITORINFOEXA
{
    MONITORINFO  s ;
    CHAR szDevice[ 32 ];
} MONITORINFOEXA, *LPMONITORINFOEXA;
typedef struct tagMONITORINFOEXW
{
    MONITORINFO  s ;
    WCHAR szDevice[ 32 ];
} MONITORINFOEXW, *LPMONITORINFOEXW;




typedef MONITORINFOEXA MONITORINFOEX;
typedef LPMONITORINFOEXA LPMONITORINFOEX;



__declspec(dllimport)
BOOL

GetMonitorInfoA(
     HMONITOR hMonitor,
     LPMONITORINFO lpmi);
__declspec(dllimport)
BOOL

GetMonitorInfoW(
     HMONITOR hMonitor,
     LPMONITORINFO lpmi);






typedef BOOL ( * MONITORENUMPROC)(HMONITOR, HDC, LPRECT, LPARAM);

__declspec(dllimport)
BOOL

EnumDisplayMonitors(
     HDC hdc,
     LPCRECT lprcClip,
     MONITORENUMPROC lpfnEnum,
     LPARAM dwData);
__declspec(dllimport)
void

NotifyWinEvent(
     DWORD event,
     HWND hwnd,
     LONG idObject,
     LONG idChild);

typedef  void  ( * WINEVENTPROC)(
    HWINEVENTHOOK hWinEventHook,
    DWORD event,
    HWND hwnd,
    LONG idObject,
    LONG idChild,
    DWORD idEventThread,
    DWORD dwmsEventTime);

__declspec(dllimport)
HWINEVENTHOOK

SetWinEventHook(
     DWORD eventMin,
     DWORD eventMax,
     HMODULE hmodWinEventProc,
     WINEVENTPROC pfnWinEventProc,
     DWORD idProcess,
     DWORD idThread,
     DWORD dwFlags);


__declspec(dllimport)
BOOL

IsWinEventHookInstalled(
     DWORD event);
__declspec(dllimport)
BOOL

UnhookWinEvent(
     HWINEVENTHOOK hWinEventHook);
typedef struct tagGUITHREADINFO
{
    DWORD cbSize;
    DWORD flags;
    HWND hwndActive;
    HWND hwndFocus;
    HWND hwndCapture;
    HWND hwndMenuOwner;
    HWND hwndMoveSize;
    HWND hwndCaret;
    RECT rcCaret;
} GUITHREADINFO, *PGUITHREADINFO,   * LPGUITHREADINFO;
__declspec(dllimport)
BOOL

GetGUIThreadInfo(
     DWORD idThread,
     PGUITHREADINFO pgui);

__declspec(dllimport)
BOOL

BlockInput(
    BOOL fBlockIt);





__declspec(dllimport)
BOOL

SetProcessDPIAware(
    void );

__declspec(dllimport)
BOOL

IsProcessDPIAware(
    void );


__declspec(dllimport)
UINT

GetWindowModuleFileNameA(
     HWND hwnd,
     LPSTR pszFileName,
     UINT cchFileNameMax);
__declspec(dllimport)
UINT

GetWindowModuleFileNameW(
     HWND hwnd,
     LPWSTR pszFileName,
     UINT cchFileNameMax);
typedef struct tagCURSORINFO
{
    DWORD cbSize;
    DWORD flags;
    HCURSOR hCursor;
    POINT ptScreenPos;
} CURSORINFO, *PCURSORINFO, *LPCURSORINFO;



__declspec(dllimport)
BOOL

GetCursorInfo(
     PCURSORINFO pci);
typedef struct tagWINDOWINFO
{
    DWORD cbSize;
    RECT rcWindow;
    RECT rcClient;
    DWORD dwStyle;
    DWORD dwExStyle;
    DWORD dwWindowStatus;
    UINT cxWindowBorders;
    UINT cyWindowBorders;
    ATOM atomWindowType;
    WORD wCreatorVersion;
} WINDOWINFO, *PWINDOWINFO, *LPWINDOWINFO;



__declspec(dllimport)
BOOL

GetWindowInfo(
     HWND hwnd,
     PWINDOWINFO pwi);
typedef struct tagTITLEBARINFO
{
    DWORD cbSize;
    RECT rcTitleBar;
    DWORD rgstate[ 5  + 1];
} TITLEBARINFO, *PTITLEBARINFO, *LPTITLEBARINFO;

__declspec(dllimport)
BOOL

GetTitleBarInfo(
     HWND hwnd,
     PTITLEBARINFO pti);


typedef struct tagTITLEBARINFOEX
{
    DWORD cbSize;
    RECT rcTitleBar;
    DWORD rgstate[ 5  + 1];
    RECT rgrect[ 5  + 1];
} TITLEBARINFOEX, *PTITLEBARINFOEX, *LPTITLEBARINFOEX;
typedef struct tagMENUBARINFO
{
    DWORD cbSize;
    RECT rcBar;
    HMENU hMenu;
    HWND hwndMenu;
    BOOL fBarFocused:1;
    BOOL fFocused:1;
} MENUBARINFO, *PMENUBARINFO, *LPMENUBARINFO;

__declspec(dllimport)
BOOL

GetMenuBarInfo(
     HWND hwnd,
     LONG idObject,
     LONG idItem,
     PMENUBARINFO pmbi);
typedef struct tagSCROLLBARINFO
{
    DWORD cbSize;
    RECT rcScrollBar;
    int dxyLineButton;
    int xyThumbTop;
    int xyThumbBottom;
    int reserved;
    DWORD rgstate[ 5  + 1];
} SCROLLBARINFO, *PSCROLLBARINFO, *LPSCROLLBARINFO;

__declspec(dllimport)
BOOL

GetScrollBarInfo(
     HWND hwnd,
     LONG idObject,
     PSCROLLBARINFO psbi);
typedef struct tagCOMBOBOXINFO
{
    DWORD cbSize;
    RECT rcItem;
    RECT rcButton;
    DWORD stateButton;
    HWND hwndCombo;
    HWND hwndItem;
    HWND hwndList;
} COMBOBOXINFO, *PCOMBOBOXINFO, *LPCOMBOBOXINFO;

__declspec(dllimport)
BOOL

GetComboBoxInfo(
     HWND hwndCombo,
     PCOMBOBOXINFO pcbi);
__declspec(dllimport)
HWND

GetAncestor(
     HWND hwnd,
     UINT gaFlags);
__declspec(dllimport)
HWND

RealChildWindowFromPoint(
     HWND hwndParent,
     POINT ptParentClientCoords);
__declspec(dllimport)
UINT

RealGetWindowClassA(
     HWND hwnd,
     LPSTR ptszClassName,
     UINT cchClassNameMax);
__declspec(dllimport)
UINT

RealGetWindowClassW(
     HWND hwnd,
     LPWSTR ptszClassName,
     UINT cchClassNameMax);
typedef struct tagALTTABINFO
{
    DWORD cbSize;
    int cItems;
    int cColumns;
    int cRows;
    int iColFocus;
    int iRowFocus;
    int cxItem;
    int cyItem;
    POINT ptStart;
} ALTTABINFO, *PALTTABINFO, *LPALTTABINFO;

__declspec(dllimport)
BOOL

GetAltTabInfoA(
     HWND hwnd,
     int iItem,
     PALTTABINFO pati,
     LPSTR pszItemText,
     UINT cchItemText);
__declspec(dllimport)
BOOL

GetAltTabInfoW(
     HWND hwnd,
     int iItem,
     PALTTABINFO pati,
     LPWSTR pszItemText,
     UINT cchItemText);
__declspec(dllimport)
DWORD

GetListBoxInfo(
     HWND hwnd);






__declspec(dllimport)
BOOL

LockWorkStation(
    void );




__declspec(dllimport)
BOOL

UserHandleGrantAccess(
     HANDLE hUserHandle,
     HANDLE hJob,
     BOOL bGrant);
struct HRAWINPUT__ {int unused;}; typedef struct HRAWINPUT__ *HRAWINPUT ;
typedef struct tagRAWINPUTHEADER {
    DWORD dwType;
    DWORD dwSize;
    HANDLE hDevice;
    WPARAM wParam;
} RAWINPUTHEADER, *PRAWINPUTHEADER, *LPRAWINPUTHEADER;
typedef struct tagRAWMOUSE {
    USHORT usFlags;
    union {
        ULONG ulButtons;
        struct {
            USHORT usButtonFlags;
            USHORT usButtonData;
        }  s ;
    }  u ;
    ULONG ulRawButtons;
    LONG lLastX;
    LONG lLastY;
    ULONG ulExtraInformation;

} RAWMOUSE, *PRAWMOUSE, *LPRAWMOUSE;
typedef struct tagRAWKEYBOARD {
    USHORT MakeCode;
    USHORT Flags;

    USHORT Reserved;
    USHORT VKey;
    UINT Message;
    ULONG ExtraInformation;


} RAWKEYBOARD, *PRAWKEYBOARD, *LPRAWKEYBOARD;
typedef struct tagRAWHID {
    DWORD dwSizeHid;
    DWORD dwCount;
    BYTE bRawData[1];
} RAWHID, *PRAWHID, *LPRAWHID;
typedef struct tagRAWINPUT {
    RAWINPUTHEADER header;
    union {
        RAWMOUSE mouse;
        RAWKEYBOARD keyboard;
        RAWHID hid;
    } data;
} RAWINPUT, *PRAWINPUT, *LPRAWINPUT;
__declspec(dllimport)
UINT

GetRawInputData(
     HRAWINPUT hRawInput,
     UINT uiCommand,
     LPVOID pData,
     PUINT pcbSize,
     UINT cbSizeHeader);
typedef struct tagRID_DEVICE_INFO_MOUSE {
    DWORD dwId;
    DWORD dwNumberOfButtons;
    DWORD dwSampleRate;
    BOOL fHasHorizontalWheel;
} RID_DEVICE_INFO_MOUSE, *PRID_DEVICE_INFO_MOUSE;

typedef struct tagRID_DEVICE_INFO_KEYBOARD {
    DWORD dwType;
    DWORD dwSubType;
    DWORD dwKeyboardMode;
    DWORD dwNumberOfFunctionKeys;
    DWORD dwNumberOfIndicators;
    DWORD dwNumberOfKeysTotal;
} RID_DEVICE_INFO_KEYBOARD, *PRID_DEVICE_INFO_KEYBOARD;

typedef struct tagRID_DEVICE_INFO_HID {
    DWORD dwVendorId;
    DWORD dwProductId;
    DWORD dwVersionNumber;
    USHORT usUsagePage;
    USHORT usUsage;
} RID_DEVICE_INFO_HID, *PRID_DEVICE_INFO_HID;

typedef struct tagRID_DEVICE_INFO {
    DWORD cbSize;
    DWORD dwType;
    union {
        RID_DEVICE_INFO_MOUSE mouse;
        RID_DEVICE_INFO_KEYBOARD keyboard;
        RID_DEVICE_INFO_HID hid;
    }  u ;
} RID_DEVICE_INFO, *PRID_DEVICE_INFO, *LPRID_DEVICE_INFO;

__declspec(dllimport)
UINT

GetRawInputDeviceInfoA(
     HANDLE hDevice,
     UINT uiCommand,
     LPVOID pData,
     PUINT pcbSize);
__declspec(dllimport)
UINT

GetRawInputDeviceInfoW(
     HANDLE hDevice,
     UINT uiCommand,
     LPVOID pData,
     PUINT pcbSize);
__declspec(dllimport)
UINT

GetRawInputBuffer(
     PRAWINPUT pData,
     PUINT pcbSize,
     UINT cbSizeHeader);
typedef struct tagRAWINPUTDEVICE {
    USHORT usUsagePage;
    USHORT usUsage;
    DWORD dwFlags;
    HWND hwndTarget;
} RAWINPUTDEVICE, *PRAWINPUTDEVICE, *LPRAWINPUTDEVICE;

typedef  const  RAWINPUTDEVICE* PCRAWINPUTDEVICE;
__declspec(dllimport)
BOOL

RegisterRawInputDevices(
     PCRAWINPUTDEVICE pRawInputDevices,
     UINT uiNumDevices,
     UINT cbSize);

__declspec(dllimport)
UINT

GetRegisteredRawInputDevices(
     PRAWINPUTDEVICE pRawInputDevices,
     PUINT puiNumDevices,
     UINT cbSize);


typedef struct tagRAWINPUTDEVICELIST {
    HANDLE hDevice;
    DWORD dwType;
} RAWINPUTDEVICELIST, *PRAWINPUTDEVICELIST;

__declspec(dllimport)
UINT

GetRawInputDeviceList(
     PRAWINPUTDEVICELIST pRawInputDeviceList,
     PUINT puiNumDevices,
     UINT cbSize);

__declspec(dllimport)
LRESULT

DefRawInputProc(
     PRAWINPUT* paRawInput,
     INT nInput,
     UINT cbSizeHeader);








__declspec(dllimport)
BOOL

ChangeWindowMessageFilter(
     UINT message,
     DWORD dwFlag);





__declspec(dllimport)
BOOL

ShutdownBlockReasonCreate(
     HWND hWnd,
     LPCWSTR pwszReason);

__declspec(dllimport)
BOOL

ShutdownBlockReasonQuery(
     HWND hWnd,
     LPWSTR pwszBuff,
     DWORD *pcchBuff);

__declspec(dllimport)
BOOL

ShutdownBlockReasonDestroy(
     HWND hWnd);
typedef DWORD LGRPID;





typedef DWORD LCTYPE;





typedef DWORD CALTYPE;





typedef DWORD CALID;






typedef struct _cpinfo {
    UINT MaxCharSize;
    BYTE DefaultChar[ 2 ];
    BYTE LeadByte[ 12 ];
} CPINFO, *LPCPINFO;

typedef struct _cpinfoexA {
    UINT MaxCharSize;
    BYTE DefaultChar[ 2 ];
    BYTE LeadByte[ 12 ];
    WCHAR UnicodeDefaultChar;
    UINT CodePage;
    CHAR CodePageName[ 260 ];
} CPINFOEXA, *LPCPINFOEXA;
typedef struct _cpinfoexW {
    UINT MaxCharSize;
    BYTE DefaultChar[ 2 ];
    BYTE LeadByte[ 12 ];
    WCHAR UnicodeDefaultChar;
    UINT CodePage;
    WCHAR CodePageName[ 260 ];
} CPINFOEXW, *LPCPINFOEXW;




typedef CPINFOEXA CPINFOEX;
typedef LPCPINFOEXA LPCPINFOEX;







typedef struct _numberfmtA {
    UINT NumDigits;
    UINT LeadingZero;
    UINT Grouping;
    LPSTR lpDecimalSep;
    LPSTR lpThousandSep;
    UINT NegativeOrder;
} NUMBERFMTA, *LPNUMBERFMTA;
typedef struct _numberfmtW {
    UINT NumDigits;
    UINT LeadingZero;
    UINT Grouping;
    LPWSTR lpDecimalSep;
    LPWSTR lpThousandSep;
    UINT NegativeOrder;
} NUMBERFMTW, *LPNUMBERFMTW;




typedef NUMBERFMTA NUMBERFMT;
typedef LPNUMBERFMTA LPNUMBERFMT;







typedef struct _currencyfmtA {
    UINT NumDigits;
    UINT LeadingZero;
    UINT Grouping;
    LPSTR lpDecimalSep;
    LPSTR lpThousandSep;
    UINT NegativeOrder;
    UINT PositiveOrder;
    LPSTR lpCurrencySymbol;
} CURRENCYFMTA, *LPCURRENCYFMTA;
typedef struct _currencyfmtW {
    UINT NumDigits;
    UINT LeadingZero;
    UINT Grouping;
    LPWSTR lpDecimalSep;
    LPWSTR lpThousandSep;
    UINT NegativeOrder;
    UINT PositiveOrder;
    LPWSTR lpCurrencySymbol;
} CURRENCYFMTW, *LPCURRENCYFMTW;




typedef CURRENCYFMTA CURRENCYFMT;
typedef LPCURRENCYFMTA LPCURRENCYFMT;






enum SYSNLS_FUNCTION{
    COMPARE_STRING = 0x0001,
};
typedef DWORD NLS_FUNCTION;






typedef struct _nlsversioninfo{
    DWORD dwNLSVersionInfoSize;
    DWORD dwNLSVersion;
    DWORD dwDefinedVersion;
} NLSVERSIONINFO, *LPNLSVERSIONINFO;

typedef struct _nlsversioninfoex{
    DWORD dwNLSVersionInfoSize;
    DWORD dwNLSVersion;
    DWORD dwDefinedVersion;
    DWORD dwEffectiveId;
    GUID guidCustomVersion;
} NLSVERSIONINFOEX, *LPNLSVERSIONINFOEX;





typedef LONG GEOID;
typedef DWORD GEOTYPE;
typedef DWORD GEOCLASS;







enum SYSGEOTYPE {
    GEO_NATION = 0x0001,
    GEO_LATITUDE = 0x0002,
    GEO_LONGITUDE = 0x0003,
    GEO_ISO2 = 0x0004,
    GEO_ISO3 = 0x0005,
    GEO_RFC1766 = 0x0006,
    GEO_LCID = 0x0007,
    GEO_FRIENDLYNAME= 0x0008,
    GEO_OFFICIALNAME= 0x0009,
    GEO_TIMEZONES = 0x000A,
    GEO_OFFICIALLANGUAGES = 0x000B,
};





enum SYSGEOCLASS {
    GEOCLASS_NATION = 16,
    GEOCLASS_REGION = 14,
};






typedef enum _NORM_FORM {
    NormalizationOther = 0,
    NormalizationC = 0x1,
    NormalizationD = 0x2,
    NormalizationKC = 0x5,

    NormalizationKD = 0x6

} NORM_FORM;
typedef BOOL ( * LANGUAGEGROUP_ENUMPROCA)(LGRPID, LPSTR, LPSTR, DWORD, LONG_PTR);
typedef BOOL ( * LANGGROUPLOCALE_ENUMPROCA)(LGRPID, LCID, LPSTR, LONG_PTR);
typedef BOOL ( * UILANGUAGE_ENUMPROCA)(LPSTR, LONG_PTR);
typedef BOOL ( * LOCALE_ENUMPROCA)(LPSTR);
typedef BOOL ( * CODEPAGE_ENUMPROCA)(LPSTR);
typedef BOOL ( * DATEFMT_ENUMPROCA)(LPSTR);
typedef BOOL ( * DATEFMT_ENUMPROCEXA)(LPSTR, CALID);
typedef BOOL ( * TIMEFMT_ENUMPROCA)(LPSTR);
typedef BOOL ( * CALINFO_ENUMPROCA)(LPSTR);
typedef BOOL ( * CALINFO_ENUMPROCEXA)(LPSTR, CALID);

typedef BOOL ( * LANGUAGEGROUP_ENUMPROCW)(LGRPID, LPWSTR, LPWSTR, DWORD, LONG_PTR);
typedef BOOL ( * LANGGROUPLOCALE_ENUMPROCW)(LGRPID, LCID, LPWSTR, LONG_PTR);
typedef BOOL ( * UILANGUAGE_ENUMPROCW)(LPWSTR, LONG_PTR);
typedef BOOL ( * LOCALE_ENUMPROCW)(LPWSTR);
typedef BOOL ( * CODEPAGE_ENUMPROCW)(LPWSTR);
typedef BOOL ( * DATEFMT_ENUMPROCW)(LPWSTR);
typedef BOOL ( * DATEFMT_ENUMPROCEXW)(LPWSTR, CALID);
typedef BOOL ( * TIMEFMT_ENUMPROCW)(LPWSTR);
typedef BOOL ( * CALINFO_ENUMPROCW)(LPWSTR);
typedef BOOL ( * CALINFO_ENUMPROCEXW)(LPWSTR, CALID);
typedef BOOL ( * GEO_ENUMPROC)(GEOID);
typedef struct _FILEMUIINFO {
    DWORD dwSize;
    DWORD dwVersion;
    DWORD dwFileType;
    BYTE pChecksum[16];
    BYTE pServiceChecksum[16];
    DWORD dwLanguageNameOffset;
    DWORD dwTypeIDMainSize;
    DWORD dwTypeIDMainOffset;
    DWORD dwTypeNameMainOffset;
    DWORD dwTypeIDMUISize;
    DWORD dwTypeIDMUIOffset;
    DWORD dwTypeNameMUIOffset;
    BYTE abBuffer[8];
} FILEMUIINFO, *PFILEMUIINFO;
__declspec(dllimport)
BOOL

IsValidCodePage(
     UINT CodePage);

__declspec(dllimport)
UINT

GetACP(void);

__declspec(dllimport)
UINT

GetOEMCP(void);

__declspec(dllimport)
BOOL

GetCPInfo(
     UINT CodePage,
     LPCPINFO lpCPInfo);

__declspec(dllimport)
BOOL

GetCPInfoExA(
     UINT CodePage,
     DWORD dwFlags,
     LPCPINFOEXA lpCPInfoEx);
__declspec(dllimport)
BOOL

GetCPInfoExW(
     UINT CodePage,
     DWORD dwFlags,
     LPCPINFOEXW lpCPInfoEx);






__declspec(dllimport)
BOOL

IsDBCSLeadByte(
     BYTE TestChar);

__declspec(dllimport)
BOOL

IsDBCSLeadByteEx(
     UINT CodePage,
     BYTE TestChar);

__declspec(dllimport)
int

MultiByteToWideChar(
     UINT CodePage,
     DWORD dwFlags,
     LPCSTR lpMultiByteStr,
     int cbMultiByte,
       LPWSTR lpWideCharStr,
     int cchWideChar);

__declspec(dllimport)
int

WideCharToMultiByte(
     UINT CodePage,
     DWORD dwFlags,
     LPCWSTR lpWideCharStr,
     int cchWideChar,
       LPSTR lpMultiByteStr,
     int cbMultiByte,
     LPCSTR lpDefaultChar,
     LPBOOL lpUsedDefaultChar);






__declspec(dllimport)
int

CompareStringA(
     LCID Locale,
     DWORD dwCmpFlags,
     LPCSTR lpString1,
     int cchCount1,
     LPCSTR lpString2,
     int cchCount2);
__declspec(dllimport)
int

CompareStringW(
     LCID Locale,
     DWORD dwCmpFlags,
     LPCWSTR lpString1,
     int cchCount1,
     LPCWSTR lpString2,
     int cchCount2);
__declspec(dllimport)
int

FindNLSString(
     LCID Locale,
     DWORD dwFindNLSStringFlags,
     LPCWSTR lpStringSource,
     int cchSource,
     LPCWSTR lpStringValue,
     int cchValue,
     LPINT pcchFound);



__declspec(dllimport)
int

LCMapStringA(
     LCID Locale,
     DWORD dwMapFlags,
     LPCSTR lpSrcStr,
     int cchSrc,
     LPSTR lpDestStr,
     int cchDest);
__declspec(dllimport)
int

LCMapStringW(
     LCID Locale,
     DWORD dwMapFlags,
     LPCWSTR lpSrcStr,
     int cchSrc,
     LPWSTR lpDestStr,
     int cchDest);






__declspec(dllimport)
int

GetLocaleInfoA(
     LCID Locale,
     LCTYPE LCType,
     LPSTR lpLCData,
     int cchData);
__declspec(dllimport)
int

GetLocaleInfoW(
     LCID Locale,
     LCTYPE LCType,
     LPWSTR lpLCData,
     int cchData);






__declspec(dllimport)
BOOL

SetLocaleInfoA(
     LCID Locale,
     LCTYPE LCType,
     LPCSTR lpLCData);
__declspec(dllimport)
BOOL

SetLocaleInfoW(
     LCID Locale,
     LCTYPE LCType,
     LPCWSTR lpLCData);







__declspec(dllimport)
int

GetCalendarInfoA(
     LCID Locale,
     CALID Calendar,
     CALTYPE CalType,
     LPSTR lpCalData,
     int cchData,
     LPDWORD lpValue);
__declspec(dllimport)
int

GetCalendarInfoW(
     LCID Locale,
     CALID Calendar,
     CALTYPE CalType,
     LPWSTR lpCalData,
     int cchData,
     LPDWORD lpValue);






__declspec(dllimport)
BOOL

SetCalendarInfoA(
     LCID Locale,
     CALID Calendar,
     CALTYPE CalType,
     LPCSTR lpCalData);
__declspec(dllimport)
BOOL

SetCalendarInfoW(
     LCID Locale,
     CALID Calendar,
     CALTYPE CalType,
     LPCWSTR lpCalData);








__declspec(dllimport)
int

LCIDToLocaleName(
     LCID Locale,
     LPWSTR lpName,
     int cchName,
     DWORD dwFlags);

__declspec(dllimport)
LCID

LocaleNameToLCID(
     LPCWSTR lpName,
     DWORD dwFlags);



__declspec(dllimport)
int

GetTimeFormatA(
     LCID Locale,
     DWORD dwFlags,
      const  SYSTEMTIME *lpTime,
     LPCSTR lpFormat,
     LPSTR lpTimeStr,
     int cchTime);
__declspec(dllimport)
int

GetTimeFormatW(
     LCID Locale,
     DWORD dwFlags,
      const  SYSTEMTIME *lpTime,
     LPCWSTR lpFormat,
     LPWSTR lpTimeStr,
     int cchTime);








__declspec(dllimport)
int

GetDurationFormat(
     LCID Locale,
     DWORD dwFlags,
      const  SYSTEMTIME *lpDuration,
     ULONGLONG ullDuration,
     LPCWSTR lpFormat,
     LPWSTR lpDurationStr,
     int cchDuration);


__declspec(dllimport)
int

GetDateFormatA(
     LCID Locale,
     DWORD dwFlags,
      const  SYSTEMTIME *lpDate,
     LPCSTR lpFormat,
     LPSTR lpDateStr,
     int cchDate);
__declspec(dllimport)
int

GetDateFormatW(
     LCID Locale,
     DWORD dwFlags,
      const  SYSTEMTIME *lpDate,
     LPCWSTR lpFormat,
     LPWSTR lpDateStr,
     int cchDate);






__declspec(dllimport)
int

GetNumberFormatA(
     LCID Locale,
     DWORD dwFlags,
     LPCSTR lpValue,
      const  NUMBERFMTA *lpFormat,
     LPSTR lpNumberStr,
     int cchNumber);
__declspec(dllimport)
int

GetNumberFormatW(
     LCID Locale,
     DWORD dwFlags,
     LPCWSTR lpValue,
      const  NUMBERFMTW *lpFormat,
     LPWSTR lpNumberStr,
     int cchNumber);






__declspec(dllimport)
int

GetCurrencyFormatA(
     LCID Locale,
     DWORD dwFlags,
     LPCSTR lpValue,
      const  CURRENCYFMTA *lpFormat,
     LPSTR lpCurrencyStr,
     int cchCurrency);
__declspec(dllimport)
int

GetCurrencyFormatW(
     LCID Locale,
     DWORD dwFlags,
     LPCWSTR lpValue,
      const  CURRENCYFMTW *lpFormat,
     LPWSTR lpCurrencyStr,
     int cchCurrency);






__declspec(dllimport)
BOOL

EnumCalendarInfoA(
     CALINFO_ENUMPROCA lpCalInfoEnumProc,
     LCID Locale,
     CALID Calendar,
     CALTYPE CalType);
__declspec(dllimport)
BOOL

EnumCalendarInfoW(
     CALINFO_ENUMPROCW lpCalInfoEnumProc,
     LCID Locale,
     CALID Calendar,
     CALTYPE CalType);







__declspec(dllimport)
BOOL

EnumCalendarInfoExA(
     CALINFO_ENUMPROCEXA lpCalInfoEnumProcEx,
     LCID Locale,
     CALID Calendar,
     CALTYPE CalType);
__declspec(dllimport)
BOOL

EnumCalendarInfoExW(
     CALINFO_ENUMPROCEXW lpCalInfoEnumProcEx,
     LCID Locale,
     CALID Calendar,
     CALTYPE CalType);







__declspec(dllimport)
BOOL

EnumTimeFormatsA(
     TIMEFMT_ENUMPROCA lpTimeFmtEnumProc,
     LCID Locale,
     DWORD dwFlags);
__declspec(dllimport)
BOOL

EnumTimeFormatsW(
     TIMEFMT_ENUMPROCW lpTimeFmtEnumProc,
     LCID Locale,
     DWORD dwFlags);






__declspec(dllimport)
BOOL

EnumDateFormatsA(
     DATEFMT_ENUMPROCA lpDateFmtEnumProc,
     LCID Locale,
     DWORD dwFlags);
__declspec(dllimport)
BOOL

EnumDateFormatsW(
     DATEFMT_ENUMPROCW lpDateFmtEnumProc,
     LCID Locale,
     DWORD dwFlags);







__declspec(dllimport)
BOOL

EnumDateFormatsExA(
     DATEFMT_ENUMPROCEXA lpDateFmtEnumProcEx,
     LCID Locale,
     DWORD dwFlags);
__declspec(dllimport)
BOOL

EnumDateFormatsExW(
     DATEFMT_ENUMPROCEXW lpDateFmtEnumProcEx,
     LCID Locale,
     DWORD dwFlags);








__declspec(dllimport)
BOOL

IsValidLanguageGroup(
     LGRPID LanguageGroup,
     DWORD dwFlags);


__declspec(dllimport)
BOOL

GetNLSVersion(
     NLS_FUNCTION Function,
     LCID Locale,
     LPNLSVERSIONINFO lpVersionInformation);

__declspec(dllimport)
BOOL

IsNLSDefinedString(
     NLS_FUNCTION Function,
     DWORD dwFlags,
     LPNLSVERSIONINFO lpVersionInformation,
     LPCWSTR lpString,
     INT cchStr);

__declspec(dllimport)
BOOL

IsValidLocale(
     LCID Locale,
     DWORD dwFlags);

__declspec(dllimport)
int

GetGeoInfoA(
     GEOID Location,
     GEOTYPE GeoType,
     LPSTR lpGeoData,
     int cchData,
     LANGID LangId);
__declspec(dllimport)
int

GetGeoInfoW(
     GEOID Location,
     GEOTYPE GeoType,
     LPWSTR lpGeoData,
     int cchData,
     LANGID LangId);






__declspec(dllimport)
BOOL

EnumSystemGeoID(
     GEOCLASS GeoClass,
     GEOID ParentGeoId,
     GEO_ENUMPROC lpGeoEnumProc);

__declspec(dllimport)
GEOID

GetUserGeoID(
     GEOCLASS GeoClass);

__declspec(dllimport)
BOOL

SetUserGeoID(
     GEOID GeoId);

__declspec(dllimport)
LCID

ConvertDefaultLocale(
     LCID Locale);

__declspec(dllimport)
LCID

GetThreadLocale(void);

__declspec(dllimport)
BOOL

SetThreadLocale(
     LCID Locale
    );


__declspec(dllimport)
LANGID

GetSystemDefaultUILanguage(void);

__declspec(dllimport)
LANGID

GetUserDefaultUILanguage(void);


__declspec(dllimport)
LANGID

GetSystemDefaultLangID(void);

__declspec(dllimport)
LANGID

GetUserDefaultLangID(void);

__declspec(dllimport)
LCID

GetSystemDefaultLCID(void);

__declspec(dllimport)
LCID

GetUserDefaultLCID(void);



__declspec(dllimport)
LANGID

SetThreadUILanguage(     LANGID LangId);




__declspec(dllimport)
LANGID

GetThreadUILanguage(void);


__declspec(dllimport)
BOOL

GetUserPreferredUILanguages (
     DWORD dwFlags,
     PULONG pulNumLanguages,
     PWSTR pwszLanguagesBuffer,
     PULONG pcchLanguagesBuffer
);


__declspec(dllimport)
BOOL

GetSystemPreferredUILanguages (
     DWORD dwFlags,
     PULONG pulNumLanguages,
     PWSTR pwszLanguagesBuffer,
     PULONG pcchLanguagesBuffer
);


__declspec(dllimport)
BOOL

GetThreadPreferredUILanguages(
     DWORD dwFlags,
     PULONG pulNumLanguages,
     PWSTR pwszLanguagesBuffer,
     PULONG pcchLanguagesBuffer
);


__declspec(dllimport)
BOOL

SetThreadPreferredUILanguages(
     DWORD dwFlags,
     PCWSTR pwszLanguagesBuffer,
     PULONG pulNumLanguages
);

__declspec(dllimport)

BOOL

GetFileMUIInfo(
                        DWORD dwFlags,
     PCWSTR pcwszFilePath,
     PFILEMUIINFO pFileMUIInfo,
     DWORD* pcbFileMUIInfo);

__declspec(dllimport)
BOOL

GetFileMUIPath(
     DWORD dwFlags,
     PCWSTR pcwszFilePath ,
     PWSTR pwszLanguage,
     PULONG pcchLanguage,
     PWSTR pwszFileMUIPath,
     PULONG pcchFileMUIPath,
     PULONGLONG pululEnumerator
);


__declspec(dllimport)
BOOL

GetUILanguageInfo(
     DWORD dwFlags,
     PCWSTR pwmszLanguage,
     PWSTR pwszFallbackLanguages,
     PDWORD pcchFallbackLanguages,
     PDWORD pAttributes
);


__declspec(dllimport)
BOOL

NotifyUILanguageChange(
     DWORD dwFlags,
     PCWSTR pcwstrNewLanguage,
     PCWSTR pcwstrPreviousLanguage,
     DWORD dwReserved,
     PDWORD pdwStatusRtrn
);







__declspec(dllimport)
BOOL

GetStringTypeExA(
     LCID Locale,
     DWORD dwInfoType,
     LPCSTR lpSrcStr,
     int cchSrc,
     LPWORD lpCharType);
__declspec(dllimport)
BOOL

GetStringTypeExW(
     LCID Locale,
     DWORD dwInfoType,
     LPCWSTR lpSrcStr,
     int cchSrc,
     LPWORD lpCharType);
__declspec(dllimport)
BOOL

GetStringTypeA(
     LCID Locale,
     DWORD dwInfoType,
     LPCSTR lpSrcStr,
     int cchSrc,
     LPWORD lpCharType);

__declspec(dllimport)
BOOL

GetStringTypeW(
     DWORD dwInfoType,
     LPCWSTR lpSrcStr,
     int cchSrc,
     LPWORD lpCharType);


__declspec(dllimport)
int

FoldStringA(
     DWORD dwMapFlags,
     LPCSTR lpSrcStr,
     int cchSrc,
     LPSTR lpDestStr,
     int cchDest);
__declspec(dllimport)
int

FoldStringW(
     DWORD dwMapFlags,
     LPCWSTR lpSrcStr,
     int cchSrc,
     LPWSTR lpDestStr,
     int cchDest);







__declspec(dllimport)
BOOL

EnumSystemLanguageGroupsA(
     LANGUAGEGROUP_ENUMPROCA lpLanguageGroupEnumProc,
     DWORD dwFlags,
     LONG_PTR lParam);
__declspec(dllimport)
BOOL

EnumSystemLanguageGroupsW(
     LANGUAGEGROUP_ENUMPROCW lpLanguageGroupEnumProc,
     DWORD dwFlags,
     LONG_PTR lParam);






__declspec(dllimport)
BOOL

EnumLanguageGroupLocalesA(
     LANGGROUPLOCALE_ENUMPROCA lpLangGroupLocaleEnumProc,
     LGRPID LanguageGroup,
     DWORD dwFlags,
     LONG_PTR lParam);
__declspec(dllimport)
BOOL

EnumLanguageGroupLocalesW(
     LANGGROUPLOCALE_ENUMPROCW lpLangGroupLocaleEnumProc,
     LGRPID LanguageGroup,
     DWORD dwFlags,
     LONG_PTR lParam);






__declspec(dllimport)
BOOL

EnumUILanguagesA(
     UILANGUAGE_ENUMPROCA lpUILanguageEnumProc,
     DWORD dwFlags,
     LONG_PTR lParam);
__declspec(dllimport)
BOOL

EnumUILanguagesW(
     UILANGUAGE_ENUMPROCW lpUILanguageEnumProc,
     DWORD dwFlags,
     LONG_PTR lParam);







__declspec(dllimport)
BOOL

EnumSystemLocalesA(
     LOCALE_ENUMPROCA lpLocaleEnumProc,
     DWORD dwFlags);
__declspec(dllimport)
BOOL

EnumSystemLocalesW(
     LOCALE_ENUMPROCW lpLocaleEnumProc,
     DWORD dwFlags);






__declspec(dllimport)
BOOL

EnumSystemCodePagesA(
     CODEPAGE_ENUMPROCA lpCodePageEnumProc,
     DWORD dwFlags);
__declspec(dllimport)
BOOL

EnumSystemCodePagesW(
     CODEPAGE_ENUMPROCW lpCodePageEnumProc,
     DWORD dwFlags);
__declspec(dllimport)
int
 NormalizeString(      NORM_FORM NormForm,
                         LPCWSTR lpSrcString,
                         int cwSrcLength,
                         LPWSTR lpDstString,
                         int cwDstLength );

__declspec(dllimport)
BOOL
 IsNormalizedString(      NORM_FORM NormForm,
                            LPCWSTR lpString,
                            int cwLength );




__declspec(dllimport)
int
 IdnToAscii(     DWORD dwFlags,
                   LPCWSTR lpUnicodeCharStr,
                   int cchUnicodeChar,
                   LPWSTR lpASCIICharStr,
                   int cchASCIIChar);

__declspec(dllimport)
int
 IdnToNameprepUnicode(     DWORD dwFlags,
                             LPCWSTR lpUnicodeCharStr,
                             int cchUnicodeChar,
                             LPWSTR lpNameprepCharStr,
                             int cchNameprepChar);

__declspec(dllimport)
int
 IdnToUnicode(     DWORD dwFlags,
                     LPCWSTR lpASCIICharStr,
                     int cchASCIIChar,
                     LPWSTR lpUnicodeCharStr,
                     int cchUnicodeChar);

__declspec(dllimport)
BOOL
 VerifyScripts(
     DWORD dwFlags,
     LPCWSTR lpLocaleScripts,
     int cchLocaleScripts,
     LPCWSTR lpTestScripts,
     int cchTestScripts);

__declspec(dllimport)
int
 GetStringScripts(
         DWORD dwFlags,
         LPCWSTR lpString,
         int cchString,
         LPWSTR lpScripts,
         int cchScripts);
__declspec(dllimport)
int

GetLocaleInfoEx(
     LPCWSTR lpLocaleName,
     LCTYPE LCType,
     LPWSTR lpLCData,
     int cchData
);

__declspec(dllimport)
int

GetCalendarInfoEx(
     LPCWSTR lpLocaleName,
     CALID Calendar,
     LPCWSTR lpReserved,
     CALTYPE CalType,
     LPWSTR lpCalData,
     int cchData,
     LPDWORD lpValue
);


__declspec(dllimport)
int

GetTimeFormatEx(
     LPCWSTR lpLocaleName,
     DWORD dwFlags,
      const  SYSTEMTIME *lpTime,
     LPCWSTR lpFormat,
     LPWSTR lpTimeStr,
     int cchTime
);

__declspec(dllimport)
int

GetDateFormatEx(
     LPCWSTR lpLocaleName,
     DWORD dwFlags,
      const  SYSTEMTIME *lpDate,
     LPCWSTR lpFormat,
     LPWSTR lpDateStr,
     int cchDate,
     LPCWSTR lpCalendar
);

__declspec(dllimport)
int

GetDurationFormatEx(
     LPCWSTR lpLocaleName,
     DWORD dwFlags,
      const  SYSTEMTIME *lpDuration,
     ULONGLONG ullDuration,
     LPCWSTR lpFormat,
     LPWSTR lpDurationStr,
     int cchDuration
);

__declspec(dllimport)
int

GetNumberFormatEx(
     LPCWSTR lpLocaleName,
     DWORD dwFlags,
     LPCWSTR lpValue,
      const  NUMBERFMTW *lpFormat,
     LPWSTR lpNumberStr,
     int cchNumber
);

__declspec(dllimport)
int

GetCurrencyFormatEx(
     LPCWSTR lpLocaleName,
     DWORD dwFlags,
     LPCWSTR lpValue,
      const  CURRENCYFMTW *lpFormat,
     LPWSTR lpCurrencyStr,
     int cchCurrency
);

__declspec(dllimport)
int

GetUserDefaultLocaleName(
     LPWSTR lpLocaleName,
     int cchLocaleName
);

__declspec(dllimport)
int

GetSystemDefaultLocaleName(
     LPWSTR lpLocaleName,
     int cchLocaleName
);

__declspec(dllimport)
BOOL

GetNLSVersionEx(
     NLS_FUNCTION function,
     LPCWSTR lpLocaleName,
     LPNLSVERSIONINFOEX lpVersionInformation
);

__declspec(dllimport)
int

CompareStringEx(
     LPCWSTR lpLocaleName,
     DWORD dwCmpFlags,
     LPCWSTR lpString1,
     int cchCount1,
     LPCWSTR lpString2,
     int cchCount2,
     LPNLSVERSIONINFO lpVersionInformation,
     LPVOID lpReserved,
     LPARAM lParam
);

__declspec(dllimport)
int

FindNLSStringEx(
     LPCWSTR lpLocaleName,
     DWORD dwFindNLSStringFlags,
     LPCWSTR lpStringSource,
     int cchSource,
     LPCWSTR lpStringValue,
     int cchValue,
     LPINT pcchFound,
     LPNLSVERSIONINFO lpVersionInformation,
     LPVOID lpReserved,
     LPARAM lParam
);


__declspec(dllimport)
int

LCMapStringEx(
     LPCWSTR lpLocaleName,
     DWORD dwMapFlags,
     LPCWSTR lpSrcStr,
     int cchSrc,
     LPWSTR lpDestStr,
     int cchDest,
     LPNLSVERSIONINFO lpVersionInformation,
     LPVOID lpReserved,
     LPARAM lParam
);

__declspec(dllimport)
int

CompareStringOrdinal(
     LPCWSTR lpString1,
     int cchCount1,
     LPCWSTR lpString2,
     int cchCount2,
     BOOL bIgnoreCase
);

__declspec(dllimport)
BOOL

IsValidLocaleName(
     LPCWSTR lpLocaleName
);

typedef BOOL ( * CALINFO_ENUMPROCEXEX)(LPWSTR, CALID, LPWSTR, LPARAM);

__declspec(dllimport)
BOOL

EnumCalendarInfoExEx(
     CALINFO_ENUMPROCEXEX pCalInfoEnumProcExEx,
     LPCWSTR lpLocaleName,
     CALID Calendar,
     LPCWSTR lpReserved,
     CALTYPE CalType,
     LPARAM lParam
);

typedef BOOL ( * DATEFMT_ENUMPROCEXEX)(LPWSTR, CALID, LPARAM);

__declspec(dllimport)
BOOL

EnumDateFormatsExEx(
     DATEFMT_ENUMPROCEXEX lpDateFmtEnumProcExEx,
     LPCWSTR lpLocaleName,
     DWORD dwFlags,
     LPARAM lParam
);

typedef BOOL ( * TIMEFMT_ENUMPROCEX)(LPWSTR, LPARAM);

__declspec(dllimport)
BOOL

EnumTimeFormatsEx(
     TIMEFMT_ENUMPROCEX lpTimeFmtEnumProcEx,
     LPCWSTR lpLocaleName,
     DWORD dwFlags,
     LPARAM lParam
);

typedef BOOL ( * LOCALE_ENUMPROCEX)(LPWSTR, DWORD, LPARAM);

__declspec(dllimport)
BOOL

EnumSystemLocalesEx(
     LOCALE_ENUMPROCEX lpLocaleEnumProcEx,
     DWORD dwFlags,
     LPARAM lParam,
     LPVOID lpReserved
);
typedef struct _COORD {
    SHORT X;
    SHORT Y;
} COORD, *PCOORD;

typedef struct _SMALL_RECT {
    SHORT Left;
    SHORT Top;
    SHORT Right;
    SHORT Bottom;
} SMALL_RECT, *PSMALL_RECT;

typedef struct _KEY_EVENT_RECORD {
    BOOL bKeyDown;
    WORD wRepeatCount;
    WORD wVirtualKeyCode;
    WORD wVirtualScanCode;
    union {
        WCHAR UnicodeChar;
        CHAR AsciiChar;
    } uChar;
    DWORD dwControlKeyState;
} KEY_EVENT_RECORD, *PKEY_EVENT_RECORD;
typedef struct _MOUSE_EVENT_RECORD {
    COORD dwMousePosition;
    DWORD dwButtonState;
    DWORD dwControlKeyState;
    DWORD dwEventFlags;
} MOUSE_EVENT_RECORD, *PMOUSE_EVENT_RECORD;
typedef struct _WINDOW_BUFFER_SIZE_RECORD {
    COORD dwSize;
} WINDOW_BUFFER_SIZE_RECORD, *PWINDOW_BUFFER_SIZE_RECORD;

typedef struct _MENU_EVENT_RECORD {
    UINT dwCommandId;
} MENU_EVENT_RECORD, *PMENU_EVENT_RECORD;

typedef struct _FOCUS_EVENT_RECORD {
    BOOL bSetFocus;
} FOCUS_EVENT_RECORD, *PFOCUS_EVENT_RECORD;

typedef struct _INPUT_RECORD {
    WORD EventType;
    union {
        KEY_EVENT_RECORD KeyEvent;
        MOUSE_EVENT_RECORD MouseEvent;
        WINDOW_BUFFER_SIZE_RECORD WindowBufferSizeEvent;
        MENU_EVENT_RECORD MenuEvent;
        FOCUS_EVENT_RECORD FocusEvent;
    } Event;
} INPUT_RECORD, *PINPUT_RECORD;
typedef struct _CHAR_INFO {
    union {
        WCHAR UnicodeChar;
        CHAR AsciiChar;
    } Char;
    WORD Attributes;
} CHAR_INFO, *PCHAR_INFO;
typedef struct _CONSOLE_SCREEN_BUFFER_INFO {
    COORD dwSize;
    COORD dwCursorPosition;
    WORD wAttributes;
    SMALL_RECT srWindow;
    COORD dwMaximumWindowSize;
} CONSOLE_SCREEN_BUFFER_INFO, *PCONSOLE_SCREEN_BUFFER_INFO;

typedef struct _CONSOLE_SCREEN_BUFFER_INFOEX {
    ULONG cbSize;
    COORD dwSize;
    COORD dwCursorPosition;
    WORD wAttributes;
    SMALL_RECT srWindow;
    COORD dwMaximumWindowSize;
    WORD wPopupAttributes;
    BOOL bFullscreenSupported;
    COLORREF ColorTable[16];
} CONSOLE_SCREEN_BUFFER_INFOEX, *PCONSOLE_SCREEN_BUFFER_INFOEX;

typedef struct _CONSOLE_CURSOR_INFO {
    DWORD dwSize;
    BOOL bVisible;
} CONSOLE_CURSOR_INFO, *PCONSOLE_CURSOR_INFO;

typedef struct _CONSOLE_FONT_INFO {
    DWORD nFont;
    COORD dwFontSize;
} CONSOLE_FONT_INFO, *PCONSOLE_FONT_INFO;


typedef struct _CONSOLE_FONT_INFOEX {
    ULONG cbSize;
    DWORD nFont;
    COORD dwFontSize;
    UINT FontFamily;
    UINT FontWeight;
    WCHAR FaceName[ 32 ];
} CONSOLE_FONT_INFOEX, *PCONSOLE_FONT_INFOEX;



typedef struct _CONSOLE_HISTORY_INFO {
    UINT cbSize;
    UINT HistoryBufferSize;
    UINT NumberOfHistoryBuffers;
    DWORD dwFlags;
} CONSOLE_HISTORY_INFO, *PCONSOLE_HISTORY_INFO;


typedef struct _CONSOLE_SELECTION_INFO {
    DWORD dwFlags;
    COORD dwSelectionAnchor;
    SMALL_RECT srSelection;
} CONSOLE_SELECTION_INFO, *PCONSOLE_SELECTION_INFO;
typedef
BOOL
(  *PHANDLER_ROUTINE)(
    DWORD CtrlType
    );
__declspec(dllimport)
BOOL

PeekConsoleInputA(
     HANDLE hConsoleInput,
     PINPUT_RECORD lpBuffer,
     DWORD nLength,
     LPDWORD lpNumberOfEventsRead
    );
__declspec(dllimport)
BOOL

PeekConsoleInputW(
     HANDLE hConsoleInput,
     PINPUT_RECORD lpBuffer,
     DWORD nLength,
     LPDWORD lpNumberOfEventsRead
    );






__declspec(dllimport)
BOOL

ReadConsoleInputA(
     HANDLE hConsoleInput,
     PINPUT_RECORD lpBuffer,
     DWORD nLength,
     LPDWORD lpNumberOfEventsRead
    );
__declspec(dllimport)
BOOL

ReadConsoleInputW(
     HANDLE hConsoleInput,
     PINPUT_RECORD lpBuffer,
     DWORD nLength,
     LPDWORD lpNumberOfEventsRead
    );






__declspec(dllimport)
BOOL

WriteConsoleInputA(
     HANDLE hConsoleInput,
      const  INPUT_RECORD *lpBuffer,
     DWORD nLength,
     LPDWORD lpNumberOfEventsWritten
    );
__declspec(dllimport)
BOOL

WriteConsoleInputW(
     HANDLE hConsoleInput,
      const  INPUT_RECORD *lpBuffer,
     DWORD nLength,
     LPDWORD lpNumberOfEventsWritten
    );






__declspec(dllimport)
BOOL

ReadConsoleOutputA(
     HANDLE hConsoleOutput,
     PCHAR_INFO lpBuffer,
     COORD dwBufferSize,
     COORD dwBufferCoord,
     PSMALL_RECT lpReadRegion
    );
__declspec(dllimport)
BOOL

ReadConsoleOutputW(
     HANDLE hConsoleOutput,
     PCHAR_INFO lpBuffer,
     COORD dwBufferSize,
     COORD dwBufferCoord,
     PSMALL_RECT lpReadRegion
    );






__declspec(dllimport)
BOOL

WriteConsoleOutputA(
     HANDLE hConsoleOutput,
      const  CHAR_INFO *lpBuffer,
     COORD dwBufferSize,
     COORD dwBufferCoord,
     PSMALL_RECT lpWriteRegion
    );
__declspec(dllimport)
BOOL

WriteConsoleOutputW(
     HANDLE hConsoleOutput,
      const  CHAR_INFO *lpBuffer,
     COORD dwBufferSize,
     COORD dwBufferCoord,
     PSMALL_RECT lpWriteRegion
    );






__declspec(dllimport)
BOOL

ReadConsoleOutputCharacterA(
     HANDLE hConsoleOutput,
     LPSTR lpCharacter,
     DWORD nLength,
     COORD dwReadCoord,
     LPDWORD lpNumberOfCharsRead
    );
__declspec(dllimport)
BOOL

ReadConsoleOutputCharacterW(
     HANDLE hConsoleOutput,
     LPWSTR lpCharacter,
     DWORD nLength,
     COORD dwReadCoord,
     LPDWORD lpNumberOfCharsRead
    );






__declspec(dllimport)
BOOL

ReadConsoleOutputAttribute(
     HANDLE hConsoleOutput,
     LPWORD lpAttribute,
     DWORD nLength,
     COORD dwReadCoord,
     LPDWORD lpNumberOfAttrsRead
    );

__declspec(dllimport)
BOOL

WriteConsoleOutputCharacterA(
     HANDLE hConsoleOutput,
     LPCSTR lpCharacter,
     DWORD nLength,
     COORD dwWriteCoord,
     LPDWORD lpNumberOfCharsWritten
    );
__declspec(dllimport)
BOOL

WriteConsoleOutputCharacterW(
     HANDLE hConsoleOutput,
     LPCWSTR lpCharacter,
     DWORD nLength,
     COORD dwWriteCoord,
     LPDWORD lpNumberOfCharsWritten
    );






__declspec(dllimport)
BOOL

WriteConsoleOutputAttribute(
     HANDLE hConsoleOutput,
      const  WORD *lpAttribute,
     DWORD nLength,
     COORD dwWriteCoord,
     LPDWORD lpNumberOfAttrsWritten
    );

__declspec(dllimport)
BOOL

FillConsoleOutputCharacterA(
     HANDLE hConsoleOutput,
     CHAR cCharacter,
     DWORD nLength,
     COORD dwWriteCoord,
     LPDWORD lpNumberOfCharsWritten
    );
__declspec(dllimport)
BOOL

FillConsoleOutputCharacterW(
     HANDLE hConsoleOutput,
     WCHAR cCharacter,
     DWORD nLength,
     COORD dwWriteCoord,
     LPDWORD lpNumberOfCharsWritten
    );






__declspec(dllimport)
BOOL

FillConsoleOutputAttribute(
     HANDLE hConsoleOutput,
     WORD wAttribute,
     DWORD nLength,
     COORD dwWriteCoord,
     LPDWORD lpNumberOfAttrsWritten
    );

__declspec(dllimport)
BOOL

GetConsoleMode(
     HANDLE hConsoleHandle,
     LPDWORD lpMode
    );

__declspec(dllimport)
BOOL

GetNumberOfConsoleInputEvents(
     HANDLE hConsoleInput,
     LPDWORD lpNumberOfEvents
    );




__declspec(dllimport)
BOOL

GetConsoleScreenBufferInfo(
     HANDLE hConsoleOutput,
     PCONSOLE_SCREEN_BUFFER_INFO lpConsoleScreenBufferInfo
    );

__declspec(dllimport)
BOOL

GetConsoleScreenBufferInfoEx(
     HANDLE hConsoleOutput,
     PCONSOLE_SCREEN_BUFFER_INFOEX lpConsoleScreenBufferInfoEx);

__declspec(dllimport)
BOOL

SetConsoleScreenBufferInfoEx(
     HANDLE hConsoleOutput,
     PCONSOLE_SCREEN_BUFFER_INFOEX lpConsoleScreenBufferInfoEx);

__declspec(dllimport)
COORD

GetLargestConsoleWindowSize(
     HANDLE hConsoleOutput
    );

__declspec(dllimport)
BOOL

GetConsoleCursorInfo(
     HANDLE hConsoleOutput,
     PCONSOLE_CURSOR_INFO lpConsoleCursorInfo
    );



__declspec(dllimport)
BOOL

GetCurrentConsoleFont(
     HANDLE hConsoleOutput,
     BOOL bMaximumWindow,
     PCONSOLE_FONT_INFO lpConsoleCurrentFont
    );


__declspec(dllimport)
BOOL

GetCurrentConsoleFontEx(
     HANDLE hConsoleOutput,
     BOOL bMaximumWindow,
     PCONSOLE_FONT_INFOEX lpConsoleCurrentFontEx);

__declspec(dllimport)
BOOL

SetCurrentConsoleFontEx(
     HANDLE hConsoleOutput,
     BOOL bMaximumWindow,
     PCONSOLE_FONT_INFOEX lpConsoleCurrentFontEx);


__declspec(dllimport)
BOOL

GetConsoleHistoryInfo(
     PCONSOLE_HISTORY_INFO lpConsoleHistoryInfo);

__declspec(dllimport)
BOOL

SetConsoleHistoryInfo(
     PCONSOLE_HISTORY_INFO lpConsoleHistoryInfo);

__declspec(dllimport)
COORD

GetConsoleFontSize(
     HANDLE hConsoleOutput,
     DWORD nFont
    );

__declspec(dllimport)
BOOL

GetConsoleSelectionInfo(
     PCONSOLE_SELECTION_INFO lpConsoleSelectionInfo
    );



__declspec(dllimport)
BOOL

GetNumberOfConsoleMouseButtons(
     LPDWORD lpNumberOfMouseButtons
    );

__declspec(dllimport)
BOOL

SetConsoleMode(
     HANDLE hConsoleHandle,
     DWORD dwMode
    );

__declspec(dllimport)
BOOL

SetConsoleActiveScreenBuffer(
     HANDLE hConsoleOutput
    );

__declspec(dllimport)
BOOL

FlushConsoleInputBuffer(
     HANDLE hConsoleInput
    );

__declspec(dllimport)
BOOL

SetConsoleScreenBufferSize(
     HANDLE hConsoleOutput,
     COORD dwSize
    );

__declspec(dllimport)
BOOL

SetConsoleCursorPosition(
     HANDLE hConsoleOutput,
     COORD dwCursorPosition
    );

__declspec(dllimport)
BOOL

SetConsoleCursorInfo(
     HANDLE hConsoleOutput,
      const  CONSOLE_CURSOR_INFO *lpConsoleCursorInfo
    );

__declspec(dllimport)
BOOL

ScrollConsoleScreenBufferA(
     HANDLE hConsoleOutput,
      const  SMALL_RECT *lpScrollRectangle,
      const  SMALL_RECT *lpClipRectangle,
     COORD dwDestinationOrigin,
      const  CHAR_INFO *lpFill
    );
__declspec(dllimport)
BOOL

ScrollConsoleScreenBufferW(
     HANDLE hConsoleOutput,
      const  SMALL_RECT *lpScrollRectangle,
      const  SMALL_RECT *lpClipRectangle,
     COORD dwDestinationOrigin,
      const  CHAR_INFO *lpFill
    );






__declspec(dllimport)
BOOL

SetConsoleWindowInfo(
     HANDLE hConsoleOutput,
     BOOL bAbsolute,
      const  SMALL_RECT *lpConsoleWindow
    );

__declspec(dllimport)
BOOL

SetConsoleTextAttribute(
     HANDLE hConsoleOutput,
     WORD wAttributes
    );

__declspec(dllimport)
BOOL

SetConsoleCtrlHandler(
     PHANDLER_ROUTINE HandlerRoutine,
     BOOL Add);

__declspec(dllimport)
BOOL

GenerateConsoleCtrlEvent(
     DWORD dwCtrlEvent,
     DWORD dwProcessGroupId
    );

__declspec(dllimport)
BOOL

AllocConsole(  void  );

__declspec(dllimport)
BOOL

FreeConsole(  void  );


__declspec(dllimport)
BOOL

AttachConsole(
     DWORD dwProcessId
    );




__declspec(dllimport)
DWORD

GetConsoleTitleA(
     LPSTR lpConsoleTitle,
     DWORD nSize
    );
__declspec(dllimport)
DWORD

GetConsoleTitleW(
     LPWSTR lpConsoleTitle,
     DWORD nSize
    );







__declspec(dllimport)
DWORD

GetConsoleOriginalTitleA(
     LPSTR lpConsoleTitle,
     DWORD nSize);
__declspec(dllimport)
DWORD

GetConsoleOriginalTitleW(
     LPWSTR lpConsoleTitle,
     DWORD nSize);







__declspec(dllimport)
BOOL

SetConsoleTitleA(
     LPCSTR lpConsoleTitle
    );
__declspec(dllimport)
BOOL

SetConsoleTitleW(
     LPCWSTR lpConsoleTitle
    );






typedef struct _CONSOLE_READCONSOLE_CONTROL {
     ULONG nLength;
     ULONG nInitialChars;
     ULONG dwCtrlWakeupMask;
     ULONG dwControlKeyState;
} CONSOLE_READCONSOLE_CONTROL, *PCONSOLE_READCONSOLE_CONTROL;

__declspec(dllimport)
BOOL

ReadConsoleA(
     HANDLE hConsoleInput,

       LPVOID lpBuffer,
     DWORD nNumberOfCharsToRead,
     LPDWORD lpNumberOfCharsRead,
     PCONSOLE_READCONSOLE_CONTROL pInputControl
    );
__declspec(dllimport)
BOOL

ReadConsoleW(
     HANDLE hConsoleInput,

       LPVOID lpBuffer,
     DWORD nNumberOfCharsToRead,
     LPDWORD lpNumberOfCharsRead,
     PCONSOLE_READCONSOLE_CONTROL pInputControl
    );






__declspec(dllimport)
BOOL

WriteConsoleA(
     HANDLE hConsoleOutput,
      const   void  *lpBuffer,
     DWORD nNumberOfCharsToWrite,
     LPDWORD lpNumberOfCharsWritten,
     LPVOID lpReserved
    );
__declspec(dllimport)
BOOL

WriteConsoleW(
     HANDLE hConsoleOutput,
      const   void  *lpBuffer,
     DWORD nNumberOfCharsToWrite,
     LPDWORD lpNumberOfCharsWritten,
     LPVOID lpReserved
    );









__declspec(dllimport)
HANDLE

CreateConsoleScreenBuffer(
     DWORD dwDesiredAccess,
     DWORD dwShareMode,
      const  SECURITY_ATTRIBUTES *lpSecurityAttributes,
     DWORD dwFlags,
     LPVOID lpScreenBufferData
    );

__declspec(dllimport)
UINT

GetConsoleCP(  void  );

__declspec(dllimport)
BOOL

SetConsoleCP(
     UINT wCodePageID
    );

__declspec(dllimport)
UINT

GetConsoleOutputCP(  void  );

__declspec(dllimport)
BOOL

SetConsoleOutputCP(
     UINT wCodePageID
    );






__declspec(dllimport)
BOOL

GetConsoleDisplayMode(
     LPDWORD lpModeFlags);




BOOL

SetConsoleDisplayMode(
     HANDLE hConsoleOutput,
     DWORD dwFlags,
     PCOORD lpNewScreenBufferDimensions);

__declspec(dllimport)
HWND

GetConsoleWindow(
    void
    );





__declspec(dllimport)
DWORD

GetConsoleProcessList(
     LPDWORD lpdwProcessList,
     DWORD dwProcessCount);





__declspec(dllimport)
BOOL

AddConsoleAliasA(
     LPSTR Source,
     LPSTR Target,
     LPSTR ExeName);
__declspec(dllimport)
BOOL

AddConsoleAliasW(
     LPWSTR Source,
     LPWSTR Target,
     LPWSTR ExeName);






__declspec(dllimport)
DWORD

GetConsoleAliasA(
     LPSTR Source,
     LPSTR TargetBuffer,
     DWORD TargetBufferLength,
     LPSTR ExeName);
__declspec(dllimport)
DWORD

GetConsoleAliasW(
     LPWSTR Source,
     LPWSTR TargetBuffer,
     DWORD TargetBufferLength,
     LPWSTR ExeName);






__declspec(dllimport)
DWORD

GetConsoleAliasesLengthA(
     LPSTR ExeName);
__declspec(dllimport)
DWORD

GetConsoleAliasesLengthW(
     LPWSTR ExeName);






__declspec(dllimport)
DWORD

GetConsoleAliasExesLengthA(
    void );
__declspec(dllimport)
DWORD

GetConsoleAliasExesLengthW(
    void );






__declspec(dllimport)
DWORD

GetConsoleAliasesA(
     LPSTR AliasBuffer,
     DWORD AliasBufferLength,
     LPSTR ExeName);
__declspec(dllimport)
DWORD

GetConsoleAliasesW(
     LPWSTR AliasBuffer,
     DWORD AliasBufferLength,
     LPWSTR ExeName);






__declspec(dllimport)
DWORD

GetConsoleAliasExesA(
     LPSTR ExeNameBuffer,
     DWORD ExeNameBufferLength);
__declspec(dllimport)
DWORD

GetConsoleAliasExesW(
     LPWSTR ExeNameBuffer,
     DWORD ExeNameBufferLength);
typedef struct tagVS_FIXEDFILEINFO
{
    DWORD dwSignature;
    DWORD dwStrucVersion;
    DWORD dwFileVersionMS;
    DWORD dwFileVersionLS;
    DWORD dwProductVersionMS;
    DWORD dwProductVersionLS;
    DWORD dwFileFlagsMask;
    DWORD dwFileFlags;
    DWORD dwFileOS;
    DWORD dwFileType;
    DWORD dwFileSubtype;
    DWORD dwFileDateMS;
    DWORD dwFileDateLS;
} VS_FIXEDFILEINFO;



DWORD

VerFindFileA(
         DWORD uFlags,
         LPCSTR szFileName,
         LPCSTR szWinDir,
         LPCSTR szAppDir,
         LPSTR szCurDir,
         PUINT lpuCurDirLen,
         LPSTR szDestDir,
         PUINT lpuDestDirLen
        );
DWORD

VerFindFileW(
         DWORD uFlags,
         LPCWSTR szFileName,
         LPCWSTR szWinDir,
         LPCWSTR szAppDir,
         LPWSTR szCurDir,
         PUINT lpuCurDirLen,
         LPWSTR szDestDir,
         PUINT lpuDestDirLen
        );






DWORD

VerInstallFileA(
         DWORD uFlags,
         LPCSTR szSrcFileName,
         LPCSTR szDestFileName,
         LPCSTR szSrcDir,
         LPCSTR szDestDir,
         LPCSTR szCurDir,
         LPSTR szTmpFile,
         PUINT lpuTmpFileLen
        );
DWORD

VerInstallFileW(
         DWORD uFlags,
         LPCWSTR szSrcFileName,
         LPCWSTR szDestFileName,
         LPCWSTR szSrcDir,
         LPCWSTR szDestDir,
         LPCWSTR szCurDir,
         LPWSTR szTmpFile,
         PUINT lpuTmpFileLen
        );







DWORD

GetFileVersionInfoSizeA(
         LPCSTR lptstrFilename,
         LPDWORD lpdwHandle
        );

DWORD

GetFileVersionInfoSizeW(
         LPCWSTR lptstrFilename,
         LPDWORD lpdwHandle
        );







BOOL

GetFileVersionInfoA(
         LPCSTR lptstrFilename,
         DWORD dwHandle,
         DWORD dwLen,
         LPVOID lpData
        );

BOOL

GetFileVersionInfoW(
         LPCWSTR lptstrFilename,
         DWORD dwHandle,
         DWORD dwLen,
         LPVOID lpData
        );






DWORD   GetFileVersionInfoSizeExA(     DWORD dwFlags,      LPCSTR lpwstrFilename,      LPDWORD lpdwHandle);
DWORD   GetFileVersionInfoSizeExW(     DWORD dwFlags,      LPCWSTR lpwstrFilename,      LPDWORD lpdwHandle);






BOOL   GetFileVersionInfoExA(     DWORD dwFlags,
                                     LPCSTR lpwstrFilename,
                                     DWORD dwHandle,
                                     DWORD dwLen,
                                     LPVOID lpData);
BOOL   GetFileVersionInfoExW(     DWORD dwFlags,
                                     LPCWSTR lpwstrFilename,
                                     DWORD dwHandle,
                                     DWORD dwLen,
                                     LPVOID lpData);






DWORD

VerLanguageNameA(
         DWORD wLang,
         LPSTR szLang,
         DWORD cchLang
        );
DWORD

VerLanguageNameW(
         DWORD wLang,
         LPWSTR szLang,
         DWORD cchLang
        );






BOOL

VerQueryValueA(
         LPCVOID pBlock,
         LPCSTR lpSubBlock,
         LPVOID * lplpBuffer,
         PUINT puLen
        );
BOOL

VerQueryValueW(
         LPCVOID pBlock,
         LPCWSTR lpSubBlock,
         LPVOID * lplpBuffer,
         PUINT puLen
        );
typedef ACCESS_MASK REGSAM;
struct val_context {
    int valuelen;
    LPVOID value_context;
    LPVOID val_buff_ptr;
};

typedef struct val_context   *PVALCONTEXT;

typedef struct pvalueA {
    LPSTR pv_valuename;
    int pv_valuelen;
    LPVOID pv_value_context;
    DWORD pv_type;
}PVALUEA,   *PPVALUEA;
typedef struct pvalueW {
    LPWSTR pv_valuename;
    int pv_valuelen;
    LPVOID pv_value_context;
    DWORD pv_type;
}PVALUEW,   *PPVALUEW;




typedef PVALUEA PVALUE;
typedef PPVALUEA PPVALUE;


typedef
DWORD
QUERYHANDLER (LPVOID keycontext, PVALCONTEXT val_list, DWORD num_vals,
          LPVOID outputbuffer, DWORD   *total_outlen, DWORD input_blen);

typedef QUERYHANDLER   *PQUERYHANDLER;

typedef struct provider_info {
    PQUERYHANDLER pi_R0_1val;
    PQUERYHANDLER pi_R0_allvals;
    PQUERYHANDLER pi_R3_1val;
    PQUERYHANDLER pi_R3_allvals;
    DWORD pi_flags;
    LPVOID pi_key_context;
}REG_PROVIDER;

typedef struct provider_info   *PPROVIDER;

typedef struct value_entA {
    LPSTR ve_valuename;
    DWORD ve_valuelen;
    DWORD_PTR ve_valueptr;
    DWORD ve_type;
}VALENTA,   *PVALENTA;
typedef struct value_entW {
    LPWSTR ve_valuename;
    DWORD ve_valuelen;
    DWORD_PTR ve_valueptr;
    DWORD ve_type;
}VALENTW,   *PVALENTW;




typedef VALENTA VALENT;
typedef PVALENTA PVALENT;
typedef   LONG LSTATUS;

__declspec(dllimport)
LSTATUS

RegCloseKey (
     HKEY hKey
    );

__declspec(dllimport)
LSTATUS

RegOverridePredefKey (
     HKEY hKey,
     HKEY hNewHKey
    );

__declspec(dllimport)
LSTATUS

RegOpenUserClassesRoot(
     HANDLE hToken,
     DWORD dwOptions,
     REGSAM samDesired,
     PHKEY phkResult
    );

__declspec(dllimport)
LSTATUS

RegOpenCurrentUser(
     REGSAM samDesired,
     PHKEY phkResult
    );

__declspec(dllimport)
LSTATUS

RegDisablePredefinedCache(
    void
    );

__declspec(dllimport)
LSTATUS

RegDisablePredefinedCacheEx(
    void
    );

__declspec(dllimport)
LSTATUS

RegConnectRegistryA (
     LPCSTR lpMachineName,
     HKEY hKey,
     PHKEY phkResult
    );
__declspec(dllimport)
LSTATUS

RegConnectRegistryW (
     LPCWSTR lpMachineName,
     HKEY hKey,
     PHKEY phkResult
    );






__declspec(dllimport)
LSTATUS

RegConnectRegistryExA (
     LPCSTR lpMachineName,
     HKEY hKey,
     ULONG Flags,
     PHKEY phkResult
    );
__declspec(dllimport)
LSTATUS

RegConnectRegistryExW (
     LPCWSTR lpMachineName,
     HKEY hKey,
     ULONG Flags,
     PHKEY phkResult
    );






__declspec(dllimport)
LSTATUS

RegCreateKeyA (
     HKEY hKey,
     LPCSTR lpSubKey,
     PHKEY phkResult
    );
__declspec(dllimport)
LSTATUS

RegCreateKeyW (
     HKEY hKey,
     LPCWSTR lpSubKey,
     PHKEY phkResult
    );






__declspec(dllimport)
LSTATUS

RegCreateKeyExA (
     HKEY hKey,
     LPCSTR lpSubKey,
     DWORD Reserved,
     LPSTR lpClass,
     DWORD dwOptions,
     REGSAM samDesired,
      const  LPSECURITY_ATTRIBUTES lpSecurityAttributes,
     PHKEY phkResult,
     LPDWORD lpdwDisposition
    );
__declspec(dllimport)
LSTATUS

RegCreateKeyExW (
     HKEY hKey,
     LPCWSTR lpSubKey,
     DWORD Reserved,
     LPWSTR lpClass,
     DWORD dwOptions,
     REGSAM samDesired,
      const  LPSECURITY_ATTRIBUTES lpSecurityAttributes,
     PHKEY phkResult,
     LPDWORD lpdwDisposition
    );






__declspec(dllimport)
LSTATUS

RegCreateKeyTransactedA (
     HKEY hKey,
     LPCSTR lpSubKey,
     DWORD Reserved,
     LPSTR lpClass,
     DWORD dwOptions,
     REGSAM samDesired,
      const  LPSECURITY_ATTRIBUTES lpSecurityAttributes,
     PHKEY phkResult,
     LPDWORD lpdwDisposition,
     HANDLE hTransaction,
     PVOID pExtendedParemeter
    );
__declspec(dllimport)
LSTATUS

RegCreateKeyTransactedW (
     HKEY hKey,
     LPCWSTR lpSubKey,
     DWORD Reserved,
     LPWSTR lpClass,
     DWORD dwOptions,
     REGSAM samDesired,
      const  LPSECURITY_ATTRIBUTES lpSecurityAttributes,
     PHKEY phkResult,
     LPDWORD lpdwDisposition,
     HANDLE hTransaction,
     PVOID pExtendedParemeter
    );






__declspec(dllimport)
LSTATUS

RegDeleteKeyA (
     HKEY hKey,
     LPCSTR lpSubKey
    );
__declspec(dllimport)
LSTATUS

RegDeleteKeyW (
     HKEY hKey,
     LPCWSTR lpSubKey
    );






__declspec(dllimport)
LSTATUS

RegDeleteKeyExA (
     HKEY hKey,
     LPCSTR lpSubKey,
     REGSAM samDesired,
     DWORD Reserved
    );
__declspec(dllimport)
LSTATUS

RegDeleteKeyExW (
     HKEY hKey,
     LPCWSTR lpSubKey,
     REGSAM samDesired,
     DWORD Reserved
    );






__declspec(dllimport)
LSTATUS

RegDeleteKeyTransactedA (
     HKEY hKey,
     LPCSTR lpSubKey,
     REGSAM samDesired,
     DWORD Reserved,
     HANDLE hTransaction,
     PVOID pExtendedParameter
    );
__declspec(dllimport)
LSTATUS

RegDeleteKeyTransactedW (
     HKEY hKey,
     LPCWSTR lpSubKey,
     REGSAM samDesired,
     DWORD Reserved,
     HANDLE hTransaction,
     PVOID pExtendedParameter
    );






__declspec(dllimport)
LONG

RegDisableReflectionKey (
     HKEY hBase
    );

__declspec(dllimport)
LONG

RegEnableReflectionKey (
     HKEY hBase
    );

__declspec(dllimport)
LONG

RegQueryReflectionKey (
     HKEY hBase,
     BOOL *bIsReflectionDisabled
    );

__declspec(dllimport)
LSTATUS

RegDeleteValueA (
     HKEY hKey,
     LPCSTR lpValueName
    );
__declspec(dllimport)
LSTATUS

RegDeleteValueW (
     HKEY hKey,
     LPCWSTR lpValueName
    );






__declspec(dllimport)
LSTATUS

RegEnumKeyA (
     HKEY hKey,
     DWORD dwIndex,
     LPSTR lpName,
     DWORD cchName
    );
__declspec(dllimport)
LSTATUS

RegEnumKeyW (
     HKEY hKey,
     DWORD dwIndex,
     LPWSTR lpName,
     DWORD cchName
    );






__declspec(dllimport)
LSTATUS

RegEnumKeyExA (
     HKEY hKey,
     DWORD dwIndex,
     LPSTR lpName,
     LPDWORD lpcchName,
     LPDWORD lpReserved,
     LPSTR lpClass,
     LPDWORD lpcchClass,
     PFILETIME lpftLastWriteTime
    );
__declspec(dllimport)
LSTATUS

RegEnumKeyExW (
     HKEY hKey,
     DWORD dwIndex,
     LPWSTR lpName,
     LPDWORD lpcchName,
     LPDWORD lpReserved,
     LPWSTR lpClass,
     LPDWORD lpcchClass,
     PFILETIME lpftLastWriteTime
    );






__declspec(dllimport)
LSTATUS

RegEnumValueA (
     HKEY hKey,
     DWORD dwIndex,
     LPSTR lpValueName,
     LPDWORD lpcchValueName,
     LPDWORD lpReserved,
     LPDWORD lpType,
       LPBYTE lpData,
     LPDWORD lpcbData
    );
__declspec(dllimport)
LSTATUS

RegEnumValueW (
     HKEY hKey,
     DWORD dwIndex,
     LPWSTR lpValueName,
     LPDWORD lpcchValueName,
     LPDWORD lpReserved,
     LPDWORD lpType,
       LPBYTE lpData,
     LPDWORD lpcbData
    );






__declspec(dllimport)
LSTATUS

RegFlushKey (
     HKEY hKey
    );

__declspec(dllimport)
LSTATUS

RegGetKeySecurity (
     HKEY hKey,
     SECURITY_INFORMATION SecurityInformation,
     PSECURITY_DESCRIPTOR pSecurityDescriptor,
     LPDWORD lpcbSecurityDescriptor
    );

__declspec(dllimport)
LSTATUS

RegLoadKeyA (
     HKEY hKey,
     LPCSTR lpSubKey,
     LPCSTR lpFile
    );
__declspec(dllimport)
LSTATUS

RegLoadKeyW (
     HKEY hKey,
     LPCWSTR lpSubKey,
     LPCWSTR lpFile
    );






__declspec(dllimport)
LSTATUS

RegNotifyChangeKeyValue (
     HKEY hKey,
     BOOL bWatchSubtree,
     DWORD dwNotifyFilter,
     HANDLE hEvent,
     BOOL fAsynchronous
    );

__declspec(dllimport)
LSTATUS

RegOpenKeyA (
     HKEY hKey,
     LPCSTR lpSubKey,
     PHKEY phkResult
    );
__declspec(dllimport)
LSTATUS

RegOpenKeyW (
     HKEY hKey,
     LPCWSTR lpSubKey,
     PHKEY phkResult
    );






__declspec(dllimport)
LSTATUS

RegOpenKeyExA (
     HKEY hKey,
     LPCSTR lpSubKey,
     DWORD ulOptions,
     REGSAM samDesired,
     PHKEY phkResult
    );
__declspec(dllimport)
LSTATUS

RegOpenKeyExW (
     HKEY hKey,
     LPCWSTR lpSubKey,
     DWORD ulOptions,
     REGSAM samDesired,
     PHKEY phkResult
    );






__declspec(dllimport)
LSTATUS

RegOpenKeyTransactedA (
     HKEY hKey,
     LPCSTR lpSubKey,
     DWORD ulOptions,
     REGSAM samDesired,
     PHKEY phkResult,
     HANDLE hTransaction,
     PVOID pExtendedParemeter
    );
__declspec(dllimport)
LSTATUS

RegOpenKeyTransactedW (
     HKEY hKey,
     LPCWSTR lpSubKey,
     DWORD ulOptions,
     REGSAM samDesired,
     PHKEY phkResult,
     HANDLE hTransaction,
     PVOID pExtendedParemeter
    );






__declspec(dllimport)
LSTATUS

RegQueryInfoKeyA (
     HKEY hKey,
     LPSTR lpClass,
     LPDWORD lpcchClass,
     LPDWORD lpReserved,
     LPDWORD lpcSubKeys,
     LPDWORD lpcbMaxSubKeyLen,
     LPDWORD lpcbMaxClassLen,
     LPDWORD lpcValues,
     LPDWORD lpcbMaxValueNameLen,
     LPDWORD lpcbMaxValueLen,
     LPDWORD lpcbSecurityDescriptor,
     PFILETIME lpftLastWriteTime
    );
__declspec(dllimport)
LSTATUS

RegQueryInfoKeyW (
     HKEY hKey,
     LPWSTR lpClass,
     LPDWORD lpcchClass,
     LPDWORD lpReserved,
     LPDWORD lpcSubKeys,
     LPDWORD lpcbMaxSubKeyLen,
     LPDWORD lpcbMaxClassLen,
     LPDWORD lpcValues,
     LPDWORD lpcbMaxValueNameLen,
     LPDWORD lpcbMaxValueLen,
     LPDWORD lpcbSecurityDescriptor,
     PFILETIME lpftLastWriteTime
    );






__declspec(dllimport)
LSTATUS

RegQueryValueA (
     HKEY hKey,
     LPCSTR lpSubKey,
       LPSTR lpData,
     PLONG lpcbData
    );
__declspec(dllimport)
LSTATUS

RegQueryValueW (
     HKEY hKey,
     LPCWSTR lpSubKey,
       LPWSTR lpData,
     PLONG lpcbData
    );








__declspec(dllimport)
LSTATUS

RegQueryMultipleValuesA (
     HKEY hKey,
     PVALENTA val_list,
     DWORD num_vals,
       LPSTR lpValueBuf,
     LPDWORD ldwTotsize
    );
__declspec(dllimport)
LSTATUS

RegQueryMultipleValuesW (
     HKEY hKey,
     PVALENTW val_list,
     DWORD num_vals,
       LPWSTR lpValueBuf,
     LPDWORD ldwTotsize
    );







__declspec(dllimport)
LSTATUS

RegQueryValueExA (
     HKEY hKey,
     LPCSTR lpValueName,
     LPDWORD lpReserved,
     LPDWORD lpType,
       LPBYTE lpData,
     LPDWORD lpcbData
    );
__declspec(dllimport)
LSTATUS

RegQueryValueExW (
     HKEY hKey,
     LPCWSTR lpValueName,
     LPDWORD lpReserved,
     LPDWORD lpType,
       LPBYTE lpData,
     LPDWORD lpcbData
    );






__declspec(dllimport)
LSTATUS

RegReplaceKeyA (
     HKEY hKey,
     LPCSTR lpSubKey,
     LPCSTR lpNewFile,
     LPCSTR lpOldFile
    );
__declspec(dllimport)
LSTATUS

RegReplaceKeyW (
     HKEY hKey,
     LPCWSTR lpSubKey,
     LPCWSTR lpNewFile,
     LPCWSTR lpOldFile
    );






__declspec(dllimport)
LSTATUS

RegRestoreKeyA (
     HKEY hKey,
     LPCSTR lpFile,
     DWORD dwFlags
    );
__declspec(dllimport)
LSTATUS

RegRestoreKeyW (
     HKEY hKey,
     LPCWSTR lpFile,
     DWORD dwFlags
    );






__declspec(dllimport)
LSTATUS

RegSaveKeyA (
     HKEY hKey,
     LPCSTR lpFile,
      const  LPSECURITY_ATTRIBUTES lpSecurityAttributes
    );
__declspec(dllimport)
LSTATUS

RegSaveKeyW (
     HKEY hKey,
     LPCWSTR lpFile,
      const  LPSECURITY_ATTRIBUTES lpSecurityAttributes
    );






__declspec(dllimport)
LSTATUS

RegSetKeySecurity (
     HKEY hKey,
     SECURITY_INFORMATION SecurityInformation,
     PSECURITY_DESCRIPTOR pSecurityDescriptor
    );

__declspec(dllimport)
LSTATUS

RegSetValueA (
     HKEY hKey,
     LPCSTR lpSubKey,
     DWORD dwType,
     LPCSTR lpData,
     DWORD cbData
    );
__declspec(dllimport)
LSTATUS

RegSetValueW (
     HKEY hKey,
     LPCWSTR lpSubKey,
     DWORD dwType,
     LPCWSTR lpData,
     DWORD cbData
    );







__declspec(dllimport)
LSTATUS

RegSetValueExA (
     HKEY hKey,
     LPCSTR lpValueName,
     DWORD Reserved,
     DWORD dwType,
      const  BYTE* lpData,
     DWORD cbData
    );
__declspec(dllimport)
LSTATUS

RegSetValueExW (
     HKEY hKey,
     LPCWSTR lpValueName,
     DWORD Reserved,
     DWORD dwType,
      const  BYTE* lpData,
     DWORD cbData
    );






__declspec(dllimport)
LSTATUS

RegUnLoadKeyA (
     HKEY hKey,
     LPCSTR lpSubKey
    );
__declspec(dllimport)
LSTATUS

RegUnLoadKeyW (
     HKEY hKey,
     LPCWSTR lpSubKey
    );
__declspec(dllimport)
LSTATUS

RegDeleteKeyValueA (
     HKEY hKey,
     LPCSTR lpSubKey,
     LPCSTR lpValueName
    );
__declspec(dllimport)
LSTATUS

RegDeleteKeyValueW (
     HKEY hKey,
     LPCWSTR lpSubKey,
     LPCWSTR lpValueName
    );






__declspec(dllimport)
LSTATUS

RegSetKeyValueA (
     HKEY hKey,
     LPCSTR lpSubKey,
     LPCSTR lpValueName,
     DWORD dwType,
     LPCVOID lpData,
     DWORD cbData
    );
__declspec(dllimport)
LSTATUS

RegSetKeyValueW (
     HKEY hKey,
     LPCWSTR lpSubKey,
     LPCWSTR lpValueName,
     DWORD dwType,
     LPCVOID lpData,
     DWORD cbData
    );






__declspec(dllimport)
LSTATUS

RegDeleteTreeA (
     HKEY hKey,
     LPCSTR lpSubKey
    );
__declspec(dllimport)
LSTATUS

RegDeleteTreeW (
     HKEY hKey,
     LPCWSTR lpSubKey
    );






__declspec(dllimport)
LSTATUS

RegCopyTreeA (
     HKEY hKeySrc,
     LPCSTR lpSubKey,
     HKEY hKeyDest
    );
__declspec(dllimport)
LSTATUS

RegCopyTreeW (
     HKEY hKeySrc,
     LPCWSTR lpSubKey,
     HKEY hKeyDest
    );






__declspec(dllimport)
LSTATUS

RegGetValueA (
     HKEY hkey,
     LPCSTR lpSubKey,
     LPCSTR lpValue,
     DWORD dwFlags,
     LPDWORD pdwType,
     PVOID pvData,
     LPDWORD pcbData
    );
__declspec(dllimport)
LSTATUS

RegGetValueW (
     HKEY hkey,
     LPCWSTR lpSubKey,
     LPCWSTR lpValue,
     DWORD dwFlags,
     LPDWORD pdwType,
     PVOID pvData,
     LPDWORD pcbData
    );






__declspec(dllimport)
LSTATUS

RegLoadMUIStringA (
                     HKEY hKey,
                     LPCSTR pszValue,
                     LPSTR pszOutBuf,
                     DWORD cbOutBuf,
                     LPDWORD pcbData,
                     DWORD Flags,
                     LPCSTR pszDirectory
                    );
__declspec(dllimport)
LSTATUS

RegLoadMUIStringW (
                     HKEY hKey,
                     LPCWSTR pszValue,
                     LPWSTR pszOutBuf,
                     DWORD cbOutBuf,
                     LPDWORD pcbData,
                     DWORD Flags,
                     LPCWSTR pszDirectory
                    );







__declspec(dllimport)
LSTATUS

RegLoadAppKeyA (
         LPCSTR lpFile,
         PHKEY phkResult,
         REGSAM samDesired,
         DWORD dwOptions,
         DWORD Reserved
    );
__declspec(dllimport)
LSTATUS

RegLoadAppKeyW (
         LPCWSTR lpFile,
         PHKEY phkResult,
         REGSAM samDesired,
         DWORD dwOptions,
         DWORD Reserved
    );
__declspec(dllimport)
BOOL

InitiateSystemShutdownA(
     LPSTR lpMachineName,
     LPSTR lpMessage,
     DWORD dwTimeout,
     BOOL bForceAppsClosed,
     BOOL bRebootAfterShutdown
    );
__declspec(dllimport)
BOOL

InitiateSystemShutdownW(
     LPWSTR lpMachineName,
     LPWSTR lpMessage,
     DWORD dwTimeout,
     BOOL bForceAppsClosed,
     BOOL bRebootAfterShutdown
    );







__declspec(dllimport)
BOOL

AbortSystemShutdownA(
     LPSTR lpMachineName
    );
__declspec(dllimport)
BOOL

AbortSystemShutdownW(
     LPWSTR lpMachineName
    );
__declspec(dllimport)
BOOL

InitiateSystemShutdownExA(
     LPSTR lpMachineName,
     LPSTR lpMessage,
     DWORD dwTimeout,
     BOOL bForceAppsClosed,
     BOOL bRebootAfterShutdown,
     DWORD dwReason
    );
__declspec(dllimport)
BOOL

InitiateSystemShutdownExW(
     LPWSTR lpMachineName,
     LPWSTR lpMessage,
     DWORD dwTimeout,
     BOOL bForceAppsClosed,
     BOOL bRebootAfterShutdown,
     DWORD dwReason
    );
__declspec(dllimport)
DWORD

InitiateShutdownA(
     LPSTR lpMachineName,
     LPSTR lpMessage,
     DWORD dwGracePeriod,
     DWORD dwShutdownFlags,
     DWORD dwReason
    );
__declspec(dllimport)
DWORD

InitiateShutdownW(
     LPWSTR lpMachineName,
     LPWSTR lpMessage,
     DWORD dwGracePeriod,
     DWORD dwShutdownFlags,
     DWORD dwReason
    );






__declspec(dllimport)
LSTATUS

RegSaveKeyExA (
     HKEY hKey,
     LPCSTR lpFile,
      const  LPSECURITY_ATTRIBUTES lpSecurityAttributes,
     DWORD Flags
    );
__declspec(dllimport)
LSTATUS

RegSaveKeyExW (
     HKEY hKey,
     LPCWSTR lpFile,
      const  LPSECURITY_ATTRIBUTES lpSecurityAttributes,
     DWORD Flags
    );






__declspec(dllimport)
LONG

Wow64Win32ApiEntry (
     DWORD dwFuncNumber,
     DWORD dwFlag,
     DWORD dwRes
    );
typedef struct _NETRESOURCEA {
    DWORD dwScope;
    DWORD dwType;
    DWORD dwDisplayType;
    DWORD dwUsage;
    LPSTR lpLocalName;
    LPSTR lpRemoteName;
    LPSTR lpComment ;
    LPSTR lpProvider;
}NETRESOURCEA, *LPNETRESOURCEA;
typedef struct _NETRESOURCEW {
    DWORD dwScope;
    DWORD dwType;
    DWORD dwDisplayType;
    DWORD dwUsage;
    LPWSTR lpLocalName;
    LPWSTR lpRemoteName;
    LPWSTR lpComment ;
    LPWSTR lpProvider;
}NETRESOURCEW, *LPNETRESOURCEW;




typedef NETRESOURCEA NETRESOURCE;
typedef LPNETRESOURCEA LPNETRESOURCE;
DWORD
WNetAddConnectionA(
     LPCSTR lpRemoteName,
     LPCSTR lpPassword,
     LPCSTR lpLocalName
    );
DWORD
WNetAddConnectionW(
     LPCWSTR lpRemoteName,
     LPCWSTR lpPassword,
     LPCWSTR lpLocalName
    );






DWORD
WNetAddConnection2A(
     LPNETRESOURCEA lpNetResource,
     LPCSTR lpPassword,
     LPCSTR lpUserName,
     DWORD dwFlags
    );
DWORD
WNetAddConnection2W(
     LPNETRESOURCEW lpNetResource,
     LPCWSTR lpPassword,
     LPCWSTR lpUserName,
     DWORD dwFlags
    );






DWORD
WNetAddConnection3A(
     HWND hwndOwner,
     LPNETRESOURCEA lpNetResource,
     LPCSTR lpPassword,
     LPCSTR lpUserName,
     DWORD dwFlags
    );
DWORD
WNetAddConnection3W(
     HWND hwndOwner,
     LPNETRESOURCEW lpNetResource,
     LPCWSTR lpPassword,
     LPCWSTR lpUserName,
     DWORD dwFlags
    );






DWORD
WNetCancelConnectionA(
     LPCSTR lpName,
     BOOL fForce
    );
DWORD
WNetCancelConnectionW(
     LPCWSTR lpName,
     BOOL fForce
    );






DWORD
WNetCancelConnection2A(
     LPCSTR lpName,
     DWORD dwFlags,
     BOOL fForce
    );
DWORD
WNetCancelConnection2W(
     LPCWSTR lpName,
     DWORD dwFlags,
     BOOL fForce
    );






DWORD
WNetGetConnectionA(
     LPCSTR lpLocalName,
     LPSTR lpRemoteName,
     LPDWORD lpnLength
    );
DWORD
WNetGetConnectionW(
     LPCWSTR lpLocalName,
     LPWSTR lpRemoteName,
     LPDWORD lpnLength
    );









DWORD
WNetRestoreSingleConnectionW(
     HWND hwndParent,
     LPCWSTR lpDevice,
     BOOL fUseUI
    );
DWORD
WNetUseConnectionA(
     HWND hwndOwner,
     LPNETRESOURCEA lpNetResource,
     LPCSTR lpPassword,
     LPCSTR lpUserId,
     DWORD dwFlags,
     LPSTR lpAccessName,
     LPDWORD lpBufferSize,
     LPDWORD lpResult
    );
DWORD
WNetUseConnectionW(
     HWND hwndOwner,
     LPNETRESOURCEW lpNetResource,
     LPCWSTR lpPassword,
     LPCWSTR lpUserId,
     DWORD dwFlags,
     LPWSTR lpAccessName,
     LPDWORD lpBufferSize,
     LPDWORD lpResult
    );
DWORD
WNetConnectionDialog(
     HWND hwnd,
     DWORD dwType
    );

DWORD
WNetDisconnectDialog(
     HWND hwnd,
     DWORD dwType
    );


typedef struct _CONNECTDLGSTRUCTA{
    DWORD cbStructure;
    HWND hwndOwner;
    LPNETRESOURCEA lpConnRes;
    DWORD dwFlags;
    DWORD dwDevNum;
} CONNECTDLGSTRUCTA,   *LPCONNECTDLGSTRUCTA;
typedef struct _CONNECTDLGSTRUCTW{
    DWORD cbStructure;
    HWND hwndOwner;
    LPNETRESOURCEW lpConnRes;
    DWORD dwFlags;
    DWORD dwDevNum;
} CONNECTDLGSTRUCTW,   *LPCONNECTDLGSTRUCTW;




typedef CONNECTDLGSTRUCTA CONNECTDLGSTRUCT;
typedef LPCONNECTDLGSTRUCTA LPCONNECTDLGSTRUCT;
DWORD
WNetConnectionDialog1A(
     LPCONNECTDLGSTRUCTA lpConnDlgStruct
    );
DWORD
WNetConnectionDialog1W(
     LPCONNECTDLGSTRUCTW lpConnDlgStruct
    );






typedef struct _DISCDLGSTRUCTA{
    DWORD cbStructure;
    HWND hwndOwner;
    LPSTR lpLocalName;
    LPSTR lpRemoteName;
    DWORD dwFlags;
} DISCDLGSTRUCTA,   *LPDISCDLGSTRUCTA;
typedef struct _DISCDLGSTRUCTW{
    DWORD cbStructure;
    HWND hwndOwner;
    LPWSTR lpLocalName;
    LPWSTR lpRemoteName;
    DWORD dwFlags;
} DISCDLGSTRUCTW,   *LPDISCDLGSTRUCTW;




typedef DISCDLGSTRUCTA DISCDLGSTRUCT;
typedef LPDISCDLGSTRUCTA LPDISCDLGSTRUCT;





DWORD
WNetDisconnectDialog1A(
     LPDISCDLGSTRUCTA lpConnDlgStruct
    );
DWORD
WNetDisconnectDialog1W(
     LPDISCDLGSTRUCTW lpConnDlgStruct
    );
DWORD
WNetOpenEnumA(
     DWORD dwScope,
     DWORD dwType,
     DWORD dwUsage,
     LPNETRESOURCEA lpNetResource,
     LPHANDLE lphEnum
    );
DWORD
WNetOpenEnumW(
     DWORD dwScope,
     DWORD dwType,
     DWORD dwUsage,
     LPNETRESOURCEW lpNetResource,
     LPHANDLE lphEnum
    );






DWORD
WNetEnumResourceA(
     HANDLE hEnum,
     LPDWORD lpcCount,
     LPVOID lpBuffer,
     LPDWORD lpBufferSize
    );
DWORD
WNetEnumResourceW(
     HANDLE hEnum,
     LPDWORD lpcCount,
     LPVOID lpBuffer,
     LPDWORD lpBufferSize
    );






DWORD
WNetCloseEnum(
     HANDLE hEnum
    );


DWORD
WNetGetResourceParentA(
     LPNETRESOURCEA lpNetResource,
     LPVOID lpBuffer,
     LPDWORD lpcbBuffer
    );
DWORD
WNetGetResourceParentW(
     LPNETRESOURCEW lpNetResource,
     LPVOID lpBuffer,
     LPDWORD lpcbBuffer
    );






DWORD
WNetGetResourceInformationA(
     LPNETRESOURCEA lpNetResource,
     LPVOID lpBuffer,
     LPDWORD lpcbBuffer,
     LPSTR *lplpSystem
    );
DWORD
WNetGetResourceInformationW(
     LPNETRESOURCEW lpNetResource,
     LPVOID lpBuffer,
     LPDWORD lpcbBuffer,
     LPWSTR *lplpSystem
    );
typedef struct _UNIVERSAL_NAME_INFOA {
    LPSTR lpUniversalName;
}UNIVERSAL_NAME_INFOA, *LPUNIVERSAL_NAME_INFOA;
typedef struct _UNIVERSAL_NAME_INFOW {
    LPWSTR lpUniversalName;
}UNIVERSAL_NAME_INFOW, *LPUNIVERSAL_NAME_INFOW;




typedef UNIVERSAL_NAME_INFOA UNIVERSAL_NAME_INFO;
typedef LPUNIVERSAL_NAME_INFOA LPUNIVERSAL_NAME_INFO;


typedef struct _REMOTE_NAME_INFOA {
    LPSTR lpUniversalName;
    LPSTR lpConnectionName;
    LPSTR lpRemainingPath;
}REMOTE_NAME_INFOA, *LPREMOTE_NAME_INFOA;
typedef struct _REMOTE_NAME_INFOW {
    LPWSTR lpUniversalName;
    LPWSTR lpConnectionName;
    LPWSTR lpRemainingPath;
}REMOTE_NAME_INFOW, *LPREMOTE_NAME_INFOW;




typedef REMOTE_NAME_INFOA REMOTE_NAME_INFO;
typedef LPREMOTE_NAME_INFOA LPREMOTE_NAME_INFO;


DWORD
WNetGetUniversalNameA(
     LPCSTR lpLocalPath,
     DWORD dwInfoLevel,
     LPVOID lpBuffer,
     LPDWORD lpBufferSize
    );
DWORD
WNetGetUniversalNameW(
     LPCWSTR lpLocalPath,
     DWORD dwInfoLevel,
     LPVOID lpBuffer,
     LPDWORD lpBufferSize
    );










DWORD
WNetGetUserA(
     LPCSTR lpName,
     LPSTR lpUserName,
     LPDWORD lpnLength
    );
DWORD
WNetGetUserW(
     LPCWSTR lpName,
     LPWSTR lpUserName,
     LPDWORD lpnLength
    );
DWORD
WNetGetProviderNameA(
     DWORD dwNetType,
     LPSTR lpProviderName,
     LPDWORD lpBufferSize
    );
DWORD
WNetGetProviderNameW(
     DWORD dwNetType,
     LPWSTR lpProviderName,
     LPDWORD lpBufferSize
    );






typedef struct _NETINFOSTRUCT{
    DWORD cbStructure;
    DWORD dwProviderVersion;
    DWORD dwStatus;
    DWORD dwCharacteristics;
    ULONG_PTR dwHandle;
    WORD wNetType;
    DWORD dwPrinters;
    DWORD dwDrives;
} NETINFOSTRUCT,   *LPNETINFOSTRUCT;





DWORD
WNetGetNetworkInformationA(
     LPCSTR lpProvider,
     LPNETINFOSTRUCT lpNetInfoStruct
    );
DWORD
WNetGetNetworkInformationW(
     LPCWSTR lpProvider,
     LPNETINFOSTRUCT lpNetInfoStruct
    );
DWORD
WNetGetLastErrorA(
     LPDWORD lpError,
     LPSTR lpErrorBuf,
     DWORD nErrorBufSize,
     LPSTR lpNameBuf,
     DWORD nNameBufSize
    );
DWORD
WNetGetLastErrorW(
     LPDWORD lpError,
     LPWSTR lpErrorBuf,
     DWORD nErrorBufSize,
     LPWSTR lpNameBuf,
     DWORD nNameBufSize
    );
typedef struct _NETCONNECTINFOSTRUCT{
    DWORD cbStructure;
    DWORD dwFlags;
    DWORD dwSpeed;
    DWORD dwDelay;
    DWORD dwOptDataSize;
} NETCONNECTINFOSTRUCT, *LPNETCONNECTINFOSTRUCT;






DWORD
MultinetGetConnectionPerformanceA(
     LPNETRESOURCEA lpNetResource,
     LPNETCONNECTINFOSTRUCT lpNetConnectInfoStruct
    );
DWORD
MultinetGetConnectionPerformanceW(
     LPNETRESOURCEW lpNetResource,
     LPNETCONNECTINFOSTRUCT lpNetConnectInfoStruct
    );
typedef struct {

        unsigned short bAppReturnCode:8,
                 reserved:6,
                 fBusy:1,
		 fAck:1;
} DDEACK;
typedef struct {

        unsigned short reserved:14,
                 fDeferUpd:1,
		 fAckReq:1;
	short cfFormat;
} DDEADVISE;
typedef struct {

	unsigned short unused:12,
                 fResponse:1,
                 fRelease:1,
                 reserved:1,
                 fAckReq:1;
	short cfFormat;
	BYTE Value[1];
} DDEDATA;
typedef struct {

	unsigned short unused:13,

		 fRelease:1,
		 fReserved:2;
	short cfFormat;
	BYTE Value[1];


} DDEPOKE;
typedef struct {

        unsigned short unused:13,
                 fRelease:1,
                 fDeferUpd:1,
		 fAckReq:1;
	short cfFormat;
} DDELN;

typedef struct {

	unsigned short unused:12,
                 fAck:1,
                 fRelease:1,
                 fReserved:1,
                 fAckReq:1;
	short cfFormat;
	BYTE rgb[1];
} DDEUP;
BOOL

DdeSetQualityOfService(
    HWND hwndClient,
    const  SECURITY_QUALITY_OF_SERVICE *pqosNew,
    PSECURITY_QUALITY_OF_SERVICE pqosPrev);

BOOL

ImpersonateDdeClientWindow(
    HWND hWndClient,
    HWND hWndServer);
LPARAM   PackDDElParam(UINT msg, UINT_PTR uiLo, UINT_PTR uiHi);
BOOL   UnpackDDElParam(UINT msg, LPARAM lParam, PUINT_PTR puiLo, PUINT_PTR puiHi);
BOOL   FreeDDElParam(UINT msg, LPARAM lParam);
LPARAM   ReuseDDElParam(LPARAM lParam, UINT msgIn, UINT msgOut, UINT_PTR uiLo, UINT_PTR uiHi);
struct HCONVLIST__ {int unused;}; typedef struct HCONVLIST__ *HCONVLIST ;
struct HCONV__ {int unused;}; typedef struct HCONV__ *HCONV ;
struct HSZ__ {int unused;}; typedef struct HSZ__ *HSZ ;
struct HDDEDATA__ {int unused;}; typedef struct HDDEDATA__ *HDDEDATA ;




typedef struct tagHSZPAIR {
    HSZ hszSvc;
    HSZ hszTopic;
} HSZPAIR,   *PHSZPAIR;
typedef struct tagCONVCONTEXT {
    UINT cb;
    UINT wFlags;
    UINT wCountryID;
    int iCodePage;
    DWORD dwLangID;
    DWORD dwSecurity;
    SECURITY_QUALITY_OF_SERVICE qos;
} CONVCONTEXT,   *PCONVCONTEXT;




typedef struct tagCONVINFO {
    DWORD cb;
    DWORD_PTR hUser;
    HCONV hConvPartner;
    HSZ hszSvcPartner;
    HSZ hszServiceReq;
    HSZ hszTopic;
    HSZ hszItem;
    UINT wFmt;
    UINT wType;
    UINT wStatus;
    UINT wConvst;
    UINT wLastError;
    HCONVLIST hConvList;
    CONVCONTEXT ConvCtxt;
    HWND hwnd;
    HWND hwndPartner;
} CONVINFO,   *PCONVINFO;
typedef HDDEDATA   FNCALLBACK(UINT wType, UINT wFmt, HCONV hConv,
        HSZ hsz1, HSZ hsz2, HDDEDATA hData, ULONG_PTR dwData1, ULONG_PTR dwData2);
typedef HDDEDATA (  *PFNCALLBACK)(UINT wType, UINT wFmt, HCONV hConv,
        HSZ hsz1, HSZ hsz2, HDDEDATA hData, ULONG_PTR dwData1, ULONG_PTR dwData2);





UINT

DdeInitializeA(
     LPDWORD pidInst,
     PFNCALLBACK pfnCallback,
     DWORD afCmd,
     DWORD ulRes);
UINT

DdeInitializeW(
     LPDWORD pidInst,
     PFNCALLBACK pfnCallback,
     DWORD afCmd,
     DWORD ulRes);
BOOL

DdeUninitialize(
     DWORD idInst);
HCONVLIST

DdeConnectList(
     DWORD idInst,
     HSZ hszService,
     HSZ hszTopic,
     HCONVLIST hConvList,
     PCONVCONTEXT pCC);

HCONV

DdeQueryNextServer(
     HCONVLIST hConvList,
     HCONV hConvPrev);
BOOL

DdeDisconnectList(
     HCONVLIST hConvList);
HCONV

DdeConnect(
     DWORD idInst,
     HSZ hszService,
     HSZ hszTopic,
     PCONVCONTEXT pCC);

BOOL

DdeDisconnect(
     HCONV hConv);

HCONV

DdeReconnect(
     HCONV hConv);

UINT

DdeQueryConvInfo(
     HCONV hConv,
     DWORD idTransaction,
     PCONVINFO pConvInfo);

BOOL

DdeSetUserHandle(
     HCONV hConv,
     DWORD id,
     DWORD_PTR hUser);

BOOL

DdeAbandonTransaction(
     DWORD idInst,
     HCONV hConv,
     DWORD idTransaction);
BOOL

DdePostAdvise(
     DWORD idInst,
     HSZ hszTopic,
     HSZ hszItem);

BOOL

DdeEnableCallback(
     DWORD idInst,
     HCONV hConv,
     UINT wCmd);

BOOL

DdeImpersonateClient(
     HCONV hConv);







HDDEDATA

DdeNameService(
     DWORD idInst,
     HSZ hsz1,
     HSZ hsz2,
     UINT afCmd);
HDDEDATA

DdeClientTransaction(
     LPBYTE pData,
     DWORD cbData,
     HCONV hConv,
     HSZ hszItem,
     UINT wFmt,
     UINT wType,
     DWORD dwTimeout,
     LPDWORD pdwResult);
HDDEDATA

DdeCreateDataHandle(
     DWORD idInst,
     LPBYTE pSrc,
     DWORD cb,
     DWORD cbOff,
     HSZ hszItem,
     UINT wFmt,
     UINT afCmd);

HDDEDATA

DdeAddData(
     HDDEDATA hData,
     LPBYTE pSrc,
     DWORD cb,
     DWORD cbOff);

DWORD

DdeGetData(
     HDDEDATA hData,
     LPBYTE pDst,
     DWORD cbMax,
     DWORD cbOff);

LPBYTE

DdeAccessData(
     HDDEDATA hData,
     LPDWORD pcbDataSize);

BOOL

DdeUnaccessData(
     HDDEDATA hData);

BOOL

DdeFreeDataHandle(
     HDDEDATA hData);




UINT

DdeGetLastError(
     DWORD idInst);
HSZ

DdeCreateStringHandleA(
     DWORD idInst,
     LPCSTR psz,
     int iCodePage);
HSZ

DdeCreateStringHandleW(
     DWORD idInst,
     LPCWSTR psz,
     int iCodePage);






DWORD

DdeQueryStringA(
     DWORD idInst,
     HSZ hsz,
     LPSTR psz,
     DWORD cchMax,
     int iCodePage);
DWORD

DdeQueryStringW(
     DWORD idInst,
     HSZ hsz,
     LPWSTR psz,
     DWORD cchMax,
     int iCodePage);






BOOL

DdeFreeStringHandle(
     DWORD idInst,
     HSZ hsz);

BOOL

DdeKeepStringHandle(
     DWORD idInst,
     HSZ hsz);

int

DdeCmpStringHandles(
     HSZ hsz1,
     HSZ hsz2);
typedef struct tagDDEML_MSG_HOOK_DATA {
    UINT_PTR uiLo;
    UINT_PTR uiHi;
    DWORD cbData;
    DWORD Data[8];
} DDEML_MSG_HOOK_DATA, *PDDEML_MSG_HOOK_DATA;


typedef struct tagMONMSGSTRUCT {
    UINT cb;
    HWND hwndTo;
    DWORD dwTime;
    HANDLE hTask;
    UINT wMsg;
    WPARAM wParam;
    LPARAM lParam;
    DDEML_MSG_HOOK_DATA dmhd;
} MONMSGSTRUCT, *PMONMSGSTRUCT;

typedef struct tagMONCBSTRUCT {
    UINT cb;
    DWORD dwTime;
    HANDLE hTask;
    DWORD dwRet;
    UINT wType;
    UINT wFmt;
    HCONV hConv;
    HSZ hsz1;
    HSZ hsz2;
    HDDEDATA hData;
    ULONG_PTR dwData1;
    ULONG_PTR dwData2;
    CONVCONTEXT cc;
    DWORD cbData;
    DWORD Data[8];
} MONCBSTRUCT, *PMONCBSTRUCT;

typedef struct tagMONHSZSTRUCTA {
    UINT cb;
    BOOL fsAction;
    DWORD dwTime;
    HSZ hsz;
    HANDLE hTask;
    CHAR str[1];
} MONHSZSTRUCTA, *PMONHSZSTRUCTA;
typedef struct tagMONHSZSTRUCTW {
    UINT cb;
    BOOL fsAction;
    DWORD dwTime;
    HSZ hsz;
    HANDLE hTask;
    WCHAR str[1];
} MONHSZSTRUCTW, *PMONHSZSTRUCTW;




typedef MONHSZSTRUCTA MONHSZSTRUCT;
typedef PMONHSZSTRUCTA PMONHSZSTRUCT;







typedef struct tagMONERRSTRUCT {
    UINT cb;
    UINT wLastError;
    DWORD dwTime;
    HANDLE hTask;
} MONERRSTRUCT, *PMONERRSTRUCT;

typedef struct tagMONLINKSTRUCT {
    UINT cb;
    DWORD dwTime;
    HANDLE hTask;
    BOOL fEstablished;
    BOOL fNoData;
    HSZ hszSvc;
    HSZ hszTopic;
    HSZ hszItem;
    UINT wFmt;
    BOOL fServer;
    HCONV hConvServer;
    HCONV hConvClient;
} MONLINKSTRUCT, *PMONLINKSTRUCT;

typedef struct tagMONCONVSTRUCT {
    UINT cb;
    BOOL fConnect;
    DWORD dwTime;
    HANDLE hTask;
    HSZ hszSvc;
    HSZ hszTopic;
    HCONV hConvClient;
    HCONV hConvServer;
} MONCONVSTRUCT, *PMONCONVSTRUCT;
typedef struct tagCRGB
{
    BYTE bRed;
    BYTE bGreen;
    BYTE bBlue;
    BYTE bExtra;
} CRGB;
INT

LZStart(
	void
	);

void

LZDone(
	void
	);

LONG

CopyLZFile(
	INT,
	INT
	);

LONG

LZCopy(
	INT,
	INT
	);

INT

LZInit(
	INT
	);

INT

GetExpandedNameA(
	LPSTR,
	LPSTR
	);
INT

GetExpandedNameW(
	LPWSTR,
	LPWSTR
	);






INT

LZOpenFileA(
	LPSTR,
	LPOFSTRUCT,
	WORD
	);
INT

LZOpenFileW(
	LPWSTR,
	LPOFSTRUCT,
	WORD
	);






LONG

LZSeek(
	INT,
	LONG,
	INT
	);

INT

LZRead(
	INT,
	LPSTR,
	INT
	);

void

LZClose(
	INT
	);
typedef UINT MMVERSION;
typedef   UINT MMRESULT;



typedef UINT   *LPUINT;




typedef struct mmtime_tag
{
    UINT wType;
    union
    {
        DWORD ms;
        DWORD sample;
        DWORD cb;
        DWORD ticks;


        struct
        {
            BYTE hour;
            BYTE min;
            BYTE sec;
            BYTE frame;
            BYTE fps;
            BYTE dummy;

            BYTE pad[2];

        } smpte;


        struct
        {
            DWORD songptrpos;
        } midi;
    } u;
} MMTIME, *PMMTIME,   *NPMMTIME,   *LPMMTIME;
struct HDRVR__ {int unused;}; typedef struct HDRVR__ *HDRVR ;
typedef struct DRVCONFIGINFOEX {
    DWORD dwDCISize;
    LPCWSTR lpszDCISectionName;
    LPCWSTR lpszDCIAliasName;
    DWORD dnDevNode;
} DRVCONFIGINFOEX, *PDRVCONFIGINFOEX,   *NPDRVCONFIGINFOEX,   *LPDRVCONFIGINFOEX;
typedef struct tagDRVCONFIGINFO {
    DWORD dwDCISize;
    LPCWSTR lpszDCISectionName;
    LPCWSTR lpszDCIAliasName;
} DRVCONFIGINFO, *PDRVCONFIGINFO,   *NPDRVCONFIGINFO,   *LPDRVCONFIGINFO;
typedef LRESULT ( * DRIVERPROC)(DWORD_PTR, HDRVR, UINT, LPARAM, LPARAM);

__declspec(dllimport)  LRESULT   CloseDriver(      HDRVR hDriver,      LPARAM lParam1,      LPARAM lParam2);
__declspec(dllimport)  HDRVR   OpenDriver(      LPCWSTR szDriverName,      LPCWSTR szSectionName,      LPARAM lParam2);
__declspec(dllimport)  LRESULT   SendDriverMessage(      HDRVR hDriver,      UINT message,      LPARAM lParam1,      LPARAM lParam2);
__declspec(dllimport)  HMODULE   DrvGetModuleHandle(      HDRVR hDriver);
__declspec(dllimport)  HMODULE   GetDriverModuleHandle(      HDRVR hDriver);
__declspec(dllimport)  LRESULT   DefDriverProc(      DWORD_PTR dwDriverIdentifier,      HDRVR hdrvr,      UINT uMsg,      LPARAM lParam1,      LPARAM lParam2);
typedef void (  DRVCALLBACK)(HDRVR hdrvr, UINT uMsg, DWORD_PTR dwUser, DWORD_PTR dw1, DWORD_PTR dw2);

typedef DRVCALLBACK   *LPDRVCALLBACK;

typedef DRVCALLBACK *PDRVCALLBACK;
__declspec(dllimport)  BOOL   sndPlaySoundA(        LPCSTR pszSound,      UINT fuSound);
__declspec(dllimport)  BOOL   sndPlaySoundW(        LPCWSTR pszSound,      UINT fuSound);
__declspec(dllimport)  BOOL   PlaySoundA(        LPCSTR pszSound,        HMODULE hmod,      DWORD fdwSound);
__declspec(dllimport)  BOOL   PlaySoundW(        LPCWSTR pszSound,        HMODULE hmod,      DWORD fdwSound);
struct HWAVE__ {int unused;}; typedef struct HWAVE__ *HWAVE ;
struct HWAVEIN__ {int unused;}; typedef struct HWAVEIN__ *HWAVEIN ;
struct HWAVEOUT__ {int unused;}; typedef struct HWAVEOUT__ *HWAVEOUT ;
typedef HWAVEIN   *LPHWAVEIN;
typedef HWAVEOUT   *LPHWAVEOUT;
typedef DRVCALLBACK WAVECALLBACK;
typedef WAVECALLBACK   *LPWAVECALLBACK;
typedef struct wavehdr_tag {
    LPSTR lpData;
    DWORD dwBufferLength;
    DWORD dwBytesRecorded;
    DWORD_PTR dwUser;
    DWORD dwFlags;
    DWORD dwLoops;
    struct wavehdr_tag   *lpNext;
    DWORD_PTR reserved;
} WAVEHDR, *PWAVEHDR,   *NPWAVEHDR,   *LPWAVEHDR;
typedef struct tagWAVEOUTCAPSA {
    WORD wMid;
    WORD wPid;
    MMVERSION vDriverVersion;
    CHAR szPname[ 32 ];
    DWORD dwFormats;
    WORD wChannels;
    WORD wReserved1;
    DWORD dwSupport;
} WAVEOUTCAPSA, *PWAVEOUTCAPSA, *NPWAVEOUTCAPSA, *LPWAVEOUTCAPSA;
typedef struct tagWAVEOUTCAPSW {
    WORD wMid;
    WORD wPid;
    MMVERSION vDriverVersion;
    WCHAR szPname[ 32 ];
    DWORD dwFormats;
    WORD wChannels;
    WORD wReserved1;
    DWORD dwSupport;
} WAVEOUTCAPSW, *PWAVEOUTCAPSW, *NPWAVEOUTCAPSW, *LPWAVEOUTCAPSW;






typedef WAVEOUTCAPSA WAVEOUTCAPS;
typedef PWAVEOUTCAPSA PWAVEOUTCAPS;
typedef NPWAVEOUTCAPSA NPWAVEOUTCAPS;
typedef LPWAVEOUTCAPSA LPWAVEOUTCAPS;

typedef struct tagWAVEOUTCAPS2A {
    WORD wMid;
    WORD wPid;
    MMVERSION vDriverVersion;
    CHAR szPname[ 32 ];
    DWORD dwFormats;
    WORD wChannels;
    WORD wReserved1;
    DWORD dwSupport;
    GUID ManufacturerGuid;
    GUID ProductGuid;
    GUID NameGuid;
} WAVEOUTCAPS2A, *PWAVEOUTCAPS2A, *NPWAVEOUTCAPS2A, *LPWAVEOUTCAPS2A;
typedef struct tagWAVEOUTCAPS2W {
    WORD wMid;
    WORD wPid;
    MMVERSION vDriverVersion;
    WCHAR szPname[ 32 ];
    DWORD dwFormats;
    WORD wChannels;
    WORD wReserved1;
    DWORD dwSupport;
    GUID ManufacturerGuid;
    GUID ProductGuid;
    GUID NameGuid;
} WAVEOUTCAPS2W, *PWAVEOUTCAPS2W, *NPWAVEOUTCAPS2W, *LPWAVEOUTCAPS2W;






typedef WAVEOUTCAPS2A WAVEOUTCAPS2;
typedef PWAVEOUTCAPS2A PWAVEOUTCAPS2;
typedef NPWAVEOUTCAPS2A NPWAVEOUTCAPS2;
typedef LPWAVEOUTCAPS2A LPWAVEOUTCAPS2;
typedef struct tagWAVEINCAPSA {
    WORD wMid;
    WORD wPid;
    MMVERSION vDriverVersion;
    CHAR szPname[ 32 ];
    DWORD dwFormats;
    WORD wChannels;
    WORD wReserved1;
} WAVEINCAPSA, *PWAVEINCAPSA, *NPWAVEINCAPSA, *LPWAVEINCAPSA;
typedef struct tagWAVEINCAPSW {
    WORD wMid;
    WORD wPid;
    MMVERSION vDriverVersion;
    WCHAR szPname[ 32 ];
    DWORD dwFormats;
    WORD wChannels;
    WORD wReserved1;
} WAVEINCAPSW, *PWAVEINCAPSW, *NPWAVEINCAPSW, *LPWAVEINCAPSW;






typedef WAVEINCAPSA WAVEINCAPS;
typedef PWAVEINCAPSA PWAVEINCAPS;
typedef NPWAVEINCAPSA NPWAVEINCAPS;
typedef LPWAVEINCAPSA LPWAVEINCAPS;

typedef struct tagWAVEINCAPS2A {
    WORD wMid;
    WORD wPid;
    MMVERSION vDriverVersion;
    CHAR szPname[ 32 ];
    DWORD dwFormats;
    WORD wChannels;
    WORD wReserved1;
    GUID ManufacturerGuid;
    GUID ProductGuid;
    GUID NameGuid;
} WAVEINCAPS2A, *PWAVEINCAPS2A, *NPWAVEINCAPS2A, *LPWAVEINCAPS2A;
typedef struct tagWAVEINCAPS2W {
    WORD wMid;
    WORD wPid;
    MMVERSION vDriverVersion;
    WCHAR szPname[ 32 ];
    DWORD dwFormats;
    WORD wChannels;
    WORD wReserved1;
    GUID ManufacturerGuid;
    GUID ProductGuid;
    GUID NameGuid;
} WAVEINCAPS2W, *PWAVEINCAPS2W, *NPWAVEINCAPS2W, *LPWAVEINCAPS2W;






typedef WAVEINCAPS2A WAVEINCAPS2;
typedef PWAVEINCAPS2A PWAVEINCAPS2;
typedef NPWAVEINCAPS2A NPWAVEINCAPS2;
typedef LPWAVEINCAPS2A LPWAVEINCAPS2;
typedef struct waveformat_tag {
    WORD wFormatTag;
    WORD nChannels;
    DWORD nSamplesPerSec;
    DWORD nAvgBytesPerSec;
    WORD nBlockAlign;
} WAVEFORMAT, *PWAVEFORMAT,   *NPWAVEFORMAT,   *LPWAVEFORMAT;






typedef struct pcmwaveformat_tag {
    WAVEFORMAT wf;
    WORD wBitsPerSample;
} PCMWAVEFORMAT, *PPCMWAVEFORMAT,   *NPPCMWAVEFORMAT,   *LPPCMWAVEFORMAT;
typedef struct tWAVEFORMATEX
{
    WORD wFormatTag;
    WORD nChannels;
    DWORD nSamplesPerSec;
    DWORD nAvgBytesPerSec;
    WORD nBlockAlign;
    WORD wBitsPerSample;
    WORD cbSize;

} WAVEFORMATEX, *PWAVEFORMATEX,   *NPWAVEFORMATEX,   *LPWAVEFORMATEX;


typedef const WAVEFORMATEX   *LPCWAVEFORMATEX;


__declspec(dllimport)  UINT   waveOutGetNumDevs(void);



__declspec(dllimport)  MMRESULT   waveOutGetDevCapsA(      UINT_PTR uDeviceID,      LPWAVEOUTCAPSA pwoc,      UINT cbwoc);
__declspec(dllimport)  MMRESULT   waveOutGetDevCapsW(      UINT_PTR uDeviceID,      LPWAVEOUTCAPSW pwoc,      UINT cbwoc);
__declspec(dllimport)  MMRESULT   waveOutGetVolume(        HWAVEOUT hwo,      LPDWORD pdwVolume);
__declspec(dllimport)  MMRESULT   waveOutSetVolume(        HWAVEOUT hwo,      DWORD dwVolume);
__declspec(dllimport)  MMRESULT   waveOutGetErrorTextA(      MMRESULT mmrError,      LPSTR pszText,      UINT cchText);
__declspec(dllimport)  MMRESULT   waveOutGetErrorTextW(      MMRESULT mmrError,      LPWSTR pszText,      UINT cchText);
__declspec(dllimport)  MMRESULT   waveOutOpen(        LPHWAVEOUT phwo,      UINT uDeviceID,
     LPCWAVEFORMATEX pwfx,        DWORD_PTR dwCallback,        DWORD_PTR dwInstance,      DWORD fdwOpen);

__declspec(dllimport)  MMRESULT   waveOutClose(      HWAVEOUT hwo);
__declspec(dllimport)  MMRESULT   waveOutPrepareHeader(      HWAVEOUT hwo,        LPWAVEHDR pwh,      UINT cbwh);
__declspec(dllimport)  MMRESULT   waveOutUnprepareHeader(      HWAVEOUT hwo,        LPWAVEHDR pwh,      UINT cbwh);
__declspec(dllimport)  MMRESULT   waveOutWrite(      HWAVEOUT hwo,        LPWAVEHDR pwh,      UINT cbwh);
__declspec(dllimport)  MMRESULT   waveOutPause(      HWAVEOUT hwo);
__declspec(dllimport)  MMRESULT   waveOutRestart(      HWAVEOUT hwo);
__declspec(dllimport)  MMRESULT   waveOutReset(      HWAVEOUT hwo);
__declspec(dllimport)  MMRESULT   waveOutBreakLoop(      HWAVEOUT hwo);
__declspec(dllimport)  MMRESULT   waveOutGetPosition(      HWAVEOUT hwo,        LPMMTIME pmmt,      UINT cbmmt);
__declspec(dllimport)  MMRESULT   waveOutGetPitch(      HWAVEOUT hwo,      LPDWORD pdwPitch);
__declspec(dllimport)  MMRESULT   waveOutSetPitch(      HWAVEOUT hwo,      DWORD dwPitch);
__declspec(dllimport)  MMRESULT   waveOutGetPlaybackRate(      HWAVEOUT hwo,      LPDWORD pdwRate);
__declspec(dllimport)  MMRESULT   waveOutSetPlaybackRate(      HWAVEOUT hwo,      DWORD dwRate);
__declspec(dllimport)  MMRESULT   waveOutGetID(      HWAVEOUT hwo,      LPUINT puDeviceID);



__declspec(dllimport)  MMRESULT   waveOutMessage(        HWAVEOUT hwo,      UINT uMsg,      DWORD_PTR dw1,      DWORD_PTR dw2);
__declspec(dllimport)  UINT   waveInGetNumDevs(void);



__declspec(dllimport)  MMRESULT   waveInGetDevCapsA(      UINT_PTR uDeviceID,      LPWAVEINCAPSA pwic,      UINT cbwic);
__declspec(dllimport)  MMRESULT   waveInGetDevCapsW(      UINT_PTR uDeviceID,      LPWAVEINCAPSW pwic,      UINT cbwic);
__declspec(dllimport)  MMRESULT   waveInGetErrorTextA(     MMRESULT mmrError,      LPSTR pszText,      UINT cchText);
__declspec(dllimport)  MMRESULT   waveInGetErrorTextW(     MMRESULT mmrError,      LPWSTR pszText,      UINT cchText);
__declspec(dllimport)  MMRESULT   waveInOpen(        LPHWAVEIN phwi,      UINT uDeviceID,
     LPCWAVEFORMATEX pwfx,        DWORD_PTR dwCallback,        DWORD_PTR dwInstance,      DWORD fdwOpen);

__declspec(dllimport)  MMRESULT   waveInClose(      HWAVEIN hwi);
__declspec(dllimport)  MMRESULT   waveInPrepareHeader(      HWAVEIN hwi,        LPWAVEHDR pwh,      UINT cbwh);
__declspec(dllimport)  MMRESULT   waveInUnprepareHeader(      HWAVEIN hwi,        LPWAVEHDR pwh,      UINT cbwh);
__declspec(dllimport)  MMRESULT   waveInAddBuffer(      HWAVEIN hwi,        LPWAVEHDR pwh,      UINT cbwh);
__declspec(dllimport)  MMRESULT   waveInStart(      HWAVEIN hwi);
__declspec(dllimport)  MMRESULT   waveInStop(      HWAVEIN hwi);
__declspec(dllimport)  MMRESULT   waveInReset(      HWAVEIN hwi);
__declspec(dllimport)  MMRESULT   waveInGetPosition(      HWAVEIN hwi,        LPMMTIME pmmt,      UINT cbmmt);
__declspec(dllimport)  MMRESULT   waveInGetID(      HWAVEIN hwi,      LPUINT puDeviceID);



__declspec(dllimport)  MMRESULT   waveInMessage(        HWAVEIN hwi,      UINT uMsg,        DWORD_PTR dw1,        DWORD_PTR dw2);
struct HMIDI__ {int unused;}; typedef struct HMIDI__ *HMIDI ;
struct HMIDIIN__ {int unused;}; typedef struct HMIDIIN__ *HMIDIIN ;
struct HMIDIOUT__ {int unused;}; typedef struct HMIDIOUT__ *HMIDIOUT ;
struct HMIDISTRM__ {int unused;}; typedef struct HMIDISTRM__ *HMIDISTRM ;
typedef HMIDI   *LPHMIDI;
typedef HMIDIIN   *LPHMIDIIN;
typedef HMIDIOUT   *LPHMIDIOUT;
typedef HMIDISTRM   *LPHMIDISTRM;
typedef DRVCALLBACK MIDICALLBACK;
typedef MIDICALLBACK   *LPMIDICALLBACK;

typedef WORD PATCHARRAY[ 128 ];
typedef WORD   *LPPATCHARRAY;
typedef WORD KEYARRAY[ 128 ];
typedef WORD   *LPKEYARRAY;
typedef struct tagMIDIOUTCAPSA {
    WORD wMid;
    WORD wPid;
    MMVERSION vDriverVersion;
    CHAR szPname[ 32 ];
    WORD wTechnology;
    WORD wVoices;
    WORD wNotes;
    WORD wChannelMask;
    DWORD dwSupport;
} MIDIOUTCAPSA, *PMIDIOUTCAPSA, *NPMIDIOUTCAPSA, *LPMIDIOUTCAPSA;
typedef struct tagMIDIOUTCAPSW {
    WORD wMid;
    WORD wPid;
    MMVERSION vDriverVersion;
    WCHAR szPname[ 32 ];
    WORD wTechnology;
    WORD wVoices;
    WORD wNotes;
    WORD wChannelMask;
    DWORD dwSupport;
} MIDIOUTCAPSW, *PMIDIOUTCAPSW, *NPMIDIOUTCAPSW, *LPMIDIOUTCAPSW;






typedef MIDIOUTCAPSA MIDIOUTCAPS;
typedef PMIDIOUTCAPSA PMIDIOUTCAPS;
typedef NPMIDIOUTCAPSA NPMIDIOUTCAPS;
typedef LPMIDIOUTCAPSA LPMIDIOUTCAPS;

typedef struct tagMIDIOUTCAPS2A {
    WORD wMid;
    WORD wPid;
    MMVERSION vDriverVersion;
    CHAR szPname[ 32 ];
    WORD wTechnology;
    WORD wVoices;
    WORD wNotes;
    WORD wChannelMask;
    DWORD dwSupport;
    GUID ManufacturerGuid;
    GUID ProductGuid;
    GUID NameGuid;
} MIDIOUTCAPS2A, *PMIDIOUTCAPS2A, *NPMIDIOUTCAPS2A, *LPMIDIOUTCAPS2A;
typedef struct tagMIDIOUTCAPS2W {
    WORD wMid;
    WORD wPid;
    MMVERSION vDriverVersion;
    WCHAR szPname[ 32 ];
    WORD wTechnology;
    WORD wVoices;
    WORD wNotes;
    WORD wChannelMask;
    DWORD dwSupport;
    GUID ManufacturerGuid;
    GUID ProductGuid;
    GUID NameGuid;
} MIDIOUTCAPS2W, *PMIDIOUTCAPS2W, *NPMIDIOUTCAPS2W, *LPMIDIOUTCAPS2W;






typedef MIDIOUTCAPS2A MIDIOUTCAPS2;
typedef PMIDIOUTCAPS2A PMIDIOUTCAPS2;
typedef NPMIDIOUTCAPS2A NPMIDIOUTCAPS2;
typedef LPMIDIOUTCAPS2A LPMIDIOUTCAPS2;
typedef struct tagMIDIINCAPSA {
    WORD wMid;
    WORD wPid;
    MMVERSION vDriverVersion;
    CHAR szPname[ 32 ];

    DWORD dwSupport;

} MIDIINCAPSA, *PMIDIINCAPSA, *NPMIDIINCAPSA, *LPMIDIINCAPSA;
typedef struct tagMIDIINCAPSW {
    WORD wMid;
    WORD wPid;
    MMVERSION vDriverVersion;
    WCHAR szPname[ 32 ];

    DWORD dwSupport;

} MIDIINCAPSW, *PMIDIINCAPSW, *NPMIDIINCAPSW, *LPMIDIINCAPSW;






typedef MIDIINCAPSA MIDIINCAPS;
typedef PMIDIINCAPSA PMIDIINCAPS;
typedef NPMIDIINCAPSA NPMIDIINCAPS;
typedef LPMIDIINCAPSA LPMIDIINCAPS;

typedef struct tagMIDIINCAPS2A {
    WORD wMid;
    WORD wPid;
    MMVERSION vDriverVersion;
    CHAR szPname[ 32 ];

    DWORD dwSupport;

    GUID ManufacturerGuid;
    GUID ProductGuid;
    GUID NameGuid;
} MIDIINCAPS2A, *PMIDIINCAPS2A, *NPMIDIINCAPS2A, *LPMIDIINCAPS2A;
typedef struct tagMIDIINCAPS2W {
    WORD wMid;
    WORD wPid;
    MMVERSION vDriverVersion;
    WCHAR szPname[ 32 ];

    DWORD dwSupport;

    GUID ManufacturerGuid;
    GUID ProductGuid;
    GUID NameGuid;
} MIDIINCAPS2W, *PMIDIINCAPS2W, *NPMIDIINCAPS2W, *LPMIDIINCAPS2W;






typedef MIDIINCAPS2A MIDIINCAPS2;
typedef PMIDIINCAPS2A PMIDIINCAPS2;
typedef NPMIDIINCAPS2A NPMIDIINCAPS2;
typedef LPMIDIINCAPS2A LPMIDIINCAPS2;
typedef struct midihdr_tag {
    LPSTR lpData;
    DWORD dwBufferLength;
    DWORD dwBytesRecorded;
    DWORD_PTR dwUser;
    DWORD dwFlags;
    struct midihdr_tag   *lpNext;
    DWORD_PTR reserved;

    DWORD dwOffset;
    DWORD_PTR dwReserved[8];

} MIDIHDR, *PMIDIHDR,   *NPMIDIHDR,   *LPMIDIHDR;



typedef struct midievent_tag
{
    DWORD dwDeltaTime;
    DWORD dwStreamID;
    DWORD dwEvent;
    DWORD dwParms[1];
} MIDIEVENT;

typedef struct midistrmbuffver_tag
{
    DWORD dwVersion;
    DWORD dwMid;
    DWORD dwOEMVersion;
} MIDISTRMBUFFVER;
typedef struct midiproptimediv_tag
{
    DWORD cbStruct;
    DWORD dwTimeDiv;
} MIDIPROPTIMEDIV,   *LPMIDIPROPTIMEDIV;

typedef struct midiproptempo_tag
{
    DWORD cbStruct;
    DWORD dwTempo;
} MIDIPROPTEMPO,   *LPMIDIPROPTEMPO;




__declspec(dllimport)  UINT   midiOutGetNumDevs(void);

__declspec(dllimport)  MMRESULT   midiStreamOpen(      LPHMIDISTRM phms,        LPUINT puDeviceID,      DWORD cMidi,        DWORD_PTR dwCallback,        DWORD_PTR dwInstance,      DWORD fdwOpen);
__declspec(dllimport)  MMRESULT   midiStreamClose(      HMIDISTRM hms);

__declspec(dllimport)  MMRESULT   midiStreamProperty(      HMIDISTRM hms,        LPBYTE lppropdata,      DWORD dwProperty);
__declspec(dllimport)  MMRESULT   midiStreamPosition(      HMIDISTRM hms,      LPMMTIME lpmmt,      UINT cbmmt);

__declspec(dllimport)  MMRESULT   midiStreamOut(      HMIDISTRM hms,      LPMIDIHDR pmh,      UINT cbmh);
__declspec(dllimport)  MMRESULT   midiStreamPause(      HMIDISTRM hms);
__declspec(dllimport)  MMRESULT   midiStreamRestart(      HMIDISTRM hms);
__declspec(dllimport)  MMRESULT   midiStreamStop(      HMIDISTRM hms);


__declspec(dllimport)  MMRESULT   midiConnect(      HMIDI hmi,      HMIDIOUT hmo,        LPVOID pReserved);
__declspec(dllimport)  MMRESULT   midiDisconnect(      HMIDI hmi,      HMIDIOUT hmo,        LPVOID pReserved);





__declspec(dllimport)  MMRESULT   midiOutGetDevCapsA(      UINT_PTR uDeviceID,      LPMIDIOUTCAPSA pmoc,      UINT cbmoc);
__declspec(dllimport)  MMRESULT   midiOutGetDevCapsW(      UINT_PTR uDeviceID,      LPMIDIOUTCAPSW pmoc,      UINT cbmoc);
__declspec(dllimport)  MMRESULT   midiOutGetVolume(        HMIDIOUT hmo,      LPDWORD pdwVolume);
__declspec(dllimport)  MMRESULT   midiOutSetVolume(        HMIDIOUT hmo,      DWORD dwVolume);
__declspec(dllimport)  MMRESULT   midiOutGetErrorTextA(      MMRESULT mmrError,      LPSTR pszText,      UINT cchText);
__declspec(dllimport)  MMRESULT   midiOutGetErrorTextW(      MMRESULT mmrError,      LPWSTR pszText,      UINT cchText);
__declspec(dllimport)  MMRESULT   midiOutOpen(      LPHMIDIOUT phmo,      UINT uDeviceID,
     DWORD_PTR dwCallback,        DWORD_PTR dwInstance,      DWORD fdwOpen);
__declspec(dllimport)  MMRESULT   midiOutClose(      HMIDIOUT hmo);
__declspec(dllimport)  MMRESULT   midiOutPrepareHeader(      HMIDIOUT hmo,        LPMIDIHDR pmh,      UINT cbmh);
__declspec(dllimport)  MMRESULT   midiOutUnprepareHeader(     HMIDIOUT hmo,        LPMIDIHDR pmh,      UINT cbmh);
__declspec(dllimport)  MMRESULT   midiOutShortMsg(      HMIDIOUT hmo,      DWORD dwMsg);
__declspec(dllimport)  MMRESULT   midiOutLongMsg(     HMIDIOUT hmo,        LPMIDIHDR pmh,      UINT cbmh);
__declspec(dllimport)  MMRESULT   midiOutReset(      HMIDIOUT hmo);
__declspec(dllimport)  MMRESULT   midiOutCachePatches(      HMIDIOUT hmo,      UINT uBank,        LPWORD pwpa,      UINT fuCache);
__declspec(dllimport)  MMRESULT   midiOutCacheDrumPatches(      HMIDIOUT hmo,      UINT uPatch,        LPWORD pwkya,      UINT fuCache);
__declspec(dllimport)  MMRESULT   midiOutGetID(      HMIDIOUT hmo,      LPUINT puDeviceID);



__declspec(dllimport)  MMRESULT   midiOutMessage(        HMIDIOUT hmo,      UINT uMsg,        DWORD_PTR dw1,        DWORD_PTR dw2);
__declspec(dllimport)  UINT   midiInGetNumDevs(void);



__declspec(dllimport)  MMRESULT   midiInGetDevCapsA(      UINT_PTR uDeviceID,      LPMIDIINCAPSA pmic,      UINT cbmic);
__declspec(dllimport)  MMRESULT   midiInGetDevCapsW(      UINT_PTR uDeviceID,      LPMIDIINCAPSW pmic,      UINT cbmic);





__declspec(dllimport)  MMRESULT   midiInGetErrorTextA(      MMRESULT mmrError,      LPSTR pszText,      UINT cchText);
__declspec(dllimport)  MMRESULT   midiInGetErrorTextW(      MMRESULT mmrError,      LPWSTR pszText,      UINT cchText);
__declspec(dllimport)  MMRESULT   midiInOpen(      LPHMIDIIN phmi,      UINT uDeviceID,
         DWORD_PTR dwCallback,        DWORD_PTR dwInstance,      DWORD fdwOpen);
__declspec(dllimport)  MMRESULT   midiInClose(      HMIDIIN hmi);
__declspec(dllimport)  MMRESULT   midiInPrepareHeader(      HMIDIIN hmi,        LPMIDIHDR pmh,      UINT cbmh);
__declspec(dllimport)  MMRESULT   midiInUnprepareHeader(      HMIDIIN hmi,        LPMIDIHDR pmh,      UINT cbmh);
__declspec(dllimport)  MMRESULT   midiInAddBuffer(      HMIDIIN hmi,      LPMIDIHDR pmh,      UINT cbmh);
__declspec(dllimport)  MMRESULT   midiInStart(      HMIDIIN hmi);
__declspec(dllimport)  MMRESULT   midiInStop(      HMIDIIN hmi);
__declspec(dllimport)  MMRESULT   midiInReset(      HMIDIIN hmi);
__declspec(dllimport)  MMRESULT   midiInGetID(      HMIDIIN hmi,      LPUINT puDeviceID);



__declspec(dllimport)  MMRESULT   midiInMessage(        HMIDIIN hmi,      UINT uMsg,        DWORD_PTR dw1,        DWORD_PTR dw2);
typedef struct tagAUXCAPSA {
    WORD wMid;
    WORD wPid;
    MMVERSION vDriverVersion;
    CHAR szPname[ 32 ];
    WORD wTechnology;
    WORD wReserved1;
    DWORD dwSupport;
} AUXCAPSA, *PAUXCAPSA, *NPAUXCAPSA, *LPAUXCAPSA;
typedef struct tagAUXCAPSW {
    WORD wMid;
    WORD wPid;
    MMVERSION vDriverVersion;
    WCHAR szPname[ 32 ];
    WORD wTechnology;
    WORD wReserved1;
    DWORD dwSupport;
} AUXCAPSW, *PAUXCAPSW, *NPAUXCAPSW, *LPAUXCAPSW;






typedef AUXCAPSA AUXCAPS;
typedef PAUXCAPSA PAUXCAPS;
typedef NPAUXCAPSA NPAUXCAPS;
typedef LPAUXCAPSA LPAUXCAPS;

typedef struct tagAUXCAPS2A {
    WORD wMid;
    WORD wPid;
    MMVERSION vDriverVersion;
    CHAR szPname[ 32 ];
    WORD wTechnology;
    WORD wReserved1;
    DWORD dwSupport;
    GUID ManufacturerGuid;
    GUID ProductGuid;
    GUID NameGuid;
} AUXCAPS2A, *PAUXCAPS2A, *NPAUXCAPS2A, *LPAUXCAPS2A;
typedef struct tagAUXCAPS2W {
    WORD wMid;
    WORD wPid;
    MMVERSION vDriverVersion;
    WCHAR szPname[ 32 ];
    WORD wTechnology;
    WORD wReserved1;
    DWORD dwSupport;
    GUID ManufacturerGuid;
    GUID ProductGuid;
    GUID NameGuid;
} AUXCAPS2W, *PAUXCAPS2W, *NPAUXCAPS2W, *LPAUXCAPS2W;






typedef AUXCAPS2A AUXCAPS2;
typedef PAUXCAPS2A PAUXCAPS2;
typedef NPAUXCAPS2A NPAUXCAPS2;
typedef LPAUXCAPS2A LPAUXCAPS2;
__declspec(dllimport)  UINT   auxGetNumDevs(void);


__declspec(dllimport)  MMRESULT   auxGetDevCapsA(      UINT_PTR uDeviceID,      LPAUXCAPSA pac,      UINT cbac);
__declspec(dllimport)  MMRESULT   auxGetDevCapsW(      UINT_PTR uDeviceID,      LPAUXCAPSW pac,      UINT cbac);
__declspec(dllimport)  MMRESULT   auxSetVolume(      UINT uDeviceID,      DWORD dwVolume);
__declspec(dllimport)  MMRESULT   auxGetVolume(      UINT uDeviceID,      LPDWORD pdwVolume);



__declspec(dllimport)  MMRESULT   auxOutMessage(      UINT uDeviceID,      UINT uMsg,        DWORD_PTR dw1,        DWORD_PTR dw2);
struct HMIXEROBJ__ {int unused;}; typedef struct HMIXEROBJ__ *HMIXEROBJ ;
typedef HMIXEROBJ   *LPHMIXEROBJ;

struct HMIXER__ {int unused;}; typedef struct HMIXER__ *HMIXER ;
typedef HMIXER   *LPHMIXER;
__declspec(dllimport)  UINT   mixerGetNumDevs(void);



typedef struct tagMIXERCAPSA {
    WORD wMid;
    WORD wPid;
    MMVERSION vDriverVersion;
    CHAR szPname[ 32 ];
    DWORD fdwSupport;
    DWORD cDestinations;
} MIXERCAPSA, *PMIXERCAPSA, *LPMIXERCAPSA;
typedef struct tagMIXERCAPSW {
    WORD wMid;
    WORD wPid;
    MMVERSION vDriverVersion;
    WCHAR szPname[ 32 ];
    DWORD fdwSupport;
    DWORD cDestinations;
} MIXERCAPSW, *PMIXERCAPSW, *LPMIXERCAPSW;





typedef MIXERCAPSA MIXERCAPS;
typedef PMIXERCAPSA PMIXERCAPS;
typedef LPMIXERCAPSA LPMIXERCAPS;

typedef struct tagMIXERCAPS2A {
    WORD wMid;
    WORD wPid;
    MMVERSION vDriverVersion;
    CHAR szPname[ 32 ];
    DWORD fdwSupport;
    DWORD cDestinations;
    GUID ManufacturerGuid;
    GUID ProductGuid;
    GUID NameGuid;
} MIXERCAPS2A, *PMIXERCAPS2A, *LPMIXERCAPS2A;
typedef struct tagMIXERCAPS2W {
    WORD wMid;
    WORD wPid;
    MMVERSION vDriverVersion;
    WCHAR szPname[ 32 ];
    DWORD fdwSupport;
    DWORD cDestinations;
    GUID ManufacturerGuid;
    GUID ProductGuid;
    GUID NameGuid;
} MIXERCAPS2W, *PMIXERCAPS2W, *LPMIXERCAPS2W;





typedef MIXERCAPS2A MIXERCAPS2;
typedef PMIXERCAPS2A PMIXERCAPS2;
typedef LPMIXERCAPS2A LPMIXERCAPS2;
__declspec(dllimport)  MMRESULT   mixerGetDevCapsA(      UINT_PTR uMxId,      LPMIXERCAPSA pmxcaps,      UINT cbmxcaps);
__declspec(dllimport)  MMRESULT   mixerGetDevCapsW(      UINT_PTR uMxId,      LPMIXERCAPSW pmxcaps,      UINT cbmxcaps);
__declspec(dllimport)  MMRESULT   mixerOpen(        LPHMIXER phmx,      UINT uMxId,        DWORD_PTR dwCallback,        DWORD_PTR dwInstance,      DWORD fdwOpen);


__declspec(dllimport)  MMRESULT   mixerClose(      HMIXER hmx);

__declspec(dllimport)  DWORD   mixerMessage(        HMIXER hmx,      UINT uMsg,        DWORD_PTR dwParam1,        DWORD_PTR dwParam2);



typedef struct tagMIXERLINEA {
    DWORD cbStruct;
    DWORD dwDestination;
    DWORD dwSource;
    DWORD dwLineID;
    DWORD fdwLine;
    DWORD_PTR dwUser;
    DWORD dwComponentType;
    DWORD cChannels;
    DWORD cConnections;
    DWORD cControls;
    CHAR szShortName[ 16 ];
    CHAR szName[ 64 ];
    struct {
        DWORD dwType;
        DWORD dwDeviceID;
        WORD wMid;
        WORD wPid;
        MMVERSION vDriverVersion;
        CHAR szPname[ 32 ];
    } Target;
} MIXERLINEA, *PMIXERLINEA, *LPMIXERLINEA;
typedef struct tagMIXERLINEW {
    DWORD cbStruct;
    DWORD dwDestination;
    DWORD dwSource;
    DWORD dwLineID;
    DWORD fdwLine;
    DWORD_PTR dwUser;
    DWORD dwComponentType;
    DWORD cChannels;
    DWORD cConnections;
    DWORD cControls;
    WCHAR szShortName[ 16 ];
    WCHAR szName[ 64 ];
    struct {
        DWORD dwType;
        DWORD dwDeviceID;
        WORD wMid;
        WORD wPid;
        MMVERSION vDriverVersion;
        WCHAR szPname[ 32 ];
    } Target;
} MIXERLINEW, *PMIXERLINEW, *LPMIXERLINEW;





typedef MIXERLINEA MIXERLINE;
typedef PMIXERLINEA PMIXERLINE;
typedef LPMIXERLINEA LPMIXERLINE;
__declspec(dllimport)  MMRESULT   mixerGetLineInfoA(        HMIXEROBJ hmxobj,      LPMIXERLINEA pmxl,      DWORD fdwInfo);
__declspec(dllimport)  MMRESULT   mixerGetLineInfoW(        HMIXEROBJ hmxobj,      LPMIXERLINEW pmxl,      DWORD fdwInfo);
__declspec(dllimport)  MMRESULT   mixerGetID(        HMIXEROBJ hmxobj,      UINT   *puMxId,      DWORD fdwId);








typedef struct tagMIXERCONTROLA {
    DWORD cbStruct;
    DWORD dwControlID;
    DWORD dwControlType;
    DWORD fdwControl;
    DWORD cMultipleItems;
    CHAR szShortName[ 16 ];
    CHAR szName[ 64 ];
    union {
        struct {
            LONG lMinimum;
            LONG lMaximum;
        }  s ;
        struct {
            DWORD dwMinimum;
            DWORD dwMaximum;
        }  s2 ;
        DWORD dwReserved[6];
    } Bounds;
    union {
        DWORD cSteps;
        DWORD cbCustomData;
        DWORD dwReserved[6];
    } Metrics;
} MIXERCONTROLA, *PMIXERCONTROLA, *LPMIXERCONTROLA;
typedef struct tagMIXERCONTROLW {
    DWORD cbStruct;
    DWORD dwControlID;
    DWORD dwControlType;
    DWORD fdwControl;
    DWORD cMultipleItems;
    WCHAR szShortName[ 16 ];
    WCHAR szName[ 64 ];
    union {
        struct {
            LONG lMinimum;
            LONG lMaximum;
        }  s ;
        struct {
            DWORD dwMinimum;
            DWORD dwMaximum;
        }  s2 ;
        DWORD dwReserved[6];
    } Bounds;
    union {
        DWORD cSteps;
        DWORD cbCustomData;
        DWORD dwReserved[6];
    } Metrics;
} MIXERCONTROLW, *PMIXERCONTROLW, *LPMIXERCONTROLW;





typedef MIXERCONTROLA MIXERCONTROL;
typedef PMIXERCONTROLA PMIXERCONTROL;
typedef LPMIXERCONTROLA LPMIXERCONTROL;
typedef struct tagMIXERLINECONTROLSA {
    DWORD cbStruct;
    DWORD dwLineID;
    union {
        DWORD dwControlID;
        DWORD dwControlType;
    }  u ;
    DWORD cControls;
    DWORD cbmxctrl;
    LPMIXERCONTROLA pamxctrl;
} MIXERLINECONTROLSA, *PMIXERLINECONTROLSA, *LPMIXERLINECONTROLSA;
typedef struct tagMIXERLINECONTROLSW {
    DWORD cbStruct;
    DWORD dwLineID;
    union {
        DWORD dwControlID;
        DWORD dwControlType;
    }  u ;
    DWORD cControls;
    DWORD cbmxctrl;
    LPMIXERCONTROLW pamxctrl;
} MIXERLINECONTROLSW, *PMIXERLINECONTROLSW, *LPMIXERLINECONTROLSW;





typedef MIXERLINECONTROLSA MIXERLINECONTROLS;
typedef PMIXERLINECONTROLSA PMIXERLINECONTROLS;
typedef LPMIXERLINECONTROLSA LPMIXERLINECONTROLS;
__declspec(dllimport)  MMRESULT   mixerGetLineControlsA(        HMIXEROBJ hmxobj,      LPMIXERLINECONTROLSA pmxlc,      DWORD fdwControls);
__declspec(dllimport)  MMRESULT   mixerGetLineControlsW(        HMIXEROBJ hmxobj,      LPMIXERLINECONTROLSW pmxlc,      DWORD fdwControls);
typedef struct tMIXERCONTROLDETAILS {
    DWORD cbStruct;
    DWORD dwControlID;
    DWORD cChannels;
    union {
        HWND hwndOwner;
        DWORD cMultipleItems;
    }  u ;
    DWORD cbDetails;
    LPVOID paDetails;
} MIXERCONTROLDETAILS, *PMIXERCONTROLDETAILS,   *LPMIXERCONTROLDETAILS;








typedef struct tagMIXERCONTROLDETAILS_LISTTEXTA {
    DWORD dwParam1;
    DWORD dwParam2;
    CHAR szName[ 64 ];
} MIXERCONTROLDETAILS_LISTTEXTA, *PMIXERCONTROLDETAILS_LISTTEXTA, *LPMIXERCONTROLDETAILS_LISTTEXTA;
typedef struct tagMIXERCONTROLDETAILS_LISTTEXTW {
    DWORD dwParam1;
    DWORD dwParam2;
    WCHAR szName[ 64 ];
} MIXERCONTROLDETAILS_LISTTEXTW, *PMIXERCONTROLDETAILS_LISTTEXTW, *LPMIXERCONTROLDETAILS_LISTTEXTW;





typedef MIXERCONTROLDETAILS_LISTTEXTA MIXERCONTROLDETAILS_LISTTEXT;
typedef PMIXERCONTROLDETAILS_LISTTEXTA PMIXERCONTROLDETAILS_LISTTEXT;
typedef LPMIXERCONTROLDETAILS_LISTTEXTA LPMIXERCONTROLDETAILS_LISTTEXT;
typedef struct tMIXERCONTROLDETAILS_BOOLEAN {
    LONG fValue;
} MIXERCONTROLDETAILS_BOOLEAN,
      *PMIXERCONTROLDETAILS_BOOLEAN,
  *LPMIXERCONTROLDETAILS_BOOLEAN;

typedef struct tMIXERCONTROLDETAILS_SIGNED {
    LONG lValue;
} MIXERCONTROLDETAILS_SIGNED,
      *PMIXERCONTROLDETAILS_SIGNED,
  *LPMIXERCONTROLDETAILS_SIGNED;


typedef struct tMIXERCONTROLDETAILS_UNSIGNED {
    DWORD dwValue;
} MIXERCONTROLDETAILS_UNSIGNED,
      *PMIXERCONTROLDETAILS_UNSIGNED,
  *LPMIXERCONTROLDETAILS_UNSIGNED;




__declspec(dllimport)  MMRESULT   mixerGetControlDetailsA(        HMIXEROBJ hmxobj,      LPMIXERCONTROLDETAILS pmxcd,      DWORD fdwDetails);
__declspec(dllimport)  MMRESULT   mixerGetControlDetailsW(        HMIXEROBJ hmxobj,      LPMIXERCONTROLDETAILS pmxcd,      DWORD fdwDetails);
__declspec(dllimport)  MMRESULT   mixerSetControlDetails(        HMIXEROBJ hmxobj,      LPMIXERCONTROLDETAILS pmxcd,      DWORD fdwDetails);
typedef void (  TIMECALLBACK)(UINT uTimerID, UINT uMsg, DWORD_PTR dwUser, DWORD_PTR dw1, DWORD_PTR dw2);

typedef TIMECALLBACK   *LPTIMECALLBACK;
typedef struct timecaps_tag {
    UINT wPeriodMin;
    UINT wPeriodMax;
} TIMECAPS, *PTIMECAPS,   *NPTIMECAPS,   *LPTIMECAPS;


__declspec(dllimport)  MMRESULT   timeGetSystemTime(      LPMMTIME pmmt,      UINT cbmmt);
__declspec(dllimport)  DWORD   timeGetTime(void);
__declspec(dllimport)  MMRESULT   timeSetEvent(      UINT uDelay,      UINT uResolution,
     LPTIMECALLBACK fptc,      DWORD_PTR dwUser,      UINT fuEvent);
__declspec(dllimport)  MMRESULT   timeKillEvent(      UINT uTimerID);
__declspec(dllimport)  MMRESULT   timeGetDevCaps(      LPTIMECAPS ptc,      UINT cbtc);
__declspec(dllimport)  MMRESULT   timeBeginPeriod(      UINT uPeriod);
__declspec(dllimport)  MMRESULT   timeEndPeriod(      UINT uPeriod);
typedef struct tagJOYCAPSA {
    WORD wMid;
    WORD wPid;
    CHAR szPname[ 32 ];
    UINT wXmin;
    UINT wXmax;
    UINT wYmin;
    UINT wYmax;
    UINT wZmin;
    UINT wZmax;
    UINT wNumButtons;
    UINT wPeriodMin;
    UINT wPeriodMax;

    UINT wRmin;
    UINT wRmax;
    UINT wUmin;
    UINT wUmax;
    UINT wVmin;
    UINT wVmax;
    UINT wCaps;
    UINT wMaxAxes;
    UINT wNumAxes;
    UINT wMaxButtons;
    CHAR szRegKey[ 32 ];
    CHAR szOEMVxD[ 260 ];

} JOYCAPSA, *PJOYCAPSA, *NPJOYCAPSA, *LPJOYCAPSA;
typedef struct tagJOYCAPSW {
    WORD wMid;
    WORD wPid;
    WCHAR szPname[ 32 ];
    UINT wXmin;
    UINT wXmax;
    UINT wYmin;
    UINT wYmax;
    UINT wZmin;
    UINT wZmax;
    UINT wNumButtons;
    UINT wPeriodMin;
    UINT wPeriodMax;

    UINT wRmin;
    UINT wRmax;
    UINT wUmin;
    UINT wUmax;
    UINT wVmin;
    UINT wVmax;
    UINT wCaps;
    UINT wMaxAxes;
    UINT wNumAxes;
    UINT wMaxButtons;
    WCHAR szRegKey[ 32 ];
    WCHAR szOEMVxD[ 260 ];

} JOYCAPSW, *PJOYCAPSW, *NPJOYCAPSW, *LPJOYCAPSW;






typedef JOYCAPSA JOYCAPS;
typedef PJOYCAPSA PJOYCAPS;
typedef NPJOYCAPSA NPJOYCAPS;
typedef LPJOYCAPSA LPJOYCAPS;

typedef struct tagJOYCAPS2A {
    WORD wMid;
    WORD wPid;
    CHAR szPname[ 32 ];
    UINT wXmin;
    UINT wXmax;
    UINT wYmin;
    UINT wYmax;
    UINT wZmin;
    UINT wZmax;
    UINT wNumButtons;
    UINT wPeriodMin;
    UINT wPeriodMax;
    UINT wRmin;
    UINT wRmax;
    UINT wUmin;
    UINT wUmax;
    UINT wVmin;
    UINT wVmax;
    UINT wCaps;
    UINT wMaxAxes;
    UINT wNumAxes;
    UINT wMaxButtons;
    CHAR szRegKey[ 32 ];
    CHAR szOEMVxD[ 260 ];
    GUID ManufacturerGuid;
    GUID ProductGuid;
    GUID NameGuid;
} JOYCAPS2A, *PJOYCAPS2A, *NPJOYCAPS2A, *LPJOYCAPS2A;
typedef struct tagJOYCAPS2W {
    WORD wMid;
    WORD wPid;
    WCHAR szPname[ 32 ];
    UINT wXmin;
    UINT wXmax;
    UINT wYmin;
    UINT wYmax;
    UINT wZmin;
    UINT wZmax;
    UINT wNumButtons;
    UINT wPeriodMin;
    UINT wPeriodMax;
    UINT wRmin;
    UINT wRmax;
    UINT wUmin;
    UINT wUmax;
    UINT wVmin;
    UINT wVmax;
    UINT wCaps;
    UINT wMaxAxes;
    UINT wNumAxes;
    UINT wMaxButtons;
    WCHAR szRegKey[ 32 ];
    WCHAR szOEMVxD[ 260 ];
    GUID ManufacturerGuid;
    GUID ProductGuid;
    GUID NameGuid;
} JOYCAPS2W, *PJOYCAPS2W, *NPJOYCAPS2W, *LPJOYCAPS2W;






typedef JOYCAPS2A JOYCAPS2;
typedef PJOYCAPS2A PJOYCAPS2;
typedef NPJOYCAPS2A NPJOYCAPS2;
typedef LPJOYCAPS2A LPJOYCAPS2;
typedef struct joyinfo_tag {
    UINT wXpos;
    UINT wYpos;
    UINT wZpos;
    UINT wButtons;
} JOYINFO, *PJOYINFO,   *NPJOYINFO,   *LPJOYINFO;


typedef struct joyinfoex_tag {
    DWORD dwSize;
    DWORD dwFlags;
    DWORD dwXpos;
    DWORD dwYpos;
    DWORD dwZpos;
    DWORD dwRpos;
    DWORD dwUpos;
    DWORD dwVpos;
    DWORD dwButtons;
    DWORD dwButtonNumber;
    DWORD dwPOV;
    DWORD dwReserved1;
    DWORD dwReserved2;
} JOYINFOEX, *PJOYINFOEX,   *NPJOYINFOEX,   *LPJOYINFOEX;



__declspec(dllimport)  UINT   joyGetNumDevs(void);


__declspec(dllimport)  MMRESULT   joyGetDevCapsA(      UINT_PTR uJoyID,      LPJOYCAPSA pjc,      UINT cbjc);
__declspec(dllimport)  MMRESULT   joyGetDevCapsW(      UINT_PTR uJoyID,      LPJOYCAPSW pjc,      UINT cbjc);
__declspec(dllimport)  MMRESULT   joyGetPos(      UINT uJoyID,      LPJOYINFO pji);


__declspec(dllimport)  MMRESULT   joyGetPosEx(      UINT uJoyID,      LPJOYINFOEX pji);


__declspec(dllimport)  MMRESULT   joyGetThreshold(      UINT uJoyID,      LPUINT puThreshold);
__declspec(dllimport)  MMRESULT   joyReleaseCapture(      UINT uJoyID);
__declspec(dllimport)  MMRESULT   joySetCapture(      HWND hwnd,      UINT uJoyID,      UINT uPeriod,
     BOOL fChanged);
__declspec(dllimport)  MMRESULT   joySetThreshold(      UINT uJoyID,      UINT uThreshold);
typedef DWORD FOURCC;
typedef char   * HPSTR;
struct HMMIO__ {int unused;}; typedef struct HMMIO__ *HMMIO ;
typedef LRESULT (  MMIOPROC)(LPSTR lpmmioinfo, UINT uMsg,
            LPARAM lParam1, LPARAM lParam2);
typedef MMIOPROC   *LPMMIOPROC;



typedef struct _MMIOINFO
{

        DWORD dwFlags;
        FOURCC fccIOProc;
        LPMMIOPROC pIOProc;
        UINT wErrorRet;
        HTASK htask;


        LONG cchBuffer;
        HPSTR pchBuffer;
        HPSTR pchNext;
        HPSTR pchEndRead;
        HPSTR pchEndWrite;
        LONG lBufOffset;


        LONG lDiskOffset;
        DWORD adwInfo[3];


        DWORD dwReserved1;
        DWORD dwReserved2;
        HMMIO hmmio;
} MMIOINFO, *PMMIOINFO,   *NPMMIOINFO,   *LPMMIOINFO;
typedef const MMIOINFO   *LPCMMIOINFO;


typedef struct _MMCKINFO
{
        FOURCC ckid;
        DWORD cksize;
        FOURCC fccType;
        DWORD dwDataOffset;
        DWORD dwFlags;
} MMCKINFO, *PMMCKINFO,   *NPMMCKINFO,   *LPMMCKINFO;
typedef const MMCKINFO *LPCMMCKINFO;
__declspec(dllimport)  FOURCC   mmioStringToFOURCCA( LPCSTR sz,      UINT uFlags);
__declspec(dllimport)  FOURCC   mmioStringToFOURCCW( LPCWSTR sz,      UINT uFlags);





__declspec(dllimport)  LPMMIOPROC   mmioInstallIOProcA(      FOURCC fccIOProc,        LPMMIOPROC pIOProc,      DWORD dwFlags);
__declspec(dllimport)  LPMMIOPROC   mmioInstallIOProcW(      FOURCC fccIOProc,        LPMMIOPROC pIOProc,      DWORD dwFlags);





 __declspec(dllimport)  HMMIO   mmioOpenA(          LPSTR pszFileName,        LPMMIOINFO pmmioinfo,      DWORD fdwOpen);
 __declspec(dllimport)  HMMIO   mmioOpenW(          LPWSTR pszFileName,        LPMMIOINFO pmmioinfo,      DWORD fdwOpen);





__declspec(dllimport)  MMRESULT   mmioRenameA(      LPCSTR pszFileName,      LPCSTR pszNewFileName,        LPCMMIOINFO pmmioinfo,      DWORD fdwRename);
__declspec(dllimport)  MMRESULT   mmioRenameW(      LPCWSTR pszFileName,      LPCWSTR pszNewFileName,        LPCMMIOINFO pmmioinfo,      DWORD fdwRename);
__declspec(dllimport)  MMRESULT   mmioClose(      HMMIO hmmio,      UINT fuClose);
__declspec(dllimport)  LONG   mmioRead(      HMMIO hmmio,      HPSTR pch,      LONG cch);
__declspec(dllimport)  LONG   mmioWrite(      HMMIO hmmio,      const char  * pch,      LONG cch);
__declspec(dllimport)  LONG   mmioSeek(      HMMIO hmmio,      LONG lOffset,      int iOrigin);
__declspec(dllimport)  MMRESULT   mmioGetInfo(      HMMIO hmmio,      LPMMIOINFO pmmioinfo,      UINT fuInfo);
__declspec(dllimport)  MMRESULT   mmioSetInfo(      HMMIO hmmio,      LPCMMIOINFO pmmioinfo,      UINT fuInfo);
__declspec(dllimport)  MMRESULT   mmioSetBuffer(      HMMIO hmmio,        LPSTR pchBuffer,      LONG cchBuffer,
     UINT fuBuffer);
__declspec(dllimport)  MMRESULT   mmioFlush(      HMMIO hmmio,      UINT fuFlush);
__declspec(dllimport)  MMRESULT   mmioAdvance(      HMMIO hmmio,        LPMMIOINFO pmmioinfo,      UINT fuAdvance);
__declspec(dllimport)  LRESULT   mmioSendMessage(      HMMIO hmmio,      UINT uMsg,
     LPARAM lParam1,        LPARAM lParam2);
__declspec(dllimport)  MMRESULT   mmioDescend(      HMMIO hmmio,      LPMMCKINFO pmmcki,
     const MMCKINFO  * pmmckiParent,      UINT fuDescend);
__declspec(dllimport)  MMRESULT   mmioAscend(      HMMIO hmmio,      LPMMCKINFO pmmcki,      UINT fuAscend);
__declspec(dllimport)  MMRESULT   mmioCreateChunk(     HMMIO hmmio,      LPMMCKINFO pmmcki,      UINT fuCreate);
typedef DWORD MCIERROR;




typedef UINT MCIDEVICEID;



typedef UINT (  *YIELDPROC)(MCIDEVICEID mciId, DWORD dwYieldData);




__declspec(dllimport)  MCIERROR   mciSendCommandA(      MCIDEVICEID mciId,      UINT uMsg,        DWORD_PTR dwParam1,        DWORD_PTR dwParam2);
__declspec(dllimport)  MCIERROR   mciSendCommandW(      MCIDEVICEID mciId,      UINT uMsg,        DWORD_PTR dwParam1,        DWORD_PTR dwParam2);





__declspec(dllimport)  MCIERROR   mciSendStringA(      LPCSTR lpstrCommand,        LPSTR lpstrReturnString,      UINT uReturnLength,        HWND hwndCallback);
__declspec(dllimport)  MCIERROR   mciSendStringW(      LPCWSTR lpstrCommand,        LPWSTR lpstrReturnString,      UINT uReturnLength,        HWND hwndCallback);





__declspec(dllimport)  MCIDEVICEID   mciGetDeviceIDA(      LPCSTR pszDevice);
__declspec(dllimport)  MCIDEVICEID   mciGetDeviceIDW(      LPCWSTR pszDevice);





__declspec(dllimport)  MCIDEVICEID   mciGetDeviceIDFromElementIDA(      DWORD dwElementID,      LPCSTR lpstrType );
__declspec(dllimport)  MCIDEVICEID   mciGetDeviceIDFromElementIDW(      DWORD dwElementID,      LPCWSTR lpstrType );





__declspec(dllimport)  BOOL   mciGetErrorStringA(      MCIERROR mcierr,      LPSTR pszText,      UINT cchText);
__declspec(dllimport)  BOOL   mciGetErrorStringW(      MCIERROR mcierr,      LPWSTR pszText,      UINT cchText);
__declspec(dllimport)  BOOL   mciSetYieldProc(      MCIDEVICEID mciId,        YIELDPROC fpYieldProc,
     DWORD dwYieldData);


__declspec(dllimport)  HTASK   mciGetCreatorTask(      MCIDEVICEID mciId);
__declspec(dllimport)  YIELDPROC   mciGetYieldProc(      MCIDEVICEID mciId,      LPDWORD pdwYieldData);
typedef struct tagMCI_GENERIC_PARMS {
    DWORD_PTR dwCallback;
} MCI_GENERIC_PARMS, *PMCI_GENERIC_PARMS,   *LPMCI_GENERIC_PARMS;





typedef struct tagMCI_OPEN_PARMSA {
    DWORD_PTR dwCallback;
    MCIDEVICEID wDeviceID;
    LPCSTR lpstrDeviceType;
    LPCSTR lpstrElementName;
    LPCSTR lpstrAlias;
} MCI_OPEN_PARMSA, *PMCI_OPEN_PARMSA, *LPMCI_OPEN_PARMSA;
typedef struct tagMCI_OPEN_PARMSW {
    DWORD_PTR dwCallback;
    MCIDEVICEID wDeviceID;
    LPCWSTR lpstrDeviceType;
    LPCWSTR lpstrElementName;
    LPCWSTR lpstrAlias;
} MCI_OPEN_PARMSW, *PMCI_OPEN_PARMSW, *LPMCI_OPEN_PARMSW;





typedef MCI_OPEN_PARMSA MCI_OPEN_PARMS;
typedef PMCI_OPEN_PARMSA PMCI_OPEN_PARMS;
typedef LPMCI_OPEN_PARMSA LPMCI_OPEN_PARMS;
typedef struct tagMCI_PLAY_PARMS {
    DWORD_PTR dwCallback;
    DWORD dwFrom;
    DWORD dwTo;
} MCI_PLAY_PARMS, *PMCI_PLAY_PARMS,   *LPMCI_PLAY_PARMS;



typedef struct tagMCI_SEEK_PARMS {
    DWORD_PTR dwCallback;
    DWORD dwTo;
} MCI_SEEK_PARMS, *PMCI_SEEK_PARMS,   *LPMCI_SEEK_PARMS;



typedef struct tagMCI_STATUS_PARMS {
    DWORD_PTR dwCallback;
    DWORD_PTR dwReturn;
    DWORD dwItem;
    DWORD dwTrack;
} MCI_STATUS_PARMS, *PMCI_STATUS_PARMS,   * LPMCI_STATUS_PARMS;





typedef struct tagMCI_INFO_PARMSA {
    DWORD_PTR dwCallback;
    LPSTR lpstrReturn;
    DWORD dwRetSize;
} MCI_INFO_PARMSA, * LPMCI_INFO_PARMSA;
typedef struct tagMCI_INFO_PARMSW {
    DWORD_PTR dwCallback;
    LPWSTR lpstrReturn;
    DWORD dwRetSize;
} MCI_INFO_PARMSW, * LPMCI_INFO_PARMSW;




typedef MCI_INFO_PARMSA MCI_INFO_PARMS;
typedef LPMCI_INFO_PARMSA LPMCI_INFO_PARMS;
typedef struct tagMCI_GETDEVCAPS_PARMS {
    DWORD_PTR dwCallback;
    DWORD dwReturn;
    DWORD dwItem;
} MCI_GETDEVCAPS_PARMS, *PMCI_GETDEVCAPS_PARMS,   * LPMCI_GETDEVCAPS_PARMS;





typedef struct tagMCI_SYSINFO_PARMSA {
    DWORD_PTR dwCallback;
    LPSTR lpstrReturn;
    DWORD dwRetSize;
    DWORD dwNumber;
    UINT wDeviceType;
} MCI_SYSINFO_PARMSA, *PMCI_SYSINFO_PARMSA, * LPMCI_SYSINFO_PARMSA;
typedef struct tagMCI_SYSINFO_PARMSW {
    DWORD_PTR dwCallback;
    LPWSTR lpstrReturn;
    DWORD dwRetSize;
    DWORD dwNumber;
    UINT wDeviceType;
} MCI_SYSINFO_PARMSW, *PMCI_SYSINFO_PARMSW, * LPMCI_SYSINFO_PARMSW;





typedef MCI_SYSINFO_PARMSA MCI_SYSINFO_PARMS;
typedef PMCI_SYSINFO_PARMSA PMCI_SYSINFO_PARMS;
typedef LPMCI_SYSINFO_PARMSA LPMCI_SYSINFO_PARMS;
typedef struct tagMCI_SET_PARMS {
    DWORD_PTR dwCallback;
    DWORD dwTimeFormat;
    DWORD dwAudio;
} MCI_SET_PARMS, *PMCI_SET_PARMS,   *LPMCI_SET_PARMS;



typedef struct tagMCI_BREAK_PARMS {
    DWORD_PTR dwCallback;

    int nVirtKey;
    HWND hwndBreak;
} MCI_BREAK_PARMS, *PMCI_BREAK_PARMS,   * LPMCI_BREAK_PARMS;





typedef struct tagMCI_SAVE_PARMSA {
    DWORD_PTR dwCallback;
    LPCSTR lpfilename;
} MCI_SAVE_PARMSA, *PMCI_SAVE_PARMSA, * LPMCI_SAVE_PARMSA;
typedef struct tagMCI_SAVE_PARMSW {
    DWORD_PTR dwCallback;
    LPCWSTR lpfilename;
} MCI_SAVE_PARMSW, *PMCI_SAVE_PARMSW, * LPMCI_SAVE_PARMSW;





typedef MCI_SAVE_PARMSA MCI_SAVE_PARMS;
typedef PMCI_SAVE_PARMSA PMCI_SAVE_PARMS;
typedef LPMCI_SAVE_PARMSA LPMCI_SAVE_PARMS;
typedef struct tagMCI_LOAD_PARMSA {
    DWORD_PTR dwCallback;
    LPCSTR lpfilename;
} MCI_LOAD_PARMSA, *PMCI_LOAD_PARMSA, * LPMCI_LOAD_PARMSA;
typedef struct tagMCI_LOAD_PARMSW {
    DWORD_PTR dwCallback;
    LPCWSTR lpfilename;
} MCI_LOAD_PARMSW, *PMCI_LOAD_PARMSW, * LPMCI_LOAD_PARMSW;





typedef MCI_LOAD_PARMSA MCI_LOAD_PARMS;
typedef PMCI_LOAD_PARMSA PMCI_LOAD_PARMS;
typedef LPMCI_LOAD_PARMSA LPMCI_LOAD_PARMS;
typedef struct tagMCI_RECORD_PARMS {
    DWORD_PTR dwCallback;
    DWORD dwFrom;
    DWORD dwTo;
} MCI_RECORD_PARMS,   *LPMCI_RECORD_PARMS;
typedef struct tagMCI_VD_PLAY_PARMS {
    DWORD_PTR dwCallback;
    DWORD dwFrom;
    DWORD dwTo;
    DWORD dwSpeed;
} MCI_VD_PLAY_PARMS, *PMCI_VD_PLAY_PARMS,   *LPMCI_VD_PLAY_PARMS;



typedef struct tagMCI_VD_STEP_PARMS {
    DWORD_PTR dwCallback;
    DWORD dwFrames;
} MCI_VD_STEP_PARMS, *PMCI_VD_STEP_PARMS,   *LPMCI_VD_STEP_PARMS;





typedef struct tagMCI_VD_ESCAPE_PARMSA {
    DWORD_PTR dwCallback;
    LPCSTR lpstrCommand;
} MCI_VD_ESCAPE_PARMSA, *PMCI_VD_ESCAPE_PARMSA, *LPMCI_VD_ESCAPE_PARMSA;
typedef struct tagMCI_VD_ESCAPE_PARMSW {
    DWORD_PTR dwCallback;
    LPCWSTR lpstrCommand;
} MCI_VD_ESCAPE_PARMSW, *PMCI_VD_ESCAPE_PARMSW, *LPMCI_VD_ESCAPE_PARMSW;





typedef MCI_VD_ESCAPE_PARMSA MCI_VD_ESCAPE_PARMS;
typedef PMCI_VD_ESCAPE_PARMSA PMCI_VD_ESCAPE_PARMS;
typedef LPMCI_VD_ESCAPE_PARMSA LPMCI_VD_ESCAPE_PARMS;
typedef struct tagMCI_WAVE_OPEN_PARMSA {
    DWORD_PTR dwCallback;
    MCIDEVICEID wDeviceID;
    LPCSTR lpstrDeviceType;
    LPCSTR lpstrElementName;
    LPCSTR lpstrAlias;
    DWORD dwBufferSeconds;
} MCI_WAVE_OPEN_PARMSA, *PMCI_WAVE_OPEN_PARMSA, *LPMCI_WAVE_OPEN_PARMSA;
typedef struct tagMCI_WAVE_OPEN_PARMSW {
    DWORD_PTR dwCallback;
    MCIDEVICEID wDeviceID;
    LPCWSTR lpstrDeviceType;
    LPCWSTR lpstrElementName;
    LPCWSTR lpstrAlias;
    DWORD dwBufferSeconds;
} MCI_WAVE_OPEN_PARMSW, *PMCI_WAVE_OPEN_PARMSW, *LPMCI_WAVE_OPEN_PARMSW;





typedef MCI_WAVE_OPEN_PARMSA MCI_WAVE_OPEN_PARMS;
typedef PMCI_WAVE_OPEN_PARMSA PMCI_WAVE_OPEN_PARMS;
typedef LPMCI_WAVE_OPEN_PARMSA LPMCI_WAVE_OPEN_PARMS;
typedef struct tagMCI_WAVE_DELETE_PARMS {
    DWORD_PTR dwCallback;
    DWORD dwFrom;
    DWORD dwTo;
} MCI_WAVE_DELETE_PARMS, *PMCI_WAVE_DELETE_PARMS,   *LPMCI_WAVE_DELETE_PARMS;



typedef struct tagMCI_WAVE_SET_PARMS {
    DWORD_PTR dwCallback;
    DWORD dwTimeFormat;
    DWORD dwAudio;

    UINT wInput;
    UINT wOutput;
    WORD wFormatTag;
    WORD wReserved2;
    WORD nChannels;
    WORD wReserved3;
    DWORD nSamplesPerSec;
    DWORD nAvgBytesPerSec;
    WORD nBlockAlign;
    WORD wReserved4;
    WORD wBitsPerSample;
    WORD wReserved5;
} MCI_WAVE_SET_PARMS, *PMCI_WAVE_SET_PARMS,   * LPMCI_WAVE_SET_PARMS;
typedef struct tagMCI_SEQ_SET_PARMS {
    DWORD_PTR dwCallback;
    DWORD dwTimeFormat;
    DWORD dwAudio;
    DWORD dwTempo;
    DWORD dwPort;
    DWORD dwSlave;
    DWORD dwMaster;
    DWORD dwOffset;
} MCI_SEQ_SET_PARMS, *PMCI_SEQ_SET_PARMS,   * LPMCI_SEQ_SET_PARMS;
typedef struct tagMCI_ANIM_OPEN_PARMSA {
    DWORD_PTR dwCallback;
    MCIDEVICEID wDeviceID;
    LPCSTR lpstrDeviceType;
    LPCSTR lpstrElementName;
    LPCSTR lpstrAlias;
    DWORD dwStyle;
    HWND hWndParent;
} MCI_ANIM_OPEN_PARMSA, *PMCI_ANIM_OPEN_PARMSA, *LPMCI_ANIM_OPEN_PARMSA;
typedef struct tagMCI_ANIM_OPEN_PARMSW {
    DWORD_PTR dwCallback;
    MCIDEVICEID wDeviceID;
    LPCWSTR lpstrDeviceType;
    LPCWSTR lpstrElementName;
    LPCWSTR lpstrAlias;
    DWORD dwStyle;
    HWND hWndParent;
} MCI_ANIM_OPEN_PARMSW, *PMCI_ANIM_OPEN_PARMSW, *LPMCI_ANIM_OPEN_PARMSW;





typedef MCI_ANIM_OPEN_PARMSA MCI_ANIM_OPEN_PARMS;
typedef PMCI_ANIM_OPEN_PARMSA PMCI_ANIM_OPEN_PARMS;
typedef LPMCI_ANIM_OPEN_PARMSA LPMCI_ANIM_OPEN_PARMS;
typedef struct tagMCI_ANIM_PLAY_PARMS {
    DWORD_PTR dwCallback;
    DWORD dwFrom;
    DWORD dwTo;
    DWORD dwSpeed;
} MCI_ANIM_PLAY_PARMS, *PMCI_ANIM_PLAY_PARMS,   *LPMCI_ANIM_PLAY_PARMS;



typedef struct tagMCI_ANIM_STEP_PARMS {
    DWORD_PTR dwCallback;
    DWORD dwFrames;
} MCI_ANIM_STEP_PARMS, *PMCI_ANIM_STEP_PARMS,   *LPMCI_ANIM_STEP_PARMS;





typedef struct tagMCI_ANIM_WINDOW_PARMSA {
    DWORD_PTR dwCallback;
    HWND hWnd;
    UINT nCmdShow;
    LPCSTR lpstrText;
} MCI_ANIM_WINDOW_PARMSA, *PMCI_ANIM_WINDOW_PARMSA, * LPMCI_ANIM_WINDOW_PARMSA;
typedef struct tagMCI_ANIM_WINDOW_PARMSW {
    DWORD_PTR dwCallback;
    HWND hWnd;
    UINT nCmdShow;
    LPCWSTR lpstrText;
} MCI_ANIM_WINDOW_PARMSW, *PMCI_ANIM_WINDOW_PARMSW, * LPMCI_ANIM_WINDOW_PARMSW;





typedef MCI_ANIM_WINDOW_PARMSA MCI_ANIM_WINDOW_PARMS;
typedef PMCI_ANIM_WINDOW_PARMSA PMCI_ANIM_WINDOW_PARMS;
typedef LPMCI_ANIM_WINDOW_PARMSA LPMCI_ANIM_WINDOW_PARMS;
typedef struct tagMCI_ANIM_RECT_PARMS {
    DWORD_PTR dwCallback;




    RECT rc;

} MCI_ANIM_RECT_PARMS;
typedef MCI_ANIM_RECT_PARMS * PMCI_ANIM_RECT_PARMS;
typedef MCI_ANIM_RECT_PARMS   * LPMCI_ANIM_RECT_PARMS;



typedef struct tagMCI_ANIM_UPDATE_PARMS {
    DWORD_PTR dwCallback;
    RECT rc;
    HDC hDC;
} MCI_ANIM_UPDATE_PARMS, *PMCI_ANIM_UPDATE_PARMS,   * LPMCI_ANIM_UPDATE_PARMS;
typedef struct tagMCI_OVLY_OPEN_PARMSA {
    DWORD_PTR dwCallback;
    MCIDEVICEID wDeviceID;
    LPCSTR lpstrDeviceType;
    LPCSTR lpstrElementName;
    LPCSTR lpstrAlias;
    DWORD dwStyle;
    HWND hWndParent;
} MCI_OVLY_OPEN_PARMSA, *PMCI_OVLY_OPEN_PARMSA, *LPMCI_OVLY_OPEN_PARMSA;
typedef struct tagMCI_OVLY_OPEN_PARMSW {
    DWORD_PTR dwCallback;
    MCIDEVICEID wDeviceID;
    LPCWSTR lpstrDeviceType;
    LPCWSTR lpstrElementName;
    LPCWSTR lpstrAlias;
    DWORD dwStyle;
    HWND hWndParent;
} MCI_OVLY_OPEN_PARMSW, *PMCI_OVLY_OPEN_PARMSW, *LPMCI_OVLY_OPEN_PARMSW;





typedef MCI_OVLY_OPEN_PARMSA MCI_OVLY_OPEN_PARMS;
typedef PMCI_OVLY_OPEN_PARMSA PMCI_OVLY_OPEN_PARMS;
typedef LPMCI_OVLY_OPEN_PARMSA LPMCI_OVLY_OPEN_PARMS;
typedef struct tagMCI_OVLY_WINDOW_PARMSA {
    DWORD_PTR dwCallback;
    HWND hWnd;
    UINT nCmdShow;
    LPCSTR lpstrText;
} MCI_OVLY_WINDOW_PARMSA, *PMCI_OVLY_WINDOW_PARMSA, * LPMCI_OVLY_WINDOW_PARMSA;
typedef struct tagMCI_OVLY_WINDOW_PARMSW {
    DWORD_PTR dwCallback;
    HWND hWnd;
    UINT nCmdShow;
    LPCWSTR lpstrText;
} MCI_OVLY_WINDOW_PARMSW, *PMCI_OVLY_WINDOW_PARMSW, * LPMCI_OVLY_WINDOW_PARMSW;





typedef MCI_OVLY_WINDOW_PARMSA MCI_OVLY_WINDOW_PARMS;
typedef PMCI_OVLY_WINDOW_PARMSA PMCI_OVLY_WINDOW_PARMS;
typedef LPMCI_OVLY_WINDOW_PARMSA LPMCI_OVLY_WINDOW_PARMS;
typedef struct tagMCI_OVLY_RECT_PARMS {
    DWORD_PTR dwCallback;




    RECT rc;

} MCI_OVLY_RECT_PARMS, *PMCI_OVLY_RECT_PARMS,   * LPMCI_OVLY_RECT_PARMS;





typedef struct tagMCI_OVLY_SAVE_PARMSA {
    DWORD_PTR dwCallback;
    LPCSTR lpfilename;
    RECT rc;
} MCI_OVLY_SAVE_PARMSA, *PMCI_OVLY_SAVE_PARMSA, * LPMCI_OVLY_SAVE_PARMSA;
typedef struct tagMCI_OVLY_SAVE_PARMSW {
    DWORD_PTR dwCallback;
    LPCWSTR lpfilename;
    RECT rc;
} MCI_OVLY_SAVE_PARMSW, *PMCI_OVLY_SAVE_PARMSW, * LPMCI_OVLY_SAVE_PARMSW;





typedef MCI_OVLY_SAVE_PARMSA MCI_OVLY_SAVE_PARMS;
typedef PMCI_OVLY_SAVE_PARMSA PMCI_OVLY_SAVE_PARMS;
typedef LPMCI_OVLY_SAVE_PARMSA LPMCI_OVLY_SAVE_PARMS;
typedef struct tagMCI_OVLY_LOAD_PARMSA {
    DWORD_PTR dwCallback;
    LPCSTR lpfilename;
    RECT rc;
} MCI_OVLY_LOAD_PARMSA, *PMCI_OVLY_LOAD_PARMSA, * LPMCI_OVLY_LOAD_PARMSA;
typedef struct tagMCI_OVLY_LOAD_PARMSW {
    DWORD_PTR dwCallback;
    LPCWSTR lpfilename;
    RECT rc;
} MCI_OVLY_LOAD_PARMSW, *PMCI_OVLY_LOAD_PARMSW, * LPMCI_OVLY_LOAD_PARMSW;





typedef MCI_OVLY_LOAD_PARMSA MCI_OVLY_LOAD_PARMS;
typedef PMCI_OVLY_LOAD_PARMSA PMCI_OVLY_LOAD_PARMS;
typedef LPMCI_OVLY_LOAD_PARMSA LPMCI_OVLY_LOAD_PARMS;
typedef struct _NCB {
    UCHAR ncb_command;
    UCHAR ncb_retcode;
    UCHAR ncb_lsn;
    UCHAR ncb_num;
    PUCHAR ncb_buffer;
    WORD ncb_length;
    UCHAR ncb_callname[ 16 ];
    UCHAR ncb_name[ 16 ];
    UCHAR ncb_rto;
    UCHAR ncb_sto;
    void (  *ncb_post)( struct _NCB * );
    UCHAR ncb_lana_num;
    UCHAR ncb_cmd_cplt;



    UCHAR ncb_reserve[10];

    HANDLE ncb_event;



} NCB, *PNCB;
typedef struct _ADAPTER_STATUS {
    UCHAR adapter_address[6];
    UCHAR rev_major;
    UCHAR reserved0;
    UCHAR adapter_type;
    UCHAR rev_minor;
    WORD duration;
    WORD frmr_recv;
    WORD frmr_xmit;

    WORD iframe_recv_err;

    WORD xmit_aborts;
    DWORD xmit_success;
    DWORD recv_success;

    WORD iframe_xmit_err;

    WORD recv_buff_unavail;
    WORD t1_timeouts;
    WORD ti_timeouts;
    DWORD reserved1;
    WORD free_ncbs;
    WORD max_cfg_ncbs;
    WORD max_ncbs;
    WORD xmit_buf_unavail;
    WORD max_dgram_size;
    WORD pending_sess;
    WORD max_cfg_sess;
    WORD max_sess;
    WORD max_sess_pkt_size;
    WORD name_count;
} ADAPTER_STATUS, *PADAPTER_STATUS;

typedef struct _NAME_BUFFER {
    UCHAR name[ 16 ];
    UCHAR name_num;
    UCHAR name_flags;
} NAME_BUFFER, *PNAME_BUFFER;
typedef struct _SESSION_HEADER {
    UCHAR sess_name;
    UCHAR num_sess;
    UCHAR rcv_dg_outstanding;
    UCHAR rcv_any_outstanding;
} SESSION_HEADER, *PSESSION_HEADER;

typedef struct _SESSION_BUFFER {
    UCHAR lsn;
    UCHAR state;
    UCHAR local_name[ 16 ];
    UCHAR remote_name[ 16 ];
    UCHAR rcvs_outstanding;
    UCHAR sends_outstanding;
} SESSION_BUFFER, *PSESSION_BUFFER;
typedef struct _LANA_ENUM {
    UCHAR length;
    UCHAR lana[ 254 +1];
} LANA_ENUM, *PLANA_ENUM;
typedef struct _FIND_NAME_HEADER {
    WORD node_count;
    UCHAR reserved;
    UCHAR unique_group;
} FIND_NAME_HEADER, *PFIND_NAME_HEADER;

typedef struct _FIND_NAME_BUFFER {
    UCHAR length;
    UCHAR access_control;
    UCHAR frame_control;
    UCHAR destination_addr[6];
    UCHAR source_addr[6];
    UCHAR routing_info[18];
} FIND_NAME_BUFFER, *PFIND_NAME_BUFFER;
typedef struct _ACTION_HEADER {
    ULONG transport_id;
    USHORT action_code;
    USHORT reserved;
} ACTION_HEADER, *PACTION_HEADER;
UCHAR

Netbios(
    PNCB pncb
    );
typedef void * I_RPC_HANDLE;



typedef long RPC_STATUS;

typedef   unsigned char   * RPC_CSTR;



typedef   unsigned short   * RPC_WSTR;


typedef I_RPC_HANDLE RPC_BINDING_HANDLE;
typedef RPC_BINDING_HANDLE handle_t;
typedef GUID UUID;





typedef struct _RPC_BINDING_VECTOR
{
    unsigned long Count;
    RPC_BINDING_HANDLE BindingH[1];
} RPC_BINDING_VECTOR;




typedef struct _UUID_VECTOR
{
  unsigned long Count;
  UUID *Uuid[1];
} UUID_VECTOR;




typedef void   * RPC_IF_HANDLE;



typedef struct _RPC_IF_ID
{
    UUID Uuid;
    unsigned short VersMajor;
    unsigned short VersMinor;
} RPC_IF_ID;
typedef struct _RPC_PROTSEQ_VECTORA
{
    unsigned int Count;
    unsigned char   * Protseq[1];
} RPC_PROTSEQ_VECTORA;

typedef struct _RPC_PROTSEQ_VECTORW
{
    unsigned int Count;
    unsigned short   * Protseq[1];
} RPC_PROTSEQ_VECTORW;
typedef struct _RPC_POLICY {
    unsigned int Length ;
    unsigned long EndpointFlags ;
    unsigned long NICFlags ;
    } RPC_POLICY,   *PRPC_POLICY ;

typedef void
RPC_OBJECT_INQ_FN (
     UUID   * ObjectUuid,
     UUID   * TypeUuid,
     RPC_STATUS   * Status
    );


typedef RPC_STATUS
RPC_IF_CALLBACK_FN (
     RPC_IF_HANDLE InterfaceUuid,
     void *Context
    ) ;

typedef void
RPC_SECURITY_CALLBACK_FN (
     void *Context
    ) ;



typedef struct
{
    unsigned int Count;
    unsigned long Stats[1];
} RPC_STATS_VECTOR;






typedef struct
{
  unsigned long Count;
  RPC_IF_ID   * IfId[1];
} RPC_IF_ID_VECTOR;


__declspec(dllimport)
RPC_STATUS

RpcBindingCopy (
     RPC_BINDING_HANDLE SourceBinding,
     RPC_BINDING_HANDLE   * DestinationBinding
    );


__declspec(dllimport)
RPC_STATUS

RpcBindingFree (
       RPC_BINDING_HANDLE   * Binding
    );


__declspec(dllimport)
RPC_STATUS

RpcBindingSetOption (
     RPC_BINDING_HANDLE hBinding,
     unsigned long option,
     ULONG_PTR optionValue
    );


__declspec(dllimport)
RPC_STATUS

RpcBindingInqOption (
     RPC_BINDING_HANDLE hBinding,
     unsigned long option,
     ULONG_PTR *pOptionValue
    );







__declspec(dllimport)
RPC_STATUS

RpcBindingFromStringBindingA (
     RPC_CSTR StringBinding,
     RPC_BINDING_HANDLE   * Binding
    );

__declspec(dllimport)
RPC_STATUS

RpcBindingFromStringBindingW (
     RPC_WSTR StringBinding,
     RPC_BINDING_HANDLE   * Binding
    );
__declspec(dllimport)
RPC_STATUS

RpcSsGetContextBinding (
     void *ContextHandle,
     RPC_BINDING_HANDLE   * Binding
    );


__declspec(dllimport)
RPC_STATUS

RpcBindingInqObject (
     RPC_BINDING_HANDLE Binding,
     UUID   * ObjectUuid
    );


__declspec(dllimport)
RPC_STATUS

RpcBindingReset (
     RPC_BINDING_HANDLE Binding
    );





__declspec(dllimport)
RPC_STATUS

RpcBindingSetObject (
     RPC_BINDING_HANDLE Binding,
     UUID   * ObjectUuid
    );


__declspec(dllimport)
RPC_STATUS

RpcMgmtInqDefaultProtectLevel (
     unsigned long AuthnSvc,
     unsigned long   *AuthnLevel
    );





__declspec(dllimport)
RPC_STATUS

RpcBindingToStringBindingA (
     RPC_BINDING_HANDLE Binding,
     RPC_CSTR   * StringBinding
    );

__declspec(dllimport)
RPC_STATUS

RpcBindingToStringBindingW (
     RPC_BINDING_HANDLE Binding,
     RPC_WSTR   * StringBinding
    );
__declspec(dllimport)
RPC_STATUS

RpcBindingVectorFree (
     RPC_BINDING_VECTOR   *   * BindingVector
    );







__declspec(dllimport)
RPC_STATUS

RpcStringBindingComposeA (
     RPC_CSTR ObjUuid,
     RPC_CSTR ProtSeq,
     RPC_CSTR NetworkAddr,
     RPC_CSTR Endpoint,
     RPC_CSTR Options,
     RPC_CSTR   * StringBinding
    );

__declspec(dllimport)
RPC_STATUS

RpcStringBindingComposeW (
     RPC_WSTR ObjUuid,
     RPC_WSTR ProtSeq,
     RPC_WSTR NetworkAddr,
     RPC_WSTR Endpoint,
     RPC_WSTR Options,
     RPC_WSTR   * StringBinding
    );
__declspec(dllimport)
RPC_STATUS

RpcStringBindingParseA (
     RPC_CSTR StringBinding,
     RPC_CSTR   * ObjUuid,
     RPC_CSTR   * Protseq,
     RPC_CSTR   * NetworkAddr,
     RPC_CSTR   * Endpoint,
     RPC_CSTR   * NetworkOptions
    );

__declspec(dllimport)
RPC_STATUS

RpcStringBindingParseW (
     RPC_WSTR StringBinding,
     RPC_WSTR   * ObjUuid,
     RPC_WSTR   * Protseq,
     RPC_WSTR   * NetworkAddr,
     RPC_WSTR   * Endpoint,
     RPC_WSTR   * NetworkOptions
    );
__declspec(dllimport)
RPC_STATUS

RpcStringFreeA (
     RPC_CSTR   * String
    );

__declspec(dllimport)
RPC_STATUS

RpcStringFreeW (
     RPC_WSTR   * String
    );
__declspec(dllimport)
RPC_STATUS

RpcIfInqId (
     RPC_IF_HANDLE RpcIfHandle,
     RPC_IF_ID   * RpcIfId
    );





__declspec(dllimport)
RPC_STATUS

RpcNetworkIsProtseqValidA (
     RPC_CSTR Protseq
    );

__declspec(dllimport)
RPC_STATUS

RpcNetworkIsProtseqValidW (
     RPC_WSTR Protseq
    );
__declspec(dllimport)
RPC_STATUS

RpcMgmtInqComTimeout (
     RPC_BINDING_HANDLE Binding,
     unsigned int   * Timeout
    );


__declspec(dllimport)
RPC_STATUS

RpcMgmtSetComTimeout (
     RPC_BINDING_HANDLE Binding,
     unsigned int Timeout
    );


__declspec(dllimport)
RPC_STATUS

RpcMgmtSetCancelTimeout(
     long Timeout
    );






__declspec(dllimport)
RPC_STATUS

RpcNetworkInqProtseqsA (
     RPC_PROTSEQ_VECTORA   *   * ProtseqVector
    );

__declspec(dllimport)
RPC_STATUS

RpcNetworkInqProtseqsW (
     RPC_PROTSEQ_VECTORW   *   * ProtseqVector
    );
__declspec(dllimport)
RPC_STATUS

RpcObjectInqType (
     UUID   * ObjUuid,
       UUID   * TypeUuid
    );


__declspec(dllimport)
RPC_STATUS

RpcObjectSetInqFn (
     RPC_OBJECT_INQ_FN   * InquiryFn
    );


__declspec(dllimport)
RPC_STATUS

RpcObjectSetType (
     UUID   * ObjUuid,
       UUID   * TypeUuid
    );





__declspec(dllimport)
RPC_STATUS

RpcProtseqVectorFreeA (
     RPC_PROTSEQ_VECTORA   *   * ProtseqVector
    );

__declspec(dllimport)
RPC_STATUS

RpcProtseqVectorFreeW (
     RPC_PROTSEQ_VECTORW   *   * ProtseqVector
    );
__declspec(dllimport)
RPC_STATUS

RpcServerInqBindings (
     RPC_BINDING_VECTOR   *   * BindingVector
    );


__declspec(dllimport)
RPC_STATUS

RpcServerInqIf (
     RPC_IF_HANDLE IfSpec,
     UUID   * MgrTypeUuid,
      void    *   * MgrEpv
    );


__declspec(dllimport)
RPC_STATUS

RpcServerListen (
     unsigned int MinimumCallThreads,
     unsigned int MaxCalls,
     unsigned int DontWait
    );


__declspec(dllimport)
RPC_STATUS

RpcServerRegisterIf (
     RPC_IF_HANDLE IfSpec,
     UUID   * MgrTypeUuid,
      void    * MgrEpv
    );


__declspec(dllimport)
RPC_STATUS

RpcServerRegisterIfEx (
     RPC_IF_HANDLE IfSpec,
     UUID   * MgrTypeUuid,
      void    * MgrEpv,
     unsigned int Flags,
     unsigned int MaxCalls,
     RPC_IF_CALLBACK_FN   *IfCallback
    );


__declspec(dllimport)
RPC_STATUS

RpcServerRegisterIf2 (
     RPC_IF_HANDLE IfSpec,
     UUID * MgrTypeUuid,
      void  * MgrEpv,
     unsigned int Flags,
     unsigned int MaxCalls,
     unsigned int MaxRpcSize,
     RPC_IF_CALLBACK_FN *IfCallbackFn
    );



__declspec(dllimport)
RPC_STATUS

RpcServerUnregisterIf (
     RPC_IF_HANDLE IfSpec,
     UUID   * MgrTypeUuid,
     unsigned int WaitForCallsToComplete
    );



__declspec(dllimport)
RPC_STATUS

RpcServerUnregisterIfEx (
     RPC_IF_HANDLE IfSpec,
     UUID   * MgrTypeUuid,
     int RundownContextHandles
    );



__declspec(dllimport)
RPC_STATUS

RpcServerUseAllProtseqs (
     unsigned int MaxCalls,
     void   * SecurityDescriptor
    );


__declspec(dllimport)
RPC_STATUS

RpcServerUseAllProtseqsEx (
     unsigned int MaxCalls,
     void   * SecurityDescriptor,
     PRPC_POLICY Policy
    );


__declspec(dllimport)
RPC_STATUS

RpcServerUseAllProtseqsIf (
     unsigned int MaxCalls,
     RPC_IF_HANDLE IfSpec,
     void   * SecurityDescriptor
    );


__declspec(dllimport)
RPC_STATUS

RpcServerUseAllProtseqsIfEx (
     unsigned int MaxCalls,
     RPC_IF_HANDLE IfSpec,
     void   * SecurityDescriptor,
     PRPC_POLICY Policy
    );






__declspec(dllimport)
RPC_STATUS

RpcServerUseProtseqA (
     RPC_CSTR Protseq,
     unsigned int MaxCalls,
     void   * SecurityDescriptor
    );

__declspec(dllimport)
RPC_STATUS

RpcServerUseProtseqExA (
     RPC_CSTR Protseq,
     unsigned int MaxCalls,
     void   * SecurityDescriptor,
     PRPC_POLICY Policy
    );

__declspec(dllimport)
RPC_STATUS

RpcServerUseProtseqW (
     RPC_WSTR Protseq,
     unsigned int MaxCalls,
     void   * SecurityDescriptor
    );

__declspec(dllimport)
RPC_STATUS

RpcServerUseProtseqExW (
     RPC_WSTR Protseq,
     unsigned int MaxCalls,
     void   * SecurityDescriptor,
     PRPC_POLICY Policy
    );
__declspec(dllimport)
RPC_STATUS

RpcServerUseProtseqEpA (
     RPC_CSTR Protseq,
     unsigned int MaxCalls,
     RPC_CSTR Endpoint,
     void   * SecurityDescriptor
    );

__declspec(dllimport)
RPC_STATUS

RpcServerUseProtseqEpExA (
     RPC_CSTR Protseq,
     unsigned int MaxCalls,
     RPC_CSTR Endpoint,
     void   * SecurityDescriptor,
     PRPC_POLICY Policy
    );

__declspec(dllimport)
RPC_STATUS

RpcServerUseProtseqEpW (
     RPC_WSTR Protseq,
     unsigned int MaxCalls,
     RPC_WSTR Endpoint,
     void   * SecurityDescriptor
    );

__declspec(dllimport)
RPC_STATUS

RpcServerUseProtseqEpExW (
     RPC_WSTR Protseq,
     unsigned int MaxCalls,
     RPC_WSTR Endpoint,
     void   * SecurityDescriptor,
     PRPC_POLICY Policy
    );
__declspec(dllimport)
RPC_STATUS

RpcServerUseProtseqIfA (
     RPC_CSTR Protseq,
     unsigned int MaxCalls,
     RPC_IF_HANDLE IfSpec,
     void   * SecurityDescriptor
    );

__declspec(dllimport)
RPC_STATUS

RpcServerUseProtseqIfExA (
     RPC_CSTR Protseq,
     unsigned int MaxCalls,
     RPC_IF_HANDLE IfSpec,
     void   * SecurityDescriptor,
     PRPC_POLICY Policy
    );

__declspec(dllimport)
RPC_STATUS

RpcServerUseProtseqIfW (
     RPC_WSTR Protseq,
     unsigned int MaxCalls,
     RPC_IF_HANDLE IfSpec,
     void   * SecurityDescriptor
    );

__declspec(dllimport)
RPC_STATUS

RpcServerUseProtseqIfExW (
     RPC_WSTR Protseq,
     unsigned int MaxCalls,
     RPC_IF_HANDLE IfSpec,
     void   * SecurityDescriptor,
     PRPC_POLICY Policy
    );
__declspec(dllimport)
void

RpcServerYield (
    void
    );


__declspec(dllimport)
RPC_STATUS

RpcMgmtStatsVectorFree (
     RPC_STATS_VECTOR ** StatsVector
    );


__declspec(dllimport)
RPC_STATUS

RpcMgmtInqStats (
     RPC_BINDING_HANDLE Binding,
     RPC_STATS_VECTOR ** Statistics
    );


__declspec(dllimport)
RPC_STATUS

RpcMgmtIsServerListening (
     RPC_BINDING_HANDLE Binding
    );


__declspec(dllimport)
RPC_STATUS

RpcMgmtStopServerListening (
     RPC_BINDING_HANDLE Binding
    );


__declspec(dllimport)
RPC_STATUS

RpcMgmtWaitServerListen (
    void
    );


__declspec(dllimport)
RPC_STATUS

RpcMgmtSetServerStackSize (
     unsigned long ThreadStackSize
    );


__declspec(dllimport)
void

RpcSsDontSerializeContext (
    void
    );


__declspec(dllimport)
RPC_STATUS

RpcMgmtEnableIdleCleanup (
    void
    );

__declspec(dllimport)
RPC_STATUS

RpcMgmtInqIfIds (
     RPC_BINDING_HANDLE Binding,
     RPC_IF_ID_VECTOR   *   * IfIdVector
    );

__declspec(dllimport)
RPC_STATUS

RpcIfIdVectorFree (
     RPC_IF_ID_VECTOR   *   * IfIdVector
    );



__declspec(dllimport)
RPC_STATUS

RpcMgmtInqServerPrincNameA (
     RPC_BINDING_HANDLE Binding,
     unsigned long AuthnSvc,
     RPC_CSTR   * ServerPrincName
    );

__declspec(dllimport)
RPC_STATUS

RpcMgmtInqServerPrincNameW (
     RPC_BINDING_HANDLE Binding,
     unsigned long AuthnSvc,
     RPC_WSTR   * ServerPrincName
    );
__declspec(dllimport)
RPC_STATUS

RpcServerInqDefaultPrincNameA (
     unsigned long AuthnSvc,
     RPC_CSTR   * PrincName
    );

__declspec(dllimport)
RPC_STATUS

RpcServerInqDefaultPrincNameW (
     unsigned long AuthnSvc,
     RPC_WSTR   * PrincName
    );
__declspec(dllimport)
RPC_STATUS

RpcEpResolveBinding (
     RPC_BINDING_HANDLE Binding,
     RPC_IF_HANDLE IfSpec
    );





__declspec(dllimport)
RPC_STATUS

RpcNsBindingInqEntryNameA (
     RPC_BINDING_HANDLE Binding,
     unsigned long EntryNameSyntax,
     RPC_CSTR   * EntryName
    );

__declspec(dllimport)
RPC_STATUS

RpcNsBindingInqEntryNameW (
     RPC_BINDING_HANDLE Binding,
     unsigned long EntryNameSyntax,
     RPC_WSTR   * EntryName
    );
typedef void   * RPC_AUTH_IDENTITY_HANDLE;
typedef void   * RPC_AUTHZ_HANDLE;
typedef struct _RPC_SECURITY_QOS {
  unsigned long Version;
  unsigned long Capabilities;
  unsigned long IdentityTracking;
  unsigned long ImpersonationType;
} RPC_SECURITY_QOS, *PRPC_SECURITY_QOS;







typedef struct _SEC_WINNT_AUTH_IDENTITY_W {
   unsigned short   *User;
  unsigned long UserLength;
   unsigned short   *Domain;
  unsigned long DomainLength;
   unsigned short   *Password;
  unsigned long PasswordLength;
  unsigned long Flags;
} SEC_WINNT_AUTH_IDENTITY_W, *PSEC_WINNT_AUTH_IDENTITY_W;





typedef struct _SEC_WINNT_AUTH_IDENTITY_A {
   unsigned char   *User;
  unsigned long UserLength;
   unsigned char   *Domain;
  unsigned long DomainLength;
   unsigned char   *Password;
  unsigned long PasswordLength;
  unsigned long Flags;
} SEC_WINNT_AUTH_IDENTITY_A, *PSEC_WINNT_AUTH_IDENTITY_A;
typedef struct _RPC_HTTP_TRANSPORT_CREDENTIALS_W
{
    SEC_WINNT_AUTH_IDENTITY_W *TransportCredentials;
    unsigned long Flags;
    unsigned long AuthenticationTarget;
    unsigned long NumberOfAuthnSchemes;
    unsigned long *AuthnSchemes;
    unsigned short   *ServerCertificateSubject;
} RPC_HTTP_TRANSPORT_CREDENTIALS_W, *PRPC_HTTP_TRANSPORT_CREDENTIALS_W;

typedef struct _RPC_HTTP_TRANSPORT_CREDENTIALS_A
{
    SEC_WINNT_AUTH_IDENTITY_A *TransportCredentials;
    unsigned long Flags;
    unsigned long AuthenticationTarget;
    unsigned long NumberOfAuthnSchemes;
    unsigned long *AuthnSchemes;
    unsigned char   *ServerCertificateSubject;
} RPC_HTTP_TRANSPORT_CREDENTIALS_A, *PRPC_HTTP_TRANSPORT_CREDENTIALS_A;



typedef struct _RPC_HTTP_TRANSPORT_CREDENTIALS_V2_W
{
    SEC_WINNT_AUTH_IDENTITY_W *TransportCredentials;
    unsigned long Flags;
    unsigned long AuthenticationTarget;
    unsigned long NumberOfAuthnSchemes;
     unsigned long *AuthnSchemes;
    unsigned short   *ServerCertificateSubject;
    SEC_WINNT_AUTH_IDENTITY_W *ProxyCredentials;
    unsigned long NumberOfProxyAuthnSchemes;
     unsigned long *ProxyAuthnSchemes;
} RPC_HTTP_TRANSPORT_CREDENTIALS_V2_W, *PRPC_HTTP_TRANSPORT_CREDENTIALS_V2_W;

typedef struct _RPC_HTTP_TRANSPORT_CREDENTIALS_V2_A
{
    SEC_WINNT_AUTH_IDENTITY_A *TransportCredentials;
    unsigned long Flags;
    unsigned long AuthenticationTarget;
    unsigned long NumberOfAuthnSchemes;
    unsigned long *AuthnSchemes;
    unsigned char   *ServerCertificateSubject;
    SEC_WINNT_AUTH_IDENTITY_A *ProxyCredentials;
    unsigned long NumberOfProxyAuthnSchemes;
    unsigned long *ProxyAuthnSchemes;
} RPC_HTTP_TRANSPORT_CREDENTIALS_V2_A, *PRPC_HTTP_TRANSPORT_CREDENTIALS_V2_A;



typedef struct _RPC_SECURITY_QOS_V2_W {
  unsigned long Version;
  unsigned long Capabilities;
  unsigned long IdentityTracking;
  unsigned long ImpersonationType;
  unsigned long AdditionalSecurityInfoType;
  union
      {
      RPC_HTTP_TRANSPORT_CREDENTIALS_W *HttpCredentials;
      } u;
} RPC_SECURITY_QOS_V2_W, *PRPC_SECURITY_QOS_V2_W;

typedef struct _RPC_SECURITY_QOS_V2_A {
  unsigned long Version;
  unsigned long Capabilities;
  unsigned long IdentityTracking;
  unsigned long ImpersonationType;
  unsigned long AdditionalSecurityInfoType;
  union
      {
      RPC_HTTP_TRANSPORT_CREDENTIALS_A *HttpCredentials;
      } u;
} RPC_SECURITY_QOS_V2_A, *PRPC_SECURITY_QOS_V2_A;




typedef struct _RPC_SECURITY_QOS_V3_W {
  unsigned long Version;
  unsigned long Capabilities;
  unsigned long IdentityTracking;
  unsigned long ImpersonationType;
  unsigned long AdditionalSecurityInfoType;
  union
      {
      RPC_HTTP_TRANSPORT_CREDENTIALS_W *HttpCredentials;
      } u;
  void *Sid;
} RPC_SECURITY_QOS_V3_W, *PRPC_SECURITY_QOS_V3_W;

typedef struct _RPC_SECURITY_QOS_V3_A {
  unsigned long Version;
  unsigned long Capabilities;
  unsigned long IdentityTracking;
  unsigned long ImpersonationType;
  unsigned long AdditionalSecurityInfoType;
  union
      {
      RPC_HTTP_TRANSPORT_CREDENTIALS_A *HttpCredentials;
      } u;
  void *Sid;
} RPC_SECURITY_QOS_V3_A, *PRPC_SECURITY_QOS_V3_A;






typedef struct _RPC_SECURITY_QOS_V4_W {
  unsigned long Version;
  unsigned long Capabilities;
  unsigned long IdentityTracking;
  unsigned long ImpersonationType;
  unsigned long AdditionalSecurityInfoType;
  union
      {
      RPC_HTTP_TRANSPORT_CREDENTIALS_W *HttpCredentials;
      } u;
  void *Sid;
  unsigned int EffectiveOnly;
} RPC_SECURITY_QOS_V4_W, *PRPC_SECURITY_QOS_V4_W;

typedef struct _RPC_SECURITY_QOS_V4_A {
  unsigned long Version;
  unsigned long Capabilities;
  unsigned long IdentityTracking;
  unsigned long ImpersonationType;
  unsigned long AdditionalSecurityInfoType;
  union
      {
      RPC_HTTP_TRANSPORT_CREDENTIALS_A *HttpCredentials;
      } u;
  void *Sid;
  unsigned int EffectiveOnly;
} RPC_SECURITY_QOS_V4_A, *PRPC_SECURITY_QOS_V4_A;
typedef struct _RPC_BINDING_HANDLE_TEMPLATE_V1_W {
    unsigned long Version;
    unsigned long Flags;
    unsigned long ProtocolSequence;
    unsigned short *NetworkAddress;
    unsigned short *StringEndpoint;
    union
    {
        unsigned short *Reserved;
    } u1;
    UUID ObjectUuid;
} RPC_BINDING_HANDLE_TEMPLATE_V1_W, *PRPC_BINDING_HANDLE_TEMPLATE_V1_W;

typedef struct _RPC_BINDING_HANDLE_TEMPLATE_V1_A {
    unsigned long Version;
    unsigned long Flags;
    unsigned long ProtocolSequence;
    unsigned char *NetworkAddress;
    unsigned char *StringEndpoint;
    union
    {
        unsigned char *Reserved;
    } u1;
    UUID ObjectUuid;
} RPC_BINDING_HANDLE_TEMPLATE_V1_A, *PRPC_BINDING_HANDLE_TEMPLATE_V1_A;

typedef struct _RPC_BINDING_HANDLE_SECURITY_V1_W {
    unsigned long Version;
    unsigned short *ServerPrincName;
    unsigned long AuthnLevel;
    unsigned long AuthnSvc;
    SEC_WINNT_AUTH_IDENTITY_W *AuthIdentity;
    RPC_SECURITY_QOS *SecurityQos;
} RPC_BINDING_HANDLE_SECURITY_V1_W, *PRPC_BINDING_HANDLE_SECURITY_V1_W;



typedef struct _RPC_BINDING_HANDLE_SECURITY_V1_A {
    unsigned long Version;
    unsigned char *ServerPrincName;
    unsigned long AuthnLevel;
    unsigned long AuthnSvc;
    SEC_WINNT_AUTH_IDENTITY_A *AuthIdentity;
    RPC_SECURITY_QOS *SecurityQos;
} RPC_BINDING_HANDLE_SECURITY_V1_A, *PRPC_BINDING_HANDLE_SECURITY_V1_A;



typedef struct _RPC_BINDING_HANDLE_OPTIONS_V1 {
    unsigned long Version;
    unsigned long Flags;
    unsigned long ComTimeout;
    unsigned long CallTimeout;
} RPC_BINDING_HANDLE_OPTIONS_V1, *PRPC_BINDING_HANDLE_OPTIONS_V1;
__declspec(dllimport)
RPC_STATUS

RpcBindingCreateA (
     RPC_BINDING_HANDLE_TEMPLATE_V1_A * Template,
     RPC_BINDING_HANDLE_SECURITY_V1_A * Security,
     RPC_BINDING_HANDLE_OPTIONS_V1 * Options,
     RPC_BINDING_HANDLE * Binding
    );



__declspec(dllimport)
RPC_STATUS

RpcBindingCreateW (
     RPC_BINDING_HANDLE_TEMPLATE_V1_W * Template,
     RPC_BINDING_HANDLE_SECURITY_V1_W * Security,
     RPC_BINDING_HANDLE_OPTIONS_V1 * Options,
     RPC_BINDING_HANDLE * Binding
    );







__declspec(dllimport)
RPC_STATUS

RpcBindingGetTrainingContextHandle (
     RPC_BINDING_HANDLE Binding,
     void ** ContextHandle
    );

__declspec(dllimport)
RPC_STATUS

RpcServerInqBindingHandle (
     RPC_BINDING_HANDLE * Binding
    );



typedef enum _RPC_HTTP_REDIRECTOR_STAGE
{
    RPCHTTP_RS_REDIRECT = 1,
    RPCHTTP_RS_ACCESS_1,
    RPCHTTP_RS_SESSION,
    RPCHTTP_RS_ACCESS_2,
    RPCHTTP_RS_INTERFACE
} RPC_HTTP_REDIRECTOR_STAGE;



typedef RPC_STATUS
(  * RPC_NEW_HTTP_PROXY_CHANNEL) (
     RPC_HTTP_REDIRECTOR_STAGE RedirectorStage,
     RPC_WSTR ServerName,
     RPC_WSTR ServerPort,
     RPC_WSTR RemoteUser,
     RPC_WSTR AuthType,
     void   * ResourceUuid,
     void   * SessionId,
     void   * Interface,
     void   * Reserved,
     unsigned long Flags,
     RPC_WSTR   * NewServerName,
     RPC_WSTR   * NewServerPort
    );
typedef void
(  * RPC_HTTP_PROXY_FREE_STRING) (
     RPC_WSTR String
    );







__declspec(dllimport)
RPC_STATUS

RpcImpersonateClient (
     RPC_BINDING_HANDLE BindingHandle
    );

__declspec(dllimport)
RPC_STATUS

RpcRevertToSelfEx (
     RPC_BINDING_HANDLE BindingHandle
    );

__declspec(dllimport)
RPC_STATUS

RpcRevertToSelf (
    void
    );



__declspec(dllimport)
RPC_STATUS

RpcBindingInqAuthClientA (
     RPC_BINDING_HANDLE ClientBinding,
     RPC_AUTHZ_HANDLE   * Privs,
     RPC_CSTR   * ServerPrincName,
     unsigned long   * AuthnLevel,
     unsigned long   * AuthnSvc,
     unsigned long   * AuthzSvc
    );

__declspec(dllimport)
RPC_STATUS

RpcBindingInqAuthClientW (
     RPC_BINDING_HANDLE ClientBinding,
     RPC_AUTHZ_HANDLE   * Privs,
     RPC_WSTR   * ServerPrincName,
     unsigned long   * AuthnLevel,
     unsigned long   * AuthnSvc,
     unsigned long   * AuthzSvc
    );

__declspec(dllimport)
RPC_STATUS

RpcBindingInqAuthClientExA (
     RPC_BINDING_HANDLE ClientBinding,
     RPC_AUTHZ_HANDLE   * Privs,
     RPC_CSTR   * ServerPrincName,
     unsigned long   * AuthnLevel,
     unsigned long   * AuthnSvc,
     unsigned long   * AuthzSvc,
     unsigned long Flags
    );

__declspec(dllimport)
RPC_STATUS

RpcBindingInqAuthClientExW (
     RPC_BINDING_HANDLE ClientBinding,
     RPC_AUTHZ_HANDLE   * Privs,
     RPC_WSTR   * ServerPrincName,
     unsigned long   * AuthnLevel,
     unsigned long   * AuthnSvc,
     unsigned long   * AuthzSvc,
     unsigned long Flags
    );

__declspec(dllimport)
RPC_STATUS

RpcBindingInqAuthInfoA (
     RPC_BINDING_HANDLE Binding,
     RPC_CSTR   * ServerPrincName,
     unsigned long   * AuthnLevel,
     unsigned long   * AuthnSvc,
     RPC_AUTH_IDENTITY_HANDLE   * AuthIdentity,
     unsigned long   * AuthzSvc
    );

__declspec(dllimport)
RPC_STATUS

RpcBindingInqAuthInfoW (
     RPC_BINDING_HANDLE Binding,
     RPC_WSTR   * ServerPrincName,
     unsigned long   * AuthnLevel,
     unsigned long   * AuthnSvc,
     RPC_AUTH_IDENTITY_HANDLE   * AuthIdentity,
     unsigned long   * AuthzSvc
    );

__declspec(dllimport)
RPC_STATUS

RpcBindingSetAuthInfoA (
     RPC_BINDING_HANDLE Binding,
     RPC_CSTR ServerPrincName,
     unsigned long AuthnLevel,
     unsigned long AuthnSvc,
     RPC_AUTH_IDENTITY_HANDLE AuthIdentity,
     unsigned long AuthzSvc
    );

__declspec(dllimport)
RPC_STATUS

RpcBindingSetAuthInfoExA (
     RPC_BINDING_HANDLE Binding,
     RPC_CSTR ServerPrincName,
     unsigned long AuthnLevel,
     unsigned long AuthnSvc,
     RPC_AUTH_IDENTITY_HANDLE AuthIdentity,
     unsigned long AuthzSvc,
     RPC_SECURITY_QOS * SecurityQos
    );

__declspec(dllimport)
RPC_STATUS

RpcBindingSetAuthInfoW (
     RPC_BINDING_HANDLE Binding,
     RPC_WSTR ServerPrincName,
     unsigned long AuthnLevel,
     unsigned long AuthnSvc,
     RPC_AUTH_IDENTITY_HANDLE AuthIdentity,
     unsigned long AuthzSvc
    );

__declspec(dllimport)
RPC_STATUS

RpcBindingSetAuthInfoExW (
     RPC_BINDING_HANDLE Binding,
     RPC_WSTR ServerPrincName,
     unsigned long AuthnLevel,
     unsigned long AuthnSvc,
     RPC_AUTH_IDENTITY_HANDLE AuthIdentity,
     unsigned long AuthzSvc,
     RPC_SECURITY_QOS * SecurityQOS
    );

__declspec(dllimport)
RPC_STATUS

RpcBindingInqAuthInfoExA (
     RPC_BINDING_HANDLE Binding,
     RPC_CSTR   * ServerPrincName,
     unsigned long   * AuthnLevel,
     unsigned long   * AuthnSvc,
     RPC_AUTH_IDENTITY_HANDLE   * AuthIdentity,
     unsigned long   * AuthzSvc,
     unsigned long RpcQosVersion,
     RPC_SECURITY_QOS *SecurityQOS
    );

__declspec(dllimport)
RPC_STATUS

RpcBindingInqAuthInfoExW (
     RPC_BINDING_HANDLE Binding,
     RPC_WSTR   * ServerPrincName,
     unsigned long   * AuthnLevel,
     unsigned long   * AuthnSvc,
     RPC_AUTH_IDENTITY_HANDLE   * AuthIdentity,
     unsigned long   * AuthzSvc,
     unsigned long RpcQosVersion,
     RPC_SECURITY_QOS * SecurityQOS
    );

typedef void
(  * RPC_AUTH_KEY_RETRIEVAL_FN) (
     void   * Arg,
     RPC_WSTR ServerPrincName,
     unsigned long KeyVer,
     void   *   * Key,
     RPC_STATUS   * Status
    );

__declspec(dllimport)
RPC_STATUS

RpcServerCompleteSecurityCallback(
     RPC_BINDING_HANDLE BindingHandle,
     RPC_STATUS Status
    );

__declspec(dllimport)
RPC_STATUS

RpcServerRegisterAuthInfoA (
     RPC_CSTR ServerPrincName,
     unsigned long AuthnSvc,
     RPC_AUTH_KEY_RETRIEVAL_FN GetKeyFn,
     void   * Arg
    );

__declspec(dllimport)
RPC_STATUS

RpcServerRegisterAuthInfoW (
     RPC_WSTR ServerPrincName,
     unsigned long AuthnSvc,
     RPC_AUTH_KEY_RETRIEVAL_FN GetKeyFn,
     void   * Arg
    );
typedef struct {
    unsigned char   * UserName;
    unsigned char   * ComputerName;
    unsigned short Privilege;
    unsigned long AuthFlags;
} RPC_CLIENT_INFORMATION1,   * PRPC_CLIENT_INFORMATION1;



__declspec(dllimport)
RPC_STATUS

RpcBindingServerFromClient (
     RPC_BINDING_HANDLE ClientBinding,
     RPC_BINDING_HANDLE   * ServerBinding
    );

__declspec(dllimport)

void

RpcRaiseException (
     RPC_STATUS exception
    );

__declspec(dllimport)
RPC_STATUS

RpcTestCancel(
    void
    );

__declspec(dllimport)
RPC_STATUS

RpcServerTestCancel (
     RPC_BINDING_HANDLE BindingHandle
    );

__declspec(dllimport)
RPC_STATUS

RpcCancelThread(
     void * Thread
    );

__declspec(dllimport)
RPC_STATUS

RpcCancelThreadEx(
     void * Thread,
     long Timeout
    );


__declspec(dllimport)
RPC_STATUS

UuidCreate (
     UUID   * Uuid
    );


__declspec(dllimport)
RPC_STATUS

UuidCreateSequential (
     UUID   * Uuid
    );




__declspec(dllimport)
RPC_STATUS

UuidToStringA (
     const UUID   * Uuid,
     RPC_CSTR   * StringUuid
    );


__declspec(dllimport)
RPC_STATUS

UuidFromStringA (
     RPC_CSTR StringUuid,
     UUID   * Uuid
    );


__declspec(dllimport)
RPC_STATUS

UuidToStringW (
     const UUID   * Uuid,
     RPC_WSTR   * StringUuid
    );


__declspec(dllimport)
RPC_STATUS

UuidFromStringW (
     RPC_WSTR StringUuid,
     UUID   * Uuid
    );
__declspec(dllimport)
signed int

UuidCompare (
     UUID   * Uuid1,
     UUID   * Uuid2,
     RPC_STATUS   * Status
    );

__declspec(dllimport)
RPC_STATUS

UuidCreateNil (
     UUID   * NilUuid
    );

__declspec(dllimport)
int

UuidEqual (
     UUID   * Uuid1,
     UUID   * Uuid2,
     RPC_STATUS   * Status
    );

__declspec(dllimport)
unsigned short

UuidHash (
     UUID   * Uuid,
     RPC_STATUS   * Status
    );

__declspec(dllimport)
int

UuidIsNil (
     UUID   * Uuid,
     RPC_STATUS   * Status
    );



__declspec(dllimport)
RPC_STATUS

RpcEpRegisterNoReplaceA (
     RPC_IF_HANDLE IfSpec,
     RPC_BINDING_VECTOR * BindingVector,
     UUID_VECTOR * UuidVector,
     RPC_CSTR Annotation
    );

__declspec(dllimport)
RPC_STATUS

RpcEpRegisterNoReplaceW (
     RPC_IF_HANDLE IfSpec,
     RPC_BINDING_VECTOR * BindingVector,
     UUID_VECTOR * UuidVector,
     RPC_WSTR Annotation
    );

__declspec(dllimport)
RPC_STATUS

RpcEpRegisterA (
     RPC_IF_HANDLE IfSpec,
     RPC_BINDING_VECTOR * BindingVector,
     UUID_VECTOR * UuidVector,
     RPC_CSTR Annotation
    );

__declspec(dllimport)
RPC_STATUS

RpcEpRegisterW (
     RPC_IF_HANDLE IfSpec,
     RPC_BINDING_VECTOR * BindingVector,
     UUID_VECTOR * UuidVector,
     RPC_WSTR Annotation
    );
__declspec(dllimport)
RPC_STATUS

RpcEpUnregister(
     RPC_IF_HANDLE IfSpec,
     RPC_BINDING_VECTOR * BindingVector,
     UUID_VECTOR * UuidVector
    );





__declspec(dllimport)
RPC_STATUS

DceErrorInqTextA (
     RPC_STATUS RpcStatus,
     RPC_CSTR ErrorText
    );

__declspec(dllimport)
RPC_STATUS

DceErrorInqTextW (
     RPC_STATUS RpcStatus,
     RPC_WSTR ErrorText
    );
typedef I_RPC_HANDLE * RPC_EP_INQ_HANDLE;
__declspec(dllimport)
RPC_STATUS

RpcMgmtEpEltInqBegin (
       RPC_BINDING_HANDLE EpBinding,
     unsigned long InquiryType,
     RPC_IF_ID   * IfId,
     unsigned long VersOption,
     UUID   * ObjectUuid,
     RPC_EP_INQ_HANDLE   * InquiryContext
    );

__declspec(dllimport)
RPC_STATUS

RpcMgmtEpEltInqDone (
     RPC_EP_INQ_HANDLE   * InquiryContext
    );



__declspec(dllimport)
RPC_STATUS

RpcMgmtEpEltInqNextA (
     RPC_EP_INQ_HANDLE InquiryContext,
     RPC_IF_ID   * IfId,
     RPC_BINDING_HANDLE   * Binding,
     UUID   * ObjectUuid,
     RPC_CSTR   * Annotation
    );

__declspec(dllimport)
RPC_STATUS

RpcMgmtEpEltInqNextW (
     RPC_EP_INQ_HANDLE InquiryContext,
     RPC_IF_ID   * IfId,
     RPC_BINDING_HANDLE   * Binding,
     UUID   * ObjectUuid,
     RPC_WSTR   * Annotation
    );
__declspec(dllimport)
RPC_STATUS

RpcMgmtEpUnregister (
     RPC_BINDING_HANDLE EpBinding,
     RPC_IF_ID   * IfId,
     RPC_BINDING_HANDLE Binding,
     UUID   * ObjectUuid
    );

typedef int
(  * RPC_MGMT_AUTHORIZATION_FN) (
     RPC_BINDING_HANDLE ClientBinding,
     unsigned long RequestedMgmtOperation,
     RPC_STATUS   * Status
    );







__declspec(dllimport)
RPC_STATUS

RpcMgmtSetAuthorizationFn (
     RPC_MGMT_AUTHORIZATION_FN AuthorizationFn
    );


__declspec(dllimport)
int

RpcExceptionFilter (
     unsigned long ExceptionCode
    );
typedef struct _RPC_VERSION {
    unsigned short MajorVersion;
    unsigned short MinorVersion;
} RPC_VERSION;

typedef struct _RPC_SYNTAX_IDENTIFIER {
    GUID SyntaxGUID;
    RPC_VERSION SyntaxVersion;
} RPC_SYNTAX_IDENTIFIER,   * PRPC_SYNTAX_IDENTIFIER;

typedef struct _RPC_MESSAGE
{
    RPC_BINDING_HANDLE Handle;
    unsigned long DataRepresentation;
    void   * Buffer;
    unsigned int BufferLength;
    unsigned int ProcNum;
    PRPC_SYNTAX_IDENTIFIER TransferSyntax;
    void   * RpcInterfaceInformation;
    void   * ReservedForRuntime;
    void    * ManagerEpv;
    void   * ImportContext;
    unsigned long RpcFlags;
} RPC_MESSAGE,   * PRPC_MESSAGE;


typedef RPC_STATUS
 RPC_FORWARD_FUNCTION(
                        UUID   * InterfaceId,
                        RPC_VERSION   * InterfaceVersion,
                        UUID   * ObjectId,
                        unsigned char   * Rpcpro,
                        void   *   * ppDestEndpoint);

enum RPC_ADDRESS_CHANGE_TYPE
{
    PROTOCOL_NOT_LOADED = 1,
    PROTOCOL_LOADED,
    PROTOCOL_ADDRESS_CHANGE
};

typedef void
 RPC_ADDRESS_CHANGE_FN(
                         void * arg
                        );
typedef
void
(    * RPC_DISPATCH_FUNCTION) (
       PRPC_MESSAGE Message
    );

typedef struct {
    unsigned int DispatchTableCount;
    RPC_DISPATCH_FUNCTION   * DispatchTable;
    LONG_PTR Reserved;
} RPC_DISPATCH_TABLE,   * PRPC_DISPATCH_TABLE;

typedef struct _RPC_PROTSEQ_ENDPOINT
{
    unsigned char   * RpcProtocolSequence;
    unsigned char   * Endpoint;
} RPC_PROTSEQ_ENDPOINT,   * PRPC_PROTSEQ_ENDPOINT;
typedef struct _RPC_SERVER_INTERFACE
{
    unsigned int Length;
    RPC_SYNTAX_IDENTIFIER InterfaceId;
    RPC_SYNTAX_IDENTIFIER TransferSyntax;
    PRPC_DISPATCH_TABLE DispatchTable;
    unsigned int RpcProtseqEndpointCount;
    PRPC_PROTSEQ_ENDPOINT RpcProtseqEndpoint;
    void    *DefaultManagerEpv;
    void const   *InterpreterInfo;
    unsigned int Flags ;
} RPC_SERVER_INTERFACE,   * PRPC_SERVER_INTERFACE;

typedef struct _RPC_CLIENT_INTERFACE
{
    unsigned int Length;
    RPC_SYNTAX_IDENTIFIER InterfaceId;
    RPC_SYNTAX_IDENTIFIER TransferSyntax;
    PRPC_DISPATCH_TABLE DispatchTable;
    unsigned int RpcProtseqEndpointCount;
    PRPC_PROTSEQ_ENDPOINT RpcProtseqEndpoint;
    ULONG_PTR Reserved;
    void const   * InterpreterInfo;
    unsigned int Flags ;
} RPC_CLIENT_INTERFACE,   * PRPC_CLIENT_INTERFACE;


__declspec(dllimport)
RPC_STATUS

I_RpcNegotiateTransferSyntax (
       RPC_MESSAGE   * Message
    );


__declspec(dllimport)
RPC_STATUS

I_RpcGetBuffer (
       RPC_MESSAGE   * Message
    );

__declspec(dllimport)
RPC_STATUS

I_RpcGetBufferWithObject (
       RPC_MESSAGE   * Message,
     UUID * ObjectUuid
    );

__declspec(dllimport)
RPC_STATUS

I_RpcSendReceive (
       RPC_MESSAGE   * Message
    );

__declspec(dllimport)
RPC_STATUS

I_RpcFreeBuffer (
       RPC_MESSAGE   * Message
    );

__declspec(dllimport)
RPC_STATUS

I_RpcSend (
       PRPC_MESSAGE Message
    );

__declspec(dllimport)
RPC_STATUS

I_RpcReceive (
       PRPC_MESSAGE Message,
     unsigned int Size
    );

__declspec(dllimport)
RPC_STATUS

I_RpcFreePipeBuffer (
       RPC_MESSAGE   * Message
    );

__declspec(dllimport)
RPC_STATUS

I_RpcReallocPipeBuffer (
     PRPC_MESSAGE Message,
     unsigned int NewSize
    );

typedef void * I_RPC_MUTEX;

__declspec(dllimport)
void

I_RpcRequestMutex (
       I_RPC_MUTEX * Mutex
    );

__declspec(dllimport)
void

I_RpcClearMutex (
     I_RPC_MUTEX Mutex
    );

__declspec(dllimport)
void

I_RpcDeleteMutex (
     I_RPC_MUTEX Mutex
    );

__declspec(dllimport)
void   *

I_RpcAllocate (
     unsigned int Size
    );

__declspec(dllimport)
void

I_RpcFree (
     void   * Object
    );

__declspec(dllimport)
void

I_RpcPauseExecution (
     unsigned long Milliseconds
    );

__declspec(dllimport)
RPC_STATUS

I_RpcGetExtendedError (
    void
    );

typedef
void
(    * PRPC_RUNDOWN) (
    void   * AssociationContext
    );

__declspec(dllimport)
RPC_STATUS

I_RpcMonitorAssociation (
     RPC_BINDING_HANDLE Handle,
     PRPC_RUNDOWN RundownRoutine,
     void * Context
    );

__declspec(dllimport)
RPC_STATUS

I_RpcStopMonitorAssociation (
     RPC_BINDING_HANDLE Handle
    );

__declspec(dllimport)
RPC_BINDING_HANDLE

I_RpcGetCurrentCallHandle(
    void
    );

__declspec(dllimport)
RPC_STATUS

I_RpcGetAssociationContext (
     RPC_BINDING_HANDLE BindingHandle,
     void   *   * AssociationContext
    );

__declspec(dllimport)
void *

I_RpcGetServerContextList (
     RPC_BINDING_HANDLE BindingHandle
    );

__declspec(dllimport)
void

I_RpcSetServerContextList (
     RPC_BINDING_HANDLE BindingHandle,
     void * ServerContextList
    );

__declspec(dllimport)
RPC_STATUS

I_RpcNsInterfaceExported (
     unsigned long EntryNameSyntax,
     unsigned short *EntryName,
     RPC_SERVER_INTERFACE * RpcInterfaceInformation
    );

__declspec(dllimport)
RPC_STATUS

I_RpcNsInterfaceUnexported (
     unsigned long EntryNameSyntax,
     unsigned short *EntryName,
     RPC_SERVER_INTERFACE * RpcInterfaceInformation
    );

__declspec(dllimport)
RPC_STATUS

I_RpcBindingToStaticStringBindingW (
     RPC_BINDING_HANDLE Binding,
     unsigned short **StringBinding
    );

__declspec(dllimport)
RPC_STATUS

I_RpcBindingInqSecurityContext (
     RPC_BINDING_HANDLE Binding,
     void **SecurityContextHandle
    );


__declspec(dllimport)
RPC_STATUS

I_RpcBindingInqSecurityContextKeyInfo (
     RPC_BINDING_HANDLE Binding,
     void *KeyInfo
    );


__declspec(dllimport)
RPC_STATUS

I_RpcBindingInqWireIdForSnego (
     RPC_BINDING_HANDLE Binding,
     RPC_CSTR WireId
    );


__declspec(dllimport)
RPC_STATUS

I_RpcBindingInqMarshalledTargetInfo (
     RPC_BINDING_HANDLE Binding,
     unsigned long * MarshalledTargetInfoSize,
     RPC_CSTR * MarshalledTargetInfo
    );



__declspec(dllimport)
RPC_STATUS

I_RpcBindingInqLocalClientPID (
     RPC_BINDING_HANDLE Binding,
     unsigned long *Pid
    );

__declspec(dllimport)
RPC_STATUS

I_RpcBindingHandleToAsyncHandle (
     RPC_BINDING_HANDLE Binding,
     void **AsyncHandle
    );




__declspec(dllimport)
RPC_STATUS

I_RpcNsBindingSetEntryNameW (
     RPC_BINDING_HANDLE Binding,
     unsigned long EntryNameSyntax,
     RPC_WSTR EntryName
    );

__declspec(dllimport)
RPC_STATUS

I_RpcNsBindingSetEntryNameA (
     RPC_BINDING_HANDLE Binding,
     unsigned long EntryNameSyntax,
     RPC_CSTR EntryName
    );

__declspec(dllimport)
RPC_STATUS

I_RpcServerUseProtseqEp2A (
     RPC_CSTR NetworkAddress,
     RPC_CSTR Protseq,
     unsigned int MaxCalls,
     RPC_CSTR Endpoint,
     void   * SecurityDescriptor,
     void * Policy
    );

__declspec(dllimport)
RPC_STATUS

I_RpcServerUseProtseqEp2W (
     RPC_WSTR NetworkAddress,
     RPC_WSTR Protseq,
     unsigned int MaxCalls,
     RPC_WSTR Endpoint,
     void   * SecurityDescriptor,
     void * Policy
    );

__declspec(dllimport)
RPC_STATUS

I_RpcServerUseProtseq2W (
     RPC_WSTR NetworkAddress,
     RPC_WSTR Protseq,
     unsigned int MaxCalls,
     void   * SecurityDescriptor,
     void * Policy
    );

__declspec(dllimport)
RPC_STATUS

I_RpcServerUseProtseq2A (
     RPC_CSTR NetworkAddress,
     RPC_CSTR Protseq,
     unsigned int MaxCalls,
     void   * SecurityDescriptor,
     void * Policy
    );
__declspec(dllimport)
RPC_STATUS

I_RpcServerStartService (
     RPC_WSTR Protseq,
     RPC_WSTR Endpoint,
     RPC_IF_HANDLE IfSpec
    );



__declspec(dllimport)
RPC_STATUS

I_RpcBindingInqDynamicEndpointW (
     RPC_BINDING_HANDLE Binding,
     RPC_WSTR   *DynamicEndpoint
    );

__declspec(dllimport)
RPC_STATUS

I_RpcBindingInqDynamicEndpointA (
     RPC_BINDING_HANDLE Binding,
     RPC_CSTR   *DynamicEndpoint
    );
__declspec(dllimport)
RPC_STATUS

I_RpcServerCheckClientRestriction (
     RPC_BINDING_HANDLE Context
    );







__declspec(dllimport)
RPC_STATUS

I_RpcBindingInqTransportType (
     RPC_BINDING_HANDLE Binding,
     unsigned int   * Type
    );

typedef struct _RPC_TRANSFER_SYNTAX
{
    UUID Uuid;
    unsigned short VersMajor;
    unsigned short VersMinor;
} RPC_TRANSFER_SYNTAX;

__declspec(dllimport)
RPC_STATUS

I_RpcIfInqTransferSyntaxes (
     RPC_IF_HANDLE RpcIfHandle,
     RPC_TRANSFER_SYNTAX   * TransferSyntaxes,
     unsigned int TransferSyntaxSize,
     unsigned int   * TransferSyntaxCount
    );

__declspec(dllimport)
RPC_STATUS

I_UuidCreate (
     UUID   * Uuid
    );

__declspec(dllimport)
RPC_STATUS

I_RpcBindingCopy (
     RPC_BINDING_HANDLE SourceBinding,
     RPC_BINDING_HANDLE   * DestinationBinding
    );

__declspec(dllimport)
RPC_STATUS

I_RpcBindingIsClientLocal (
       RPC_BINDING_HANDLE BindingHandle,
     unsigned int   * ClientLocalFlag
    );

__declspec(dllimport)
RPC_STATUS

I_RpcBindingInqConnId (
     RPC_BINDING_HANDLE Binding,
     void **ConnId,
     int *pfFirstCall
    );

__declspec(dllimport)
RPC_STATUS

I_RpcBindingCreateNP (
     RPC_WSTR ServerName,
     RPC_WSTR ServiceName,
     RPC_WSTR NetworkOptions,
     RPC_BINDING_HANDLE *Binding
    );

__declspec(dllimport)
void

I_RpcSsDontSerializeContext (
    void
    );

__declspec(dllimport)
RPC_STATUS

I_RpcLaunchDatagramReceiveThread(
    void   * pAddress
    );

__declspec(dllimport)
RPC_STATUS

I_RpcServerRegisterForwardFunction (
     RPC_FORWARD_FUNCTION * pForwardFunction
    );

RPC_ADDRESS_CHANGE_FN *
I_RpcServerInqAddressChangeFn(
    void
    );

RPC_STATUS
I_RpcServerSetAddressChangeFn(
     RPC_ADDRESS_CHANGE_FN * pAddressChangeFn
    );








__declspec(dllimport)
RPC_STATUS

I_RpcServerInqLocalConnAddress (
     RPC_BINDING_HANDLE Binding,
       void *Buffer,
       unsigned long *BufferSize,
     unsigned long *AddressFormat
    );

__declspec(dllimport)
RPC_STATUS

I_RpcServerInqRemoteConnAddress (
     RPC_BINDING_HANDLE Binding,
       void *Buffer,
       unsigned long *BufferSize,
     unsigned long *AddressFormat
    );

__declspec(dllimport)
void

I_RpcSessionStrictContextHandle (
    void
    );

__declspec(dllimport)
RPC_STATUS

I_RpcTurnOnEEInfoPropagation (
    void
    );


__declspec(dllimport)
RPC_STATUS

I_RpcConnectionInqSockBuffSize(
   unsigned long   * RecvBuffSize,
   unsigned long   * SendBuffSize
  );

__declspec(dllimport)
RPC_STATUS

I_RpcConnectionSetSockBuffSize(
    unsigned long RecvBuffSize,
    unsigned long SendBuffSize
   );

typedef
void
(*RPCLT_PDU_FILTER_FUNC) (
     void *Buffer,
     unsigned int BufferLength,
     int fDatagram
    );

typedef
void
(  *RPC_SETFILTER_FUNC) (
     RPCLT_PDU_FILTER_FUNC pfnFilter
    );


__declspec(dllimport)
RPC_STATUS

I_RpcServerStartListening(
    void * hWnd
    );

__declspec(dllimport)
RPC_STATUS

I_RpcServerStopListening(
    void
    );

typedef RPC_STATUS (*RPC_BLOCKING_FN) (
     void * hWnd,
     void * Context,
       void * hSyncEvent
    );

__declspec(dllimport)
RPC_STATUS

I_RpcBindingSetAsync(
     RPC_BINDING_HANDLE Binding,
     RPC_BLOCKING_FN BlockingFn,
     unsigned long ServerTid
    );

__declspec(dllimport)
RPC_STATUS

I_RpcSetThreadParams(
     int fClientFree,
       void *Context,
       void * hWndClient
    );

__declspec(dllimport)
unsigned int

I_RpcWindowProc(
     void * hWnd,
     unsigned int Message,
     unsigned int wParam,
     unsigned long lParam
    );

__declspec(dllimport)
RPC_STATUS

I_RpcServerUnregisterEndpointA (
     RPC_CSTR Protseq,
     RPC_CSTR Endpoint
    );

__declspec(dllimport)
RPC_STATUS

I_RpcServerUnregisterEndpointW (
     RPC_WSTR Protseq,
     RPC_WSTR Endpoint
    );








__declspec(dllimport)
RPC_STATUS

I_RpcServerInqTransportType(
     unsigned int   * Type
    );

__declspec(dllimport)
long

I_RpcMapWin32Status (
     RPC_STATUS Status
    );







typedef struct _RPC_C_OPT_COOKIE_AUTH_DESCRIPTOR
{
    unsigned long BufferSize;
     char *Buffer;
} RPC_C_OPT_COOKIE_AUTH_DESCRIPTOR;

typedef struct _RDR_CALLOUT_STATE
{

    RPC_STATUS LastError;
    void *LastEEInfo;

    RPC_HTTP_REDIRECTOR_STAGE LastCalledStage;


    unsigned short *ServerName;
    unsigned short *ServerPort;
    unsigned short *RemoteUser;
    unsigned short *AuthType;
    unsigned char ResourceTypePresent;
    unsigned char SessionIdPresent;
    unsigned char InterfacePresent;
    UUID ResourceType;
    UUID SessionId;
    RPC_SYNTAX_IDENTIFIER Interface;
    void *CertContext;


} RDR_CALLOUT_STATE;



typedef RPC_STATUS
(  *I_RpcProxyIsValidMachineFn)
        (
         RPC_WSTR Machine,
         RPC_WSTR DotMachine,
         unsigned long PortNumber
        );

typedef RPC_STATUS
(  *I_RpcProxyGetClientAddressFn)
        (
         void *Context,
         char *Buffer,
         unsigned long *BufferLength
        );

typedef RPC_STATUS
(  *I_RpcProxyGetConnectionTimeoutFn)
        (
         unsigned long *ConnectionTimeout
        );


typedef RPC_STATUS
(  *I_RpcPerformCalloutFn)
    (
     void *Context,
     RDR_CALLOUT_STATE *CallOutState,
     RPC_HTTP_REDIRECTOR_STAGE Stage
    );

typedef void
(  *I_RpcFreeCalloutStateFn)
    (
     RDR_CALLOUT_STATE *CallOutState
    );

typedef RPC_STATUS
(  *I_RpcProxyGetClientSessionAndResourceUUID)
        (
         void *Context,
         int *SessionIdPresent,
         UUID *SessionId,
         int *ResourceIdPresent,
         UUID *ResourceId
        );




typedef RPC_STATUS
(  *I_RpcProxyFilterIfFn)
    (
     void *Context,
     UUID *IfUuid,
     unsigned short IfMajorVersion,
     int *fAllow
    );

typedef enum RpcProxyPerfCounters
{
    RpcCurrentUniqueUser = 1,
    RpcBackEndConnectionAttempts,
    RpcBackEndConnectionFailed,
    RpcRequestsPerSecond,
    RpcIncomingConnections,
    RpcIncomingBandwidth,
    RpcOutgoingBandwidth,
    RpcAttemptedLbsDecisions,
    RpcFailedLbsDecisions,
    RpcAttemptedLbsMessages,
    RpcFailedLbsMessages,
    RpcLastCounter
} RpcPerfCounters;

typedef void
(  *I_RpcProxyUpdatePerfCounterFn)
    (
     RpcPerfCounters Counter,
     int ModifyTrend,
     unsigned long Size
    );

 typedef void
(  *I_RpcProxyUpdatePerfCounterBackendServerFn)
    (
     unsigned short* MachineName,
     int IsConnectEvent
    );







typedef struct tagI_RpcProxyCallbackInterface
{
    I_RpcProxyIsValidMachineFn IsValidMachineFn;
    I_RpcProxyGetClientAddressFn GetClientAddressFn;
    I_RpcProxyGetConnectionTimeoutFn GetConnectionTimeoutFn;
    I_RpcPerformCalloutFn PerformCalloutFn;
    I_RpcFreeCalloutStateFn FreeCalloutStateFn;
    I_RpcProxyGetClientSessionAndResourceUUID GetClientSessionAndResourceUUIDFn;

    I_RpcProxyFilterIfFn ProxyFilterIfFn;
    I_RpcProxyUpdatePerfCounterFn RpcProxyUpdatePerfCounterFn;
    I_RpcProxyUpdatePerfCounterBackendServerFn RpcProxyUpdatePerfCounterBackendServerFn;

} I_RpcProxyCallbackInterface;

__declspec(dllimport)
RPC_STATUS

I_RpcProxyNewConnection (
     unsigned long ConnectionType,
     unsigned short *ServerAddress,
     unsigned short *ServerPort,
     unsigned short *MinConnTimeout,
     void *ConnectionParameter,
       RDR_CALLOUT_STATE *CallOutState,
     I_RpcProxyCallbackInterface *ProxyCallbackInterface
    );
__declspec(dllimport)
RPC_STATUS

I_RpcReplyToClientWithStatus (
     void *ConnectionParameter,
     RPC_STATUS RpcStatus
    );

__declspec(dllimport)
void

I_RpcRecordCalloutFailure (
     RPC_STATUS RpcStatus,
     RDR_CALLOUT_STATE *CallOutState,
     unsigned short *DllName
    );
typedef void   * RPC_NS_HANDLE;
__declspec(dllimport)  RPC_STATUS
RpcNsBindingExportA(
     unsigned long EntryNameSyntax,
     RPC_CSTR EntryName,
     RPC_IF_HANDLE IfSpec,
     RPC_BINDING_VECTOR   *BindingVec,
     UUID_VECTOR   *ObjectUuidVec
    );


__declspec(dllimport)  RPC_STATUS
RpcNsBindingUnexportA(
     unsigned long EntryNameSyntax,
     RPC_CSTR EntryName,
     RPC_IF_HANDLE IfSpec,
     UUID_VECTOR   *ObjectUuidVec
    );



__declspec(dllimport)  RPC_STATUS
RpcNsBindingExportW(
     unsigned long EntryNameSyntax,
     RPC_WSTR EntryName,
     RPC_IF_HANDLE IfSpec,
     RPC_BINDING_VECTOR   *BindingVec,
     UUID_VECTOR   *ObjectUuidVec
    );

__declspec(dllimport)  RPC_STATUS
RpcNsBindingUnexportW(
     unsigned long EntryNameSyntax,
     RPC_WSTR EntryName,
     RPC_IF_HANDLE IfSpec,
     UUID_VECTOR   *ObjectUuidVec
    );





RPC_STATUS
RpcNsBindingExportPnPA(
     unsigned long EntryNameSyntax,
     RPC_CSTR EntryName,
     RPC_IF_HANDLE IfSpec,
     UUID_VECTOR *ObjectVector
    );

RPC_STATUS
RpcNsBindingUnexportPnPA(
     unsigned long EntryNameSyntax,
     RPC_CSTR EntryName,
     RPC_IF_HANDLE IfSpec,
     UUID_VECTOR *ObjectVector
    );



RPC_STATUS
RpcNsBindingExportPnPW(
     unsigned long EntryNameSyntax,
     RPC_WSTR EntryName,
     RPC_IF_HANDLE IfSpec,
     UUID_VECTOR *ObjectVector
    );

RPC_STATUS
RpcNsBindingUnexportPnPW(
     unsigned long EntryNameSyntax,
     RPC_WSTR EntryName,
     RPC_IF_HANDLE IfSpec,
     UUID_VECTOR *ObjectVector
    );





__declspec(dllimport)  RPC_STATUS
RpcNsBindingLookupBeginA(
     unsigned long EntryNameSyntax,
     RPC_CSTR EntryName,
     RPC_IF_HANDLE IfSpec,
     UUID   *ObjUuid,
     unsigned long BindingMaxCount,
     RPC_NS_HANDLE   *LookupContext
    );



__declspec(dllimport)  RPC_STATUS
RpcNsBindingLookupBeginW(
     unsigned long EntryNameSyntax,
     RPC_WSTR EntryName,
     RPC_IF_HANDLE IfSpec,
     UUID   *ObjUuid,
     unsigned long BindingMaxCount,
     RPC_NS_HANDLE   *LookupContext
    );


__declspec(dllimport)  RPC_STATUS
RpcNsBindingLookupNext(
     RPC_NS_HANDLE LookupContext,
     RPC_BINDING_VECTOR   *   * BindingVec
    );

__declspec(dllimport)  RPC_STATUS
RpcNsBindingLookupDone(
       RPC_NS_HANDLE   * LookupContext
    );



__declspec(dllimport)  RPC_STATUS
RpcNsGroupDeleteA(
     unsigned long GroupNameSyntax,
     RPC_CSTR GroupName
    );

__declspec(dllimport)  RPC_STATUS
RpcNsGroupMbrAddA(
     unsigned long GroupNameSyntax,
     RPC_CSTR GroupName,
     unsigned long MemberNameSyntax,
     RPC_CSTR MemberName
    );

__declspec(dllimport)  RPC_STATUS
RpcNsGroupMbrRemoveA(
     unsigned long GroupNameSyntax,
     RPC_CSTR GroupName,
     unsigned long MemberNameSyntax,
     RPC_CSTR MemberName
    );

__declspec(dllimport)  RPC_STATUS
RpcNsGroupMbrInqBeginA(
     unsigned long GroupNameSyntax,
     RPC_CSTR GroupName,
     unsigned long MemberNameSyntax,
     RPC_NS_HANDLE   *InquiryContext
    );

__declspec(dllimport)  RPC_STATUS
RpcNsGroupMbrInqNextA(
     RPC_NS_HANDLE InquiryContext,
     RPC_CSTR   *MemberName
    );



__declspec(dllimport)  RPC_STATUS
RpcNsGroupDeleteW(
     unsigned long GroupNameSyntax,
     RPC_WSTR GroupName
    );

__declspec(dllimport)  RPC_STATUS
RpcNsGroupMbrAddW(
     unsigned long GroupNameSyntax,
     RPC_WSTR GroupName,
     unsigned long MemberNameSyntax,
     RPC_WSTR MemberName
    );

__declspec(dllimport)  RPC_STATUS
RpcNsGroupMbrRemoveW(
     unsigned long GroupNameSyntax,
     RPC_WSTR GroupName,
     unsigned long MemberNameSyntax,
     RPC_WSTR MemberName
    );

__declspec(dllimport)  RPC_STATUS
RpcNsGroupMbrInqBeginW(
     unsigned long GroupNameSyntax,
     RPC_WSTR GroupName,
     unsigned long MemberNameSyntax,
     RPC_NS_HANDLE   *InquiryContext
    );

__declspec(dllimport)  RPC_STATUS
RpcNsGroupMbrInqNextW(
     RPC_NS_HANDLE InquiryContext,
     RPC_WSTR   *MemberName
    );



__declspec(dllimport)  RPC_STATUS
RpcNsGroupMbrInqDone(
       RPC_NS_HANDLE   * InquiryContext
    );



__declspec(dllimport)  RPC_STATUS
RpcNsProfileDeleteA(
     unsigned long ProfileNameSyntax,
     RPC_CSTR ProfileName
    );

__declspec(dllimport)  RPC_STATUS
RpcNsProfileEltAddA(
     unsigned long ProfileNameSyntax,
     RPC_CSTR ProfileName,
     RPC_IF_ID   *IfId,
     unsigned long MemberNameSyntax,
     RPC_CSTR MemberName,
     unsigned long Priority,
     RPC_CSTR Annotation
    );

__declspec(dllimport)  RPC_STATUS
RpcNsProfileEltRemoveA(
     unsigned long ProfileNameSyntax,
     RPC_CSTR ProfileName,
     RPC_IF_ID   *IfId,
     unsigned long MemberNameSyntax,
     RPC_CSTR MemberName
    );

__declspec(dllimport)  RPC_STATUS
RpcNsProfileEltInqBeginA(
     unsigned long ProfileNameSyntax,
     RPC_CSTR ProfileName,
     unsigned long InquiryType,
     RPC_IF_ID   *IfId,
     unsigned long VersOption,
     unsigned long MemberNameSyntax,
     RPC_CSTR MemberName,
     RPC_NS_HANDLE   *InquiryContext
    );

__declspec(dllimport)  RPC_STATUS
RpcNsProfileEltInqNextA(
     RPC_NS_HANDLE InquiryContext,
     RPC_IF_ID   *IfId,
     RPC_CSTR   *MemberName,
     unsigned long   *Priority,
     RPC_CSTR   *Annotation
    );



__declspec(dllimport)  RPC_STATUS
RpcNsProfileDeleteW(
     unsigned long ProfileNameSyntax,
     RPC_WSTR ProfileName
    );

__declspec(dllimport)  RPC_STATUS
RpcNsProfileEltAddW(
     unsigned long ProfileNameSyntax,
     RPC_WSTR ProfileName,
     RPC_IF_ID   *IfId,
     unsigned long MemberNameSyntax,
     RPC_WSTR MemberName,
     unsigned long Priority,
     RPC_WSTR Annotation
    );

__declspec(dllimport)  RPC_STATUS
RpcNsProfileEltRemoveW(
     unsigned long ProfileNameSyntax,
     RPC_WSTR ProfileName,
     RPC_IF_ID   *IfId,
     unsigned long MemberNameSyntax,
     RPC_WSTR MemberName
    );

__declspec(dllimport)  RPC_STATUS
RpcNsProfileEltInqBeginW(
     unsigned long ProfileNameSyntax,
     RPC_WSTR ProfileName,
     unsigned long InquiryType,
     RPC_IF_ID   *IfId,
     unsigned long VersOption,
     unsigned long MemberNameSyntax,
     RPC_WSTR MemberName,
     RPC_NS_HANDLE   *InquiryContext
    );

__declspec(dllimport)  RPC_STATUS
RpcNsProfileEltInqNextW(
     RPC_NS_HANDLE InquiryContext,
     RPC_IF_ID   *IfId,
     RPC_WSTR   *MemberName,
     unsigned long   *Priority,
     RPC_WSTR   *Annotation
    );



__declspec(dllimport)  RPC_STATUS
RpcNsProfileEltInqDone(
       RPC_NS_HANDLE   * InquiryContext
    );



__declspec(dllimport)  RPC_STATUS
RpcNsEntryObjectInqBeginA(
     unsigned long EntryNameSyntax,
     RPC_CSTR EntryName,
     RPC_NS_HANDLE   *InquiryContext
    );



__declspec(dllimport)  RPC_STATUS
RpcNsEntryObjectInqBeginW(
     unsigned long EntryNameSyntax,
     RPC_WSTR EntryName,
     RPC_NS_HANDLE   *InquiryContext
    );



__declspec(dllimport)  RPC_STATUS
RpcNsEntryObjectInqNext(
     RPC_NS_HANDLE InquiryContext,
     UUID   * ObjUuid
    );

__declspec(dllimport)  RPC_STATUS
RpcNsEntryObjectInqDone(
       RPC_NS_HANDLE   * InquiryContext
    );



__declspec(dllimport)  RPC_STATUS
RpcNsEntryExpandNameA(
     unsigned long EntryNameSyntax,
     RPC_CSTR EntryName,
     RPC_CSTR   *ExpandedName
    );

__declspec(dllimport)  RPC_STATUS
RpcNsMgmtBindingUnexportA(
     unsigned long EntryNameSyntax,
     RPC_CSTR EntryName,
     RPC_IF_ID   *IfId,
     unsigned long VersOption,
     UUID_VECTOR   *ObjectUuidVec
    );

__declspec(dllimport)  RPC_STATUS
RpcNsMgmtEntryCreateA(
     unsigned long EntryNameSyntax,
     RPC_CSTR EntryName
    );

__declspec(dllimport)  RPC_STATUS
RpcNsMgmtEntryDeleteA(
     unsigned long EntryNameSyntax,
     RPC_CSTR EntryName
    );

__declspec(dllimport)  RPC_STATUS
RpcNsMgmtEntryInqIfIdsA(
     unsigned long EntryNameSyntax,
     RPC_CSTR EntryName,
     RPC_IF_ID_VECTOR   *   *IfIdVec
    );

__declspec(dllimport)  RPC_STATUS
RpcNsMgmtHandleSetExpAge(
     RPC_NS_HANDLE NsHandle,
     unsigned long ExpirationAge
    );

__declspec(dllimport)  RPC_STATUS
RpcNsMgmtInqExpAge(
     unsigned long   * ExpirationAge
    );

__declspec(dllimport)  RPC_STATUS
RpcNsMgmtSetExpAge(
     unsigned long ExpirationAge
    );



__declspec(dllimport)  RPC_STATUS
RpcNsEntryExpandNameW(
     unsigned long EntryNameSyntax,
     RPC_WSTR EntryName,
     RPC_WSTR   *ExpandedName
    );

__declspec(dllimport)  RPC_STATUS
RpcNsMgmtBindingUnexportW(
     unsigned long EntryNameSyntax,
     RPC_WSTR EntryName,
     RPC_IF_ID   *IfId,
     unsigned long VersOption,
     UUID_VECTOR   *ObjectUuidVec
    );

__declspec(dllimport)  RPC_STATUS
RpcNsMgmtEntryCreateW(
     unsigned long EntryNameSyntax,
     RPC_WSTR EntryName
    );

__declspec(dllimport)  RPC_STATUS
RpcNsMgmtEntryDeleteW(
     unsigned long EntryNameSyntax,
     RPC_WSTR EntryName
    );

__declspec(dllimport)  RPC_STATUS
RpcNsMgmtEntryInqIfIdsW(
     unsigned long EntryNameSyntax,
     RPC_WSTR EntryName,
     RPC_IF_ID_VECTOR   *   *IfIdVec
    );





__declspec(dllimport)  RPC_STATUS
RpcNsBindingImportBeginA(
     unsigned long EntryNameSyntax,
     RPC_CSTR EntryName,
     RPC_IF_HANDLE IfSpec,
     UUID   *ObjUuid,
     RPC_NS_HANDLE   *ImportContext
    );



__declspec(dllimport)  RPC_STATUS
RpcNsBindingImportBeginW(
     unsigned long EntryNameSyntax,
     RPC_WSTR EntryName,
     RPC_IF_HANDLE IfSpec,
     UUID   *ObjUuid,
     RPC_NS_HANDLE   *ImportContext
    );



__declspec(dllimport)  RPC_STATUS
RpcNsBindingImportNext(
     RPC_NS_HANDLE ImportContext,
     RPC_BINDING_HANDLE   * Binding
    );

__declspec(dllimport)  RPC_STATUS
RpcNsBindingImportDone(
       RPC_NS_HANDLE   * ImportContext
    );

__declspec(dllimport)  RPC_STATUS
RpcNsBindingSelect(
       RPC_BINDING_VECTOR   * BindingVec,
     RPC_BINDING_HANDLE   * Binding
    );
typedef
enum _RPC_NOTIFICATION_TYPES
{
    RpcNotificationTypeNone,
    RpcNotificationTypeEvent,

    RpcNotificationTypeApc,
    RpcNotificationTypeIoc,
    RpcNotificationTypeHwnd,

    RpcNotificationTypeCallback
} RPC_NOTIFICATION_TYPES;


typedef
enum _RPC_ASYNC_EVENT {
    RpcCallComplete,
    RpcSendComplete,
    RpcReceiveComplete,
    RpcClientDisconnect,
    RpcClientCancel
    } RPC_ASYNC_EVENT;
struct _RPC_ASYNC_STATE;

typedef void
RPCNOTIFICATION_ROUTINE (
                  struct _RPC_ASYNC_STATE *pAsync,
                  void *Context,
                  RPC_ASYNC_EVENT Event);
typedef RPCNOTIFICATION_ROUTINE *PFN_RPCNOTIFICATION_ROUTINE;

typedef union _RPC_ASYNC_NOTIFICATION_INFO {




    struct {
        PFN_RPCNOTIFICATION_ROUTINE NotificationRoutine;
        HANDLE hThread;
        } APC;




    struct {
        HANDLE hIOPort;
        DWORD dwNumberOfBytesTransferred;
        DWORD_PTR dwCompletionKey;
        LPOVERLAPPED lpOverlapped;
        } IOC;




    struct {
        HWND hWnd;
        UINT Msg;
        } HWND;







    HANDLE hEvent;
    PFN_RPCNOTIFICATION_ROUTINE NotificationRoutine;
} RPC_ASYNC_NOTIFICATION_INFO, *PRPC_ASYNC_NOTIFICATION_INFO;

typedef struct _RPC_ASYNC_STATE {
    unsigned int Size;
    unsigned long Signature;
    long Lock;
    unsigned long Flags;
    void *StubInfo;
    void *UserInfo;
    void *RuntimeInfo;
    RPC_ASYNC_EVENT Event;

    RPC_NOTIFICATION_TYPES NotificationType;
    RPC_ASYNC_NOTIFICATION_INFO u;

    LONG_PTR Reserved[4];
    } RPC_ASYNC_STATE, *PRPC_ASYNC_STATE;







__declspec(dllimport)
RPC_STATUS

RpcAsyncInitializeHandle (
     PRPC_ASYNC_STATE pAsync,
     unsigned int Size
    );


__declspec(dllimport)
RPC_STATUS

RpcAsyncRegisterInfo (
     PRPC_ASYNC_STATE pAsync
    ) ;


__declspec(dllimport)
RPC_STATUS

RpcAsyncGetCallStatus (
     PRPC_ASYNC_STATE pAsync
    ) ;

__declspec(dllimport)
RPC_STATUS

RpcAsyncCompleteCall (
     PRPC_ASYNC_STATE pAsync,
     void *Reply
    ) ;

__declspec(dllimport)
RPC_STATUS

RpcAsyncAbortCall (
     PRPC_ASYNC_STATE pAsync,
     unsigned long ExceptionCode
    ) ;

__declspec(dllimport)
RPC_STATUS

RpcAsyncCancelCall (
     PRPC_ASYNC_STATE pAsync,
     BOOL fAbort
    ) ;


typedef enum tagExtendedErrorParamTypes
{
    eeptAnsiString = 1,
    eeptUnicodeString,
    eeptLongVal,
    eeptShortVal,
    eeptPointerVal,
    eeptNone,
    eeptBinary
} ExtendedErrorParamTypes;




typedef struct tagBinaryParam
{
    void *Buffer;
    short Size;
} BinaryParam;

typedef struct tagRPC_EE_INFO_PARAM
{
    ExtendedErrorParamTypes ParameterType;
    union
        {
        LPSTR AnsiString;
        LPWSTR UnicodeString;
        long LVal;
        short SVal;
        ULONGLONG PVal;
        BinaryParam BVal;
        } u;
} RPC_EE_INFO_PARAM;










typedef struct tagRPC_EXTENDED_ERROR_INFO
{
    ULONG Version;
    LPWSTR ComputerName;
    ULONG ProcessID;
    union
        {

        SYSTEMTIME SystemTime;
        FILETIME FileTime;
        } u;
    ULONG GeneratingComponent;
    ULONG Status;
    USHORT DetectionLocation;
    USHORT Flags;
    int NumberOfParameters;
    RPC_EE_INFO_PARAM Parameters[ 4 ];
} RPC_EXTENDED_ERROR_INFO;

typedef struct tagRPC_ERROR_ENUM_HANDLE
{
    ULONG Signature;
    void *CurrentPos;
    void *Head;
} RPC_ERROR_ENUM_HANDLE;

__declspec(dllimport)
RPC_STATUS

RpcErrorStartEnumeration (
     RPC_ERROR_ENUM_HANDLE *EnumHandle
    );

__declspec(dllimport)
RPC_STATUS

RpcErrorGetNextRecord (
     RPC_ERROR_ENUM_HANDLE *EnumHandle,
     BOOL CopyStrings,
     RPC_EXTENDED_ERROR_INFO *ErrorInfo
    );

__declspec(dllimport)
RPC_STATUS

RpcErrorEndEnumeration (
     RPC_ERROR_ENUM_HANDLE *EnumHandle
    );

__declspec(dllimport)
RPC_STATUS

RpcErrorResetEnumeration (
     RPC_ERROR_ENUM_HANDLE *EnumHandle
    );

__declspec(dllimport)
RPC_STATUS

RpcErrorGetNumberOfRecords (
     RPC_ERROR_ENUM_HANDLE *EnumHandle,
     int *Records
    );

__declspec(dllimport)
RPC_STATUS

RpcErrorSaveErrorInfo (
     RPC_ERROR_ENUM_HANDLE *EnumHandle,
     PVOID *ErrorBlob,
     size_t *BlobSize
    );

__declspec(dllimport)
RPC_STATUS

RpcErrorLoadErrorInfo (
     PVOID ErrorBlob,
     size_t BlobSize,
     RPC_ERROR_ENUM_HANDLE *EnumHandle
    );

__declspec(dllimport)
RPC_STATUS

RpcErrorAddRecord (
     RPC_EXTENDED_ERROR_INFO *ErrorInfo
    );

__declspec(dllimport)
void

RpcErrorClearInformation (
    void
    );



__declspec(dllimport)
RPC_STATUS

RpcAsyncCleanupThread (
     DWORD dwTimeout
    );

__declspec(dllimport)
RPC_STATUS

RpcGetAuthorizationContextForClient (
     RPC_BINDING_HANDLE ClientBinding,
     BOOL ImpersonateOnReturn,
     PVOID Reserved1,
     PLARGE_INTEGER pExpirationTime,
     LUID Reserved2,
     DWORD Reserved3,
     PVOID Reserved4,
     PVOID *pAuthzClientContext
    );

__declspec(dllimport)
RPC_STATUS

RpcFreeAuthorizationContext (
     PVOID *pAuthzClientContext
    );

__declspec(dllimport)
RPC_STATUS

RpcSsContextLockExclusive (
     RPC_BINDING_HANDLE ServerBindingHandle,
     PVOID UserContext
    );

__declspec(dllimport)
RPC_STATUS

RpcSsContextLockShared (
     RPC_BINDING_HANDLE ServerBindingHandle,
     PVOID UserContext
    );


typedef enum tagRpcLocalAddressFormat
{
    rlafInvalid = 0,
    rlafIPv4,
    rlafIPv6
} RpcLocalAddressFormat;

typedef struct _RPC_CALL_LOCAL_ADDRESS_V1
{
    unsigned int Version;
    void *Buffer;
    unsigned long BufferSize;
    RpcLocalAddressFormat AddressFormat;
} RPC_CALL_LOCAL_ADDRESS_V1, *PRPC_CALL_LOCAL_ADDRESS_V1;
typedef struct tagRPC_CALL_ATTRIBUTES_V1_W
{
    unsigned int Version;
    unsigned long Flags;
    unsigned long ServerPrincipalNameBufferLength;
    unsigned short *ServerPrincipalName;
    unsigned long ClientPrincipalNameBufferLength;
    unsigned short *ClientPrincipalName;
    unsigned long AuthenticationLevel;
    unsigned long AuthenticationService;
    BOOL NullSession;
} RPC_CALL_ATTRIBUTES_V1_W;

typedef struct tagRPC_CALL_ATTRIBUTES_V1_A
{
    unsigned int Version;
    unsigned long Flags;
    unsigned long ServerPrincipalNameBufferLength;
    unsigned char *ServerPrincipalName;
    unsigned long ClientPrincipalNameBufferLength;
    unsigned char *ClientPrincipalName;
    unsigned long AuthenticationLevel;
    unsigned long AuthenticationService;
    BOOL NullSession;
} RPC_CALL_ATTRIBUTES_V1_A;






typedef enum tagRpcCallType
{
    rctInvalid = 0,
    rctNormal,
    rctTraining,
    rctGuaranteed
} RpcCallType;

typedef enum tagRpcCallClientLocality
{
    rcclInvalid = 0,
    rcclLocal,
    rcclRemote,
    rcclClientUnknownLocality
} RpcCallClientLocality;


typedef struct tagRPC_CALL_ATTRIBUTES_V2_W
{
    unsigned int Version;
    unsigned long Flags;
    unsigned long ServerPrincipalNameBufferLength;
    unsigned short *ServerPrincipalName;
    unsigned long ClientPrincipalNameBufferLength;
    unsigned short *ClientPrincipalName;
    unsigned long AuthenticationLevel;
    unsigned long AuthenticationService;
    BOOL NullSession;
    BOOL KernelModeCaller;
    unsigned long ProtocolSequence;
    RpcCallClientLocality IsClientLocal;
    HANDLE ClientPID;
    unsigned long CallStatus;
    RpcCallType CallType;
    RPC_CALL_LOCAL_ADDRESS_V1 *CallLocalAddress;
    unsigned short OpNum;
    UUID InterfaceUuid;
} RPC_CALL_ATTRIBUTES_V2_W;

typedef struct tagRPC_CALL_ATTRIBUTES_V2_A
{
    unsigned int Version;
    unsigned long Flags;
    unsigned long ServerPrincipalNameBufferLength;
    unsigned char *ServerPrincipalName;
    unsigned long ClientPrincipalNameBufferLength;
    unsigned char *ClientPrincipalName;
    unsigned long AuthenticationLevel;
    unsigned long AuthenticationService;
    BOOL NullSession;
    BOOL KernelModeCaller;
    unsigned long ProtocolSequence;
    unsigned long IsClientLocal;
    HANDLE ClientPID;
    unsigned long CallStatus;
    RpcCallType CallType;
    RPC_CALL_LOCAL_ADDRESS_V1 *CallLocalAddress;
    unsigned short OpNum;
    UUID InterfaceUuid;
} RPC_CALL_ATTRIBUTES_V2_A;


__declspec(dllimport)
RPC_STATUS

RpcServerInqCallAttributesW (
     RPC_BINDING_HANDLE ClientBinding,
     void *RpcCallAttributes
    );

__declspec(dllimport)
RPC_STATUS

RpcServerInqCallAttributesA (
     RPC_BINDING_HANDLE ClientBinding,
     void *RpcCallAttributes
    );
typedef  RPC_CALL_ATTRIBUTES_V2_A  RPC_CALL_ATTRIBUTES;
typedef enum _RPC_NOTIFICATIONS
{
    RpcNotificationCallNone = 0,
    RpcNotificationClientDisconnect = 1,
    RpcNotificationCallCancel = 2
} RPC_NOTIFICATIONS;



__declspec(dllimport)
RPC_STATUS

RpcServerSubscribeForNotification (
     RPC_BINDING_HANDLE Binding,
     RPC_NOTIFICATIONS Notification,
     RPC_NOTIFICATION_TYPES NotificationType,
     RPC_ASYNC_NOTIFICATION_INFO *NotificationInfo
    );

__declspec(dllimport)
RPC_STATUS

RpcServerUnsubscribeForNotification (
     RPC_BINDING_HANDLE Binding,
     RPC_NOTIFICATIONS Notification,
     unsigned long *NotificationsQueued
    );





__declspec(dllimport)
RPC_STATUS

RpcBindingBind (
     PRPC_ASYNC_STATE pAsync,
     RPC_BINDING_HANDLE Binding,
     RPC_IF_HANDLE IfSpec
    );

__declspec(dllimport)
RPC_STATUS

RpcBindingUnbind (
     RPC_BINDING_HANDLE Binding
    );



__declspec(dllimport)
RPC_STATUS

RpcDiagnoseError (
     RPC_BINDING_HANDLE BindingHandle,
     RPC_IF_HANDLE IfSpec,
     RPC_STATUS RpcStatus,
     RPC_ERROR_ENUM_HANDLE *EnumHandle,
     ULONG Options,
     HWND ParentWindow
    );






RPC_STATUS
I_RpcAsyncSetHandle (
     PRPC_MESSAGE Message,
     PRPC_ASYNC_STATE pAsync
    );

RPC_STATUS
I_RpcAsyncAbortCall (
     PRPC_ASYNC_STATE pAsync,
     unsigned long ExceptionCode
    ) ;


int

I_RpcExceptionFilter (
     unsigned long ExceptionCode
    );
struct HDROP__ {int unused;}; typedef struct HDROP__ *HDROP ;

extern __declspec(dllimport) UINT __stdcall  DragQueryFileA(HDROP hDrop, UINT iFile,        LPSTR lpszFile, UINT cch);
extern __declspec(dllimport) UINT __stdcall  DragQueryFileW(HDROP hDrop, UINT iFile,        LPWSTR lpszFile, UINT cch);





extern __declspec(dllimport) BOOL __stdcall  DragQueryPoint(HDROP hDrop,     LPPOINT lppt);
extern __declspec(dllimport) void __stdcall  DragFinish(     HDROP hDrop);
extern __declspec(dllimport) void __stdcall  DragAcceptFiles(     HWND hWnd,      BOOL fAccept);

extern __declspec(dllimport) HINSTANCE __stdcall  ShellExecuteA(HWND hwnd, LPCSTR lpOperation, LPCSTR lpFile, LPCSTR lpParameters,
    LPCSTR lpDirectory, INT nShowCmd);
extern __declspec(dllimport) HINSTANCE __stdcall  ShellExecuteW(HWND hwnd, LPCWSTR lpOperation, LPCWSTR lpFile, LPCWSTR lpParameters,
    LPCWSTR lpDirectory, INT nShowCmd);





extern __declspec(dllimport) HINSTANCE __stdcall  FindExecutableA(LPCSTR lpFile, LPCSTR lpDirectory,      LPSTR lpResult);
extern __declspec(dllimport) HINSTANCE __stdcall  FindExecutableW(LPCWSTR lpFile, LPCWSTR lpDirectory,      LPWSTR lpResult);





extern __declspec(dllimport) LPWSTR * __stdcall  CommandLineToArgvW(LPCWSTR lpCmdLine,      int* pNumArgs);

extern __declspec(dllimport) INT __stdcall  ShellAboutA(HWND hWnd, LPCSTR szApp, LPCSTR szOtherStuff, HICON hIcon);
extern __declspec(dllimport) INT __stdcall  ShellAboutW(HWND hWnd, LPCWSTR szApp, LPCWSTR szOtherStuff, HICON hIcon);





extern __declspec(dllimport) HICON __stdcall  DuplicateIcon(HINSTANCE hInst, HICON hIcon);
extern __declspec(dllimport) HICON __stdcall  ExtractAssociatedIconA(HINSTANCE hInst,        LPSTR lpIconPath,      LPWORD lpiIcon);
extern __declspec(dllimport) HICON __stdcall  ExtractAssociatedIconW(HINSTANCE hInst,        LPWSTR lpIconPath,      LPWORD lpiIcon);





extern __declspec(dllimport) HICON __stdcall  ExtractAssociatedIconExA(HINSTANCE hInst,        LPSTR lpIconPath,      LPWORD lpiIconIndex,      LPWORD lpiIconId);
extern __declspec(dllimport) HICON __stdcall  ExtractAssociatedIconExW(HINSTANCE hInst,        LPWSTR lpIconPath,      LPWORD lpiIconIndex,      LPWORD lpiIconId);





extern __declspec(dllimport) HICON __stdcall  ExtractIconA(HINSTANCE hInst, LPCSTR lpszExeFileName, UINT nIconIndex);
extern __declspec(dllimport) HICON __stdcall  ExtractIconW(HINSTANCE hInst, LPCWSTR lpszExeFileName, UINT nIconIndex);








typedef struct _DRAGINFOA {
    UINT uSize;
    POINT pt;
    BOOL fNC;
    LPSTR lpFileList;
    DWORD grfKeyState;
} DRAGINFOA, *LPDRAGINFOA;
typedef struct _DRAGINFOW {
    UINT uSize;
    POINT pt;
    BOOL fNC;
    LPWSTR lpFileList;
    DWORD grfKeyState;
} DRAGINFOW, *LPDRAGINFOW;




typedef DRAGINFOA DRAGINFO;
typedef LPDRAGINFOA LPDRAGINFO;
typedef struct _AppBarData
{
    DWORD cbSize;
    HWND hWnd;
    UINT uCallbackMessage;
    UINT uEdge;
    RECT rc;
    LPARAM lParam;
} APPBARDATA, *PAPPBARDATA;


extern __declspec(dllimport) UINT_PTR __stdcall  SHAppBarMessage(DWORD dwMessage,      PAPPBARDATA pData);





extern __declspec(dllimport) DWORD __stdcall  DoEnvironmentSubstA(       LPSTR szString, UINT cchString);
extern __declspec(dllimport) DWORD __stdcall  DoEnvironmentSubstW(       LPWSTR szString, UINT cchString);







extern __declspec(dllimport) UINT __stdcall  ExtractIconExA(LPCSTR lpszFile, int nIconIndex,        HICON *phiconLarge,        HICON *phiconSmall, UINT nIcons);
extern __declspec(dllimport) UINT __stdcall  ExtractIconExW(LPCWSTR lpszFile, int nIconIndex,        HICON *phiconLarge,        HICON *phiconSmall, UINT nIcons);
typedef WORD FILEOP_FLAGS;
typedef WORD PRINTEROP_FLAGS;








typedef struct _SHFILEOPSTRUCTA
{
    HWND hwnd;
    UINT wFunc;
    LPCSTR pFrom;
    LPCSTR pTo;
    FILEOP_FLAGS fFlags;
    BOOL fAnyOperationsAborted;
    LPVOID hNameMappings;
    LPCSTR lpszProgressTitle;
} SHFILEOPSTRUCTA, *LPSHFILEOPSTRUCTA;
typedef struct _SHFILEOPSTRUCTW
{
    HWND hwnd;
    UINT wFunc;
    LPCWSTR pFrom;
    LPCWSTR pTo;
    FILEOP_FLAGS fFlags;
    BOOL fAnyOperationsAborted;
    LPVOID hNameMappings;
    LPCWSTR lpszProgressTitle;
} SHFILEOPSTRUCTW, *LPSHFILEOPSTRUCTW;




typedef SHFILEOPSTRUCTA SHFILEOPSTRUCT;
typedef LPSHFILEOPSTRUCTA LPSHFILEOPSTRUCT;


extern __declspec(dllimport) int __stdcall  SHFileOperationA(     LPSHFILEOPSTRUCTA lpFileOp);
extern __declspec(dllimport) int __stdcall  SHFileOperationW(     LPSHFILEOPSTRUCTW lpFileOp);





extern __declspec(dllimport) void __stdcall  SHFreeNameMappings(HANDLE hNameMappings);

typedef struct _SHNAMEMAPPINGA
{
    LPSTR pszOldPath;
    LPSTR pszNewPath;
    int cchOldPath;
    int cchNewPath;
} SHNAMEMAPPINGA, *LPSHNAMEMAPPINGA;
typedef struct _SHNAMEMAPPINGW
{
    LPWSTR pszOldPath;
    LPWSTR pszNewPath;
    int cchOldPath;
    int cchNewPath;
} SHNAMEMAPPINGW, *LPSHNAMEMAPPINGW;




typedef SHNAMEMAPPINGA SHNAMEMAPPING;
typedef LPSHNAMEMAPPINGA LPSHNAMEMAPPING;
typedef struct _SHELLEXECUTEINFOA
{
        DWORD cbSize;
        ULONG fMask;
        HWND hwnd;
        LPCSTR lpVerb;
        LPCSTR lpFile;
        LPCSTR lpParameters;
        LPCSTR lpDirectory;
        int nShow;
        HINSTANCE hInstApp;

        LPVOID lpIDList;
        LPCSTR lpClass;
        HKEY hkeyClass;
        DWORD dwHotKey;
        union {
        HANDLE hIcon;

        HANDLE hMonitor;

        }  u ;
        HANDLE hProcess;
} SHELLEXECUTEINFOA, *LPSHELLEXECUTEINFOA;
typedef struct _SHELLEXECUTEINFOW
{
        DWORD cbSize;
        ULONG fMask;
        HWND hwnd;
        LPCWSTR lpVerb;
        LPCWSTR lpFile;
        LPCWSTR lpParameters;
        LPCWSTR lpDirectory;
        int nShow;
        HINSTANCE hInstApp;

        LPVOID lpIDList;
        LPCWSTR lpClass;
        HKEY hkeyClass;
        DWORD dwHotKey;
        union {
        HANDLE hIcon;

        HANDLE hMonitor;

        }  u ;
        HANDLE hProcess;
} SHELLEXECUTEINFOW, *LPSHELLEXECUTEINFOW;




typedef SHELLEXECUTEINFOA SHELLEXECUTEINFO;
typedef LPSHELLEXECUTEINFOA LPSHELLEXECUTEINFO;


extern __declspec(dllimport) BOOL __stdcall  ShellExecuteExA(     LPSHELLEXECUTEINFOA lpExecInfo);
extern __declspec(dllimport) BOOL __stdcall  ShellExecuteExW(     LPSHELLEXECUTEINFOW lpExecInfo);









typedef struct _SHCREATEPROCESSINFOW
{
        DWORD cbSize;
        ULONG fMask;
        HWND hwnd;
        LPCWSTR pszFile;
        LPCWSTR pszParameters;
        LPCWSTR pszCurrentDirectory;
        HANDLE hUserToken;
        LPSECURITY_ATTRIBUTES lpProcessAttributes;
        LPSECURITY_ATTRIBUTES lpThreadAttributes;
        BOOL bInheritHandles;
        DWORD dwCreationFlags;
        LPSTARTUPINFOW lpStartupInfo;
        LPPROCESS_INFORMATION lpProcessInformation;
} SHCREATEPROCESSINFOW, *PSHCREATEPROCESSINFOW;

extern __declspec(dllimport) BOOL __stdcall  SHCreateProcessAsUserW(     PSHCREATEPROCESSINFOW pscpi);




extern __declspec(dllimport) HRESULT __stdcall  SHEvaluateSystemCommandTemplate(PCWSTR pszCmdTemplate,      PWSTR *ppszApplication,        PWSTR *ppszCommandLine,        PWSTR *ppszParameters);
typedef enum ASSOCCLASS
{
    ASSOCCLASS_SHELL_KEY = 0,
    ASSOCCLASS_PROGID_KEY,
    ASSOCCLASS_PROGID_STR,
    ASSOCCLASS_CLSID_KEY,
    ASSOCCLASS_CLSID_STR,
    ASSOCCLASS_APP_KEY,
    ASSOCCLASS_APP_STR,
    ASSOCCLASS_SYSTEM_STR,
    ASSOCCLASS_FOLDER,
    ASSOCCLASS_STAR,
} ASSOCCLASS;
typedef struct ASSOCIATIONELEMENT_
{
    ASSOCCLASS ac;
    HKEY hkClass;
    PCWSTR pszClass;
} ASSOCIATIONELEMENT;



extern __declspec(dllimport) HRESULT __stdcall  AssocCreateForClasses(     const ASSOCIATIONELEMENT *rgClasses, ULONG cClasses,  const IID * const  riid,      void **ppv);
typedef struct _SHQUERYRBINFO {
    DWORD cbSize;

    __int64 i64Size;
    __int64 i64NumItems;
} SHQUERYRBINFO, *LPSHQUERYRBINFO;









extern __declspec(dllimport) HRESULT __stdcall  SHQueryRecycleBinA(LPCSTR pszRootPath,      LPSHQUERYRBINFO pSHQueryRBInfo);
extern __declspec(dllimport) HRESULT __stdcall  SHQueryRecycleBinW(LPCWSTR pszRootPath,      LPSHQUERYRBINFO pSHQueryRBInfo);





extern __declspec(dllimport) HRESULT __stdcall  SHEmptyRecycleBinA(HWND hwnd, LPCSTR pszRootPath, DWORD dwFlags);
extern __declspec(dllimport) HRESULT __stdcall  SHEmptyRecycleBinW(HWND hwnd, LPCWSTR pszRootPath, DWORD dwFlags);
typedef enum
{
    QUNS_NOT_PRESENT = 1,
    QUNS_BUSY = 2,
    QUNS_RUNNING_D3D_FULL_SCREEN = 3,
    QUNS_PRESENTATION_MODE = 4,
    QUNS_ACCEPTS_NOTIFICATIONS = 5,
} QUERY_USER_NOTIFICATION_STATE;

extern __declspec(dllimport) HRESULT __stdcall  SHQueryUserNotificationState(     QUERY_USER_NOTIFICATION_STATE *pquns);



typedef struct _NOTIFYICONDATAA {
    DWORD cbSize;
    HWND hWnd;
    UINT uID;
    UINT uFlags;
    UINT uCallbackMessage;
    HICON hIcon;
    CHAR szTip[128];
    DWORD dwState;
    DWORD dwStateMask;
    CHAR szInfo[256];
    union {
        UINT uTimeout;
        UINT uVersion;
    }  u ;
    CHAR szInfoTitle[64];
    DWORD dwInfoFlags;


    GUID guidItem;


    HICON hBalloonIcon;

} NOTIFYICONDATAA, *PNOTIFYICONDATAA;
typedef struct _NOTIFYICONDATAW {
    DWORD cbSize;
    HWND hWnd;
    UINT uID;
    UINT uFlags;
    UINT uCallbackMessage;
    HICON hIcon;
    WCHAR szTip[128];
    DWORD dwState;
    DWORD dwStateMask;
    WCHAR szInfo[256];
    union {
        UINT uTimeout;
        UINT uVersion;
    }  u ;
    WCHAR szInfoTitle[64];
    DWORD dwInfoFlags;


    GUID guidItem;


    HICON hBalloonIcon;

} NOTIFYICONDATAW, *PNOTIFYICONDATAW;




typedef NOTIFYICONDATAA NOTIFYICONDATA;
typedef PNOTIFYICONDATAA PNOTIFYICONDATA;
extern __declspec(dllimport) BOOL __stdcall  Shell_NotifyIconA(DWORD dwMessage,      PNOTIFYICONDATAA lpData);
extern __declspec(dllimport) BOOL __stdcall  Shell_NotifyIconW(DWORD dwMessage,      PNOTIFYICONDATAW lpData);
typedef struct _SHFILEINFOA
{
        HICON hIcon;
        int iIcon;
        DWORD dwAttributes;
        CHAR szDisplayName[ 260 ];
        CHAR szTypeName[80];
} SHFILEINFOA;
typedef struct _SHFILEINFOW
{
        HICON hIcon;
        int iIcon;
        DWORD dwAttributes;
        WCHAR szDisplayName[ 260 ];
        WCHAR szTypeName[80];
} SHFILEINFOW;



typedef SHFILEINFOA SHFILEINFO;
extern __declspec(dllimport) DWORD_PTR __stdcall  SHGetFileInfoA(LPCSTR pszPath, DWORD dwFileAttributes,          SHFILEINFOA *psfi,
    UINT cbFileInfo, UINT uFlags);
extern __declspec(dllimport) DWORD_PTR __stdcall  SHGetFileInfoW(LPCWSTR pszPath, DWORD dwFileAttributes,          SHFILEINFOW *psfi,
    UINT cbFileInfo, UINT uFlags);







typedef struct _SHSTOCKICONINFO
{
    DWORD cbSize;
    HICON hIcon;
    int iSysImageIndex;
    int iIcon;
    WCHAR szPath[ 260 ];
} SHSTOCKICONINFO;
typedef enum SHSTOCKICONID
{
    SIID_DOCNOASSOC = 0,
    SIID_DOCASSOC = 1,
    SIID_APPLICATION = 2,
    SIID_FOLDER = 3,
    SIID_FOLDEROPEN = 4,
    SIID_DRIVE525 = 5,
    SIID_DRIVE35 = 6,
    SIID_DRIVEREMOVE = 7,
    SIID_DRIVEFIXED = 8,
    SIID_DRIVENET = 9,
    SIID_DRIVENETDISABLED = 10,
    SIID_DRIVECD = 11,
    SIID_DRIVERAM = 12,
    SIID_WORLD = 13,
    SIID_SERVER = 15,
    SIID_PRINTER = 16,
    SIID_MYNETWORK = 17,
    SIID_FIND = 22,
    SIID_HELP = 23,
    SIID_SHARE = 28,
    SIID_LINK = 29,
    SIID_SLOWFILE = 30,
    SIID_RECYCLER = 31,
    SIID_RECYCLERFULL = 32,
    SIID_MEDIACDAUDIO = 40,
    SIID_LOCK = 47,
    SIID_AUTOLIST = 49,
    SIID_PRINTERNET = 50,
    SIID_SERVERSHARE = 51,
    SIID_PRINTERFAX = 52,
    SIID_PRINTERFAXNET = 53,
    SIID_PRINTERFILE = 54,
    SIID_STACK = 55,
    SIID_MEDIASVCD = 56,
    SIID_STUFFEDFOLDER = 57,
    SIID_DRIVEUNKNOWN = 58,
    SIID_DRIVEDVD = 59,
    SIID_MEDIADVD = 60,
    SIID_MEDIADVDRAM = 61,
    SIID_MEDIADVDRW = 62,
    SIID_MEDIADVDR = 63,
    SIID_MEDIADVDROM = 64,
    SIID_MEDIACDAUDIOPLUS = 65,
    SIID_MEDIACDRW = 66,
    SIID_MEDIACDR = 67,
    SIID_MEDIACDBURN = 68,
    SIID_MEDIABLANKCD = 69,
    SIID_MEDIACDROM = 70,
    SIID_AUDIOFILES = 71,
    SIID_IMAGEFILES = 72,
    SIID_VIDEOFILES = 73,
    SIID_MIXEDFILES = 74,
    SIID_FOLDERBACK = 75,
    SIID_FOLDERFRONT = 76,
    SIID_SHIELD = 77,
    SIID_WARNING = 78,
    SIID_INFO = 79,
    SIID_ERROR = 80,
    SIID_KEY = 81,
    SIID_SOFTWARE = 82,
    SIID_RENAME = 83,
    SIID_DELETE = 84,
    SIID_MEDIAAUDIODVD = 85,
    SIID_MEDIAMOVIEDVD = 86,
    SIID_MEDIAENHANCEDCD = 87,
    SIID_MEDIAENHANCEDDVD = 88,
    SIID_MEDIAHDDVD = 89,
    SIID_MEDIABLURAY = 90,
    SIID_MEDIAVCD = 91,
    SIID_MEDIADVDPLUSR = 92,
    SIID_MEDIADVDPLUSRW = 93,
    SIID_DESKTOPPC = 94,
    SIID_MOBILEPC = 95,
    SIID_USERS = 96,
    SIID_MEDIASMARTMEDIA = 97,
    SIID_MEDIACOMPACTFLASH = 98,
    SIID_DEVICECELLPHONE = 99,
    SIID_DEVICECAMERA = 100,
    SIID_DEVICEVIDEOCAMERA = 101,
    SIID_DEVICEAUDIOPLAYER = 102,
    SIID_NETWORKCONNECT = 103,
    SIID_INTERNET = 104,
    SIID_ZIPFILE = 105,
    SIID_SETTINGS = 106,


    SIID_DRIVEHDDVD = 132,
    SIID_DRIVEBD = 133,
    SIID_MEDIAHDDVDROM = 134,
    SIID_MEDIAHDDVDR = 135,
    SIID_MEDIAHDDVDRAM = 136,
    SIID_MEDIABDROM = 137,
    SIID_MEDIABDR = 138,
    SIID_MEDIABDRE = 139,
    SIID_CLUSTEREDDRIVE = 140,
    SIID_MAX_ICONS = 141,
} SHSTOCKICONID;




extern __declspec(dllimport) HRESULT __stdcall  SHGetStockIconInfo(SHSTOCKICONID siid, UINT uFlags,      SHSTOCKICONINFO *psii);






extern __declspec(dllimport) BOOL __stdcall  SHGetDiskFreeSpaceExA(LPCSTR pszDirectoryName,        ULARGE_INTEGER* pulFreeBytesAvailableToCaller,
     ULARGE_INTEGER* pulTotalNumberOfBytes,        ULARGE_INTEGER* pulTotalNumberOfFreeBytes);
extern __declspec(dllimport) BOOL __stdcall  SHGetDiskFreeSpaceExW(LPCWSTR pszDirectoryName,        ULARGE_INTEGER* pulFreeBytesAvailableToCaller,
     ULARGE_INTEGER* pulTotalNumberOfBytes,        ULARGE_INTEGER* pulTotalNumberOfFreeBytes);





extern __declspec(dllimport) BOOL __stdcall  SHGetNewLinkInfoA(     LPCSTR pszLinkTo,      LPCSTR pszDir,      LPSTR pszName,      BOOL *pfMustCopy,      UINT uFlags);
extern __declspec(dllimport) BOOL __stdcall  SHGetNewLinkInfoW(     LPCWSTR pszLinkTo,      LPCWSTR pszDir,      LPWSTR pszName,      BOOL *pfMustCopy,      UINT uFlags);
extern __declspec(dllimport) BOOL __stdcall  SHInvokePrinterCommandA(HWND hwnd, UINT uAction, LPCSTR lpBuf1, LPCSTR lpBuf2, BOOL fModal);
extern __declspec(dllimport) BOOL __stdcall  SHInvokePrinterCommandW(HWND hwnd, UINT uAction, LPCWSTR lpBuf1, LPCWSTR lpBuf2, BOOL fModal);








typedef struct _OPEN_PRINTER_PROPS_INFOA
{
    DWORD dwSize;
    LPSTR pszSheetName;
    UINT uSheetIndex;
    DWORD dwFlags;
    BOOL bModal;
} OPEN_PRINTER_PROPS_INFOA, *POPEN_PRINTER_PROPS_INFOA;
typedef struct _OPEN_PRINTER_PROPS_INFOW
{
    DWORD dwSize;
    LPWSTR pszSheetName;
    UINT uSheetIndex;
    DWORD dwFlags;
    BOOL bModal;
} OPEN_PRINTER_PROPS_INFOW, *POPEN_PRINTER_PROPS_INFOW;




typedef OPEN_PRINTER_PROPS_INFOA OPEN_PRINTER_PROPS_INFO;
typedef POPEN_PRINTER_PROPS_INFOA POPEN_PRINTER_PROPS_INFO;
extern __declspec(dllimport) HRESULT __stdcall  SHLoadNonloadedIconOverlayIdentifiers(void);
extern __declspec(dllimport) HRESULT __stdcall  SHIsFileAvailableOffline(     LPCWSTR pwszPath,        LPDWORD pdwStatus);
extern __declspec(dllimport) HRESULT __stdcall  SHSetLocalizedName(LPCWSTR pszPath, LPCWSTR pszResModule, int idsRes);




extern __declspec(dllimport) HRESULT __stdcall  SHRemoveLocalizedName(LPCWSTR pszPath);

extern __declspec(dllimport) HRESULT __stdcall  SHGetLocalizedName(     LPCWSTR pszPath,      LPWSTR pszResModule, UINT cch,      int *pidsRes);
extern __declspec(dllimport) int  ShellMessageBoxA(
     HINSTANCE hAppInst,
     HWND hWnd,
     LPCSTR lpcText,
     LPCSTR lpcTitle,
     UINT fuStyle, ...);
extern __declspec(dllimport) int  ShellMessageBoxW(
     HINSTANCE hAppInst,
     HWND hWnd,
     LPCWSTR lpcText,
     LPCWSTR lpcTitle,
     UINT fuStyle, ...);







extern __declspec(dllimport) BOOL __stdcall  IsLFNDriveA(LPCSTR pszPath);
extern __declspec(dllimport) BOOL __stdcall  IsLFNDriveW(LPCWSTR pszPath);










extern HRESULT __stdcall  SHEnumerateUnreadMailAccountsA(HKEY hKeyUser, DWORD dwIndex,      LPSTR pszMailAddress, int cchMailAddress);
extern HRESULT __stdcall  SHEnumerateUnreadMailAccountsW(HKEY hKeyUser, DWORD dwIndex,      LPWSTR pszMailAddress, int cchMailAddress);





extern HRESULT __stdcall  SHGetUnreadMailCountA(HKEY hKeyUser, LPCSTR pszMailAddress,        DWORD *pdwCount,        FILETIME *pFileTime,        LPSTR pszShellExecuteCommand, int cchShellExecuteCommand);
extern HRESULT __stdcall  SHGetUnreadMailCountW(HKEY hKeyUser, LPCWSTR pszMailAddress,        DWORD *pdwCount,        FILETIME *pFileTime,        LPWSTR pszShellExecuteCommand, int cchShellExecuteCommand);





extern HRESULT __stdcall  SHSetUnreadMailCountA(LPCSTR pszMailAddress, DWORD dwCount, LPCSTR pszShellExecuteCommand);
extern HRESULT __stdcall  SHSetUnreadMailCountW(LPCWSTR pszMailAddress, DWORD dwCount, LPCWSTR pszShellExecuteCommand);









extern BOOL __stdcall  SHTestTokenMembership(       HANDLE hToken,      ULONG ulRID);





extern __declspec(dllimport) HRESULT __stdcall  SHGetImageList(int iImageList,  const IID * const  riid,      void **ppvObj);
typedef HRESULT ( __stdcall  *PFNCANSHAREFOLDERW)(LPCWSTR pszPath);
typedef HRESULT ( __stdcall  *PFNSHOWSHAREFOLDERUIW)(HWND hwndParent, LPCWSTR pszPath);
extern __declspec(dllimport) BOOL __stdcall  InitNetworkAddressControl(void);
typedef struct tagNC_ADDRESS
{
   struct NET_ADDRESS_INFO_ *pAddrInfo;
   USHORT PortNumber;
   BYTE PrefixLength;
} NC_ADDRESS, *PNC_ADDRESS;
extern HRESULT __stdcall  SHGetDriveMedia(LPCWSTR pszDrive,      DWORD *pdwMediaContent);
typedef struct _PERF_DATA_BLOCK {
    WCHAR Signature[4];
    DWORD LittleEndian;
    DWORD Version;

    DWORD Revision;

    DWORD TotalByteLength;
    DWORD HeaderLength;
    DWORD NumObjectTypes;

    LONG DefaultObject;




    SYSTEMTIME SystemTime;

    LARGE_INTEGER PerfTime;

    LARGE_INTEGER PerfFreq;

    LARGE_INTEGER PerfTime100nSec;

    DWORD SystemNameLength;
    DWORD SystemNameOffset;


} PERF_DATA_BLOCK, *PPERF_DATA_BLOCK;









typedef struct _PERF_OBJECT_TYPE {
    DWORD TotalByteLength;







    DWORD DefinitionLength;







    DWORD HeaderLength;



    DWORD ObjectNameTitleIndex;




    LPWSTR ObjectNameTitle;



    DWORD ObjectHelpTitleIndex;




    LPWSTR ObjectHelpTitle;



    DWORD DetailLevel;



    DWORD NumCounters;


    LONG DefaultCounter;



    LONG NumInstances;
    DWORD CodePage;


    LARGE_INTEGER PerfTime;

    LARGE_INTEGER PerfFreq;

} PERF_OBJECT_TYPE, *PPERF_OBJECT_TYPE;
typedef struct _PERF_COUNTER_DEFINITION {
    DWORD ByteLength;
    DWORD CounterNameTitleIndex;





    LPWSTR CounterNameTitle;



    DWORD CounterHelpTitleIndex;





    LPWSTR CounterHelpTitle;



    LONG DefaultScale;


    DWORD DetailLevel;

    DWORD CounterType;
    DWORD CounterSize;
    DWORD CounterOffset;


} PERF_COUNTER_DEFINITION, *PPERF_COUNTER_DEFINITION;
typedef struct _PERF_INSTANCE_DEFINITION {
    DWORD ByteLength;

    DWORD ParentObjectTitleIndex;





    DWORD ParentObjectInstance;



    LONG UniqueID;


    DWORD NameOffset;


    DWORD NameLength;





} PERF_INSTANCE_DEFINITION, *PPERF_INSTANCE_DEFINITION;
typedef struct _PERF_COUNTER_BLOCK {
    DWORD ByteLength;

} PERF_COUNTER_BLOCK, *PPERF_COUNTER_BLOCK;
typedef DWORD (  PM_OPEN_PROC) (       LPWSTR);
typedef DWORD (  PM_COLLECT_PROC) (       LPWSTR, LPVOID *, LPDWORD, LPDWORD);
typedef DWORD (  PM_CLOSE_PROC) (void);
typedef DWORD (  PM_QUERY_PROC) (LPDWORD, LPVOID *, LPDWORD, LPDWORD);
typedef unsigned char u_char;
typedef unsigned short u_short;
typedef unsigned int u_int;
typedef unsigned long u_long;
typedef UINT_PTR SOCKET;
typedef struct fd_set {
        u_int fd_count;
        SOCKET fd_array[ 64 ];
} fd_set;
extern int     __WSAFDIsSet(SOCKET, fd_set   *);
struct timeval {
        long tv_sec;
        long tv_usec;
};
struct hostent {
        char   * h_name;
        char   *   * h_aliases;
        short h_addrtype;
        short h_length;
        char   *   * h_addr_list;

};
struct netent {
        char   * n_name;
        char   *   * n_aliases;
        short n_addrtype;
        u_long n_net;
};

struct servent {
        char   * s_name;
        char   *   * s_aliases;




        short s_port;
        char   * s_proto;

};

struct protoent {
        char   * p_name;
        char   *   * p_aliases;
        short p_proto;
};
typedef struct in_addr {
        union {
                struct { UCHAR s_b1,s_b2,s_b3,s_b4; } S_un_b;
                struct { USHORT s_w1,s_w2; } S_un_w;
                ULONG S_addr;
        } S_un;






} IN_ADDR, *PIN_ADDR,   *LPIN_ADDR;
struct sockaddr_in {
        short sin_family;
        u_short sin_port;
        struct in_addr sin_addr;
        char sin_zero[8];
};




typedef struct WSAData {
        WORD wVersion;
        WORD wHighVersion;







        char szDescription[ 256 +1];
        char szSystemStatus[ 128 +1];
        unsigned short iMaxSockets;
        unsigned short iMaxUdpDg;
        char   * lpVendorInfo;

} WSADATA;

typedef WSADATA   *LPWSADATA;
struct ip_mreq {
        struct in_addr imr_multiaddr;
        struct in_addr imr_interface;
};
struct sockaddr {
        u_short sa_family;
        char sa_data[14];
};
struct sockproto {
        u_short sp_family;
        u_short sp_protocol;
};
struct linger {
        u_short l_onoff;
        u_short l_linger;
};
SOCKET     accept (
                           SOCKET s,
                           struct sockaddr   *addr,
                             int   *addrlen);

int     bind (
                      SOCKET s,
                      const struct sockaddr   *addr,
                      int namelen);

int     closesocket (   SOCKET s);

int     connect (
                         SOCKET s,
                         const struct sockaddr   *name,
                         int namelen);

int     ioctlsocket (
                             SOCKET s,
                             long cmd,
                               u_long   *argp);

int     getpeername (
                             SOCKET s,
                             struct sockaddr   *name,
                               int   * namelen);

int     getsockname (
                             SOCKET s,
                             struct sockaddr   *name,
                               int   * namelen);

int     getsockopt (
                            SOCKET s,
                            int level,
                            int optname,
     char   * optval,
                              int   *optlen);

u_long     htonl (   u_long hostlong);

u_short     htons (  u_short hostshort);

unsigned long     inet_addr (  const char   * cp);

char   *     inet_ntoa (  struct in_addr in);

int     listen (
                        SOCKET s,
                        int backlog);

u_long     ntohl (  u_long netlong);

u_short     ntohs (  u_short netshort);

int     recv (
                      SOCKET s,
       char   * buf,
                      int len,
                      int flags);

int     recvfrom (
                          SOCKET s,
       char   * buf,
                          int len,
                          int flags,
     struct sockaddr   * from,
                            int   * fromlen);

int     select (
                         int nfds,
                           fd_set   *readfds,
                           fd_set   *writefds,
                           fd_set   *exceptfds,
                         const struct timeval   *timeout);

int     send (
                      SOCKET s,
                      const char   * buf,
                      int len,
                      int flags);

int     sendto (
                        SOCKET s,
                        const char   * buf,
                        int len,
                        int flags,
                        const struct sockaddr   *to,
                        int tolen);

int     setsockopt (
                            SOCKET s,
                            int level,
                            int optname,
                            const char   * optval,
                            int optlen);

int     shutdown (
                          SOCKET s,
                          int how);

SOCKET     socket (
                           int af,
                           int type,
                           int protocol);



struct hostent   *     gethostbyaddr(
                                               const char   * addr,
                                               int len,
                                               int type);

struct hostent   *     gethostbyname(  const char   * name);

int     gethostname (
     char   * name,
                             int namelen);

struct servent   *     getservbyport(
                                               int port,
                                               const char   * proto);

struct servent   *     getservbyname(
                                               const char   * name,
                                               const char   * proto);

struct protoent   *     getprotobynumber(  int proto);

struct protoent   *     getprotobyname(  const char   * name);



int     WSAStartup(
                           WORD wVersionRequired,
                           LPWSADATA lpWSAData);

int     WSACleanup(void);

void     WSASetLastError(  int iError);

int     WSAGetLastError(void);

BOOL     WSAIsBlocking(void);

int     WSAUnhookBlockingHook(void);

FARPROC     WSASetBlockingHook(  FARPROC lpBlockFunc);

int     WSACancelBlockingCall(void);

HANDLE     WSAAsyncGetServByName(
                                         HWND hWnd,
                                         u_int wMsg,
                                         const char   * name,
                                         const char   * proto,
     char   * buf,
                                         int buflen);

HANDLE     WSAAsyncGetServByPort(
                                         HWND hWnd,
                                         u_int wMsg,
                                         int port,
                                         const char   * proto,
     char   * buf,
                                         int buflen);

HANDLE     WSAAsyncGetProtoByName(
                                          HWND hWnd,
                                          u_int wMsg,
                                          const char   * name,
     char   * buf,
                                          int buflen);

HANDLE     WSAAsyncGetProtoByNumber(
                                            HWND hWnd,
                                            u_int wMsg,
                                            int number,
     char   * buf,
                                            int buflen);

HANDLE     WSAAsyncGetHostByName(
                                         HWND hWnd,
                                         u_int wMsg,
                                         const char   * name,
     char   * buf,
                                         int buflen);

HANDLE     WSAAsyncGetHostByAddr(
                                         HWND hWnd,
                                         u_int wMsg,
                                         const char   * addr,
                                         int len,
                                         int type,
     char   * buf,
                                         int buflen);

int     WSACancelAsyncRequest(  HANDLE hAsyncTaskHandle);

int     WSAAsyncSelect(
                               SOCKET s,
                               HWND hWnd,
                               u_int wMsg,
                               long lEvent);

int     WSARecvEx (
                           SOCKET s,
       char   * buf,
                           int len,
                             int   *flags);

typedef struct _TRANSMIT_FILE_BUFFERS {
    PVOID Head;
    DWORD HeadLength;
    PVOID Tail;
    DWORD TailLength;
} TRANSMIT_FILE_BUFFERS, *PTRANSMIT_FILE_BUFFERS, *LPTRANSMIT_FILE_BUFFERS;





BOOL

TransmitFile (
     SOCKET hSocket,
     HANDLE hFile,
     DWORD nNumberOfBytesToWrite,
     DWORD nNumberOfBytesPerSend,
     LPOVERLAPPED lpOverlapped,
     LPTRANSMIT_FILE_BUFFERS lpTransmitBuffers,
     DWORD dwReserved
    );

BOOL

AcceptEx (
     SOCKET sListenSocket,
     SOCKET sAcceptSocket,
     PVOID lpOutputBuffer,
     DWORD dwReceiveDataLength,
     DWORD dwLocalAddressLength,
     DWORD dwRemoteAddressLength,
     LPDWORD lpdwBytesReceived,
     LPOVERLAPPED lpOverlapped
    );

void

GetAcceptExSockaddrs (
     PVOID lpOutputBuffer,
     DWORD dwReceiveDataLength,
     DWORD dwLocalAddressLength,
     DWORD dwRemoteAddressLength,
     struct sockaddr **LocalSockaddr,
     LPINT LocalSockaddrLength,
     struct sockaddr **RemoteSockaddr,
     LPINT RemoteSockaddrLength
    );
typedef struct sockaddr SOCKADDR;
typedef struct sockaddr *PSOCKADDR;
typedef struct sockaddr   *LPSOCKADDR;

typedef struct sockaddr_in SOCKADDR_IN;
typedef struct sockaddr_in *PSOCKADDR_IN;
typedef struct sockaddr_in   *LPSOCKADDR_IN;

typedef struct linger LINGER;
typedef struct linger *PLINGER;
typedef struct linger   *LPLINGER;

typedef struct fd_set FD_SET;
typedef struct fd_set *PFD_SET;
typedef struct fd_set   *LPFD_SET;

typedef struct hostent HOSTENT;
typedef struct hostent *PHOSTENT;
typedef struct hostent   *LPHOSTENT;

typedef struct servent SERVENT;
typedef struct servent *PSERVENT;
typedef struct servent   *LPSERVENT;

typedef struct protoent PROTOENT;
typedef struct protoent *PPROTOENT;
typedef struct protoent   *LPPROTOENT;

typedef struct timeval TIMEVAL;
typedef struct timeval *PTIMEVAL;
typedef struct timeval   *LPTIMEVAL;
typedef unsigned int ALG_ID;
typedef ULONG_PTR HCRYPTPROV;
typedef ULONG_PTR HCRYPTKEY;
typedef ULONG_PTR HCRYPTHASH;
typedef struct _CMS_KEY_INFO {
    DWORD dwVersion;
    ALG_ID Algid;
    BYTE *pbOID;
    DWORD cbOID;
} CMS_KEY_INFO, *PCMS_KEY_INFO;


typedef struct _HMAC_Info {
    ALG_ID HashAlgid;
    BYTE *pbInnerString;
    DWORD cbInnerString;
    BYTE *pbOuterString;
    DWORD cbOuterString;
} HMAC_INFO, *PHMAC_INFO;


typedef struct _SCHANNEL_ALG {
    DWORD dwUse;
    ALG_ID Algid;
    DWORD cBits;
    DWORD dwFlags;
    DWORD dwReserved;
} SCHANNEL_ALG, *PSCHANNEL_ALG;








typedef struct _PROV_ENUMALGS {
    ALG_ID aiAlgid;
    DWORD dwBitLen;
    DWORD dwNameLen;
    CHAR szName[20];
} PROV_ENUMALGS;


typedef struct _PROV_ENUMALGS_EX {
    ALG_ID aiAlgid;
    DWORD dwDefaultLen;
    DWORD dwMinLen;
    DWORD dwMaxLen;
    DWORD dwProtocols;
    DWORD dwNameLen;
    CHAR szName[20];
    DWORD dwLongNameLen;
    CHAR szLongName[40];
} PROV_ENUMALGS_EX;


typedef struct _PUBLICKEYSTRUC {
        BYTE bType;
        BYTE bVersion;
        WORD reserved;
        ALG_ID aiKeyAlg;
} BLOBHEADER, PUBLICKEYSTRUC;

typedef struct _RSAPUBKEY {
        DWORD magic;
        DWORD bitlen;
        DWORD pubexp;

} RSAPUBKEY;

typedef struct _PUBKEY {
        DWORD magic;
        DWORD bitlen;
} DHPUBKEY, DSSPUBKEY, KEAPUBKEY, TEKPUBKEY;

typedef struct _DSSSEED {
        DWORD counter;
        BYTE seed[20];
} DSSSEED;

typedef struct _PUBKEYVER3 {
        DWORD magic;
        DWORD bitlenP;
        DWORD bitlenQ;
        DWORD bitlenJ;
        DSSSEED DSSSeed;
} DHPUBKEY_VER3, DSSPUBKEY_VER3;

typedef struct _PRIVKEYVER3 {
        DWORD magic;
        DWORD bitlenP;
        DWORD bitlenQ;
        DWORD bitlenJ;
        DWORD bitlenX;
        DSSSEED DSSSeed;
} DHPRIVKEY_VER3, DSSPRIVKEY_VER3;

typedef struct _KEY_TYPE_SUBTYPE {
        DWORD dwKeySpec;
        GUID Type;
        GUID Subtype;
} KEY_TYPE_SUBTYPE, *PKEY_TYPE_SUBTYPE;

typedef struct _CERT_FORTEZZA_DATA_PROP {
    unsigned char SerialNumber[8];
    int CertIndex;
    unsigned char CertLabel[36];
} CERT_FORTEZZA_DATA_PROP;


typedef struct _CRYPT_RC4_KEY_STATE {
    unsigned char Key[16];
    unsigned char SBox[256];
    unsigned char i;
    unsigned char j;
} CRYPT_RC4_KEY_STATE, *PCRYPT_RC4_KEY_STATE;

typedef struct _CRYPT_DES_KEY_STATE {
    unsigned char Key[8];
    unsigned char IV[8];
    unsigned char Feedback[8];
} CRYPT_DES_KEY_STATE, *PCRYPT_DES_KEY_STATE;

typedef struct _CRYPT_3DES_KEY_STATE {
    unsigned char Key[24];
    unsigned char IV[8];
    unsigned char Feedback[8];
} CRYPT_3DES_KEY_STATE, *PCRYPT_3DES_KEY_STATE;



typedef struct _CRYPT_AES_128_KEY_STATE {
    unsigned char Key[16];
    unsigned char IV[16];
    unsigned char EncryptionState[11][16];
    unsigned char DecryptionState[11][16];
    unsigned char Feedback[16];
} CRYPT_AES_128_KEY_STATE, *PCRYPT_AES_128_KEY_STATE;

typedef struct _CRYPT_AES_256_KEY_STATE {
    unsigned char Key[32];
    unsigned char IV[16];
    unsigned char EncryptionState[15][16];
    unsigned char DecryptionState[15][16];
    unsigned char Feedback[16];
} CRYPT_AES_256_KEY_STATE, *PCRYPT_AES_256_KEY_STATE;







typedef struct _CRYPTOAPI_BLOB {
                            DWORD cbData;
     BYTE *pbData;
} CRYPT_INTEGER_BLOB, *PCRYPT_INTEGER_BLOB,
CRYPT_UINT_BLOB, *PCRYPT_UINT_BLOB,
CRYPT_OBJID_BLOB, *PCRYPT_OBJID_BLOB,
CERT_NAME_BLOB, *PCERT_NAME_BLOB,
CERT_RDN_VALUE_BLOB, *PCERT_RDN_VALUE_BLOB,
CERT_BLOB, *PCERT_BLOB,
CRL_BLOB, *PCRL_BLOB,
DATA_BLOB, *PDATA_BLOB,
CRYPT_DATA_BLOB, *PCRYPT_DATA_BLOB,
CRYPT_HASH_BLOB, *PCRYPT_HASH_BLOB,
CRYPT_DIGEST_BLOB, *PCRYPT_DIGEST_BLOB,
CRYPT_DER_BLOB, *PCRYPT_DER_BLOB,
CRYPT_ATTR_BLOB, *PCRYPT_ATTR_BLOB;



typedef struct _CMS_DH_KEY_INFO {
    DWORD dwVersion;
    ALG_ID Algid;
    LPSTR pszContentEncObjId;
    CRYPT_DATA_BLOB PubInfo;
    void *pReserved;
} CMS_DH_KEY_INFO, *PCMS_DH_KEY_INFO;


__declspec(dllimport)
BOOL

CryptAcquireContextA(
     HCRYPTPROV *phProv,
     LPCSTR szContainer,
     LPCSTR szProvider,
     DWORD dwProvType,
     DWORD dwFlags
    );
__declspec(dllimport)
BOOL

CryptAcquireContextW(
     HCRYPTPROV *phProv,
     LPCWSTR szContainer,
     LPCWSTR szProvider,
     DWORD dwProvType,
     DWORD dwFlags
    );
__declspec(dllimport)
BOOL

CryptReleaseContext(
     HCRYPTPROV hProv,
     DWORD dwFlags
    );
__declspec(dllimport)
BOOL

CryptGenKey(
     HCRYPTPROV hProv,
     ALG_ID Algid,
     DWORD dwFlags,
     HCRYPTKEY *phKey
    );

__declspec(dllimport)
BOOL

CryptDeriveKey(
     HCRYPTPROV hProv,
     ALG_ID Algid,
     HCRYPTHASH hBaseData,
     DWORD dwFlags,
     HCRYPTKEY *phKey
    );

__declspec(dllimport)
BOOL

CryptDestroyKey(
     HCRYPTKEY hKey
    );


__declspec(dllimport)
BOOL

CryptSetKeyParam(
     HCRYPTKEY hKey,
     DWORD dwParam,
      const  BYTE *pbData,
     DWORD dwFlags
    );
__declspec(dllimport)
BOOL

CryptGetKeyParam(
     HCRYPTKEY hKey,
     DWORD dwParam,
     BYTE *pbData,
     DWORD *pdwDataLen,
     DWORD dwFlags
    );


__declspec(dllimport)
BOOL

CryptSetHashParam(
     HCRYPTHASH hHash,
     DWORD dwParam,
      const  BYTE *pbData,
     DWORD dwFlags
    );
__declspec(dllimport)
BOOL

CryptGetHashParam(
     HCRYPTHASH hHash,
     DWORD dwParam,
     BYTE *pbData,
     DWORD *pdwDataLen,
     DWORD dwFlags
    );


__declspec(dllimport)
BOOL

CryptSetProvParam(
     HCRYPTPROV hProv,
     DWORD dwParam,
      const  BYTE *pbData,
     DWORD dwFlags
    );
__declspec(dllimport)
BOOL

CryptGetProvParam(
     HCRYPTPROV hProv,
     DWORD dwParam,
     BYTE *pbData,
     DWORD *pdwDataLen,
     DWORD dwFlags
    );

__declspec(dllimport)
BOOL

CryptGenRandom(
     HCRYPTPROV hProv,
     DWORD dwLen,
     BYTE *pbBuffer
    );

__declspec(dllimport)
BOOL

CryptGetUserKey(
     HCRYPTPROV hProv,
     DWORD dwKeySpec,
     HCRYPTKEY *phUserKey
    );

__declspec(dllimport)
BOOL

CryptExportKey(
     HCRYPTKEY hKey,
     HCRYPTKEY hExpKey,
     DWORD dwBlobType,
     DWORD dwFlags,
     BYTE *pbData,
     DWORD *pdwDataLen
    );

__declspec(dllimport)
BOOL

CryptImportKey(
     HCRYPTPROV hProv,
      const  BYTE *pbData,
     DWORD dwDataLen,
     HCRYPTKEY hPubKey,
     DWORD dwFlags,
     HCRYPTKEY *phKey
    );

__declspec(dllimport)
 BOOL

CryptEncrypt(
     HCRYPTKEY hKey,
     HCRYPTHASH hHash,
     BOOL Final,
     DWORD dwFlags,
     BYTE *pbData,
     DWORD *pdwDataLen,
     DWORD dwBufLen
    );

__declspec(dllimport)
BOOL

CryptDecrypt(
     HCRYPTKEY hKey,
     HCRYPTHASH hHash,
     BOOL Final,
     DWORD dwFlags,
     BYTE *pbData,
     DWORD *pdwDataLen
    );

__declspec(dllimport)
BOOL

CryptCreateHash(
     HCRYPTPROV hProv,
     ALG_ID Algid,
     HCRYPTKEY hKey,
     DWORD dwFlags,
     HCRYPTHASH *phHash
    );

__declspec(dllimport)
BOOL

CryptHashData(
     HCRYPTHASH hHash,
      const  BYTE *pbData,
     DWORD dwDataLen,
     DWORD dwFlags
    );

__declspec(dllimport)
BOOL

CryptHashSessionKey(
     HCRYPTHASH hHash,
     HCRYPTKEY hKey,
     DWORD dwFlags
    );

__declspec(dllimport)
BOOL

CryptDestroyHash(
     HCRYPTHASH hHash
    );


__declspec(dllimport)
BOOL

CryptSignHashA(
     HCRYPTHASH hHash,
     DWORD dwKeySpec,
     LPCSTR szDescription,
     DWORD dwFlags,
     BYTE *pbSignature,
     DWORD *pdwSigLen
    );
__declspec(dllimport)
BOOL

CryptSignHashW(
     HCRYPTHASH hHash,
     DWORD dwKeySpec,
     LPCWSTR szDescription,
     DWORD dwFlags,
     BYTE *pbSignature,
     DWORD *pdwSigLen
    );
__declspec(dllimport)
BOOL

CryptVerifySignatureA(
     HCRYPTHASH hHash,
      const  BYTE *pbSignature,
     DWORD dwSigLen,
     HCRYPTKEY hPubKey,
     LPCSTR szDescription,
     DWORD dwFlags
    );
__declspec(dllimport)
BOOL

CryptVerifySignatureW(
     HCRYPTHASH hHash,
      const  BYTE *pbSignature,
     DWORD dwSigLen,
     HCRYPTKEY hPubKey,
     LPCWSTR szDescription,
     DWORD dwFlags
    );
__declspec(dllimport)
BOOL

CryptSetProviderA(
     LPCSTR pszProvName,
     DWORD dwProvType
    );
__declspec(dllimport)
BOOL

CryptSetProviderW(
     LPCWSTR pszProvName,
     DWORD dwProvType
    );
__declspec(dllimport)
BOOL

CryptSetProviderExA(
     LPCSTR pszProvName,
     DWORD dwProvType,
     DWORD *pdwReserved,
     DWORD dwFlags
    );
__declspec(dllimport)
BOOL

CryptSetProviderExW(
     LPCWSTR pszProvName,
     DWORD dwProvType,
     DWORD *pdwReserved,
     DWORD dwFlags
    );
__declspec(dllimport)
BOOL

CryptGetDefaultProviderA(
     DWORD dwProvType,
     DWORD *pdwReserved,
     DWORD dwFlags,
     LPSTR pszProvName,
     DWORD *pcbProvName
    );
__declspec(dllimport)
BOOL

CryptGetDefaultProviderW(
     DWORD dwProvType,
     DWORD *pdwReserved,
     DWORD dwFlags,
     LPWSTR pszProvName,
     DWORD *pcbProvName
    );
__declspec(dllimport)
BOOL

CryptEnumProviderTypesA(
     DWORD dwIndex,
     DWORD *pdwReserved,
     DWORD dwFlags,
     DWORD *pdwProvType,
     LPSTR szTypeName,
     DWORD *pcbTypeName
    );
__declspec(dllimport)
BOOL

CryptEnumProviderTypesW(
     DWORD dwIndex,
     DWORD *pdwReserved,
     DWORD dwFlags,
     DWORD *pdwProvType,
     LPWSTR szTypeName,
     DWORD *pcbTypeName
    );
__declspec(dllimport)
BOOL

CryptEnumProvidersA(
     DWORD dwIndex,
     DWORD *pdwReserved,
     DWORD dwFlags,
     DWORD *pdwProvType,
     LPSTR szProvName,
     DWORD *pcbProvName
    );
__declspec(dllimport)
BOOL

CryptEnumProvidersW(
     DWORD dwIndex,
     DWORD *pdwReserved,
     DWORD dwFlags,
     DWORD *pdwProvType,
     LPWSTR szProvName,
     DWORD *pcbProvName
    );
__declspec(dllimport)
BOOL

CryptContextAddRef(
     HCRYPTPROV hProv,
     DWORD *pdwReserved,
     DWORD dwFlags
    );

__declspec(dllimport)
BOOL

CryptDuplicateKey(
     HCRYPTKEY hKey,
     DWORD *pdwReserved,
     DWORD dwFlags,
     HCRYPTKEY *phKey
    );

__declspec(dllimport)
BOOL

CryptDuplicateHash(
     HCRYPTHASH hHash,
     DWORD *pdwReserved,
     DWORD dwFlags,
     HCRYPTHASH *phHash
    );








BOOL

GetEncSChannel(
    BYTE **pData,
    DWORD *dwDecSize
    );
typedef   LONG NTSTATUS, *PNTSTATUS;
typedef struct __BCRYPT_KEY_LENGTHS_STRUCT
{
    ULONG dwMinLength;
    ULONG dwMaxLength;
    ULONG dwIncrement;
} BCRYPT_KEY_LENGTHS_STRUCT;

typedef BCRYPT_KEY_LENGTHS_STRUCT BCRYPT_AUTH_TAG_LENGTHS_STRUCT;
typedef  __declspec(align( 4 ))  struct _BCRYPT_OID
{
    ULONG cbOID;
    PUCHAR pbOID;
} BCRYPT_OID;

typedef  __declspec(align( 4 ))  struct _BCRYPT_OID_LIST
{
    ULONG dwOIDCount;
    BCRYPT_OID *pOIDs;
} BCRYPT_OID_LIST;

typedef struct _BCRYPT_PKCS1_PADDING_INFO
{
    LPCWSTR pszAlgId;
} BCRYPT_PKCS1_PADDING_INFO;

typedef struct _BCRYPT_PSS_PADDING_INFO
{
    LPCWSTR pszAlgId;
    ULONG cbSalt;
} BCRYPT_PSS_PADDING_INFO;

typedef struct _BCRYPT_OAEP_PADDING_INFO
{
    LPCWSTR pszAlgId;
    PUCHAR pbLabel;
    ULONG cbLabel;
} BCRYPT_OAEP_PADDING_INFO;






typedef struct _BCRYPT_AUTHENTICATED_CIPHER_MODE_INFO
{
    ULONG cbSize;
    ULONG dwInfoVersion;
    PUCHAR pbNonce;
    ULONG cbNonce;
    PUCHAR pbAuthData;
    ULONG cbAuthData;
    PUCHAR pbTag;
    ULONG cbTag;
    PUCHAR pbMacContext;
    ULONG cbMacContext;
    ULONG cbAAD;
    ULONGLONG cbData;
    ULONG dwFlags;
} BCRYPT_AUTHENTICATED_CIPHER_MODE_INFO, *PBCRYPT_AUTHENTICATED_CIPHER_MODE_INFO;
typedef struct _BCryptBuffer {
    ULONG cbBuffer;
    ULONG BufferType;
    PVOID pvBuffer;
} BCryptBuffer, * PBCryptBuffer;

typedef struct _BCryptBufferDesc {
    ULONG ulVersion;
    ULONG cBuffers;
    PBCryptBuffer pBuffers;
} BCryptBufferDesc, * PBCryptBufferDesc;






typedef PVOID BCRYPT_HANDLE;
typedef PVOID BCRYPT_ALG_HANDLE;
typedef PVOID BCRYPT_KEY_HANDLE;
typedef PVOID BCRYPT_HASH_HANDLE;
typedef PVOID BCRYPT_SECRET_HANDLE;









typedef struct _BCRYPT_KEY_BLOB
{
    ULONG Magic;
} BCRYPT_KEY_BLOB;
typedef struct _BCRYPT_RSAKEY_BLOB
{
    ULONG Magic;
    ULONG BitLength;
    ULONG cbPublicExp;
    ULONG cbModulus;
    ULONG cbPrime1;
    ULONG cbPrime2;
} BCRYPT_RSAKEY_BLOB;
typedef struct _BCRYPT_ECCKEY_BLOB
{
    ULONG dwMagic;
    ULONG cbKey;
} BCRYPT_ECCKEY_BLOB, *PBCRYPT_ECCKEY_BLOB;
typedef struct _BCRYPT_DH_KEY_BLOB
{
    ULONG dwMagic;
    ULONG cbKey;
} BCRYPT_DH_KEY_BLOB, *PBCRYPT_DH_KEY_BLOB;






typedef   struct _BCRYPT_DH_PARAMETER_HEADER
{
    ULONG cbLength;
    ULONG dwMagic;
    ULONG cbKeyLength;
} BCRYPT_DH_PARAMETER_HEADER;
typedef struct _BCRYPT_DSA_KEY_BLOB
{
    ULONG dwMagic;
    ULONG cbKey;
    UCHAR Count[4];
    UCHAR Seed[20];
    UCHAR q[20];
} BCRYPT_DSA_KEY_BLOB, *PBCRYPT_DSA_KEY_BLOB;

typedef struct _BCRYPT_KEY_DATA_BLOB_HEADER
{
    ULONG dwMagic;
    ULONG dwVersion;
    ULONG cbKeyData;
} BCRYPT_KEY_DATA_BLOB_HEADER, *PBCRYPT_KEY_DATA_BLOB_HEADER;










typedef struct _BCRYPT_DSA_PARAMETER_HEADER
{
    ULONG cbLength;
    ULONG dwMagic;
    ULONG cbKeyLength;
    UCHAR Count[4];
    UCHAR Seed[20];
    UCHAR q[20];
} BCRYPT_DSA_PARAMETER_HEADER;
NTSTATUS

BCryptOpenAlgorithmProvider(
     BCRYPT_ALG_HANDLE *phAlgorithm,
     LPCWSTR pszAlgId,
     LPCWSTR pszImplementation,
     ULONG dwFlags);

typedef NTSTATUS
(  * BCryptOpenAlgorithmProviderFn)(
     BCRYPT_ALG_HANDLE *phAlgorithm,
     LPCWSTR pszAlgId,
     ULONG dwFlags);
typedef struct _BCRYPT_ALGORITHM_IDENTIFIER
{
    LPWSTR pszName;
    ULONG dwClass;
    ULONG dwFlags;

} BCRYPT_ALGORITHM_IDENTIFIER;


NTSTATUS

BCryptEnumAlgorithms(
     ULONG dwAlgOperations,
     ULONG *pAlgCount,
     BCRYPT_ALGORITHM_IDENTIFIER **ppAlgList,
     ULONG dwFlags);


typedef struct _BCRYPT_PROVIDER_NAME
{
    LPWSTR pszProviderName;
} BCRYPT_PROVIDER_NAME;

NTSTATUS

BCryptEnumProviders(
     LPCWSTR pszAlgId,
     ULONG *pImplCount,
     BCRYPT_PROVIDER_NAME **ppImplList,
     ULONG dwFlags);







NTSTATUS

BCryptGetProperty(
     BCRYPT_HANDLE hObject,
     LPCWSTR pszProperty,
     PUCHAR pbOutput,
     ULONG cbOutput,
     ULONG *pcbResult,
     ULONG dwFlags);


NTSTATUS

BCryptSetProperty(
     BCRYPT_HANDLE hObject,
     LPCWSTR pszProperty,
     PUCHAR pbInput,
     ULONG cbInput,
     ULONG dwFlags);


NTSTATUS

BCryptCloseAlgorithmProvider(
     BCRYPT_ALG_HANDLE hAlgorithm,
     ULONG dwFlags);


void

BCryptFreeBuffer(
     PVOID pvBuffer);






NTSTATUS

BCryptGenerateSymmetricKey(
     BCRYPT_ALG_HANDLE hAlgorithm,
     BCRYPT_KEY_HANDLE *phKey,
     PUCHAR pbKeyObject,
     ULONG cbKeyObject,
     PUCHAR pbSecret,
     ULONG cbSecret,
     ULONG dwFlags);


NTSTATUS

BCryptGenerateKeyPair(
     BCRYPT_ALG_HANDLE hAlgorithm,
     BCRYPT_KEY_HANDLE *phKey,
     ULONG dwLength,
     ULONG dwFlags);


NTSTATUS

BCryptEncrypt(
     BCRYPT_KEY_HANDLE hKey,
     PUCHAR pbInput,
     ULONG cbInput,
      void  *pPaddingInfo,
     PUCHAR pbIV,
     ULONG cbIV,
     PUCHAR pbOutput,
     ULONG cbOutput,
     ULONG *pcbResult,
     ULONG dwFlags);


NTSTATUS

BCryptDecrypt(
     BCRYPT_KEY_HANDLE hKey,
     PUCHAR pbInput,
     ULONG cbInput,
      void  *pPaddingInfo,
     PUCHAR pbIV,
     ULONG cbIV,
     PUCHAR pbOutput,
     ULONG cbOutput,
     ULONG *pcbResult,
     ULONG dwFlags);


NTSTATUS

BCryptExportKey(
     BCRYPT_KEY_HANDLE hKey,
     BCRYPT_KEY_HANDLE hExportKey,
     LPCWSTR pszBlobType,
     PUCHAR pbOutput,
     ULONG cbOutput,
     ULONG *pcbResult,
     ULONG dwFlags);


NTSTATUS

BCryptImportKey(
     BCRYPT_ALG_HANDLE hAlgorithm,
     BCRYPT_KEY_HANDLE hImportKey,
     LPCWSTR pszBlobType,
     BCRYPT_KEY_HANDLE *phKey,
     PUCHAR pbKeyObject,
     ULONG cbKeyObject,
     PUCHAR pbInput,
     ULONG cbInput,
     ULONG dwFlags);




NTSTATUS

BCryptImportKeyPair(
     BCRYPT_ALG_HANDLE hAlgorithm,
     BCRYPT_KEY_HANDLE hImportKey,
     LPCWSTR pszBlobType,
     BCRYPT_KEY_HANDLE *phKey,
     PUCHAR pbInput,
     ULONG cbInput,
     ULONG dwFlags);


NTSTATUS

BCryptDuplicateKey(
     BCRYPT_KEY_HANDLE hKey,
     BCRYPT_KEY_HANDLE *phNewKey,
     PUCHAR pbKeyObject,
     ULONG cbKeyObject,
     ULONG dwFlags);


NTSTATUS

BCryptFinalizeKeyPair(
     BCRYPT_KEY_HANDLE hKey,
     ULONG dwFlags);


NTSTATUS

BCryptDestroyKey(
     BCRYPT_KEY_HANDLE hKey);


NTSTATUS

BCryptDestroySecret(
     BCRYPT_SECRET_HANDLE hSecret);


NTSTATUS

BCryptSignHash(
     BCRYPT_KEY_HANDLE hKey,
      void  *pPaddingInfo,
     PUCHAR pbInput,
     ULONG cbInput,
     PUCHAR pbOutput,
     ULONG cbOutput,
     ULONG *pcbResult,
     ULONG dwFlags);


NTSTATUS

BCryptVerifySignature(
     BCRYPT_KEY_HANDLE hKey,
      void  *pPaddingInfo,
     PUCHAR pbHash,
     ULONG cbHash,
     PUCHAR pbSignature,
     ULONG cbSignature,
     ULONG dwFlags);


NTSTATUS

BCryptSecretAgreement(
     BCRYPT_KEY_HANDLE hPrivKey,
     BCRYPT_KEY_HANDLE hPubKey,
     BCRYPT_SECRET_HANDLE *phAgreedSecret,
     ULONG dwFlags);


NTSTATUS

BCryptDeriveKey(
     BCRYPT_SECRET_HANDLE hSharedSecret,
     LPCWSTR pwszKDF,
     BCryptBufferDesc *pParameterList,
     PUCHAR pbDerivedKey,
     ULONG cbDerivedKey,
     ULONG *pcbResult,
     ULONG dwFlags);






NTSTATUS

BCryptCreateHash(
     BCRYPT_ALG_HANDLE hAlgorithm,
     BCRYPT_HASH_HANDLE *phHash,
     PUCHAR pbHashObject,
     ULONG cbHashObject,
     PUCHAR pbSecret,
     ULONG cbSecret,
     ULONG dwFlags);


NTSTATUS

BCryptHashData(
     BCRYPT_HASH_HANDLE hHash,
     PUCHAR pbInput,
     ULONG cbInput,
     ULONG dwFlags);


NTSTATUS

BCryptFinishHash(
     BCRYPT_HASH_HANDLE hHash,
     PUCHAR pbOutput,
     ULONG cbOutput,
     ULONG dwFlags);


NTSTATUS

BCryptDuplicateHash(
     BCRYPT_HASH_HANDLE hHash,
     BCRYPT_HASH_HANDLE *phNewHash,
     PUCHAR pbHashObject,
     ULONG cbHashObject,
     ULONG dwFlags);


NTSTATUS

BCryptDestroyHash(
     BCRYPT_HASH_HANDLE hHash);










NTSTATUS

BCryptGenRandom(
     BCRYPT_ALG_HANDLE hAlgorithm,
     PUCHAR pbBuffer,
     ULONG cbBuffer,
     ULONG dwFlags);





typedef struct _BCRYPT_INTERFACE_VERSION
{
    USHORT MajorVersion;
    USHORT MinorVersion;

} BCRYPT_INTERFACE_VERSION, *PBCRYPT_INTERFACE_VERSION;
typedef struct _CRYPT_INTERFACE_REG
{
    ULONG dwInterface;
    ULONG dwFlags;

    ULONG cFunctions;
    PWSTR *rgpszFunctions;
}
CRYPT_INTERFACE_REG, *PCRYPT_INTERFACE_REG;

typedef struct _CRYPT_IMAGE_REG
{
    PWSTR pszImage;

    ULONG cInterfaces;
    PCRYPT_INTERFACE_REG *rgpInterfaces;
}
CRYPT_IMAGE_REG, *PCRYPT_IMAGE_REG;

typedef struct _CRYPT_PROVIDER_REG
{
    ULONG cAliases;
    PWSTR *rgpszAliases;

    PCRYPT_IMAGE_REG pUM;
    PCRYPT_IMAGE_REG pKM;
}
CRYPT_PROVIDER_REG, *PCRYPT_PROVIDER_REG;

typedef struct _CRYPT_PROVIDERS
{
    ULONG cProviders;
    PWSTR *rgpszProviders;
}
CRYPT_PROVIDERS, *PCRYPT_PROVIDERS;





typedef struct _CRYPT_CONTEXT_CONFIG
{
    ULONG dwFlags;
    ULONG dwReserved;
}
CRYPT_CONTEXT_CONFIG, *PCRYPT_CONTEXT_CONFIG;

typedef struct _CRYPT_CONTEXT_FUNCTION_CONFIG
{
    ULONG dwFlags;
    ULONG dwReserved;
}
CRYPT_CONTEXT_FUNCTION_CONFIG, *PCRYPT_CONTEXT_FUNCTION_CONFIG;

typedef struct _CRYPT_CONTEXTS
{
    ULONG cContexts;
    PWSTR *rgpszContexts;
}
CRYPT_CONTEXTS, *PCRYPT_CONTEXTS;

typedef struct _CRYPT_CONTEXT_FUNCTIONS
{
    ULONG cFunctions;
    PWSTR *rgpszFunctions;
}
CRYPT_CONTEXT_FUNCTIONS, *PCRYPT_CONTEXT_FUNCTIONS;

typedef struct _CRYPT_CONTEXT_FUNCTION_PROVIDERS
{
    ULONG cProviders;
    PWSTR *rgpszProviders;
}
CRYPT_CONTEXT_FUNCTION_PROVIDERS, *PCRYPT_CONTEXT_FUNCTION_PROVIDERS;





typedef struct _CRYPT_PROPERTY_REF
{
    PWSTR pszProperty;

    ULONG cbValue;
    PUCHAR pbValue;
}
CRYPT_PROPERTY_REF, *PCRYPT_PROPERTY_REF;

typedef struct _CRYPT_IMAGE_REF
{
    PWSTR pszImage;
    ULONG dwFlags;
}
CRYPT_IMAGE_REF, *PCRYPT_IMAGE_REF;

typedef struct _CRYPT_PROVIDER_REF
{
    ULONG dwInterface;
    PWSTR pszFunction;
    PWSTR pszProvider;

    ULONG cProperties;
    PCRYPT_PROPERTY_REF *rgpProperties;

    PCRYPT_IMAGE_REF pUM;
    PCRYPT_IMAGE_REF pKM;
}
CRYPT_PROVIDER_REF, *PCRYPT_PROVIDER_REF;

typedef struct _CRYPT_PROVIDER_REFS
{
    ULONG cProviders;
    PCRYPT_PROVIDER_REF *rgpProviders;
}
CRYPT_PROVIDER_REFS, *PCRYPT_PROVIDER_REFS;








NTSTATUS

BCryptQueryProviderRegistration(
     LPCWSTR pszProvider,
     ULONG dwMode,
     ULONG dwInterface,
     ULONG* pcbBuffer,
     PCRYPT_PROVIDER_REG *ppBuffer);

NTSTATUS

BCryptEnumRegisteredProviders(
     ULONG* pcbBuffer,
     PCRYPT_PROVIDERS *ppBuffer);





NTSTATUS

BCryptCreateContext(
     ULONG dwTable,
     LPCWSTR pszContext,
     PCRYPT_CONTEXT_CONFIG pConfig);

NTSTATUS

BCryptDeleteContext(
     ULONG dwTable,
     LPCWSTR pszContext);

NTSTATUS

BCryptEnumContexts(
     ULONG dwTable,
     ULONG* pcbBuffer,
     PCRYPT_CONTEXTS *ppBuffer);

NTSTATUS

BCryptConfigureContext(
     ULONG dwTable,
     LPCWSTR pszContext,
     PCRYPT_CONTEXT_CONFIG pConfig);

NTSTATUS

BCryptQueryContextConfiguration(
     ULONG dwTable,
     LPCWSTR pszContext,
     ULONG* pcbBuffer,
     PCRYPT_CONTEXT_CONFIG *ppBuffer);

NTSTATUS

BCryptAddContextFunction(
     ULONG dwTable,
     LPCWSTR pszContext,
     ULONG dwInterface,
     LPCWSTR pszFunction,
     ULONG dwPosition);

NTSTATUS

BCryptRemoveContextFunction(
     ULONG dwTable,
     LPCWSTR pszContext,
     ULONG dwInterface,
     LPCWSTR pszFunction);

NTSTATUS

BCryptEnumContextFunctions(
     ULONG dwTable,
     LPCWSTR pszContext,
     ULONG dwInterface,
     ULONG* pcbBuffer,
     PCRYPT_CONTEXT_FUNCTIONS *ppBuffer);

NTSTATUS

BCryptConfigureContextFunction(
     ULONG dwTable,
     LPCWSTR pszContext,
     ULONG dwInterface,
     LPCWSTR pszFunction,
     PCRYPT_CONTEXT_FUNCTION_CONFIG pConfig);

NTSTATUS

BCryptQueryContextFunctionConfiguration(
     ULONG dwTable,
     LPCWSTR pszContext,
     ULONG dwInterface,
     LPCWSTR pszFunction,
     ULONG* pcbBuffer,
     PCRYPT_CONTEXT_FUNCTION_CONFIG *ppBuffer);


NTSTATUS

BCryptEnumContextFunctionProviders(
     ULONG dwTable,
     LPCWSTR pszContext,
     ULONG dwInterface,
     LPCWSTR pszFunction,
     ULONG* pcbBuffer,
     PCRYPT_CONTEXT_FUNCTION_PROVIDERS *ppBuffer);

NTSTATUS

BCryptSetContextFunctionProperty(
     ULONG dwTable,
     LPCWSTR pszContext,
     ULONG dwInterface,
     LPCWSTR pszFunction,
     LPCWSTR pszProperty,
     ULONG cbValue,
     PUCHAR pbValue);

NTSTATUS

BCryptQueryContextFunctionProperty(
     ULONG dwTable,
     LPCWSTR pszContext,
     ULONG dwInterface,
     LPCWSTR pszFunction,
     LPCWSTR pszProperty,
     ULONG* pcbValue,
     PUCHAR *ppbValue);
NTSTATUS

BCryptRegisterConfigChangeNotify(
     HANDLE *phEvent);








NTSTATUS

BCryptUnregisterConfigChangeNotify(
     HANDLE hEvent);






NTSTATUS
BCryptResolveProviders(
     LPCWSTR pszContext,
     ULONG dwInterface,
     LPCWSTR pszFunction,
     LPCWSTR pszProvider,
     ULONG dwMode,
     ULONG dwFlags,
     ULONG* pcbBuffer,
     PCRYPT_PROVIDER_REFS *ppBuffer);






NTSTATUS

BCryptGetFipsAlgorithmMode(
     BOOLEAN *pfEnabled
    );
typedef LONG SECURITY_STATUS;
typedef BCryptBuffer NCryptBuffer;
typedef BCryptBuffer* PNCryptBuffer;
typedef BCryptBufferDesc NCryptBufferDesc;
typedef BCryptBufferDesc* PNCryptBufferDesc;





typedef ULONG_PTR NCRYPT_HANDLE;
typedef ULONG_PTR NCRYPT_PROV_HANDLE;
typedef ULONG_PTR NCRYPT_KEY_HANDLE;
typedef ULONG_PTR NCRYPT_HASH_HANDLE;
typedef ULONG_PTR NCRYPT_SECRET_HANDLE;
SECURITY_STATUS

NCryptOpenStorageProvider(
     NCRYPT_PROV_HANDLE *phProvider,
     LPCWSTR pszProviderName,
     DWORD dwFlags);
typedef struct _NCryptAlgorithmName
{
    LPWSTR pszName;
    DWORD dwClass;
    DWORD dwAlgOperations;
    DWORD dwFlags;
} NCryptAlgorithmName;


SECURITY_STATUS

NCryptEnumAlgorithms(
     NCRYPT_PROV_HANDLE hProvider,
     DWORD dwAlgOperations,
     DWORD * pdwAlgCount,
     NCryptAlgorithmName **ppAlgList,
     DWORD dwFlags);



SECURITY_STATUS

NCryptIsAlgSupported(
     NCRYPT_PROV_HANDLE hProvider,
     LPCWSTR pszAlgId,
     DWORD dwFlags);






typedef struct NCryptKeyName
{
    LPWSTR pszName;
    LPWSTR pszAlgid;
    DWORD dwLegacyKeySpec;
    DWORD dwFlags;
} NCryptKeyName;

SECURITY_STATUS

NCryptEnumKeys(
     NCRYPT_PROV_HANDLE hProvider,
     LPCWSTR pszScope,
     NCryptKeyName **ppKeyName,
     PVOID * ppEnumState,
     DWORD dwFlags);



typedef struct NCryptProviderName
{
    LPWSTR pszName;
    LPWSTR pszComment;
} NCryptProviderName;

SECURITY_STATUS

NCryptEnumStorageProviders(
     DWORD * pdwProviderCount,
     NCryptProviderName **ppProviderList,
     DWORD dwFlags);



SECURITY_STATUS

NCryptFreeBuffer(
     PVOID pvInput);







SECURITY_STATUS

NCryptOpenKey(
     NCRYPT_PROV_HANDLE hProvider,
     NCRYPT_KEY_HANDLE *phKey,
     LPCWSTR pszKeyName,
     DWORD dwLegacyKeySpec,
     DWORD dwFlags);







SECURITY_STATUS

NCryptCreatePersistedKey(
     NCRYPT_PROV_HANDLE hProvider,
     NCRYPT_KEY_HANDLE *phKey,
     LPCWSTR pszAlgId,
     LPCWSTR pszKeyName,
     DWORD dwLegacyKeySpec,
     DWORD dwFlags);
typedef struct __NCRYPT_UI_POLICY_BLOB
{
    DWORD dwVersion;
    DWORD dwFlags;
    DWORD cbCreationTitle;
    DWORD cbFriendlyName;
    DWORD cbDescription;



} NCRYPT_UI_POLICY_BLOB;

typedef struct __NCRYPT_UI_POLICY
{
    DWORD dwVersion;
    DWORD dwFlags;
    LPCWSTR pszCreationTitle;
    LPCWSTR pszFriendlyName;
    LPCWSTR pszDescription;
} NCRYPT_UI_POLICY;



typedef struct __NCRYPT_SUPPORTED_LENGTHS
{
    DWORD dwMinLength;
    DWORD dwMaxLength;
    DWORD dwIncrement;
    DWORD dwDefaultLength;
} NCRYPT_SUPPORTED_LENGTHS;




SECURITY_STATUS

NCryptGetProperty(
     NCRYPT_HANDLE hObject,
     LPCWSTR pszProperty,
     PBYTE pbOutput,
     DWORD cbOutput,
     DWORD * pcbResult,
     DWORD dwFlags);







SECURITY_STATUS

NCryptSetProperty(
     NCRYPT_HANDLE hObject,
     LPCWSTR pszProperty,
     PBYTE pbInput,
     DWORD cbInput,
     DWORD dwFlags);





SECURITY_STATUS

NCryptFinalizeKey(
     NCRYPT_KEY_HANDLE hKey,
     DWORD dwFlags);



SECURITY_STATUS

NCryptEncrypt(
     NCRYPT_KEY_HANDLE hKey,
     PBYTE pbInput,
     DWORD cbInput,
      void  *pPaddingInfo,
     PBYTE pbOutput,
     DWORD cbOutput,
     DWORD * pcbResult,
     DWORD dwFlags);



SECURITY_STATUS

NCryptDecrypt(
     NCRYPT_KEY_HANDLE hKey,
     PBYTE pbInput,
     DWORD cbInput,
      void  *pPaddingInfo,
     PBYTE pbOutput,
     DWORD cbOutput,
     DWORD * pcbResult,
     DWORD dwFlags);
SECURITY_STATUS

NCryptImportKey(
     NCRYPT_PROV_HANDLE hProvider,
     NCRYPT_KEY_HANDLE hImportKey,
     LPCWSTR pszBlobType,
     NCryptBufferDesc *pParameterList,
     NCRYPT_KEY_HANDLE *phKey,
     PBYTE pbData,
     DWORD cbData,
     DWORD dwFlags);



SECURITY_STATUS

NCryptExportKey(
     NCRYPT_KEY_HANDLE hKey,
     NCRYPT_KEY_HANDLE hExportKey,
     LPCWSTR pszBlobType,
     NCryptBufferDesc *pParameterList,
     PBYTE pbOutput,
     DWORD cbOutput,
     DWORD * pcbResult,
     DWORD dwFlags);



SECURITY_STATUS

NCryptSignHash(
     NCRYPT_KEY_HANDLE hKey,
      void  *pPaddingInfo,
     PBYTE pbHashValue,
     DWORD cbHashValue,
     PBYTE pbSignature,
     DWORD cbSignature,
     DWORD * pcbResult,
     DWORD dwFlags);



SECURITY_STATUS

NCryptVerifySignature(
     NCRYPT_KEY_HANDLE hKey,
      void  *pPaddingInfo,
     PBYTE pbHashValue,
     DWORD cbHashValue,
     PBYTE pbSignature,
     DWORD cbSignature,
     DWORD dwFlags);



SECURITY_STATUS

NCryptDeleteKey(
     NCRYPT_KEY_HANDLE hKey,
     DWORD dwFlags);



SECURITY_STATUS

NCryptFreeObject(
     NCRYPT_HANDLE hObject);



BOOL

NCryptIsKeyHandle(
     NCRYPT_KEY_HANDLE hKey);

SECURITY_STATUS

NCryptTranslateHandle(
     NCRYPT_PROV_HANDLE *phProvider,
     NCRYPT_KEY_HANDLE *phKey,
     HCRYPTPROV hLegacyProv,
     HCRYPTKEY hLegacyKey,
     DWORD dwLegacyKeySpec,
     DWORD dwFlags);








SECURITY_STATUS

NCryptNotifyChangeKey(
     NCRYPT_PROV_HANDLE hProvider,
     HANDLE *phEvent,
     DWORD dwFlags);



SECURITY_STATUS

NCryptSecretAgreement(
     NCRYPT_KEY_HANDLE hPrivKey,
     NCRYPT_KEY_HANDLE hPubKey,
     NCRYPT_SECRET_HANDLE *phAgreedSecret,
     DWORD dwFlags);



SECURITY_STATUS

NCryptDeriveKey(
     NCRYPT_SECRET_HANDLE hSharedSecret,
     LPCWSTR pwszKDF,
     NCryptBufferDesc *pParameterList,
     PBYTE pbDerivedKey,
     DWORD cbDerivedKey,
     DWORD *pcbResult,
     ULONG dwFlags);




typedef ULONG_PTR HCRYPTPROV_OR_NCRYPT_KEY_HANDLE;



typedef ULONG_PTR HCRYPTPROV_LEGACY;






typedef struct _CRYPT_BIT_BLOB {
    DWORD cbData;
    BYTE *pbData;
    DWORD cUnusedBits;
} CRYPT_BIT_BLOB, *PCRYPT_BIT_BLOB;







typedef struct _CRYPT_ALGORITHM_IDENTIFIER {
    LPSTR pszObjId;
    CRYPT_OBJID_BLOB Parameters;
} CRYPT_ALGORITHM_IDENTIFIER, *PCRYPT_ALGORITHM_IDENTIFIER;
typedef struct _CRYPT_OBJID_TABLE {
    DWORD dwAlgId;
    LPCSTR pszObjId;
} CRYPT_OBJID_TABLE, *PCRYPT_OBJID_TABLE;





typedef struct _CRYPT_HASH_INFO {
    CRYPT_ALGORITHM_IDENTIFIER HashAlgorithm;
    CRYPT_HASH_BLOB Hash;
} CRYPT_HASH_INFO, *PCRYPT_HASH_INFO;







typedef struct _CERT_EXTENSION {
    LPSTR pszObjId;
    BOOL fCritical;
    CRYPT_OBJID_BLOB Value;
} CERT_EXTENSION, *PCERT_EXTENSION;








typedef struct _CRYPT_ATTRIBUTE_TYPE_VALUE {
    LPSTR pszObjId;
    CRYPT_OBJID_BLOB Value;
} CRYPT_ATTRIBUTE_TYPE_VALUE, *PCRYPT_ATTRIBUTE_TYPE_VALUE;








typedef struct _CRYPT_ATTRIBUTE {
    LPSTR pszObjId;
    DWORD cValue;
    PCRYPT_ATTR_BLOB rgValue;
} CRYPT_ATTRIBUTE, *PCRYPT_ATTRIBUTE;

typedef struct _CRYPT_ATTRIBUTES {
    DWORD cAttr;
    PCRYPT_ATTRIBUTE rgAttr;
} CRYPT_ATTRIBUTES, *PCRYPT_ATTRIBUTES;








typedef struct _CERT_RDN_ATTR {
    LPSTR pszObjId;
    DWORD dwValueType;
    CERT_RDN_VALUE_BLOB Value;
} CERT_RDN_ATTR, *PCERT_RDN_ATTR;
typedef struct _CERT_RDN {
    DWORD cRDNAttr;
    PCERT_RDN_ATTR rgRDNAttr;
} CERT_RDN, *PCERT_RDN;





typedef struct _CERT_NAME_INFO {
    DWORD cRDN;
    PCERT_RDN rgRDN;
} CERT_NAME_INFO, *PCERT_NAME_INFO;







typedef struct _CERT_NAME_VALUE {
    DWORD dwValueType;
    CERT_RDN_VALUE_BLOB Value;
} CERT_NAME_VALUE, *PCERT_NAME_VALUE;








typedef struct _CERT_PUBLIC_KEY_INFO {
    CRYPT_ALGORITHM_IDENTIFIER Algorithm;
    CRYPT_BIT_BLOB PublicKey;
} CERT_PUBLIC_KEY_INFO, *PCERT_PUBLIC_KEY_INFO;










typedef struct _CRYPT_PRIVATE_KEY_INFO{
    DWORD Version;
    CRYPT_ALGORITHM_IDENTIFIER Algorithm;
    CRYPT_DER_BLOB PrivateKey;
    PCRYPT_ATTRIBUTES pAttributes;
} CRYPT_PRIVATE_KEY_INFO, *PCRYPT_PRIVATE_KEY_INFO;





typedef struct _CRYPT_ENCRYPTED_PRIVATE_KEY_INFO{
    CRYPT_ALGORITHM_IDENTIFIER EncryptionAlgorithm;
    CRYPT_DATA_BLOB EncryptedPrivateKey;
} CRYPT_ENCRYPTED_PRIVATE_KEY_INFO, *PCRYPT_ENCRYPTED_PRIVATE_KEY_INFO;
typedef BOOL (  *PCRYPT_DECRYPT_PRIVATE_KEY_FUNC)(
     CRYPT_ALGORITHM_IDENTIFIER Algorithm,
     CRYPT_DATA_BLOB EncryptedPrivateKey,
     BYTE* pbClearTextKey,
     DWORD* pcbClearTextKey,
     LPVOID pVoidDecryptFunc);
typedef BOOL (  *PCRYPT_ENCRYPT_PRIVATE_KEY_FUNC)(
     CRYPT_ALGORITHM_IDENTIFIER* pAlgorithm,
     CRYPT_DATA_BLOB* pClearTextPrivateKey,
     BYTE* pbEncryptedKey,
     DWORD* pcbEncryptedKey,
     LPVOID pVoidEncryptFunc);
typedef BOOL (  *PCRYPT_RESOLVE_HCRYPTPROV_FUNC)(
                                                       CRYPT_PRIVATE_KEY_INFO *pPrivateKeyInfo,
                                                       HCRYPTPROV *phCryptProv,
                                                       LPVOID pVoidResolveFunc);










typedef struct _CRYPT_PKCS8_IMPORT_PARAMS{
    CRYPT_DIGEST_BLOB PrivateKey;
    PCRYPT_RESOLVE_HCRYPTPROV_FUNC pResolvehCryptProvFunc;
    LPVOID pVoidResolveFunc;
    PCRYPT_DECRYPT_PRIVATE_KEY_FUNC pDecryptPrivateKeyFunc;
    LPVOID pVoidDecryptFunc;
} CRYPT_PKCS8_IMPORT_PARAMS, *PCRYPT_PKCS8_IMPORT_PARAMS, CRYPT_PRIVATE_KEY_BLOB_AND_PARAMS, *PCRYPT_PRIVATE_KEY_BLOB_AND_PARAMS;









typedef struct _CRYPT_PKCS8_EXPORT_PARAMS{
    HCRYPTPROV hCryptProv;
    DWORD dwKeySpec;
    LPSTR pszPrivateKeyObjId;

    PCRYPT_ENCRYPT_PRIVATE_KEY_FUNC pEncryptPrivateKeyFunc;
    LPVOID pVoidEncryptFunc;
} CRYPT_PKCS8_EXPORT_PARAMS, *PCRYPT_PKCS8_EXPORT_PARAMS;








typedef struct _CERT_INFO {
    DWORD dwVersion;
    CRYPT_INTEGER_BLOB SerialNumber;
    CRYPT_ALGORITHM_IDENTIFIER SignatureAlgorithm;
    CERT_NAME_BLOB Issuer;
    FILETIME NotBefore;
    FILETIME NotAfter;
    CERT_NAME_BLOB Subject;
    CERT_PUBLIC_KEY_INFO SubjectPublicKeyInfo;
    CRYPT_BIT_BLOB IssuerUniqueId;
    CRYPT_BIT_BLOB SubjectUniqueId;
    DWORD cExtension;
    PCERT_EXTENSION rgExtension;
} CERT_INFO, *PCERT_INFO;
typedef struct _CRL_ENTRY {
    CRYPT_INTEGER_BLOB SerialNumber;
    FILETIME RevocationDate;
    DWORD cExtension;
    PCERT_EXTENSION rgExtension;
} CRL_ENTRY, *PCRL_ENTRY;







typedef struct _CRL_INFO {
    DWORD dwVersion;
    CRYPT_ALGORITHM_IDENTIFIER SignatureAlgorithm;
    CERT_NAME_BLOB Issuer;
    FILETIME ThisUpdate;
    FILETIME NextUpdate;
    DWORD cCRLEntry;
    PCRL_ENTRY rgCRLEntry;
    DWORD cExtension;
    PCERT_EXTENSION rgExtension;
} CRL_INFO, *PCRL_INFO;
typedef struct _CERT_REQUEST_INFO {
    DWORD dwVersion;
    CERT_NAME_BLOB Subject;
    CERT_PUBLIC_KEY_INFO SubjectPublicKeyInfo;
    DWORD cAttribute;
    PCRYPT_ATTRIBUTE rgAttribute;
} CERT_REQUEST_INFO, *PCERT_REQUEST_INFO;









typedef struct _CERT_KEYGEN_REQUEST_INFO {
    DWORD dwVersion;
    CERT_PUBLIC_KEY_INFO SubjectPublicKeyInfo;
    LPWSTR pwszChallengeString;
} CERT_KEYGEN_REQUEST_INFO, *PCERT_KEYGEN_REQUEST_INFO;
typedef struct _CERT_SIGNED_CONTENT_INFO {
    CRYPT_DER_BLOB ToBeSigned;
    CRYPT_ALGORITHM_IDENTIFIER SignatureAlgorithm;
    CRYPT_BIT_BLOB Signature;
} CERT_SIGNED_CONTENT_INFO, *PCERT_SIGNED_CONTENT_INFO;









typedef struct _CTL_USAGE {
    DWORD cUsageIdentifier;
    LPSTR *rgpszUsageIdentifier;
} CTL_USAGE, *PCTL_USAGE,
CERT_ENHKEY_USAGE, *PCERT_ENHKEY_USAGE;





typedef struct _CTL_ENTRY {
    CRYPT_DATA_BLOB SubjectIdentifier;
    DWORD cAttribute;
    PCRYPT_ATTRIBUTE rgAttribute;
} CTL_ENTRY, *PCTL_ENTRY;




typedef struct _CTL_INFO {
    DWORD dwVersion;
    CTL_USAGE SubjectUsage;
    CRYPT_DATA_BLOB ListIdentifier;
    CRYPT_INTEGER_BLOB SequenceNumber;
    FILETIME ThisUpdate;
    FILETIME NextUpdate;
    CRYPT_ALGORITHM_IDENTIFIER SubjectAlgorithm;
    DWORD cCTLEntry;
    PCTL_ENTRY rgCTLEntry;
    DWORD cExtension;
    PCERT_EXTENSION rgExtension;
} CTL_INFO, *PCTL_INFO;
typedef struct _CRYPT_TIME_STAMP_REQUEST_INFO {
    LPSTR pszTimeStampAlgorithm;
    LPSTR pszContentType;
    CRYPT_OBJID_BLOB Content;
    DWORD cAttribute;
    PCRYPT_ATTRIBUTE rgAttribute;
} CRYPT_TIME_STAMP_REQUEST_INFO, *PCRYPT_TIME_STAMP_REQUEST_INFO;




typedef struct _CRYPT_ENROLLMENT_NAME_VALUE_PAIR {
    LPWSTR pwszName;
    LPWSTR pwszValue;
} CRYPT_ENROLLMENT_NAME_VALUE_PAIR, * PCRYPT_ENROLLMENT_NAME_VALUE_PAIR;




typedef struct _CRYPT_CSP_PROVIDER {
    DWORD dwKeySpec;
    LPWSTR pwszProviderName;
    CRYPT_BIT_BLOB Signature;
} CRYPT_CSP_PROVIDER, * PCRYPT_CSP_PROVIDER;
__declspec(dllimport)
BOOL

CryptFormatObject(
     DWORD dwCertEncodingType,
     DWORD dwFormatType,
     DWORD dwFormatStrType,
     void *pFormatStruct,
     LPCSTR lpszStructType,
     const BYTE *pbEncoded,
     DWORD cbEncoded,
       void *pbFormat,
     DWORD *pcbFormat
    );
typedef LPVOID (  *PFN_CRYPT_ALLOC)(
     size_t cbSize
    );

typedef  void  (  *PFN_CRYPT_FREE)(
     LPVOID pv
    );


typedef struct _CRYPT_ENCODE_PARA {
    DWORD cbSize;
    PFN_CRYPT_ALLOC pfnAlloc;
    PFN_CRYPT_FREE pfnFree;
} CRYPT_ENCODE_PARA, *PCRYPT_ENCODE_PARA;


__declspec(dllimport)
BOOL

CryptEncodeObjectEx(
     DWORD dwCertEncodingType,
     LPCSTR lpszStructType,
     const void *pvStructInfo,
     DWORD dwFlags,
     PCRYPT_ENCODE_PARA pEncodePara,
     void *pvEncoded,
          DWORD *pcbEncoded
    );

__declspec(dllimport)
BOOL

CryptEncodeObject(
     DWORD dwCertEncodingType,
     LPCSTR lpszStructType,
     const void *pvStructInfo,
     BYTE *pbEncoded,
     DWORD *pcbEncoded
    );
typedef struct _CRYPT_DECODE_PARA {
    DWORD cbSize;
    PFN_CRYPT_ALLOC pfnAlloc;
    PFN_CRYPT_FREE pfnFree;
} CRYPT_DECODE_PARA, *PCRYPT_DECODE_PARA;

__declspec(dllimport)
BOOL

CryptDecodeObjectEx(
     DWORD dwCertEncodingType,
     LPCSTR lpszStructType,
     const BYTE *pbEncoded,
     DWORD cbEncoded,
     DWORD dwFlags,
     PCRYPT_DECODE_PARA pDecodePara,
     void *pvStructInfo,
          DWORD *pcbStructInfo
    );


__declspec(dllimport)
BOOL

CryptDecodeObject(
     DWORD dwCertEncodingType,
     LPCSTR lpszStructType,
     const BYTE *pbEncoded,
     DWORD cbEncoded,
     DWORD dwFlags,
     void *pvStructInfo,
     DWORD *pcbStructInfo
    );
typedef struct _CERT_EXTENSIONS {
    DWORD cExtension;
    PCERT_EXTENSION rgExtension;
} CERT_EXTENSIONS, *PCERT_EXTENSIONS;
typedef struct _CERT_AUTHORITY_KEY_ID_INFO {
    CRYPT_DATA_BLOB KeyId;
    CERT_NAME_BLOB CertIssuer;
    CRYPT_INTEGER_BLOB CertSerialNumber;
} CERT_AUTHORITY_KEY_ID_INFO, *PCERT_AUTHORITY_KEY_ID_INFO;







typedef struct _CERT_PRIVATE_KEY_VALIDITY {
    FILETIME NotBefore;
    FILETIME NotAfter;
} CERT_PRIVATE_KEY_VALIDITY, *PCERT_PRIVATE_KEY_VALIDITY;

typedef struct _CERT_KEY_ATTRIBUTES_INFO {
    CRYPT_DATA_BLOB KeyId;
    CRYPT_BIT_BLOB IntendedKeyUsage;
    PCERT_PRIVATE_KEY_VALIDITY pPrivateKeyUsagePeriod;
} CERT_KEY_ATTRIBUTES_INFO, *PCERT_KEY_ATTRIBUTES_INFO;
typedef struct _CERT_POLICY_ID {
    DWORD cCertPolicyElementId;
    LPSTR *rgpszCertPolicyElementId;
} CERT_POLICY_ID, *PCERT_POLICY_ID;

typedef struct _CERT_KEY_USAGE_RESTRICTION_INFO {
    DWORD cCertPolicyId;
    PCERT_POLICY_ID rgCertPolicyId;
    CRYPT_BIT_BLOB RestrictedKeyUsage;
} CERT_KEY_USAGE_RESTRICTION_INFO, *PCERT_KEY_USAGE_RESTRICTION_INFO;
typedef struct _CERT_OTHER_NAME {
    LPSTR pszObjId;
    CRYPT_OBJID_BLOB Value;
} CERT_OTHER_NAME, *PCERT_OTHER_NAME;

typedef struct _CERT_ALT_NAME_ENTRY {
    DWORD dwAltNameChoice;
    union {
        PCERT_OTHER_NAME pOtherName;
        LPWSTR pwszRfc822Name;
        LPWSTR pwszDNSName;

        CERT_NAME_BLOB DirectoryName;

        LPWSTR pwszURL;
        CRYPT_DATA_BLOB IPAddress;
        LPSTR pszRegisteredID;
    }  u ;
} CERT_ALT_NAME_ENTRY, *PCERT_ALT_NAME_ENTRY;
typedef struct _CERT_ALT_NAME_INFO {
    DWORD cAltEntry;
    PCERT_ALT_NAME_ENTRY rgAltEntry;
} CERT_ALT_NAME_INFO, *PCERT_ALT_NAME_INFO;
typedef struct _CERT_BASIC_CONSTRAINTS_INFO {
    CRYPT_BIT_BLOB SubjectType;
    BOOL fPathLenConstraint;
    DWORD dwPathLenConstraint;
    DWORD cSubtreesConstraint;
    CERT_NAME_BLOB *rgSubtreesConstraint;
} CERT_BASIC_CONSTRAINTS_INFO, *PCERT_BASIC_CONSTRAINTS_INFO;










typedef struct _CERT_BASIC_CONSTRAINTS2_INFO {
    BOOL fCA;
    BOOL fPathLenConstraint;
    DWORD dwPathLenConstraint;
} CERT_BASIC_CONSTRAINTS2_INFO, *PCERT_BASIC_CONSTRAINTS2_INFO;
typedef struct _CERT_POLICY_QUALIFIER_INFO {
    LPSTR pszPolicyQualifierId;
    CRYPT_OBJID_BLOB Qualifier;
} CERT_POLICY_QUALIFIER_INFO, *PCERT_POLICY_QUALIFIER_INFO;

typedef struct _CERT_POLICY_INFO {
    LPSTR pszPolicyIdentifier;
    DWORD cPolicyQualifier;
    CERT_POLICY_QUALIFIER_INFO *rgPolicyQualifier;
} CERT_POLICY_INFO, *PCERT_POLICY_INFO;

typedef struct _CERT_POLICIES_INFO {
    DWORD cPolicyInfo;
    CERT_POLICY_INFO *rgPolicyInfo;
} CERT_POLICIES_INFO, *PCERT_POLICIES_INFO;









typedef struct _CERT_POLICY_QUALIFIER_NOTICE_REFERENCE {
    LPSTR pszOrganization;
    DWORD cNoticeNumbers;
    int *rgNoticeNumbers;
} CERT_POLICY_QUALIFIER_NOTICE_REFERENCE, *PCERT_POLICY_QUALIFIER_NOTICE_REFERENCE;

typedef struct _CERT_POLICY_QUALIFIER_USER_NOTICE {
    CERT_POLICY_QUALIFIER_NOTICE_REFERENCE *pNoticeReference;
    LPWSTR pszDisplayText;
} CERT_POLICY_QUALIFIER_USER_NOTICE, *PCERT_POLICY_QUALIFIER_USER_NOTICE;







typedef struct _CPS_URLS {
    LPWSTR pszURL;
    CRYPT_ALGORITHM_IDENTIFIER *pAlgorithm;
    CRYPT_DATA_BLOB *pDigest;
} CPS_URLS, *PCPS_URLS;

typedef struct _CERT_POLICY95_QUALIFIER1 {
    LPWSTR pszPracticesReference;
    LPSTR pszNoticeIdentifier;
    LPSTR pszNSINoticeIdentifier;
    DWORD cCPSURLs;
    CPS_URLS *rgCPSURLs;
} CERT_POLICY95_QUALIFIER1, *PCERT_POLICY95_QUALIFIER1;
typedef struct _CERT_POLICY_MAPPING {
    LPSTR pszIssuerDomainPolicy;
    LPSTR pszSubjectDomainPolicy;
} CERT_POLICY_MAPPING, *PCERT_POLICY_MAPPING;

typedef struct _CERT_POLICY_MAPPINGS_INFO {
    DWORD cPolicyMapping;
    PCERT_POLICY_MAPPING rgPolicyMapping;
} CERT_POLICY_MAPPINGS_INFO, *PCERT_POLICY_MAPPINGS_INFO;







typedef struct _CERT_POLICY_CONSTRAINTS_INFO {
    BOOL fRequireExplicitPolicy;
    DWORD dwRequireExplicitPolicySkipCerts;

    BOOL fInhibitPolicyMapping;
    DWORD dwInhibitPolicyMappingSkipCerts;
} CERT_POLICY_CONSTRAINTS_INFO, *PCERT_POLICY_CONSTRAINTS_INFO;
typedef struct _CRYPT_CONTENT_INFO_SEQUENCE_OF_ANY {
    LPSTR pszObjId;
    DWORD cValue;
    PCRYPT_DER_BLOB rgValue;
} CRYPT_CONTENT_INFO_SEQUENCE_OF_ANY, *PCRYPT_CONTENT_INFO_SEQUENCE_OF_ANY;









typedef struct _CRYPT_CONTENT_INFO {
    LPSTR pszObjId;
    CRYPT_DER_BLOB Content;
} CRYPT_CONTENT_INFO, *PCRYPT_CONTENT_INFO;
typedef struct _CRYPT_SEQUENCE_OF_ANY {
    DWORD cValue;
    PCRYPT_DER_BLOB rgValue;
} CRYPT_SEQUENCE_OF_ANY, *PCRYPT_SEQUENCE_OF_ANY;
typedef struct _CERT_AUTHORITY_KEY_ID2_INFO {
    CRYPT_DATA_BLOB KeyId;
    CERT_ALT_NAME_INFO AuthorityCertIssuer;

    CRYPT_INTEGER_BLOB AuthorityCertSerialNumber;
} CERT_AUTHORITY_KEY_ID2_INFO, *PCERT_AUTHORITY_KEY_ID2_INFO;
typedef struct _CERT_ACCESS_DESCRIPTION {
    LPSTR pszAccessMethod;
    CERT_ALT_NAME_ENTRY AccessLocation;
} CERT_ACCESS_DESCRIPTION, *PCERT_ACCESS_DESCRIPTION;


typedef struct _CERT_AUTHORITY_INFO_ACCESS {
    DWORD cAccDescr;
    PCERT_ACCESS_DESCRIPTION rgAccDescr;
} CERT_AUTHORITY_INFO_ACCESS, *PCERT_AUTHORITY_INFO_ACCESS,
  CERT_SUBJECT_INFO_ACCESS, *PCERT_SUBJECT_INFO_ACCESS;
typedef struct _CRL_DIST_POINT_NAME {
    DWORD dwDistPointNameChoice;
    union {
        CERT_ALT_NAME_INFO FullName;

    }  u ;
} CRL_DIST_POINT_NAME, *PCRL_DIST_POINT_NAME;





typedef struct _CRL_DIST_POINT {
    CRL_DIST_POINT_NAME DistPointName;
    CRYPT_BIT_BLOB ReasonFlags;
    CERT_ALT_NAME_INFO CRLIssuer;
} CRL_DIST_POINT, *PCRL_DIST_POINT;









typedef struct _CRL_DIST_POINTS_INFO {
    DWORD cDistPoint;
    PCRL_DIST_POINT rgDistPoint;
} CRL_DIST_POINTS_INFO, *PCRL_DIST_POINTS_INFO;
typedef struct _CROSS_CERT_DIST_POINTS_INFO {

    DWORD dwSyncDeltaTime;

    DWORD cDistPoint;
    PCERT_ALT_NAME_INFO rgDistPoint;
} CROSS_CERT_DIST_POINTS_INFO, *PCROSS_CERT_DIST_POINTS_INFO;
typedef struct _CERT_PAIR {
   CERT_BLOB Forward;
   CERT_BLOB Reverse;
} CERT_PAIR, *PCERT_PAIR;
typedef struct _CRL_ISSUING_DIST_POINT {
    CRL_DIST_POINT_NAME DistPointName;
    BOOL fOnlyContainsUserCerts;
    BOOL fOnlyContainsCACerts;
    CRYPT_BIT_BLOB OnlySomeReasonFlags;
    BOOL fIndirectCRL;
} CRL_ISSUING_DIST_POINT, *PCRL_ISSUING_DIST_POINT;
typedef struct _CERT_GENERAL_SUBTREE {
    CERT_ALT_NAME_ENTRY Base;
    DWORD dwMinimum;
    BOOL fMaximum;
    DWORD dwMaximum;
} CERT_GENERAL_SUBTREE, *PCERT_GENERAL_SUBTREE;

typedef struct _CERT_NAME_CONSTRAINTS_INFO {
    DWORD cPermittedSubtree;
    PCERT_GENERAL_SUBTREE rgPermittedSubtree;
    DWORD cExcludedSubtree;
    PCERT_GENERAL_SUBTREE rgExcludedSubtree;
} CERT_NAME_CONSTRAINTS_INFO, *PCERT_NAME_CONSTRAINTS_INFO;
typedef struct _CERT_DSS_PARAMETERS {
    CRYPT_UINT_BLOB p;
    CRYPT_UINT_BLOB q;
    CRYPT_UINT_BLOB g;
} CERT_DSS_PARAMETERS, *PCERT_DSS_PARAMETERS;
typedef struct _CERT_DH_PARAMETERS {
    CRYPT_UINT_BLOB p;
    CRYPT_UINT_BLOB g;
} CERT_DH_PARAMETERS, *PCERT_DH_PARAMETERS;









typedef struct _CERT_ECC_SIGNATURE {
    CRYPT_UINT_BLOB r;
    CRYPT_UINT_BLOB s;
} CERT_ECC_SIGNATURE, *PCERT_ECC_SIGNATURE;








typedef struct _CERT_X942_DH_VALIDATION_PARAMS {
    CRYPT_BIT_BLOB seed;
    DWORD pgenCounter;
} CERT_X942_DH_VALIDATION_PARAMS, *PCERT_X942_DH_VALIDATION_PARAMS;

typedef struct _CERT_X942_DH_PARAMETERS {
    CRYPT_UINT_BLOB p;
    CRYPT_UINT_BLOB g;
    CRYPT_UINT_BLOB q;
    CRYPT_UINT_BLOB j;
    PCERT_X942_DH_VALIDATION_PARAMS pValidationParams;
} CERT_X942_DH_PARAMETERS, *PCERT_X942_DH_PARAMETERS;
typedef struct _CRYPT_X942_OTHER_INFO {
    LPSTR pszContentEncryptionObjId;
    BYTE rgbCounter[ 4 ];
    BYTE rgbKeyLength[ 4 ];
    CRYPT_DATA_BLOB PubInfo;
} CRYPT_X942_OTHER_INFO, *PCRYPT_X942_OTHER_INFO;










typedef struct _CRYPT_ECC_CMS_SHARED_INFO {
    CRYPT_ALGORITHM_IDENTIFIER Algorithm;
    CRYPT_DATA_BLOB EntityUInfo;
    BYTE rgbSuppPubInfo[ 4 ];
} CRYPT_ECC_CMS_SHARED_INFO, *PCRYPT_ECC_CMS_SHARED_INFO;








typedef struct _CRYPT_RC2_CBC_PARAMETERS {
    DWORD dwVersion;
    BOOL fIV;
    BYTE rgbIV[8];
} CRYPT_RC2_CBC_PARAMETERS, *PCRYPT_RC2_CBC_PARAMETERS;
typedef struct _CRYPT_SMIME_CAPABILITY {
    LPSTR pszObjId;
    CRYPT_OBJID_BLOB Parameters;
} CRYPT_SMIME_CAPABILITY, *PCRYPT_SMIME_CAPABILITY;

typedef struct _CRYPT_SMIME_CAPABILITIES {
    DWORD cCapability;
    PCRYPT_SMIME_CAPABILITY rgCapability;
} CRYPT_SMIME_CAPABILITIES, *PCRYPT_SMIME_CAPABILITIES;
typedef struct _CERT_QC_STATEMENT {
    LPSTR pszStatementId;
    CRYPT_OBJID_BLOB StatementInfo;
} CERT_QC_STATEMENT, *PCERT_QC_STATEMENT;

typedef struct _CERT_QC_STATEMENTS_EXT_INFO {
    DWORD cStatement;
    PCERT_QC_STATEMENT rgStatement;
} CERT_QC_STATEMENTS_EXT_INFO, *PCERT_QC_STATEMENTS_EXT_INFO;
typedef struct _CRYPT_MASK_GEN_ALGORITHM {
    LPSTR pszObjId;
    CRYPT_ALGORITHM_IDENTIFIER HashAlgorithm;
} CRYPT_MASK_GEN_ALGORITHM, *PCRYPT_MASK_GEN_ALGORITHM;

typedef struct _CRYPT_RSA_SSA_PSS_PARAMETERS {
    CRYPT_ALGORITHM_IDENTIFIER HashAlgorithm;
    CRYPT_MASK_GEN_ALGORITHM MaskGenAlgorithm;
    DWORD dwSaltLength;
    DWORD dwTrailerField;
} CRYPT_RSA_SSA_PSS_PARAMETERS, *PCRYPT_RSA_SSA_PSS_PARAMETERS;
typedef struct _CRYPT_PSOURCE_ALGORITHM {
    LPSTR pszObjId;
    CRYPT_DATA_BLOB EncodingParameters;
} CRYPT_PSOURCE_ALGORITHM, *PCRYPT_PSOURCE_ALGORITHM;

typedef struct _CRYPT_RSAES_OAEP_PARAMETERS {
    CRYPT_ALGORITHM_IDENTIFIER HashAlgorithm;
    CRYPT_MASK_GEN_ALGORITHM MaskGenAlgorithm;
    CRYPT_PSOURCE_ALGORITHM PSourceAlgorithm;
} CRYPT_RSAES_OAEP_PARAMETERS, *PCRYPT_RSAES_OAEP_PARAMETERS;
typedef struct _CMC_TAGGED_ATTRIBUTE {
    DWORD dwBodyPartID;
    CRYPT_ATTRIBUTE Attribute;
} CMC_TAGGED_ATTRIBUTE, *PCMC_TAGGED_ATTRIBUTE;

typedef struct _CMC_TAGGED_CERT_REQUEST {
    DWORD dwBodyPartID;
    CRYPT_DER_BLOB SignedCertRequest;
} CMC_TAGGED_CERT_REQUEST, *PCMC_TAGGED_CERT_REQUEST;

typedef struct _CMC_TAGGED_REQUEST {
    DWORD dwTaggedRequestChoice;
    union {

        PCMC_TAGGED_CERT_REQUEST pTaggedCertRequest;
    }  u ;
} CMC_TAGGED_REQUEST, *PCMC_TAGGED_REQUEST;



typedef struct _CMC_TAGGED_CONTENT_INFO {
    DWORD dwBodyPartID;
    CRYPT_DER_BLOB EncodedContentInfo;
} CMC_TAGGED_CONTENT_INFO, *PCMC_TAGGED_CONTENT_INFO;

typedef struct _CMC_TAGGED_OTHER_MSG {
    DWORD dwBodyPartID;
    LPSTR pszObjId;
    CRYPT_OBJID_BLOB Value;
} CMC_TAGGED_OTHER_MSG, *PCMC_TAGGED_OTHER_MSG;



typedef struct _CMC_DATA_INFO {
    DWORD cTaggedAttribute;
    PCMC_TAGGED_ATTRIBUTE rgTaggedAttribute;
    DWORD cTaggedRequest;
    PCMC_TAGGED_REQUEST rgTaggedRequest;
    DWORD cTaggedContentInfo;
    PCMC_TAGGED_CONTENT_INFO rgTaggedContentInfo;
    DWORD cTaggedOtherMsg;
    PCMC_TAGGED_OTHER_MSG rgTaggedOtherMsg;
} CMC_DATA_INFO, *PCMC_DATA_INFO;



typedef struct _CMC_RESPONSE_INFO {
    DWORD cTaggedAttribute;
    PCMC_TAGGED_ATTRIBUTE rgTaggedAttribute;
    DWORD cTaggedContentInfo;
    PCMC_TAGGED_CONTENT_INFO rgTaggedContentInfo;
    DWORD cTaggedOtherMsg;
    PCMC_TAGGED_OTHER_MSG rgTaggedOtherMsg;
} CMC_RESPONSE_INFO, *PCMC_RESPONSE_INFO;









typedef struct _CMC_PEND_INFO {
    CRYPT_DATA_BLOB PendToken;
    FILETIME PendTime;
} CMC_PEND_INFO, *PCMC_PEND_INFO;

typedef struct _CMC_STATUS_INFO {
    DWORD dwStatus;
    DWORD cBodyList;
    DWORD *rgdwBodyList;
    LPWSTR pwszStatusString;
    DWORD dwOtherInfoChoice;
    union {



        DWORD dwFailInfo;

        PCMC_PEND_INFO pPendInfo;
    }  u ;
} CMC_STATUS_INFO, *PCMC_STATUS_INFO;
typedef struct _CMC_ADD_EXTENSIONS_INFO {
    DWORD dwCmcDataReference;
    DWORD cCertReference;
    DWORD *rgdwCertReference;
    DWORD cExtension;
    PCERT_EXTENSION rgExtension;
} CMC_ADD_EXTENSIONS_INFO, *PCMC_ADD_EXTENSIONS_INFO;










typedef struct _CMC_ADD_ATTRIBUTES_INFO {
    DWORD dwCmcDataReference;
    DWORD cCertReference;
    DWORD *rgdwCertReference;
    DWORD cAttribute;
    PCRYPT_ATTRIBUTE rgAttribute;
} CMC_ADD_ATTRIBUTES_INFO, *PCMC_ADD_ATTRIBUTES_INFO;









typedef struct _CERT_TEMPLATE_EXT {
    LPSTR pszObjId;
    DWORD dwMajorVersion;
    BOOL fMinorVersion;
    DWORD dwMinorVersion;
} CERT_TEMPLATE_EXT, *PCERT_TEMPLATE_EXT;










typedef struct _CERT_HASHED_URL {
    CRYPT_ALGORITHM_IDENTIFIER HashAlgorithm;
    CRYPT_HASH_BLOB Hash;
    LPWSTR pwszUrl;

} CERT_HASHED_URL, *PCERT_HASHED_URL;

typedef struct _CERT_LOGOTYPE_DETAILS {
    LPWSTR pwszMimeType;
    DWORD cHashedUrl;
    PCERT_HASHED_URL rgHashedUrl;
} CERT_LOGOTYPE_DETAILS, *PCERT_LOGOTYPE_DETAILS;

typedef struct _CERT_LOGOTYPE_REFERENCE {
    DWORD cHashedUrl;
    PCERT_HASHED_URL rgHashedUrl;
} CERT_LOGOTYPE_REFERENCE, *PCERT_LOGOTYPE_REFERENCE;

typedef struct _CERT_LOGOTYPE_IMAGE_INFO {


    DWORD dwLogotypeImageInfoChoice;

    DWORD dwFileSize;
    DWORD dwXSize;
    DWORD dwYSize;

    DWORD dwLogotypeImageResolutionChoice;
    union {




        DWORD dwNumBits;


        DWORD dwTableSize;
    }  u ;
    LPWSTR pwszLanguage;

} CERT_LOGOTYPE_IMAGE_INFO, *PCERT_LOGOTYPE_IMAGE_INFO;








typedef struct _CERT_LOGOTYPE_IMAGE {
    CERT_LOGOTYPE_DETAILS LogotypeDetails;

    PCERT_LOGOTYPE_IMAGE_INFO pLogotypeImageInfo;
} CERT_LOGOTYPE_IMAGE, *PCERT_LOGOTYPE_IMAGE;


typedef struct _CERT_LOGOTYPE_AUDIO_INFO {
    DWORD dwFileSize;
    DWORD dwPlayTime;
    DWORD dwChannels;
    DWORD dwSampleRate;

    LPWSTR pwszLanguage;

} CERT_LOGOTYPE_AUDIO_INFO, *PCERT_LOGOTYPE_AUDIO_INFO;

typedef struct _CERT_LOGOTYPE_AUDIO {
    CERT_LOGOTYPE_DETAILS LogotypeDetails;

    PCERT_LOGOTYPE_AUDIO_INFO pLogotypeAudioInfo;
} CERT_LOGOTYPE_AUDIO, *PCERT_LOGOTYPE_AUDIO;


typedef struct _CERT_LOGOTYPE_DATA {
    DWORD cLogotypeImage;
    PCERT_LOGOTYPE_IMAGE rgLogotypeImage;

    DWORD cLogotypeAudio;
    PCERT_LOGOTYPE_AUDIO rgLogotypeAudio;
} CERT_LOGOTYPE_DATA, *PCERT_LOGOTYPE_DATA;


typedef struct _CERT_LOGOTYPE_INFO {
    DWORD dwLogotypeInfoChoice;
    union {

        PCERT_LOGOTYPE_DATA pLogotypeDirectInfo;


        PCERT_LOGOTYPE_REFERENCE pLogotypeIndirectInfo;
    }  u ;
} CERT_LOGOTYPE_INFO, *PCERT_LOGOTYPE_INFO;




typedef struct _CERT_OTHER_LOGOTYPE_INFO {
    LPSTR pszObjId;
    CERT_LOGOTYPE_INFO LogotypeInfo;
} CERT_OTHER_LOGOTYPE_INFO, *PCERT_OTHER_LOGOTYPE_INFO;




typedef struct _CERT_LOGOTYPE_EXT_INFO {
    DWORD cCommunityLogo;
    PCERT_LOGOTYPE_INFO rgCommunityLogo;
    PCERT_LOGOTYPE_INFO pIssuerLogo;
    PCERT_LOGOTYPE_INFO pSubjectLogo;
    DWORD cOtherLogo;
    PCERT_OTHER_LOGOTYPE_INFO rgOtherLogo;
} CERT_LOGOTYPE_EXT_INFO, *PCERT_LOGOTYPE_EXT_INFO;
typedef struct _CERT_BIOMETRIC_DATA {
    DWORD dwTypeOfBiometricDataChoice;
    union {

        DWORD dwPredefined;


        LPSTR pszObjId;
    }  u ;

    CERT_HASHED_URL HashedUrl;
} CERT_BIOMETRIC_DATA, *PCERT_BIOMETRIC_DATA;








typedef struct _CERT_BIOMETRIC_EXT_INFO {
    DWORD cBiometricData;
    PCERT_BIOMETRIC_DATA rgBiometricData;
} CERT_BIOMETRIC_EXT_INFO, *PCERT_BIOMETRIC_EXT_INFO;
typedef struct _OCSP_SIGNATURE_INFO {
    CRYPT_ALGORITHM_IDENTIFIER SignatureAlgorithm;
    CRYPT_BIT_BLOB Signature;
    DWORD cCertEncoded;
    PCERT_BLOB rgCertEncoded;
} OCSP_SIGNATURE_INFO, *POCSP_SIGNATURE_INFO;

typedef struct _OCSP_SIGNED_REQUEST_INFO {
    CRYPT_DER_BLOB ToBeSigned;
    POCSP_SIGNATURE_INFO pOptionalSignatureInfo;
} OCSP_SIGNED_REQUEST_INFO, *POCSP_SIGNED_REQUEST_INFO;







typedef struct _OCSP_CERT_ID {
    CRYPT_ALGORITHM_IDENTIFIER HashAlgorithm;
    CRYPT_HASH_BLOB IssuerNameHash;
    CRYPT_HASH_BLOB IssuerKeyHash;
    CRYPT_INTEGER_BLOB SerialNumber;
} OCSP_CERT_ID, *POCSP_CERT_ID;

typedef struct _OCSP_REQUEST_ENTRY {
    OCSP_CERT_ID CertId;
    DWORD cExtension;
    PCERT_EXTENSION rgExtension;
} OCSP_REQUEST_ENTRY, *POCSP_REQUEST_ENTRY;

typedef struct _OCSP_REQUEST_INFO {
    DWORD dwVersion;
    PCERT_ALT_NAME_ENTRY pRequestorName;
    DWORD cRequestEntry;
    POCSP_REQUEST_ENTRY rgRequestEntry;
    DWORD cExtension;
    PCERT_EXTENSION rgExtension;
} OCSP_REQUEST_INFO, *POCSP_REQUEST_INFO;








typedef struct _OCSP_RESPONSE_INFO {
    DWORD dwStatus;
    LPSTR pszObjId;
    CRYPT_OBJID_BLOB Value;
} OCSP_RESPONSE_INFO, *POCSP_RESPONSE_INFO;
typedef struct _OCSP_BASIC_SIGNED_RESPONSE_INFO {
    CRYPT_DER_BLOB ToBeSigned;
    OCSP_SIGNATURE_INFO SignatureInfo;
} OCSP_BASIC_SIGNED_RESPONSE_INFO, *POCSP_BASIC_SIGNED_RESPONSE_INFO;







typedef struct _OCSP_BASIC_REVOKED_INFO {
    FILETIME RevocationDate;


    DWORD dwCrlReasonCode;
} OCSP_BASIC_REVOKED_INFO, *POCSP_BASIC_REVOKED_INFO;

typedef struct _OCSP_BASIC_RESPONSE_ENTRY {
    OCSP_CERT_ID CertId;
    DWORD dwCertStatus;
    union {





        POCSP_BASIC_REVOKED_INFO pRevokedInfo;

    }  u ;
    FILETIME ThisUpdate;
    FILETIME NextUpdate;

    DWORD cExtension;
    PCERT_EXTENSION rgExtension;
} OCSP_BASIC_RESPONSE_ENTRY, *POCSP_BASIC_RESPONSE_ENTRY;






typedef struct _OCSP_BASIC_RESPONSE_INFO {
    DWORD dwVersion;
    DWORD dwResponderIdChoice;
    union {

        CERT_NAME_BLOB ByNameResponderId;

        CRYPT_HASH_BLOB ByKeyResponderId;
    }  u ;
    FILETIME ProducedAt;
    DWORD cResponseEntry;
    POCSP_BASIC_RESPONSE_ENTRY rgResponseEntry;
    DWORD cExtension;
    PCERT_EXTENSION rgExtension;
} OCSP_BASIC_RESPONSE_INFO, *POCSP_BASIC_RESPONSE_INFO;
typedef void *HCRYPTOIDFUNCSET;
typedef void *HCRYPTOIDFUNCADDR;
typedef struct _CRYPT_OID_FUNC_ENTRY {
    LPCSTR pszOID;
    void *pvFuncAddr;
} CRYPT_OID_FUNC_ENTRY, *PCRYPT_OID_FUNC_ENTRY;
__declspec(dllimport)
BOOL

CryptInstallOIDFunctionAddress(
     HMODULE hModule,
     DWORD dwEncodingType,
     LPCSTR pszFuncName,
     DWORD cFuncEntry,
     const CRYPT_OID_FUNC_ENTRY rgFuncEntry[],
     DWORD dwFlags
    );







__declspec(dllimport)
HCRYPTOIDFUNCSET

CryptInitOIDFunctionSet(
     LPCSTR pszFuncName,
     DWORD dwFlags
    );
__declspec(dllimport)

BOOL

CryptGetOIDFunctionAddress(
     HCRYPTOIDFUNCSET hFuncSet,
     DWORD dwEncodingType,
     LPCSTR pszOID,
     DWORD dwFlags,
     void **ppvFuncAddr,
     HCRYPTOIDFUNCADDR *phFuncAddr
    );
__declspec(dllimport)
BOOL

CryptGetDefaultOIDDllList(
     HCRYPTOIDFUNCSET hFuncSet,
     DWORD dwEncodingType,
       WCHAR *pwszDllList,
     DWORD *pcchDllList
    );
__declspec(dllimport)

BOOL

CryptGetDefaultOIDFunctionAddress(
     HCRYPTOIDFUNCSET hFuncSet,
     DWORD dwEncodingType,
     LPCWSTR pwszDll,
     DWORD dwFlags,
     void **ppvFuncAddr,
     HCRYPTOIDFUNCADDR *phFuncAddr
    );
__declspec(dllimport)
BOOL

CryptFreeOIDFunctionAddress(
     HCRYPTOIDFUNCADDR hFuncAddr,
     DWORD dwFlags
    );
__declspec(dllimport)
BOOL

CryptRegisterOIDFunction(
     DWORD dwEncodingType,
     LPCSTR pszFuncName,
     LPCSTR pszOID,
     LPCWSTR pwszDll,
     LPCSTR pszOverrideFuncName
    );





__declspec(dllimport)
BOOL

CryptUnregisterOIDFunction(
     DWORD dwEncodingType,
     LPCSTR pszFuncName,
     LPCSTR pszOID
    );
__declspec(dllimport)
BOOL

CryptRegisterDefaultOIDFunction(
     DWORD dwEncodingType,
     LPCSTR pszFuncName,
     DWORD dwIndex,
     LPCWSTR pwszDll
    );








__declspec(dllimport)
BOOL

CryptUnregisterDefaultOIDFunction(
     DWORD dwEncodingType,
     LPCSTR pszFuncName,
     LPCWSTR pwszDll
    );









__declspec(dllimport)
BOOL

CryptSetOIDFunctionValue(
     DWORD dwEncodingType,
     LPCSTR pszFuncName,
     LPCSTR pszOID,
     LPCWSTR pwszValueName,
     DWORD dwValueType,
     const BYTE *pbValueData,
     DWORD cbValueData
    );









__declspec(dllimport)
BOOL

CryptGetOIDFunctionValue(
     DWORD dwEncodingType,
     LPCSTR pszFuncName,
     LPCSTR pszOID,
     LPCWSTR pwszValueName,
     DWORD *pdwValueType,
     BYTE *pbValueData,
     DWORD *pcbValueData
    );

typedef BOOL (  *PFN_CRYPT_ENUM_OID_FUNC)(
     DWORD dwEncodingType,
     LPCSTR pszFuncName,
     LPCSTR pszOID,
     DWORD cValue,
     const DWORD rgdwValueType[],
     LPCWSTR const rgpwszValueName[],
     const BYTE * const rgpbValueData[],
     const DWORD rgcbValueData[],
     void *pvArg
    );
__declspec(dllimport)
BOOL

CryptEnumOIDFunction(
     DWORD dwEncodingType,
     LPCSTR pszFuncName,
     LPCSTR pszOID,
     DWORD dwFlags,
     void *pvArg,
     PFN_CRYPT_ENUM_OID_FUNC pfnEnumOIDFunc
    );
typedef struct _CRYPT_OID_INFO {
    DWORD cbSize;
    LPCSTR pszOID;
    LPCWSTR pwszName;
    DWORD dwGroupId;
    union {
        DWORD dwValue;
        ALG_ID Algid;
        DWORD dwLength;
    }  u ;
    CRYPT_DATA_BLOB ExtraInfo;
} CRYPT_OID_INFO, *PCRYPT_OID_INFO;
typedef const CRYPT_OID_INFO CCRYPT_OID_INFO, *PCCRYPT_OID_INFO;
__declspec(dllimport)
PCCRYPT_OID_INFO

CryptFindOIDInfo(
     DWORD dwKeyType,
     void *pvKey,
     DWORD dwGroupId
    );
__declspec(dllimport)
BOOL

CryptRegisterOIDInfo(
     PCCRYPT_OID_INFO pInfo,
     DWORD dwFlags
    );







__declspec(dllimport)
BOOL

CryptUnregisterOIDInfo(
     PCCRYPT_OID_INFO pInfo
    );


typedef BOOL (  *PFN_CRYPT_ENUM_OID_INFO)(
     PCCRYPT_OID_INFO pInfo,
     void *pvArg
    );
__declspec(dllimport)
BOOL

CryptEnumOIDInfo(
     DWORD dwGroupId,
     DWORD dwFlags,
     void *pvArg,
     PFN_CRYPT_ENUM_OID_INFO pfnEnumOIDInfo
    );
__declspec(dllimport)
LPCWSTR

CryptFindLocalizedName(
     LPCWSTR pwszCryptName
    );








typedef void *HCRYPTMSG;
typedef struct _CERT_ISSUER_SERIAL_NUMBER {
    CERT_NAME_BLOB Issuer;
    CRYPT_INTEGER_BLOB SerialNumber;
} CERT_ISSUER_SERIAL_NUMBER, *PCERT_ISSUER_SERIAL_NUMBER;




typedef struct _CERT_ID {
    DWORD dwIdChoice;
    union {

        CERT_ISSUER_SERIAL_NUMBER IssuerSerialNumber;

        CRYPT_HASH_BLOB KeyId;

        CRYPT_HASH_BLOB HashId;
    }  u ;
} CERT_ID, *PCERT_ID;
typedef struct _CMSG_SIGNER_ENCODE_INFO {
    DWORD cbSize;
    PCERT_INFO pCertInfo;


    union {
        HCRYPTPROV hCryptProv;
        NCRYPT_KEY_HANDLE hNCryptKey;
    }  u ;


    DWORD dwKeySpec;

    CRYPT_ALGORITHM_IDENTIFIER HashAlgorithm;
    void *pvHashAuxInfo;
    DWORD cAuthAttr;
    PCRYPT_ATTRIBUTE rgAuthAttr;
    DWORD cUnauthAttr;
    PCRYPT_ATTRIBUTE rgUnauthAttr;
} CMSG_SIGNER_ENCODE_INFO, *PCMSG_SIGNER_ENCODE_INFO;

typedef struct _CMSG_SIGNED_ENCODE_INFO {
    DWORD cbSize;
    DWORD cSigners;
    PCMSG_SIGNER_ENCODE_INFO rgSigners;
    DWORD cCertEncoded;
    PCERT_BLOB rgCertEncoded;
    DWORD cCrlEncoded;
    PCRL_BLOB rgCrlEncoded;
} CMSG_SIGNED_ENCODE_INFO, *PCMSG_SIGNED_ENCODE_INFO;
typedef struct _CMSG_RECIPIENT_ENCODE_INFO CMSG_RECIPIENT_ENCODE_INFO,
    *PCMSG_RECIPIENT_ENCODE_INFO;

typedef struct _CMSG_ENVELOPED_ENCODE_INFO {
    DWORD cbSize;
    HCRYPTPROV_LEGACY hCryptProv;
    CRYPT_ALGORITHM_IDENTIFIER ContentEncryptionAlgorithm;
    void *pvEncryptionAuxInfo;
    DWORD cRecipients;




    PCERT_INFO *rgpRecipients;
} CMSG_ENVELOPED_ENCODE_INFO, *PCMSG_ENVELOPED_ENCODE_INFO;
typedef struct _CMSG_KEY_TRANS_RECIPIENT_ENCODE_INFO {
    DWORD cbSize;
    CRYPT_ALGORITHM_IDENTIFIER KeyEncryptionAlgorithm;
    void *pvKeyEncryptionAuxInfo;
    HCRYPTPROV_LEGACY hCryptProv;
    CRYPT_BIT_BLOB RecipientPublicKey;
    CERT_ID RecipientId;
} CMSG_KEY_TRANS_RECIPIENT_ENCODE_INFO, *PCMSG_KEY_TRANS_RECIPIENT_ENCODE_INFO;
typedef struct _CMSG_RECIPIENT_ENCRYPTED_KEY_ENCODE_INFO {
    DWORD cbSize;
    CRYPT_BIT_BLOB RecipientPublicKey;
    CERT_ID RecipientId;



    FILETIME Date;
    PCRYPT_ATTRIBUTE_TYPE_VALUE pOtherAttr;
} CMSG_RECIPIENT_ENCRYPTED_KEY_ENCODE_INFO,
    *PCMSG_RECIPIENT_ENCRYPTED_KEY_ENCODE_INFO;

typedef struct _CMSG_KEY_AGREE_RECIPIENT_ENCODE_INFO {
    DWORD cbSize;
    CRYPT_ALGORITHM_IDENTIFIER KeyEncryptionAlgorithm;
    void *pvKeyEncryptionAuxInfo;
    CRYPT_ALGORITHM_IDENTIFIER KeyWrapAlgorithm;
    void *pvKeyWrapAuxInfo;







    HCRYPTPROV_LEGACY hCryptProv;
    DWORD dwKeySpec;

    DWORD dwKeyChoice;
    union {



        PCRYPT_ALGORITHM_IDENTIFIER pEphemeralAlgorithm;




        PCERT_ID pSenderId;
    }  u ;
    CRYPT_DATA_BLOB UserKeyingMaterial;

    DWORD cRecipientEncryptedKeys;
    PCMSG_RECIPIENT_ENCRYPTED_KEY_ENCODE_INFO *rgpRecipientEncryptedKeys;
} CMSG_KEY_AGREE_RECIPIENT_ENCODE_INFO, *PCMSG_KEY_AGREE_RECIPIENT_ENCODE_INFO;
typedef struct _CMSG_MAIL_LIST_RECIPIENT_ENCODE_INFO {
    DWORD cbSize;
    CRYPT_ALGORITHM_IDENTIFIER KeyEncryptionAlgorithm;
    void *pvKeyEncryptionAuxInfo;
    HCRYPTPROV hCryptProv;
    DWORD dwKeyChoice;
    union {

        HCRYPTKEY hKeyEncryptionKey;

        void *pvKeyEncryptionKey;
    }  u ;
    CRYPT_DATA_BLOB KeyId;


    FILETIME Date;
    PCRYPT_ATTRIBUTE_TYPE_VALUE pOtherAttr;
} CMSG_MAIL_LIST_RECIPIENT_ENCODE_INFO, *PCMSG_MAIL_LIST_RECIPIENT_ENCODE_INFO;








struct _CMSG_RECIPIENT_ENCODE_INFO {
    DWORD dwRecipientChoice;
    union {

        PCMSG_KEY_TRANS_RECIPIENT_ENCODE_INFO pKeyTrans;

        PCMSG_KEY_AGREE_RECIPIENT_ENCODE_INFO pKeyAgree;

        PCMSG_MAIL_LIST_RECIPIENT_ENCODE_INFO pMailList;
    }  u ;
};
typedef struct _CMSG_RC2_AUX_INFO {
    DWORD cbSize;
    DWORD dwBitLen;
} CMSG_RC2_AUX_INFO, *PCMSG_RC2_AUX_INFO;
typedef struct _CMSG_SP3_COMPATIBLE_AUX_INFO {
    DWORD cbSize;
    DWORD dwFlags;
} CMSG_SP3_COMPATIBLE_AUX_INFO, *PCMSG_SP3_COMPATIBLE_AUX_INFO;
typedef struct _CMSG_RC4_AUX_INFO {
    DWORD cbSize;
    DWORD dwBitLen;
} CMSG_RC4_AUX_INFO, *PCMSG_RC4_AUX_INFO;










typedef struct _CMSG_SIGNED_AND_ENVELOPED_ENCODE_INFO {
    DWORD cbSize;
    CMSG_SIGNED_ENCODE_INFO SignedInfo;
    CMSG_ENVELOPED_ENCODE_INFO EnvelopedInfo;
} CMSG_SIGNED_AND_ENVELOPED_ENCODE_INFO, *PCMSG_SIGNED_AND_ENVELOPED_ENCODE_INFO;
typedef struct _CMSG_HASHED_ENCODE_INFO {
    DWORD cbSize;
    HCRYPTPROV_LEGACY hCryptProv;
    CRYPT_ALGORITHM_IDENTIFIER HashAlgorithm;
    void *pvHashAuxInfo;
} CMSG_HASHED_ENCODE_INFO, *PCMSG_HASHED_ENCODE_INFO;
typedef struct _CMSG_ENCRYPTED_ENCODE_INFO {
    DWORD cbSize;
    CRYPT_ALGORITHM_IDENTIFIER ContentEncryptionAlgorithm;
    void *pvEncryptionAuxInfo;
} CMSG_ENCRYPTED_ENCODE_INFO, *PCMSG_ENCRYPTED_ENCODE_INFO;
typedef BOOL (  *PFN_CMSG_STREAM_OUTPUT)(
     const void *pvArg,
     BYTE *pbData,
     DWORD cbData,
     BOOL fFinal
    );



typedef struct _CMSG_STREAM_INFO {
    DWORD cbContent;
    PFN_CMSG_STREAM_OUTPUT pfnStreamOutput;
    void *pvArg;
} CMSG_STREAM_INFO, *PCMSG_STREAM_INFO;
__declspec(dllimport)
HCRYPTMSG

CryptMsgOpenToEncode(
     DWORD dwMsgEncodingType,
     DWORD dwFlags,
     DWORD dwMsgType,
     void const *pvMsgEncodeInfo,
     LPSTR pszInnerContentObjID,
     PCMSG_STREAM_INFO pStreamInfo
    );









__declspec(dllimport)
DWORD

CryptMsgCalculateEncodedLength(
     DWORD dwMsgEncodingType,
     DWORD dwFlags,
     DWORD dwMsgType,
     void const *pvMsgEncodeInfo,
     LPSTR pszInnerContentObjID,
     DWORD cbData
    );
__declspec(dllimport)
HCRYPTMSG

CryptMsgOpenToDecode(
     DWORD dwMsgEncodingType,
     DWORD dwFlags,
     DWORD dwMsgType,
     HCRYPTPROV_LEGACY hCryptProv,
     PCERT_INFO pRecipientInfo,
     PCMSG_STREAM_INFO pStreamInfo
    );




__declspec(dllimport)
HCRYPTMSG

CryptMsgDuplicate(
     HCRYPTMSG hCryptMsg
    );






__declspec(dllimport)
BOOL

CryptMsgClose(
     HCRYPTMSG hCryptMsg
    );










__declspec(dllimport)
BOOL

CryptMsgUpdate(
     HCRYPTMSG hCryptMsg,
     const BYTE *pbData,
     DWORD cbData,
     BOOL fFinal
    );
__declspec(dllimport)
BOOL

CryptMsgGetParam(
     HCRYPTMSG hCryptMsg,
     DWORD dwParamType,
     DWORD dwIndex,
     void *pvData,
     DWORD *pcbData
    );
typedef struct _CMSG_SIGNER_INFO {
    DWORD dwVersion;
    CERT_NAME_BLOB Issuer;
    CRYPT_INTEGER_BLOB SerialNumber;
    CRYPT_ALGORITHM_IDENTIFIER HashAlgorithm;


    CRYPT_ALGORITHM_IDENTIFIER HashEncryptionAlgorithm;

    CRYPT_DATA_BLOB EncryptedHash;
    CRYPT_ATTRIBUTES AuthAttrs;
    CRYPT_ATTRIBUTES UnauthAttrs;
} CMSG_SIGNER_INFO, *PCMSG_SIGNER_INFO;
typedef struct _CMSG_CMS_SIGNER_INFO {
    DWORD dwVersion;
    CERT_ID SignerId;
    CRYPT_ALGORITHM_IDENTIFIER HashAlgorithm;


    CRYPT_ALGORITHM_IDENTIFIER HashEncryptionAlgorithm;

    CRYPT_DATA_BLOB EncryptedHash;
    CRYPT_ATTRIBUTES AuthAttrs;
    CRYPT_ATTRIBUTES UnauthAttrs;
} CMSG_CMS_SIGNER_INFO, *PCMSG_CMS_SIGNER_INFO;
typedef CRYPT_ATTRIBUTES CMSG_ATTR;
typedef CRYPT_ATTRIBUTES *PCMSG_ATTR;
typedef struct _CMSG_KEY_TRANS_RECIPIENT_INFO {
    DWORD dwVersion;


    CERT_ID RecipientId;

    CRYPT_ALGORITHM_IDENTIFIER KeyEncryptionAlgorithm;
    CRYPT_DATA_BLOB EncryptedKey;
} CMSG_KEY_TRANS_RECIPIENT_INFO, *PCMSG_KEY_TRANS_RECIPIENT_INFO;

typedef struct _CMSG_RECIPIENT_ENCRYPTED_KEY_INFO {

    CERT_ID RecipientId;

    CRYPT_DATA_BLOB EncryptedKey;


    FILETIME Date;
    PCRYPT_ATTRIBUTE_TYPE_VALUE pOtherAttr;
} CMSG_RECIPIENT_ENCRYPTED_KEY_INFO, *PCMSG_RECIPIENT_ENCRYPTED_KEY_INFO;

typedef struct _CMSG_KEY_AGREE_RECIPIENT_INFO {
    DWORD dwVersion;
    DWORD dwOriginatorChoice;
    union {

        CERT_ID OriginatorCertId;

        CERT_PUBLIC_KEY_INFO OriginatorPublicKeyInfo;
    }  u ;
    CRYPT_DATA_BLOB UserKeyingMaterial;
    CRYPT_ALGORITHM_IDENTIFIER KeyEncryptionAlgorithm;

    DWORD cRecipientEncryptedKeys;
    PCMSG_RECIPIENT_ENCRYPTED_KEY_INFO *rgpRecipientEncryptedKeys;
} CMSG_KEY_AGREE_RECIPIENT_INFO, *PCMSG_KEY_AGREE_RECIPIENT_INFO;





typedef struct _CMSG_MAIL_LIST_RECIPIENT_INFO {
    DWORD dwVersion;
    CRYPT_DATA_BLOB KeyId;
    CRYPT_ALGORITHM_IDENTIFIER KeyEncryptionAlgorithm;
    CRYPT_DATA_BLOB EncryptedKey;


    FILETIME Date;
    PCRYPT_ATTRIBUTE_TYPE_VALUE pOtherAttr;
} CMSG_MAIL_LIST_RECIPIENT_INFO, *PCMSG_MAIL_LIST_RECIPIENT_INFO;

typedef struct _CMSG_CMS_RECIPIENT_INFO {
    DWORD dwRecipientChoice;
    union {

        PCMSG_KEY_TRANS_RECIPIENT_INFO pKeyTrans;

        PCMSG_KEY_AGREE_RECIPIENT_INFO pKeyAgree;

        PCMSG_MAIL_LIST_RECIPIENT_INFO pMailList;
    }  u ;
} CMSG_CMS_RECIPIENT_INFO, *PCMSG_CMS_RECIPIENT_INFO;
__declspec(dllimport)
BOOL

CryptMsgControl(
     HCRYPTMSG hCryptMsg,
     DWORD dwFlags,
     DWORD dwCtrlType,
     void const *pvCtrlPara
    );
typedef struct _CMSG_CTRL_VERIFY_SIGNATURE_EX_PARA {
    DWORD cbSize;
    HCRYPTPROV_LEGACY hCryptProv;
    DWORD dwSignerIndex;
    DWORD dwSignerType;
    void *pvSigner;
} CMSG_CTRL_VERIFY_SIGNATURE_EX_PARA, *PCMSG_CTRL_VERIFY_SIGNATURE_EX_PARA;
typedef struct _CMSG_CTRL_DECRYPT_PARA {
    DWORD cbSize;


    union {
        HCRYPTPROV hCryptProv;
        NCRYPT_KEY_HANDLE hNCryptKey;
    }  u ;


    DWORD dwKeySpec;

    DWORD dwRecipientIndex;
} CMSG_CTRL_DECRYPT_PARA, *PCMSG_CTRL_DECRYPT_PARA;
typedef struct _CMSG_CTRL_KEY_TRANS_DECRYPT_PARA {
    DWORD cbSize;

    union {
        HCRYPTPROV hCryptProv;
        NCRYPT_KEY_HANDLE hNCryptKey;
    }  u ;


    DWORD dwKeySpec;

    PCMSG_KEY_TRANS_RECIPIENT_INFO pKeyTrans;
    DWORD dwRecipientIndex;
} CMSG_CTRL_KEY_TRANS_DECRYPT_PARA, *PCMSG_CTRL_KEY_TRANS_DECRYPT_PARA;
typedef struct _CMSG_CTRL_KEY_AGREE_DECRYPT_PARA {
    DWORD cbSize;


    union {
        HCRYPTPROV hCryptProv;
        NCRYPT_KEY_HANDLE hNCryptKey;
    }  u ;


    DWORD dwKeySpec;

    PCMSG_KEY_AGREE_RECIPIENT_INFO pKeyAgree;
    DWORD dwRecipientIndex;
    DWORD dwRecipientEncryptedKeyIndex;
    CRYPT_BIT_BLOB OriginatorPublicKey;
} CMSG_CTRL_KEY_AGREE_DECRYPT_PARA, *PCMSG_CTRL_KEY_AGREE_DECRYPT_PARA;
typedef struct _CMSG_CTRL_MAIL_LIST_DECRYPT_PARA {
    DWORD cbSize;
    HCRYPTPROV hCryptProv;
    PCMSG_MAIL_LIST_RECIPIENT_INFO pMailList;
    DWORD dwRecipientIndex;
    DWORD dwKeyChoice;
    union {

        HCRYPTKEY hKeyEncryptionKey;

        void *pvKeyEncryptionKey;
    }  u ;
} CMSG_CTRL_MAIL_LIST_DECRYPT_PARA, *PCMSG_CTRL_MAIL_LIST_DECRYPT_PARA;
typedef struct _CMSG_CTRL_ADD_SIGNER_UNAUTH_ATTR_PARA {
    DWORD cbSize;
    DWORD dwSignerIndex;
    CRYPT_DATA_BLOB blob;
} CMSG_CTRL_ADD_SIGNER_UNAUTH_ATTR_PARA, *PCMSG_CTRL_ADD_SIGNER_UNAUTH_ATTR_PARA;
typedef struct _CMSG_CTRL_DEL_SIGNER_UNAUTH_ATTR_PARA {
    DWORD cbSize;
    DWORD dwSignerIndex;
    DWORD dwUnauthAttrIndex;
} CMSG_CTRL_DEL_SIGNER_UNAUTH_ATTR_PARA, *PCMSG_CTRL_DEL_SIGNER_UNAUTH_ATTR_PARA;
BOOL

CryptMsgVerifyCountersignatureEncoded(
     HCRYPTPROV_LEGACY hCryptProv,
     DWORD dwEncodingType,
     PBYTE pbSignerInfo,
     DWORD cbSignerInfo,
     PBYTE pbSignerInfoCountersignature,
     DWORD cbSignerInfoCountersignature,
     PCERT_INFO pciCountersigner
    );
BOOL

CryptMsgVerifyCountersignatureEncodedEx(
     HCRYPTPROV_LEGACY hCryptProv,
     DWORD dwEncodingType,
     PBYTE pbSignerInfo,
     DWORD cbSignerInfo,
     PBYTE pbSignerInfoCountersignature,
     DWORD cbSignerInfoCountersignature,
     DWORD dwSignerType,
     void *pvSigner,
     DWORD dwFlags,
     void *pvReserved
    );










BOOL

CryptMsgCountersign(
     HCRYPTMSG hCryptMsg,
     DWORD dwIndex,
     DWORD cCountersigners,
     PCMSG_SIGNER_ENCODE_INFO rgCountersigners
    );







BOOL

CryptMsgCountersignEncoded(
     DWORD dwEncodingType,
     PBYTE pbSignerInfo,
     DWORD cbSignerInfo,
     DWORD cCountersigners,
     PCMSG_SIGNER_ENCODE_INFO rgCountersigners,
     PBYTE pbCountersignature,
     PDWORD pcbCountersignature
    );








typedef void * (  *PFN_CMSG_ALLOC) (
     size_t cb
    );

typedef void (  *PFN_CMSG_FREE)(
     void *pv
    );
typedef   BOOL (  *PFN_CMSG_GEN_ENCRYPT_KEY) (
     HCRYPTPROV *phCryptProv,
     PCRYPT_ALGORITHM_IDENTIFIER paiEncrypt,
     PVOID pvEncryptAuxInfo,
     PCERT_PUBLIC_KEY_INFO pPublicKeyInfo,
     PFN_CMSG_ALLOC pfnAlloc,
     HCRYPTKEY *phEncryptKey,
     PBYTE *ppbEncryptParameters,
     PDWORD pcbEncryptParameters
    );


typedef BOOL (  *PFN_CMSG_EXPORT_ENCRYPT_KEY) (
     HCRYPTPROV hCryptProv,
     HCRYPTKEY hEncryptKey,
     PCERT_PUBLIC_KEY_INFO pPublicKeyInfo,
     PBYTE pbData,
     PDWORD pcbData
    );


typedef BOOL (  *PFN_CMSG_IMPORT_ENCRYPT_KEY) (
     HCRYPTPROV hCryptProv,
     DWORD dwKeySpec,
     PCRYPT_ALGORITHM_IDENTIFIER paiEncrypt,
     PCRYPT_ALGORITHM_IDENTIFIER paiPubKey,
     PBYTE pbEncodedKey,
     DWORD cbEncodedKey,
     HCRYPTKEY *phEncryptKey
    );
typedef struct _CMSG_CONTENT_ENCRYPT_INFO {
    DWORD cbSize;
    HCRYPTPROV_LEGACY hCryptProv;
    CRYPT_ALGORITHM_IDENTIFIER ContentEncryptionAlgorithm;
    void *pvEncryptionAuxInfo;
    DWORD cRecipients;
    PCMSG_RECIPIENT_ENCODE_INFO rgCmsRecipients;
    PFN_CMSG_ALLOC pfnAlloc;
    PFN_CMSG_FREE pfnFree;
    DWORD dwEncryptFlags;
    union {

        HCRYPTKEY hContentEncryptKey;

        BCRYPT_KEY_HANDLE hCNGContentEncryptKey;
    }  u ;
    DWORD dwFlags;

    BOOL fCNG;

    BYTE *pbCNGContentEncryptKeyObject;
    BYTE *pbContentEncryptKey;
    DWORD cbContentEncryptKey;
} CMSG_CONTENT_ENCRYPT_INFO, *PCMSG_CONTENT_ENCRYPT_INFO;
typedef BOOL (  *PFN_CMSG_GEN_CONTENT_ENCRYPT_KEY) (
     PCMSG_CONTENT_ENCRYPT_INFO pContentEncryptInfo,
     DWORD dwFlags,
     void *pvReserved
    );
typedef struct _CMSG_KEY_TRANS_ENCRYPT_INFO {
    DWORD cbSize;
    DWORD dwRecipientIndex;
    CRYPT_ALGORITHM_IDENTIFIER KeyEncryptionAlgorithm;
    CRYPT_DATA_BLOB EncryptedKey;
    DWORD dwFlags;
} CMSG_KEY_TRANS_ENCRYPT_INFO, *PCMSG_KEY_TRANS_ENCRYPT_INFO;
typedef BOOL (  *PFN_CMSG_EXPORT_KEY_TRANS) (
     PCMSG_CONTENT_ENCRYPT_INFO pContentEncryptInfo,
     PCMSG_KEY_TRANS_RECIPIENT_ENCODE_INFO pKeyTransEncodeInfo,
     PCMSG_KEY_TRANS_ENCRYPT_INFO pKeyTransEncryptInfo,
     DWORD dwFlags,
     void *pvReserved
    );
typedef struct _CMSG_KEY_AGREE_KEY_ENCRYPT_INFO {
    DWORD cbSize;
    CRYPT_DATA_BLOB EncryptedKey;
} CMSG_KEY_AGREE_KEY_ENCRYPT_INFO, *PCMSG_KEY_AGREE_KEY_ENCRYPT_INFO;







typedef struct _CMSG_KEY_AGREE_ENCRYPT_INFO {
    DWORD cbSize;
    DWORD dwRecipientIndex;
    CRYPT_ALGORITHM_IDENTIFIER KeyEncryptionAlgorithm;
    CRYPT_DATA_BLOB UserKeyingMaterial;
    DWORD dwOriginatorChoice;
    union {

        CERT_ID OriginatorCertId;

        CERT_PUBLIC_KEY_INFO OriginatorPublicKeyInfo;
    }  u ;
    DWORD cKeyAgreeKeyEncryptInfo;
    PCMSG_KEY_AGREE_KEY_ENCRYPT_INFO *rgpKeyAgreeKeyEncryptInfo;
    DWORD dwFlags;
} CMSG_KEY_AGREE_ENCRYPT_INFO, *PCMSG_KEY_AGREE_ENCRYPT_INFO;
typedef BOOL (  *PFN_CMSG_EXPORT_KEY_AGREE) (
     PCMSG_CONTENT_ENCRYPT_INFO pContentEncryptInfo,
     PCMSG_KEY_AGREE_RECIPIENT_ENCODE_INFO pKeyAgreeEncodeInfo,
     PCMSG_KEY_AGREE_ENCRYPT_INFO pKeyAgreeEncryptInfo,
     DWORD dwFlags,
     void *pvReserved
    );
typedef struct _CMSG_MAIL_LIST_ENCRYPT_INFO {
    DWORD cbSize;
    DWORD dwRecipientIndex;
    CRYPT_ALGORITHM_IDENTIFIER KeyEncryptionAlgorithm;
    CRYPT_DATA_BLOB EncryptedKey;
    DWORD dwFlags;
} CMSG_MAIL_LIST_ENCRYPT_INFO, *PCMSG_MAIL_LIST_ENCRYPT_INFO;
typedef BOOL (  *PFN_CMSG_EXPORT_MAIL_LIST) (
     PCMSG_CONTENT_ENCRYPT_INFO pContentEncryptInfo,
     PCMSG_MAIL_LIST_RECIPIENT_ENCODE_INFO pMailListEncodeInfo,
     PCMSG_MAIL_LIST_ENCRYPT_INFO pMailListEncryptInfo,
     DWORD dwFlags,
     void *pvReserved
    );
typedef BOOL (  *PFN_CMSG_IMPORT_KEY_TRANS) (
     PCRYPT_ALGORITHM_IDENTIFIER pContentEncryptionAlgorithm,
     PCMSG_CTRL_KEY_TRANS_DECRYPT_PARA pKeyTransDecryptPara,
     DWORD dwFlags,
     void *pvReserved,
     HCRYPTKEY *phContentEncryptKey
    );



typedef BOOL (  *PFN_CMSG_IMPORT_KEY_AGREE) (
     PCRYPT_ALGORITHM_IDENTIFIER pContentEncryptionAlgorithm,
     PCMSG_CTRL_KEY_AGREE_DECRYPT_PARA pKeyAgreeDecryptPara,
     DWORD dwFlags,
     void *pvReserved,
     HCRYPTKEY *phContentEncryptKey
    );



typedef BOOL (  *PFN_CMSG_IMPORT_MAIL_LIST) (
     PCRYPT_ALGORITHM_IDENTIFIER pContentEncryptionAlgorithm,
     PCMSG_CTRL_MAIL_LIST_DECRYPT_PARA pMailListDecryptPara,
     DWORD dwFlags,
     void *pvReserved,
     HCRYPTKEY *phContentEncryptKey
    );
typedef struct _CMSG_CNG_CONTENT_DECRYPT_INFO {
    DWORD cbSize;
    CRYPT_ALGORITHM_IDENTIFIER ContentEncryptionAlgorithm;
    PFN_CMSG_ALLOC pfnAlloc;
    PFN_CMSG_FREE pfnFree;




    NCRYPT_KEY_HANDLE hNCryptKey;

    BYTE *pbContentEncryptKey;
    DWORD cbContentEncryptKey;

    BCRYPT_KEY_HANDLE hCNGContentEncryptKey;
    BYTE *pbCNGContentEncryptKeyObject;
} CMSG_CNG_CONTENT_DECRYPT_INFO, *PCMSG_CNG_CONTENT_DECRYPT_INFO;
typedef BOOL (  *PFN_CMSG_CNG_IMPORT_KEY_TRANS) (
     PCMSG_CNG_CONTENT_DECRYPT_INFO pCNGContentDecryptInfo,
     PCMSG_CTRL_KEY_TRANS_DECRYPT_PARA pKeyTransDecryptPara,
     DWORD dwFlags,
     void *pvReserved
    );
typedef BOOL (  *PFN_CMSG_CNG_IMPORT_KEY_AGREE) (
     PCMSG_CNG_CONTENT_DECRYPT_INFO pCNGContentDecryptInfo,
     PCMSG_CTRL_KEY_AGREE_DECRYPT_PARA pKeyAgreeDecryptPara,
     DWORD dwFlags,
     void *pvReserved
    );
typedef BOOL (  *PFN_CMSG_CNG_IMPORT_CONTENT_ENCRYPT_KEY) (
     PCMSG_CNG_CONTENT_DECRYPT_INFO pCNGContentDecryptInfo,
     DWORD dwFlags,
     void *pvReserved
    );
typedef void *HCERTSTORE;
typedef struct _CERT_CONTEXT {
    DWORD dwCertEncodingType;
    BYTE *pbCertEncoded;
    DWORD cbCertEncoded;
    PCERT_INFO pCertInfo;
    HCERTSTORE hCertStore;
} CERT_CONTEXT, *PCERT_CONTEXT;
typedef const CERT_CONTEXT *PCCERT_CONTEXT;
typedef struct _CRL_CONTEXT {
    DWORD dwCertEncodingType;
    BYTE *pbCrlEncoded;
    DWORD cbCrlEncoded;
    PCRL_INFO pCrlInfo;
    HCERTSTORE hCertStore;
} CRL_CONTEXT, *PCRL_CONTEXT;
typedef const CRL_CONTEXT *PCCRL_CONTEXT;
typedef struct _CTL_CONTEXT {
    DWORD dwMsgAndCertEncodingType;
    BYTE *pbCtlEncoded;
    DWORD cbCtlEncoded;
    PCTL_INFO pCtlInfo;
    HCERTSTORE hCertStore;
    HCRYPTMSG hCryptMsg;
    BYTE *pbCtlContent;
    DWORD cbCtlContent;
} CTL_CONTEXT, *PCTL_CONTEXT;
typedef const CTL_CONTEXT *PCCTL_CONTEXT;
typedef struct _CRYPT_KEY_PROV_PARAM {
    DWORD dwParam;
    BYTE *pbData;
    DWORD cbData;
    DWORD dwFlags;
} CRYPT_KEY_PROV_PARAM, *PCRYPT_KEY_PROV_PARAM;

typedef struct _CRYPT_KEY_PROV_INFO {
    LPWSTR pwszContainerName;
    LPWSTR pwszProvName;
    DWORD dwProvType;
    DWORD dwFlags;
    DWORD cProvParam;
    PCRYPT_KEY_PROV_PARAM rgProvParam;
    DWORD dwKeySpec;
} CRYPT_KEY_PROV_INFO, *PCRYPT_KEY_PROV_INFO;
typedef struct _CERT_KEY_CONTEXT {
    DWORD cbSize;
    union {
        HCRYPTPROV hCryptProv;


        NCRYPT_KEY_HANDLE hNCryptKey;
    }  u ;
    DWORD dwKeySpec;
} CERT_KEY_CONTEXT, *PCERT_KEY_CONTEXT;







typedef struct _ROOT_INFO_LUID {
    DWORD LowPart;
    LONG HighPart;
} ROOT_INFO_LUID, *PROOT_INFO_LUID;

typedef struct _CRYPT_SMART_CARD_ROOT_INFO {
    BYTE rgbCardID [16];
    ROOT_INFO_LUID luid;
} CRYPT_SMART_CARD_ROOT_INFO, *PCRYPT_SMART_CARD_ROOT_INFO;
typedef struct _CERT_SYSTEM_STORE_RELOCATE_PARA {
    union {
        HKEY hKeyBase;
        void *pvBase;
    }  u ;
    union {
        void *pvSystemStore;
        LPCSTR pszSystemStore;
        LPCWSTR pwszSystemStore;
    }  u2 ;
} CERT_SYSTEM_STORE_RELOCATE_PARA, *PCERT_SYSTEM_STORE_RELOCATE_PARA;
typedef struct _CERT_REGISTRY_STORE_CLIENT_GPT_PARA {
    HKEY hKeyBase;
    LPWSTR pwszRegPath;
} CERT_REGISTRY_STORE_CLIENT_GPT_PARA, *PCERT_REGISTRY_STORE_CLIENT_GPT_PARA;









typedef struct _CERT_REGISTRY_STORE_ROAMING_PARA {
    HKEY hKey;
    LPWSTR pwszStoreDirectory;
} CERT_REGISTRY_STORE_ROAMING_PARA, *PCERT_REGISTRY_STORE_ROAMING_PARA;
typedef struct _CERT_LDAP_STORE_OPENED_PARA {
    void *pvLdapSessionHandle;

    LPCWSTR pwszLdapUrl;
} CERT_LDAP_STORE_OPENED_PARA, *PCERT_LDAP_STORE_OPENED_PARA;
__declspec(dllimport)

HCERTSTORE

CertOpenStore(
     LPCSTR lpszStoreProvider,
     DWORD dwEncodingType,
     HCRYPTPROV_LEGACY hCryptProv,
     DWORD dwFlags,
     const void *pvPara
    );







typedef void *HCERTSTOREPROV;










typedef struct _CERT_STORE_PROV_INFO {
    DWORD cbSize;
    DWORD cStoreProvFunc;
    void **rgpvStoreProvFunc;
    HCERTSTOREPROV hStoreProv;
    DWORD dwStoreProvFlags;
    HCRYPTOIDFUNCADDR hStoreProvFuncAddr2;
} CERT_STORE_PROV_INFO, *PCERT_STORE_PROV_INFO;








typedef BOOL (  *PFN_CERT_DLL_OPEN_STORE_PROV_FUNC)(
     LPCSTR lpszStoreProvider,
     DWORD dwEncodingType,
     HCRYPTPROV_LEGACY hCryptProv,
     DWORD dwFlags,
     const void *pvPara,
     HCERTSTORE hCertStore,
     PCERT_STORE_PROV_INFO pStoreProvInfo
    );
typedef void (  *PFN_CERT_STORE_PROV_CLOSE)(
     HCERTSTOREPROV hStoreProv,
     DWORD dwFlags
    );






typedef   BOOL (  *PFN_CERT_STORE_PROV_READ_CERT)(
     HCERTSTOREPROV hStoreProv,
     PCCERT_CONTEXT pStoreCertContext,
     DWORD dwFlags,
     PCCERT_CONTEXT *ppProvCertContext
    );










typedef BOOL (  *PFN_CERT_STORE_PROV_WRITE_CERT)(
     HCERTSTOREPROV hStoreProv,
     PCCERT_CONTEXT pCertContext,
     DWORD dwFlags
    );





typedef BOOL (  *PFN_CERT_STORE_PROV_DELETE_CERT)(
     HCERTSTOREPROV hStoreProv,
     PCCERT_CONTEXT pCertContext,
     DWORD dwFlags
    );









typedef BOOL (  *PFN_CERT_STORE_PROV_SET_CERT_PROPERTY)(
     HCERTSTOREPROV hStoreProv,
     PCCERT_CONTEXT pCertContext,
     DWORD dwPropId,
     DWORD dwFlags,
     const void *pvData
    );






typedef   BOOL (  *PFN_CERT_STORE_PROV_READ_CRL)(
     HCERTSTOREPROV hStoreProv,
     PCCRL_CONTEXT pStoreCrlContext,
     DWORD dwFlags,
     PCCRL_CONTEXT *ppProvCrlContext
    );








typedef BOOL (  *PFN_CERT_STORE_PROV_WRITE_CRL)(
     HCERTSTOREPROV hStoreProv,
     PCCRL_CONTEXT pCrlContext,
     DWORD dwFlags
    );




typedef BOOL (  *PFN_CERT_STORE_PROV_DELETE_CRL)(
     HCERTSTOREPROV hStoreProv,
     PCCRL_CONTEXT pCrlContext,
     DWORD dwFlags
    );









typedef BOOL (  *PFN_CERT_STORE_PROV_SET_CRL_PROPERTY)(
     HCERTSTOREPROV hStoreProv,
     PCCRL_CONTEXT pCrlContext,
     DWORD dwPropId,
     DWORD dwFlags,
     const void *pvData
    );






typedef   BOOL (  *PFN_CERT_STORE_PROV_READ_CTL)(
     HCERTSTOREPROV hStoreProv,
     PCCTL_CONTEXT pStoreCtlContext,
     DWORD dwFlags,
     PCCTL_CONTEXT *ppProvCtlContext
    );








typedef BOOL (  *PFN_CERT_STORE_PROV_WRITE_CTL)(
     HCERTSTOREPROV hStoreProv,
     PCCTL_CONTEXT pCtlContext,
     DWORD dwFlags
    );




typedef BOOL (  *PFN_CERT_STORE_PROV_DELETE_CTL)(
     HCERTSTOREPROV hStoreProv,
     PCCTL_CONTEXT pCtlContext,
     DWORD dwFlags
                                                     );









typedef BOOL (  *PFN_CERT_STORE_PROV_SET_CTL_PROPERTY)(
     HCERTSTOREPROV hStoreProv,
     PCCTL_CONTEXT pCtlContext,
     DWORD dwPropId,
     DWORD dwFlags,
     const void *pvData
    );

typedef BOOL (  *PFN_CERT_STORE_PROV_CONTROL)(
     HCERTSTOREPROV hStoreProv,
     DWORD dwFlags,
     DWORD dwCtrlType,
     void const *pvCtrlPara
    );

typedef struct _CERT_STORE_PROV_FIND_INFO {
    DWORD cbSize;
    DWORD dwMsgAndCertEncodingType;
    DWORD dwFindFlags;
    DWORD dwFindType;
    const void *pvFindPara;
} CERT_STORE_PROV_FIND_INFO, *PCERT_STORE_PROV_FIND_INFO;
typedef const CERT_STORE_PROV_FIND_INFO CCERT_STORE_PROV_FIND_INFO,
*PCCERT_STORE_PROV_FIND_INFO;

typedef   BOOL (  *PFN_CERT_STORE_PROV_FIND_CERT)(
     HCERTSTOREPROV hStoreProv,
     PCCERT_STORE_PROV_FIND_INFO pFindInfo,
     PCCERT_CONTEXT pPrevCertContext,
     DWORD dwFlags,
     void **ppvStoreProvFindInfo,
     PCCERT_CONTEXT *ppProvCertContext
    );

typedef BOOL (  *PFN_CERT_STORE_PROV_FREE_FIND_CERT)(
     HCERTSTOREPROV hStoreProv,
     PCCERT_CONTEXT pCertContext,
     void *pvStoreProvFindInfo,
     DWORD dwFlags
    );

typedef BOOL (  *PFN_CERT_STORE_PROV_GET_CERT_PROPERTY)(
     HCERTSTOREPROV hStoreProv,
     PCCERT_CONTEXT pCertContext,
     DWORD dwPropId,
     DWORD dwFlags,
     void *pvData,
     DWORD *pcbData
    );


typedef   BOOL (  *PFN_CERT_STORE_PROV_FIND_CRL)(
     HCERTSTOREPROV hStoreProv,
     PCCERT_STORE_PROV_FIND_INFO pFindInfo,
     PCCRL_CONTEXT pPrevCrlContext,
     DWORD dwFlags,
     void **ppvStoreProvFindInfo,
     PCCRL_CONTEXT *ppProvCrlContext
    );

typedef BOOL (  *PFN_CERT_STORE_PROV_FREE_FIND_CRL)(
     HCERTSTOREPROV hStoreProv,
     PCCRL_CONTEXT pCrlContext,
     void *pvStoreProvFindInfo,
     DWORD dwFlags
    );

typedef BOOL (  *PFN_CERT_STORE_PROV_GET_CRL_PROPERTY)(
     HCERTSTOREPROV hStoreProv,
     PCCRL_CONTEXT pCrlContext,
     DWORD dwPropId,
     DWORD dwFlags,
     void *pvData,
     DWORD *pcbData
    );

typedef   BOOL (  *PFN_CERT_STORE_PROV_FIND_CTL)(
     HCERTSTOREPROV hStoreProv,
     PCCERT_STORE_PROV_FIND_INFO pFindInfo,
     PCCTL_CONTEXT pPrevCtlContext,
     DWORD dwFlags,
     void **ppvStoreProvFindInfo,
     PCCTL_CONTEXT *ppProvCtlContext
    );

typedef BOOL (  *PFN_CERT_STORE_PROV_FREE_FIND_CTL)(
     HCERTSTOREPROV hStoreProv,
     PCCTL_CONTEXT pCtlContext,
     void *pvStoreProvFindInfo,
     DWORD dwFlags
    );

typedef BOOL (  *PFN_CERT_STORE_PROV_GET_CTL_PROPERTY)(
     HCERTSTOREPROV hStoreProv,
     PCCTL_CONTEXT pCtlContext,
     DWORD dwPropId,
     DWORD dwFlags,
     void *pvData,
     DWORD *pcbData
    );





__declspec(dllimport)
HCERTSTORE

CertDuplicateStore(
     HCERTSTORE hCertStore
    );
__declspec(dllimport)
BOOL

CertSaveStore(
     HCERTSTORE hCertStore,
     DWORD dwEncodingType,
     DWORD dwSaveAs,
     DWORD dwSaveTo,
     void *pvSaveToPara,
     DWORD dwFlags
    );
__declspec(dllimport)
BOOL

CertCloseStore(
     HCERTSTORE hCertStore,
     DWORD dwFlags
    );
__declspec(dllimport)
PCCERT_CONTEXT

CertGetSubjectCertificateFromStore(
     HCERTSTORE hCertStore,
     DWORD dwCertEncodingType,
     PCERT_INFO pCertId

    );
__declspec(dllimport)
PCCERT_CONTEXT

CertEnumCertificatesInStore(
     HCERTSTORE hCertStore,
     PCCERT_CONTEXT pPrevCertContext
    );
__declspec(dllimport)
PCCERT_CONTEXT

CertFindCertificateInStore(
     HCERTSTORE hCertStore,
     DWORD dwCertEncodingType,
     DWORD dwFindFlags,
     DWORD dwFindType,
     const void *pvFindPara,
     PCCERT_CONTEXT pPrevCertContext
    );
__declspec(dllimport)
PCCERT_CONTEXT

CertGetIssuerCertificateFromStore(
     HCERTSTORE hCertStore,
     PCCERT_CONTEXT pSubjectContext,
     PCCERT_CONTEXT pPrevIssuerContext,
     DWORD *pdwFlags
    );
__declspec(dllimport)
BOOL

CertVerifySubjectCertificateContext(
     PCCERT_CONTEXT pSubject,
     PCCERT_CONTEXT pIssuer,
     DWORD *pdwFlags
    );




__declspec(dllimport)
PCCERT_CONTEXT

CertDuplicateCertificateContext(
     PCCERT_CONTEXT pCertContext
    );
__declspec(dllimport)
PCCERT_CONTEXT

CertCreateCertificateContext(
     DWORD dwCertEncodingType,
     const BYTE *pbCertEncoded,
     DWORD cbCertEncoded
    );







__declspec(dllimport)
BOOL

CertFreeCertificateContext(
     PCCERT_CONTEXT pCertContext
    );
__declspec(dllimport)
BOOL

CertSetCertificateContextProperty(
     PCCERT_CONTEXT pCertContext,
     DWORD dwPropId,
     DWORD dwFlags,
     const void *pvData
    );
__declspec(dllimport)
BOOL

CertGetCertificateContextProperty(
     PCCERT_CONTEXT pCertContext,
     DWORD dwPropId,
     void *pvData,
     DWORD *pcbData
    );
__declspec(dllimport)
DWORD

CertEnumCertificateContextProperties(
     PCCERT_CONTEXT pCertContext,
     DWORD dwPropId
    );
__declspec(dllimport)
BOOL

CertCreateCTLEntryFromCertificateContextProperties(
     PCCERT_CONTEXT pCertContext,
     DWORD cOptAttr,
     PCRYPT_ATTRIBUTE rgOptAttr,
     DWORD dwFlags,
     void *pvReserved,
     PCTL_ENTRY pCtlEntry,
     DWORD *pcbCtlEntry
    );
__declspec(dllimport)
BOOL

CertSetCertificateContextPropertiesFromCTLEntry(
     PCCERT_CONTEXT pCertContext,
     PCTL_ENTRY pCtlEntry,
     DWORD dwFlags
    );
__declspec(dllimport)
PCCRL_CONTEXT

CertGetCRLFromStore(
     HCERTSTORE hCertStore,
     PCCERT_CONTEXT pIssuerContext,
     PCCRL_CONTEXT pPrevCrlContext,
     DWORD *pdwFlags
    );
__declspec(dllimport)
PCCRL_CONTEXT

CertEnumCRLsInStore(
     HCERTSTORE hCertStore,
     PCCRL_CONTEXT pPrevCrlContext
    );
__declspec(dllimport)
PCCRL_CONTEXT

CertFindCRLInStore(
     HCERTSTORE hCertStore,
     DWORD dwCertEncodingType,
     DWORD dwFindFlags,
     DWORD dwFindType,
     const void *pvFindPara,
     PCCRL_CONTEXT pPrevCrlContext
    );
typedef struct _CRL_FIND_ISSUED_FOR_PARA {
    PCCERT_CONTEXT pSubjectCert;
    PCCERT_CONTEXT pIssuerCert;
} CRL_FIND_ISSUED_FOR_PARA, *PCRL_FIND_ISSUED_FOR_PARA;





__declspec(dllimport)
PCCRL_CONTEXT

CertDuplicateCRLContext(
     PCCRL_CONTEXT pCrlContext
    );
__declspec(dllimport)
PCCRL_CONTEXT

CertCreateCRLContext(
     DWORD dwCertEncodingType,
     const BYTE *pbCrlEncoded,
     DWORD cbCrlEncoded
    );







__declspec(dllimport)
BOOL

CertFreeCRLContext(
     PCCRL_CONTEXT pCrlContext
    );






__declspec(dllimport)
BOOL

CertSetCRLContextProperty(
     PCCRL_CONTEXT pCrlContext,
     DWORD dwPropId,
     DWORD dwFlags,
     const void *pvData
    );









__declspec(dllimport)
BOOL

CertGetCRLContextProperty(
     PCCRL_CONTEXT pCrlContext,
     DWORD dwPropId,
     void *pvData,
     DWORD *pcbData
    );
__declspec(dllimport)
DWORD

CertEnumCRLContextProperties(
     PCCRL_CONTEXT pCrlContext,
     DWORD dwPropId
    );
__declspec(dllimport)
BOOL

CertFindCertificateInCRL(
     PCCERT_CONTEXT pCert,
     PCCRL_CONTEXT pCrlContext,
     DWORD dwFlags,
     void *pvReserved,
     PCRL_ENTRY *ppCrlEntry
    );
__declspec(dllimport)
BOOL

CertIsValidCRLForCertificate(
     PCCERT_CONTEXT pCert,
     PCCRL_CONTEXT pCrl,
     DWORD dwFlags,
     void *pvReserved
    );
__declspec(dllimport)

BOOL

CertAddEncodedCertificateToStore(
     HCERTSTORE hCertStore,
     DWORD dwCertEncodingType,
     const BYTE *pbCertEncoded,
     DWORD cbCertEncoded,
     DWORD dwAddDisposition,
     PCCERT_CONTEXT *ppCertContext
    );
__declspec(dllimport)

BOOL

CertAddCertificateContextToStore(
     HCERTSTORE hCertStore,
     PCCERT_CONTEXT pCertContext,
     DWORD dwAddDisposition,
     PCCERT_CONTEXT *ppStoreContext
    );
__declspec(dllimport)

BOOL

CertAddSerializedElementToStore(
     HCERTSTORE hCertStore,
     const BYTE *pbElement,
     DWORD cbElement,
     DWORD dwAddDisposition,
     DWORD dwFlags,
     DWORD dwContextTypeFlags,
     DWORD *pdwContextType,
     const void **ppvContext
    );
__declspec(dllimport)
BOOL

CertDeleteCertificateFromStore(
     PCCERT_CONTEXT pCertContext
    );
__declspec(dllimport)

BOOL

CertAddEncodedCRLToStore(
     HCERTSTORE hCertStore,
     DWORD dwCertEncodingType,
     const BYTE *pbCrlEncoded,
     DWORD cbCrlEncoded,
     DWORD dwAddDisposition,
     PCCRL_CONTEXT *ppCrlContext
    );
__declspec(dllimport)

BOOL

CertAddCRLContextToStore(
     HCERTSTORE hCertStore,
     PCCRL_CONTEXT pCrlContext,
     DWORD dwAddDisposition,
     PCCRL_CONTEXT *ppStoreContext
    );
__declspec(dllimport)
BOOL

CertDeleteCRLFromStore(
     PCCRL_CONTEXT pCrlContext
    );





__declspec(dllimport)
BOOL

CertSerializeCertificateStoreElement(
     PCCERT_CONTEXT pCertContext,
     DWORD dwFlags,
     BYTE *pbElement,
     DWORD *pcbElement
    );





__declspec(dllimport)
BOOL

CertSerializeCRLStoreElement(
     PCCRL_CONTEXT pCrlContext,
     DWORD dwFlags,
     BYTE *pbElement,
     DWORD *pcbElement
    );










__declspec(dllimport)
PCCTL_CONTEXT

CertDuplicateCTLContext(
     PCCTL_CONTEXT pCtlContext
    );
__declspec(dllimport)
PCCTL_CONTEXT

CertCreateCTLContext(
     DWORD dwMsgAndCertEncodingType,
     const BYTE *pbCtlEncoded,
     DWORD cbCtlEncoded
    );







__declspec(dllimport)
BOOL

CertFreeCTLContext(
     PCCTL_CONTEXT pCtlContext
    );






__declspec(dllimport)
BOOL

CertSetCTLContextProperty(
     PCCTL_CONTEXT pCtlContext,
     DWORD dwPropId,
     DWORD dwFlags,
     const void *pvData
    );









__declspec(dllimport)
BOOL

CertGetCTLContextProperty(
     PCCTL_CONTEXT pCtlContext,
     DWORD dwPropId,
     void *pvData,
     DWORD *pcbData
    );




__declspec(dllimport)
DWORD

CertEnumCTLContextProperties(
     PCCTL_CONTEXT pCtlContext,
     DWORD dwPropId
    );
__declspec(dllimport)
PCCTL_CONTEXT

CertEnumCTLsInStore(
     HCERTSTORE hCertStore,
     PCCTL_CONTEXT pPrevCtlContext
    );
__declspec(dllimport)
PCTL_ENTRY

CertFindSubjectInCTL(
     DWORD dwEncodingType,
     DWORD dwSubjectType,
     void *pvSubject,
     PCCTL_CONTEXT pCtlContext,
     DWORD dwFlags
    );







typedef struct _CTL_ANY_SUBJECT_INFO {
    CRYPT_ALGORITHM_IDENTIFIER SubjectAlgorithm;
    CRYPT_DATA_BLOB SubjectIdentifier;
} CTL_ANY_SUBJECT_INFO, *PCTL_ANY_SUBJECT_INFO;
__declspec(dllimport)
PCCTL_CONTEXT

CertFindCTLInStore(
     HCERTSTORE hCertStore,
     DWORD dwMsgAndCertEncodingType,
     DWORD dwFindFlags,
     DWORD dwFindType,
     const void *pvFindPara,
     PCCTL_CONTEXT pPrevCtlContext
    );








typedef struct _CTL_FIND_USAGE_PARA {
    DWORD cbSize;
    CTL_USAGE SubjectUsage;
    CRYPT_DATA_BLOB ListIdentifier;
    PCERT_INFO pSigner;
} CTL_FIND_USAGE_PARA, *PCTL_FIND_USAGE_PARA;







typedef struct _CTL_FIND_SUBJECT_PARA {
    DWORD cbSize;
    PCTL_FIND_USAGE_PARA pUsagePara;
    DWORD dwSubjectType;
    void *pvSubject;
} CTL_FIND_SUBJECT_PARA, *PCTL_FIND_SUBJECT_PARA;
__declspec(dllimport)

BOOL

CertAddEncodedCTLToStore(
     HCERTSTORE hCertStore,
     DWORD dwMsgAndCertEncodingType,
     const BYTE *pbCtlEncoded,
     DWORD cbCtlEncoded,
     DWORD dwAddDisposition,
     PCCTL_CONTEXT *ppCtlContext
    );
__declspec(dllimport)

BOOL

CertAddCTLContextToStore(
     HCERTSTORE hCertStore,
     PCCTL_CONTEXT pCtlContext,
     DWORD dwAddDisposition,
     PCCTL_CONTEXT *ppStoreContext
    );




__declspec(dllimport)
BOOL

CertSerializeCTLStoreElement(
     PCCTL_CONTEXT pCtlContext,
     DWORD dwFlags,
     BYTE *pbElement,
     DWORD *pcbElement
    );
__declspec(dllimport)
BOOL

CertDeleteCTLFromStore(
     PCCTL_CONTEXT pCtlContext
    );


__declspec(dllimport)

BOOL

CertAddCertificateLinkToStore(
     HCERTSTORE hCertStore,
     PCCERT_CONTEXT pCertContext,
     DWORD dwAddDisposition,
     PCCERT_CONTEXT *ppStoreContext
    );

__declspec(dllimport)

BOOL

CertAddCRLLinkToStore(
     HCERTSTORE hCertStore,
     PCCRL_CONTEXT pCrlContext,
     DWORD dwAddDisposition,
     PCCRL_CONTEXT *ppStoreContext
    );

__declspec(dllimport)

BOOL

CertAddCTLLinkToStore(
     HCERTSTORE hCertStore,
     PCCTL_CONTEXT pCtlContext,
     DWORD dwAddDisposition,
     PCCTL_CONTEXT *ppStoreContext
    );

__declspec(dllimport)
BOOL

CertAddStoreToCollection(
     HCERTSTORE hCollectionStore,
     HCERTSTORE hSiblingStore,
     DWORD dwUpdateFlags,
     DWORD dwPriority
    );

__declspec(dllimport)
void

CertRemoveStoreFromCollection(
     HCERTSTORE hCollectionStore,
     HCERTSTORE hSiblingStore
    );


__declspec(dllimport)
BOOL

CertControlStore(
     HCERTSTORE hCertStore,
     DWORD dwFlags,
     DWORD dwCtrlType,
     void const *pvCtrlPara
    );
__declspec(dllimport)
BOOL

CertSetStoreProperty(
     HCERTSTORE hCertStore,
     DWORD dwPropId,
     DWORD dwFlags,
     const void *pvData
    );
__declspec(dllimport)
BOOL

CertGetStoreProperty(
     HCERTSTORE hCertStore,
     DWORD dwPropId,
     void *pvData,
     DWORD *pcbData
    );
typedef BOOL (  *PFN_CERT_CREATE_CONTEXT_SORT_FUNC)(
     DWORD cbTotalEncoded,
     DWORD cbRemainEncoded,
     DWORD cEntry,
     void *pvSort
    );

typedef struct _CERT_CREATE_CONTEXT_PARA {
    DWORD cbSize;
    PFN_CRYPT_FREE pfnFree;
    void *pvFree;



    PFN_CERT_CREATE_CONTEXT_SORT_FUNC pfnSort;
    void *pvSort;
} CERT_CREATE_CONTEXT_PARA, *PCERT_CREATE_CONTEXT_PARA;
__declspec(dllimport)
const void *

CertCreateContext(
     DWORD dwContextType,
     DWORD dwEncodingType,
     const BYTE *pbEncoded,
     DWORD cbEncoded,
     DWORD dwFlags,
     PCERT_CREATE_CONTEXT_PARA pCreatePara
    );
typedef struct _CERT_SYSTEM_STORE_INFO {
    DWORD cbSize;
} CERT_SYSTEM_STORE_INFO, *PCERT_SYSTEM_STORE_INFO;
typedef struct _CERT_PHYSICAL_STORE_INFO {
    DWORD cbSize;
    LPSTR pszOpenStoreProvider;
    DWORD dwOpenEncodingType;
    DWORD dwOpenFlags;
    CRYPT_DATA_BLOB OpenParameters;
    DWORD dwFlags;
    DWORD dwPriority;
} CERT_PHYSICAL_STORE_INFO, *PCERT_PHYSICAL_STORE_INFO;
__declspec(dllimport)
BOOL

CertRegisterSystemStore(
     const void *pvSystemStore,
     DWORD dwFlags,
     PCERT_SYSTEM_STORE_INFO pStoreInfo,
     void *pvReserved
    );
__declspec(dllimport)
BOOL

CertRegisterPhysicalStore(
     const void *pvSystemStore,
     DWORD dwFlags,
     LPCWSTR pwszStoreName,
     PCERT_PHYSICAL_STORE_INFO pStoreInfo,
     void *pvReserved
    );
__declspec(dllimport)
BOOL

CertUnregisterSystemStore(
     const void *pvSystemStore,
     DWORD dwFlags
    );
__declspec(dllimport)
BOOL

CertUnregisterPhysicalStore(
     const void *pvSystemStore,
     DWORD dwFlags,
     LPCWSTR pwszStoreName
    );
typedef BOOL (  *PFN_CERT_ENUM_SYSTEM_STORE_LOCATION)(
     LPCWSTR pwszStoreLocation,
     DWORD dwFlags,
     void *pvReserved,
     void *pvArg
    );

typedef BOOL (  *PFN_CERT_ENUM_SYSTEM_STORE)(
     const void *pvSystemStore,
     DWORD dwFlags,
     PCERT_SYSTEM_STORE_INFO pStoreInfo,
     void *pvReserved,
     void *pvArg
    );

typedef BOOL (  *PFN_CERT_ENUM_PHYSICAL_STORE)(
     const void *pvSystemStore,
     DWORD dwFlags,
     LPCWSTR pwszStoreName,
     PCERT_PHYSICAL_STORE_INFO pStoreInfo,
     void *pvReserved,
     void *pvArg
    );
__declspec(dllimport)
BOOL

CertEnumSystemStoreLocation(
     DWORD dwFlags,
     void *pvArg,
     PFN_CERT_ENUM_SYSTEM_STORE_LOCATION pfnEnum
    );
__declspec(dllimport)
BOOL

CertEnumSystemStore(
     DWORD dwFlags,
     void *pvSystemStoreLocationPara,
     void *pvArg,
     PFN_CERT_ENUM_SYSTEM_STORE pfnEnum
    );
__declspec(dllimport)
BOOL

CertEnumPhysicalStore(
     const void *pvSystemStore,
     DWORD dwFlags,
     void *pvArg,
     PFN_CERT_ENUM_PHYSICAL_STORE pfnEnum
    );
__declspec(dllimport)
BOOL

CertGetEnhancedKeyUsage(
     PCCERT_CONTEXT pCertContext,
     DWORD dwFlags,
     PCERT_ENHKEY_USAGE pUsage,
     DWORD *pcbUsage
    );




__declspec(dllimport)
BOOL

CertSetEnhancedKeyUsage(
     PCCERT_CONTEXT pCertContext,
     PCERT_ENHKEY_USAGE pUsage
    );




__declspec(dllimport)
BOOL

CertAddEnhancedKeyUsageIdentifier(
     PCCERT_CONTEXT pCertContext,
     LPCSTR pszUsageIdentifier
    );






__declspec(dllimport)
BOOL

CertRemoveEnhancedKeyUsageIdentifier(
     PCCERT_CONTEXT pCertContext,
     LPCSTR pszUsageIdentifier
    );









__declspec(dllimport)
BOOL

CertGetValidUsages(
     DWORD cCerts,
     PCCERT_CONTEXT *rghCerts,
     int *cNumOIDs,
     LPSTR *rghOIDs,
     DWORD *pcbOIDs);
__declspec(dllimport)

BOOL

CryptMsgGetAndVerifySigner(
     HCRYPTMSG hCryptMsg,
     DWORD cSignerStore,
     HCERTSTORE *rghSignerStore,
     DWORD dwFlags,
     PCCERT_CONTEXT *ppSigner,
     DWORD *pdwSignerIndex
    );
__declspec(dllimport)
BOOL

CryptMsgSignCTL(
     DWORD dwMsgEncodingType,
     BYTE *pbCtlContent,
     DWORD cbCtlContent,
     PCMSG_SIGNED_ENCODE_INFO pSignInfo,
     DWORD dwFlags,
     BYTE *pbEncoded,
     DWORD *pcbEncoded
    );
__declspec(dllimport)
BOOL

CryptMsgEncodeAndSignCTL(
     DWORD dwMsgEncodingType,
     PCTL_INFO pCtlInfo,
     PCMSG_SIGNED_ENCODE_INFO pSignInfo,
     DWORD dwFlags,
     BYTE *pbEncoded,
     DWORD *pcbEncoded
    );
__declspec(dllimport)
BOOL

CertFindSubjectInSortedCTL(
     PCRYPT_DATA_BLOB pSubjectIdentifier,
     PCCTL_CONTEXT pCtlContext,
     DWORD dwFlags,
     void *pvReserved,
     PCRYPT_DER_BLOB pEncodedAttributes
    );
__declspec(dllimport)
BOOL

CertEnumSubjectInSortedCTL(
     PCCTL_CONTEXT pCtlContext,
     void **ppvNextSubject,
     PCRYPT_DER_BLOB pSubjectIdentifier,
     PCRYPT_DER_BLOB pEncodedAttributes
    );






typedef struct _CTL_VERIFY_USAGE_PARA {
    DWORD cbSize;
    CRYPT_DATA_BLOB ListIdentifier;
    DWORD cCtlStore;
    HCERTSTORE *rghCtlStore;
    DWORD cSignerStore;
    HCERTSTORE *rghSignerStore;
} CTL_VERIFY_USAGE_PARA, *PCTL_VERIFY_USAGE_PARA;

typedef struct _CTL_VERIFY_USAGE_STATUS {
    DWORD cbSize;
    DWORD dwError;
    DWORD dwFlags;
    PCCTL_CONTEXT *ppCtl;
    DWORD dwCtlEntryIndex;
    PCCERT_CONTEXT *ppSigner;
    DWORD dwSignerIndex;
} CTL_VERIFY_USAGE_STATUS, *PCTL_VERIFY_USAGE_STATUS;
__declspec(dllimport)
BOOL

CertVerifyCTLUsage(
     DWORD dwEncodingType,
     DWORD dwSubjectType,
     void *pvSubject,
     PCTL_USAGE pSubjectUsage,
     DWORD dwFlags,
     PCTL_VERIFY_USAGE_PARA pVerifyUsagePara,
     PCTL_VERIFY_USAGE_STATUS pVerifyUsageStatus
    );










typedef struct _CERT_REVOCATION_CRL_INFO {
    DWORD cbSize;
    PCCRL_CONTEXT pBaseCrlContext;
    PCCRL_CONTEXT pDeltaCrlContext;



    PCRL_ENTRY pCrlEntry;
    BOOL fDeltaCrlEntry;
} CERT_REVOCATION_CRL_INFO, *PCERT_REVOCATION_CRL_INFO;










typedef struct _CERT_REVOCATION_CHAIN_PARA
    CERT_REVOCATION_CHAIN_PARA,
    *PCERT_REVOCATION_CHAIN_PARA;
typedef struct _CERT_REVOCATION_PARA {
    DWORD cbSize;
    PCCERT_CONTEXT pIssuerCert;
    DWORD cCertStore;
    HCERTSTORE *rgCertStore;
    HCERTSTORE hCrlStore;
    LPFILETIME pftTimeToUse;
} CERT_REVOCATION_PARA, *PCERT_REVOCATION_PARA;
typedef struct _CERT_REVOCATION_STATUS {
    DWORD cbSize;
    DWORD dwIndex;
    DWORD dwError;
    DWORD dwReason;









    BOOL fHasFreshnessTime;
    DWORD dwFreshnessTime;
} CERT_REVOCATION_STATUS, *PCERT_REVOCATION_STATUS;
__declspec(dllimport)
BOOL

CertVerifyRevocation(
     DWORD dwEncodingType,
     DWORD dwRevType,
     DWORD cContext,
     PVOID rgpvContext[],
     DWORD dwFlags,
     PCERT_REVOCATION_PARA pRevPara,
     PCERT_REVOCATION_STATUS pRevStatus
    );
BOOL

CertCompareIntegerBlob(
     PCRYPT_INTEGER_BLOB pInt1,
     PCRYPT_INTEGER_BLOB pInt2
    );









__declspec(dllimport)
BOOL

CertCompareCertificate(
     DWORD dwCertEncodingType,
     PCERT_INFO pCertId1,
     PCERT_INFO pCertId2
    );






__declspec(dllimport)
BOOL

CertCompareCertificateName(
     DWORD dwCertEncodingType,
     PCERT_NAME_BLOB pCertName1,
     PCERT_NAME_BLOB pCertName2
    );
__declspec(dllimport)
BOOL

CertIsRDNAttrsInCertificateName(
     DWORD dwCertEncodingType,
     DWORD dwFlags,
     PCERT_NAME_BLOB pCertName,
     PCERT_RDN pRDN
    );









__declspec(dllimport)
BOOL

CertComparePublicKeyInfo(
     DWORD dwCertEncodingType,
     PCERT_PUBLIC_KEY_INFO pPublicKey1,
     PCERT_PUBLIC_KEY_INFO pPublicKey2
    );






__declspec(dllimport)
DWORD

CertGetPublicKeyLength(
     DWORD dwCertEncodingType,
     PCERT_PUBLIC_KEY_INFO pPublicKey
    );










__declspec(dllimport)

BOOL

CryptVerifyCertificateSignature(
     HCRYPTPROV_LEGACY hCryptProv,
     DWORD dwCertEncodingType,
     const BYTE *pbEncoded,
     DWORD cbEncoded,
     PCERT_PUBLIC_KEY_INFO pPublicKey
    );
__declspec(dllimport)

BOOL

CryptVerifyCertificateSignatureEx(
     HCRYPTPROV_LEGACY hCryptProv,
     DWORD dwCertEncodingType,
     DWORD dwSubjectType,
     void *pvSubject,
     DWORD dwIssuerType,
     void *pvIssuer,
     DWORD dwFlags,
     void *pvReserved
    );
__declspec(dllimport)
BOOL

CryptHashToBeSigned(
     HCRYPTPROV_LEGACY hCryptProv,
     DWORD dwCertEncodingType,
     const BYTE *pbEncoded,
     DWORD cbEncoded,
     BYTE *pbComputedHash,
     DWORD *pcbComputedHash
    );










__declspec(dllimport)
BOOL

CryptHashCertificate(
     HCRYPTPROV_LEGACY hCryptProv,
     ALG_ID Algid,
     DWORD dwFlags,
     const BYTE *pbEncoded,
     DWORD cbEncoded,
     BYTE *pbComputedHash,
     DWORD *pcbComputedHash
    );




__declspec(dllimport)
BOOL

CryptHashCertificate2(
     LPCWSTR pwszCNGHashAlgid,
     DWORD dwFlags,
     void *pvReserved,
     const BYTE *pbEncoded,
     DWORD cbEncoded,
     BYTE *pbComputedHash,
     DWORD *pcbComputedHash
    );
__declspec(dllimport)
BOOL

CryptSignCertificate(
     HCRYPTPROV_OR_NCRYPT_KEY_HANDLE hCryptProvOrNCryptKey,
     DWORD dwKeySpec,
     DWORD dwCertEncodingType,
     const BYTE *pbEncodedToBeSigned,
     DWORD cbEncodedToBeSigned,
     PCRYPT_ALGORITHM_IDENTIFIER pSignatureAlgorithm,
     const void *pvHashAuxInfo,
     BYTE *pbSignature,
     DWORD *pcbSignature
    );
__declspec(dllimport)
BOOL

CryptSignAndEncodeCertificate(
     HCRYPTPROV_OR_NCRYPT_KEY_HANDLE hCryptProvOrNCryptKey,
     DWORD dwKeySpec,
     DWORD dwCertEncodingType,
     LPCSTR lpszStructType,
     const void *pvStructInfo,
     PCRYPT_ALGORITHM_IDENTIFIER pSignatureAlgorithm,
     const void *pvHashAuxInfo,
     BYTE *pbEncoded,
     DWORD *pcbEncoded
    );
typedef BOOL (  *PFN_CRYPT_EXTRACT_ENCODED_SIGNATURE_PARAMETERS_FUNC)(
     DWORD dwCertEncodingType,
     PCRYPT_ALGORITHM_IDENTIFIER pSignatureAlgorithm,
     void **ppvDecodedSignPara,
     LPWSTR *ppwszCNGHashAlgid
    );
typedef BOOL (  *PFN_CRYPT_SIGN_AND_ENCODE_HASH_FUNC)(
     NCRYPT_KEY_HANDLE hKey,
     DWORD dwCertEncodingType,
     PCRYPT_ALGORITHM_IDENTIFIER pSignatureAlgorithm,
     void *pvDecodedSignPara,
     LPCWSTR pwszCNGPubKeyAlgid,
     LPCWSTR pwszCNGHashAlgid,
     BYTE *pbComputedHash,
     DWORD cbComputedHash,
     BYTE *pbSignature,
     DWORD *pcbSignature
    );
typedef BOOL (  *PFN_CRYPT_VERIFY_ENCODED_SIGNATURE_FUNC)(
     DWORD dwCertEncodingType,
     PCERT_PUBLIC_KEY_INFO pPubKeyInfo,
     PCRYPT_ALGORITHM_IDENTIFIER pSignatureAlgorithm,
     void *pvDecodedSignPara,
     LPCWSTR pwszCNGPubKeyAlgid,
     LPCWSTR pwszCNGHashAlgid,
     BYTE *pbComputedHash,
     DWORD cbComputedHash,
     BYTE *pbSignature,
     DWORD cbSignature
    );










__declspec(dllimport)
LONG

CertVerifyTimeValidity(
     LPFILETIME pTimeToVerify,
     PCERT_INFO pCertInfo
    );










__declspec(dllimport)
LONG

CertVerifyCRLTimeValidity(
     LPFILETIME pTimeToVerify,
     PCRL_INFO pCrlInfo
    );







__declspec(dllimport)
BOOL

CertVerifyValidityNesting(
     PCERT_INFO pSubjectInfo,
     PCERT_INFO pIssuerInfo
    );






__declspec(dllimport)
BOOL

CertVerifyCRLRevocation(
     DWORD dwCertEncodingType,
     PCERT_INFO pCertId,

     DWORD cCrlInfo,
     PCRL_INFO rgpCrlInfo[]
    );






__declspec(dllimport)
LPCSTR

CertAlgIdToOID(
     DWORD dwAlgId
    );






__declspec(dllimport)
DWORD

CertOIDToAlgId(
     LPCSTR pszObjId
    );






__declspec(dllimport)
PCERT_EXTENSION

CertFindExtension(
     LPCSTR pszObjId,
     DWORD cExtensions,
     CERT_EXTENSION rgExtensions[]
    );






__declspec(dllimport)
PCRYPT_ATTRIBUTE

CertFindAttribute(
     LPCSTR pszObjId,
     DWORD cAttr,
     CRYPT_ATTRIBUTE rgAttr[]
    );







__declspec(dllimport)
PCERT_RDN_ATTR

CertFindRDNAttr(
     LPCSTR pszObjId,
     PCERT_NAME_INFO pName
    );









__declspec(dllimport)
BOOL

CertGetIntendedKeyUsage(
     DWORD dwCertEncodingType,
     PCERT_INFO pCertInfo,
     BYTE *pbKeyUsage,
     DWORD cbKeyUsage
    );

typedef void *HCRYPTDEFAULTCONTEXT;
__declspec(dllimport)
BOOL

CryptInstallDefaultContext(
     HCRYPTPROV hCryptProv,
     DWORD dwDefaultType,
     const void *pvDefaultPara,
     DWORD dwFlags,
     void *pvReserved,
     HCRYPTDEFAULTCONTEXT *phDefaultContext
    );
typedef struct _CRYPT_DEFAULT_CONTEXT_MULTI_OID_PARA {
    DWORD cOID;
    LPSTR *rgpszOID;
} CRYPT_DEFAULT_CONTEXT_MULTI_OID_PARA, *PCRYPT_DEFAULT_CONTEXT_MULTI_OID_PARA;










__declspec(dllimport)
BOOL

CryptUninstallDefaultContext(
     HCRYPTDEFAULTCONTEXT hDefaultContext,
     DWORD dwFlags,
     void *pvReserved
    );








__declspec(dllimport)
BOOL

CryptExportPublicKeyInfo(
     HCRYPTPROV_OR_NCRYPT_KEY_HANDLE hCryptProvOrNCryptKey,
     DWORD dwKeySpec,
     DWORD dwCertEncodingType,
     PCERT_PUBLIC_KEY_INFO pInfo,
     DWORD *pcbInfo
    );
__declspec(dllimport)
BOOL

CryptExportPublicKeyInfoEx(
     HCRYPTPROV_OR_NCRYPT_KEY_HANDLE hCryptProvOrNCryptKey,
     DWORD dwKeySpec,
     DWORD dwCertEncodingType,
     LPSTR pszPublicKeyObjId,
     DWORD dwFlags,
     void *pvAuxInfo,
     PCERT_PUBLIC_KEY_INFO pInfo,
     DWORD *pcbInfo
    );
typedef BOOL (  *PFN_CRYPT_EXPORT_PUBLIC_KEY_INFO_EX2_FUNC) (
     NCRYPT_KEY_HANDLE hNCryptKey,
     DWORD dwCertEncodingType,
     LPSTR pszPublicKeyObjId,
     DWORD dwFlags,
     void *pvAuxInfo,
     PCERT_PUBLIC_KEY_INFO pInfo,
     DWORD *pcbInfo
    );









__declspec(dllimport)
BOOL

CryptImportPublicKeyInfo(
     HCRYPTPROV hCryptProv,
     DWORD dwCertEncodingType,
     PCERT_PUBLIC_KEY_INFO pInfo,
     HCRYPTKEY *phKey
    );
__declspec(dllimport)
BOOL

CryptImportPublicKeyInfoEx(
     HCRYPTPROV hCryptProv,
     DWORD dwCertEncodingType,
     PCERT_PUBLIC_KEY_INFO pInfo,
     ALG_ID aiKeyAlg,
     DWORD dwFlags,
     void *pvAuxInfo,
     HCRYPTKEY *phKey
    );
__declspec(dllimport)
BOOL

CryptImportPublicKeyInfoEx2(
     DWORD dwCertEncodingType,
     PCERT_PUBLIC_KEY_INFO pInfo,
     DWORD dwFlags,
     void *pvAuxInfo,
     BCRYPT_KEY_HANDLE *phKey
    );
typedef BOOL (  *PFN_IMPORT_PUBLIC_KEY_INFO_EX2_FUNC) (
     DWORD dwCertEncodingType,
     PCERT_PUBLIC_KEY_INFO pInfo,
     DWORD dwFlags,
     void *pvAuxInfo,
     BCRYPT_KEY_HANDLE *phKey
    );
__declspec(dllimport)
BOOL

CryptAcquireCertificatePrivateKey(
     PCCERT_CONTEXT pCert,
     DWORD dwFlags,
     void *pvReserved,
     HCRYPTPROV_OR_NCRYPT_KEY_HANDLE *phCryptProvOrNCryptKey,
     DWORD *pdwKeySpec,
     BOOL *pfCallerFreeProvOrNCryptKey
    );
__declspec(dllimport)
BOOL

CryptFindCertificateKeyProvInfo(
     PCCERT_CONTEXT pCert,
     DWORD dwFlags,
     void *pvReserved
    );
typedef BOOL (  *PFN_IMPORT_PRIV_KEY_FUNC) (
     HCRYPTPROV hCryptProv,
     CRYPT_PRIVATE_KEY_INFO* pPrivateKeyInfo,
     DWORD dwFlags,
     void* pvAuxInfo
    );
__declspec(dllimport)
BOOL

CryptImportPKCS8(
     CRYPT_PKCS8_IMPORT_PARAMS sPrivateKeyAndParams,
     DWORD dwFlags,
     HCRYPTPROV *phCryptProv,
     void* pvAuxInfo
    );




typedef BOOL (  *PFN_EXPORT_PRIV_KEY_FUNC) (
     HCRYPTPROV hCryptProv,
     DWORD dwKeySpec,
     LPSTR pszPrivateKeyObjId,
     DWORD dwFlags,
     void* pvAuxInfo,
     CRYPT_PRIVATE_KEY_INFO* pPrivateKeyInfo,
     DWORD* pcbPrivateKeyInfo
    );









__declspec(dllimport)
BOOL

CryptExportPKCS8(
     HCRYPTPROV hCryptProv,
     DWORD dwKeySpec,
     LPSTR pszPrivateKeyObjId,
     DWORD dwFlags,
     void* pvAuxInfo,
     BYTE* pbPrivateKeyBlob,
     DWORD *pcbPrivateKeyBlob
    );
__declspec(dllimport)
BOOL

CryptExportPKCS8Ex(
     CRYPT_PKCS8_EXPORT_PARAMS* psExportParams,
     DWORD dwFlags,
     void* pvAuxInfo,
     BYTE* pbPrivateKeyBlob,
     DWORD* pcbPrivateKeyBlob
    );






__declspec(dllimport)
BOOL

CryptHashPublicKeyInfo(
     HCRYPTPROV_LEGACY hCryptProv,
     ALG_ID Algid,
     DWORD dwFlags,
     DWORD dwCertEncodingType,
     PCERT_PUBLIC_KEY_INFO pInfo,
     BYTE *pbComputedHash,
     DWORD *pcbComputedHash
    );
__declspec(dllimport)
DWORD

CertRDNValueToStrA(
     DWORD dwValueType,
     PCERT_RDN_VALUE_BLOB pValue,
     LPSTR psz,
     DWORD csz
    );
__declspec(dllimport)
DWORD

CertRDNValueToStrW(
     DWORD dwValueType,
     PCERT_RDN_VALUE_BLOB pValue,
     LPWSTR psz,
     DWORD csz
    );
__declspec(dllimport)
DWORD

CertNameToStrA(
     DWORD dwCertEncodingType,
     PCERT_NAME_BLOB pName,
     DWORD dwStrType,
     LPSTR psz,
     DWORD csz
    );


__declspec(dllimport)
DWORD

CertNameToStrW(
     DWORD dwCertEncodingType,
     PCERT_NAME_BLOB pName,
     DWORD dwStrType,
     LPWSTR psz,
     DWORD csz
    );
__declspec(dllimport)
BOOL

CertStrToNameA(
     DWORD dwCertEncodingType,
     LPCSTR pszX500,
     DWORD dwStrType,
     void *pvReserved,
     BYTE *pbEncoded,
     DWORD *pcbEncoded,
     LPCSTR *ppszError
    );


__declspec(dllimport)
BOOL

CertStrToNameW(
     DWORD dwCertEncodingType,
     LPCWSTR pszX500,
     DWORD dwStrType,
     void *pvReserved,
     BYTE *pbEncoded,
     DWORD *pcbEncoded,
     LPCWSTR *ppszError
    );
__declspec(dllimport)
DWORD

CertGetNameStringA(
     PCCERT_CONTEXT pCertContext,
     DWORD dwType,
     DWORD dwFlags,
     void *pvTypePara,
     LPSTR pszNameString,
     DWORD cchNameString
    );


__declspec(dllimport)
DWORD

CertGetNameStringW(
     PCCERT_CONTEXT pCertContext,
     DWORD dwType,
     DWORD dwFlags,
     void *pvTypePara,
     LPWSTR pszNameString,
     DWORD cchNameString
    );
typedef PCCERT_CONTEXT (  *PFN_CRYPT_GET_SIGNER_CERTIFICATE)(
     void *pvGetArg,
     DWORD dwCertEncodingType,
     PCERT_INFO pSignerId,

     HCERTSTORE hMsgCertStore
    );
typedef struct _CRYPT_SIGN_MESSAGE_PARA {
    DWORD cbSize;
    DWORD dwMsgEncodingType;
    PCCERT_CONTEXT pSigningCert;
    CRYPT_ALGORITHM_IDENTIFIER HashAlgorithm;
    void *pvHashAuxInfo;
    DWORD cMsgCert;
    PCCERT_CONTEXT *rgpMsgCert;
    DWORD cMsgCrl;
    PCCRL_CONTEXT *rgpMsgCrl;
    DWORD cAuthAttr;
    PCRYPT_ATTRIBUTE rgAuthAttr;
    DWORD cUnauthAttr;
    PCRYPT_ATTRIBUTE rgUnauthAttr;
    DWORD dwFlags;
    DWORD dwInnerContentType;
} CRYPT_SIGN_MESSAGE_PARA, *PCRYPT_SIGN_MESSAGE_PARA;
typedef struct _CRYPT_VERIFY_MESSAGE_PARA {
    DWORD cbSize;
    DWORD dwMsgAndCertEncodingType;
    HCRYPTPROV_LEGACY hCryptProv;
    PFN_CRYPT_GET_SIGNER_CERTIFICATE pfnGetSignerCertificate;
    void *pvGetArg;
} CRYPT_VERIFY_MESSAGE_PARA, *PCRYPT_VERIFY_MESSAGE_PARA;
typedef struct _CRYPT_ENCRYPT_MESSAGE_PARA {
    DWORD cbSize;
    DWORD dwMsgEncodingType;
    HCRYPTPROV_LEGACY hCryptProv;
    CRYPT_ALGORITHM_IDENTIFIER ContentEncryptionAlgorithm;
    void *pvEncryptionAuxInfo;
    DWORD dwFlags;
    DWORD dwInnerContentType;
} CRYPT_ENCRYPT_MESSAGE_PARA, *PCRYPT_ENCRYPT_MESSAGE_PARA;
typedef struct _CRYPT_DECRYPT_MESSAGE_PARA {
    DWORD cbSize;
    DWORD dwMsgAndCertEncodingType;
    DWORD cCertStore;
    HCERTSTORE *rghCertStore;
} CRYPT_DECRYPT_MESSAGE_PARA, *PCRYPT_DECRYPT_MESSAGE_PARA;
typedef struct _CRYPT_HASH_MESSAGE_PARA {
    DWORD cbSize;
    DWORD dwMsgEncodingType;
    HCRYPTPROV_LEGACY hCryptProv;
    CRYPT_ALGORITHM_IDENTIFIER HashAlgorithm;
    void *pvHashAuxInfo;
} CRYPT_HASH_MESSAGE_PARA, *PCRYPT_HASH_MESSAGE_PARA;
typedef struct _CRYPT_KEY_SIGN_MESSAGE_PARA {
    DWORD cbSize;
    DWORD dwMsgAndCertEncodingType;


    union {
        HCRYPTPROV hCryptProv;
        NCRYPT_KEY_HANDLE hNCryptKey;
    }  u ;


    DWORD dwKeySpec;

    CRYPT_ALGORITHM_IDENTIFIER HashAlgorithm;
    void *pvHashAuxInfo;

    CRYPT_ALGORITHM_IDENTIFIER PubKeyAlgorithm;
} CRYPT_KEY_SIGN_MESSAGE_PARA, *PCRYPT_KEY_SIGN_MESSAGE_PARA;
typedef struct _CRYPT_KEY_VERIFY_MESSAGE_PARA {
    DWORD cbSize;
    DWORD dwMsgEncodingType;
    HCRYPTPROV_LEGACY hCryptProv;
} CRYPT_KEY_VERIFY_MESSAGE_PARA, *PCRYPT_KEY_VERIFY_MESSAGE_PARA;








__declspec(dllimport)
BOOL

CryptSignMessage(
     PCRYPT_SIGN_MESSAGE_PARA pSignPara,
     BOOL fDetachedSignature,
     DWORD cToBeSigned,
     const BYTE *rgpbToBeSigned[],
     DWORD rgcbToBeSigned[],
     BYTE *pbSignedBlob,
     DWORD *pcbSignedBlob
    );
__declspec(dllimport)
BOOL

CryptVerifyMessageSignature(
     PCRYPT_VERIFY_MESSAGE_PARA pVerifyPara,
     DWORD dwSignerIndex,
     const BYTE *pbSignedBlob,
     DWORD cbSignedBlob,
     BYTE *pbDecoded,
     DWORD *pcbDecoded,
     PCCERT_CONTEXT *ppSignerCert
    );





__declspec(dllimport)
LONG

CryptGetMessageSignerCount(
     DWORD dwMsgEncodingType,
     const BYTE *pbSignedBlob,
     DWORD cbSignedBlob
    );





__declspec(dllimport)
HCERTSTORE

CryptGetMessageCertificates(
     DWORD dwMsgAndCertEncodingType,
     HCRYPTPROV_LEGACY hCryptProv,
     DWORD dwFlags,
     const BYTE *pbSignedBlob,
     DWORD cbSignedBlob
    );






__declspec(dllimport)
BOOL

CryptVerifyDetachedMessageSignature(
     PCRYPT_VERIFY_MESSAGE_PARA pVerifyPara,
     DWORD dwSignerIndex,
     const BYTE *pbDetachedSignBlob,
     DWORD cbDetachedSignBlob,
     DWORD cToBeSigned,
     const BYTE *rgpbToBeSigned[],
     DWORD rgcbToBeSigned[],
     PCCERT_CONTEXT *ppSignerCert
    );




__declspec(dllimport)
BOOL

CryptEncryptMessage(
     PCRYPT_ENCRYPT_MESSAGE_PARA pEncryptPara,
     DWORD cRecipientCert,
     PCCERT_CONTEXT rgpRecipientCert[],
     const BYTE *pbToBeEncrypted,
     DWORD cbToBeEncrypted,
     BYTE *pbEncryptedBlob,
     DWORD *pcbEncryptedBlob
    );
__declspec(dllimport)
BOOL

CryptDecryptMessage(
     PCRYPT_DECRYPT_MESSAGE_PARA pDecryptPara,
     const BYTE *pbEncryptedBlob,
     DWORD cbEncryptedBlob,
     BYTE *pbDecrypted,
     DWORD *pcbDecrypted,
     PCCERT_CONTEXT *ppXchgCert
    );








__declspec(dllimport)
BOOL

CryptSignAndEncryptMessage(
     PCRYPT_SIGN_MESSAGE_PARA pSignPara,
     PCRYPT_ENCRYPT_MESSAGE_PARA pEncryptPara,
     DWORD cRecipientCert,
     PCCERT_CONTEXT rgpRecipientCert[],
     const BYTE *pbToBeSignedAndEncrypted,
     DWORD cbToBeSignedAndEncrypted,
     BYTE *pbSignedAndEncryptedBlob,
     DWORD *pcbSignedAndEncryptedBlob
    );
__declspec(dllimport)
BOOL

CryptDecryptAndVerifyMessageSignature(
     PCRYPT_DECRYPT_MESSAGE_PARA pDecryptPara,
     PCRYPT_VERIFY_MESSAGE_PARA pVerifyPara,
     DWORD dwSignerIndex,
     const BYTE *pbEncryptedBlob,
     DWORD cbEncryptedBlob,
     BYTE *pbDecrypted,
     DWORD *pcbDecrypted,
     PCCERT_CONTEXT *ppXchgCert,
     PCCERT_CONTEXT *ppSignerCert
    );
__declspec(dllimport)
BOOL

CryptDecodeMessage(
     DWORD dwMsgTypeFlags,
     PCRYPT_DECRYPT_MESSAGE_PARA pDecryptPara,
     PCRYPT_VERIFY_MESSAGE_PARA pVerifyPara,
     DWORD dwSignerIndex,
     const BYTE *pbEncodedBlob,
     DWORD cbEncodedBlob,
     DWORD dwPrevInnerContentType,
     DWORD *pdwMsgType,
     DWORD *pdwInnerContentType,
     BYTE *pbDecoded,
     DWORD *pcbDecoded,
     PCCERT_CONTEXT *ppXchgCert,
     PCCERT_CONTEXT *ppSignerCert
    );
__declspec(dllimport)
BOOL

CryptHashMessage(
     PCRYPT_HASH_MESSAGE_PARA pHashPara,
     BOOL fDetachedHash,
     DWORD cToBeHashed,
     const BYTE *rgpbToBeHashed[],
     DWORD rgcbToBeHashed[],
     BYTE *pbHashedBlob,
     DWORD *pcbHashedBlob,
     BYTE *pbComputedHash,
     DWORD *pcbComputedHash
    );







__declspec(dllimport)
BOOL

CryptVerifyMessageHash(
     PCRYPT_HASH_MESSAGE_PARA pHashPara,
     BYTE *pbHashedBlob,
     DWORD cbHashedBlob,
     BYTE *pbToBeHashed,
     DWORD *pcbToBeHashed,
     BYTE *pbComputedHash,
     DWORD *pcbComputedHash
    );









__declspec(dllimport)
BOOL

CryptVerifyDetachedMessageHash(
     PCRYPT_HASH_MESSAGE_PARA pHashPara,
     BYTE *pbDetachedHashBlob,
     DWORD cbDetachedHashBlob,
     DWORD cToBeHashed,
     const BYTE *rgpbToBeHashed[],
     DWORD rgcbToBeHashed[],
     BYTE *pbComputedHash,
     DWORD *pcbComputedHash
    );







__declspec(dllimport)
BOOL

CryptSignMessageWithKey(
     PCRYPT_KEY_SIGN_MESSAGE_PARA pSignPara,
     const BYTE *pbToBeSigned,
     DWORD cbToBeSigned,
     BYTE *pbSignedBlob,
     DWORD *pcbSignedBlob
    );
__declspec(dllimport)
BOOL

CryptVerifyMessageSignatureWithKey(
     PCRYPT_KEY_VERIFY_MESSAGE_PARA pVerifyPara,
     PCERT_PUBLIC_KEY_INFO pPublicKeyInfo,
     const BYTE *pbSignedBlob,
     DWORD cbSignedBlob,
     BYTE *pbDecoded,
     DWORD *pcbDecoded
    );
__declspec(dllimport)
HCERTSTORE

CertOpenSystemStoreA(
     HCRYPTPROV_LEGACY hProv,
     LPCSTR szSubsystemProtocol
    );
__declspec(dllimport)
HCERTSTORE

CertOpenSystemStoreW(
     HCRYPTPROV_LEGACY hProv,
     LPCWSTR szSubsystemProtocol
    );






__declspec(dllimport)
BOOL

CertAddEncodedCertificateToSystemStoreA(
     LPCSTR szCertStoreName,
     const BYTE * pbCertEncoded,
     DWORD cbCertEncoded
    );
__declspec(dllimport)
BOOL

CertAddEncodedCertificateToSystemStoreW(
     LPCWSTR szCertStoreName,
     const BYTE * pbCertEncoded,
     DWORD cbCertEncoded
    );
typedef struct _CERT_CHAIN {
    DWORD cCerts;
    PCERT_BLOB certs;

    CRYPT_KEY_PROV_INFO keyLocatorInfo;
} CERT_CHAIN, *PCERT_CHAIN;



HRESULT

FindCertsByIssuer(
     PCERT_CHAIN pCertChains,
     DWORD *pcbCertChains,
     DWORD *pcCertChains,
     BYTE* pbEncodedIssuerName,
     DWORD cbEncodedIssuerName,
     LPCWSTR pwszPurpose,
     DWORD dwKeySpec

    );
__declspec(dllimport)
BOOL

CryptQueryObject(
     DWORD dwObjectType,
     const void *pvObject,
     DWORD dwExpectedContentTypeFlags,
     DWORD dwExpectedFormatTypeFlags,
     DWORD dwFlags,
     DWORD *pdwMsgAndCertEncodingType,
     DWORD *pdwContentType,
     DWORD *pdwFormatType,
     HCERTSTORE *phCertStore,
     HCRYPTMSG *phMsg,
     const void **ppvContext
    );
__declspec(dllimport)
LPVOID

CryptMemAlloc (
     ULONG cbSize
    );

__declspec(dllimport)
LPVOID

CryptMemRealloc (
     LPVOID pv,
     ULONG cbSize
    );

__declspec(dllimport)
void

CryptMemFree (
     LPVOID pv
    );
typedef HANDLE HCRYPTASYNC, *PHCRYPTASYNC;

typedef  void  (  *PFN_CRYPT_ASYNC_PARAM_FREE_FUNC) (
     LPSTR pszParamOid,
     LPVOID pvParam
    );

__declspec(dllimport)
BOOL

CryptCreateAsyncHandle (
     DWORD dwFlags,
     PHCRYPTASYNC phAsync
    );

__declspec(dllimport)
BOOL

CryptSetAsyncParam (
     HCRYPTASYNC hAsync,
     LPSTR pszParamOid,
     LPVOID pvParam,
     PFN_CRYPT_ASYNC_PARAM_FREE_FUNC pfnFree
    );

__declspec(dllimport)
BOOL

CryptGetAsyncParam (
     HCRYPTASYNC hAsync,
     LPSTR pszParamOid,
     LPVOID* ppvParam,
       PFN_CRYPT_ASYNC_PARAM_FREE_FUNC* ppfnFree
    );

__declspec(dllimport)
BOOL

CryptCloseAsyncHandle (
     HCRYPTASYNC hAsync
    );
typedef struct _CRYPT_BLOB_ARRAY {
    DWORD cBlob;
    PCRYPT_DATA_BLOB rgBlob;
} CRYPT_BLOB_ARRAY, *PCRYPT_BLOB_ARRAY;

typedef struct _CRYPT_CREDENTIALS {
    DWORD cbSize;
    LPCSTR pszCredentialsOid;
    LPVOID pvCredentials;
} CRYPT_CREDENTIALS, *PCRYPT_CREDENTIALS;










typedef struct _CRYPT_PASSWORD_CREDENTIALSA {
    DWORD cbSize;
    LPSTR pszUsername;
    LPSTR pszPassword;
} CRYPT_PASSWORD_CREDENTIALSA, *PCRYPT_PASSWORD_CREDENTIALSA;
typedef struct _CRYPT_PASSWORD_CREDENTIALSW {
    DWORD cbSize;
    LPWSTR pszUsername;
    LPWSTR pszPassword;
} CRYPT_PASSWORD_CREDENTIALSW, *PCRYPT_PASSWORD_CREDENTIALSW;




typedef CRYPT_PASSWORD_CREDENTIALSA CRYPT_PASSWORD_CREDENTIALS;
typedef PCRYPT_PASSWORD_CREDENTIALSA PCRYPT_PASSWORD_CREDENTIALS;
typedef  void  (  *PFN_FREE_ENCODED_OBJECT_FUNC) (
     LPCSTR pszObjectOid,
     PCRYPT_BLOB_ARRAY pObject,
     LPVOID pvFreeContext
    );
typedef struct _CRYPTNET_URL_CACHE_PRE_FETCH_INFO {
    DWORD cbSize;
    DWORD dwObjectType;







    DWORD dwError;
    DWORD dwReserved;

    FILETIME ThisUpdateTime;
    FILETIME NextUpdateTime;
    FILETIME PublishTime;
} CRYPTNET_URL_CACHE_PRE_FETCH_INFO, *PCRYPTNET_URL_CACHE_PRE_FETCH_INFO;
typedef struct _CRYPTNET_URL_CACHE_FLUSH_INFO {
    DWORD cbSize;




    DWORD dwExemptSeconds;




    FILETIME ExpireTime;
} CRYPTNET_URL_CACHE_FLUSH_INFO, *PCRYPTNET_URL_CACHE_FLUSH_INFO;








typedef struct _CRYPTNET_URL_CACHE_RESPONSE_INFO {
    DWORD cbSize;
    WORD wResponseType;
    WORD wResponseFlags;


    FILETIME LastModifiedTime;
    DWORD dwMaxAge;
    LPCWSTR pwszETag;
    DWORD dwProxyId;
} CRYPTNET_URL_CACHE_RESPONSE_INFO, *PCRYPTNET_URL_CACHE_RESPONSE_INFO;
typedef struct _CRYPT_RETRIEVE_AUX_INFO {
    DWORD cbSize;
    FILETIME *pLastSyncTime;


    DWORD dwMaxUrlRetrievalByteCount;





    PCRYPTNET_URL_CACHE_PRE_FETCH_INFO pPreFetchInfo;





    PCRYPTNET_URL_CACHE_FLUSH_INFO pFlushInfo;





    PCRYPTNET_URL_CACHE_RESPONSE_INFO *ppResponseInfo;



    LPWSTR pwszCacheFileNamePrefix;





    LPFILETIME pftCacheResync;





    BOOL fProxyCacheRetrieval;









    DWORD dwHttpStatusCode;
} CRYPT_RETRIEVE_AUX_INFO, *PCRYPT_RETRIEVE_AUX_INFO;


__declspec(dllimport)

BOOL

CryptRetrieveObjectByUrlA (
     LPCSTR pszUrl,
     LPCSTR pszObjectOid,
     DWORD dwRetrievalFlags,
     DWORD dwTimeout,
     LPVOID* ppvObject,
     HCRYPTASYNC hAsyncRetrieve,
     PCRYPT_CREDENTIALS pCredentials,
     LPVOID pvVerify,
     PCRYPT_RETRIEVE_AUX_INFO pAuxInfo
    );
__declspec(dllimport)

BOOL

CryptRetrieveObjectByUrlW (
     LPCWSTR pszUrl,
     LPCSTR pszObjectOid,
     DWORD dwRetrievalFlags,
     DWORD dwTimeout,
     LPVOID* ppvObject,
     HCRYPTASYNC hAsyncRetrieve,
     PCRYPT_CREDENTIALS pCredentials,
     LPVOID pvVerify,
     PCRYPT_RETRIEVE_AUX_INFO pAuxInfo
    );
typedef BOOL (  *PFN_CRYPT_CANCEL_RETRIEVAL)(
     DWORD dwFlags,
     void *pvArg
    );









__declspec(dllimport)
BOOL

CryptInstallCancelRetrieval(
     PFN_CRYPT_CANCEL_RETRIEVAL pfnCancel,
     const void *pvArg,
     DWORD dwFlags,
     void *pvReserved
);


__declspec(dllimport)
BOOL

CryptUninstallCancelRetrieval(
         DWORD dwFlags,
         void *pvReserved
        );


__declspec(dllimport)
BOOL

CryptCancelAsyncRetrieval (
     HCRYPTASYNC hAsyncRetrieval
    );
typedef  void  (  *PFN_CRYPT_ASYNC_RETRIEVAL_COMPLETION_FUNC) (
     LPVOID pvCompletion,
     DWORD dwCompletionCode,
     LPCSTR pszUrl,
     LPSTR pszObjectOid,
     LPVOID pvObject
    );

typedef struct _CRYPT_ASYNC_RETRIEVAL_COMPLETION {
     PFN_CRYPT_ASYNC_RETRIEVAL_COMPLETION_FUNC pfnCompletion;
     LPVOID pvCompletion;
} CRYPT_ASYNC_RETRIEVAL_COMPLETION, *PCRYPT_ASYNC_RETRIEVAL_COMPLETION;








typedef BOOL (  *PFN_CANCEL_ASYNC_RETRIEVAL_FUNC) (
     HCRYPTASYNC hAsyncRetrieve
    );










typedef struct _CRYPT_URL_ARRAY {
    DWORD cUrl;
    LPWSTR* rgwszUrl;
} CRYPT_URL_ARRAY, *PCRYPT_URL_ARRAY;

typedef struct _CRYPT_URL_INFO {
    DWORD cbSize;


    DWORD dwSyncDeltaTime;




    DWORD cGroup;
    DWORD *rgcGroupEntry;
} CRYPT_URL_INFO, *PCRYPT_URL_INFO;

__declspec(dllimport)
BOOL

CryptGetObjectUrl (
     LPCSTR pszUrlOid,
     LPVOID pvPara,
     DWORD dwFlags,
     PCRYPT_URL_ARRAY pUrlArray,
     DWORD* pcbUrlArray,
     PCRYPT_URL_INFO pUrlInfo,
     DWORD* pcbUrlInfo,
     LPVOID pvReserved
    );
typedef struct _CERT_CRL_CONTEXT_PAIR {
    PCCERT_CONTEXT pCertContext;
    PCCRL_CONTEXT pCrlContext;
} CERT_CRL_CONTEXT_PAIR, *PCERT_CRL_CONTEXT_PAIR;
typedef const CERT_CRL_CONTEXT_PAIR *PCCERT_CRL_CONTEXT_PAIR;
typedef struct _CRYPT_GET_TIME_VALID_OBJECT_EXTRA_INFO {
    DWORD cbSize;


    int iDeltaCrlIndicator;



    LPFILETIME pftCacheResync;


    LPFILETIME pLastSyncTime;




    LPFILETIME pMaxAgeTime;



    PCERT_REVOCATION_CHAIN_PARA pChainPara;
} CRYPT_GET_TIME_VALID_OBJECT_EXTRA_INFO,
    *PCRYPT_GET_TIME_VALID_OBJECT_EXTRA_INFO;

__declspec(dllimport)

BOOL

CryptGetTimeValidObject (
     LPCSTR pszTimeValidOid,
     LPVOID pvPara,
     PCCERT_CONTEXT pIssuer,
     LPFILETIME pftValidFor,
     DWORD dwFlags,
     DWORD dwTimeout,
     LPVOID* ppvObject,
     PCRYPT_CREDENTIALS pCredentials,
     PCRYPT_GET_TIME_VALID_OBJECT_EXTRA_INFO pExtraInfo
    );
__declspec(dllimport)
BOOL

CryptFlushTimeValidObject (
      LPCSTR pszFlushTimeValidOid,
      LPVOID pvPara,
      PCCERT_CONTEXT pIssuer,
      DWORD dwFlags,
      LPVOID pvReserved
     );
typedef struct _CRYPTPROTECT_PROMPTSTRUCT
{
    DWORD cbSize;
    DWORD dwPromptFlags;
    HWND hwndApp;
    LPCWSTR szPrompt;
} CRYPTPROTECT_PROMPTSTRUCT, *PCRYPTPROTECT_PROMPTSTRUCT;
__declspec(dllimport)
BOOL

CryptProtectData(
     DATA_BLOB* pDataIn,
     LPCWSTR szDataDescr,
       DATA_BLOB* pOptionalEntropy,
     PVOID pvReserved,
       CRYPTPROTECT_PROMPTSTRUCT* pPromptStruct,
     DWORD dwFlags,
     DATA_BLOB* pDataOut
    );

__declspec(dllimport)
BOOL

CryptUnprotectData(
     DATA_BLOB* pDataIn,
     LPWSTR* ppszDataDescr,
       DATA_BLOB* pOptionalEntropy,
     PVOID pvReserved,
       CRYPTPROTECT_PROMPTSTRUCT* pPromptStruct,
     DWORD dwFlags,
     DATA_BLOB* pDataOut
    );

__declspec(dllimport)
BOOL

CryptUpdateProtectedState(
     PSID pOldSid,
     LPCWSTR pwszOldPassword,
     DWORD dwFlags,
     DWORD *pdwSuccessCount,
     DWORD *pdwFailureCount);
__declspec(dllimport)
BOOL

CryptProtectMemory(
       LPVOID pDataIn,
     DWORD cbDataIn,
     DWORD dwFlags
    );

__declspec(dllimport)
BOOL

CryptUnprotectMemory(
       LPVOID pDataIn,
     DWORD cbDataIn,
     DWORD dwFlags
    );
__declspec(dllimport)
PCCERT_CONTEXT

CertCreateSelfSignCertificate(
     HCRYPTPROV_OR_NCRYPT_KEY_HANDLE hCryptProvOrNCryptKey,
     PCERT_NAME_BLOB pSubjectIssuerBlob,
     DWORD dwFlags,
     PCRYPT_KEY_PROV_INFO pKeyProvInfo,
     PCRYPT_ALGORITHM_IDENTIFIER pSignatureAlgorithm,
     PSYSTEMTIME pStartTime,
     PSYSTEMTIME pEndTime,
     PCERT_EXTENSIONS pExtensions
    );
__declspec(dllimport)
BOOL

CryptGetKeyIdentifierProperty(
     const CRYPT_HASH_BLOB *pKeyIdentifier,
     DWORD dwPropId,
     DWORD dwFlags,
     LPCWSTR pwszComputerName,
     void *pvReserved,
     void *pvData,
     DWORD *pcbData
    );
__declspec(dllimport)
BOOL

CryptSetKeyIdentifierProperty(
     const CRYPT_HASH_BLOB *pKeyIdentifier,
     DWORD dwPropId,
     DWORD dwFlags,
     LPCWSTR pwszComputerName,
     void *pvReserved,
     const void *pvData
    );
typedef BOOL (  *PFN_CRYPT_ENUM_KEYID_PROP)(
     const CRYPT_HASH_BLOB *pKeyIdentifier,
     DWORD dwFlags,
     void *pvReserved,
     void *pvArg,
     DWORD cProp,
     DWORD *rgdwPropId,
     void **rgpvData,
     DWORD *rgcbData
    );
__declspec(dllimport)
BOOL

CryptEnumKeyIdentifierProperties(
     const CRYPT_HASH_BLOB *pKeyIdentifier,
     DWORD dwPropId,
     DWORD dwFlags,
     LPCWSTR pwszComputerName,
     void *pvReserved,
     void *pvArg,
     PFN_CRYPT_ENUM_KEYID_PROP pfnEnum
    );
__declspec(dllimport)
BOOL

CryptCreateKeyIdentifierFromCSP(
     DWORD dwCertEncodingType,
     LPCSTR pszPubKeyOID,
     const PUBLICKEYSTRUC *pPubKeyStruc,
     DWORD cbPubKeyStruc,
     DWORD dwFlags,
     void *pvReserved,
     BYTE *pbHash,
     DWORD *pcbHash
    );
typedef HANDLE HCERTCHAINENGINE;
typedef struct _CERT_CHAIN_ENGINE_CONFIG {

    DWORD cbSize;
    HCERTSTORE hRestrictedRoot;
    HCERTSTORE hRestrictedTrust;
    HCERTSTORE hRestrictedOther;
    DWORD cAdditionalStore;
    HCERTSTORE* rghAdditionalStore;
    DWORD dwFlags;
    DWORD dwUrlRetrievalTimeout;
    DWORD MaximumCachedCertificates;
    DWORD CycleDetectionModulus;

} CERT_CHAIN_ENGINE_CONFIG, *PCERT_CHAIN_ENGINE_CONFIG;

__declspec(dllimport)

BOOL

CertCreateCertificateChainEngine (
     PCERT_CHAIN_ENGINE_CONFIG pConfig,
     HCERTCHAINENGINE* phChainEngine
    );





__declspec(dllimport)
void

CertFreeCertificateChainEngine (
     HCERTCHAINENGINE hChainEngine
    );






__declspec(dllimport)
BOOL

CertResyncCertificateChainEngine (
     HCERTCHAINENGINE hChainEngine
    );
typedef struct _CERT_TRUST_STATUS {

    DWORD dwErrorStatus;
    DWORD dwInfoStatus;

} CERT_TRUST_STATUS, *PCERT_TRUST_STATUS;
typedef struct _CERT_REVOCATION_INFO {

    DWORD cbSize;
    DWORD dwRevocationResult;
    LPCSTR pszRevocationOid;
    LPVOID pvOidSpecificInfo;



    BOOL fHasFreshnessTime;
    DWORD dwFreshnessTime;


    PCERT_REVOCATION_CRL_INFO pCrlInfo;

} CERT_REVOCATION_INFO, *PCERT_REVOCATION_INFO;





typedef struct _CERT_TRUST_LIST_INFO {

    DWORD cbSize;
    PCTL_ENTRY pCtlEntry;
    PCCTL_CONTEXT pCtlContext;

} CERT_TRUST_LIST_INFO, *PCERT_TRUST_LIST_INFO;





typedef struct _CERT_CHAIN_ELEMENT {

    DWORD cbSize;
    PCCERT_CONTEXT pCertContext;
    CERT_TRUST_STATUS TrustStatus;
    PCERT_REVOCATION_INFO pRevocationInfo;

    PCERT_ENHKEY_USAGE pIssuanceUsage;
    PCERT_ENHKEY_USAGE pApplicationUsage;

    LPCWSTR pwszExtendedErrorInfo;
} CERT_CHAIN_ELEMENT, *PCERT_CHAIN_ELEMENT;










typedef struct _CERT_SIMPLE_CHAIN {

    DWORD cbSize;
    CERT_TRUST_STATUS TrustStatus;
    DWORD cElement;
    PCERT_CHAIN_ELEMENT* rgpElement;
    PCERT_TRUST_LIST_INFO pTrustListInfo;







    BOOL fHasRevocationFreshnessTime;
    DWORD dwRevocationFreshnessTime;

} CERT_SIMPLE_CHAIN, *PCERT_SIMPLE_CHAIN;
typedef struct _CERT_CHAIN_CONTEXT CERT_CHAIN_CONTEXT, *PCERT_CHAIN_CONTEXT;
typedef const CERT_CHAIN_CONTEXT *PCCERT_CHAIN_CONTEXT;

struct _CERT_CHAIN_CONTEXT {
    DWORD cbSize;
    CERT_TRUST_STATUS TrustStatus;
    DWORD cChain;
    PCERT_SIMPLE_CHAIN* rgpChain;



    DWORD cLowerQualityChainContext;
    PCCERT_CHAIN_CONTEXT* rgpLowerQualityChainContext;







    BOOL fHasRevocationFreshnessTime;
    DWORD dwRevocationFreshnessTime;


    DWORD dwCreateFlags;


    GUID ChainId;
};
typedef struct _CERT_USAGE_MATCH {

    DWORD dwType;
    CERT_ENHKEY_USAGE Usage;

} CERT_USAGE_MATCH, *PCERT_USAGE_MATCH;

typedef struct _CTL_USAGE_MATCH {

    DWORD dwType;
    CTL_USAGE Usage;

} CTL_USAGE_MATCH, *PCTL_USAGE_MATCH;

typedef struct _CERT_CHAIN_PARA {

    DWORD cbSize;
    CERT_USAGE_MATCH RequestedUsage;
} CERT_CHAIN_PARA, *PCERT_CHAIN_PARA;
__declspec(dllimport)

BOOL

CertGetCertificateChain (
     HCERTCHAINENGINE hChainEngine,
     PCCERT_CONTEXT pCertContext,
     LPFILETIME pTime,
     HCERTSTORE hAdditionalStore,
     PCERT_CHAIN_PARA pChainPara,
     DWORD dwFlags,
     LPVOID pvReserved,
     PCCERT_CHAIN_CONTEXT* ppChainContext
    );





__declspec(dllimport)
void

CertFreeCertificateChain (
     PCCERT_CHAIN_CONTEXT pChainContext
    );





__declspec(dllimport)
PCCERT_CHAIN_CONTEXT

CertDuplicateCertificateChain (
     PCCERT_CHAIN_CONTEXT pChainContext
    );







struct _CERT_REVOCATION_CHAIN_PARA {
    DWORD cbSize;
    HCERTCHAINENGINE hChainEngine;
    HCERTSTORE hAdditionalStore;
    DWORD dwChainFlags;
    DWORD dwUrlRetrievalTimeout;
    LPFILETIME pftCurrentTime;
    LPFILETIME pftCacheResync;
};
typedef struct _CRL_REVOCATION_INFO {

    PCRL_ENTRY pCrlEntry;
    PCCRL_CONTEXT pCrlContext;
    PCCERT_CHAIN_CONTEXT pCrlIssuerChain;

} CRL_REVOCATION_INFO, *PCRL_REVOCATION_INFO;
__declspec(dllimport)
PCCERT_CHAIN_CONTEXT

CertFindChainInStore(
     HCERTSTORE hCertStore,
     DWORD dwCertEncodingType,
     DWORD dwFindFlags,
     DWORD dwFindType,
     const void *pvFindPara,
     PCCERT_CHAIN_CONTEXT pPrevChainContext
    );
typedef BOOL (  *PFN_CERT_CHAIN_FIND_BY_ISSUER_CALLBACK)(
     PCCERT_CONTEXT pCert,
     void *pvFindArg
    );

typedef struct _CERT_CHAIN_FIND_BY_ISSUER_PARA {
    DWORD cbSize;


    LPCSTR pszUsageIdentifier;


    DWORD dwKeySpec;






    DWORD dwAcquirePrivateKeyFlags;



    DWORD cIssuer;
    CERT_NAME_BLOB *rgIssuer;




    PFN_CERT_CHAIN_FIND_BY_ISSUER_CALLBACK pfnFindCallback;
    void *pvFindArg;
} CERT_CHAIN_FIND_ISSUER_PARA, *PCERT_CHAIN_FIND_ISSUER_PARA,
    CERT_CHAIN_FIND_BY_ISSUER_PARA, *PCERT_CHAIN_FIND_BY_ISSUER_PARA;
typedef struct _CERT_CHAIN_POLICY_PARA {
    DWORD cbSize;
    DWORD dwFlags;
    void *pvExtraPolicyPara;
} CERT_CHAIN_POLICY_PARA, *PCERT_CHAIN_POLICY_PARA;






typedef struct _CERT_CHAIN_POLICY_STATUS {
    DWORD cbSize;
    DWORD dwError;
    LONG lChainIndex;
    LONG lElementIndex;
    void *pvExtraPolicyStatus;
} CERT_CHAIN_POLICY_STATUS, *PCERT_CHAIN_POLICY_STATUS;
__declspec(dllimport)
BOOL

CertVerifyCertificateChainPolicy(
     LPCSTR pszPolicyOID,
     PCCERT_CHAIN_CONTEXT pChainContext,
     PCERT_CHAIN_POLICY_PARA pPolicyPara,
     PCERT_CHAIN_POLICY_STATUS pPolicyStatus
    );
typedef struct _AUTHENTICODE_EXTRA_CERT_CHAIN_POLICY_PARA {
    DWORD cbSize;
    DWORD dwRegPolicySettings;
    PCMSG_SIGNER_INFO pSignerInfo;
} AUTHENTICODE_EXTRA_CERT_CHAIN_POLICY_PARA,
    *PAUTHENTICODE_EXTRA_CERT_CHAIN_POLICY_PARA;

typedef struct _AUTHENTICODE_EXTRA_CERT_CHAIN_POLICY_STATUS {
    DWORD cbSize;
    BOOL fCommercial;
} AUTHENTICODE_EXTRA_CERT_CHAIN_POLICY_STATUS,
    *PAUTHENTICODE_EXTRA_CERT_CHAIN_POLICY_STATUS;
typedef struct _AUTHENTICODE_TS_EXTRA_CERT_CHAIN_POLICY_PARA {
    DWORD cbSize;
    DWORD dwRegPolicySettings;
    BOOL fCommercial;
} AUTHENTICODE_TS_EXTRA_CERT_CHAIN_POLICY_PARA,
    *PAUTHENTICODE_TS_EXTRA_CERT_CHAIN_POLICY_PARA;
typedef struct _HTTPSPolicyCallbackData
{
    union {
        DWORD cbStruct;
        DWORD cbSize;
    }  u ;

    DWORD dwAuthType;



    DWORD fdwChecks;

    WCHAR *pwszServerName;

} HTTPSPolicyCallbackData, *PHTTPSPolicyCallbackData,
    SSL_EXTRA_CERT_CHAIN_POLICY_PARA, *PSSL_EXTRA_CERT_CHAIN_POLICY_PARA;
__declspec(dllimport)
BOOL

CryptStringToBinaryA(
     LPCSTR pszString,
     DWORD cchString,
     DWORD dwFlags,
     BYTE *pbBinary,
     DWORD *pcbBinary,
     DWORD *pdwSkip,
     DWORD *pdwFlags
    );









__declspec(dllimport)
BOOL

CryptStringToBinaryW(
     LPCWSTR pszString,
     DWORD cchString,
     DWORD dwFlags,
     BYTE *pbBinary,
     DWORD *pcbBinary,
     DWORD *pdwSkip,
     DWORD *pdwFlags
    );
__declspec(dllimport)
BOOL

CryptBinaryToStringA(
      const  BYTE *pbBinary,
     DWORD cbBinary,
     DWORD dwFlags,
     LPSTR pszString,
     DWORD *pcchString
    );






__declspec(dllimport)
BOOL

CryptBinaryToStringW(
      const  BYTE *pbBinary,
     DWORD cbBinary,
     DWORD dwFlags,
     LPWSTR pszString,
     DWORD *pcchString
    );
typedef struct _CRYPT_PKCS12_PBE_PARAMS
{
    int iIterations;
    ULONG cbSalt;
}
CRYPT_PKCS12_PBE_PARAMS;
__declspec(dllimport)
HCERTSTORE

PFXImportCertStore(
     CRYPT_DATA_BLOB* pPFX,
     LPCWSTR szPassword,
     DWORD dwFlags);
__declspec(dllimport)
BOOL

PFXIsPFXBlob(
     CRYPT_DATA_BLOB* pPFX);
__declspec(dllimport)
BOOL

PFXVerifyPassword(
     CRYPT_DATA_BLOB* pPFX,
     LPCWSTR szPassword,
     DWORD dwFlags);
__declspec(dllimport)
BOOL

PFXExportCertStoreEx(
     HCERTSTORE hStore,
     CRYPT_DATA_BLOB* pPFX,
     LPCWSTR szPassword,
     void* pvReserved,
     DWORD dwFlags);
__declspec(dllimport)
BOOL

PFXExportCertStore(
     HCERTSTORE hStore,
     CRYPT_DATA_BLOB* pPFX,
     LPCWSTR szPassword,
     DWORD dwFlags);
typedef  void  *HCERT_SERVER_OCSP_RESPONSE;
__declspec(dllimport)
HCERT_SERVER_OCSP_RESPONSE

CertOpenServerOcspResponse(
     PCCERT_CHAIN_CONTEXT pChainContext,
     DWORD dwFlags,
     LPVOID pvReserved
    );






__declspec(dllimport)
void

CertAddRefServerOcspResponse(
     HCERT_SERVER_OCSP_RESPONSE hServerOcspResponse
    );







__declspec(dllimport)
void

CertCloseServerOcspResponse(
     HCERT_SERVER_OCSP_RESPONSE hServerOcspResponse,
     DWORD dwFlags
    );





typedef struct _CERT_SERVER_OCSP_RESPONSE_CONTEXT
    CERT_SERVER_OCSP_RESPONSE_CONTEXT,
    *PCERT_SERVER_OCSP_RESPONSE_CONTEXT;
typedef const CERT_SERVER_OCSP_RESPONSE_CONTEXT
    *PCCERT_SERVER_OCSP_RESPONSE_CONTEXT;

struct _CERT_SERVER_OCSP_RESPONSE_CONTEXT {
    DWORD cbSize;
    BYTE *pbEncodedOcspResponse;
    DWORD cbEncodedOcspResponse;
};
__declspec(dllimport)
PCCERT_SERVER_OCSP_RESPONSE_CONTEXT

CertGetServerOcspResponseContext(
     HCERT_SERVER_OCSP_RESPONSE hServerOcspResponse,
     DWORD dwFlags,
     LPVOID pvReserved
    );






__declspec(dllimport)
void

CertAddRefServerOcspResponseContext(
     PCCERT_SERVER_OCSP_RESPONSE_CONTEXT pServerOcspResponseContext
    );





__declspec(dllimport)
void

CertFreeServerOcspResponseContext(
     PCCERT_SERVER_OCSP_RESPONSE_CONTEXT pServerOcspResponseContext
    );
__declspec(dllimport)

BOOL

CertRetrieveLogoOrBiometricInfo(
     PCCERT_CONTEXT pCertContext,
     LPCSTR lpszLogoOrBiometricType,
     DWORD dwRetrievalFlags,
     DWORD dwTimeout,
     DWORD dwFlags,
     void *pvReserved,
     BYTE **ppbData,
     DWORD *pcbData,
     LPWSTR *ppwszMimeType
    );
typedef struct _CERTIFICATE_BLOB {

    DWORD dwCertEncodingType;
    DWORD cbData;
    PBYTE pbData;

} EFS_CERTIFICATE_BLOB, *PEFS_CERTIFICATE_BLOB;





typedef struct _EFS_HASH_BLOB {
    DWORD cbData;
    PBYTE pbData;

} EFS_HASH_BLOB, *PEFS_HASH_BLOB;









typedef struct _EFS_RPC_BLOB {
    DWORD cbData;
    PBYTE pbData;

} EFS_RPC_BLOB, *PEFS_RPC_BLOB;






typedef struct _EFS_PIN_BLOB {
    DWORD cbPadding;
    DWORD cbData;
    PBYTE pbData;

} EFS_PIN_BLOB, *PEFS_PIN_BLOB;







typedef struct _EFS_KEY_INFO {

    DWORD dwVersion;
    ULONG Entropy;
    ALG_ID Algorithm;
    ULONG KeyLength;

} EFS_KEY_INFO, *PEFS_KEY_INFO;






typedef struct _EFS_DECRYPTION_STATUS_INFO {

    DWORD dwDecryptionError;
    DWORD dwHashOffset;
    DWORD cbHash;

} EFS_DECRYPTION_STATUS_INFO, *PEFS_DECRYPTION_STATUS_INFO;

typedef struct _EFS_ENCRYPTION_STATUS_INFO {

    BOOL bHasCurrentKey;
    DWORD dwEncryptionError;

} EFS_ENCRYPTION_STATUS_INFO, *PEFS_ENCRYPTION_STATUS_INFO;







typedef struct _ENCRYPTION_CERTIFICATE {
    DWORD cbTotalLength;
    SID * pUserSid;
    PEFS_CERTIFICATE_BLOB pCertBlob;
} ENCRYPTION_CERTIFICATE, *PENCRYPTION_CERTIFICATE;




typedef struct _ENCRYPTION_CERTIFICATE_HASH {
    DWORD cbTotalLength;
    SID * pUserSid;
    PEFS_HASH_BLOB pHash;
    LPWSTR lpDisplayInformation;

} ENCRYPTION_CERTIFICATE_HASH, *PENCRYPTION_CERTIFICATE_HASH;

typedef struct _ENCRYPTION_CERTIFICATE_HASH_LIST {
    DWORD nCert_Hash;
     PENCRYPTION_CERTIFICATE_HASH * pUsers;
} ENCRYPTION_CERTIFICATE_HASH_LIST, *PENCRYPTION_CERTIFICATE_HASH_LIST;



typedef struct _ENCRYPTION_CERTIFICATE_LIST {
    DWORD nUsers;
     PENCRYPTION_CERTIFICATE * pUsers;
} ENCRYPTION_CERTIFICATE_LIST, *PENCRYPTION_CERTIFICATE_LIST;









typedef struct _ENCRYPTED_FILE_METADATA_SIGNATURE {

	DWORD dwEfsAccessType;
	PENCRYPTION_CERTIFICATE_HASH_LIST pCertificatesAdded;
    PENCRYPTION_CERTIFICATE pEncryptionCertificate;
    PEFS_RPC_BLOB pEfsStreamSignature;

} ENCRYPTED_FILE_METADATA_SIGNATURE, *PENCRYPTED_FILE_METADATA_SIGNATURE;
__declspec(dllimport)
DWORD

QueryUsersOnEncryptedFile(
     LPCWSTR lpFileName,
     PENCRYPTION_CERTIFICATE_HASH_LIST *pUsers
    );


__declspec(dllimport)
DWORD

QueryRecoveryAgentsOnEncryptedFile(
     LPCWSTR lpFileName,
     PENCRYPTION_CERTIFICATE_HASH_LIST *pRecoveryAgents
    );


__declspec(dllimport)
DWORD

RemoveUsersFromEncryptedFile(
     LPCWSTR lpFileName,
     PENCRYPTION_CERTIFICATE_HASH_LIST pHashes
    );

__declspec(dllimport)
DWORD

AddUsersToEncryptedFile(
     LPCWSTR lpFileName,
     PENCRYPTION_CERTIFICATE_LIST pEncryptionCertificates
    );

__declspec(dllimport)
DWORD

SetUserFileEncryptionKey(
     PENCRYPTION_CERTIFICATE pEncryptionCertificate
    );




__declspec(dllimport)
DWORD

SetUserFileEncryptionKeyEx(
     PENCRYPTION_CERTIFICATE pEncryptionCertificate,
                    DWORD dwCapabilities,
                    DWORD dwFlags,
     LPVOID pvReserved
    );



__declspec(dllimport)
void

FreeEncryptionCertificateHashList(
     PENCRYPTION_CERTIFICATE_HASH_LIST pUsers
    );

__declspec(dllimport)
BOOL

EncryptionDisable(
     LPCWSTR DirPath,
         BOOL Disable
    );







__declspec(dllimport)
DWORD

DuplicateEncryptionInfoFile(
      LPCWSTR SrcFileName,
      LPCWSTR DstFileName,
                DWORD dwCreationDistribution,
                DWORD dwAttributes,
       const  LPSECURITY_ATTRIBUTES lpSecurityAttributes
     );
__declspec(dllimport)
DWORD

GetEncryptedFileMetadata(
     LPCWSTR lpFileName,
     PDWORD pcbMetadata,
     PBYTE *ppbMetadata
    );

__declspec(dllimport)
DWORD

SetEncryptedFileMetadata(
     LPCWSTR lpFileName,
     PBYTE pbOldMetadata,
     PBYTE pbNewMetadata,
     PENCRYPTION_CERTIFICATE_HASH pOwnerHash,
                DWORD dwOperation,
     PENCRYPTION_CERTIFICATE_HASH_LIST pCertificatesAdded
    );

__declspec(dllimport)
void

FreeEncryptedFileMetadata(
     PBYTE pbMetadata
    );
typedef struct
{
   RPC_NS_HANDLE LookupContext;
   RPC_BINDING_HANDLE ProposedHandle;
   RPC_BINDING_VECTOR * Bindings;

} RPC_IMPORT_CONTEXT_P, * PRPC_IMPORT_CONTEXT_P;




__declspec(dllimport)
RPC_STATUS

I_RpcNsGetBuffer(
     PRPC_MESSAGE Message
    );

__declspec(dllimport)
RPC_STATUS

I_RpcNsSendReceive(
     PRPC_MESSAGE Message,
     RPC_BINDING_HANDLE   * Handle
    );

__declspec(dllimport)
void

I_RpcNsRaiseException(
     PRPC_MESSAGE Message,
     RPC_STATUS Status
    );

__declspec(dllimport)
RPC_STATUS

I_RpcReBindBuffer(
     PRPC_MESSAGE Message
    );

__declspec(dllimport)
RPC_STATUS

I_NsServerBindSearch(
    void
    );

__declspec(dllimport)
RPC_STATUS

I_NsClientBindSearch(
    void
    );

__declspec(dllimport)
void

I_NsClientBindDone(
    void
    );
typedef unsigned char byte;
typedef byte cs_byte;
typedef unsigned char boolean;








typedef double hyper;
typedef double MIDL_uhyper;


void *   MIDL_user_allocate(size_t size);
void   MIDL_user_free(      void * );



void *   I_RpcDefaultAllocate(
         handle_t bh, size_t size, void * (* RealAlloc)(size_t) );

void   I_RpcDefaultFree(
         handle_t bh, void *, void (*RealFree)(void *) );
typedef void * NDR_CCONTEXT;

typedef struct
    {
    void * pad[2];
    void * userContext;
    } * NDR_SCONTEXT;





typedef void (  * NDR_RUNDOWN)(void * context);

typedef void (  * NDR_NOTIFY_ROUTINE)(void);
typedef void (  * NDR_NOTIFY2_ROUTINE)(boolean flag);

typedef struct _SCONTEXT_QUEUE {
    unsigned long NumberOfObjects;
    NDR_SCONTEXT * ArrayOfObjects;
    } SCONTEXT_QUEUE, * PSCONTEXT_QUEUE;

__declspec(dllimport)
RPC_BINDING_HANDLE

NDRCContextBinding (
     NDR_CCONTEXT CContext
    );

__declspec(dllimport)
void

NDRCContextMarshall (
     NDR_CCONTEXT CContext,
     void *pBuff
    );

__declspec(dllimport)
void

NDRCContextUnmarshall (
     NDR_CCONTEXT * pCContext,
     RPC_BINDING_HANDLE hBinding,
     void * pBuff,
     unsigned long DataRepresentation
    );

__declspec(dllimport)
void

NDRCContextUnmarshall2 (
     NDR_CCONTEXT * pCContext,
     RPC_BINDING_HANDLE hBinding,
     void * pBuff,
     unsigned long DataRepresentation
    );

__declspec(dllimport)
void

NDRSContextMarshall (
     NDR_SCONTEXT CContext,
     void * pBuff,
     NDR_RUNDOWN userRunDownIn
    );

__declspec(dllimport)
NDR_SCONTEXT

NDRSContextUnmarshall (
     void * pBuff,
     unsigned long DataRepresentation
    );

__declspec(dllimport)
void

NDRSContextMarshallEx (
     RPC_BINDING_HANDLE BindingHandle,
     NDR_SCONTEXT CContext,
     void * pBuff,
     NDR_RUNDOWN userRunDownIn
    );

__declspec(dllimport)
void

NDRSContextMarshall2 (
     RPC_BINDING_HANDLE BindingHandle,
     NDR_SCONTEXT CContext,
     void * pBuff,
     NDR_RUNDOWN userRunDownIn,
     void * CtxGuard,
     unsigned long Flags
    );

__declspec(dllimport)
NDR_SCONTEXT

NDRSContextUnmarshallEx (
     RPC_BINDING_HANDLE BindingHandle,
     void * pBuff,
     unsigned long DataRepresentation
    );

__declspec(dllimport)
NDR_SCONTEXT

NDRSContextUnmarshall2(
     RPC_BINDING_HANDLE BindingHandle,
     void * pBuff,
     unsigned long DataRepresentation,
     void * CtxGuard,
     unsigned long Flags
    );

__declspec(dllimport)
void

RpcSsDestroyClientContext (
     void * * ContextHandle
    );
typedef unsigned long error_status_t;
struct _MIDL_STUB_MESSAGE;
struct _MIDL_STUB_DESC;
struct _FULL_PTR_XLAT_TABLES;

typedef unsigned char * RPC_BUFPTR;
typedef unsigned long RPC_LENGTH;


typedef void (  * EXPR_EVAL)( struct _MIDL_STUB_MESSAGE * );

typedef const unsigned char * PFORMAT_STRING;
typedef struct
    {
    long Dimension;


    unsigned long * BufferConformanceMark;
    unsigned long * BufferVarianceMark;


    unsigned long * MaxCountArray;
    unsigned long * OffsetArray;
    unsigned long * ActualCountArray;
    } ARRAY_INFO, *PARRAY_INFO;


typedef struct _NDR_ASYNC_MESSAGE * PNDR_ASYNC_MESSAGE;
typedef struct _NDR_CORRELATION_INFO *PNDR_CORRELATION_INFO;
typedef const unsigned char * PFORMAT_STRING;
typedef struct _MIDL_SYNTAX_INFO MIDL_SYNTAX_INFO, *PMIDL_SYNTAX_INFO;

struct NDR_ALLOC_ALL_NODES_CONTEXT;
struct NDR_POINTER_QUEUE_STATE;
struct _NDR_PROC_CONTEXT;

typedef struct _MIDL_STUB_MESSAGE
    {

    PRPC_MESSAGE RpcMsg;


    unsigned char * Buffer;
    unsigned char * BufferStart;
    unsigned char * BufferEnd;
    unsigned char * BufferMark;


    unsigned long BufferLength;


    unsigned long MemorySize;


    unsigned char * Memory;


    unsigned char IsClient;
    unsigned char Pad;
    unsigned short uFlags2;


    int ReuseBuffer;


    struct NDR_ALLOC_ALL_NODES_CONTEXT *pAllocAllNodesContext;
    struct NDR_POINTER_QUEUE_STATE *pPointerQueueState;
    int IgnoreEmbeddedPointers;
    unsigned char * PointerBufferMark;
    unsigned char CorrDespIncrement;

    unsigned char uFlags;
    unsigned short UniquePtrCount;
    ULONG_PTR MaxCount;
    unsigned long Offset;
    unsigned long ActualCount;


    void * (   * pfnAllocate)( size_t );
    void (   * pfnFree)(void *);
    unsigned char * StackTop;
    unsigned char * pPresentedType;
    unsigned char * pTransmitType;
    handle_t SavedHandle;
    const struct _MIDL_STUB_DESC * StubDesc;
    struct _FULL_PTR_XLAT_TABLES * FullPtrXlatTables;
    unsigned long FullPtrRefId;

    unsigned long PointerLength;

    int fInDontFree :1;
    int fDontCallFreeInst :1;
    int fInOnlyParam :1;
    int fHasReturn :1;
    int fHasExtensions :1;
    int fHasNewCorrDesc :1;
    int fIsIn :1;
    int fIsOut :1;
    int fIsOicf :1;
    int fBufferValid :1;
    int fHasMemoryValidateCallback: 1;
    int fInFree :1;
    int fNeedMCCP :1;
    int fUnused :3;
    int fUnused2 :16;


    unsigned long dwDestContext;
    void * pvDestContext;

    NDR_SCONTEXT * SavedContextHandles;

    long ParamNumber;

    struct IRpcChannelBuffer * pRpcChannelBuffer;

    PARRAY_INFO pArrayInfo;
    unsigned long * SizePtrCountArray;
    unsigned long * SizePtrOffsetArray;
    unsigned long * SizePtrLengthArray;
    void * pArgQueue;

    unsigned long dwStubPhase;

    void * LowStackMark;
    PNDR_ASYNC_MESSAGE pAsyncMsg;
    PNDR_CORRELATION_INFO pCorrInfo;
    unsigned char * pCorrMemory;

    void * pMemoryList;
    INT_PTR pCSInfo;

    unsigned char * ConformanceMark;
    unsigned char * VarianceMark;




    INT_PTR Unused;


    struct _NDR_PROC_CONTEXT * pContext;
    void * ContextHandleHash;
    void * pUserMarshalList;
    INT_PTR Reserved51_3;
    INT_PTR Reserved51_4;
    INT_PTR Reserved51_5;
    } MIDL_STUB_MESSAGE, *PMIDL_STUB_MESSAGE;


typedef struct _MIDL_STUB_MESSAGE MIDL_STUB_MESSAGE, *PMIDL_STUB_MESSAGE;
typedef void *
        (   * GENERIC_BINDING_ROUTINE)
        (void *);
typedef void
        (   * GENERIC_UNBIND_ROUTINE)
        (void *, unsigned char *);

typedef struct _GENERIC_BINDING_ROUTINE_PAIR
    {
    GENERIC_BINDING_ROUTINE pfnBind;
    GENERIC_UNBIND_ROUTINE pfnUnbind;
    } GENERIC_BINDING_ROUTINE_PAIR, *PGENERIC_BINDING_ROUTINE_PAIR;

typedef struct __GENERIC_BINDING_INFO
    {
    void * pObj;
    unsigned int Size;
    GENERIC_BINDING_ROUTINE pfnBind;
    GENERIC_UNBIND_ROUTINE pfnUnbind;
    } GENERIC_BINDING_INFO, *PGENERIC_BINDING_INFO;
typedef void (   * XMIT_HELPER_ROUTINE)
    ( PMIDL_STUB_MESSAGE );

typedef struct _XMIT_ROUTINE_QUINTUPLE
    {
    XMIT_HELPER_ROUTINE pfnTranslateToXmit;
    XMIT_HELPER_ROUTINE pfnTranslateFromXmit;
    XMIT_HELPER_ROUTINE pfnFreeXmit;
    XMIT_HELPER_ROUTINE pfnFreeInst;
    } XMIT_ROUTINE_QUINTUPLE, *PXMIT_ROUTINE_QUINTUPLE;

typedef unsigned long
(   * USER_MARSHAL_SIZING_ROUTINE)
    (unsigned long *,
     unsigned long,
     void * );

typedef unsigned char *
(   * USER_MARSHAL_MARSHALLING_ROUTINE)
    (unsigned long *,
     unsigned char * ,
     void * );

typedef unsigned char *
(   * USER_MARSHAL_UNMARSHALLING_ROUTINE)
    (unsigned long *,
     unsigned char *,
     void * );

typedef void (   * USER_MARSHAL_FREEING_ROUTINE)
    (unsigned long *,
     void * );

typedef struct _USER_MARSHAL_ROUTINE_QUADRUPLE
    {
    USER_MARSHAL_SIZING_ROUTINE pfnBufferSize;
    USER_MARSHAL_MARSHALLING_ROUTINE pfnMarshall;
    USER_MARSHAL_UNMARSHALLING_ROUTINE pfnUnmarshall;
    USER_MARSHAL_FREEING_ROUTINE pfnFree;
    } USER_MARSHAL_ROUTINE_QUADRUPLE;



typedef enum _USER_MARSHAL_CB_TYPE
{
    USER_MARSHAL_CB_BUFFER_SIZE,
    USER_MARSHAL_CB_MARSHALL,
    USER_MARSHAL_CB_UNMARSHALL,
    USER_MARSHAL_CB_FREE
} USER_MARSHAL_CB_TYPE;

typedef struct _USER_MARSHAL_CB
{
    unsigned long Flags;
    PMIDL_STUB_MESSAGE pStubMsg;
    PFORMAT_STRING pReserve;
    unsigned long Signature;
    USER_MARSHAL_CB_TYPE CBType;
    PFORMAT_STRING pFormat;
    PFORMAT_STRING pTypeFormat;
} USER_MARSHAL_CB;









typedef struct _MALLOC_FREE_STRUCT
    {
    void * (   * pfnAllocate)(size_t);
    void (   * pfnFree)(void *);
    } MALLOC_FREE_STRUCT;

typedef struct _COMM_FAULT_OFFSETS
    {
    short CommOffset;
    short FaultOffset;
    } COMM_FAULT_OFFSETS;
typedef enum _IDL_CS_CONVERT
    {
    IDL_CS_NO_CONVERT,
    IDL_CS_IN_PLACE_CONVERT,
    IDL_CS_NEW_BUFFER_CONVERT
    } IDL_CS_CONVERT;

typedef void
(   * CS_TYPE_NET_SIZE_ROUTINE)
    (RPC_BINDING_HANDLE hBinding,
     unsigned long ulNetworkCodeSet,
     unsigned long ulLocalBufferSize,
     IDL_CS_CONVERT * conversionType,
     unsigned long * pulNetworkBufferSize,
     error_status_t * pStatus);

typedef void
(   * CS_TYPE_LOCAL_SIZE_ROUTINE)
    (RPC_BINDING_HANDLE hBinding,
     unsigned long ulNetworkCodeSet,
     unsigned long ulNetworkBufferSize,
     IDL_CS_CONVERT * conversionType,
     unsigned long * pulLocalBufferSize,
     error_status_t * pStatus);

typedef void
(   * CS_TYPE_TO_NETCS_ROUTINE)
    (RPC_BINDING_HANDLE hBinding,
     unsigned long ulNetworkCodeSet,
     void * pLocalData,
     unsigned long ulLocalDataLength,
     byte * pNetworkData,
     unsigned long * pulNetworkDataLength,
     error_status_t * pStatus);

typedef void
(   * CS_TYPE_FROM_NETCS_ROUTINE)
    (RPC_BINDING_HANDLE hBinding,
     unsigned long ulNetworkCodeSet,
     byte * pNetworkData,
     unsigned long ulNetworkDataLength,
     unsigned long ulLocalBufferSize,
     void * pLocalData,
     unsigned long * pulLocalDataLength,
     error_status_t * pStatus);

typedef void
(   * CS_TAG_GETTING_ROUTINE)
    (RPC_BINDING_HANDLE hBinding,
     int fServerSide,
     unsigned long * pulSendingTag,
     unsigned long * pulDesiredReceivingTag,
     unsigned long * pulReceivingTag,
     error_status_t * pStatus);

void
RpcCsGetTags(
     RPC_BINDING_HANDLE hBinding,
     int fServerSide,
     unsigned long * pulSendingTag,
     unsigned long * pulDesiredReceivingTag,
     unsigned long * pulReceivingTag,
     error_status_t * pStatus);

typedef struct _NDR_CS_SIZE_CONVERT_ROUTINES
    {
    CS_TYPE_NET_SIZE_ROUTINE pfnNetSize;
    CS_TYPE_TO_NETCS_ROUTINE pfnToNetCs;
    CS_TYPE_LOCAL_SIZE_ROUTINE pfnLocalSize;
    CS_TYPE_FROM_NETCS_ROUTINE pfnFromNetCs;
    } NDR_CS_SIZE_CONVERT_ROUTINES;

typedef struct _NDR_CS_ROUTINES
    {
    NDR_CS_SIZE_CONVERT_ROUTINES *pSizeConvertRoutines;
    CS_TAG_GETTING_ROUTINE *pTagGettingRoutines;
    } NDR_CS_ROUTINES;

typedef struct _NDR_EXPR_DESC
{
    const unsigned short * pOffset;
    PFORMAT_STRING pFormatExpr;
} NDR_EXPR_DESC;
typedef struct _MIDL_STUB_DESC
    {
    void * RpcInterfaceInformation;

    void * (   * pfnAllocate)(size_t);
    void (   * pfnFree)(void *);

    union
        {
        handle_t * pAutoHandle;
        handle_t * pPrimitiveHandle;
        PGENERIC_BINDING_INFO pGenericBindingInfo;
        } IMPLICIT_HANDLE_INFO;

    const NDR_RUNDOWN * apfnNdrRundownRoutines;
    const GENERIC_BINDING_ROUTINE_PAIR * aGenericBindingRoutinePairs;
    const EXPR_EVAL * apfnExprEval;
    const XMIT_ROUTINE_QUINTUPLE * aXmitQuintuple;

    const unsigned char * pFormatTypes;

    int fCheckBounds;


    unsigned long Version;

    MALLOC_FREE_STRUCT * pMallocFreeStruct;

    long MIDLVersion;

    const COMM_FAULT_OFFSETS * CommFaultOffsets;


    const USER_MARSHAL_ROUTINE_QUADRUPLE * aUserMarshalQuadruple;


    const NDR_NOTIFY_ROUTINE * NotifyRoutineTable;
    ULONG_PTR mFlags;


    const NDR_CS_ROUTINES * CsRoutineTables;

    void * ProxyServerInfo;
    const NDR_EXPR_DESC * pExprInfo;



    } MIDL_STUB_DESC;


typedef const MIDL_STUB_DESC * PMIDL_STUB_DESC;

typedef void * PMIDL_XMIT_TYPE;
typedef void (   * STUB_THUNK)( PMIDL_STUB_MESSAGE );


typedef long (   * SERVER_ROUTINE)();
typedef struct _MIDL_SERVER_INFO_
    {
    PMIDL_STUB_DESC pStubDesc;
    const SERVER_ROUTINE * DispatchTable;
    PFORMAT_STRING ProcString;
    const unsigned short * FmtStringOffset;
    const STUB_THUNK * ThunkTable;
    PRPC_SYNTAX_IDENTIFIER pTransferSyntax;
    ULONG_PTR nCount;
    PMIDL_SYNTAX_INFO pSyntaxInfo;
    } MIDL_SERVER_INFO, *PMIDL_SERVER_INFO;
typedef struct _MIDL_STUBLESS_PROXY_INFO
    {
    PMIDL_STUB_DESC pStubDesc;
    PFORMAT_STRING ProcFormatString;
    const unsigned short * FormatStringOffset;
    PRPC_SYNTAX_IDENTIFIER pTransferSyntax;
    ULONG_PTR nCount;
    PMIDL_SYNTAX_INFO pSyntaxInfo;
    } MIDL_STUBLESS_PROXY_INFO;

typedef MIDL_STUBLESS_PROXY_INFO * PMIDL_STUBLESS_PROXY_INFO;
typedef struct _MIDL_SYNTAX_INFO
{
RPC_SYNTAX_IDENTIFIER TransferSyntax;
RPC_DISPATCH_TABLE * DispatchTable;
PFORMAT_STRING ProcString;
const unsigned short * FmtStringOffset;
PFORMAT_STRING TypeString;
const void * aUserMarshalQuadruple;
ULONG_PTR pReserved1;
ULONG_PTR pReserved2;
} MIDL_SYNTAX_INFO, *PMIDL_SYNTAX_INFO;

typedef unsigned short * PARAM_OFFSETTABLE, *PPARAM_OFFSETTABLE;
typedef union _CLIENT_CALL_RETURN
    {
    void * Pointer;
    LONG_PTR Simple;
    } CLIENT_CALL_RETURN;


typedef enum
        {
        XLAT_SERVER = 1,
        XLAT_CLIENT
        } XLAT_SIDE;

typedef struct _FULL_PTR_XLAT_TABLES
{
    void * RefIdToPointer;
    void * PointerToRefId;
    unsigned long NextRefId;
    XLAT_SIDE XlatSide;
} FULL_PTR_XLAT_TABLES, *PFULL_PTR_XLAT_TABLES;
RPC_STATUS
NdrClientGetSupportedSyntaxes(
     RPC_CLIENT_INTERFACE * pInf,
     unsigned long * pCount,
     MIDL_SYNTAX_INFO ** pArr );


RPC_STATUS
NdrServerGetSupportedSyntaxes(
     RPC_SERVER_INTERFACE * pInf,
     unsigned long * pCount,
     MIDL_SYNTAX_INFO ** pArr,
     unsigned long * pPreferSyntaxIndex);
__declspec(dllimport)
void

NdrSimpleTypeMarshall(
    PMIDL_STUB_MESSAGE pStubMsg,
    unsigned char * pMemory,
    unsigned char FormatChar
    );

__declspec(dllimport)
unsigned char *

NdrPointerMarshall(
    PMIDL_STUB_MESSAGE pStubMsg,
    unsigned char * pMemory,
    PFORMAT_STRING pFormat
    );

__declspec(dllimport)
unsigned char *

NdrCsArrayMarshall(
    PMIDL_STUB_MESSAGE pStubMsg,
    unsigned char * pMemory,
    PFORMAT_STRING pFormat
    );

__declspec(dllimport)
unsigned char *

NdrCsTagMarshall(
    PMIDL_STUB_MESSAGE pStubMsg,
    unsigned char * pMemory,
    PFORMAT_STRING pFormat
    );



__declspec(dllimport)
unsigned char *

NdrSimpleStructMarshall(
    PMIDL_STUB_MESSAGE pStubMsg,
    unsigned char * pMemory,
    PFORMAT_STRING pFormat
    );

__declspec(dllimport)
unsigned char *

NdrConformantStructMarshall(
    PMIDL_STUB_MESSAGE pStubMsg,
    unsigned char * pMemory,
    PFORMAT_STRING pFormat
    );

__declspec(dllimport)
unsigned char *

NdrConformantVaryingStructMarshall(
    PMIDL_STUB_MESSAGE pStubMsg,
    unsigned char * pMemory,
    PFORMAT_STRING pFormat
    );

__declspec(dllimport)
unsigned char *

NdrComplexStructMarshall(
    PMIDL_STUB_MESSAGE pStubMsg,
    unsigned char * pMemory,
    PFORMAT_STRING pFormat
    );



__declspec(dllimport)
unsigned char *

NdrFixedArrayMarshall(
    PMIDL_STUB_MESSAGE pStubMsg,
    unsigned char * pMemory,
    PFORMAT_STRING pFormat
    );

__declspec(dllimport)
unsigned char *

NdrConformantArrayMarshall(
    PMIDL_STUB_MESSAGE pStubMsg,
    unsigned char * pMemory,
    PFORMAT_STRING pFormat
    );

__declspec(dllimport)
unsigned char *

NdrConformantVaryingArrayMarshall(
    PMIDL_STUB_MESSAGE pStubMsg,
    unsigned char * pMemory,
    PFORMAT_STRING pFormat
    );

__declspec(dllimport)
unsigned char *

NdrVaryingArrayMarshall(
    PMIDL_STUB_MESSAGE pStubMsg,
    unsigned char * pMemory,
    PFORMAT_STRING pFormat
    );

__declspec(dllimport)
unsigned char *

NdrComplexArrayMarshall(
    PMIDL_STUB_MESSAGE pStubMsg,
    unsigned char * pMemory,
    PFORMAT_STRING pFormat
    );



__declspec(dllimport)
unsigned char *

NdrNonConformantStringMarshall(
    PMIDL_STUB_MESSAGE pStubMsg,
    unsigned char * pMemory,
    PFORMAT_STRING pFormat
    );

__declspec(dllimport)
unsigned char *

NdrConformantStringMarshall(
    PMIDL_STUB_MESSAGE pStubMsg,
    unsigned char * pMemory,
    PFORMAT_STRING pFormat
    );



__declspec(dllimport)
unsigned char *

NdrEncapsulatedUnionMarshall(
    PMIDL_STUB_MESSAGE pStubMsg,
    unsigned char * pMemory,
    PFORMAT_STRING pFormat
    );

__declspec(dllimport)
unsigned char *

NdrNonEncapsulatedUnionMarshall(
    PMIDL_STUB_MESSAGE pStubMsg,
    unsigned char * pMemory,
    PFORMAT_STRING pFormat
    );



__declspec(dllimport)
unsigned char *

NdrByteCountPointerMarshall(
    PMIDL_STUB_MESSAGE pStubMsg,
    unsigned char * pMemory,
    PFORMAT_STRING pFormat
    );



__declspec(dllimport)
unsigned char *

NdrXmitOrRepAsMarshall(
    PMIDL_STUB_MESSAGE pStubMsg,
    unsigned char * pMemory,
    PFORMAT_STRING pFormat
    );



__declspec(dllimport)
unsigned char *

NdrUserMarshalMarshall(
    PMIDL_STUB_MESSAGE pStubMsg,
    unsigned char * pMemory,
    PFORMAT_STRING pFormat
    );



__declspec(dllimport)
unsigned char *

NdrInterfacePointerMarshall(
    PMIDL_STUB_MESSAGE pStubMsg,
    unsigned char * pMemory,
    PFORMAT_STRING pFormat
    );



__declspec(dllimport)
void

NdrClientContextMarshall(
    PMIDL_STUB_MESSAGE pStubMsg,
    NDR_CCONTEXT ContextHandle,
    int fCheck
    );

__declspec(dllimport)
void

NdrServerContextMarshall(
    PMIDL_STUB_MESSAGE pStubMsg,
    NDR_SCONTEXT ContextHandle,
    NDR_RUNDOWN RundownRoutine
    );

__declspec(dllimport)
void

NdrServerContextNewMarshall(
    PMIDL_STUB_MESSAGE pStubMsg,
    NDR_SCONTEXT ContextHandle,
    NDR_RUNDOWN RundownRoutine,
    PFORMAT_STRING pFormat
    );
__declspec(dllimport)
void

NdrSimpleTypeUnmarshall(
    PMIDL_STUB_MESSAGE pStubMsg,
    unsigned char * pMemory,
    unsigned char FormatChar
    );

__declspec(dllimport)
unsigned char *

NdrCsArrayUnmarshall(
    PMIDL_STUB_MESSAGE pStubMsg,
    unsigned char ** ppMemory,
    PFORMAT_STRING pFormat,
    unsigned char fMustAlloc
    );

__declspec(dllimport)
unsigned char *

NdrCsTagUnmarshall(
    PMIDL_STUB_MESSAGE pStubMsg,
    unsigned char ** ppMemory,
    PFORMAT_STRING pFormat,
    unsigned char fMustAlloc
    );

__declspec(dllimport)
unsigned char *
NdrRangeUnmarshall(
    PMIDL_STUB_MESSAGE pStubMsg,
    unsigned char ** ppMemory,
    PFORMAT_STRING pFormat,
    unsigned char fMustAlloc
    );

__declspec(dllimport)
void

NdrCorrelationInitialize(
    PMIDL_STUB_MESSAGE pStubMsg,
    void * pMemory,
    unsigned long CacheSize,
    unsigned long flags
    );

__declspec(dllimport)
void

NdrCorrelationPass(
    PMIDL_STUB_MESSAGE pStubMsg
    );

__declspec(dllimport)
void

NdrCorrelationFree(
    PMIDL_STUB_MESSAGE pStubMsg
    );

__declspec(dllimport)
unsigned char *

NdrPointerUnmarshall(
    PMIDL_STUB_MESSAGE pStubMsg,
    unsigned char * * ppMemory,
    PFORMAT_STRING pFormat,
    unsigned char fMustAlloc
    );



__declspec(dllimport)
unsigned char *

NdrSimpleStructUnmarshall(
    PMIDL_STUB_MESSAGE pStubMsg,
    unsigned char * * ppMemory,
    PFORMAT_STRING pFormat,
    unsigned char fMustAlloc
    );

__declspec(dllimport)
unsigned char *

NdrConformantStructUnmarshall(
    PMIDL_STUB_MESSAGE pStubMsg,
    unsigned char * * ppMemory,
    PFORMAT_STRING pFormat,
    unsigned char fMustAlloc
    );

__declspec(dllimport)
unsigned char *

NdrConformantVaryingStructUnmarshall(
    PMIDL_STUB_MESSAGE pStubMsg,
    unsigned char * * ppMemory,
    PFORMAT_STRING pFormat,
    unsigned char fMustAlloc
    );

__declspec(dllimport)
unsigned char *

NdrComplexStructUnmarshall(
    PMIDL_STUB_MESSAGE pStubMsg,
    unsigned char * * ppMemory,
    PFORMAT_STRING pFormat,
    unsigned char fMustAlloc
    );



__declspec(dllimport)
unsigned char *

NdrFixedArrayUnmarshall(
    PMIDL_STUB_MESSAGE pStubMsg,
    unsigned char * * ppMemory,
    PFORMAT_STRING pFormat,
    unsigned char fMustAlloc
    );

__declspec(dllimport)
unsigned char *

NdrConformantArrayUnmarshall(
    PMIDL_STUB_MESSAGE pStubMsg,
    unsigned char * * ppMemory,
    PFORMAT_STRING pFormat,
    unsigned char fMustAlloc
    );

__declspec(dllimport)
unsigned char *

NdrConformantVaryingArrayUnmarshall(
    PMIDL_STUB_MESSAGE pStubMsg,
    unsigned char * * ppMemory,
    PFORMAT_STRING pFormat,
    unsigned char fMustAlloc
    );

__declspec(dllimport)
unsigned char *

NdrVaryingArrayUnmarshall(
    PMIDL_STUB_MESSAGE pStubMsg,
    unsigned char * * ppMemory,
    PFORMAT_STRING pFormat,
    unsigned char fMustAlloc
    );

__declspec(dllimport)
unsigned char *

NdrComplexArrayUnmarshall(
    PMIDL_STUB_MESSAGE pStubMsg,
    unsigned char * * ppMemory,
    PFORMAT_STRING pFormat,
    unsigned char fMustAlloc
    );



__declspec(dllimport)
unsigned char *

NdrNonConformantStringUnmarshall(
    PMIDL_STUB_MESSAGE pStubMsg,
    unsigned char * * ppMemory,
    PFORMAT_STRING pFormat,
    unsigned char fMustAlloc
    );

__declspec(dllimport)
unsigned char *

NdrConformantStringUnmarshall(
    PMIDL_STUB_MESSAGE pStubMsg,
    unsigned char * * ppMemory,
    PFORMAT_STRING pFormat,
    unsigned char fMustAlloc
    );



__declspec(dllimport)
unsigned char *

NdrEncapsulatedUnionUnmarshall(
    PMIDL_STUB_MESSAGE pStubMsg,
    unsigned char * * ppMemory,
    PFORMAT_STRING pFormat,
    unsigned char fMustAlloc
    );

__declspec(dllimport)
unsigned char *

NdrNonEncapsulatedUnionUnmarshall(
    PMIDL_STUB_MESSAGE pStubMsg,
    unsigned char * * ppMemory,
    PFORMAT_STRING pFormat,
    unsigned char fMustAlloc
    );



__declspec(dllimport)
unsigned char *

NdrByteCountPointerUnmarshall(
    PMIDL_STUB_MESSAGE pStubMsg,
    unsigned char * * ppMemory,
    PFORMAT_STRING pFormat,
    unsigned char fMustAlloc
    );



__declspec(dllimport)
unsigned char *

NdrXmitOrRepAsUnmarshall(
    PMIDL_STUB_MESSAGE pStubMsg,
    unsigned char * * ppMemory,
    PFORMAT_STRING pFormat,
    unsigned char fMustAlloc
    );



__declspec(dllimport)
unsigned char *

NdrUserMarshalUnmarshall(
    PMIDL_STUB_MESSAGE pStubMsg,
    unsigned char * * ppMemory,
    PFORMAT_STRING pFormat,
    unsigned char fMustAlloc
    );



__declspec(dllimport)
unsigned char *

NdrInterfacePointerUnmarshall(
    PMIDL_STUB_MESSAGE pStubMsg,
    unsigned char * * ppMemory,
    PFORMAT_STRING pFormat,
    unsigned char fMustAlloc
    );



__declspec(dllimport)
void

NdrClientContextUnmarshall(
    PMIDL_STUB_MESSAGE pStubMsg,
    NDR_CCONTEXT * pContextHandle,
    RPC_BINDING_HANDLE BindHandle
    );

__declspec(dllimport)
NDR_SCONTEXT

NdrServerContextUnmarshall(
    PMIDL_STUB_MESSAGE pStubMsg
    );



__declspec(dllimport)
NDR_SCONTEXT

NdrContextHandleInitialize(
     PMIDL_STUB_MESSAGE pStubMsg,
     PFORMAT_STRING pFormat
    );

__declspec(dllimport)
NDR_SCONTEXT

NdrServerContextNewUnmarshall(
     PMIDL_STUB_MESSAGE pStubMsg,
     PFORMAT_STRING pFormat
    );
__declspec(dllimport)
void

NdrPointerBufferSize(
    PMIDL_STUB_MESSAGE pStubMsg,
    unsigned char * pMemory,
    PFORMAT_STRING pFormat
    );

__declspec(dllimport)
void

NdrCsArrayBufferSize(
    PMIDL_STUB_MESSAGE pStubMsg,
    unsigned char * pMemory,
    PFORMAT_STRING pFormat
    );

__declspec(dllimport)
void

NdrCsTagBufferSize(
    PMIDL_STUB_MESSAGE pStubMsg,
    unsigned char * pMemory,
    PFORMAT_STRING pFormat
    );



__declspec(dllimport)
void

NdrSimpleStructBufferSize(
    PMIDL_STUB_MESSAGE pStubMsg,
    unsigned char * pMemory,
    PFORMAT_STRING pFormat
    );

__declspec(dllimport)
void

NdrConformantStructBufferSize(
    PMIDL_STUB_MESSAGE pStubMsg,
    unsigned char * pMemory,
    PFORMAT_STRING pFormat
    );

__declspec(dllimport)
void

NdrConformantVaryingStructBufferSize(
    PMIDL_STUB_MESSAGE pStubMsg,
    unsigned char * pMemory,
    PFORMAT_STRING pFormat
    );

__declspec(dllimport)
void

NdrComplexStructBufferSize(
    PMIDL_STUB_MESSAGE pStubMsg,
    unsigned char * pMemory,
    PFORMAT_STRING pFormat
    );



__declspec(dllimport)
void

NdrFixedArrayBufferSize(
    PMIDL_STUB_MESSAGE pStubMsg,
    unsigned char * pMemory,
    PFORMAT_STRING pFormat
    );

__declspec(dllimport)
void

NdrConformantArrayBufferSize(
    PMIDL_STUB_MESSAGE pStubMsg,
    unsigned char * pMemory,
    PFORMAT_STRING pFormat
    );

__declspec(dllimport)
void

NdrConformantVaryingArrayBufferSize(
    PMIDL_STUB_MESSAGE pStubMsg,
    unsigned char * pMemory,
    PFORMAT_STRING pFormat
    );

__declspec(dllimport)
void

NdrVaryingArrayBufferSize(
    PMIDL_STUB_MESSAGE pStubMsg,
    unsigned char * pMemory,
    PFORMAT_STRING pFormat
    );

__declspec(dllimport)
void

NdrComplexArrayBufferSize(
    PMIDL_STUB_MESSAGE pStubMsg,
    unsigned char * pMemory,
    PFORMAT_STRING pFormat
    );



__declspec(dllimport)
void

NdrConformantStringBufferSize(
    PMIDL_STUB_MESSAGE pStubMsg,
    unsigned char * pMemory,
    PFORMAT_STRING pFormat
    );

__declspec(dllimport)
void

NdrNonConformantStringBufferSize(
    PMIDL_STUB_MESSAGE pStubMsg,
    unsigned char * pMemory,
    PFORMAT_STRING pFormat
    );



__declspec(dllimport)
void

NdrEncapsulatedUnionBufferSize(
    PMIDL_STUB_MESSAGE pStubMsg,
    unsigned char * pMemory,
    PFORMAT_STRING pFormat
    );

__declspec(dllimport)
void

NdrNonEncapsulatedUnionBufferSize(
    PMIDL_STUB_MESSAGE pStubMsg,
    unsigned char * pMemory,
    PFORMAT_STRING pFormat
    );



__declspec(dllimport)
void

NdrByteCountPointerBufferSize(
    PMIDL_STUB_MESSAGE pStubMsg,
    unsigned char * pMemory,
    PFORMAT_STRING pFormat
    );



__declspec(dllimport)
void

NdrXmitOrRepAsBufferSize(
    PMIDL_STUB_MESSAGE pStubMsg,
    unsigned char * pMemory,
    PFORMAT_STRING pFormat
    );



__declspec(dllimport)
void

NdrUserMarshalBufferSize(
    PMIDL_STUB_MESSAGE pStubMsg,
    unsigned char * pMemory,
    PFORMAT_STRING pFormat
    );



__declspec(dllimport)
void

NdrInterfacePointerBufferSize(
    PMIDL_STUB_MESSAGE pStubMsg,
    unsigned char * pMemory,
    PFORMAT_STRING pFormat
    );



__declspec(dllimport)
void

NdrContextHandleSize(
    PMIDL_STUB_MESSAGE pStubMsg,
    unsigned char * pMemory,
    PFORMAT_STRING pFormat
    );
__declspec(dllimport)
unsigned long

NdrPointerMemorySize(
    PMIDL_STUB_MESSAGE pStubMsg,
    PFORMAT_STRING pFormat
    );

__declspec(dllimport)
unsigned long

NdrContextHandleMemorySize(
    PMIDL_STUB_MESSAGE pStubMsg,
    PFORMAT_STRING pFormat
    );




__declspec(dllimport)
unsigned long

NdrCsArrayMemorySize(
    PMIDL_STUB_MESSAGE pStubMsg,
    PFORMAT_STRING pFormat
    );

__declspec(dllimport)
unsigned long

NdrCsTagMemorySize(
    PMIDL_STUB_MESSAGE pStubMsg,
    PFORMAT_STRING pFormat
    );



__declspec(dllimport)
unsigned long

NdrSimpleStructMemorySize(
    PMIDL_STUB_MESSAGE pStubMsg,
    PFORMAT_STRING pFormat
    );

__declspec(dllimport)
unsigned long

NdrConformantStructMemorySize(
    PMIDL_STUB_MESSAGE pStubMsg,
    PFORMAT_STRING pFormat
    );

__declspec(dllimport)
unsigned long

NdrConformantVaryingStructMemorySize(
    PMIDL_STUB_MESSAGE pStubMsg,
    PFORMAT_STRING pFormat
    );

__declspec(dllimport)
unsigned long

NdrComplexStructMemorySize(
    PMIDL_STUB_MESSAGE pStubMsg,
    PFORMAT_STRING pFormat
    );



__declspec(dllimport)
unsigned long

NdrFixedArrayMemorySize(
    PMIDL_STUB_MESSAGE pStubMsg,
    PFORMAT_STRING pFormat
    );

__declspec(dllimport)
unsigned long

NdrConformantArrayMemorySize(
    PMIDL_STUB_MESSAGE pStubMsg,
    PFORMAT_STRING pFormat
    );

__declspec(dllimport)
unsigned long

NdrConformantVaryingArrayMemorySize(
    PMIDL_STUB_MESSAGE pStubMsg,
    PFORMAT_STRING pFormat
    );

__declspec(dllimport)
unsigned long

NdrVaryingArrayMemorySize(
    PMIDL_STUB_MESSAGE pStubMsg,
    PFORMAT_STRING pFormat
    );

__declspec(dllimport)
unsigned long

NdrComplexArrayMemorySize(
    PMIDL_STUB_MESSAGE pStubMsg,
    PFORMAT_STRING pFormat
    );



__declspec(dllimport)
unsigned long

NdrConformantStringMemorySize(
    PMIDL_STUB_MESSAGE pStubMsg,
    PFORMAT_STRING pFormat
    );

__declspec(dllimport)
unsigned long

NdrNonConformantStringMemorySize(
    PMIDL_STUB_MESSAGE pStubMsg,
    PFORMAT_STRING pFormat
    );



__declspec(dllimport)
unsigned long

NdrEncapsulatedUnionMemorySize(
    PMIDL_STUB_MESSAGE pStubMsg,
    PFORMAT_STRING pFormat
    );

__declspec(dllimport)
unsigned long

NdrNonEncapsulatedUnionMemorySize(
    PMIDL_STUB_MESSAGE pStubMsg,
    PFORMAT_STRING pFormat
    );



__declspec(dllimport)
unsigned long

NdrXmitOrRepAsMemorySize(
    PMIDL_STUB_MESSAGE pStubMsg,
    PFORMAT_STRING pFormat
    );



__declspec(dllimport)
unsigned long

NdrUserMarshalMemorySize(
    PMIDL_STUB_MESSAGE pStubMsg,
    PFORMAT_STRING pFormat
    );



__declspec(dllimport)
unsigned long

NdrInterfacePointerMemorySize(
    PMIDL_STUB_MESSAGE pStubMsg,
    PFORMAT_STRING pFormat
    );
__declspec(dllimport)
void

NdrPointerFree(
    PMIDL_STUB_MESSAGE pStubMsg,
    unsigned char * pMemory,
    PFORMAT_STRING pFormat
    );

__declspec(dllimport)
void

NdrCsArrayFree(
    PMIDL_STUB_MESSAGE pStubMsg,
    unsigned char * pMemory,
    PFORMAT_STRING pFormat
    );



__declspec(dllimport)
void

NdrSimpleStructFree(
    PMIDL_STUB_MESSAGE pStubMsg,
    unsigned char * pMemory,
    PFORMAT_STRING pFormat
    );

__declspec(dllimport)
void

NdrConformantStructFree(
    PMIDL_STUB_MESSAGE pStubMsg,
    unsigned char * pMemory,
    PFORMAT_STRING pFormat
    );

__declspec(dllimport)
void

NdrConformantVaryingStructFree(
    PMIDL_STUB_MESSAGE pStubMsg,
    unsigned char * pMemory,
    PFORMAT_STRING pFormat
    );

__declspec(dllimport)
void

NdrComplexStructFree(
    PMIDL_STUB_MESSAGE pStubMsg,
    unsigned char * pMemory,
    PFORMAT_STRING pFormat
    );



__declspec(dllimport)
void

NdrFixedArrayFree(
    PMIDL_STUB_MESSAGE pStubMsg,
    unsigned char * pMemory,
    PFORMAT_STRING pFormat
    );

__declspec(dllimport)
void

NdrConformantArrayFree(
    PMIDL_STUB_MESSAGE pStubMsg,
    unsigned char * pMemory,
    PFORMAT_STRING pFormat
    );

__declspec(dllimport)
void

NdrConformantVaryingArrayFree(
    PMIDL_STUB_MESSAGE pStubMsg,
    unsigned char * pMemory,
    PFORMAT_STRING pFormat
    );

__declspec(dllimport)
void

NdrVaryingArrayFree(
    PMIDL_STUB_MESSAGE pStubMsg,
    unsigned char * pMemory,
    PFORMAT_STRING pFormat
    );

__declspec(dllimport)
void

NdrComplexArrayFree(
    PMIDL_STUB_MESSAGE pStubMsg,
    unsigned char * pMemory,
    PFORMAT_STRING pFormat
    );



__declspec(dllimport)
void

NdrEncapsulatedUnionFree(
    PMIDL_STUB_MESSAGE pStubMsg,
    unsigned char * pMemory,
    PFORMAT_STRING pFormat
    );

__declspec(dllimport)
void

NdrNonEncapsulatedUnionFree(
    PMIDL_STUB_MESSAGE pStubMsg,
    unsigned char * pMemory,
    PFORMAT_STRING pFormat
    );



__declspec(dllimport)
void

NdrByteCountPointerFree(
    PMIDL_STUB_MESSAGE pStubMsg,
    unsigned char * pMemory,
    PFORMAT_STRING pFormat
    );



__declspec(dllimport)
void

NdrXmitOrRepAsFree(
    PMIDL_STUB_MESSAGE pStubMsg,
    unsigned char * pMemory,
    PFORMAT_STRING pFormat
    );



__declspec(dllimport)
void

NdrUserMarshalFree(
    PMIDL_STUB_MESSAGE pStubMsg,
    unsigned char * pMemory,
    PFORMAT_STRING pFormat
    );



__declspec(dllimport)
void

NdrInterfacePointerFree(
    PMIDL_STUB_MESSAGE pStubMsg,
    unsigned char * pMemory,
    PFORMAT_STRING pFormat
    );
__declspec(dllimport)
void

NdrConvert2(
    PMIDL_STUB_MESSAGE pStubMsg,
    PFORMAT_STRING pFormat,
    long NumberParams
    );

__declspec(dllimport)
void

NdrConvert(
    PMIDL_STUB_MESSAGE pStubMsg,
    PFORMAT_STRING pFormat
    );
__declspec(dllimport)
unsigned char *

NdrUserMarshalSimpleTypeConvert(
    unsigned long * pFlags,
    unsigned char * pBuffer,
    unsigned char FormatChar
    );
__declspec(dllimport)
void

NdrClientInitializeNew(
    PRPC_MESSAGE pRpcMsg,
    PMIDL_STUB_MESSAGE pStubMsg,
    PMIDL_STUB_DESC pStubDescriptor,
    unsigned int ProcNum
    );

__declspec(dllimport)
unsigned char *

NdrServerInitializeNew(
    PRPC_MESSAGE pRpcMsg,
    PMIDL_STUB_MESSAGE pStubMsg,
    PMIDL_STUB_DESC pStubDescriptor
    );

__declspec(dllimport)
void

NdrServerInitializePartial(
    PRPC_MESSAGE pRpcMsg,
    PMIDL_STUB_MESSAGE pStubMsg,
    PMIDL_STUB_DESC pStubDescriptor,
    unsigned long RequestedBufferSize
    );

__declspec(dllimport)
void

NdrClientInitialize(
    PRPC_MESSAGE pRpcMsg,
    PMIDL_STUB_MESSAGE pStubMsg,
    PMIDL_STUB_DESC pStubDescriptor,
    unsigned int ProcNum
    );

__declspec(dllimport)
unsigned char *

NdrServerInitialize(
    PRPC_MESSAGE pRpcMsg,
    PMIDL_STUB_MESSAGE pStubMsg,
    PMIDL_STUB_DESC pStubDescriptor
    );

__declspec(dllimport)
unsigned char *

NdrServerInitializeUnmarshall (
    PMIDL_STUB_MESSAGE pStubMsg,
    PMIDL_STUB_DESC pStubDescriptor,
    PRPC_MESSAGE pRpcMsg
    );

__declspec(dllimport)
void

NdrServerInitializeMarshall (
    PRPC_MESSAGE pRpcMsg,
    PMIDL_STUB_MESSAGE pStubMsg
    );

__declspec(dllimport)
unsigned char *

NdrGetBuffer(
    PMIDL_STUB_MESSAGE pStubMsg,
    unsigned long BufferLength,
    RPC_BINDING_HANDLE Handle
    );

__declspec(dllimport)
unsigned char *

NdrNsGetBuffer(
    PMIDL_STUB_MESSAGE pStubMsg,
    unsigned long BufferLength,
    RPC_BINDING_HANDLE Handle
    );

__declspec(dllimport)
unsigned char *

NdrSendReceive(
    PMIDL_STUB_MESSAGE pStubMsg,
    unsigned char * pBufferEnd
    );

__declspec(dllimport)
unsigned char *

NdrNsSendReceive(
    PMIDL_STUB_MESSAGE pStubMsg,
    unsigned char * pBufferEnd,
    RPC_BINDING_HANDLE * pAutoHandle
    );

__declspec(dllimport)
void

NdrFreeBuffer(
    PMIDL_STUB_MESSAGE pStubMsg
    );

__declspec(dllimport)
RPC_STATUS

NdrGetDcomProtocolVersion(
    PMIDL_STUB_MESSAGE pStubMsg,
    RPC_VERSION * pVersion );
CLIENT_CALL_RETURN
NdrClientCall2(
    PMIDL_STUB_DESC pStubDescriptor,
    PFORMAT_STRING pFormat,
    ...
    );


CLIENT_CALL_RETURN
NdrClientCall(
    PMIDL_STUB_DESC pStubDescriptor,
    PFORMAT_STRING pFormat,
    ...
    );

CLIENT_CALL_RETURN
NdrAsyncClientCall(
    PMIDL_STUB_DESC pStubDescriptor,
    PFORMAT_STRING pFormat,
    ...
    );

CLIENT_CALL_RETURN
NdrDcomAsyncClientCall(
    PMIDL_STUB_DESC pStubDescriptor,
    PFORMAT_STRING pFormat,
    ...
    );


typedef enum {
    STUB_UNMARSHAL,
    STUB_CALL_SERVER,
    STUB_MARSHAL,
    STUB_CALL_SERVER_NO_HRESULT
}STUB_PHASE;

typedef enum {
    PROXY_CALCSIZE,
    PROXY_GETBUFFER,
    PROXY_MARSHAL,
    PROXY_SENDRECEIVE,
    PROXY_UNMARSHAL
}PROXY_PHASE;

struct IRpcStubBuffer;


__declspec(dllimport)
void

NdrAsyncServerCall(
    PRPC_MESSAGE pRpcMsg
    );


__declspec(dllimport)
long

NdrAsyncStubCall(
    struct IRpcStubBuffer * pThis,
    struct IRpcChannelBuffer * pChannel,
    PRPC_MESSAGE pRpcMsg,
    unsigned long * pdwStubPhase
    );


__declspec(dllimport)
long

NdrDcomAsyncStubCall(
    struct IRpcStubBuffer * pThis,
    struct IRpcChannelBuffer * pChannel,
    PRPC_MESSAGE pRpcMsg,
    unsigned long * pdwStubPhase
    );

__declspec(dllimport)
long

NdrStubCall2(
    struct IRpcStubBuffer * pThis,
    struct IRpcChannelBuffer * pChannel,
    PRPC_MESSAGE pRpcMsg,
    unsigned long * pdwStubPhase
    );

__declspec(dllimport)
void

NdrServerCall2(
    PRPC_MESSAGE pRpcMsg
    );

__declspec(dllimport)
long

NdrStubCall (
    struct IRpcStubBuffer * pThis,
    struct IRpcChannelBuffer * pChannel,
    PRPC_MESSAGE pRpcMsg,
    unsigned long * pdwStubPhase
    );

__declspec(dllimport)
void

NdrServerCall(
    PRPC_MESSAGE pRpcMsg
    );

__declspec(dllimport)
int

NdrServerUnmarshall(
    struct IRpcChannelBuffer * pChannel,
    PRPC_MESSAGE pRpcMsg,
    PMIDL_STUB_MESSAGE pStubMsg,
    PMIDL_STUB_DESC pStubDescriptor,
    PFORMAT_STRING pFormat,
    void * pParamList
    );

__declspec(dllimport)
void

NdrServerMarshall(
    struct IRpcStubBuffer * pThis,
    struct IRpcChannelBuffer * pChannel,
    PMIDL_STUB_MESSAGE pStubMsg,
    PFORMAT_STRING pFormat
    );



__declspec(dllimport)
RPC_STATUS

NdrMapCommAndFaultStatus(
    PMIDL_STUB_MESSAGE pStubMsg,
    unsigned long * pCommStatus,
    unsigned long * pFaultStatus,
    RPC_STATUS Status
    );
typedef void * RPC_SS_THREAD_HANDLE;

typedef void *
RPC_CLIENT_ALLOC (
     size_t Size
    );

typedef void
RPC_CLIENT_FREE (
     void * Ptr
    );
__declspec(dllimport)
void *

RpcSsAllocate (
     size_t Size
    );

__declspec(dllimport)
void

RpcSsDisableAllocate (
    void
    );

__declspec(dllimport)
void

RpcSsEnableAllocate (
    void
    );

__declspec(dllimport)
void

RpcSsFree (
     void * NodeToFree
    );

__declspec(dllimport)
RPC_SS_THREAD_HANDLE

RpcSsGetThreadHandle (
    void
    );

__declspec(dllimport)
void

RpcSsSetClientAllocFree (
     RPC_CLIENT_ALLOC * ClientAlloc,
     RPC_CLIENT_FREE * ClientFree
    );

__declspec(dllimport)
void

RpcSsSetThreadHandle (
     RPC_SS_THREAD_HANDLE Id
    );

__declspec(dllimport)
void

RpcSsSwapClientAllocFree (
     RPC_CLIENT_ALLOC * ClientAlloc,
     RPC_CLIENT_FREE * ClientFree,
     RPC_CLIENT_ALLOC * * OldClientAlloc,
     RPC_CLIENT_FREE * * OldClientFree
    );
__declspec(dllimport)
void *

RpcSmAllocate (
     size_t Size,
     RPC_STATUS * pStatus
    );

__declspec(dllimport)
RPC_STATUS

RpcSmClientFree (
     void * pNodeToFree
    );

__declspec(dllimport)
RPC_STATUS

RpcSmDestroyClientContext (
     void * * ContextHandle
    );

__declspec(dllimport)
RPC_STATUS

RpcSmDisableAllocate (
    void
    );

__declspec(dllimport)
RPC_STATUS

RpcSmEnableAllocate (
    void
    );

__declspec(dllimport)
RPC_STATUS

RpcSmFree (
     void * NodeToFree
    );

__declspec(dllimport)
RPC_SS_THREAD_HANDLE

RpcSmGetThreadHandle (
     RPC_STATUS * pStatus
    );

__declspec(dllimport)
RPC_STATUS

RpcSmSetClientAllocFree (
     RPC_CLIENT_ALLOC * ClientAlloc,
     RPC_CLIENT_FREE * ClientFree
    );

__declspec(dllimport)
RPC_STATUS

RpcSmSetThreadHandle (
     RPC_SS_THREAD_HANDLE Id
    );

__declspec(dllimport)
RPC_STATUS

RpcSmSwapClientAllocFree (
     RPC_CLIENT_ALLOC * ClientAlloc,
     RPC_CLIENT_FREE * ClientFree,
     RPC_CLIENT_ALLOC * * OldClientAlloc,
     RPC_CLIENT_FREE * * OldClientFree
    );
__declspec(dllimport)
void

NdrRpcSsEnableAllocate(
    PMIDL_STUB_MESSAGE pMessage );

__declspec(dllimport)
void

NdrRpcSsDisableAllocate(
    PMIDL_STUB_MESSAGE pMessage );

__declspec(dllimport)
void

NdrRpcSmSetClientToOsf(
    PMIDL_STUB_MESSAGE pMessage );

__declspec(dllimport)
void *

NdrRpcSmClientAllocate (
     size_t Size
    );

__declspec(dllimport)
void

NdrRpcSmClientFree (
     void * NodeToFree
    );

__declspec(dllimport)
void *

NdrRpcSsDefaultAllocate (
     size_t Size
    );

__declspec(dllimport)
void

NdrRpcSsDefaultFree (
     void * NodeToFree
    );
__declspec(dllimport)
PFULL_PTR_XLAT_TABLES

NdrFullPointerXlatInit(
    unsigned long NumberOfPointers,
    XLAT_SIDE XlatSide
    );

__declspec(dllimport)
void

NdrFullPointerXlatFree(
    PFULL_PTR_XLAT_TABLES pXlatTables
    );


__declspec(dllimport)
void *

NdrAllocate(
    PMIDL_STUB_MESSAGE pStubMsg,
    size_t Len
    );

__declspec(dllimport)
void

NdrClearOutParameters(
    PMIDL_STUB_MESSAGE pStubMsg,
    PFORMAT_STRING pFormat,
    void * ArgAddr
    );
__declspec(dllimport)
void *

NdrOleAllocate (
     size_t Size
    );

__declspec(dllimport)
void

NdrOleFree (
     void * NodeToFree
    );
typedef struct _NDR_USER_MARSHAL_INFO_LEVEL1
{
    void * Buffer;
    unsigned long BufferSize;
    void *(  * pfnAllocate)(size_t);
    void (  * pfnFree)(void *);
    struct IRpcChannelBuffer * pRpcChannelBuffer;
    ULONG_PTR Reserved[5];
} NDR_USER_MARSHAL_INFO_LEVEL1;


typedef struct _NDR_USER_MARSHAL_INFO
{
    unsigned long InformationLevel;
    union {
        NDR_USER_MARSHAL_INFO_LEVEL1 Level1;
    }  u ;
} NDR_USER_MARSHAL_INFO;



RPC_STATUS

NdrGetUserMarshalInfo (
     unsigned long * pFlags,
     unsigned long InformationLevel,
     NDR_USER_MARSHAL_INFO * pMarshalInfo
    );
RPC_STATUS
NdrCreateServerInterfaceFromStub(
             struct IRpcStubBuffer* pStub,
               RPC_SERVER_INTERFACE *pServerIf );
CLIENT_CALL_RETURN
NdrClientCall3(
    MIDL_STUBLESS_PROXY_INFO *pProxyInfo,
    unsigned long nProcNum,
    void * pReturnValue,
    ...
    );

CLIENT_CALL_RETURN
Ndr64AsyncClientCall(
    MIDL_STUBLESS_PROXY_INFO *pProxyInfo,
    unsigned long nProcNum,
    void * pReturnValue,
    ...
    );

CLIENT_CALL_RETURN
Ndr64DcomAsyncClientCall(
    MIDL_STUBLESS_PROXY_INFO *pProxyInfo,
    unsigned long nProcNum,
    void * pReturnValue,
    ...
    );

struct IRpcStubBuffer;

__declspec(dllimport)
void

Ndr64AsyncServerCall(
    PRPC_MESSAGE pRpcMsg
    );

__declspec(dllimport)
void

Ndr64AsyncServerCall64(
    PRPC_MESSAGE pRpcMsg
    );

__declspec(dllimport)
void

Ndr64AsyncServerCallAll(
    PRPC_MESSAGE pRpcMsg
    );

__declspec(dllimport)
long

Ndr64AsyncStubCall(
    struct IRpcStubBuffer * pThis,
    struct IRpcChannelBuffer * pChannel,
    PRPC_MESSAGE pRpcMsg,
    unsigned long * pdwStubPhase
    );


__declspec(dllimport)
long

Ndr64DcomAsyncStubCall(
    struct IRpcStubBuffer * pThis,
    struct IRpcChannelBuffer * pChannel,
    PRPC_MESSAGE pRpcMsg,
    unsigned long * pdwStubPhase
    );

__declspec(dllimport)
long

NdrStubCall3 (
    struct IRpcStubBuffer * pThis,
    struct IRpcChannelBuffer * pChannel,
    PRPC_MESSAGE pRpcMsg,
    unsigned long * pdwStubPhase
    );

__declspec(dllimport)
void

NdrServerCallAll(
    PRPC_MESSAGE pRpcMsg
    );

__declspec(dllimport)
void

NdrServerCallNdr64(
    PRPC_MESSAGE pRpcMsg
    );


__declspec(dllimport)
void

NdrServerCall3(
    PRPC_MESSAGE pRpcMsg
    );



__declspec(dllimport)
void

NdrPartialIgnoreClientMarshall(
    PMIDL_STUB_MESSAGE pStubMsg,
    void * pMemory
    );

__declspec(dllimport)
void

NdrPartialIgnoreServerUnmarshall(
    PMIDL_STUB_MESSAGE pStubMsg,
    void ** ppMemory
    );

__declspec(dllimport)
void

NdrPartialIgnoreClientBufferSize(
    PMIDL_STUB_MESSAGE pStubMsg,
    void * pMemory
    );

__declspec(dllimport)
void

NdrPartialIgnoreServerInitialize(
    PMIDL_STUB_MESSAGE pStubMsg,
    void ** ppMemory,
    PFORMAT_STRING pFormat
    );


void
RpcUserFree( handle_t AsyncHandle, void * pBuffer );
extern RPC_IF_HANDLE __MIDL_itf_wtypes_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_wtypes_0000_0000_v0_0_s_ifspec;







typedef struct tagRemHGLOBAL
    {
    long fNullHGlobal;
    unsigned long cbData;
    byte data[ 1 ];
    } RemHGLOBAL;

typedef struct tagRemHMETAFILEPICT
    {
    long mm;
    long xExt;
    long yExt;
    unsigned long cbData;
    byte data[ 1 ];
    } RemHMETAFILEPICT;

typedef struct tagRemHENHMETAFILE
    {
    unsigned long cbData;
    byte data[ 1 ];
    } RemHENHMETAFILE;

typedef struct tagRemHBITMAP
    {
    unsigned long cbData;
    byte data[ 1 ];
    } RemHBITMAP;

typedef struct tagRemHPALETTE
    {
    unsigned long cbData;
    byte data[ 1 ];
    } RemHPALETTE;

typedef struct tagRemBRUSH
    {
    unsigned long cbData;
    byte data[ 1 ];
    } RemHBRUSH;
typedef WCHAR OLECHAR;

typedef   OLECHAR *LPOLESTR;

typedef   const OLECHAR *LPCOLESTR;
typedef unsigned char UCHAR;

typedef short SHORT;

typedef unsigned short USHORT;

typedef DWORD ULONG;

typedef double DOUBLE;
typedef struct _COAUTHIDENTITY
    {
    USHORT *User;
    ULONG UserLength;
    USHORT *Domain;
    ULONG DomainLength;
    USHORT *Password;
    ULONG PasswordLength;
    ULONG Flags;
    } COAUTHIDENTITY;

typedef struct _COAUTHINFO
    {
    DWORD dwAuthnSvc;
    DWORD dwAuthzSvc;
    LPWSTR pwszServerPrincName;
    DWORD dwAuthnLevel;
    DWORD dwImpersonationLevel;
    COAUTHIDENTITY *pAuthIdentityData;
    DWORD dwCapabilities;
    } COAUTHINFO;

typedef LONG SCODE;

typedef SCODE *PSCODE;
typedef
enum tagMEMCTX
    { MEMCTX_TASK = 1,
	MEMCTX_SHARED = 2,
	MEMCTX_MACSYSTEM = 3,
	MEMCTX_UNKNOWN = -1,
	MEMCTX_SAME = -2
    } MEMCTX;
typedef
enum tagCLSCTX
    { CLSCTX_INPROC_SERVER = 0x1,
	CLSCTX_INPROC_HANDLER = 0x2,
	CLSCTX_LOCAL_SERVER = 0x4,
	CLSCTX_INPROC_SERVER16 = 0x8,
	CLSCTX_REMOTE_SERVER = 0x10,
	CLSCTX_INPROC_HANDLER16 = 0x20,
	CLSCTX_RESERVED1 = 0x40,
	CLSCTX_RESERVED2 = 0x80,
	CLSCTX_RESERVED3 = 0x100,
	CLSCTX_RESERVED4 = 0x200,
	CLSCTX_NO_CODE_DOWNLOAD = 0x400,
	CLSCTX_RESERVED5 = 0x800,
	CLSCTX_NO_CUSTOM_MARSHAL = 0x1000,
	CLSCTX_ENABLE_CODE_DOWNLOAD = 0x2000,
	CLSCTX_NO_FAILURE_LOG = 0x4000,
	CLSCTX_DISABLE_AAA = 0x8000,
	CLSCTX_ENABLE_AAA = 0x10000,
	CLSCTX_FROM_DEFAULT_CONTEXT = 0x20000,
	CLSCTX_ACTIVATE_32_BIT_SERVER = 0x40000,
	CLSCTX_ACTIVATE_64_BIT_SERVER = 0x80000,
	CLSCTX_ENABLE_CLOAKING = 0x100000,
	CLSCTX_PS_DLL = ( int )0x80000000
    } CLSCTX;
typedef
enum tagMSHLFLAGS
    { MSHLFLAGS_NORMAL = 0,
	MSHLFLAGS_TABLESTRONG = 1,
	MSHLFLAGS_TABLEWEAK = 2,
	MSHLFLAGS_NOPING = 4,
	MSHLFLAGS_RESERVED1 = 8,
	MSHLFLAGS_RESERVED2 = 16,
	MSHLFLAGS_RESERVED3 = 32,
	MSHLFLAGS_RESERVED4 = 64
    } MSHLFLAGS;

typedef
enum tagMSHCTX
    { MSHCTX_LOCAL = 0,
	MSHCTX_NOSHAREDMEM = 1,
	MSHCTX_DIFFERENTMACHINE = 2,
	MSHCTX_INPROC = 3,
	MSHCTX_CROSSCTX = 4
    } MSHCTX;

typedef
enum tagDVASPECT
    { DVASPECT_CONTENT = 1,
	DVASPECT_THUMBNAIL = 2,
	DVASPECT_ICON = 4,
	DVASPECT_DOCPRINT = 8
    } DVASPECT;

typedef
enum tagSTGC
    { STGC_DEFAULT = 0,
	STGC_OVERWRITE = 1,
	STGC_ONLYIFCURRENT = 2,
	STGC_DANGEROUSLYCOMMITMERELYTODISKCACHE = 4,
	STGC_CONSOLIDATE = 8
    } STGC;

typedef
enum tagSTGMOVE
    { STGMOVE_MOVE = 0,
	STGMOVE_COPY = 1,
	STGMOVE_SHALLOWCOPY = 2
    } STGMOVE;

typedef
enum tagSTATFLAG
    { STATFLAG_DEFAULT = 0,
	STATFLAG_NONAME = 1,
	STATFLAG_NOOPEN = 2
    } STATFLAG;

typedef void *HCONTEXT;



typedef DWORD LCID;




typedef USHORT LANGID;


typedef struct _BYTE_BLOB
    {
    unsigned long clSize;
    byte abData[ 1 ];
    } BYTE_BLOB;

typedef   BYTE_BLOB *UP_BYTE_BLOB;

typedef struct _WORD_BLOB
    {
    unsigned long clSize;
    unsigned short asData[ 1 ];
    } WORD_BLOB;

typedef   WORD_BLOB *UP_WORD_BLOB;

typedef struct _DWORD_BLOB
    {
    unsigned long clSize;
    unsigned long alData[ 1 ];
    } DWORD_BLOB;

typedef   DWORD_BLOB *UP_DWORD_BLOB;

typedef struct _FLAGGED_BYTE_BLOB
    {
    unsigned long fFlags;
    unsigned long clSize;
    byte abData[ 1 ];
    } FLAGGED_BYTE_BLOB;

typedef   FLAGGED_BYTE_BLOB *UP_FLAGGED_BYTE_BLOB;

typedef struct _FLAGGED_WORD_BLOB
    {
    unsigned long fFlags;
    unsigned long clSize;
    unsigned short asData[ 1 ];
    } FLAGGED_WORD_BLOB;

typedef   FLAGGED_WORD_BLOB *UP_FLAGGED_WORD_BLOB;

typedef struct _BYTE_SIZEDARR
    {
    unsigned long clSize;
    byte *pData;
    } BYTE_SIZEDARR;

typedef struct _SHORT_SIZEDARR
    {
    unsigned long clSize;
    unsigned short *pData;
    } WORD_SIZEDARR;

typedef struct _LONG_SIZEDARR
    {
    unsigned long clSize;
    unsigned long *pData;
    } DWORD_SIZEDARR;

typedef struct _HYPER_SIZEDARR
    {
    unsigned long clSize;
    hyper *pData;
    } HYPER_SIZEDARR;







typedef struct _userCLIPFORMAT
    {
    long fContext;
    union __MIDL_IWinTypes_0001
        {
        DWORD dwValue;
        wchar_t *pwszName;
        } u;
    } userCLIPFORMAT;

typedef   userCLIPFORMAT *wireCLIPFORMAT;

typedef WORD CLIPFORMAT;

typedef struct _GDI_NONREMOTE
    {
    long fContext;
    union __MIDL_IWinTypes_0002
        {
        long hInproc;
        DWORD_BLOB *hRemote;
        } u;
    } GDI_NONREMOTE;

typedef struct _userHGLOBAL
    {
    long fContext;
    union __MIDL_IWinTypes_0003
        {
        long hInproc;
        FLAGGED_BYTE_BLOB *hRemote;
        __int64 hInproc64;
        } u;
    } userHGLOBAL;

typedef   userHGLOBAL *wireHGLOBAL;

typedef struct _userHMETAFILE
    {
    long fContext;
    union __MIDL_IWinTypes_0004
        {
        long hInproc;
        BYTE_BLOB *hRemote;
        __int64 hInproc64;
        } u;
    } userHMETAFILE;

typedef struct _remoteMETAFILEPICT
    {
    long mm;
    long xExt;
    long yExt;
    userHMETAFILE *hMF;
    } remoteMETAFILEPICT;

typedef struct _userHMETAFILEPICT
    {
    long fContext;
    union __MIDL_IWinTypes_0005
        {
        long hInproc;
        remoteMETAFILEPICT *hRemote;
        __int64 hInproc64;
        } u;
    } userHMETAFILEPICT;

typedef struct _userHENHMETAFILE
    {
    long fContext;
    union __MIDL_IWinTypes_0006
        {
        long hInproc;
        BYTE_BLOB *hRemote;
        __int64 hInproc64;
        } u;
    } userHENHMETAFILE;

typedef struct _userBITMAP
    {
    LONG bmType;
    LONG bmWidth;
    LONG bmHeight;
    LONG bmWidthBytes;
    WORD bmPlanes;
    WORD bmBitsPixel;
    ULONG cbSize;
    byte pBuffer[ 1 ];
    } userBITMAP;

typedef struct _userHBITMAP
    {
    long fContext;
    union __MIDL_IWinTypes_0007
        {
        long hInproc;
        userBITMAP *hRemote;
        __int64 hInproc64;
        } u;
    } userHBITMAP;

typedef struct _userHPALETTE
    {
    long fContext;
    union __MIDL_IWinTypes_0008
        {
        long hInproc;
        LOGPALETTE *hRemote;
        __int64 hInproc64;
        } u;
    } userHPALETTE;

typedef struct _RemotableHandle
    {
    long fContext;
    union __MIDL_IWinTypes_0009
        {
        long hInproc;
        long hRemote;
        } u;
    } RemotableHandle;

typedef   RemotableHandle *wireHWND;

typedef   RemotableHandle *wireHMENU;

typedef   RemotableHandle *wireHACCEL;

typedef   RemotableHandle *wireHBRUSH;

typedef   RemotableHandle *wireHFONT;

typedef   RemotableHandle *wireHDC;

typedef   RemotableHandle *wireHICON;

typedef   RemotableHandle *wireHRGN;
typedef   userHBITMAP *wireHBITMAP;

typedef   userHPALETTE *wireHPALETTE;

typedef   userHENHMETAFILE *wireHENHMETAFILE;

typedef   userHMETAFILE *wireHMETAFILE;

typedef   userHMETAFILEPICT *wireHMETAFILEPICT;
typedef void *HMETAFILEPICT;



extern RPC_IF_HANDLE IWinTypes_v0_1_c_ifspec;
extern RPC_IF_HANDLE IWinTypes_v0_1_s_ifspec;
typedef double DATE;
typedef union tagCY {
    struct {




        unsigned long Lo;
        long Hi;

    }  s ;
    LONGLONG int64;
} CY;


typedef CY *LPCY;
typedef struct tagDEC {
    USHORT wReserved;
    union {
        struct {
            BYTE scale;
            BYTE sign;
        }  s ;
        USHORT signscale;
    }  u ;
    ULONG Hi32;
    union {
        struct {




            ULONG Lo32;
            ULONG Mid32;

        }  s2 ;
        ULONGLONG Lo64;
    }  u2 ;
} DECIMAL;
typedef DECIMAL *LPDECIMAL;
typedef   FLAGGED_WORD_BLOB *wireBSTR;

typedef OLECHAR *BSTR;

typedef BSTR *LPBSTR;


typedef short VARIANT_BOOL;









typedef boolean BOOLEAN;






typedef struct tagBSTRBLOB
    {
    ULONG cbSize;
    BYTE *pData;
    } BSTRBLOB;

typedef struct tagBSTRBLOB *LPBSTRBLOB;








typedef struct tagBLOB
    {
    ULONG cbSize;
    BYTE *pBlobData;
    } BLOB;

typedef struct tagBLOB *LPBLOB;


typedef struct tagCLIPDATA
    {
    ULONG cbSize;
    long ulClipFmt;
    BYTE *pClipData;
    } CLIPDATA;



typedef unsigned short VARTYPE;
enum VARENUM
    { VT_EMPTY = 0,
	VT_NULL = 1,
	VT_I2 = 2,
	VT_I4 = 3,
	VT_R4 = 4,
	VT_R8 = 5,
	VT_CY = 6,
	VT_DATE = 7,
	VT_BSTR = 8,
	VT_DISPATCH = 9,
	VT_ERROR = 10,
	VT_BOOL = 11,
	VT_VARIANT = 12,
	VT_UNKNOWN = 13,
	VT_DECIMAL = 14,
	VT_I1 = 16,
	VT_UI1 = 17,
	VT_UI2 = 18,
	VT_UI4 = 19,
	VT_I8 = 20,
	VT_UI8 = 21,
	VT_INT = 22,
	VT_UINT = 23,
	VT_VOID = 24,
	VT_HRESULT = 25,
	VT_PTR = 26,
	VT_SAFEARRAY = 27,
	VT_CARRAY = 28,
	VT_USERDEFINED = 29,
	VT_LPSTR = 30,
	VT_LPWSTR = 31,
	VT_RECORD = 36,
	VT_INT_PTR = 37,
	VT_UINT_PTR = 38,
	VT_FILETIME = 64,
	VT_BLOB = 65,
	VT_STREAM = 66,
	VT_STORAGE = 67,
	VT_STREAMED_OBJECT = 68,
	VT_STORED_OBJECT = 69,
	VT_BLOB_OBJECT = 70,
	VT_CF = 71,
	VT_CLSID = 72,
	VT_VERSIONED_STREAM = 73,
	VT_BSTR_BLOB = 0xfff,
	VT_VECTOR = 0x1000,
	VT_ARRAY = 0x2000,
	VT_BYREF = 0x4000,
	VT_RESERVED = 0x8000,
	VT_ILLEGAL = 0xffff,
	VT_ILLEGALMASKED = 0xfff,
	VT_TYPEMASK = 0xfff
    } ;
typedef ULONG PROPID;



typedef struct _tagpropertykey
    {
    GUID fmtid;
    DWORD pid;
    } PROPERTYKEY;
typedef struct tagCSPLATFORM
    {
    DWORD dwPlatformId;
    DWORD dwVersionHi;
    DWORD dwVersionLo;
    DWORD dwProcessorArch;
    } CSPLATFORM;

typedef struct tagQUERYCONTEXT
    {
    DWORD dwContext;
    CSPLATFORM Platform;
    LCID Locale;
    DWORD dwVersionHi;
    DWORD dwVersionLo;
    } QUERYCONTEXT;

typedef
enum tagTYSPEC
    { TYSPEC_CLSID = 0,
	TYSPEC_FILEEXT = ( TYSPEC_CLSID + 1 ) ,
	TYSPEC_MIMETYPE = ( TYSPEC_FILEEXT + 1 ) ,
	TYSPEC_FILENAME = ( TYSPEC_MIMETYPE + 1 ) ,
	TYSPEC_PROGID = ( TYSPEC_FILENAME + 1 ) ,
	TYSPEC_PACKAGENAME = ( TYSPEC_PROGID + 1 ) ,
	TYSPEC_OBJECTID = ( TYSPEC_PACKAGENAME + 1 )
    } TYSPEC;

typedef struct __MIDL___MIDL_itf_wtypes_0000_0001_0001
    {
    DWORD tyspec;
    union __MIDL___MIDL_itf_wtypes_0000_0001_0005
        {
        CLSID clsid;
        LPOLESTR pFileExt;
        LPOLESTR pMimeType;
        LPOLESTR pProgId;
        LPOLESTR pFileName;
        struct
            {
            LPOLESTR pPackageName;
            GUID PolicyId;
            } ByName;
        struct
            {
            GUID ObjectId;
            GUID PolicyId;
            } ByObjectId;
        } tagged_union;
    } uCLSSPEC;



extern RPC_IF_HANDLE __MIDL_itf_wtypes_0000_0001_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_wtypes_0000_0001_v0_0_s_ifspec;
extern const GUID  GUID_DEVINTERFACE_DISK ;
extern const GUID  GUID_DEVINTERFACE_CDROM ;
extern const GUID  GUID_DEVINTERFACE_PARTITION ;
extern const GUID  GUID_DEVINTERFACE_TAPE ;
extern const GUID  GUID_DEVINTERFACE_WRITEONCEDISK ;
extern const GUID  GUID_DEVINTERFACE_VOLUME ;
extern const GUID  GUID_DEVINTERFACE_MEDIUMCHANGER ;
extern const GUID  GUID_DEVINTERFACE_FLOPPY ;
extern const GUID  GUID_DEVINTERFACE_CDCHANGER ;
extern const GUID  GUID_DEVINTERFACE_STORAGEPORT ;









extern const GUID  GUID_DEVINTERFACE_HIDDEN_VOLUME ;

extern const GUID  GUID_DEVINTERFACE_COMPORT ;
extern const GUID  GUID_DEVINTERFACE_SERENUM_BUS_ENUMERATOR ;
typedef struct _STORAGE_HOTPLUG_INFO {
    DWORD Size;
    BOOLEAN MediaRemovable;
    BOOLEAN MediaHotplug;
    BOOLEAN DeviceHotplug;
    BOOLEAN WriteCacheEnableOverride;
} STORAGE_HOTPLUG_INFO, *PSTORAGE_HOTPLUG_INFO;
typedef struct _STORAGE_DEVICE_NUMBER {





    DWORD  DeviceType;





    DWORD DeviceNumber;






    DWORD PartitionNumber;
} STORAGE_DEVICE_NUMBER, *PSTORAGE_DEVICE_NUMBER;





typedef struct _STORAGE_BUS_RESET_REQUEST {
    BYTE PathId;
} STORAGE_BUS_RESET_REQUEST, *PSTORAGE_BUS_RESET_REQUEST;





typedef struct STORAGE_BREAK_RESERVATION_REQUEST {
        DWORD Length;
        BYTE _unused;
    BYTE PathId;
    BYTE TargetId;
    BYTE Lun;
} STORAGE_BREAK_RESERVATION_REQUEST, *PSTORAGE_BREAK_RESERVATION_REQUEST;
typedef struct _PREVENT_MEDIA_REMOVAL {
    BOOLEAN PreventMediaRemoval;
} PREVENT_MEDIA_REMOVAL, *PPREVENT_MEDIA_REMOVAL;







typedef struct _CLASS_MEDIA_CHANGE_CONTEXT {
        DWORD MediaChangeCount;
        DWORD NewState;
} CLASS_MEDIA_CHANGE_CONTEXT, *PCLASS_MEDIA_CHANGE_CONTEXT;





typedef struct _TAPE_STATISTICS {
    DWORD Version;
    DWORD Flags;
    LARGE_INTEGER RecoveredWrites;
    LARGE_INTEGER UnrecoveredWrites;
    LARGE_INTEGER RecoveredReads;
    LARGE_INTEGER UnrecoveredReads;
    BYTE CompressionRatioReads;
    BYTE CompressionRatioWrites;
} TAPE_STATISTICS, *PTAPE_STATISTICS;








typedef struct _TAPE_GET_STATISTICS {
    DWORD Operation;
} TAPE_GET_STATISTICS, *PTAPE_GET_STATISTICS;










typedef enum _STORAGE_MEDIA_TYPE {
    DDS_4mm = 0x20,
    MiniQic,
    Travan,
    QIC,
    MP_8mm,
    AME_8mm,
    AIT1_8mm,
    DLT,
    NCTP,
    IBM_3480,
    IBM_3490E,
    IBM_Magstar_3590,
    IBM_Magstar_MP,
    STK_DATA_D3,
    SONY_DTF,
    DV_6mm,
    DMI,
    SONY_D2,
    CLEANER_CARTRIDGE,
    CD_ROM,
    CD_R,
    CD_RW,
    DVD_ROM,
    DVD_R,
    DVD_RW,
    MO_3_RW,
    MO_5_WO,
    MO_5_RW,
    MO_5_LIMDOW,
    PC_5_WO,
    PC_5_RW,
    PD_5_RW,
    ABL_5_WO,
    PINNACLE_APEX_5_RW,
    SONY_12_WO,
    PHILIPS_12_WO,
    HITACHI_12_WO,
    CYGNET_12_WO,
    KODAK_14_WO,
    MO_NFR_525,
    NIKON_12_RW,
    IOMEGA_ZIP,
    IOMEGA_JAZ,
    SYQUEST_EZ135,
    SYQUEST_EZFLYER,
    SYQUEST_SYJET,
    AVATAR_F2,
    MP2_8mm,
    DST_S,
    DST_M,
    DST_L,
    VXATape_1,
    VXATape_2,



    STK_9840,

    LTO_Ultrium,
    LTO_Accelis,
    DVD_RAM,
    AIT_8mm,
    ADR_1,
    ADR_2,
    STK_9940,
    SAIT,
    VXATape
}STORAGE_MEDIA_TYPE, *PSTORAGE_MEDIA_TYPE;
typedef enum _STORAGE_BUS_TYPE {
    BusTypeUnknown = 0x00,
    BusTypeScsi,
    BusTypeAtapi,
    BusTypeAta,
    BusType1394,
    BusTypeSsa,
    BusTypeFibre,
    BusTypeUsb,
    BusTypeRAID,
    BusTypeiScsi,
    BusTypeSas,
    BusTypeSata,
    BusTypeSd,
    BusTypeMmc,
    BusTypeMax,
    BusTypeMaxReserved = 0x7F
} STORAGE_BUS_TYPE, *PSTORAGE_BUS_TYPE;

typedef struct _DEVICE_MEDIA_INFO {
    union {
        struct {
            LARGE_INTEGER Cylinders;
            STORAGE_MEDIA_TYPE MediaType;
            DWORD TracksPerCylinder;
            DWORD SectorsPerTrack;
            DWORD BytesPerSector;
            DWORD NumberMediaSides;
            DWORD MediaCharacteristics;
        } DiskInfo;

        struct {
            LARGE_INTEGER Cylinders;
            STORAGE_MEDIA_TYPE MediaType;
            DWORD TracksPerCylinder;
            DWORD SectorsPerTrack;
            DWORD BytesPerSector;
            DWORD NumberMediaSides;
            DWORD MediaCharacteristics;
        } RemovableDiskInfo;

        struct {
            STORAGE_MEDIA_TYPE MediaType;
            DWORD MediaCharacteristics;
            DWORD CurrentBlockSize;
            STORAGE_BUS_TYPE BusType;





            union {
                struct {
                    BYTE MediumType;
                    BYTE DensityCode;
                } ScsiInformation;
            } BusSpecificData;

        } TapeInfo;
    } DeviceSpecific;
} DEVICE_MEDIA_INFO, *PDEVICE_MEDIA_INFO;

typedef struct _GET_MEDIA_TYPES {
    DWORD DeviceType;
    DWORD MediaInfoCount;
    DEVICE_MEDIA_INFO MediaInfo[1];
} GET_MEDIA_TYPES, *PGET_MEDIA_TYPES;
typedef struct _STORAGE_PREDICT_FAILURE
{
    DWORD PredictFailure;
    BYTE VendorSpecific[512];
} STORAGE_PREDICT_FAILURE, *PSTORAGE_PREDICT_FAILURE;
typedef enum _STORAGE_QUERY_TYPE {
    PropertyStandardQuery = 0,
    PropertyExistsQuery,
    PropertyMaskQuery,
    PropertyQueryMaxDefined
} STORAGE_QUERY_TYPE, *PSTORAGE_QUERY_TYPE;





typedef enum _STORAGE_PROPERTY_ID {
    StorageDeviceProperty = 0,
    StorageAdapterProperty,
    StorageDeviceIdProperty,
    StorageDeviceUniqueIdProperty,
    StorageDeviceWriteCacheProperty,
    StorageMiniportProperty,
    StorageAccessAlignmentProperty
} STORAGE_PROPERTY_ID, *PSTORAGE_PROPERTY_ID;






typedef struct _STORAGE_PROPERTY_QUERY {





    STORAGE_PROPERTY_ID PropertyId;





    STORAGE_QUERY_TYPE QueryType;





    BYTE AdditionalParameters[1];

} STORAGE_PROPERTY_QUERY, *PSTORAGE_PROPERTY_QUERY;






typedef   struct _STORAGE_DESCRIPTOR_HEADER {

    DWORD Version;

    DWORD Size;

} STORAGE_DESCRIPTOR_HEADER, *PSTORAGE_DESCRIPTOR_HEADER;









typedef   struct _STORAGE_DEVICE_DESCRIPTOR {





    DWORD Version;






    DWORD Size;





    BYTE DeviceType;





    BYTE DeviceTypeModifier;






    BOOLEAN RemovableMedia;







    BOOLEAN CommandQueueing;






    DWORD VendorIdOffset;






    DWORD ProductIdOffset;







    DWORD ProductRevisionOffset;






    DWORD SerialNumberOffset;







    STORAGE_BUS_TYPE BusType;






    DWORD RawPropertiesLength;





    BYTE RawDeviceProperties[1];

} STORAGE_DEVICE_DESCRIPTOR, *PSTORAGE_DEVICE_DESCRIPTOR;










typedef   struct _STORAGE_ADAPTER_DESCRIPTOR {

    DWORD Version;

    DWORD Size;

    DWORD MaximumTransferLength;

    DWORD MaximumPhysicalPages;

    DWORD AlignmentMask;

    BOOLEAN AdapterUsesPio;

    BOOLEAN AdapterScansDown;

    BOOLEAN CommandQueueing;

    BOOLEAN AcceleratedTransfer;




    BYTE BusType;


    WORD BusMajorVersion;

    WORD BusMinorVersion;

} STORAGE_ADAPTER_DESCRIPTOR, *PSTORAGE_ADAPTER_DESCRIPTOR;

typedef   struct _STORAGE_ACCESS_ALIGNMENT_DESCRIPTOR {





    DWORD Version;






    DWORD Size;





    DWORD BytesPerCacheLine;





    DWORD BytesOffsetForCacheAlignment;





    DWORD BytesPerLogicalSector;





    DWORD BytesPerPhysicalSector;





    DWORD BytesOffsetForSectorAlignment;

} STORAGE_ACCESS_ALIGNMENT_DESCRIPTOR, *PSTORAGE_ACCESS_ALIGNMENT_DESCRIPTOR;



typedef enum _STORAGE_PORT_CODE_SET {
    StoragePortCodeSetReserved = 0,
    StoragePortCodeSetStorport = 1,
    StoragePortCodeSetSCSIport = 2
} STORAGE_PORT_CODE_SET, *PSTORAGE_PORT_CODE_SET;

typedef struct _STORAGE_MINIPORT_DESCRIPTOR {

    DWORD Version;

    DWORD Size;

    STORAGE_PORT_CODE_SET Portdriver;

    BOOLEAN LUNResetSupported;

    BOOLEAN TargetResetSupported;


} STORAGE_MINIPORT_DESCRIPTOR, *PSTORAGE_MINIPORT_DESCRIPTOR;







typedef enum _STORAGE_IDENTIFIER_CODE_SET {
    StorageIdCodeSetReserved = 0,
    StorageIdCodeSetBinary = 1,
    StorageIdCodeSetAscii = 2,
    StorageIdCodeSetUtf8 = 3
} STORAGE_IDENTIFIER_CODE_SET, *PSTORAGE_IDENTIFIER_CODE_SET;

typedef enum _STORAGE_IDENTIFIER_TYPE {
    StorageIdTypeVendorSpecific = 0,
    StorageIdTypeVendorId = 1,
    StorageIdTypeEUI64 = 2,
    StorageIdTypeFCPHName = 3,
    StorageIdTypePortRelative = 4,
    StorageIdTypeTargetPortGroup = 5,
    StorageIdTypeLogicalUnitGroup = 6,
    StorageIdTypeMD5LogicalUnitIdentifier = 7,
    StorageIdTypeScsiNameString = 8
} STORAGE_IDENTIFIER_TYPE, *PSTORAGE_IDENTIFIER_TYPE;





typedef enum _STORAGE_ID_NAA_FORMAT {
        StorageIdNAAFormatIEEEExtended = 2,
        StorageIdNAAFormatIEEERegistered = 3,
        StorageIdNAAFormatIEEEERegisteredExtended = 5
} STORAGE_ID_NAA_FORMAT, *PSTORAGE_ID_NAA_FORMAT;

typedef enum _STORAGE_ASSOCIATION_TYPE {
    StorageIdAssocDevice = 0,
    StorageIdAssocPort = 1,
    StorageIdAssocTarget = 2
} STORAGE_ASSOCIATION_TYPE, *PSTORAGE_ASSOCIATION_TYPE;

typedef struct _STORAGE_IDENTIFIER {
    STORAGE_IDENTIFIER_CODE_SET CodeSet;
    STORAGE_IDENTIFIER_TYPE Type;
    WORD IdentifierSize;
    WORD NextOffset;






    STORAGE_ASSOCIATION_TYPE Association;





    BYTE Identifier[1];
} STORAGE_IDENTIFIER, *PSTORAGE_IDENTIFIER;

typedef   struct _STORAGE_DEVICE_ID_DESCRIPTOR {

    DWORD Version;

    DWORD Size;





    DWORD NumberOfIdentifiers;







    BYTE Identifiers[1];
} STORAGE_DEVICE_ID_DESCRIPTOR, *PSTORAGE_DEVICE_ID_DESCRIPTOR;
typedef struct _STORAGE_GET_BC_PROPERTIES_OUTPUT {





    DWORD MaximumRequestsPerPeriod;





    DWORD MinimumPeriod;







    DWORDLONG MaximumRequestSize;






    DWORD EstimatedTimePerRequest;








    DWORD NumOutStandingRequests;






    DWORDLONG RequestSize;

} STORAGE_GET_BC_PROPERTIES_OUTPUT, *PSTORAGE_GET_BC_PROPERTIES_OUTPUT;
typedef struct _STORAGE_ALLOCATE_BC_STREAM_INPUT {




    DWORD Version;





    DWORD RequestsPerPeriod;





    DWORD Period;





    BOOLEAN RetryFailures;





    BOOLEAN Discardable;




    BOOLEAN Reserved1[2];





    DWORD AccessType;





    DWORD AccessMode;

} STORAGE_ALLOCATE_BC_STREAM_INPUT, *PSTORAGE_ALLOCATE_BC_STREAM_INPUT;

typedef struct _STORAGE_ALLOCATE_BC_STREAM_OUTPUT {





    DWORDLONG RequestSize;






    DWORD NumOutStandingRequests;

} STORAGE_ALLOCATE_BC_STREAM_OUTPUT, *PSTORAGE_ALLOCATE_BC_STREAM_OUTPUT;
typedef struct _STORAGE_PRIORITY_HINT_SUPPORT {
    DWORD SupportFlags;
} STORAGE_PRIORITY_HINT_SUPPORT, *PSTORAGE_PRIORITY_HINT_SUPPORT;
typedef   struct _STORAGE_READ_CAPACITY {




    DWORD Version;




    DWORD Size;





    DWORD BlockLength;






    LARGE_INTEGER NumberOfBlocks;





    LARGE_INTEGER DiskLength;

} STORAGE_READ_CAPACITY, *PSTORAGE_READ_CAPACITY;








typedef enum _WRITE_CACHE_TYPE {
    WriteCacheTypeUnknown,
    WriteCacheTypeNone,
    WriteCacheTypeWriteBack,
    WriteCacheTypeWriteThrough
} WRITE_CACHE_TYPE;

typedef enum _WRITE_CACHE_ENABLE {
    WriteCacheEnableUnknown,
    WriteCacheDisabled,
    WriteCacheEnabled
} WRITE_CACHE_ENABLE;

typedef enum _WRITE_CACHE_CHANGE {
    WriteCacheChangeUnknown,
    WriteCacheNotChangeable,
    WriteCacheChangeable
} WRITE_CACHE_CHANGE;

typedef enum _WRITE_THROUGH {
    WriteThroughUnknown,
    WriteThroughNotSupported,
    WriteThroughSupported
} WRITE_THROUGH;

typedef   struct _STORAGE_WRITE_CACHE_PROPERTY {





    DWORD Version;





    DWORD Size;




    WRITE_CACHE_TYPE WriteCacheType;




    WRITE_CACHE_ENABLE WriteCacheEnabled;




    WRITE_CACHE_CHANGE WriteCacheChangeable;




    WRITE_THROUGH WriteThroughSupported;




    BOOLEAN FlushCacheSupported;




    BOOLEAN UserDefinedPowerProtection;




    BOOLEAN NVCacheEnabled;

} STORAGE_WRITE_CACHE_PROPERTY, *PSTORAGE_WRITE_CACHE_PROPERTY;
typedef enum _MEDIA_TYPE {
    Unknown,
    F5_1Pt2_512,
    F3_1Pt44_512,
    F3_2Pt88_512,
    F3_20Pt8_512,
    F3_720_512,
    F5_360_512,
    F5_320_512,
    F5_320_1024,
    F5_180_512,
    F5_160_512,
    RemovableMedia,
    FixedMedia,
    F3_120M_512,
    F3_640_512,
    F5_640_512,
    F5_720_512,
    F3_1Pt2_512,
    F3_1Pt23_1024,
    F5_1Pt23_1024,
    F3_128Mb_512,
    F3_230Mb_512,
    F8_256_128,
    F3_200Mb_512,
    F3_240M_512,
    F3_32M_512
} MEDIA_TYPE, *PMEDIA_TYPE;






typedef struct _FORMAT_PARAMETERS {
   MEDIA_TYPE MediaType;
   DWORD StartCylinderNumber;
   DWORD EndCylinderNumber;
   DWORD StartHeadNumber;
   DWORD EndHeadNumber;
} FORMAT_PARAMETERS, *PFORMAT_PARAMETERS;








typedef WORD BAD_TRACK_NUMBER;
typedef WORD *PBAD_TRACK_NUMBER;






typedef struct _FORMAT_EX_PARAMETERS {
   MEDIA_TYPE MediaType;
   DWORD StartCylinderNumber;
   DWORD EndCylinderNumber;
   DWORD StartHeadNumber;
   DWORD EndHeadNumber;
   WORD FormatGapLength;
   WORD SectorsPerTrack;
   WORD SectorNumber[1];
} FORMAT_EX_PARAMETERS, *PFORMAT_EX_PARAMETERS;







typedef struct _DISK_GEOMETRY {
    LARGE_INTEGER Cylinders;
    MEDIA_TYPE MediaType;
    DWORD TracksPerCylinder;
    DWORD SectorsPerTrack;
    DWORD BytesPerSector;
} DISK_GEOMETRY, *PDISK_GEOMETRY;
typedef struct _PARTITION_INFORMATION {
    LARGE_INTEGER StartingOffset;
    LARGE_INTEGER PartitionLength;
    DWORD HiddenSectors;
    DWORD PartitionNumber;
    BYTE PartitionType;
    BOOLEAN BootIndicator;
    BOOLEAN RecognizedPartition;
    BOOLEAN RewritePartition;
} PARTITION_INFORMATION, *PPARTITION_INFORMATION;







typedef struct _SET_PARTITION_INFORMATION {
    BYTE PartitionType;
} SET_PARTITION_INFORMATION, *PSET_PARTITION_INFORMATION;






typedef struct _DRIVE_LAYOUT_INFORMATION {
    DWORD PartitionCount;
    DWORD Signature;
    PARTITION_INFORMATION PartitionEntry[1];
} DRIVE_LAYOUT_INFORMATION, *PDRIVE_LAYOUT_INFORMATION;






typedef struct _VERIFY_INFORMATION {
    LARGE_INTEGER StartingOffset;
    DWORD Length;
} VERIFY_INFORMATION, *PVERIFY_INFORMATION;






typedef struct _REASSIGN_BLOCKS {
    WORD Reserved;
    WORD Count;
    DWORD BlockNumber[1];
} REASSIGN_BLOCKS, *PREASSIGN_BLOCKS;
typedef struct _REASSIGN_BLOCKS_EX {
    WORD Reserved;
    WORD Count;
    LARGE_INTEGER BlockNumber[1];
} REASSIGN_BLOCKS_EX, *PREASSIGN_BLOCKS_EX;
typedef enum _PARTITION_STYLE {
    PARTITION_STYLE_MBR,
    PARTITION_STYLE_GPT,
    PARTITION_STYLE_RAW
} PARTITION_STYLE;







typedef struct _PARTITION_INFORMATION_GPT {
    GUID PartitionType;
    GUID PartitionId;
    DWORD64 Attributes;
    WCHAR Name [36];
} PARTITION_INFORMATION_GPT, *PPARTITION_INFORMATION_GPT;
typedef struct _PARTITION_INFORMATION_MBR {
    BYTE PartitionType;
    BOOLEAN BootIndicator;
    BOOLEAN RecognizedPartition;
    DWORD HiddenSectors;
} PARTITION_INFORMATION_MBR, *PPARTITION_INFORMATION_MBR;










typedef SET_PARTITION_INFORMATION SET_PARTITION_INFORMATION_MBR;
typedef PARTITION_INFORMATION_GPT SET_PARTITION_INFORMATION_GPT;


typedef struct _SET_PARTITION_INFORMATION_EX {
    PARTITION_STYLE PartitionStyle;
    union {
        SET_PARTITION_INFORMATION_MBR Mbr;
        SET_PARTITION_INFORMATION_GPT Gpt;
    }  u ;
} SET_PARTITION_INFORMATION_EX, *PSET_PARTITION_INFORMATION_EX;







typedef struct _CREATE_DISK_GPT {
    GUID DiskId;
    DWORD MaxPartitionCount;
} CREATE_DISK_GPT, *PCREATE_DISK_GPT;






typedef struct _CREATE_DISK_MBR {
    DWORD Signature;
} CREATE_DISK_MBR, *PCREATE_DISK_MBR;


typedef struct _CREATE_DISK {
    PARTITION_STYLE PartitionStyle;
    union {
        CREATE_DISK_MBR Mbr;
        CREATE_DISK_GPT Gpt;
    }  u ;
} CREATE_DISK, *PCREATE_DISK;








typedef struct _GET_LENGTH_INFORMATION {
    LARGE_INTEGER Length;
} GET_LENGTH_INFORMATION, *PGET_LENGTH_INFORMATION;







typedef struct _PARTITION_INFORMATION_EX {
    PARTITION_STYLE PartitionStyle;
    LARGE_INTEGER StartingOffset;
    LARGE_INTEGER PartitionLength;
    DWORD PartitionNumber;
    BOOLEAN RewritePartition;
    union {
        PARTITION_INFORMATION_MBR Mbr;
        PARTITION_INFORMATION_GPT Gpt;
    }  u ;
} PARTITION_INFORMATION_EX, *PPARTITION_INFORMATION_EX;






typedef struct _DRIVE_LAYOUT_INFORMATION_GPT {
    GUID DiskId;
    LARGE_INTEGER StartingUsableOffset;
    LARGE_INTEGER UsableLength;
    DWORD MaxPartitionCount;
} DRIVE_LAYOUT_INFORMATION_GPT, *PDRIVE_LAYOUT_INFORMATION_GPT;






typedef struct _DRIVE_LAYOUT_INFORMATION_MBR {
    DWORD Signature;
} DRIVE_LAYOUT_INFORMATION_MBR, *PDRIVE_LAYOUT_INFORMATION_MBR;






typedef struct _DRIVE_LAYOUT_INFORMATION_EX {
    DWORD PartitionStyle;
    DWORD PartitionCount;
    union {
        DRIVE_LAYOUT_INFORMATION_MBR Mbr;
        DRIVE_LAYOUT_INFORMATION_GPT Gpt;
    }  u ;
    PARTITION_INFORMATION_EX PartitionEntry[1];
} DRIVE_LAYOUT_INFORMATION_EX, *PDRIVE_LAYOUT_INFORMATION_EX;
typedef enum _DETECTION_TYPE {
        DetectNone,
        DetectInt13,
        DetectExInt13
} DETECTION_TYPE;

typedef struct _DISK_INT13_INFO {
        WORD DriveSelect;
        DWORD MaxCylinders;
        WORD SectorsPerTrack;
        WORD MaxHeads;
        WORD NumberDrives;
} DISK_INT13_INFO, *PDISK_INT13_INFO;

typedef struct _DISK_EX_INT13_INFO {
        WORD ExBufferSize;
        WORD ExFlags;
        DWORD ExCylinders;
        DWORD ExHeads;
        DWORD ExSectorsPerTrack;
        DWORD64 ExSectorsPerDrive;
        WORD ExSectorSize;
        WORD ExReserved;
} DISK_EX_INT13_INFO, *PDISK_EX_INT13_INFO;

typedef struct _DISK_DETECTION_INFO {
        DWORD SizeOfDetectInfo;
        DETECTION_TYPE DetectionType;
        union {
                struct {






                        DISK_INT13_INFO Int13;






                        DISK_EX_INT13_INFO ExInt13;
                }  s ;
        }  u ;
} DISK_DETECTION_INFO, *PDISK_DETECTION_INFO;


typedef struct _DISK_PARTITION_INFO {
        DWORD SizeOfPartitionInfo;
        PARTITION_STYLE PartitionStyle;
        union {
                struct {
                        DWORD Signature;
                        DWORD CheckSum;
                } Mbr;
                struct {
                        GUID DiskId;
                } Gpt;
        }  u ;
} DISK_PARTITION_INFO, *PDISK_PARTITION_INFO;
typedef struct _DISK_GEOMETRY_EX {
        DISK_GEOMETRY Geometry;
        LARGE_INTEGER DiskSize;
        BYTE Data[1];
} DISK_GEOMETRY_EX, *PDISK_GEOMETRY_EX;










typedef struct _DISK_CONTROLLER_NUMBER {
    DWORD ControllerNumber;
    DWORD DiskNumber;
} DISK_CONTROLLER_NUMBER, *PDISK_CONTROLLER_NUMBER;
typedef enum {
    EqualPriority,
    KeepPrefetchedData,
    KeepReadData
} DISK_CACHE_RETENTION_PRIORITY;
typedef struct _DISK_CACHE_INFORMATION {







    BOOLEAN ParametersSavable;





    BOOLEAN ReadCacheEnabled;
    BOOLEAN WriteCacheEnabled;








    DISK_CACHE_RETENTION_PRIORITY ReadRetentionPriority;
    DISK_CACHE_RETENTION_PRIORITY WriteRetentionPriority;






    WORD DisablePrefetchTransferLength;







    BOOLEAN PrefetchScalar;









    union {
        struct {
            WORD Minimum;
            WORD Maximum;






            WORD MaximumBlocks;
        } ScalarPrefetch;

        struct {
            WORD Minimum;
            WORD Maximum;
        } BlockPrefetch;
    }  u ;

} DISK_CACHE_INFORMATION, *PDISK_CACHE_INFORMATION;







typedef struct _DISK_GROW_PARTITION {
    DWORD PartitionNumber;
    LARGE_INTEGER BytesToGrow;
} DISK_GROW_PARTITION, *PDISK_GROW_PARTITION;
typedef struct _HISTOGRAM_BUCKET {
    DWORD Reads;
    DWORD Writes;
} HISTOGRAM_BUCKET, *PHISTOGRAM_BUCKET;



typedef struct _DISK_HISTOGRAM {
    LARGE_INTEGER DiskSize;
    LARGE_INTEGER Start;
    LARGE_INTEGER End;
    LARGE_INTEGER Average;
    LARGE_INTEGER AverageRead;
    LARGE_INTEGER AverageWrite;
    DWORD Granularity;
    DWORD Size;
    DWORD ReadCount;
    DWORD WriteCount;
    PHISTOGRAM_BUCKET Histogram;
} DISK_HISTOGRAM, *PDISK_HISTOGRAM;
typedef struct _DISK_PERFORMANCE {
        LARGE_INTEGER BytesRead;
        LARGE_INTEGER BytesWritten;
        LARGE_INTEGER ReadTime;
        LARGE_INTEGER WriteTime;
        LARGE_INTEGER IdleTime;
        DWORD ReadCount;
        DWORD WriteCount;
        DWORD QueueDepth;
        DWORD SplitCount;
        LARGE_INTEGER QueryTime;
        DWORD StorageDeviceNumber;
        WCHAR StorageManagerName[8];
} DISK_PERFORMANCE, *PDISK_PERFORMANCE;







typedef struct _DISK_RECORD {
   LARGE_INTEGER ByteOffset;
   LARGE_INTEGER StartTime;
   LARGE_INTEGER EndTime;
   PVOID VirtualAddress;
   DWORD NumberOfBytes;
   BYTE DeviceNumber;
   BOOLEAN ReadRequest;
} DISK_RECORD, *PDISK_RECORD;






typedef struct _DISK_LOGGING {
    BYTE Function;
    PVOID BufferAddress;
    DWORD BufferSize;
} DISK_LOGGING, *PDISK_LOGGING;
typedef enum _BIN_TYPES {
    RequestSize,
    RequestLocation
} BIN_TYPES;





typedef struct _BIN_RANGE {
    LARGE_INTEGER StartValue;
    LARGE_INTEGER Length;
} BIN_RANGE, *PBIN_RANGE;





typedef struct _PERF_BIN {
    DWORD NumberOfBins;
    DWORD TypeOfBin;
    BIN_RANGE BinsRanges[1];
} PERF_BIN, *PPERF_BIN ;





typedef struct _BIN_COUNT {
    BIN_RANGE BinRange;
    DWORD BinCount;
} BIN_COUNT, *PBIN_COUNT;





typedef struct _BIN_RESULTS {
    DWORD NumberOfBins;
    BIN_COUNT BinCounts[1];
} BIN_RESULTS, *PBIN_RESULTS;
typedef struct _GETVERSIONINPARAMS {
        BYTE bVersion;
        BYTE bRevision;
        BYTE bReserved;
        BYTE bIDEDeviceMap;
        DWORD fCapabilities;
        DWORD dwReserved[4];
} GETVERSIONINPARAMS, *PGETVERSIONINPARAMS, *LPGETVERSIONINPARAMS;
typedef struct _IDEREGS {
        BYTE bFeaturesReg;
        BYTE bSectorCountReg;
        BYTE bSectorNumberReg;
        BYTE bCylLowReg;
        BYTE bCylHighReg;
        BYTE bDriveHeadReg;
        BYTE bCommandReg;
        BYTE bReserved;
} IDEREGS, *PIDEREGS, *LPIDEREGS;
typedef struct _SENDCMDINPARAMS {
        DWORD cBufferSize;
        IDEREGS irDriveRegs;
        BYTE bDriveNumber;

        BYTE bReserved[3];
        DWORD dwReserved[4];
        BYTE bBuffer[1];
} SENDCMDINPARAMS, *PSENDCMDINPARAMS, *LPSENDCMDINPARAMS;
typedef struct _DRIVERSTATUS {
        BYTE bDriverError;

        BYTE bIDEError;


        BYTE bReserved[2];
        DWORD dwReserved[2];
} DRIVERSTATUS, *PDRIVERSTATUS, *LPDRIVERSTATUS;
typedef struct _SENDCMDOUTPARAMS {
        DWORD cBufferSize;
        DRIVERSTATUS DriverStatus;
        BYTE bBuffer[1];
} SENDCMDOUTPARAMS, *PSENDCMDOUTPARAMS, *LPSENDCMDOUTPARAMS;
typedef enum _ELEMENT_TYPE {
    AllElements,
    ChangerTransport,
    ChangerSlot,
    ChangerIEPort,
    ChangerDrive,
    ChangerDoor,
    ChangerKeypad,
    ChangerMaxElement
} ELEMENT_TYPE, *PELEMENT_TYPE;

typedef struct _CHANGER_ELEMENT {
    ELEMENT_TYPE ElementType;
    DWORD ElementAddress;
} CHANGER_ELEMENT, *PCHANGER_ELEMENT;

typedef struct _CHANGER_ELEMENT_LIST {
    CHANGER_ELEMENT Element;
    DWORD NumberOfElements;
} CHANGER_ELEMENT_LIST , *PCHANGER_ELEMENT_LIST;
typedef struct _GET_CHANGER_PARAMETERS {





    DWORD Size;





    WORD NumberTransportElements;
    WORD NumberStorageElements;
    WORD NumberCleanerSlots;
    WORD NumberIEElements;
    WORD NumberDataTransferElements;





    WORD NumberOfDoors;






    WORD FirstSlotNumber;
    WORD FirstDriveNumber;
    WORD FirstTransportNumber;
    WORD FirstIEPortNumber;
    WORD FirstCleanerSlotAddress;





    WORD MagazineSize;






    DWORD DriveCleanTimeout;





    DWORD Features0;
    DWORD Features1;






    BYTE MoveFromTransport;
    BYTE MoveFromSlot;
    BYTE MoveFromIePort;
    BYTE MoveFromDrive;






    BYTE ExchangeFromTransport;
    BYTE ExchangeFromSlot;
    BYTE ExchangeFromIePort;
    BYTE ExchangeFromDrive;






    BYTE LockUnlockCapabilities;






    BYTE PositionCapabilities;





    BYTE Reserved1[2];
    DWORD Reserved2[2];

} GET_CHANGER_PARAMETERS, * PGET_CHANGER_PARAMETERS;






typedef struct _CHANGER_PRODUCT_DATA {





    BYTE VendorId[ 8 ];





    BYTE ProductId[ 16 ];





    BYTE Revision[ 4 ];






    BYTE SerialNumber[ 32 ];





    BYTE DeviceType;

} CHANGER_PRODUCT_DATA, *PCHANGER_PRODUCT_DATA;
typedef struct _CHANGER_SET_ACCESS {





    CHANGER_ELEMENT Element;





    DWORD Control;
} CHANGER_SET_ACCESS, *PCHANGER_SET_ACCESS;










typedef struct _CHANGER_READ_ELEMENT_STATUS {





    CHANGER_ELEMENT_LIST ElementList;





    BOOLEAN VolumeTagInfo;
} CHANGER_READ_ELEMENT_STATUS, *PCHANGER_READ_ELEMENT_STATUS;





typedef struct _CHANGER_ELEMENT_STATUS {





    CHANGER_ELEMENT Element;







    CHANGER_ELEMENT SrcElementAddress;





    DWORD Flags;





    DWORD ExceptionCode;






    BYTE TargetId;






    BYTE Lun;
    WORD Reserved;






    BYTE PrimaryVolumeID[ 36 ];







    BYTE AlternateVolumeID[ 36 ];

} CHANGER_ELEMENT_STATUS, *PCHANGER_ELEMENT_STATUS;







typedef struct _CHANGER_ELEMENT_STATUS_EX {





    CHANGER_ELEMENT Element;







    CHANGER_ELEMENT SrcElementAddress;





    DWORD Flags;





    DWORD ExceptionCode;






    BYTE TargetId;






    BYTE Lun;
    WORD Reserved;






    BYTE PrimaryVolumeID[ 36 ];







    BYTE AlternateVolumeID[ 36 ];




    BYTE VendorIdentification[ 8 ];




    BYTE ProductIdentification[ 16 ];




    BYTE SerialNumber[ 32 ];

} CHANGER_ELEMENT_STATUS_EX, *PCHANGER_ELEMENT_STATUS_EX;
typedef struct _CHANGER_INITIALIZE_ELEMENT_STATUS {





    CHANGER_ELEMENT_LIST ElementList;






    BOOLEAN BarCodeScan;
} CHANGER_INITIALIZE_ELEMENT_STATUS, *PCHANGER_INITIALIZE_ELEMENT_STATUS;






typedef struct _CHANGER_SET_POSITION {






    CHANGER_ELEMENT Transport;





    CHANGER_ELEMENT Destination;





    BOOLEAN Flip;
} CHANGER_SET_POSITION, *PCHANGER_SET_POSITION;






typedef struct _CHANGER_EXCHANGE_MEDIUM {





    CHANGER_ELEMENT Transport;





    CHANGER_ELEMENT Source;





    CHANGER_ELEMENT Destination1;





    CHANGER_ELEMENT Destination2;





    BOOLEAN Flip1;
    BOOLEAN Flip2;
} CHANGER_EXCHANGE_MEDIUM, *PCHANGER_EXCHANGE_MEDIUM;






typedef struct _CHANGER_MOVE_MEDIUM {





    CHANGER_ELEMENT Transport;





    CHANGER_ELEMENT Source;





    CHANGER_ELEMENT Destination;





    BOOLEAN Flip;
} CHANGER_MOVE_MEDIUM, *PCHANGER_MOVE_MEDIUM;
typedef struct _CHANGER_SEND_VOLUME_TAG_INFORMATION {





    CHANGER_ELEMENT StartingElement;





    DWORD ActionCode;





    BYTE VolumeIDTemplate[ 40 ];
} CHANGER_SEND_VOLUME_TAG_INFORMATION, *PCHANGER_SEND_VOLUME_TAG_INFORMATION;






typedef struct _READ_ELEMENT_ADDRESS_INFO {





    DWORD NumberOfElements;






    CHANGER_ELEMENT_STATUS ElementStatus[1];
} READ_ELEMENT_ADDRESS_INFO, *PREAD_ELEMENT_ADDRESS_INFO;
typedef enum _CHANGER_DEVICE_PROBLEM_TYPE {
   DeviceProblemNone,
   DeviceProblemHardware,
   DeviceProblemCHMError,
   DeviceProblemDoorOpen,
   DeviceProblemCalibrationError,
   DeviceProblemTargetFailure,
   DeviceProblemCHMMoveError,
   DeviceProblemCHMZeroError,
   DeviceProblemCartridgeInsertError,
   DeviceProblemPositionError,
   DeviceProblemSensorError,
   DeviceProblemCartridgeEjectError,
   DeviceProblemGripperError,
   DeviceProblemDriveError
} CHANGER_DEVICE_PROBLEM_TYPE, *PCHANGER_DEVICE_PROBLEM_TYPE;
typedef struct _PATHNAME_BUFFER {

    DWORD PathNameLength;
    WCHAR Name[1];

} PATHNAME_BUFFER, *PPATHNAME_BUFFER;





typedef struct _FSCTL_QUERY_FAT_BPB_BUFFER {

    BYTE First0x24BytesOfBootSector[0x24];

} FSCTL_QUERY_FAT_BPB_BUFFER, *PFSCTL_QUERY_FAT_BPB_BUFFER;









typedef struct {

    LARGE_INTEGER VolumeSerialNumber;
    LARGE_INTEGER NumberSectors;
    LARGE_INTEGER TotalClusters;
    LARGE_INTEGER FreeClusters;
    LARGE_INTEGER TotalReserved;
    DWORD BytesPerSector;
    DWORD BytesPerCluster;
    DWORD BytesPerFileRecordSegment;
    DWORD ClustersPerFileRecordSegment;
    LARGE_INTEGER MftValidDataLength;
    LARGE_INTEGER MftStartLcn;
    LARGE_INTEGER Mft2StartLcn;
    LARGE_INTEGER MftZoneStart;
    LARGE_INTEGER MftZoneEnd;

} NTFS_VOLUME_DATA_BUFFER, *PNTFS_VOLUME_DATA_BUFFER;

typedef struct {

    DWORD ByteCount;

    WORD MajorVersion;
    WORD MinorVersion;

} NTFS_EXTENDED_VOLUME_DATA, *PNTFS_EXTENDED_VOLUME_DATA;







typedef struct {

    LARGE_INTEGER StartingLcn;

} STARTING_LCN_INPUT_BUFFER, *PSTARTING_LCN_INPUT_BUFFER;

typedef struct {

    LARGE_INTEGER StartingLcn;
    LARGE_INTEGER BitmapSize;
    BYTE Buffer[1];

} VOLUME_BITMAP_BUFFER, *PVOLUME_BITMAP_BUFFER;







typedef struct {

    LARGE_INTEGER StartingVcn;

} STARTING_VCN_INPUT_BUFFER, *PSTARTING_VCN_INPUT_BUFFER;

typedef struct RETRIEVAL_POINTERS_BUFFER {

    DWORD ExtentCount;
    LARGE_INTEGER StartingVcn;
    struct {
        LARGE_INTEGER NextVcn;
        LARGE_INTEGER Lcn;
    } Extents[1];

} RETRIEVAL_POINTERS_BUFFER, *PRETRIEVAL_POINTERS_BUFFER;







typedef struct {

    LARGE_INTEGER FileReferenceNumber;

} NTFS_FILE_RECORD_INPUT_BUFFER, *PNTFS_FILE_RECORD_INPUT_BUFFER;

typedef struct {

    LARGE_INTEGER FileReferenceNumber;
    DWORD FileRecordLength;
    BYTE FileRecordBuffer[1];

} NTFS_FILE_RECORD_OUTPUT_BUFFER, *PNTFS_FILE_RECORD_OUTPUT_BUFFER;







typedef struct {

    HANDLE FileHandle;
    LARGE_INTEGER StartingVcn;
    LARGE_INTEGER StartingLcn;
    DWORD ClusterCount;

} MOVE_FILE_DATA, *PMOVE_FILE_DATA;

typedef struct {

    HANDLE FileHandle;
    LARGE_INTEGER SourceFileRecord;
    LARGE_INTEGER TargetFileRecord;

} MOVE_FILE_RECORD_DATA, *PMOVE_FILE_RECORD_DATA;
typedef struct {
    DWORD Restart;
    SID Sid;
} FIND_BY_SID_DATA, *PFIND_BY_SID_DATA;

typedef struct {
    DWORD NextEntryOffset;
    DWORD FileIndex;
    DWORD FileNameLength;
    WCHAR FileName[1];
} FIND_BY_SID_OUTPUT, *PFIND_BY_SID_OUTPUT;
typedef struct {

    DWORDLONG StartFileReferenceNumber;
    USN LowUsn;
    USN HighUsn;

} MFT_ENUM_DATA, *PMFT_ENUM_DATA;





typedef struct {

    DWORDLONG MaximumSize;
    DWORDLONG AllocationDelta;

} CREATE_USN_JOURNAL_DATA, *PCREATE_USN_JOURNAL_DATA;





typedef struct {

    USN StartUsn;
    DWORD ReasonMask;
    DWORD ReturnOnlyOnClose;
    DWORDLONG Timeout;
    DWORDLONG BytesToWaitFor;
    DWORDLONG UsnJournalID;

} READ_USN_JOURNAL_DATA, *PREAD_USN_JOURNAL_DATA;
typedef struct {

    DWORD RecordLength;
    WORD MajorVersion;
    WORD MinorVersion;
    DWORDLONG FileReferenceNumber;
    DWORDLONG ParentFileReferenceNumber;
    USN Usn;
    LARGE_INTEGER TimeStamp;
    DWORD Reason;
    DWORD SourceInfo;
    DWORD SecurityId;
    DWORD FileAttributes;
    WORD FileNameLength;
    WORD FileNameOffset;
    WCHAR FileName[1];

} USN_RECORD, *PUSN_RECORD;
typedef struct {

    DWORDLONG UsnJournalID;
    USN FirstUsn;
    USN NextUsn;
    USN LowestValidUsn;
    USN MaxUsn;
    DWORDLONG MaximumSize;
    DWORDLONG AllocationDelta;

} USN_JOURNAL_DATA, *PUSN_JOURNAL_DATA;





typedef struct {

    DWORDLONG UsnJournalID;
    DWORD DeleteFlags;

} DELETE_USN_JOURNAL_DATA, *PDELETE_USN_JOURNAL_DATA;










typedef struct {

    DWORD UsnSourceInfo;
    HANDLE VolumeHandle;
    DWORD HandleInfo;

} MARK_HANDLE_INFO, *PMARK_HANDLE_INFO;
typedef struct {

    ACCESS_MASK DesiredAccess;
    DWORD SecurityIds[1];

} BULK_SECURITY_TEST_DATA, *PBULK_SECURITY_TEST_DATA;
typedef struct _FILE_PREFETCH {
    DWORD Type;
    DWORD Count;
    DWORDLONG Prefetch[1];
} FILE_PREFETCH, *PFILE_PREFETCH;

typedef struct _FILE_PREFETCH_EX {
    DWORD Type;
    DWORD Count;
    PVOID Context;
    DWORDLONG Prefetch[1];
} FILE_PREFETCH_EX, *PFILE_PREFETCH_EX;
typedef struct _VOLUME_COMPRESSION_STATE {
    BOOLEAN CompressNewFiles;
} VOLUME_COMPRESSION_STATE, *PVOLUME_COMPRESSION_STATE;







typedef struct _FILESYSTEM_STATISTICS {

    WORD FileSystemType;
    WORD Version;

    DWORD SizeOfCompleteStructure;

    DWORD UserFileReads;
    DWORD UserFileReadBytes;
    DWORD UserDiskReads;
    DWORD UserFileWrites;
    DWORD UserFileWriteBytes;
    DWORD UserDiskWrites;

    DWORD MetaDataReads;
    DWORD MetaDataReadBytes;
    DWORD MetaDataDiskReads;
    DWORD MetaDataWrites;
    DWORD MetaDataWriteBytes;
    DWORD MetaDataDiskWrites;





} FILESYSTEM_STATISTICS, *PFILESYSTEM_STATISTICS;
typedef struct _FAT_STATISTICS {
    DWORD CreateHits;
    DWORD SuccessfulCreates;
    DWORD FailedCreates;

    DWORD NonCachedReads;
    DWORD NonCachedReadBytes;
    DWORD NonCachedWrites;
    DWORD NonCachedWriteBytes;

    DWORD NonCachedDiskReads;
    DWORD NonCachedDiskWrites;
} FAT_STATISTICS, *PFAT_STATISTICS;

typedef struct _EXFAT_STATISTICS {
    DWORD CreateHits;
    DWORD SuccessfulCreates;
    DWORD FailedCreates;

    DWORD NonCachedReads;
    DWORD NonCachedReadBytes;
    DWORD NonCachedWrites;
    DWORD NonCachedWriteBytes;

    DWORD NonCachedDiskReads;
    DWORD NonCachedDiskWrites;
} EXFAT_STATISTICS, *PEXFAT_STATISTICS;

typedef struct _NTFS_STATISTICS {

    DWORD LogFileFullExceptions;
    DWORD OtherExceptions;





    DWORD MftReads;
    DWORD MftReadBytes;
    DWORD MftWrites;
    DWORD MftWriteBytes;
    struct {
        WORD Write;
        WORD Create;
        WORD SetInfo;
        WORD Flush;
    } MftWritesUserLevel;

    WORD MftWritesFlushForLogFileFull;
    WORD MftWritesLazyWriter;
    WORD MftWritesUserRequest;

    DWORD Mft2Writes;
    DWORD Mft2WriteBytes;
    struct {
        WORD Write;
        WORD Create;
        WORD SetInfo;
        WORD Flush;
    } Mft2WritesUserLevel;

    WORD Mft2WritesFlushForLogFileFull;
    WORD Mft2WritesLazyWriter;
    WORD Mft2WritesUserRequest;

    DWORD RootIndexReads;
    DWORD RootIndexReadBytes;
    DWORD RootIndexWrites;
    DWORD RootIndexWriteBytes;

    DWORD BitmapReads;
    DWORD BitmapReadBytes;
    DWORD BitmapWrites;
    DWORD BitmapWriteBytes;

    WORD BitmapWritesFlushForLogFileFull;
    WORD BitmapWritesLazyWriter;
    WORD BitmapWritesUserRequest;

    struct {
        WORD Write;
        WORD Create;
        WORD SetInfo;
    } BitmapWritesUserLevel;

    DWORD MftBitmapReads;
    DWORD MftBitmapReadBytes;
    DWORD MftBitmapWrites;
    DWORD MftBitmapWriteBytes;

    WORD MftBitmapWritesFlushForLogFileFull;
    WORD MftBitmapWritesLazyWriter;
    WORD MftBitmapWritesUserRequest;

    struct {
        WORD Write;
        WORD Create;
        WORD SetInfo;
        WORD Flush;
    } MftBitmapWritesUserLevel;

    DWORD UserIndexReads;
    DWORD UserIndexReadBytes;
    DWORD UserIndexWrites;
    DWORD UserIndexWriteBytes;





    DWORD LogFileReads;
    DWORD LogFileReadBytes;
    DWORD LogFileWrites;
    DWORD LogFileWriteBytes;

    struct {
        DWORD Calls;
        DWORD Clusters;
        DWORD Hints;

        DWORD RunsReturned;

        DWORD HintsHonored;
        DWORD HintsClusters;
        DWORD Cache;
        DWORD CacheClusters;
        DWORD CacheMiss;
        DWORD CacheMissClusters;
    } Allocate;

} NTFS_STATISTICS, *PNTFS_STATISTICS;

typedef struct _FILE_OBJECTID_BUFFER {





    BYTE ObjectId[16];






    union {
        struct {
            BYTE BirthVolumeId[16];
            BYTE BirthObjectId[16];
            BYTE DomainId[16];
        }  s ;
        BYTE ExtendedInfo[48];
    }  u ;

} FILE_OBJECTID_BUFFER, *PFILE_OBJECTID_BUFFER;










typedef struct _FILE_SET_SPARSE_BUFFER {
    BOOLEAN SetSparse;
} FILE_SET_SPARSE_BUFFER, *PFILE_SET_SPARSE_BUFFER;










typedef struct _FILE_ZERO_DATA_INFORMATION {

    LARGE_INTEGER FileOffset;
    LARGE_INTEGER BeyondFinalZero;

} FILE_ZERO_DATA_INFORMATION, *PFILE_ZERO_DATA_INFORMATION;
typedef struct _FILE_ALLOCATED_RANGE_BUFFER {

    LARGE_INTEGER FileOffset;
    LARGE_INTEGER Length;

} FILE_ALLOCATED_RANGE_BUFFER, *PFILE_ALLOCATED_RANGE_BUFFER;
typedef struct _ENCRYPTION_BUFFER {

    DWORD EncryptionOperation;
    BYTE Private[1];

} ENCRYPTION_BUFFER, *PENCRYPTION_BUFFER;
typedef struct _DECRYPTION_STATUS_BUFFER {

    BOOLEAN NoEncryptedStreams;

} DECRYPTION_STATUS_BUFFER, *PDECRYPTION_STATUS_BUFFER;
typedef struct _REQUEST_RAW_ENCRYPTED_DATA {








    LONGLONG FileOffset;
    DWORD Length;

} REQUEST_RAW_ENCRYPTED_DATA, *PREQUEST_RAW_ENCRYPTED_DATA;
typedef struct _ENCRYPTED_DATA_INFO {








    DWORDLONG StartingFileOffset;









    DWORD OutputBufferOffset;










    DWORD BytesWithinFileSize;










    DWORD BytesWithinValidDataLength;








    WORD CompressionFormat;
    BYTE DataUnitShift;
    BYTE ChunkShift;
    BYTE ClusterShift;





    BYTE EncryptionFormat;






    WORD NumberOfDataBlocks;
    DWORD DataBlockSize[ 1 ];

} ENCRYPTED_DATA_INFO;
typedef ENCRYPTED_DATA_INFO *PENCRYPTED_DATA_INFO;










typedef struct _PLEX_READ_DATA_REQUEST {
    LARGE_INTEGER ByteOffset;
    DWORD ByteLength;
    DWORD PlexNumber;

} PLEX_READ_DATA_REQUEST, *PPLEX_READ_DATA_REQUEST;
typedef struct _SI_COPYFILE {
    DWORD SourceFileNameLength;
    DWORD DestinationFileNameLength;
    DWORD Flags;
    WCHAR FileNameBuffer[1];
} SI_COPYFILE, *PSI_COPYFILE;
typedef struct _FILE_MAKE_COMPATIBLE_BUFFER {
    BOOLEAN CloseDisc;
} FILE_MAKE_COMPATIBLE_BUFFER, *PFILE_MAKE_COMPATIBLE_BUFFER;





typedef struct _FILE_SET_DEFECT_MGMT_BUFFER {
    BOOLEAN Disable;
} FILE_SET_DEFECT_MGMT_BUFFER, *PFILE_SET_DEFECT_MGMT_BUFFER;





typedef struct _FILE_QUERY_SPARING_BUFFER {
    DWORD SparingUnitBytes;
    BOOLEAN SoftwareSparing;
    DWORD TotalSpareBlocks;
    DWORD FreeSpareBlocks;
} FILE_QUERY_SPARING_BUFFER, *PFILE_QUERY_SPARING_BUFFER;





typedef struct _FILE_QUERY_ON_DISK_VOL_INFO_BUFFER {
    LARGE_INTEGER DirectoryCount;
    LARGE_INTEGER FileCount;
    WORD FsFormatMajVersion;
    WORD FsFormatMinVersion;
    WCHAR FsFormatName[ 12];
    LARGE_INTEGER FormatTime;
    LARGE_INTEGER LastUpdateTime;
    WCHAR CopyrightInfo[ 34];
    WCHAR AbstractInfo[ 34];
    WCHAR FormattingImplementationInfo[ 34];
    WCHAR LastModifyingImplementationInfo[ 34];
} FILE_QUERY_ON_DISK_VOL_INFO_BUFFER, *PFILE_QUERY_ON_DISK_VOL_INFO_BUFFER;
typedef enum _SHRINK_VOLUME_REQUEST_TYPES
{
    ShrinkPrepare = 1,
    ShrinkCommit,
    ShrinkAbort

} SHRINK_VOLUME_REQUEST_TYPES, *PSHRINK_VOLUME_REQUEST_TYPES;



typedef struct _SHRINK_VOLUME_INFORMATION
{
    SHRINK_VOLUME_REQUEST_TYPES ShrinkRequestType;
    DWORDLONG Flags;
    LONGLONG NewNumberOfSectors;

} SHRINK_VOLUME_INFORMATION, *PSHRINK_VOLUME_INFORMATION;
typedef struct _TXFS_MODIFY_RM {





    DWORD Flags;





    DWORD LogContainerCountMax;





    DWORD LogContainerCountMin;





    DWORD LogContainerCount;







    DWORD LogGrowthIncrement;






    DWORD LogAutoShrinkPercentage;





    DWORDLONG Reserved;






    WORD LoggingMode;

} TXFS_MODIFY_RM,
 *PTXFS_MODIFY_RM;
typedef struct _TXFS_QUERY_RM_INFORMATION {






    DWORD BytesRequired;





    DWORDLONG TailLsn;





    DWORDLONG CurrentLsn;





    DWORDLONG ArchiveTailLsn;





    DWORDLONG LogContainerSize;





    LARGE_INTEGER HighestVirtualClock;





    DWORD LogContainerCount;





    DWORD LogContainerCountMax;





    DWORD LogContainerCountMin;







    DWORD LogGrowthIncrement;







    DWORD LogAutoShrinkPercentage;






    DWORD Flags;





    WORD LoggingMode;





    WORD Reserved;





    DWORD RmState;





    DWORDLONG LogCapacity;





    DWORDLONG LogFree;





    DWORDLONG TopsSize;





    DWORDLONG TopsUsed;





    DWORDLONG TransactionCount;





    DWORDLONG OnePCCount;





    DWORDLONG TwoPCCount;





    DWORDLONG NumberLogFileFull;





    DWORDLONG OldestTransactionAge;





    GUID RMName;






    DWORD TmLogPathOffset;

} TXFS_QUERY_RM_INFORMATION,
 *PTXFS_QUERY_RM_INFORMATION;
typedef struct _TXFS_ROLLFORWARD_REDO_INFORMATION {
    LARGE_INTEGER LastVirtualClock;
    DWORDLONG LastRedoLsn;
    DWORDLONG HighestRecoveryLsn;
    DWORD Flags;
} TXFS_ROLLFORWARD_REDO_INFORMATION,
 *PTXFS_ROLLFORWARD_REDO_INFORMATION;
typedef struct _TXFS_START_RM_INFORMATION {





    DWORD Flags;





    DWORDLONG LogContainerSize;





    DWORD LogContainerCountMin;





    DWORD LogContainerCountMax;







    DWORD LogGrowthIncrement;





    DWORD LogAutoShrinkPercentage;







    DWORD TmLogPathOffset;






    WORD TmLogPathLength;







    WORD LoggingMode;






    WORD LogPathLength;





    WORD Reserved;






    WCHAR LogPath[1];

} TXFS_START_RM_INFORMATION,
 *PTXFS_START_RM_INFORMATION;





typedef struct _TXFS_GET_METADATA_INFO_OUT {





    struct {
        LONGLONG LowPart;
        LONGLONG HighPart;
    } TxfFileId;





    GUID LockingTransaction;





    DWORDLONG LastLsn;





    DWORD TransactionState;

} TXFS_GET_METADATA_INFO_OUT, *PTXFS_GET_METADATA_INFO_OUT;





typedef struct _TXFS_LIST_TRANSACTION_LOCKED_FILES_ENTRY {






    DWORDLONG Offset;





    DWORD UsnReason;





    LONGLONG FileId;





    DWORD Reserved1;
    DWORD Reserved2;
    LONGLONG Reserved3;





    WCHAR FileName[1];
} TXFS_LIST_TRANSACTION_LOCKED_FILES_ENTRY, *PTXFS_LIST_TRANSACTION_LOCKED_FILES_ENTRY;


typedef struct _TXFS_LIST_TRANSACTION_LOCKED_FILES {





    GUID KtmTransaction;





    DWORDLONG NumberOfFiles;






    DWORDLONG BufferSizeRequired;






    DWORDLONG Offset;
} TXFS_LIST_TRANSACTION_LOCKED_FILES, *PTXFS_LIST_TRANSACTION_LOCKED_FILES;





typedef struct _TXFS_LIST_TRANSACTIONS_ENTRY {





    GUID TransactionId;





    DWORD TransactionState;





    DWORD Reserved1;
    DWORD Reserved2;
    LONGLONG Reserved3;
} TXFS_LIST_TRANSACTIONS_ENTRY, *PTXFS_LIST_TRANSACTIONS_ENTRY;

typedef struct _TXFS_LIST_TRANSACTIONS {





    DWORDLONG NumberOfTransactions;







    DWORDLONG BufferSizeRequired;
} TXFS_LIST_TRANSACTIONS, *PTXFS_LIST_TRANSACTIONS;






typedef struct _TXFS_READ_BACKUP_INFORMATION_OUT {
    union {





        DWORD BufferLength;





        BYTE Buffer[1];
    }  u ;
} TXFS_READ_BACKUP_INFORMATION_OUT, *PTXFS_READ_BACKUP_INFORMATION_OUT;





typedef struct _TXFS_WRITE_BACKUP_INFORMATION {






    BYTE Buffer[1];
} TXFS_WRITE_BACKUP_INFORMATION, *PTXFS_WRITE_BACKUP_INFORMATION;








typedef struct _TXFS_GET_TRANSACTED_VERSION {







    DWORD ThisBaseVersion;





    DWORD LatestVersion;






    WORD ThisMiniVersion;






    WORD FirstMiniVersion;






    WORD LatestMiniVersion;

} TXFS_GET_TRANSACTED_VERSION, *PTXFS_GET_TRANSACTED_VERSION;
typedef struct _TXFS_SAVEPOINT_INFORMATION {





    HANDLE KtmTransaction;





    DWORD ActionCode;
    DWORD SavepointId;

} TXFS_SAVEPOINT_INFORMATION, *PTXFS_SAVEPOINT_INFORMATION;







typedef struct _TXFS_CREATE_MINIVERSION_INFO {

    WORD StructureVersion;

    WORD StructureLength;





    DWORD BaseVersion;





    WORD MiniVersion;

} TXFS_CREATE_MINIVERSION_INFO, *PTXFS_CREATE_MINIVERSION_INFO;





typedef struct _TXFS_TRANSACTION_ACTIVE_INFO {





    BOOLEAN TransactionsActiveAtSnapshot;

} TXFS_TRANSACTION_ACTIVE_INFO, *PTXFS_TRANSACTION_ACTIVE_INFO;
typedef struct _DISK_EXTENT {





    DWORD DiskNumber;






    LARGE_INTEGER StartingOffset;
    LARGE_INTEGER ExtentLength;

} DISK_EXTENT, *PDISK_EXTENT;

typedef struct _VOLUME_DISK_EXTENTS {





    DWORD NumberOfDiskExtents;
    DISK_EXTENT Extents[ 1 ];

} VOLUME_DISK_EXTENTS, *PVOLUME_DISK_EXTENTS;
typedef DWORD ULONG;
typedef WORD UWORD;
typedef BYTE UCHAR;
typedef struct _SCARD_IO_REQUEST{
    DWORD dwProtocol;
    DWORD cbPciLength;
} SCARD_IO_REQUEST, *PSCARD_IO_REQUEST, *LPSCARD_IO_REQUEST;
typedef const SCARD_IO_REQUEST *LPCSCARD_IO_REQUEST;






typedef struct {
    BYTE
        bCla,
        bIns,
        bP1,
        bP2,
        bP3;
} SCARD_T0_COMMAND, *LPSCARD_T0_COMMAND;

typedef struct {
    SCARD_IO_REQUEST ioRequest;
    BYTE
        bSw1,
        bSw2;
    union
    {
        SCARD_T0_COMMAND CmdBytes;
        BYTE rgbHeader[5];
    }  u ;
} SCARD_T0_REQUEST;

typedef SCARD_T0_REQUEST *PSCARD_T0_REQUEST, *LPSCARD_T0_REQUEST;






typedef struct {
    SCARD_IO_REQUEST ioRequest;
} SCARD_T1_REQUEST;
typedef SCARD_T1_REQUEST *PSCARD_T1_REQUEST, *LPSCARD_T1_REQUEST;
typedef const BYTE *LPCBYTE;



typedef const  void  *LPCVOID;
__declspec(dllimport)  extern const SCARD_IO_REQUEST
    g_rgSCardT0Pci,
    g_rgSCardT1Pci,
    g_rgSCardRawPci;
typedef ULONG_PTR SCARDCONTEXT;
typedef SCARDCONTEXT *PSCARDCONTEXT, *LPSCARDCONTEXT;

typedef ULONG_PTR SCARDHANDLE;
typedef SCARDHANDLE *PSCARDHANDLE, *LPSCARDHANDLE;
extern   LONG
SCardEstablishContext(
     DWORD dwScope,
     LPCVOID pvReserved1,
     LPCVOID pvReserved2,
     LPSCARDCONTEXT phContext);

extern   LONG
SCardReleaseContext(
     SCARDCONTEXT hContext);

extern   LONG
SCardIsValidContext(
     SCARDCONTEXT hContext);
extern   LONG
SCardListReaderGroupsA(
     SCARDCONTEXT hContext,
     LPSTR mszGroups,
       LPDWORD pcchGroups);
extern   LONG
SCardListReaderGroupsW(
     SCARDCONTEXT hContext,
     LPWSTR mszGroups,
       LPDWORD pcchGroups);






extern   LONG
SCardListReadersA(
     SCARDCONTEXT hContext,
     LPCSTR mszGroups,
     LPSTR mszReaders,
       LPDWORD pcchReaders);
extern   LONG
SCardListReadersW(
     SCARDCONTEXT hContext,
     LPCWSTR mszGroups,
     LPWSTR mszReaders,
       LPDWORD pcchReaders);






extern   LONG
SCardListCardsA(
     SCARDCONTEXT hContext,
     LPCBYTE pbAtr,
     LPCGUID rgquidInterfaces,
     DWORD cguidInterfaceCount,
     LPSTR mszCards,
       LPDWORD pcchCards);
extern   LONG
SCardListCardsW(
     SCARDCONTEXT hContext,
     LPCBYTE pbAtr,
     LPCGUID rgquidInterfaces,
     DWORD cguidInterfaceCount,
     LPWSTR mszCards,
       LPDWORD pcchCards);
extern   LONG
SCardListInterfacesA(
     SCARDCONTEXT hContext,
     LPCSTR szCard,
     LPGUID pguidInterfaces,
       LPDWORD pcguidInterfaces);
extern   LONG
SCardListInterfacesW(
     SCARDCONTEXT hContext,
     LPCWSTR szCard,
     LPGUID pguidInterfaces,
       LPDWORD pcguidInterfaces);






extern   LONG
SCardGetProviderIdA(
     SCARDCONTEXT hContext,
     LPCSTR szCard,
     LPGUID pguidProviderId);
extern   LONG
SCardGetProviderIdW(
     SCARDCONTEXT hContext,
     LPCWSTR szCard,
     LPGUID pguidProviderId);










extern   LONG
SCardGetCardTypeProviderNameA(
     SCARDCONTEXT hContext,
     LPCSTR szCardName,
     DWORD dwProviderId,
     LPSTR szProvider,
       LPDWORD pcchProvider);
extern   LONG
SCardGetCardTypeProviderNameW(
     SCARDCONTEXT hContext,
     LPCWSTR szCardName,
     DWORD dwProviderId,
     LPWSTR szProvider,
       LPDWORD pcchProvider);
extern   LONG
SCardIntroduceReaderGroupA(
     SCARDCONTEXT hContext,
     LPCSTR szGroupName);
extern   LONG
SCardIntroduceReaderGroupW(
     SCARDCONTEXT hContext,
     LPCWSTR szGroupName);






extern   LONG
SCardForgetReaderGroupA(
     SCARDCONTEXT hContext,
     LPCSTR szGroupName);
extern   LONG
SCardForgetReaderGroupW(
     SCARDCONTEXT hContext,
     LPCWSTR szGroupName);






extern   LONG
SCardIntroduceReaderA(
     SCARDCONTEXT hContext,
     LPCSTR szReaderName,
     LPCSTR szDeviceName);
extern   LONG
SCardIntroduceReaderW(
     SCARDCONTEXT hContext,
     LPCWSTR szReaderName,
     LPCWSTR szDeviceName);






extern   LONG
SCardForgetReaderA(
     SCARDCONTEXT hContext,
     LPCSTR szReaderName);
extern   LONG
SCardForgetReaderW(
     SCARDCONTEXT hContext,
     LPCWSTR szReaderName);






extern   LONG
SCardAddReaderToGroupA(
     SCARDCONTEXT hContext,
     LPCSTR szReaderName,
     LPCSTR szGroupName);
extern   LONG
SCardAddReaderToGroupW(
     SCARDCONTEXT hContext,
     LPCWSTR szReaderName,
     LPCWSTR szGroupName);






extern   LONG
SCardRemoveReaderFromGroupA(
     SCARDCONTEXT hContext,
     LPCSTR szReaderName,
     LPCSTR szGroupName);
extern   LONG
SCardRemoveReaderFromGroupW(
     SCARDCONTEXT hContext,
     LPCWSTR szReaderName,
     LPCWSTR szGroupName);






extern   LONG
SCardIntroduceCardTypeA(
     SCARDCONTEXT hContext,
     LPCSTR szCardName,
     LPCGUID pguidPrimaryProvider,
     LPCGUID rgguidInterfaces,
     DWORD dwInterfaceCount,
     LPCBYTE pbAtr,
     LPCBYTE pbAtrMask,
     DWORD cbAtrLen);
extern   LONG
SCardIntroduceCardTypeW(
     SCARDCONTEXT hContext,
     LPCWSTR szCardName,
     LPCGUID pguidPrimaryProvider,
     LPCGUID rgguidInterfaces,
     DWORD dwInterfaceCount,
     LPCBYTE pbAtr,
     LPCBYTE pbAtrMask,
     DWORD cbAtrLen);
extern   LONG
SCardSetCardTypeProviderNameA(
     SCARDCONTEXT hContext,
     LPCSTR szCardName,
     DWORD dwProviderId,
     LPCSTR szProvider);
extern   LONG
SCardSetCardTypeProviderNameW(
     SCARDCONTEXT hContext,
     LPCWSTR szCardName,
     DWORD dwProviderId,
     LPCWSTR szProvider);









extern   LONG
SCardForgetCardTypeA(
     SCARDCONTEXT hContext,
     LPCSTR szCardName);
extern   LONG
SCardForgetCardTypeW(
     SCARDCONTEXT hContext,
     LPCWSTR szCardName);
extern   LONG
SCardFreeMemory(
     SCARDCONTEXT hContext,
     LPCVOID pvMem);


extern   HANDLE
SCardAccessStartedEvent(void);

extern   void
SCardReleaseStartedEvent(void);










typedef struct {
    LPCSTR szReader;
    LPVOID pvUserData;
    DWORD dwCurrentState;
    DWORD dwEventState;
    DWORD cbAtr;
    BYTE rgbAtr[36];
} SCARD_READERSTATEA, *PSCARD_READERSTATEA, *LPSCARD_READERSTATEA;
typedef struct {
    LPCWSTR szReader;
    LPVOID pvUserData;
    DWORD dwCurrentState;
    DWORD dwEventState;
    DWORD cbAtr;
    BYTE rgbAtr[36];
} SCARD_READERSTATEW, *PSCARD_READERSTATEW, *LPSCARD_READERSTATEW;





typedef SCARD_READERSTATEA SCARD_READERSTATE;
typedef PSCARD_READERSTATEA PSCARD_READERSTATE;
typedef LPSCARD_READERSTATEA LPSCARD_READERSTATE;
extern   LONG
SCardLocateCardsA(
     SCARDCONTEXT hContext,
     LPCSTR mszCards,
       LPSCARD_READERSTATEA rgReaderStates,
     DWORD cReaders);
extern   LONG
SCardLocateCardsW(
     SCARDCONTEXT hContext,
     LPCWSTR mszCards,
       LPSCARD_READERSTATEW rgReaderStates,
     DWORD cReaders);







typedef struct _SCARD_ATRMASK {
    DWORD cbAtr;
    BYTE rgbAtr[36];
    BYTE rgbMask[36];
} SCARD_ATRMASK, *PSCARD_ATRMASK, *LPSCARD_ATRMASK;


extern   LONG
SCardLocateCardsByATRA(
     SCARDCONTEXT hContext,
     LPSCARD_ATRMASK rgAtrMasks,
     DWORD cAtrs,
       LPSCARD_READERSTATEA rgReaderStates,
     DWORD cReaders);
extern   LONG
SCardLocateCardsByATRW(
     SCARDCONTEXT hContext,
     LPSCARD_ATRMASK rgAtrMasks,
     DWORD cAtrs,
       LPSCARD_READERSTATEW rgReaderStates,
     DWORD cReaders);







extern   LONG
SCardGetStatusChangeA(
     SCARDCONTEXT hContext,
     DWORD dwTimeout,
       LPSCARD_READERSTATEA rgReaderStates,
     DWORD cReaders);
extern   LONG
SCardGetStatusChangeW(
     SCARDCONTEXT hContext,
     DWORD dwTimeout,
       LPSCARD_READERSTATEW rgReaderStates,
     DWORD cReaders);






extern   LONG
SCardCancel(
     SCARDCONTEXT hContext);
extern   LONG
SCardConnectA(
     SCARDCONTEXT hContext,
     LPCSTR szReader,
     DWORD dwShareMode,
     DWORD dwPreferredProtocols,
     LPSCARDHANDLE phCard,
     LPDWORD pdwActiveProtocol);
extern   LONG
SCardConnectW(
     SCARDCONTEXT hContext,
     LPCWSTR szReader,
     DWORD dwShareMode,
     DWORD dwPreferredProtocols,
     LPSCARDHANDLE phCard,
     LPDWORD pdwActiveProtocol);






extern   LONG




