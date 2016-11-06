// f00290_wsrequesthandler.e
//

#ifndef LZZ_f00290_wsrequesthandler_e
#define LZZ_f00290_wsrequesthandler_e
#define LZZ_INLINE inline
class WebSocketRequestHandler : public HTTPRequestHandler
{
public:
  WebSocketServer * ws_ptr;
  WebSocketRequestHandler (WebSocketServer * _ws_ptr);
  ~ WebSocketRequestHandler ();
  void handleRequest (HTTPServerRequest & request, HTTPServerResponse & response);
};
#undef LZZ_INLINE
#endif
// f00291_rhfactory.e
//

#ifndef LZZ_f00291_rhfactory_e
#define LZZ_f00291_rhfactory_e
#define LZZ_INLINE inline
class RequestHandlerFactory : public HTTPRequestHandlerFactory
{
public:
  WebSocketServer * ws_ptr;
  RequestHandlerFactory (WebSocketServer * _ws_ptr);
  HTTPRequestHandler * createRequestHandler (HTTPServerRequest const & request);
};
#undef LZZ_INLINE
#endif
// f00292_wsserver.e
//

#ifndef LZZ_f00292_wsserver_e
#define LZZ_f00292_wsserver_e
#define LZZ_INLINE inline
class WebSocketServer : public Poco::Util::ServerApplication
{
public:
  bool dataReady;
  bool isWorking;
  bool isJSON;
  int MAX_FRAME_SIZE;
  charArr recBuffer;
  charArr okBuffer;
  WebSocketServer ();
  ~ WebSocketServer ();
protected:
  void initialize (Application & self);
  void uninitialize ();
  void defineOptions (OptionSet & options);
  void handleOption (std::string const & name, std::string const & value);
  void displayHelp ();
  int main (std::vector <std::string> const & args);
private:
  bool _helpRequested;
};
#undef LZZ_INLINE
#endif
// f00293_gamesound.e
//

#ifndef LZZ_f00293_gamesound_e
#define LZZ_f00293_gamesound_e
#define LZZ_INLINE inline
class GameSound
{
public:
  sf::SoundBuffer buffer;
  sf::Sound sound;
  GameSound ();
  void init (string path);
  void setPitch (float val);
  void setPositionAndMinDis (float x, float y, float z, float w);
  void setLoop (bool val);
  void stop ();
  void play (float volume = 1.0f);
};
#undef LZZ_INLINE
#endif
// f00294_gamemusic.e
//

#ifndef LZZ_f00294_gamemusic_e
#define LZZ_f00294_gamemusic_e
#define LZZ_INLINE inline
class GameMusic
{
public:
  sf::Music sound;
  float volume;
  GameMusic ();
  void init (string path);
  void setLoop (bool val);
  void stop ();
  void setVolume (float _volume = 1.0f);
  void play (float _volume = 1.0f);
};
#undef LZZ_INLINE
#endif
// f00295_gamegeom.e
//

#ifndef LZZ_f00295_gamegeom_e
#define LZZ_f00295_gamegeom_e
#define LZZ_INLINE inline
class GameGeom
{
private:
  FIVector4 boundsMinInPixels;
  FIVector4 boundsMaxInPixels;
  FIVector4 visMinInPixels;
  FIVector4 visMaxInPixels;
public:
  FIVector4 (geomParams) [E_GP_LENGTH];
  FIVector4 anchorPointInPixels;
  FIVector4 moveMinInPixels;
  FIVector4 moveMaxInPixels;
  GameLight * light;
  bool visible;
  bool hasAnchor;
  bool isToggled;
  int rotDir;
  int minRot;
  int maxRot;
  int curRot;
  int buildingType;
  int id;
  int globalId;
  GameGeom ();
  void init (int _id);
  float getRand ();
  FIVector4 tempVec1;
  FIVector4 tempVec2;
  FIVector4 tempVec3;
  FIVector4 * getBoundsMinInPixels ();
  FIVector4 * getBoundsMaxInPixels ();
  FIVector4 * getVisMinInPixels ();
  FIVector4 * getVisMaxInPixels ();
  FIVector4 * getBoundsMinInPixelsT ();
  FIVector4 * getBoundsMaxInPixelsT ();
  FIVector4 * getVisMinInPixelsT ();
  FIVector4 * getVisMaxInPixelsT ();
  int getClampedRot ();
  void rotate (int mod, bool ignoreConstraints);
  void initBounds (int _buildingType, int _id, int _globalId, int alignBottomMiddleTop, float _zOffset, FIVector4 * p1, FIVector4 * p2, FIVector4 * rad, FIVector4 * _cornerDisInPixels, FIVector4 * _visInsetFromMin, FIVector4 * _visInsetFromMax, FIVector4 * _powerVals, FIVector4 * _powerVals2, FIVector4 * _thickVals, FIVector4 * _matParams, FIVector4 * _centerPoint, FIVector4 * _anchorPoint, int _minRot, int _maxRot);
  void initLines (int _buildingType, int _id, int _globalId, float scale, FIVector4 * _offset, FIVector4 * _orgVec, FIVector4 * _tanVec, FIVector4 * _bitVec, FIVector4 * _norVec, FIVector4 * _radVec0, FIVector4 * _radVec1, FIVector4 * _radVecScale0, FIVector4 * _radVecScale1, FIVector4 * _matParams);
  void initTree (int _buildingType, int _id, int _globalId, FIVector4 * p0, FIVector4 * p1, FIVector4 * p2, float radP0, float radP1, float sphereRad, FIVector4 * _matParams);
  void toggleTransform ();
  void applyTransform (int rotMod, bool ignoreConstraints);
  void initAnchorPoint (FIVector4 * _anchorPointInPixels, int _minRot, int _maxRot);
};
#undef LZZ_INLINE
#endif
// f00300_singleton.e
//

