#pragma once
#include "UtilityBoxForCPP.h"
#include <stdio.h>
#include <fstream>

struct Vector4
{
public:
	Vector4() {}
	Vector4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}
	float x = 0;
	float y = 0;
	float z = 0;
	float w = 0;
};

struct Vector3
{
public:
	Vector3() {}
	Vector3(float x, float y, float z) : x(x), y(y), z(z) {}
	float x = 0;
	float y = 0;
	float z = 0;
};

struct Vector2
{
public:
	Vector2() {}
	Vector2(float x, float y) : x(x), y(y) {}
	float x = 0;
	float y = 0;
};

struct Material
{
public:
	Material() {}
	enum SurfaceTypeEnum
	{
		Opaque,
		Transparent
	};

	enum CullModeEnum
	{
		Off,
		Front,
		Back,
	};

	enum MaterialTypeEnum
	{
		SubsurfaceScattering,
		Standard,
		Anisotropy,
		Iridescence,
		SpecularColor,
		Translucent
	};
	bool doubleSided = false;
	MaterialTypeEnum materialType = Standard;
	CullModeEnum cullMode = Back;
	SurfaceTypeEnum surfaceType = Opaque;
	StaticString* baseMapPath = nullptr;
	Vector4 baseColor = Vector4(0,0,0,0);
	float metallic = 0;
	float smoothness = 0;
	StaticString* normalMapPath = nullptr;
	float normalScale = 0;
};

struct Bounds
{
public:
	Vector3 center;
	Vector3 extents;
};

struct Mesh
{
public:
	Mesh() {}
	Mesh(const char* name, int length)
	{
		this->name = new StaticString(name, length);
	}
	Mesh(StaticString* name)
	{
		this->name = new StaticString(name->GetCharPointer(), name->GetCount());
	}
	~Mesh() 
	{
		delete this->name;
		delete this->vertices;
		delete this->normals;
		delete this->triangles;
		delete this->tangents;
		delete this->colors;
		delete this->uv;
		delete this->uv2;
		delete this->uv3;
		delete this->uv4;
		delete this->uv5;
		delete this->uv6;
		delete this->uv7;
		delete this->uv8;
		cout << "Mesh Å¬·¡½º ¼Ò¸ê" << endl;
	}
	StaticString* name = nullptr;
	StaticArray<Vector3>* vertices = nullptr;
	StaticArray<int>* triangles = nullptr;
	StaticArray<Vector3>* normals = nullptr;
	StaticArray<Vector4>* tangents = nullptr;
	StaticArray<Vector4>* colors = nullptr;
	StaticArray<Vector2>* uv = nullptr;
	StaticArray<Vector2>* uv2 = nullptr;
	StaticArray<Vector2>* uv3 = nullptr;
	StaticArray<Vector2>* uv4 = nullptr;
	StaticArray<Vector2>* uv5 = nullptr;
	StaticArray<Vector2>* uv6 = nullptr;
	StaticArray<Vector2>* uv7 = nullptr;
	StaticArray<Vector2>* uv8 = nullptr;
	Bounds bounds;
};

struct CustomFemaleCharacter
{
public:
	enum FootwearEnum
	{
		NoFootwear,
		AnkleBoots,
		Boots,
		HighHeels,
		Sandals,
		Sneaker1,
		Sneaker2,
		Socks
	};
	enum LowerwearEnum
	{
		Underwear,
		Jeans,
		JeansBaggy,
		JoggingPants,
		SkirtGray,
	};
	enum UpperwearEnum
	{
		Bra,
		CropTop1,
		CropTop2,
		DenimJacket,
		Hoodie,
		LeatherJacket,
		Shirt,
		Sleeveless,
		Sweater,
		TShirt,
		Vest
	};
	enum EyebrowsEnum
	{
		NoEyebrows,
		Eyebrows1,
		Eyebrows2,
		Eyebrows3,
		Eyebrows4,
		Eyebrows5,
	};
	enum GlassesEnum
	{
		NoGlasses,
		Aviator,
		Variant
	};
	enum MakeUpsEnum
	{
		NoMakeUps,
		MakeUps1,
		MakeUps2,
		MakeUps3,
		MakeUps4
	};
	enum HairsEnum
	{
		NoHairs,
		AfroCurl,
		AfroShort,
		Bob,
		Long,
		LongFringe,
		Ponytail1,
		Ponytail2,
		ShortFringe,
		ShortMiddlePart,
		SidePart,
		Wavey,
	};
	enum WristwatchEnum
	{
		NoWristwatch,
		Wristwatch
	};
	struct BlendShapesStruct
	{
	public:
		float jawForward;
		float jawLeft;
		float mouthRollLower;
		float mouthRollUpper;
		float mouthClose;
		float mouthPressRight;
		float mouthPressLeft;
		float mouthStretchLeft;
		float mouthStretchRight;
		float cheekPuff;
		float mouthShrugLower;
		float mouthShrugUpper;
		float mouthDimpleRight;
		float mouthUpperUpLeft;
		float noseSneerLeft;
		float noseSneerRight;
		float eyeLookOutRight;
		float eyeLookInLeft;
		float eyeLookUpLeft;
		float eyeBlinkLeft;
		float eyeSquintRight;
		float cheekSquintRight;
		float eyeWideLeft;
		float browDownRight;
		float browDownLeft;
		float sil;
		float ou;
		float laughter;
		float TH;
		float SS;
		float RR;
		float PP;
		float oh;
		float nn;
		float kk;
		float ih;
		float FF;
		float E;
		float DD;
		float CH;
		float mouthFunnel;
		float aa;
		float mouthLowerDownLeft;
		float mouthFrownLeft;
		float mouthSmileLeft;
		float shp_face_05;
		float shp_face_01;
		float shp_mouth_07;
		float mod_jaw_height;
		float shp_mouth_06;
		float shp_eyes_06;
		float mod_mouth_height;
		float mod_nose_tip_angle;
		float shp_ears_07;
		float mod_eyes_size;
		float mod_nose_tip;
		float shp_eyes_02;
		float mod_nose_curve;
		float shp_ears_06;
		float mod_nose_size;
		float mod_chin_height;
		float shp_mouth_05;
		float shp_mouth_08;
		float shp_face_02;
		float shp_ears_09;
		float mod_chin_size;
		float shp_face_07;
		float shp_nose_08;
		float shp_nose_05;
		float shp_eyes_01;
		float shp_mouth_09;
		float browOuterUpLeft;
		float cheekSquintLeft;
		float eyeSquintLeft;
		float eyeLookInRight;
		float browOuterUpRight;
		float eyeLookOutLeft;
		float mouthLowerDownRight;
		float mouthRight;
		float mouthPucker;
		float mouthUpperUpRight;
		float eyeLookUpRight;
		float eyeBlinkRight;
		float shp_brow_05;
		float body_curvy;
		float shp_face_06;
		float shp_mouth_02;
		float shp_brow_02;
		float shp_eyes_08;
		float shp_eyes_07;
		float shp_ears_08;
		float shp_face_08;
		float shp_ears_02;
		float shp_mouth_03;
		float shp_ears_03;
		float shp_ears_05;
		float shp_ears_04;
		float shp_nose_02;
		float shp_face_03;
		float body_fat;
		float shp_eyes_03;
		float body_skinny;
		float body_muscular;
		float shp_nose_01;
		float mod_mouth_size;
		float mod_eyes_depth;
		float mod_mouth_depth;
		float mod_eyes_narrow;
		float mod_eyes_height;
		float mod_1D_nasolabial_fold;
		float mod_underbite;
		float shp_mouth_01;
		float shp_brow_01;
		float mod_chin_width;
		float mod_brow_depth;
		float body_breastsize;
		float shp_ears_01;
		float mod_jaw_width;
		float shp_mouth_04;
		float shp_eyes_04;
		float shp_nose_03;
		float shp_nose_04;
		float shp_brow_06;
		float shp_brow_04;
		float shp_face_04;
		float shp_brow_08;
		float shp_brow_07;
		float shp_nose_07;
		float shp_eyes_05;
		float jawRight;
		float mouthLeft;
		float mouthFrownRight;
		float mouthSmileRight;
		float jawOpen;
		float browInnerUp;
		float eyeWideRight;
		float mouthDimpleLeft;
		float mod_ears_size;
		float mod_brow_height;
		float shp_brow_03;
		float shp_brow_09;
		float shp_face_09;
		float shp_nose_09;
		float shp_eyes_09;
		float shp_nose_06;
		float eyeLookDownLeft;
		float eyeLookDownRight;
	};
	FootwearEnum footwear;
	LowerwearEnum lowerwear;
	UpperwearEnum upperwear;
	EyebrowsEnum eyebrows = EyebrowsEnum::Eyebrows1;
	GlassesEnum glasses;
	MakeUpsEnum makeUps;
	HairsEnum hairs;
	WristwatchEnum wristwatch;
	BlendShapesStruct blendShapes;
	Vector4 hairColor = Vector4(0.3411765f, 0.2784314f, 0.2235294f, 1.0f);
	Vector4 eyebrowColor = Vector4(0.3411765f, 0.2784314f, 0.2235294f, 1.0f);
	Vector4 skinColor = Vector4(1, 1, 1, 0);
	Vector4 lipColor = Vector4(0.7450981f, 0, 0, 0);
	Vector4 eyesColor = Vector4(0.4156863f, 0.5921569f, 0.6431373f, 1);
	float makeUpAlpha;
	float wrinkles = 0.1f;
};

