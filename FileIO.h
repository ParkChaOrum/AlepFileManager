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
		//delete this->name;
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
};

#define MeshBase 0
#define MaterialBase 1
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

class Unserializer
{
public:
#define WordBufferSize 50
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
		fileStream.open(&(*path)[0]);
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
	void* (Unserializer::* baseDecoders[1])() =
	{
		&Unserializer::MeshBaseDecoder
	};
	void (Unserializer::* meshDecoders[14])(Mesh*) =
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
		fileStream.open(&(*path)[0]);
		MeshBaseEncoder(mesh);
		fileStream.close();
	}
private:
#define arrayCount 14
#define charBufferCount 30
	ofstream fileStream;
	void MeshBaseEncoder(Mesh* mesh)
	{
		DynamicString targets[arrayCount]
		{
			10 + mesh->name->GetCount() ,
			10 + 40 * mesh->vertices->GetCount(),
			10 + 20 * mesh->triangles->GetCount(),
			10 + 40 * mesh->normals->GetCount(),
			10 + 40 * mesh->tangents->GetCount(),
			10 + 40 * mesh->colors->GetCount(),
			10 + 40 * mesh->uv->GetCount(),
			10 + 40 * mesh->uv2->GetCount(),
			10 + 40 * mesh->uv3->GetCount(),
			10 + 40 * mesh->uv4->GetCount(),
			10 + 40 * mesh->uv5->GetCount(),
			10 + 40 * mesh->uv6->GetCount(),
			10 + 40 * mesh->uv7->GetCount(),
			10 + 40 * mesh->uv8->GetCount(),
		};

		SetInt(&targets[0], MeshBase);
		SetString(&targets[0], mesh->name);

		SetInt(&targets[1], Vertices);
		SetVectorArray(&targets[1], mesh->vertices);

		SetInt(&targets[2], Triangles);
		SetIntArray(&targets[2], mesh->triangles);

		SetInt(&targets[3], Normals);
		SetVectorArray(&targets[3], mesh->normals);

		SetInt(&targets[4], Tangents);
		SetVectorArray(&targets[4], mesh->tangents);

		SetInt(&targets[5], Colors);
		SetVectorArray(&targets[5], mesh->colors);

		SetInt(&targets[6], UV);
		SetVectorArray(&targets[6], mesh->uv);

		SetInt(&targets[7], UV2);
		SetVectorArray(&targets[7], mesh->uv2);

		SetInt(&targets[8], UV3);
		SetVectorArray(&targets[8], mesh->uv3);

		SetInt(&targets[9], UV4);
		SetVectorArray(&targets[9], mesh->uv4);

		SetInt(&targets[10], UV5);
		SetVectorArray(&targets[10], mesh->uv5);

		SetInt(&targets[11], UV6);
		SetVectorArray(&targets[11], mesh->uv6);

		SetInt(&targets[12], UV7);
		SetVectorArray(&targets[12], mesh->uv7);

		SetInt(&targets[13], UV8);
		SetVectorArray(&targets[13], mesh->uv8);

		for (size_t i = 0; i < arrayCount; i++)
		{
			for (size_t j = 0; targets[i][j] != '\0'; j++)
			{
				fileStream.put(targets[i][j]);
			}
		}
		fileStream.put('\0');
	}
	void SetString(DynamicString* target, StaticString* value)
	{
		target->Append(value->GetCharPointer());
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
};