#ifndef LZZ_f00300_singleton_e
#define LZZ_f00300_singleton_e
#define LZZ_INLINE inline
class Singleton
{
public:
  struct UIQuad
  {
    fBoundingBox hitBounds;
    CharStruct * cs;
    int fontId;
  };
  struct UICont
  {
    UIComponent * uiComp;
    UIQuad bg;
    std::vector <UIQuad> charVec;
  };
  struct JSONStruct
  {
    JSONValue * jv;
  };
  UIComponent * testTT;
  E_OBJ activeObject;
  E_OBJ tempObj;
  int mouseState;
  eProgramState programState;
  eProgramAction (progActionsDown) [E_PS_SIZE * 256];
  eProgramAction (progActionsUp) [E_PS_SIZE * 256];
  float ambVolume;
  float guiVolume;
  bool hitGUI;
  bool guiLock;
  bool guiDirty;
  bool guiOn;
  bool mirrorOn;
  bool bCtrl;
  bool bShift;
  bool tiltChanged;
  bool testOn;
  bool emptyVDNotReady;
  bool radiosityOn;
  bool updateLock;
  bool isFullScreen;
  bool changesMade;
  bool mapInvalid;
  bool bufferInvalid;
  bool wsBufferInvalid;
  bool forceGetPD;
  bool mouseLeftDown;
  bool mouseRightDown;
  bool pboSupported;
  bool notQuit;
  bool timerNotSet;
  bool lbDown;
  bool abDown;
  bool rbDown;
  bool mbDown;
  bool isZooming;
  bool isPanning;
  bool isBare;
  bool showMap;
  bool traceOn;
  bool waterOn;
  bool treesOn;
  bool firstRun;
  bool rotOn;
  int maxLayerOver;
  int currentStep;
  int maxLayers;
  int maxChangesInHolders;
  int baseW;
  int baseH;
  int scaleFactor;
  int activeMode;
  int visPageSizeInPixels;
  int visPageSizeInUnits;
  int unitSizeInPixels;
  int maxHeightInUnits;
  int holdersPerLot;
  int pixelsPerLot;
  int numDynLights;
  int iNumSteps;
  int curEntId;
  int pixelsPerMeter;
  int pixelsPerUnit;
  int metersPerLot;
  int unitsPerMeter;
  int unitsPerLot;
  int extraRad;
  int defaultWinW;
  int defaultWinH;
  int guiWinW;
  int guiWinH;
  int shadersAreLoaded;
  int readyToRecompile;
  int lastPosX;
  int lastPosY;
  int frameCount;
  int maxHInPages;
  int maxWInPages;
  int screenWidth;
  int screenHeight;
  int mouseMovingSize;
  int mouseMovingLoc;
  int mouseMovingStepsBack;
  int mouseCount;
  int lastMouseX;
  int lastMouseY;
  int bufferedPageSizeInUnits;
  int voroSize;
  int geomCounter;
  int lightCounter;
  int charState;
  int metersPerNodeXY;
  int terDataVisPitchXY;
  int terDataBufPitchXY;
  int terDataBufPitchScaledXY;
  int metersPerNodeZ;
  int terDataVisPitchZ;
  int terDataBufPitchZ;
  int terDataBufPitchScaledZ;
  int terDataBufAmount;
  int terDataVisSize;
  int terDataBufSize;
  int terDataTexScale;
  int terDataBufSizeScaled;
  uint * terDataScaled;
  int iNodeDivsPerLot;
  int selGeomListInd;
  int holderSizeInPages;
  int holderSizeInPixels;
  uint volGenFBOX;
  uint palWidth;
  uint palHeight;
  uint blockShift;
  float directPass;
  float fogOn;
  float gridOn;
  float mapSampScale;
  float curBrushRad;
  float timeOfDay;
  float targetTimeOfDay;
  float gridSizeInPixels;
  float origWinW;
  float origWinH;
  float guiX;
  float guiY;
  double curMS;
  float tiltAmount;
  float currentFBOResolutionX;
  float currentFBOResolutionY;
  float mouseX;
  float mouseY;
  float mouseXUp;
  float mouseYUp;
  float cameraZoom;
  float targetZoom;
  float curTime;
  float lastTime;
  float myDelta;
  float mdTime;
  float muTime;
  float bufferMult;
  float holderSizeMB;
  float * paramArr;
  float * voroArr;
  float * matCountArr;
  int * geomIdArr;
  float * paramArrMap;
  GameEntNode * bestNode;
  GameEntNode * selectedNode;
  GameEntNode * lastSelNode;
  GameEntNode * activeNode;
  float bestNodeDis;
  FIVector4 worldSizeInPixels;
  FIVector4 mouseUpPD;
  FIVector4 mouseDownPD;
  FIVector4 mouseMovePD;
  FIVector4 tempVec1;
  FIVector4 tempVec2;
  FIVector4 tempVec3;
  FIVector4 worldSizeInPages;
  FIVector4 worldSizeInLots;
  FIVector4 worldSizeInHolders;
  FIVector4 worldSizeInBlocks;
  FIVector4 (moveNodes) [2];
  FIVector4 (voroVecArr) [125];
  floatAndIndex (indexArr) [125];
  FIVector4 mouseStart;
  FIVector4 mouseEnd;
  FIVector4 mapFreqs;
  FIVector4 mapAmps;
  FIVector4 * mouseMoving;
  FIVector4 mouseVel;
  FIVector4 worldSeed;
  FIVector4 bufferDim;
  FIVector4 bufferDimHalf;
  FIVector4 origin;
  FIVector4 lastModXYZ;
  FIVector4 panMod;
  FIVector4 dMod;
  FIVector4 modXYZ;
  std::vector <UICont*> (guiLayers) [MAX_UI_LAYERS];
  std::vector <FIVector4> rotStack;
  std::vector <FIVector4> transStack;
  std::vector <DynObject *> dynObjects;
  std::vector <GameGeom *> selGeomList;
  PathHolder charPathHolder;
  PathHolder splitPathHolder;
  float floorHeightInMeters;
  float roofHeightInMeters;
  float wallRadInMeters;
  int holderSizeMod;
  int holderSizeInPixelsMod;
  int blockSizeInLots;
  int blockSizeInMeters;
  int blockSizeInHolders;
  int blockSizeInPages;
  int blockSizeInPixels;
  Image * imageHM0;
  Image * imageHM1;
  Image * cloudImage;
  GameGeom * highlightedGeom;
  GameGeom * selectedGeom;
  Shader * curShaderPtr;
  string curShader;
  string allText;
  string stringBuf;
  string curCallback;
  string (cbDataStrings) [10];
  PoolManager * gpuPool;
  PoolManager * entityPool;
  vector <string> shaderStrings;
  vector <string> shaderTextureIds;
  map <string, Shader *> shaderMap;
  map <string, FBOSet> fboMap;
  GLuint volId;
  GLuint volIdLinear;
  GLuint volIdEmpty;
  GLuint volIdEmptyLinear;
  GLuint volGenId;
  GLuint volTris;
  GLuint sliceTris;
  uint * lookup2to3;
  unsigned char * resultImage;
  charArr nullBuffer;
  charArr lastImageBuffer;
  charArr lastJSONBuffer;
  charArr lastJSONBufferGUI;
  JSONValue * rootObjJS;
  JSONValue * guiRootJS;
  WebSocketServer * myWS;
  Timer myTimer;
  GameWorld * gw;
  float (lightArr) [MAX_LIGHTS * 16];
  int numLights;
  bool multiLights;
  int * rbHeightStack;
  TerTexture (terTextures) [MAX_TER_TEX];
  GameEnt * testHuman;
  GameGUI * mainGUI;
  FontWrapper * (fontWrappers) [EFW_LENGTH];
  GameMusic * (music) [EML_LENGTH];
  map <string, GameSound> soundMap;
  map <string, StyleSheet> styleSheetMap;
  map <string, JSONStruct> internalJSON;
  Singleton ();
  void init (int _defaultWinW, int _defaultWinH, int _scaleFactor, WebSocketServer * _myWS);
  void prepSound (string soundName);
  void playSoundPosAndPitch (string soundName, FIVector4 * listenerPos, FIVector4 * soundPos, float variance = 0.0f, float volume = 1.0f);
  void playSound (string soundName, float volume = 1.0f);
  void playSoundEvent (char const * eventName);
  void dispatchEvent (int button, int state, float x, float y, UIComponent * comp);
  StyleSheet * getNewStyleSheet (string ssName);
  void initStyleSheet ();
  int requestTerIndex (int requestingBlockId);
  static void qNormalizeAngle (int & angle);
  void perspectiveProjection ();
  void orthographicProjection ();
  ~ Singleton ();
  float genRand (float LO, float HI);
  void setProgAction (eProgramState ps, unsigned char kc, eProgramAction pa, bool isDown);
  void setProgActionAll (unsigned char kc, eProgramAction pa, bool isDown);
  void drawCrossHairs (FIVector4 originVec, float radius);
  void drawLine (FIVector4 * p0, FIVector4 * p1);
  void drawCubeCentered (FIVector4 * originVec, float radius);
  void drawBoxUp (FIVector4 originVec, float radiusX, float radiusY, float diamZ);
  void drawBox (FIVector4 * minVec, FIVector4 * maxVec, int faceFlag = 2);
  float glslMod (float x, float y);
  void createVTListTilt ();
  void createVTList ();
  void doShaderRefresh ();
  void setMatrices (int w, int h);
  void setWH (int w, int h);
  void sampleFBODirect (FBOSet * fbos, int offset = 0);
  void unsampleFBODirect (FBOSet * fbos, int offset = 0);
  void bindFBODirect (FBOSet * fbos, int doClear = 1);
  void sampleFBO (string fboName, int offset = 0, int swapFlag = -1);
  void unsampleFBO (string fboName, int offset = 0, int swapFlag = -1);
  FBOSet * getFBOSet (string fboName);
  FBOWrapper * getFBOWrapper (string fboName, int offset);
  void copyFBO (string src, string dest);
  void copyFBO2 (string src, string dest);
  void bindFBO (string fboName, int swapFlag = -1);
  void unbindFBO ();
  void bindShader (string shaderName);
  void unbindShader ();
  void setShaderArrayfVec3 (string paramName, float * x, int count);
  void setShaderArrayfVec4 (string paramName, float * x, int count);
  void setShaderArray (string paramName, float * x, int count);
  void setShaderFloat (string paramName, float x);
  void setShaderInt (string paramName, int x);
  void setShaderfVec2 (string paramName, FIVector4 * v);
  void setShaderVec2 (string paramName, float x, float y);
  void setShaderVec3 (string paramName, float x, float y, float z);
  void setShaderfVec3 (string paramName, FIVector4 * v);
  void setShaderVec4 (string paramName, float x, float y, float z, float w);
  void setShaderfVec4 (string paramName, FIVector4 * v);
  void setShaderFloatUB (string paramName, float x);
  void setShaderfVec4UB (string paramName, FIVector4 * v);
  void updateUniformBlock (int ubIndex, int ubDataSize = -1);
  void invalidateUniformBlock (int ubIndex);
  void beginUniformBlock (int ubIndex);
  bool wasUpdatedUniformBlock (int ubIndex);
  void setShaderTexture (int multitexNumber, uint texId);
  void setShaderTexture3D (int multitexNumber, uint texId);
  bool shiftDown ();
  bool ctrlDown ();
  bool altDown ();
  void drawQuadBounds (float fx1, float fy1, float fx2, float fy2, float fz);
  void drawFSQuad (float zoom);
  void drawFSQuadOffset (float xOff, float yOff, float zoom);
  void drawFBO (string fboName, int ind, float zoom, int swapFlag = -1);
  void drawFBOOffsetDirect (FBOSet * fbos, int ind, float xOff, float yOff, float zoom);
  void drawFBOOffset (string fboName, int ind, float xOff, float yOff, float zoom);
  float getTerHeightScaled (float val);
  float getSLNormalized ();
  float getSLInPixels ();
  float getHeightAtPixelPos (float x, float y, bool dd = false);
  void moveCamera (FIVector4 * pModXYZ);
  GameEntNode * getMirroredNode (GameEntNode * curNode);
  void moveObject (float dx, float dy, float zoom);
  void updateMultiLights ();
  void toggleFullScreen ();
  void restartGen (bool instantRefresh, bool clearEverything);
  void setCameraToElevationBase ();
  void setCameraToElevation ();
  void processSpecialKeys (int key, int _x, int _y);
  void processKey (unsigned char key, int _x, int _y, bool isPressed);
  void keyboardUp (unsigned char key, int _x, int _y);
  void keyboardDown (unsigned char key, int _x, int _y);
  void runReport ();
  void getPixData (FIVector4 * toVector, int xv, int yv);
  GameGeom * findNearestGeom (FIVector4 * testPoint, bool createList = false);
  void mouseMove (int _x, int _y);
  void makeDirty ();
  void setSelNode (GameEntNode * newNode);
  void screenToWorldBase (FIVector4 * tc, FIVector4 * wc);
  void worldToScreenBase (FIVector4 * sc, FIVector4 * wc);
  void worldToScreen (FIVector4 * sc, FIVector4 * wc, bool centerIsOrigin = false);
  void mouseClick (int button, int state, int _x, int _y);
  void resetActiveNode ();
  void updateNearestEntNode (bool setActive, FIVector4 * mousePosWS);
  void findNearestEntNode (GameEntNode * curNode, FIVector4 * mousePosSS);
  void processB64 (charArr * sourceBuffer, charArr * saveBuffer);
  bool processJSONFromString (string * sourceBuffer, JSONValue * * destObj);
  bool processJSON (charArr * sourceBuffer, charArr * saveBuffer, JSONValue * * destObj);
  bool loadJSON (string path, JSONValue * * destObj);
  void loadGUI ();
  void loadAllData ();
  void saveAllData ();
  bool loadFile (string fnString, charArr * dest);
  bool saveFile (char * fileName, charArr * source);
  void updateAmbientSounds ();
  void display ();
  void reshape (int w, int h);
  void idleFunc ();
};
LZZ_INLINE float Singleton::glslMod (float x, float y)
        {
		return x - y * floor(x / y);
	}