struct CustomMaleCharacter
{
public:
	enum FootwearEnum
	{
		NoFootwear,
		Boots,
		DressShoes,
		Sandals,
		Sneaker1,
		Sneaker2,
		Socks
	};
	enum LowerwearEnum
	{
		Underwear,
		CargoPants,
		Jeans,
		Shorts,
		SuitPants,
	};
	enum UpperwearEnum
	{
		NoUpperwear,
		CasualShirt,
		Hoodie,
		Jacket,
		PaloShirt,
		Shirt,
		SuitJacket,
		TShirt
	};
	enum BeardsEnum
	{
		NoBeards,
		Beards1,
		Beards2,
		Beards3,
		Beards4,
	};
	enum EyebrowsEnum
	{
		NoEyebrows,
		Eyebrows1,
		Eyebrows2,
		Eyebrows3,
		Eyebrows4,
		Eyebrows5,
	};
	enum GlassesEnum
	{
		NoGlasses,
		Aviator,
		Variant
	};
	enum MakeUpsEnum
	{
		NoMakeUps,
		MakeUps1,
		MakeUps2,
		MakeUps3,
		MakeUps4
	};
	enum HairsEnum
	{
		NoHairs,
		AfroCurl,
		AfroShort,
		Long,
		Receded,
		ShortFringe,
		ShortMiddlePart,
		SidePart1,
		SidePart2,
	};
	enum WristwatchEnum
	{
		NoWristwatch,
		Wristwatch
	};
	struct BlendShapesStruct
	{
	public:
		float jawForward;
		float jawLeft;
		float mouthRollLower;
		float mouthRollUpper;
		float mouthClose;
		float mouthPressRight;
		float mouthPressLeft;
		float mouthStretchLeft;
		float mouthStretchRight;
		float cheekPuff;
		float mouthShrugLower;
		float mouthShrugUpper;
		float mouthDimpleRight;
		float mouthUpperUpLeft;
		float noseSneerLeft;
		float noseSneerRight;
		float eyeLookOutRight;
		float eyeLookInLeft;
		float eyeLookUpLeft;
		float eyeBlinkLeft;
		float eyeSquintRight;
		float cheekSquintRight;
		float eyeWideLeft;
		float browDownRight;
		float browDownLeft;
		float sil;
		float ou;
		float laughter;
		float TH;
		float SS;
		float RR;
		float PP;
		float oh;
		float nn;
		float kk;
		float ih;
		float FF;
		float E;
		float DD;
		float CH;
		float mouthFunnel;
		float aa;
		float mouthLowerDownLeft;
		float mouthFrownLeft;
		float mouthSmileLeft;
		float shp_face_05;
		float shp_face_01;
		float shp_mouth_07;
		float mod_jaw_height;
		float shp_mouth_06;
		float shp_eyes_06;
		float mod_mouth_height;
		float mod_nose_tip_angle;
		float shp_ears_07;
		float mod_eyes_size;
		float mod_nose_tip;
		float shp_eyes_02;
		float mod_nose_curve;
		float shp_ears_06;
		float mod_nose_size;
		float mod_chin_height;
		float shp_mouth_05;
		float shp_mouth_08;
		float shp_face_02;
		float shp_ears_09;
		float mod_chin_size;
		float shp_face_07;
		float shp_nose_08;
		float shp_nose_05;
		float shp_eyes_01;
		float shp_mouth_09;
		float browOuterUpLeft;
		float cheekSquintLeft;
		float eyeSquintLeft;
		float eyeLookInRight;
		float browOuterUpRight;
		float eyeLookOutLeft;
		float mouthLowerDownRight;
		float mouthRight;
		float mouthPucker;
		float mouthUpperUpRight;
		float eyeLookUpRight;
		float eyeBlinkRight;
		float shp_brow_05;
		float body_curvy;
		float shp_face_06;
		float shp_mouth_02;
		float shp_brow_02;
		float shp_eyes_08;
		float shp_eyes_07;
		float shp_ears_08;
		float shp_face_08;
		float shp_ears_02;
		float shp_mouth_03;
		float shp_ears_03;
		float shp_ears_05;
		float shp_ears_04;
		float shp_nose_02;
		float shp_face_03;
		float body_fat;
		float shp_eyes_03;
		float body_skinny;
		float body_muscular;
		float shp_nose_01;
		float mod_mouth_size;
		float mod_eyes_depth;
		float mod_mouth_depth;
		float mod_eyes_narrow;
		float mod_eyes_height;
		float mod_1D_nasolabial_fold;
		float mod_underbite;
		float shp_mouth_01;
		float shp_brow_01;
		float mod_chin_width;
		float mod_brow_depth;
		float body_breastsize;
		float shp_ears_01;
		float mod_jaw_width;
		float shp_mouth_04;
		float shp_eyes_04;
		float shp_nose_03;
		float shp_nose_04;
		float shp_brow_06;
		float shp_brow_04;
		float shp_face_04;
		float shp_brow_08;
		float shp_brow_07;
		float shp_nose_07;
		float jawRight;
		float mouthLeft;
		float mouthFrownRight;
		float mouthSmileRight;
		float jawOpen;
		float browInnerUp;
		float eyeWideRight;
		float mouthDimpleLeft;
		float mod_ears_size;
		float mod_brow_height;
		float shp_brow_03;
		float shp_brow_09;
		float shp_face_09;
		float shp_nose_09;
		float shp_eyes_09;
		float shp_nose_06;
		float eyeLookDownLeft;
		float eyeLookDownRight;
		float shp_eyes_05;
	};
	FootwearEnum footwear;
	LowerwearEnum lowerwear;
	UpperwearEnum upperwear;
	BeardsEnum beards;
	EyebrowsEnum eyebrows = EyebrowsEnum::Eyebrows1;
	GlassesEnum glasses;
	MakeUpsEnum makeUps;
	HairsEnum hairs;
	WristwatchEnum wristwatch;
	BlendShapesStruct blendShapes;
	Vector4 hairColor = Vector4(0.3411765f, 0.2784314f, 0.2235294f, 1.0f);
	Vector4 eyebrowColor = Vector4(0.3411765f, 0.2784314f, 0.2235294f, 1.0f);
	Vector4 skinColor = Vector4(1, 1, 1, 0);
	Vector4 lipColor = Vector4(0.7450981f, 0, 0, 0);
	Vector4 eyesColor = Vector4(0.4156863f, 0.5921569f, 0.6431373f, 1);
	float makeUpAlpha;
	float wrinkles = 0.1f;
};

struct Transform
{
public:
	StaticString* name = nullptr;
	Vector3 localPos;
	Vector3 localRot;
	Vector3 localScale;
};

struct GeneralMeshRenderer
{
public:
	StaticString* meshPath = nullptr;
	StaticString* matPath = nullptr;
	bool castShadows;
};

struct MaleCharacterCompStruct
{
public:
	StaticString* characterPath = nullptr;
	float walkSpeed;
	float runSpeed;
	float jumpPower;
	int initJumpCount;
};

struct FemaleCharacterCompStruct
{
public:
	StaticString* characterPath = nullptr;
	float walkSpeed;
	float runSpeed;
	float jumpPower;
	int initJumpCount;
};

struct Light
{
public:
	Vector4 filter;
	float intensity;
	float range;
	bool shadowsEnable;
};

struct MeshCollider
{
public:
	bool enable;
};

struct PhysicsCompStruct
{
public:
	float mass;
	float drag;
	bool useGravity;
};

struct WaterCompStruct
{
public:
	Vector4 baseColor;
	bool underWater;
};

struct Components
{
public:
	Transform* transform = nullptr;
	GeneralMeshRenderer* generalMeshRenderer = nullptr;
	MaleCharacterCompStruct* maleCharacterComp = nullptr;
	FemaleCharacterCompStruct* femaleCharacterComp = nullptr;
	Light* light = nullptr;
	MeshCollider* meshCollider = nullptr;
	PhysicsCompStruct* physicsComp = nullptr;
	WaterCompStruct* waterComp = nullptr;
};

struct AlepObjectNode
{
public:
	int parentIndex;
	int nextIndex;
	int prevIndex;
	int firstChildIndex;
	int depth;
	int componentsIndex;
};

struct Stage
{
public:
	StaticArray<AlepObjectNode>* alepObjectNodes;
	StaticArray<int>* availableIndices;
};

#define MeshBase 0
#define MaterialBase 1
#define MaleBase 2
#define FemaleBase 3
#define ComponentsBase 4
#define StageBase 5

#define Vertices 0
#define Triangles 1
#define Normals 2
#define Tangents 3
#define Colors 4
#define UV 5
#define UV2 6
#define UV3 7
#define UV4 8
#define UV5 9
#define UV6 10
#define UV7 11
#define UV8 12
#define Bounds 13

#define DoubleSided 0
#define MaterialType 1
#define CullMode 2
#define SurfaceType 3
#define BaseMapPath 4
#define BaseColor 5
#define Metallic 6
#define Smoothness 7
#define NormalMapPath 8
#define NormalScale 9

#define Footwear 0
#define Lowerwear 1
#define Upperwear 2
#define Beards 3
#define Eyebrows 4
#define Glasses 5
#define MakeUps 6
#define Hairs 7
#define Wristwatch 8
#define BlendShapes 9
#define HairColor 10
#define EyebrowColor 11
#define SkinColor 12
#define LipColor 13
#define EyesColor 14
#define MakeUpAlpha 15
#define Wrinkles 16

#define TransformComp 0
#define GeneralMeshRendererComp 1
#define MaleCharacterComp 2
#define FemaleCharacterComp 3
#define LightComp 4
#define MeshColliderComp 5
#define PhysicsComp 6
#define WaterComp 7

#define AlepObjectNodes 0
#define AvailableIndices 1

