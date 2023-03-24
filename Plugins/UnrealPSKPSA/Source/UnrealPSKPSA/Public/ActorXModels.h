#pragma once

struct VChunkHeader
{
	char ChunkID[20];
	int TypeFlag;
	int DataSize;
	int DataCount;
};

struct VVertex
{
	int PointIndex;
	float U, V;
	char MatIndex;
	char Reserved;
	short Pad;
};

struct VTriangle
{
	int WedgeIndex[3];
	char MatIndex;
	char AuxMatIndex;
	unsigned SmoothingGroups;
};

struct VMaterial
{
	char MaterialName[64];
	int TextureIndex;
	unsigned PolyFlags;
	int AuxMaterial;
	unsigned AuxFlags;
	int LodBias;
	int LodStyle;
};

struct VJointPos
{
	FQuat Orientation;
	FVector Position;
	float Length;
	float XSize;
	float YSize;
	float ZSize;
};

struct VNamedBoneBinary
{
	char Name[64];
	int Flags;
	int NumChildren;
	int ParentIndex;
	VJointPos BonePos;
};

struct VRawBoneInfluence
{
	float Weight;
	int PointIdx;
	int BoneIdx;
};