#undef LZZ_INLINE
#endif
// f00310_pooledresource.e
//

#ifndef LZZ_f00310_pooledresource_e
#define LZZ_f00310_pooledresource_e
#define LZZ_INLINE inline
class PooledResource
{
private:
  FBOSet * (fboSet) [MAX_LAYERS];
  uint * (cpuSet) [MAX_LAYERS];
public:
  intPair usedByHolderId;
  bool isCPU;
  Singleton * singleton;
  PooledResource ();
  FBOSet * getFBOS (int fboNum);
  void init (Singleton * _singleton, bool _isCPU);
};
#undef LZZ_INLINE
#endif
// f00315_poolmanager.e
//

#ifndef LZZ_f00315_poolmanager_e
#define LZZ_f00315_poolmanager_e
#define LZZ_INLINE inline
class PoolManager
{
public:
  int poolItemsCreated;
  bool isCPU;
  list <int> holderPoolIds;
  vector <intPair> orderedIds;
  vector <PooledResource *> holderPoolItems;
  Singleton * singleton;
  GameWorld * gw;
  bool isEntity;
  PoolManager ();
  void init (Singleton * _singleton, bool _isEntity, bool _isCPU);
  float getMaxMem ();
  float getTotMemUsed ();
  void reorderIds ();
  int findFurthestHolderId ();
  int requestPoolId (int blockId, int holderId);
};
#undef LZZ_INLINE
#endif
// f00320_fontwrapper.e
//