class Unserializer
{
public:
#define WordBufferSize 200
	Unserializer()
	{
		wordBuffer = new StaticString(WordBufferSize);
	};
	~Unserializer()
	{
		delete wordBuffer;
		cout << "\nUnserializer ¼Ò¸ê\n";
	};
	void* StartUnserialize(StaticString* path)
	{
		fileStream.open(path->GetCharPointer());
		if (fileStream.is_open())
		{
			return StandardBaseDecoder();
		}
		else
		{
			return nullptr;
		}
	}
private:
	StaticString* wordBuffer;
	ifstream fileStream;
	bool finishedFlag = false;
	void* (Unserializer::*baseDecoders[6])() =
	{
		&Unserializer::MeshBaseDecoder,
		&Unserializer::MaterialBaseDecoder,
		&Unserializer::MaleCharacterBaseDecoder,
		&Unserializer::FemaleCharacterBaseDecoder,
		&Unserializer::ComponentsBaseDecoder,
		&Unserializer::StageBaseDecoder,
	};
	void (Unserializer::*meshDecoders[15])(Mesh*) =
	{
		&Unserializer::VerticesDecoder,
		&Unserializer::TrianglesDecoder,
		&Unserializer::NormalsDecoder,
		&Unserializer::TangentsDecoder,
		&Unserializer::ColorsDecoder,
		&Unserializer::UVDecoder,
		&Unserializer::UV2Decoder,
		&Unserializer::UV3Decoder,
		&Unserializer::UV4Decoder,
		&Unserializer::UV5Decoder,
		&Unserializer::UV6Decoder,
		&Unserializer::UV7Decoder,
		&Unserializer::UV8Decoder,
		&Unserializer::BoundsDecoder,
	};
	void (Unserializer::*materialDecoders[10])(Material*) =
	{
		&Unserializer::DoubleSidedDecoder,
		&Unserializer::MaterialTypeDecoder,
		&Unserializer::CullModeDecoder,
		&Unserializer::SurfaceDecoder,
		&Unserializer::BaseMapDecoder,
		&Unserializer::BaseColorDecoder,
		&Unserializer::MetallicDecoder,
		&Unserializer::SmoothnessDecoder,
		&Unserializer::NormalMapDecoder,
		&Unserializer::NormalScaleDecoder,
	};
	void (Unserializer::*maleCharacterDecoders[17])(CustomMaleCharacter*) =
	{
		&Unserializer::MFootwear,
		&Unserializer::MLowerwear,
		&Unserializer::MUpperwear,
		&Unserializer::MBeards,
		&Unserializer::MEyebrows,
		&Unserializer::MGlasses,
		&Unserializer::MMakeUps,
		&Unserializer::MHairs,
		&Unserializer::MWristwatch,
		&Unserializer::MBlendShapes,
		&Unserializer::MHairColor,
		&Unserializer::MEyebrowColor,
		&Unserializer::MSkinColor,
		&Unserializer::MLipColor,
		&Unserializer::MEyesColor,
		&Unserializer::MMakeUpAlpha,
		&Unserializer::MWrinkles,
	};
	void (Unserializer::* femaleCharacterDecoders[17])(CustomFemaleCharacter*) =
	{
		&Unserializer::FFootwear,
		&Unserializer::FLowerwear,
		&Unserializer::FUpperwear,
		&Unserializer::FVoid,
		&Unserializer::FEyebrows,
		&Unserializer::FGlasses,
		&Unserializer::FMakeUps,
		&Unserializer::FHairs,
		&Unserializer::FWristwatch,
		&Unserializer::FBlendShapes,
		&Unserializer::FHairColor,
		&Unserializer::FEyebrowColor,
		&Unserializer::FSkinColor,
		&Unserializer::FLipColor,
		&Unserializer::FEyesColor,
		&Unserializer::FMakeUpAlpha,
		&Unserializer::FWrinkles,
	};
	void (Unserializer::* compsDecoders[8])(Components*) =
	{
		&Unserializer::TransformDecoder,
		&Unserializer::GeneralMeshRendererDecoder,
		&Unserializer::MaleCharacterCompDecoder,
		&Unserializer::FemaleCharacterCompDecoder,
		&Unserializer::LightDecoder,
		&Unserializer::MeshColliderDecoder,
		&Unserializer::PhysicsCompDecoder,
		&Unserializer::WaterCompDecoder,
	};
	void (Unserializer::* stageDecoders[2])(Stage*) =
	{
		&Unserializer::AlepObjectNodesDecoder,
		&Unserializer::AvailableIndicesDecoder,
	};
	void* StandardBaseDecoder()
	{
		return (this->*baseDecoders[GetInt()])();
	}
	void* MeshBaseDecoder()
	{
		GetWord();
		Mesh* mesh = new Mesh(wordBuffer);
		int decoderIndex = GetInt();
		while (!finishedFlag)
		{
			(this->*meshDecoders[decoderIndex])(mesh);
			decoderIndex = GetInt();
		}
		return mesh;
	}
	void* MaterialBaseDecoder()
	{
		Material* mat = new Material();
		int decoderIndex = GetInt();
		while (!finishedFlag)
		{
			(this->*materialDecoders[decoderIndex])(mat);
			decoderIndex = GetInt();
		}
		return mat;
	}
	void* MaleCharacterBaseDecoder()
	{
		CustomMaleCharacter* character = new CustomMaleCharacter();
		int decoderIndex = GetInt();
		while (!finishedFlag)
		{
			(this->*maleCharacterDecoders[decoderIndex])(character);
			decoderIndex = GetInt();
		}
		return character;
	}
	void* FemaleCharacterBaseDecoder()
	{
		CustomFemaleCharacter* character = new CustomFemaleCharacter();
		int decoderIndex = GetInt();
		while (!finishedFlag)
		{
			(this->*femaleCharacterDecoders[decoderIndex])(character);
			decoderIndex = GetInt();
		}
		return character;
	}
	void* ComponentsBaseDecoder()
	{
		Components* comps = new Components();
		int decoderIndex = GetInt();
		while (!finishedFlag)
		{
			(this->*compsDecoders[decoderIndex])(comps);
			decoderIndex = GetInt();
		}
		return comps;
	}
	void* StageBaseDecoder()
	{
		Stage* stage = new Stage();
		int decoderIndex = GetInt();
		while (!finishedFlag)
		{
			(this->*stageDecoders[decoderIndex])(stage);
			decoderIndex = GetInt();
		}
		return stage;
	}
	void AlepObjectNodesDecoder(Stage* stage)
	{
		int length = GetInt();
		StaticArray<AlepObjectNode>* alepObjectNodes = new StaticArray<AlepObjectNode>(length);
		for (size_t i = 0; i < length; i++)
		{
			AlepObjectNode alepObjectNode;
			alepObjectNode.parentIndex = GetInt();
			alepObjectNode.nextIndex = GetInt();
			alepObjectNode.prevIndex = GetInt();
			alepObjectNode.firstChildIndex = GetInt();
			alepObjectNode.depth = GetInt();
			alepObjectNode.componentsIndex = GetInt();
			alepObjectNodes->Add(alepObjectNode);
		}
		stage->alepObjectNodes = alepObjectNodes;
	}
	void AvailableIndicesDecoder(Stage* stage)
	{
		int length = GetInt();
		StaticArray<int>* availableIndices = new StaticArray<int>(length);
		for (size_t i = 0; i < length; i++)
		{
			availableIndices->Add(GetInt());
		}
		stage->availableIndices = availableIndices;
	}
	void TransformDecoder(Components* comps)
	{
		Transform* transform = new Transform();
		comps->transform = transform;
		GetWord();
		transform->name = new StaticString(wordBuffer->GetCharPointer(), wordBuffer->GetCount());
		transform->localPos = GetVector3();
		transform->localRot = GetVector3();
		transform->localScale = GetVector3();
	}
	void GeneralMeshRendererDecoder(Components* comps)
	{
		GeneralMeshRenderer* generalMeshRenderer = new GeneralMeshRenderer();
		comps->generalMeshRenderer = generalMeshRenderer;
		GetWord();
		generalMeshRenderer->meshPath = new StaticString(wordBuffer->GetCharPointer(), wordBuffer->GetCount());
		GetWord();
		generalMeshRenderer->matPath = new StaticString(wordBuffer->GetCharPointer(), wordBuffer->GetCount());
		generalMeshRenderer->castShadows = GetInt();
	}
	void MaleCharacterCompDecoder(Components* comps)
	{
		MaleCharacterCompStruct* maleCharacterComp = new MaleCharacterCompStruct();
		comps->maleCharacterComp = maleCharacterComp;
		GetWord();
		maleCharacterComp->characterPath = new StaticString(wordBuffer->GetCharPointer(), wordBuffer->GetCount());
		maleCharacterComp->walkSpeed = GetFloat();
		maleCharacterComp->runSpeed = GetFloat();
		maleCharacterComp->jumpPower = GetFloat();
		maleCharacterComp->initJumpCount = GetInt();
	}
	void FemaleCharacterCompDecoder(Components* comps)
	{
		FemaleCharacterCompStruct* femaleCharacterComp = new FemaleCharacterCompStruct();
		comps->femaleCharacterComp = femaleCharacterComp;
		GetWord();
		femaleCharacterComp->characterPath = new StaticString(wordBuffer->GetCharPointer(), wordBuffer->GetCount());
		femaleCharacterComp->walkSpeed = GetFloat();
		femaleCharacterComp->runSpeed = GetFloat();
		femaleCharacterComp->jumpPower = GetFloat();
		femaleCharacterComp->initJumpCount = GetInt();
	}
	void LightDecoder(Components* comps)
	{
		Light* light = new Light();
		comps->light = light;
		light->filter = GetVector4();
		light->intensity = GetFloat();
		light->range = GetFloat();
		light->shadowsEnable = GetInt();
	}
	void MeshColliderDecoder(Components* comps)
	{
		MeshCollider* meshCollider = new MeshCollider();
		comps->meshCollider = meshCollider;
		meshCollider->enable = GetInt();
	}
	void PhysicsCompDecoder(Components* comps)
	{
		PhysicsCompStruct* physicsComp = new PhysicsCompStruct();
		comps->physicsComp = physicsComp;
		physicsComp->mass = GetFloat();
		physicsComp->drag = GetFloat();
		physicsComp->useGravity = GetInt();
	}
	void WaterCompDecoder(Components* comps)
	{
		WaterCompStruct* waterComp = new WaterCompStruct();
		comps->waterComp = waterComp;
		waterComp->baseColor = GetVector4();
		waterComp->underWater = GetInt();
	}
	void FFootwear(CustomFemaleCharacter* character)
	{
		character->footwear = (CustomFemaleCharacter::FootwearEnum)GetInt();
	}
	void FLowerwear(CustomFemaleCharacter* character)
	{
		character->lowerwear = (CustomFemaleCharacter::LowerwearEnum)GetInt();
	}
	void FUpperwear(CustomFemaleCharacter* character)
	{
		character->upperwear = (CustomFemaleCharacter::UpperwearEnum)GetInt();
	}
	void FVoid(CustomFemaleCharacter* character) {}
	void FEyebrows(CustomFemaleCharacter* character)
	{
		character->eyebrows = (CustomFemaleCharacter::EyebrowsEnum)GetInt();
	}
	void FGlasses(CustomFemaleCharacter* character)
	{
		character->glasses = (CustomFemaleCharacter::GlassesEnum)GetInt();
	}
	void FMakeUps(CustomFemaleCharacter* character)
	{
		character->makeUps = (CustomFemaleCharacter::MakeUpsEnum)GetInt();
	}
	void FHairs(CustomFemaleCharacter* character)
	{
		character->hairs = (CustomFemaleCharacter::HairsEnum)GetInt();
	}
	void FWristwatch(CustomFemaleCharacter* character)
	{
		character->wristwatch = (CustomFemaleCharacter::WristwatchEnum)GetInt();
	}
	void FBlendShapes(CustomFemaleCharacter* character)
	{
		character->blendShapes.jawForward = GetFloat();
		character->blendShapes.jawLeft = GetFloat();
		character->blendShapes.mouthRollLower = GetFloat();
		character->blendShapes.mouthRollUpper = GetFloat();
		character->blendShapes.mouthClose = GetFloat();
		character->blendShapes.mouthPressRight = GetFloat();
		character->blendShapes.mouthPressLeft = GetFloat();
		character->blendShapes.mouthStretchLeft = GetFloat();
		character->blendShapes.mouthStretchRight = GetFloat();
		character->blendShapes.cheekPuff = GetFloat();
		character->blendShapes.mouthShrugLower = GetFloat();
		character->blendShapes.mouthShrugUpper = GetFloat();
		character->blendShapes.mouthDimpleRight = GetFloat();
		character->blendShapes.mouthUpperUpLeft = GetFloat();
		character->blendShapes.noseSneerLeft = GetFloat();
		character->blendShapes.noseSneerRight = GetFloat();
		character->blendShapes.eyeLookOutRight = GetFloat();
		character->blendShapes.eyeLookInLeft = GetFloat();
		character->blendShapes.eyeLookUpLeft = GetFloat();
		character->blendShapes.eyeBlinkLeft = GetFloat();
		character->blendShapes.eyeSquintRight = GetFloat();
		character->blendShapes.cheekSquintRight = GetFloat();
		character->blendShapes.eyeWideLeft = GetFloat();
		character->blendShapes.browDownRight = GetFloat();
		character->blendShapes.browDownLeft = GetFloat();
		character->blendShapes.sil = GetFloat();
		character->blendShapes.ou = GetFloat();
		character->blendShapes.laughter = GetFloat();
		character->blendShapes.TH = GetFloat();
		character->blendShapes.SS = GetFloat();
		character->blendShapes.RR = GetFloat();
		character->blendShapes.PP = GetFloat();
		character->blendShapes.oh = GetFloat();
		character->blendShapes.nn = GetFloat();
		character->blendShapes.kk = GetFloat();
		character->blendShapes.ih = GetFloat();
		character->blendShapes.FF = GetFloat();
		character->blendShapes.E = GetFloat();
		character->blendShapes.DD = GetFloat();
		character->blendShapes.CH = GetFloat();
		character->blendShapes.mouthFunnel = GetFloat();
		character->blendShapes.aa = GetFloat();
		character->blendShapes.mouthLowerDownLeft = GetFloat();
		character->blendShapes.mouthFrownLeft = GetFloat();
		character->blendShapes.mouthSmileLeft = GetFloat();
		character->blendShapes.shp_face_05 = GetFloat();
		character->blendShapes.shp_face_01 = GetFloat();
		character->blendShapes.shp_mouth_07 = GetFloat();
		character->blendShapes.mod_jaw_height = GetFloat();
		character->blendShapes.shp_mouth_06 = GetFloat();
		character->blendShapes.shp_eyes_06 = GetFloat();
		character->blendShapes.mod_mouth_height = GetFloat();
		character->blendShapes.mod_nose_tip_angle = GetFloat();
		character->blendShapes.shp_ears_07 = GetFloat();
		character->blendShapes.mod_eyes_size = GetFloat();
		character->blendShapes.mod_nose_tip = GetFloat();
		character->blendShapes.shp_eyes_02 = GetFloat();
		character->blendShapes.mod_nose_curve = GetFloat();
		character->blendShapes.shp_ears_06 = GetFloat();
		character->blendShapes.mod_nose_size = GetFloat();
		character->blendShapes.mod_chin_height = GetFloat();
		character->blendShapes.shp_mouth_05 = GetFloat();
		character->blendShapes.shp_mouth_08 = GetFloat();
		character->blendShapes.shp_face_02 = GetFloat();
		character->blendShapes.shp_ears_09 = GetFloat();
		character->blendShapes.mod_chin_size = GetFloat();
		character->blendShapes.shp_face_07 = GetFloat();
		character->blendShapes.shp_nose_08 = GetFloat();
		character->blendShapes.shp_nose_05 = GetFloat();
		character->blendShapes.shp_eyes_01 = GetFloat();
		character->blendShapes.shp_mouth_09 = GetFloat();
		character->blendShapes.browOuterUpLeft = GetFloat();
		character->blendShapes.cheekSquintLeft = GetFloat();
		character->blendShapes.eyeSquintLeft = GetFloat();
		character->blendShapes.eyeLookInRight = GetFloat();
		character->blendShapes.browOuterUpRight = GetFloat();
		character->blendShapes.eyeLookOutLeft = GetFloat();
		character->blendShapes.mouthLowerDownRight = GetFloat();
		character->blendShapes.mouthRight = GetFloat();
		character->blendShapes.mouthPucker = GetFloat();
		character->blendShapes.mouthUpperUpRight = GetFloat();
		character->blendShapes.eyeLookUpRight = GetFloat();
		character->blendShapes.eyeBlinkRight = GetFloat();
		character->blendShapes.shp_brow_05 = GetFloat();
		character->blendShapes.body_curvy = GetFloat();
		character->blendShapes.shp_face_06 = GetFloat();
		character->blendShapes.shp_mouth_02 = GetFloat();
		character->blendShapes.shp_brow_02 = GetFloat();
		character->blendShapes.shp_eyes_08 = GetFloat();
		character->blendShapes.shp_eyes_07 = GetFloat();
		character->blendShapes.shp_ears_08 = GetFloat();
		character->blendShapes.shp_face_08 = GetFloat();
		character->blendShapes.shp_ears_02 = GetFloat();
		character->blendShapes.shp_mouth_03 = GetFloat();
		character->blendShapes.shp_ears_03 = GetFloat();
		character->blendShapes.shp_ears_05 = GetFloat();
		character->blendShapes.shp_ears_04 = GetFloat();
		character->blendShapes.shp_nose_02 = GetFloat();
		character->blendShapes.shp_face_03 = GetFloat();
		character->blendShapes.body_fat = GetFloat();
		character->blendShapes.shp_eyes_03 = GetFloat();
		character->blendShapes.body_skinny = GetFloat();
		character->blendShapes.body_muscular = GetFloat();
		character->blendShapes.shp_nose_01 = GetFloat();
		character->blendShapes.mod_mouth_size = GetFloat();
		character->blendShapes.mod_eyes_depth = GetFloat();
		character->blendShapes.mod_mouth_depth = GetFloat();
		character->blendShapes.mod_eyes_narrow = GetFloat();
		character->blendShapes.mod_eyes_height = GetFloat();
		character->blendShapes.mod_1D_nasolabial_fold = GetFloat();
		character->blendShapes.mod_underbite = GetFloat();
		character->blendShapes.shp_mouth_01 = GetFloat();
		character->blendShapes.shp_brow_01 = GetFloat();
		character->blendShapes.mod_chin_width = GetFloat();
		character->blendShapes.mod_brow_depth = GetFloat();
		character->blendShapes.body_breastsize = GetFloat();
		character->blendShapes.shp_ears_01 = GetFloat();
		character->blendShapes.mod_jaw_width = GetFloat();
		character->blendShapes.shp_mouth_04 = GetFloat();
		character->blendShapes.shp_eyes_04 = GetFloat();
		character->blendShapes.shp_nose_03 = GetFloat();
		character->blendShapes.shp_nose_04 = GetFloat();
		character->blendShapes.shp_brow_06 = GetFloat();
		character->blendShapes.shp_brow_04 = GetFloat();
		character->blendShapes.shp_face_04 = GetFloat();
		character->blendShapes.shp_brow_08 = GetFloat();
		character->blendShapes.shp_brow_07 = GetFloat();
		character->blendShapes.shp_nose_07 = GetFloat();
		character->blendShapes.shp_eyes_05 = GetFloat();
		character->blendShapes.jawRight = GetFloat();
		character->blendShapes.mouthLeft = GetFloat();
		character->blendShapes.mouthFrownRight = GetFloat();
		character->blendShapes.mouthSmileRight = GetFloat();
		character->blendShapes.jawOpen = GetFloat();
		character->blendShapes.browInnerUp = GetFloat();
		character->blendShapes.eyeWideRight = GetFloat();
		character->blendShapes.mouthDimpleLeft = GetFloat();
		character->blendShapes.mod_ears_size = GetFloat();
		character->blendShapes.mod_brow_height = GetFloat();
		character->blendShapes.shp_brow_03 = GetFloat();
		character->blendShapes.shp_brow_09 = GetFloat();
		character->blendShapes.shp_face_09 = GetFloat();
		character->blendShapes.shp_nose_09 = GetFloat();
		character->blendShapes.shp_eyes_09 = GetFloat();
		character->blendShapes.shp_nose_06 = GetFloat();
		character->blendShapes.eyeLookDownLeft = GetFloat();
		character->blendShapes.eyeLookDownRight = GetFloat();
	}
	void FHairColor(CustomFemaleCharacter* character)
	{
		character->hairColor = GetVector4();
	}
	void FEyebrowColor(CustomFemaleCharacter* character)
	{
		character->eyebrowColor = GetVector4();
	}
	void FSkinColor(CustomFemaleCharacter* character)
	{
		character->skinColor = GetVector4();
	}
	void FLipColor(CustomFemaleCharacter* character)
	{
		character->lipColor = GetVector4();
	}
	void FEyesColor(CustomFemaleCharacter* character)
	{
		character->eyesColor = GetVector4();
	}
	void FMakeUpAlpha(CustomFemaleCharacter* character)
	{
		character->makeUpAlpha = GetFloat();
	}
	void FWrinkles(CustomFemaleCharacter* character)
	{
		character->wrinkles = GetFloat();
	}
	void MFootwear(CustomMaleCharacter* character)
	{
		character->footwear = (CustomMaleCharacter::FootwearEnum)GetInt();
	}
	void MLowerwear(CustomMaleCharacter* character)
	{
		character->lowerwear = (CustomMaleCharacter::LowerwearEnum)GetInt();
	}
	void MUpperwear(CustomMaleCharacter* character)
	{
		character->upperwear = (CustomMaleCharacter::UpperwearEnum)GetInt();
	}
	void MBeards(CustomMaleCharacter* character)
	{
		character->beards = (CustomMaleCharacter::BeardsEnum)GetInt();
	}
	void MEyebrows(CustomMaleCharacter* character)
	{
		character->eyebrows = (CustomMaleCharacter::EyebrowsEnum)GetInt();
	}
	void MGlasses(CustomMaleCharacter* character)
	{
		character->glasses = (CustomMaleCharacter::GlassesEnum)GetInt();
	}
	void MMakeUps(CustomMaleCharacter* character)
	{
		character->makeUps = (CustomMaleCharacter::MakeUpsEnum)GetInt();
	}
	void MHairs(CustomMaleCharacter* character)
	{
		character->hairs = (CustomMaleCharacter::HairsEnum)GetInt();
	}
	void MWristwatch(CustomMaleCharacter* character)
	{
		character->wristwatch = (CustomMaleCharacter::WristwatchEnum)GetInt();
	}
	void MBlendShapes(CustomMaleCharacter* character)
	{
		character->blendShapes.jawForward = GetFloat();
		character->blendShapes.jawLeft = GetFloat();
		character->blendShapes.mouthRollLower = GetFloat();
		character->blendShapes.mouthRollUpper = GetFloat();
		character->blendShapes.mouthClose = GetFloat();
		character->blendShapes.mouthPressRight = GetFloat();
		character->blendShapes.mouthPressLeft = GetFloat();
		character->blendShapes.mouthStretchLeft = GetFloat();
		character->blendShapes.mouthStretchRight = GetFloat();
		character->blendShapes.cheekPuff = GetFloat();
		character->blendShapes.mouthShrugLower = GetFloat();
		character->blendShapes.mouthShrugUpper = GetFloat();
		character->blendShapes.mouthDimpleRight = GetFloat();
		character->blendShapes.mouthUpperUpLeft = GetFloat();
		character->blendShapes.noseSneerLeft = GetFloat();
		character->blendShapes.noseSneerRight = GetFloat();
		character->blendShapes.eyeLookOutRight = GetFloat();
		character->blendShapes.eyeLookInLeft = GetFloat();
		character->blendShapes.eyeLookUpLeft = GetFloat();
		character->blendShapes.eyeBlinkLeft = GetFloat();
		character->blendShapes.eyeSquintRight = GetFloat();
		character->blendShapes.cheekSquintRight = GetFloat();
		character->blendShapes.eyeWideLeft = GetFloat();
		character->blendShapes.browDownRight = GetFloat();
		character->blendShapes.browDownLeft = GetFloat();
		character->blendShapes.sil = GetFloat();
		character->blendShapes.ou = GetFloat();
		character->blendShapes.laughter = GetFloat();
		character->blendShapes.TH = GetFloat();
		character->blendShapes.SS = GetFloat();
		character->blendShapes.RR = GetFloat();
		character->blendShapes.PP = GetFloat();
		character->blendShapes.oh = GetFloat();
		character->blendShapes.nn = GetFloat();
		character->blendShapes.kk = GetFloat();
		character->blendShapes.ih = GetFloat();
		character->blendShapes.FF = GetFloat();
		character->blendShapes.E = GetFloat();
		character->blendShapes.DD = GetFloat();
		character->blendShapes.CH = GetFloat();
		character->blendShapes.mouthFunnel = GetFloat();
		character->blendShapes.aa = GetFloat();
		character->blendShapes.mouthLowerDownLeft = GetFloat();
		character->blendShapes.mouthFrownLeft = GetFloat();
		character->blendShapes.mouthSmileLeft = GetFloat();
		character->blendShapes.shp_face_05 = GetFloat();
		character->blendShapes.shp_face_01 = GetFloat();
		character->blendShapes.shp_mouth_07 = GetFloat();
		character->blendShapes.mod_jaw_height = GetFloat();
		character->blendShapes.shp_mouth_06 = GetFloat();
		character->blendShapes.shp_eyes_06 = GetFloat();
		character->blendShapes.mod_mouth_height = GetFloat();
		character->blendShapes.mod_nose_tip_angle = GetFloat();
		character->blendShapes.shp_ears_07 = GetFloat();
		character->blendShapes.mod_eyes_size = GetFloat();
		character->blendShapes.mod_nose_tip = GetFloat();
		character->blendShapes.shp_eyes_02 = GetFloat();
		character->blendShapes.mod_nose_curve = GetFloat();
		character->blendShapes.shp_ears_06 = GetFloat();
		character->blendShapes.mod_nose_size = GetFloat();
		character->blendShapes.mod_chin_height = GetFloat();
		character->blendShapes.shp_mouth_05 = GetFloat();
		character->blendShapes.shp_mouth_08 = GetFloat();
		character->blendShapes.shp_face_02 = GetFloat();
		character->blendShapes.shp_ears_09 = GetFloat();
		character->blendShapes.mod_chin_size = GetFloat();
		character->blendShapes.shp_face_07 = GetFloat();
		character->blendShapes.shp_nose_08 = GetFloat();
		character->blendShapes.shp_nose_05 = GetFloat();
		character->blendShapes.shp_eyes_01 = GetFloat();
		character->blendShapes.shp_mouth_09 = GetFloat();
		character->blendShapes.browOuterUpLeft = GetFloat();
		character->blendShapes.cheekSquintLeft = GetFloat();
		character->blendShapes.eyeSquintLeft = GetFloat();
		character->blendShapes.eyeLookInRight = GetFloat();
		character->blendShapes.browOuterUpRight = GetFloat();
		character->blendShapes.eyeLookOutLeft = GetFloat();
		character->blendShapes.mouthLowerDownRight = GetFloat();
		character->blendShapes.mouthRight = GetFloat();
		character->blendShapes.mouthPucker = GetFloat();
		character->blendShapes.mouthUpperUpRight = GetFloat();
		character->blendShapes.eyeLookUpRight = GetFloat();
		character->blendShapes.eyeBlinkRight = GetFloat();
		character->blendShapes.shp_brow_05 = GetFloat();
		character->blendShapes.body_curvy = GetFloat();
		character->blendShapes.shp_face_06 = GetFloat();
		character->blendShapes.shp_mouth_02 = GetFloat();
		character->blendShapes.shp_brow_02 = GetFloat();
		character->blendShapes.shp_eyes_08 = GetFloat();
		character->blendShapes.shp_eyes_07 = GetFloat();
		character->blendShapes.shp_ears_08 = GetFloat();
		character->blendShapes.shp_face_08 = GetFloat();
		character->blendShapes.shp_ears_02 = GetFloat();
		character->blendShapes.shp_mouth_03 = GetFloat();
		character->blendShapes.shp_ears_03 = GetFloat();
		character->blendShapes.shp_ears_05 = GetFloat();
		character->blendShapes.shp_ears_04 = GetFloat();
		character->blendShapes.shp_nose_02 = GetFloat();
		character->blendShapes.shp_face_03 = GetFloat();
		character->blendShapes.body_fat = GetFloat();
		character->blendShapes.shp_eyes_03 = GetFloat();
		character->blendShapes.body_skinny = GetFloat();
		character->blendShapes.body_muscular = GetFloat();
		character->blendShapes.shp_nose_01 = GetFloat();
		character->blendShapes.mod_mouth_size = GetFloat();
		character->blendShapes.mod_eyes_depth = GetFloat();
		character->blendShapes.mod_mouth_depth = GetFloat();
		character->blendShapes.mod_eyes_narrow = GetFloat();
		character->blendShapes.mod_eyes_height = GetFloat();
		character->blendShapes.mod_1D_nasolabial_fold = GetFloat();
		character->blendShapes.mod_underbite = GetFloat();
		character->blendShapes.shp_mouth_01 = GetFloat();
		character->blendShapes.shp_brow_01 = GetFloat();
		character->blendShapes.mod_chin_width = GetFloat();
		character->blendShapes.mod_brow_depth = GetFloat();
		character->blendShapes.body_breastsize = GetFloat();
		character->blendShapes.shp_ears_01 = GetFloat();
		character->blendShapes.mod_jaw_width = GetFloat();
		character->blendShapes.shp_mouth_04 = GetFloat();
		character->blendShapes.shp_eyes_04 = GetFloat();
		character->blendShapes.shp_nose_03 = GetFloat();
		character->blendShapes.shp_nose_04 = GetFloat();
		character->blendShapes.shp_brow_06 = GetFloat();
		character->blendShapes.shp_brow_04 = GetFloat();
		character->blendShapes.shp_face_04 = GetFloat();
		character->blendShapes.shp_brow_08 = GetFloat();
		character->blendShapes.shp_brow_07 = GetFloat();
		character->blendShapes.shp_nose_07 = GetFloat();
		character->blendShapes.jawRight = GetFloat();
		character->blendShapes.mouthLeft = GetFloat();
		character->blendShapes.mouthFrownRight = GetFloat();
		character->blendShapes.mouthSmileRight = GetFloat();
		character->blendShapes.jawOpen = GetFloat();
		character->blendShapes.browInnerUp = GetFloat();
		character->blendShapes.eyeWideRight = GetFloat();
		character->blendShapes.mouthDimpleLeft = GetFloat();
		character->blendShapes.mod_ears_size = GetFloat();
		character->blendShapes.mod_brow_height = GetFloat();
		character->blendShapes.shp_brow_03 = GetFloat();
		character->blendShapes.shp_brow_09 = GetFloat();
		character->blendShapes.shp_face_09 = GetFloat();
		character->blendShapes.shp_nose_09 = GetFloat();
		character->blendShapes.shp_eyes_09 = GetFloat();
		character->blendShapes.shp_nose_06 = GetFloat();
		character->blendShapes.eyeLookDownLeft = GetFloat();
		character->blendShapes.eyeLookDownRight = GetFloat();
		character->blendShapes.shp_eyes_05 = GetFloat();
	}
	void MHairColor(CustomMaleCharacter* character)
	{
		character->hairColor = GetVector4();
	}
	void MEyebrowColor(CustomMaleCharacter* character)
	{
		character->eyebrowColor = GetVector4();
	}
	void MSkinColor(CustomMaleCharacter* character)
	{
		character->skinColor = GetVector4();
	}
	void MLipColor(CustomMaleCharacter* character)
	{
		character->lipColor = GetVector4();
	}
	void MEyesColor(CustomMaleCharacter* character)
	{
		character->eyesColor = GetVector4();
	}
	void MMakeUpAlpha(CustomMaleCharacter* character)
	{
		character->makeUpAlpha = GetFloat();
	}
	void MWrinkles(CustomMaleCharacter* character)
	{
		character->wrinkles = GetFloat();
	}
	void DoubleSidedDecoder(Material* mat)
	{
		mat->doubleSided = GetInt();
	}
	void MaterialTypeDecoder(Material* mat)
	{
		mat->materialType = (Material::MaterialTypeEnum)GetInt();
	}
	void CullModeDecoder(Material* mat)
	{
		mat->cullMode = (Material::CullModeEnum)GetInt();
	}
	void SurfaceDecoder(Material* mat)
	{
		mat->surfaceType = (Material::SurfaceTypeEnum)GetInt();
	}
	void BaseMapDecoder(Material* mat)
	{
		GetWord();
		mat->baseMapPath = new StaticString(wordBuffer->GetCount());
		mat->baseMapPath->Append(*wordBuffer);
	}
	void BaseColorDecoder(Material* mat)
	{
		mat->baseColor = GetVector4();
	}
	void MetallicDecoder(Material* mat)
	{
		mat->metallic = GetFloat();
	}
	void SmoothnessDecoder(Material* mat)
	{
		mat->smoothness = GetFloat();
	}
	void NormalMapDecoder(Material* mat)
	{
		GetWord();
		mat->normalMapPath = new StaticString(wordBuffer->GetCount());
		mat->normalMapPath->Append(*wordBuffer);
	}
	void NormalScaleDecoder(Material* mat)
	{
		mat->normalScale = GetFloat();
	}
	void ColorsDecoder(Mesh* mesh)
	{
		int length = GetInt();
		mesh->colors = new StaticArray<Vector4>(length);
		for (int i = 0; i < length; i++)
		{
			mesh->colors->Add(GetVector4());
		}
	}
	void UVDecoder(Mesh* mesh)
	{
		int length = GetInt();
		mesh->uv = new StaticArray<Vector2>(length);
		for (int i = 0; i < length; i++)
		{
			mesh->uv->Add(GetVector2());
		}
	}
	void UV2Decoder(Mesh* mesh)
	{
		int length = GetInt();
		mesh->uv2 = new StaticArray<Vector2>(length);
		for (int i = 0; i < length; i++)
		{
			mesh->uv2->Add(GetVector2());
		}
	}
	void UV3Decoder(Mesh* mesh)
	{
		int length = GetInt();
		mesh->uv3 = new StaticArray<Vector2>(length);
		for (int i = 0; i < length; i++)
		{
			mesh->uv3->Add(GetVector2());
		}
	}
	void UV4Decoder(Mesh* mesh)
	{
		int length = GetInt();
		mesh->uv4 = new StaticArray<Vector2>(length);
		for (int i = 0; i < length; i++)
		{
			mesh->uv4->Add(GetVector2());
		}
	}
	void UV5Decoder(Mesh* mesh)
	{
		int length = GetInt();
		mesh->uv5 = new StaticArray<Vector2>(length);
		for (int i = 0; i < length; i++)
		{
			mesh->uv5->Add(GetVector2());
		}
	}
	void UV6Decoder(Mesh* mesh)
	{
		int length = GetInt();
		mesh->uv6 = new StaticArray<Vector2>(length);
		for (int i = 0; i < length; i++)
		{
			mesh->uv6->Add(GetVector2());
		}
	}
	void UV7Decoder(Mesh* mesh)
	{
		int length = GetInt();
		mesh->uv7 = new StaticArray<Vector2>(length);
		for (int i = 0; i < length; i++)
		{
			mesh->uv7->Add(GetVector2());
		}
	}
	void UV8Decoder(Mesh* mesh)
	{
		int length = GetInt();
		mesh->uv8 = new StaticArray<Vector2>(length);
		for (int i = 0; i < length; i++)
		{
			mesh->uv8->Add(GetVector2());
		}
	}
	void TangentsDecoder(Mesh* mesh)
	{
		int length = GetInt();
		mesh->tangents = new StaticArray<Vector4>(length);
		for (int i = 0; i < length; i++)
		{
			mesh->tangents->Add(GetVector4());
		}
	}
	void VerticesDecoder(Mesh* mesh)
	{
		int length = GetInt();
		mesh->vertices = new StaticArray<Vector3>(length);
		for (int i = 0; i < length; i++)
		{
			mesh->vertices->Add(GetVector3());
		}
	}
	void TrianglesDecoder(Mesh* mesh)
	{
		int length = GetInt();
		mesh->triangles = new StaticArray<int>(length);
		for (int i = 0; i < length; i++)
		{
			mesh->triangles->Add(GetInt());
		}
	}
	void NormalsDecoder(Mesh* mesh)
	{
		int length = GetInt();
		mesh->normals = new StaticArray<Vector3>(length);
		for (int i = 0; i < length; i++)
		{
			mesh->normals->Add(GetVector3());
		}
	}
	void BoundsDecoder(Mesh* mesh)
	{
		mesh->bounds.center = GetVector3();
		mesh->bounds.extents = GetVector3();
	}
	Vector2 GetVector2()
	{
		float x = GetFloat();
		float y = GetFloat();
		return Vector2(x, y);
	}
	Vector3 GetVector3()
	{
		float x = GetFloat();
		float y = GetFloat();
		float z = GetFloat();
		return Vector3(x, y, z);
	}
	Vector4 GetVector4()
	{
		float x = GetFloat();
		float y = GetFloat();
		float z = GetFloat();
		float w = GetFloat();
		return Vector4(x, y, z, w);
	}
	float GetFloat()
	{
		GetWord();
		float value = (float)atof(wordBuffer->GetCharPointer());
		return value;
	}
	int GetInt()
	{
		GetWord();
		int value = atoi(wordBuffer->GetCharPointer());
		return value;
	}
	void GetWord()
	{
		wordBuffer->Clear();
		char charBuffer = '0';
		fileStream.get(charBuffer);
		while (charBuffer != ';' && charBuffer != '\0')
		{
			wordBuffer->Append(charBuffer);
			fileStream.get(charBuffer);
		}

		if (charBuffer == '\0')
		{
			wordBuffer->AddNullChar();
			finishedFlag = true;
		}
	}
};