#ifndef LZZ_f00320_fontwrapper_e
#define LZZ_f00320_fontwrapper_e
#define LZZ_INLINE inline
class FontWrapper
{
public:
  Singleton * singleton;
  charArr lastJSONBuffer;
  JSONValue * jsRoot;
  Image * fontImage;
  float ascender;
  float descender;
  float fontHeight;
  float maxWidth;
  float fontScale;
  float additionalOffset;
  bool isIcons;
  CharStruct (charVals) [4096];
  FontWrapper ();
  void init (Singleton * _singleton, string fontName, bool _isIcons, float _fontScale, float _additionalOffset = 0.0f);
};
#undef LZZ_INLINE
#endif
// f00325_uicomponent.e
//

#ifndef LZZ_f00325_uicomponent_e
#define LZZ_f00325_uicomponent_e
#define LZZ_INLINE inline
class UIComponent
{
private:
  UIComponent * parent;
public:
  Singleton * singleton;
  Singleton::UIQuad thisUIQuad;
  Singleton::UICont thisUICont;
  string uid;
  string ss;
  string text;
  int parentId;
  int nodeId;
  int index;
  int fillDir;
  int layer;
  int hoverType;
  int guiClass;
  Singleton::UIQuad * curQuad;
  bool foundParent;
  bool visible;
  iVector2 align;
  JSONValue * jvNodeNoTemplate;
  fVector2 floatOffset;
  fVector2 originPos;
  fVector2 resultDimInPixels;
  fVector2 textDimInPixels;
  fVector2 minDimInPixels;
  fVector2 maxAvailDimInPixels;
  fVector2 fillRatioDim;
  FontWrapper * curFont;
  FontWrapper * curFontIcons;
  bool contOnStack;
  bool overChild;
  bool overSelf;
  bool singleLine;
  bool hasBackground;
  bool mouseOver;
  bool mouseDown;
  bool wasHit;
  bool isDirty;
  bool isFloating;
  float value;
  float divisions;
  float paddingInPixels;
  float borderInPixels;
  float marginInPixels;
  float spaceForCharsInPixels;
  iVector2 spacing;
  std::vector <string> lineVec;
  std::vector < std::vector<string> > wordVec;
  std::vector <float> linePitchVec;
  fBoundingBox hitBounds;
  StyleSheetResult resSS;
  std::vector <UIComponent> children;
  std::vector <UIComponent> floatingChildren;
  UIComponent * curComp;
  UIComponent ();
  void init (Singleton * _singleton, int _parentId, int _nodeId, int _index, JSONValue * _jvNodeNoTemplate, string _text, string _uid, string _ss, int _guiClass = E_GT_HOLDER, float _divisions = 0.0f, bool _hasBackground = true, bool _singleLine = true, float _fillRatioX = 0.0f, float _fillRatioY = 0.0f, int _fillDir = E_FILL_HORIZONTAL, int _alignX = E_ALIGNH_LEFT, int _alignY = E_ALIGNV_TOP, float _value = 0.0f, int _layer = 0, int _hoverType = E_HT_NORMAL, bool _isFloating = false);
  UIComponent * getParent ();
  UIComponent * findNodeByString (string _uid);
  UIComponent * findNodeById (int id);
  float getMinWidth ();
  float getMinHeight ();
  UIComponent * addChild (int _parentId, int _nodeId, string * stringVals, float * floatVals, bool _isFloating, JSONValue * _jvNodeNoTemplate);
  void setOrigPos ();
  void applyHeight ();
  void applyWidth ();
  void gatherDirty (vector <UIComponent*> * dirtyVec);
  void clearDirty ();
  void layout ();
  void updateValue (float x, float y);
  void runReport ();
  void clearOver ();
  bool findMaxLayer (float x, float y);
  void testOver (float x, float y);
  bool testHit (int button, int state, float x, float y);
  void setText (string _text);
  void updateVecs ();
  void renderAll ();
  void updateSS ();
  float getLineOffset (int lineCount);
  float lengthOfWord (int i, int j, bool isIcon);
  int maxCharsForWord (int i, int j);
  void renderText (bool getDimensions);
};
#undef LZZ_INLINE
#endif
// f00330_gamegui.e
//

#ifndef LZZ_f00330_gamegui_e
#define LZZ_f00330_gamegui_e
#define LZZ_INLINE inline
class GameGUI
{
private:
public:
  Singleton * singleton;
  UIComponent * baseComp;
  JSONValue * jvRoot;
  JSONValue * jvTemplates;
  JSONValue * jvSounds;
  bool isReady;
  int nodeCount;
  vector <UIComponent*> dirtyVec;
  string (tempStrings) [10];
  GameGUI ();
  void init (Singleton * _singleton);
  void getJVNodeByString (JSONValue * rootNode, JSONValue * * resultNode, string stringToSplit);
  bool compChildStr (string childStr);
  void addChildFromJSON (JSONValue * jv, UIComponent * curParent, bool isFloating = false);
  void guiFromJSON (JSONValue * jv);
  void doRefresh ();
  void testOver (int x, int y);
  bool testHit (int button, int state, int x, int y);
  UIComponent * findNodeByString (string _uid);
  void renderCharAt (UIComponent * uiComp, CharStruct * cs, FontWrapper * activeFont, float px, float py, float shadowOffset);
  void renderQuad (UIComponent * uiComp, fBoundingBox fbb, float shadowOffset);
  void runReport ();
  void renderGUI (float newZoom, int activeFBO);
};
LZZ_INLINE bool GameGUI::compChildStr (string childStr)
                                                  {
		return tempStrings[E_GDS_CHILD_TYPE].compare(childStr) == 0;
	}
LZZ_INLINE void GameGUI::renderQuad (UIComponent * uiComp, fBoundingBox fbb, float shadowOffset)
          {

		StyleSheetResult* resSS = &(uiComp->resSS);

		
		

		float x0 = (fbb.xMin+uiComp->floatOffset.x)/singleton->guiWinW;
		float x1 = (fbb.xMax+uiComp->floatOffset.x)/singleton->guiWinW;
		float y0 = (fbb.yMin+uiComp->floatOffset.y+shadowOffset)/singleton->guiWinH;
		float y1 = (fbb.yMax+uiComp->floatOffset.y+shadowOffset)/singleton->guiWinH;

		x0 = (x0-0.5f)*2.0f;
		x1 = (x1-0.5f)*2.0f;
		y0 = ((1.0f-y0) - 0.5f)*2.0f;
		y1 = ((1.0f-y1) - 0.5f)*2.0f;

		
		//dimensions
		glMultiTexCoord4f(1, fbb.xMax-fbb.xMin, fbb.yMax-fbb.yMin, resSS->props[E_SS_BORDER], resSS->props[E_SS_CORNERRAD]);

		glMultiTexCoord4f(5, 0.0f, shadowOffset, 1.0f, 1.0f);
		
		//border color
		glMultiTexCoord4f(6, resSS->props[E_SS_BDCOL_R], resSS->props[E_SS_BDCOL_G], resSS->props[E_SS_BDCOL_B], resSS->props[E_SS_BDCOL_A]);
		//misc
		glMultiTexCoord4f(7, resSS->props[E_SS_ROUNDNESS], uiComp->value, 1.0f, 1.0f);


		//bg
		glMultiTexCoord4f(2, resSS->props[E_SS_BGCOL1_R], resSS->props[E_SS_BGCOL1_G], resSS->props[E_SS_BGCOL1_B], resSS->props[E_SS_BGCOL1_A]);
		//fg
		glMultiTexCoord4f(3, resSS->props[E_SS_FGCOL1_R], resSS->props[E_SS_FGCOL1_G], resSS->props[E_SS_FGCOL1_B], resSS->props[E_SS_FGCOL1_A]);
		//tg
		glMultiTexCoord4f(4, resSS->props[E_SS_TGCOL1_R], resSS->props[E_SS_TGCOL1_G], resSS->props[E_SS_TGCOL1_B], resSS->props[E_SS_TGCOL1_A]);
		
		
		glMultiTexCoord4f(0, 0.0f, 0.0f, 0.0f, 1.0f);
		glVertex3f (  x0, y1, -1.0f );
		glMultiTexCoord4f(0, 0.0f, 0.0f, 1.0f, 1.0f);
		glVertex3f (  x1, y1, -1.0f );

		//bg
		glMultiTexCoord4f(2, resSS->props[E_SS_BGCOL0_R], resSS->props[E_SS_BGCOL0_G], resSS->props[E_SS_BGCOL0_B], resSS->props[E_SS_BGCOL0_A]);
		//fg
		glMultiTexCoord4f(3, resSS->props[E_SS_FGCOL0_R], resSS->props[E_SS_FGCOL0_G], resSS->props[E_SS_FGCOL0_B], resSS->props[E_SS_FGCOL0_A]);
		//tg
		glMultiTexCoord4f(4, resSS->props[E_SS_TGCOL0_R], resSS->props[E_SS_TGCOL0_G], resSS->props[E_SS_TGCOL0_B], resSS->props[E_SS_TGCOL0_A]);

		glMultiTexCoord4f(0, 0.0f, 0.0f, 1.0f, 0.0f);
		glVertex3f (  x1, y0, -1.0f );
		glMultiTexCoord4f(0, 0.0f, 0.0f, 0.0f, 0.0f);
		glVertex3f (  x0, y0, -1.0f );


	}
#undef LZZ_INLINE
#endif
// f00338_gameentnode.e
//

#ifndef LZZ_f00338_gameentnode_e
#define LZZ_f00338_gameentnode_e
#define LZZ_INLINE inline
class GameEntNode
{
private:
public:
  float rotThe;
  float rotPhi;
  float rotRho;
  float material;
  float boneLengthHalf;
  FIVector4 * readTBN;
  FIVector4 * writeTBN;
  FIVector4 (tbnBase) [3];
  FIVector4 (tbnRotA) [3];
  FIVector4 (tbnRotB) [3];
  FIVector4 (tbnRotC) [3];
  FIVector4 (tbnTrans) [3];
  FIVector4 tbnRadInMeters0;
  FIVector4 tbnRadInMeters1;
  FIVector4 tbnRadScale0;
  FIVector4 tbnRadScale1;
  FIVector4 (orgTrans) [3];
  int nodeName;
  GameEntNode * parent;
  std::vector <GameEntNode*> children;
  GameEntNode (GameEntNode * _parent, int _nodeName, float _boneLength, float _tanLengthInMeters, float _bitLengthInMeters, float _norLengthInMeters, float _tanX, float _tanY, float _tanZ, float _bitX, float _bitY, float _bitZ, float _norX, float _norY, float _norZ);
  GameEntNode * addChild (int _nodeName, float _boneLength, float _tanLengthInMeters, float _bitLengthInMeters, float _norLengthInMeters, float _tanX, float _tanY, float _tanZ, float _bitX, float _bitY, float _bitZ, float _norX, float _norY, float _norZ);
  GameEntNode * getNode (int _nodeName);
  void doTransform (Singleton * singleton);
};
#undef LZZ_INLINE
#endif
// f00339_gameent.e
//