class Serializer
{
public:
	Serializer() {}
	~Serializer() {}
	void StartSerialize(Mesh* mesh, StaticString* path)
	{
		fileStream.open(path->GetCharPointer());
		MeshEncoder(mesh);
		fileStream.close();
	}
	void StartSerialize(Material* mat, StaticString* path)
	{
		fileStream.open(path->GetCharPointer());
		MaterialEncoder(mat);
		fileStream.close();
	}
	void StartSerialize(CustomMaleCharacter* character, StaticString* path)
	{
		fileStream.open(path->GetCharPointer());
		MaleCharacterEncoder(character);
		fileStream.close();
	}
	void StartSerialize(CustomFemaleCharacter* character, StaticString* path)
	{
		fileStream.open(path->GetCharPointer());
		FemaleCharacterEncoder(character);
		fileStream.close();
	}
	void StartSerialize(Components* comps, StaticString* path)
	{
		fileStream.open(path->GetCharPointer());
		ComponentsEncoder(comps);
		fileStream.close();
	}
	void StartSerialize(Stage* stage, StaticString* path)
	{
		fileStream.open(path->GetCharPointer());
		StageEncoder(stage);
		fileStream.close();
	}
private:
#define charBufferCount 30
	ofstream fileStream;
	void MeshEncoder(Mesh* mesh)
	{
		DynamicString target
		(
			10 + mesh->name->GetCount() +
			10 + 40 * mesh->vertices->GetCount() +
			10 + 20 * mesh->triangles->GetCount() +
			10 + 40 * mesh->normals->GetCount() +
			10 + 40 * mesh->tangents->GetCount() +
			10 + 40 * mesh->colors->GetCount() +
			10 + 40 * mesh->uv->GetCount() +
			10 + 40 * mesh->uv2->GetCount() +
			10 + 40 * mesh->uv3->GetCount() +
			10 + 40 * mesh->uv4->GetCount() +
			10 + 40 * mesh->uv5->GetCount() +
			10 + 40 * mesh->uv6->GetCount() +
			10 + 40 * mesh->uv7->GetCount() +
			10 + 40 * mesh->uv8->GetCount() +
			30
		);

		SetInt(&target, MeshBase);
		SetString(&target, mesh->name);

		SetInt(&target, Vertices);
		SetVectorArray(&target, mesh->vertices);

		SetInt(&target, Triangles);
		SetIntArray(&target, mesh->triangles);

		SetInt(&target, Normals);
		SetVectorArray(&target, mesh->normals);

		SetInt(&target, Tangents);
		SetVectorArray(&target, mesh->tangents);

		SetInt(&target, Colors);
		SetVectorArray(&target, mesh->colors);

		SetInt(&target, UV);
		SetVectorArray(&target, mesh->uv);

		SetInt(&target, UV2);
		SetVectorArray(&target, mesh->uv2);

		SetInt(&target, UV3);
		SetVectorArray(&target, mesh->uv3);

		SetInt(&target, UV4);
		SetVectorArray(&target, mesh->uv4);

		SetInt(&target, UV5);
		SetVectorArray(&target, mesh->uv5);

		SetInt(&target, UV6);
		SetVectorArray(&target, mesh->uv6);

		SetInt(&target, UV7);
		SetVectorArray(&target, mesh->uv7);

		SetInt(&target, UV8);
		SetVectorArray(&target, mesh->uv8);

		SetInt(&target, Bounds);
		SetVector(&target, mesh->bounds.center);
		SetVector(&target, mesh->bounds.extents);

		for (size_t i = 0; i < target.GetCount(); i++)
		{
			fileStream.put(target[i]);
		}
	}