#ifndef LZZ_f00339_gameent_e
#define LZZ_f00339_gameent_e
#define LZZ_INLINE inline
class GameEnt
{
public:
  Singleton * singleton;
  GamePageHolder * gph;
  GameEntNode * baseNode;
  FIVector4 basePosition;
  float defVecLength;
  float gv (float * vals);
  GameEnt ();
  void init (Singleton * _singleton);
  void initHuman ();
};
#undef LZZ_INLINE
#endif
// f00340_gameplantnode.e
//

#ifndef LZZ_f00340_gameplantnode_e
#define LZZ_f00340_gameplantnode_e
#define LZZ_INLINE inline
class GamePlantNode
{
public:
  FIVector4 begPoint;
  FIVector4 endPoint;
  FIVector4 tangent;
  FIVector4 baseShoot;
  float shootLength;
  float begThickness;
  float endThickness;
  float midThickness;
  float sphereRad;
  FIVector4 startEndWidth;
  FIVector4 upVec;
  GamePlantNode * parent;
  GamePlantNode * children;
  int maxChildren;
  int numChildren;
  GamePlantNode ();
  void updateTangent (float angleInRadians);
  void init (GamePlantNode * _parent, int _maxChildren, int _numChildren);
};
#undef LZZ_INLINE
#endif
// f00341_gameplant.e
//

#ifndef LZZ_f00341_gameplant_e
#define LZZ_f00341_gameplant_e
#define LZZ_INLINE inline
class GamePlant
{
public:
  Singleton * singleton;
  FIVector4 origin;
  FIVector4 tempv0;
  FIVector4 tempv1;
  FIVector4 tempv2;
  FIVector4 tempv3;
  FIVector4 rootVec;
  FIVector4 trunkVec;
  GamePlantNode * trunkNode;
  GamePlantNode * rootsNode;
  PlantRules * rootRules;
  PlantRules * trunkRules;
  static PlantRules (allPlantRules) [E_PT_LENGTH];
  static void initAllPlants (Singleton * _singleton);
  float gv (float * vals);
  GamePlant ();
  void init (Singleton * _singleton, PlantRules * _rootRules, PlantRules * _trunkRules, FIVector4 * _origin);
  void initBase (PlantRules * rules, GamePlantNode * curNode, FIVector4 * baseVec);
  void applyRules (PlantRules * rules, GamePlantNode * curParent, int curGen, int maxGen, float totLength, float maxLength);
};
#undef LZZ_INLINE
#endif
// f00350_gamepage.e
//

#ifndef LZZ_f00350_gamepage_e
#define LZZ_f00350_gamepage_e
#define LZZ_INLINE inline
class GamePage
{
private:
  uint * volData;
  uint * volDataLinear;
public:
  Singleton * singleton;
  int thisPageId;
  int bufferedPageSizeInUnits;
  FIVector4 offsetInUnits;
  FIVector4 offsetInPages;
  FIVector4 offsetInPagesLocal;
  float pageDepth;
  int iVolumeSize;
  bool hasGeom;
  bool hasLines;
  bool hasTerrain;
  bool hasWater;
  bool hasWindow;
  bool hasTree;
  bool nearTerrain;
  bool nearAir;
  int voroCount;
  bool volDataModified;
  bool isRendering;
  bool isEntity;
  int paramsPerEntry;
  int numEntries;
  int totParams;
  int maxEntries;
  int maxHeightInUnits;
  FIVector4 worldSeed;
  bool threadRunning;
  float unitSizeInPixels;
  GameWorld * gw;
  FIVector4 worldMinVisInPixels;
  FIVector4 worldMaxVisInPixels;
  FIVector4 worldMinBufInPixels;
  FIVector4 worldMaxBufInPixels;
  FIVector4 centerPosition;
  FIVector4 scaleAndOffset;
  FIVector4 worldUnitMin;
  FIVector4 worldUnitMax;
  FIVector4 voroSize;
  FIVector4 curPos;
  FIVector4 randNum;
  FIVector4 testNum;
  FIVector4 newPos;
  FIVector4 tempVec1;
  FIVector4 tempVec2;
  GamePageHolder * parentGPH;
  GameBlock * parentBlock;
  uint * getVolData ();
  uint * getVolDataLinear ();
  GamePage ();
  void init (Singleton * _singleton, GamePageHolder * _parentGPH, int _thisPageId, int offsetX, int offsetY, int offsetZ, int oxLoc, int oyLoc, int ozLoc, bool _isEntity = false);
  void copyToTexture (bool isForEmptyVD);
  void addEntityGeom (bool justTesting);
  void addGeom (bool justTesting);
  void getVoroPoints ();
  void generateVolume ();
  void getCoords ();
  ~ GamePage ();
};
#undef LZZ_INLINE
#endif
// f00351_gamepageholder.e
//

#ifndef LZZ_f00351_gamepageholder_e
#define LZZ_f00351_gamepageholder_e
#define LZZ_INLINE inline
class GamePageHolder
{
public:
  int iPageDataVolume;
  int holderSizeInPages;
  int usingPoolId;
  int blockId;
  int holderId;
  bool isDirty;
  bool hasTrans;
  bool hasSolids;
  bool underground;
  std::vector <GameGeom *> entityGeom;
  int entityGeomCounter;
  FIVector4 offsetInHolders;
  FIVector4 gphMinInPixels;
  FIVector4 gphMaxInPixels;
  FIVector4 gphCenInPixels;
  FIVector4 offsetInBlocks;
  FIVector4 origOffset;
  FIVector4 tempVec;
  FIVector4 tempVec2;
  PooledResource * gpuRes;
  Singleton * singleton;
  std::vector <intPair> containsGeomIds;
  GamePage * * pageData;
  bool readyForClear;
  bool isEntity;
  float holderSizeInPixels;
  float halfHolderSizeInPixels;
  GamePageHolder ();
  void init (Singleton * _singleton, int _blockId, int _holderId, int trueX, int trueY, int trueZ, bool _isEntity = false);
  GamePage * getPageAtCoordsLocal (int x, int y, int z, bool createOnNull = false);
  void refreshGeom ();
  void clearSet ();
  void refreshChildren (bool refreshImmediate, bool clearEverything = false);
  void addNewGeom (int _curBT, int _curAlign, float _baseOffset, FIVector4 * _p1, FIVector4 * _p2, FIVector4 * _rad, FIVector4 * _cornerRad, FIVector4 * _visInsetFromMin, FIVector4 * _visInsetFromMax, FIVector4 * _powerVals, FIVector4 * _powerVals2, FIVector4 * _thickVals, FIVector4 * _matParams, FIVector4 * _centerPoint, FIVector4 * _anchorPoint, int _minRot, int _maxRot);
  void addNewLinesGeom (GameEntNode * curNode, float scale);
  void fetchEntityGeom ();
  void fetchGeom ();
  void unbindGPUResources ();
};
#undef LZZ_INLINE
#endif
// f00352_gameblock.e
//

#ifndef LZZ_f00352_gameblock_e
#define LZZ_f00352_gameblock_e
#define LZZ_INLINE inline
class GameBlock
{
public:
  Singleton * singleton;
  int blockId;
  int blockSizeInHolders;
  int blockSizeInLots;
  int localGeomCounter;
  int lightCounter;
  int terDataBufAmount;
  int terDataVisPitchXY;
  float fTerDataVisPitchXY;
  int terDataBufPitchXY;
  int terDataBufPitchScaledXY;
  int terDataVisPitchZ;
  float fTerDataVisPitchZ;
  int terDataBufPitchZ;
  int terDataBufPitchScaledZ;
  int terDataTexScale;
  int terDataVisSize;
  int terDataBufSize;
  int blockSizeInPixels;
  int iHolderSize;
  int maxFloors;
  float fBlockSizeInPixels;
  int (dirModX) [6];
  int (dirModY) [6];
  int (dirModZ) [6];
  int (opDir) [6];
  float pixelsPerMeter;
  float floorHeightInMeters;
  float floorHeight;
  float roofHeight;
  bool (isBuilding) [E_CT_LENGTH];
  bool (isRoad) [E_CT_LENGTH];
  bool (isRoom) [E_CT_LENGTH];
  bool (isBase) [E_CT_LENGTH];
  bool (isTraversable) [E_CT_LENGTH];
  int (ctClasses) [E_CT_LENGTH];
  int (layerHash) [E_CT_LENGTH];
  FIVector4 anchorPoint;
  FIVector4 moveMinInPixels;
  FIVector4 moveMaxInPixels;
  FIVector4 p1;
  FIVector4 p2;
  FIVector4 newP1;
  FIVector4 newP2;
  FIVector4 rad;
  FIVector4 visInsetFromMin;
  FIVector4 visInsetFromMax;
  FIVector4 cornerRad;
  FIVector4 thickVals;
  FIVector4 powerVals;
  FIVector4 powerVals2;
  FIVector4 matParams;
  FIVector4 centerPoint;
  FIVector4 lightVec;
  FIVector4 offsetInBlocks;
  FIVector4 offsetInBlocksWrapped;
  FIVector4 origin;
  FIVector4 blockMinBufInPixels;
  FIVector4 blockMaxBufInPixels;
  FIVector4 tempVec;
  FIVector4 tempVec2;
  FIVector4 tempVec3;
  FIVector4 tempVec4;
  FIVector4 tempVecB;
  FIVector4 tempVecB2;
  FIVector4 tempVecB3;
  std::vector <GameGeom *> gameGeom;
  std::vector <GameLight *> gameLights;
  GamePlant oakTree;
  GamePlant bareTree;
  GameWorld * gw;
  GamePageHolder * * holderData;
  BuildingNode * buildingData;
  MapNode * mapData;
  uint * terData;
  BuildingCon * curCon;
  GameBlock ();
  void init (Singleton * _singleton, int _blockId, int _x, int _y, int _xw, int _yw);
  int getNodeIndex (int x, int y, int z, int bufAmount);
  int touchesPlanarBN (int x, int y, int z, int buildingType, int bufAmount);
  int touchesPlanarClass (int x, int y, int z, int classType, int bufAmount);
  bool isLCorner (int x, int y, int z, int classType, bool includeSingle);
  void applyWingValues (int _x1, int _y1, int _z1, int _x2, int _y2, int _z2, int cnum, bool isWingBeg, bool isWingEnd, float multiplier);
  void addNewGeom (int _curBT, int _curAlign, float _baseOffset, FIVector4 * _p1, FIVector4 * _p2, FIVector4 * _rad, FIVector4 * _cornerRad, FIVector4 * _visInsetFromMin, FIVector4 * _visInsetFromMax, FIVector4 * _powerVals, FIVector4 * _powerVals2, FIVector4 * _thickVals, FIVector4 * _matParams, FIVector4 * _centerPoint, FIVector4 * _anchorPoint, int _minRot, int _maxRot);
  void connectNodes (int _x1, int _y1, int _z1, int _x2, int _y2, int _z2, int ct, int id = -1, int _heightDelta = 0, int _direction = 0, float _wallRadInMeters = -1.0f);
  int getMapNodeIndex (int x, int y, int bufAmount);
  int touchesMap (int x, int y, int buildingType, int bufAmount);
  int touches2Map (int x, int y, int buildingType, int bufAmount);
  void connectMapNodes (int _x1, int _y1, int _x2, int _y2, int buildingType, int id, int bufAmount);
  void isNearTerrain (FIVector4 * worldPositionInPixels, bool & nearT, bool & nearA);
  int findNearestNode (FIVector4 * worldPositionInPixelsIn, FIVector4 * posInNodesOut, FIVector4 * posInPixelsOut);
  void nodeIndexToWorldSpaceInPixels (int ind, FIVector4 * posInPixelsOut);
  bool hasTerrainBelow (int i, int j, int k, int conDir, bool bothEnds);
  bool hasRoomBelow (int i, int j, int k, int conDir);
  bool isSupportedBelow (int i, int j, int k, int conDir, bool bothEnds);
  bool touchesRoomOnLevel (int i, int j, int k);
  bool touchesBaseOnLevel (int i, int j, int k, int layer);
  bool buildingAbove (int x, int y, int z);
  int copyTerToTexture ();
};
#undef LZZ_INLINE
#endif
// f00380_gameworld.e
//