	void MaterialEncoder(Material* mat)
	{
		DynamicString target(300);

		SetInt(&target, MaterialBase);

		SetInt(&target, DoubleSided);
		SetInt(&target, mat->doubleSided);

		SetInt(&target, MaterialType);
		SetInt(&target, mat->materialType);

		SetInt(&target, CullMode);
		SetInt(&target, mat->cullMode);

		SetInt(&target, SurfaceType);
		SetInt(&target, mat->surfaceType);

		SetInt(&target, BaseMapPath);
		SetString(&target, mat->baseMapPath);

		SetInt(&target, BaseColor);
		SetVector(&target, mat->baseColor);

		SetInt(&target, Metallic);
		SetFloat(&target, mat->metallic);

		SetInt(&target, Smoothness);
		SetFloat(&target, mat->smoothness);

		SetInt(&target, NormalMapPath);
		SetString(&target, mat->normalMapPath);

		SetInt(&target, NormalScale);
		SetFloat(&target, mat->normalScale);

		for (size_t i = 0; i < target.GetCount(); i++)
		{
			fileStream.put(target[i]);
		}
	}

	void MaleCharacterEncoder(CustomMaleCharacter* character)
	{
		DynamicString target(3000);

		SetInt(&target, MaleBase);

		SetInt(&target, Footwear);
		SetInt(&target, character->footwear);

		SetInt(&target, Lowerwear);
		SetInt(&target, character->lowerwear);

		SetInt(&target, Upperwear);
		SetInt(&target, character->upperwear);

		SetInt(&target, Beards);
		SetInt(&target, character->beards);

		SetInt(&target, Eyebrows);
		SetInt(&target, character->eyebrows);

		SetInt(&target, Glasses);
		SetInt(&target, character->glasses);

		SetInt(&target, MakeUps);
		SetInt(&target, character->makeUps);

		SetInt(&target, Hairs);
		SetInt(&target, character->hairs);

		SetInt(&target, Wristwatch);
		SetInt(&target, character->wristwatch);

		SetInt(&target, BlendShapes);
		SetMaleBlendShapes(&target, &character->blendShapes);

		SetInt(&target, HairColor);
		SetVector(&target, character->hairColor);

		SetInt(&target, EyebrowColor);
		SetVector(&target, character->eyebrowColor);

		SetInt(&target, SkinColor);
		SetVector(&target, character->skinColor);

		SetInt(&target, LipColor);
		SetVector(&target, character->lipColor);

		SetInt(&target, EyesColor);
		SetVector(&target, character->eyesColor);

		SetInt(&target, MakeUpAlpha);
		SetFloat(&target, character->makeUpAlpha);

		SetInt(&target, Wrinkles);
		SetFloat(&target, character->wrinkles);

		for (size_t i = 0; i < target.GetCount(); i++)
		{
			fileStream.put(target[i]);
		}
	}