#ifndef LZZ_f00380_gameworld_e
#define LZZ_f00380_gameworld_e
#define LZZ_INLINE inline
class GameWorld
{
public:
  int numProvinces;
  int seaLevel;
  int seaSlack;
  int pageCount;
  int mapSwapFlag;
  int visPageSizeInUnits;
  int blockSizeInHolders;
  int iBlockSize;
  int renderMethod;
  int iBufferSize;
  int maxThreads;
  int availThreads;
  int visPageSizeInPixels;
  int holderSizeInPages;
  int lightCount;
  int MIN_MIP;
  int MAX_MIP;
  int AVG_MIP;
  int blockMip;
  int hmChannel;
  int idChannel;
  int densityChannel;
  int blockChannel;
  int stChannel;
  int btChannel;
  int pathChannel;
  int houseChannel;
  int * curDiagram;
  int * provinceGrid;
  int * provinceX;
  int * provinceY;
  bool doDrawFBO;
  bool lastProcResult;
  bool mapLockOn;
  bool foundPath;
  float mapStep;
  float mapTrans;
  float newZoom;
  int (dirFlags) [4];
  int (dirFlagsOp) [4];
  int (dirFlagsO) [4];
  int (dirFlagsOpO) [4];
  int (dirModX) [6];
  int (dirModY) [6];
  int (dirModZ) [6];
  int (opDir) [4];
  GameLight * (activeLights) [MAX_EVAL_LIGHTS];
  int dirFlagClear;
  int visFlag;
  int visFlagO;
  int activeFBO;
  bool noiseGenerated;
  bool wavesGenerated;
  std::vector <coordAndIndex> roadCoords;
  std::vector <GamePageHolder *> holdersToRefresh;
  vector <int> ocThreads;
  FIVector4 lScreenCoords;
  FIVector4 cScreenCoords;
  FIVector4 worldSizeInPages;
  FIVector4 worldSizeInHolders;
  FIVector4 worldSizeInBlocks;
  FIVector4 geomMin;
  FIVector4 geomMax;
  FIVector4 camPagePos;
  FIVector4 camHolderPos;
  FIVector4 cutHolderPos;
  FIVector4 camBlockPos;
  FIVector4 iPixelWorldCoords;
  FIVector4 pagePos;
  FIVector4 unitPos;
  FIVector4 lastUnitPos;
  FIVector4 lastPagePos;
  FIVector4 tempVec1;
  FIVector4 tempVec2;
  FIVector4 tempVec3;
  FIVector4 (blockPos) [2];
  FIVector4 (nodePos) [2];
  FIVector4 (nodePosInPixels) [2];
  PathNode (blockAndIndexPath) [2];
  PathNode (blockAndIndexSplitPath) [2];
  FIVector4 (lineSeg) [2];
  PathHolder * finalPath;
  int (nodeInd) [2];
  GameBlock * (blockRef) [2];
  FIVector4 minLRInPixels;
  FIVector4 maxLRInPixels;
  FIVector4 minLRInHolders;
  FIVector4 maxLRInHolders;
  FIVector4 minv;
  FIVector4 maxv;
  FIVector4 tempVec;
  FIVector4 unitPosMin;
  FIVector4 unitPosMax;
  FIVector4 startBounds;
  FIVector4 endBounds;
  FIVector4 * fogPos;
  FIVector4 * cutPos;
  FIVector4 * lightPos;
  FIVector4 * globLightPos;
  FIVector4 lightPosBase;
  FIVector4 * cameraPos;
  FIVector4 * curBoxPos;
  FIVector4 tv0;
  FIVector4 tv1;
  FIVector4 tv2;
  FIVector4 tv3;
  FIVector4 tv4;
  FIVector4 tv5;
  Singleton * singleton;
  GameBlock * * blockData;
  FBOWrapper * curFBO;
  FBOWrapper * curFBO2;
  GameWorld ();
  void init (Singleton * _singleton);
  GameBlock * getBlockAtCoords (int xInBlocks, int yInBlocks, bool createOnNull = false);
  GamePageHolder * getHolderAtCoords (int x, int y, int z, bool createOnNull = false);
  GamePageHolder * getHolderAtId (intPair id);
  GameBlock * getBlockAtId (int id);
  GamePage * getPageAtIndex (int ind);
  GamePage * getPageAtCoords (int x, int y, int z, bool createOnNull = false);
  bool checkBounds (int k);
  void update ();
  bool processPages ();
  bool addHolderToRefresh (GamePageHolder * toAdd);
  int getHoldersInGeom (GameGeom * gg);
  void refreshHoldersInList (bool doImmediate);
  void actionOnHolders (int action, bool instantRefresh = false, bool clearEverything = false);
  void drawHolder (GamePageHolder * gp, int curLayer, float xoff, float yoff, float zoff);
  void combineHolders ();
  void combineBuffers ();
  void transformEnt (GameEnt * curEnt);
  void drawEnt (GameEnt * curEnt, bool drawAll);
  void drawNodeEnt (GameEntNode * curNode, FIVector4 * basePosition, float scale, int drawMode, bool drawAll);
  void clearVisitedPaths (PathHolder * pathHolder);
  void clearPathList (PathHolder * pathHolder);
  float getIdealPathLength (PathNode * blockAndIndex);
  int findAIPathRBT (PathHolder * pathHolder, PathNode * blockAndIndex, float _pathSlack);
  void drawPathLine (PathHolder * curPath, int r, int g, int b, float lw, float zoff);
  void drawAIPath (PathHolder * pathHolder, PathHolder * splitPathHolder);
  void renderGeom ();
  void modifyUnit (FIVector4 * fPixelWorldCoordsBase, E_BRUSH brushAction);
  void renderWorldSpaceGPU (float processPagesFBO, float processGeomFBO, float processWaterFBO);
  void getWorldSpaceBuffer ();
  float weighPath (float x1, float y1, float x2, float y2, float rad, bool doSet, bool isOcean);
  float findBestPath (float x1, float y1, float x2, float y2, int generation, int roadIndex, bool doSet, bool isOcean);
  void initMap ();
  void drawMap ();
  void doBlur (string fboName, float blurAmount);
  void updateLights ();
  void postProcess ();
  ~ GameWorld ();
};
#undef LZZ_INLINE
#endif
 