	void FemaleCharacterEncoder(CustomFemaleCharacter* character)
	{
		DynamicString target(3000);

		SetInt(&target, FemaleBase);

		SetInt(&target, Footwear);
		SetInt(&target, character->footwear);

		SetInt(&target, Lowerwear);
		SetInt(&target, character->lowerwear);

		SetInt(&target, Upperwear);
		SetInt(&target, character->upperwear);

		SetInt(&target, Eyebrows);
		SetInt(&target, character->eyebrows);

		SetInt(&target, Glasses);
		SetInt(&target, character->glasses);

		SetInt(&target, MakeUps);
		SetInt(&target, character->makeUps);

		SetInt(&target, Hairs);
		SetInt(&target, character->hairs);

		SetInt(&target, Wristwatch);
		SetInt(&target, character->wristwatch);

		SetInt(&target, BlendShapes);
		SetFemaleBlendShapes(&target, &character->blendShapes);

		SetInt(&target, HairColor);
		SetVector(&target, character->hairColor);

		SetInt(&target, EyebrowColor);
		SetVector(&target, character->eyebrowColor);

		SetInt(&target, SkinColor);
		SetVector(&target, character->skinColor);

		SetInt(&target, LipColor);
		SetVector(&target, character->lipColor);

		SetInt(&target, EyesColor);
		SetVector(&target, character->eyesColor);

		SetInt(&target, MakeUpAlpha);
		SetFloat(&target, character->makeUpAlpha);

		SetInt(&target, Wrinkles);
		SetFloat(&target, character->wrinkles);

		for (size_t i = 0; i < target.GetCount(); i++)
		{
			fileStream.put(target[i]);
		}
	}

	void ComponentsEncoder(Components* comps)
	{
		DynamicString target(3000);
		SetInt(&target, ComponentsBase);
		
		if (comps->transform != nullptr)
		{
			SetInt(&target, TransformComp);
			SetTransform(&target, comps->transform);
		}
		if (comps->generalMeshRenderer != nullptr)
		{
			SetInt(&target, GeneralMeshRendererComp);
			SetGeneralMeshRenderer(&target, comps->generalMeshRenderer);
		}
		if (comps->maleCharacterComp != nullptr)
		{
			SetInt(&target, MaleCharacterComp);
			SetCharacterComp(&target, comps->maleCharacterComp);
		}
		if (comps->femaleCharacterComp != nullptr)
		{
			SetInt(&target, FemaleCharacterComp);
			SetCharacterComp(&target, comps->femaleCharacterComp);
		}
		if (comps->light != nullptr)
		{
			SetInt(&target, LightComp);
			SetLight(&target, comps->light);
		}
		if (comps->meshCollider != nullptr)
		{
			SetInt(&target, MeshColliderComp);
			SetMeshCollider(&target, comps->meshCollider);
		}
		if (comps->physicsComp != nullptr)
		{
			SetInt(&target, PhysicsComp);
			SetPhysics(&target, comps->physicsComp);
		}
		if (comps->waterComp != nullptr)
		{
			SetInt(&target, WaterComp);
			SetWater(&target, comps->waterComp);
		}

		for (size_t i = 0; i < target.GetCount(); i++)
		{
			fileStream.put(target[i]);
		}
	}

	void StageEncoder(Stage* stage)
	{
		DynamicString target(3000);
		SetInt(&target, StageBase);

		SetInt(&target, AlepObjectNodes);
		SetAlepObjectNodeArray(&target, stage->alepObjectNodes);

		SetInt(&target, AvailableIndices);
		SetIntArray(&target, stage->availableIndices);

		for (size_t i = 0; i < target.GetCount(); i++)
		{
			fileStream.put(target[i]);
		}
	}

	void SetWater(DynamicString* target, WaterCompStruct* value)
	{
		SetVector(target, value->baseColor);
		SetInt(target, value->underWater);
	}
	void SetPhysics(DynamicString* target, PhysicsCompStruct* value)
	{
		SetFloat(target, value->mass);
		SetFloat(target, value->drag);
		SetInt(target, value->useGravity);
	}
	void SetMeshCollider(DynamicString* target, MeshCollider* value)
	{
		SetInt(target, value->enable);
	}
	void SetLight(DynamicString* target, Light* value)
	{
		SetVector(target, value->filter);
		SetFloat(target, value->intensity);
		SetFloat(target, value->range);
		SetInt(target, value->shadowsEnable);
	}
	void SetCharacterComp(DynamicString* target, FemaleCharacterCompStruct* value)
	{
		SetString(target, value->characterPath);
		SetFloat(target, value->walkSpeed);
		SetFloat(target, value->runSpeed);
		SetFloat(target, value->jumpPower);
		SetInt(target, value->initJumpCount);
	}
	void SetCharacterComp(DynamicString* target, MaleCharacterCompStruct* value)
	{
		SetString(target, value->characterPath);
		SetFloat(target, value->walkSpeed);
		SetFloat(target, value->runSpeed);
		SetFloat(target, value->jumpPower);
		SetInt(target, value->initJumpCount);
	}
	void SetTransform(DynamicString* target, Transform* value)
	{
		SetString(target, value->name);
		SetVector(target,value->localPos);
		SetVector(target,value->localRot);
		SetVector(target,value->localScale);
	}
	void SetGeneralMeshRenderer(DynamicString* target, GeneralMeshRenderer* value)
	{
		SetString(target, value->meshPath);
		SetString(target, value->matPath);
		SetInt(target, value->castShadows);
	}
	void SetFemaleBlendShapes(DynamicString* target, CustomFemaleCharacter::BlendShapesStruct* value)
	{
		SetFloat(target, value->jawForward);
		SetFloat(target, value->jawLeft);
		SetFloat(target, value->mouthRollLower);
		SetFloat(target, value->mouthRollUpper);
		SetFloat(target, value->mouthClose);
		SetFloat(target, value->mouthPressRight);
		SetFloat(target, value->mouthPressLeft);
		SetFloat(target, value->mouthStretchLeft);
		SetFloat(target, value->mouthStretchRight);
		SetFloat(target, value->cheekPuff);
		SetFloat(target, value->mouthShrugLower);
		SetFloat(target, value->mouthShrugUpper);
		SetFloat(target, value->mouthDimpleRight);
		SetFloat(target, value->mouthUpperUpLeft);
		SetFloat(target, value->noseSneerLeft);
		SetFloat(target, value->noseSneerRight);
		SetFloat(target, value->eyeLookOutRight);
		SetFloat(target, value->eyeLookInLeft);
		SetFloat(target, value->eyeLookUpLeft);
		SetFloat(target, value->eyeBlinkLeft);
		SetFloat(target, value->eyeSquintRight);
		SetFloat(target, value->cheekSquintRight);
		SetFloat(target, value->eyeWideLeft);
		SetFloat(target, value->browDownRight);
		SetFloat(target, value->browDownLeft);
		SetFloat(target, value->sil);
		SetFloat(target, value->ou);
		SetFloat(target, value->laughter);
		SetFloat(target, value->TH);
		SetFloat(target, value->SS);
		SetFloat(target, value->RR);
		SetFloat(target, value->PP);
		SetFloat(target, value->oh);
		SetFloat(target, value->nn);
		SetFloat(target, value->kk);
		SetFloat(target, value->ih);
		SetFloat(target, value->FF);
		SetFloat(target, value->E);
		SetFloat(target, value->DD);
		SetFloat(target, value->CH);
		SetFloat(target, value->mouthFunnel);
		SetFloat(target, value->aa);
		SetFloat(target, value->mouthLowerDownLeft);
		SetFloat(target, value->mouthFrownLeft);
		SetFloat(target, value->mouthSmileLeft);
		SetFloat(target, value->shp_face_05);
		SetFloat(target, value->shp_face_01);
		SetFloat(target, value->shp_mouth_07);
		SetFloat(target, value->mod_jaw_height);
		SetFloat(target, value->shp_mouth_06);
		SetFloat(target, value->shp_eyes_06);
		SetFloat(target, value->mod_mouth_height);
		SetFloat(target, value->mod_nose_tip_angle);
		SetFloat(target, value->shp_ears_07);
		SetFloat(target, value->mod_eyes_size);
		SetFloat(target, value->mod_nose_tip);
		SetFloat(target, value->shp_eyes_02);
		SetFloat(target, value->mod_nose_curve);
		SetFloat(target, value->shp_ears_06);
		SetFloat(target, value->mod_nose_size);
		SetFloat(target, value->mod_chin_height);
		SetFloat(target, value->shp_mouth_05);
		SetFloat(target, value->shp_mouth_08);
		SetFloat(target, value->shp_face_02);
		SetFloat(target, value->shp_ears_09);
		SetFloat(target, value->mod_chin_size);
		SetFloat(target, value->shp_face_07);
		SetFloat(target, value->shp_nose_08);
		SetFloat(target, value->shp_nose_05);
		SetFloat(target, value->shp_eyes_01);
		SetFloat(target, value->shp_mouth_09);
		SetFloat(target, value->browOuterUpLeft);
		SetFloat(target, value->cheekSquintLeft);
		SetFloat(target, value->eyeSquintLeft);
		SetFloat(target, value->eyeLookInRight);
		SetFloat(target, value->browOuterUpRight);
		SetFloat(target, value->eyeLookOutLeft);
		SetFloat(target, value->mouthLowerDownRight);
		SetFloat(target, value->mouthRight);
		SetFloat(target, value->mouthPucker);
		SetFloat(target, value->mouthUpperUpRight);
		SetFloat(target, value->eyeLookUpRight);
		SetFloat(target, value->eyeBlinkRight);
		SetFloat(target, value->shp_brow_05);
		SetFloat(target, value->body_curvy);
		SetFloat(target, value->shp_face_06);
		SetFloat(target, value->shp_mouth_02);
		SetFloat(target, value->shp_brow_02);
		SetFloat(target, value->shp_eyes_08);
		SetFloat(target, value->shp_eyes_07);
		SetFloat(target, value->shp_ears_08);
		SetFloat(target, value->shp_face_08);
		SetFloat(target, value->shp_ears_02);
		SetFloat(target, value->shp_mouth_03);
		SetFloat(target, value->shp_ears_03);
		SetFloat(target, value->shp_ears_05);
		SetFloat(target, value->shp_ears_04);
		SetFloat(target, value->shp_nose_02);
		SetFloat(target, value->shp_face_03);
		SetFloat(target, value->body_fat);
		SetFloat(target, value->shp_eyes_03);
		SetFloat(target, value->body_skinny);
		SetFloat(target, value->body_muscular);
		SetFloat(target, value->shp_nose_01);
		SetFloat(target, value->mod_mouth_size);
		SetFloat(target, value->mod_eyes_depth);
		SetFloat(target, value->mod_mouth_depth);
		SetFloat(target, value->mod_eyes_narrow);
		SetFloat(target, value->mod_eyes_height);
		SetFloat(target, value->mod_1D_nasolabial_fold);
		SetFloat(target, value->mod_underbite);
		SetFloat(target, value->shp_mouth_01);
		SetFloat(target, value->shp_brow_01);
		SetFloat(target, value->mod_chin_width);
		SetFloat(target, value->mod_brow_depth);
		SetFloat(target, value->body_breastsize);
		SetFloat(target, value->shp_ears_01);
		SetFloat(target, value->mod_jaw_width);
		SetFloat(target, value->shp_mouth_04);
		SetFloat(target, value->shp_eyes_04);
		SetFloat(target, value->shp_nose_03);
		SetFloat(target, value->shp_nose_04);
		SetFloat(target, value->shp_brow_06);
		SetFloat(target, value->shp_brow_04);
		SetFloat(target, value->shp_face_04);
		SetFloat(target, value->shp_brow_08);
		SetFloat(target, value->shp_brow_07);
		SetFloat(target, value->shp_nose_07);
		SetFloat(target, value->shp_eyes_05);
		SetFloat(target, value->jawRight);
		SetFloat(target, value->mouthLeft);
		SetFloat(target, value->mouthFrownRight);
		SetFloat(target, value->mouthSmileRight);
		SetFloat(target, value->jawOpen);
		SetFloat(target, value->browInnerUp);
		SetFloat(target, value->eyeWideRight);
		SetFloat(target, value->mouthDimpleLeft);
		SetFloat(target, value->mod_ears_size);
		SetFloat(target, value->mod_brow_height);
		SetFloat(target, value->shp_brow_03);
		SetFloat(target, value->shp_brow_09);
		SetFloat(target, value->shp_face_09);
		SetFloat(target, value->shp_nose_09);
		SetFloat(target, value->shp_eyes_09);
		SetFloat(target, value->shp_nose_06);
		SetFloat(target, value->eyeLookDownLeft);
		SetFloat(target, value->eyeLookDownRight);
	}
	void SetMaleBlendShapes(DynamicString* target, CustomMaleCharacter::BlendShapesStruct* value)
	{
		SetFloat(target, value->jawForward);
		SetFloat(target, value->jawLeft);
		SetFloat(target, value->mouthRollLower);
		SetFloat(target, value->mouthRollUpper);
		SetFloat(target, value->mouthClose);
		SetFloat(target, value->mouthPressRight);
		SetFloat(target, value->mouthPressLeft);
		SetFloat(target, value->mouthStretchLeft);
		SetFloat(target, value->mouthStretchRight);
		SetFloat(target, value->cheekPuff);
		SetFloat(target, value->mouthShrugLower);
		SetFloat(target, value->mouthShrugUpper);
		SetFloat(target, value->mouthDimpleRight);
		SetFloat(target, value->mouthUpperUpLeft);
		SetFloat(target, value->noseSneerLeft);
		SetFloat(target, value->noseSneerRight);
		SetFloat(target, value->eyeLookOutRight);
		SetFloat(target, value->eyeLookInLeft);
		SetFloat(target, value->eyeLookUpLeft);
		SetFloat(target, value->eyeBlinkLeft);
		SetFloat(target, value->eyeSquintRight);
		SetFloat(target, value->cheekSquintRight);
		SetFloat(target, value->eyeWideLeft);
		SetFloat(target, value->browDownRight);
		SetFloat(target, value->browDownLeft);
		SetFloat(target, value->sil);
		SetFloat(target, value->ou);
		SetFloat(target, value->laughter);
		SetFloat(target, value->TH);
		SetFloat(target, value->SS);
		SetFloat(target, value->RR);
		SetFloat(target, value->PP);
		SetFloat(target, value->oh);
		SetFloat(target, value->nn);
		SetFloat(target, value->kk);
		SetFloat(target, value->ih);
		SetFloat(target, value->FF);
		SetFloat(target, value->E);
		SetFloat(target, value->DD);
		SetFloat(target, value->CH);
		SetFloat(target, value->mouthFunnel);
		SetFloat(target, value->aa);
		SetFloat(target, value->mouthLowerDownLeft);
		SetFloat(target, value->mouthFrownLeft);
		SetFloat(target, value->mouthSmileLeft);
		SetFloat(target, value->shp_face_05);
		SetFloat(target, value->shp_face_01);
		SetFloat(target, value->shp_mouth_07);
		SetFloat(target, value->mod_jaw_height);
		SetFloat(target, value->shp_mouth_06);
		SetFloat(target, value->shp_eyes_06);
		SetFloat(target, value->mod_mouth_height);
		SetFloat(target, value->mod_nose_tip_angle);
		SetFloat(target, value->shp_ears_07);
		SetFloat(target, value->mod_eyes_size);
		SetFloat(target, value->mod_nose_tip);
		SetFloat(target, value->shp_eyes_02);
		SetFloat(target, value->mod_nose_curve);
		SetFloat(target, value->shp_ears_06);
		SetFloat(target, value->mod_nose_size);
		SetFloat(target, value->mod_chin_height);
		SetFloat(target, value->shp_mouth_05);
		SetFloat(target, value->shp_mouth_08);
		SetFloat(target, value->shp_face_02);
		SetFloat(target, value->shp_ears_09);
		SetFloat(target, value->mod_chin_size);
		SetFloat(target, value->shp_face_07);
		SetFloat(target, value->shp_nose_08);
		SetFloat(target, value->shp_nose_05);
		SetFloat(target, value->shp_eyes_01);
		SetFloat(target, value->shp_mouth_09);
		SetFloat(target, value->browOuterUpLeft);
		SetFloat(target, value->cheekSquintLeft);
		SetFloat(target, value->eyeSquintLeft);
		SetFloat(target, value->eyeLookInRight);
		SetFloat(target, value->browOuterUpRight);
		SetFloat(target, value->eyeLookOutLeft);
		SetFloat(target, value->mouthLowerDownRight);
		SetFloat(target, value->mouthRight);
		SetFloat(target, value->mouthPucker);
		SetFloat(target, value->mouthUpperUpRight);
		SetFloat(target, value->eyeLookUpRight);
		SetFloat(target, value->eyeBlinkRight);
		SetFloat(target, value->shp_brow_05);
		SetFloat(target, value->body_curvy);
		SetFloat(target, value->shp_face_06);
		SetFloat(target, value->shp_mouth_02);
		SetFloat(target, value->shp_brow_02);
		SetFloat(target, value->shp_eyes_08);
		SetFloat(target, value->shp_eyes_07);
		SetFloat(target, value->shp_ears_08);
		SetFloat(target, value->shp_face_08);
		SetFloat(target, value->shp_ears_02);
		SetFloat(target, value->shp_mouth_03);
		SetFloat(target, value->shp_ears_03);
		SetFloat(target, value->shp_ears_05);
		SetFloat(target, value->shp_ears_04);
		SetFloat(target, value->shp_nose_02);
		SetFloat(target, value->shp_face_03);
		SetFloat(target, value->body_fat);
		SetFloat(target, value->shp_eyes_03);
		SetFloat(target, value->body_skinny);
		SetFloat(target, value->body_muscular);
		SetFloat(target, value->shp_nose_01);
		SetFloat(target, value->mod_mouth_size);
		SetFloat(target, value->mod_eyes_depth);
		SetFloat(target, value->mod_mouth_depth);
		SetFloat(target, value->mod_eyes_narrow);
		SetFloat(target, value->mod_eyes_height);
		SetFloat(target, value->mod_1D_nasolabial_fold);
		SetFloat(target, value->mod_underbite);
		SetFloat(target, value->shp_mouth_01);
		SetFloat(target, value->shp_brow_01);
		SetFloat(target, value->mod_chin_width);
		SetFloat(target, value->mod_brow_depth);
		SetFloat(target, value->body_breastsize);
		SetFloat(target, value->shp_ears_01);
		SetFloat(target, value->mod_jaw_width);
		SetFloat(target, value->shp_mouth_04);
		SetFloat(target, value->shp_eyes_04);
		SetFloat(target, value->shp_nose_03);
		SetFloat(target, value->shp_nose_04);
		SetFloat(target, value->shp_brow_06);
		SetFloat(target, value->shp_brow_04);
		SetFloat(target, value->shp_face_04);
		SetFloat(target, value->shp_brow_08);
		SetFloat(target, value->shp_brow_07);
		SetFloat(target, value->shp_nose_07);
		SetFloat(target, value->jawRight);
		SetFloat(target, value->mouthLeft);
		SetFloat(target, value->mouthFrownRight);
		SetFloat(target, value->mouthSmileRight);
		SetFloat(target, value->jawOpen);
		SetFloat(target, value->browInnerUp);
		SetFloat(target, value->eyeWideRight);
		SetFloat(target, value->mouthDimpleLeft);
		SetFloat(target, value->mod_ears_size);
		SetFloat(target, value->mod_brow_height);
		SetFloat(target, value->shp_brow_03);
		SetFloat(target, value->shp_brow_09);
		SetFloat(target, value->shp_face_09);
		SetFloat(target, value->shp_nose_09);
		SetFloat(target, value->shp_eyes_09);
		SetFloat(target, value->shp_nose_06);
		SetFloat(target, value->eyeLookDownLeft);
		SetFloat(target, value->eyeLookDownRight);
		SetFloat(target, value->shp_eyes_05);
	}
	void SetString(DynamicString* target, StaticString* value)
	{
		target->Append(*value);
		target->Append(';');
	}
	void SetInt(DynamicString* target, int value)
	{
		char stringBuffer[charBufferCount];
		sprintf_s(stringBuffer, "%d", value);
		target->Append(stringBuffer);
		target->Append(';');
	}
	void SetFloat(DynamicString* target, float value)
	{
		char stringBuffer[charBufferCount];
		sprintf_s(stringBuffer, "%f", value);
		target->Append(stringBuffer);
		target->Append(';');
	}
	void SetVector(DynamicString* target, Vector2 vector)
	{
		SetFloat(target, vector.x);
		SetFloat(target, vector.y);
	}
	void SetVector(DynamicString* target, Vector3 vector)
	{
		SetFloat(target, vector.x);
		SetFloat(target, vector.y);
		SetFloat(target, vector.z);
	}
	void SetVector(DynamicString* target, Vector4 vector)
	{
		SetFloat(target, vector.x);
		SetFloat(target, vector.y);
		SetFloat(target, vector.z);
		SetFloat(target, vector.w);
	}
	void SetIntArray(DynamicString* target, StaticArray<int>* intArray)
	{
		size_t length = intArray->GetCount();
		SetInt(target, (int)length);
		for (size_t i = 0; i < length; i++)
		{
			SetInt(target, (*intArray)[i]);
		}
	}
	void SetVectorArray(DynamicString* target, StaticArray<Vector2>* vectors)
	{
		size_t length = vectors->GetCount();
		SetInt(target, (int)length);
		for (size_t i = 0; i < length; i++)
		{
			SetVector(target, (*vectors)[i]);
		}
	}
	void SetVectorArray(DynamicString* target, StaticArray<Vector3>* vectors)
	{
		size_t length = vectors->GetCount();
		SetInt(target, (int)length);
		for (size_t i = 0; i < length; i++)
		{
			SetVector(target, (*vectors)[i]);
		}
	}
	void SetVectorArray(DynamicString* target, StaticArray<Vector4>* vectors)
	{
		size_t length = vectors->GetCount();
		SetInt(target, (int)length);
		for (size_t i = 0; i < length; i++)
		{
			SetVector(target, (*vectors)[i]);
		}
	}
	void SetAlepObjectNode(DynamicString* target, AlepObjectNode* node)
	{
		SetInt(target, node->parentIndex);
		SetInt(target, node->nextIndex);
		SetInt(target, node->prevIndex);
		SetInt(target, node->firstChildIndex);
		SetInt(target, node->depth);
		SetInt(target, node->componentsIndex);
	}
	void SetAlepObjectNodeArray(DynamicString* target, StaticArray<AlepObjectNode>* nodes)
	{
		size_t length = nodes->GetCount();
		SetInt(target, (int)length);
		for (size_t i = 0; i < length; i++)
		{
			SetAlepObjectNode(target, &(*nodes)[i]);
		}
	}
};