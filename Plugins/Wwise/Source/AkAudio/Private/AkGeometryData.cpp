/*******************************************************************************
The content of the files in this repository include portions of the
AUDIOKINETIC Wwise Technology released in source code form as part of the SDK
package.

Commercial License Usage

Licensees holding valid commercial licenses to the AUDIOKINETIC Wwise Technology
may use these files in accordance with the end user license agreement provided
with the software or, alternatively, in accordance with the terms contained in a
written agreement between you and Audiokinetic Inc.

Copyright (c) 2021 Audiokinetic Inc.
*******************************************************************************/

#include "AkGeometryData.h"

void GetBasicBoxGeometryData(TArray<FVector>& Vertices, TArray<FAkTriangle>& Triangles)
{
	Vertices.Init(FVector(0, 0, 0), 8);
	Vertices[0] = FVector(-1, -1, -1);
	Vertices[1] = FVector(-1, -1, 1);
	Vertices[2] = FVector(-1, 1, -1);
	Vertices[3] = FVector(-1, 1, 1);
	Vertices[4] = FVector(1, -1, -1);
	Vertices[5] = FVector(1, -1, 1);
	Vertices[6] = FVector(1, 1, -1);
	Vertices[7] = FVector(1, 1, 1);

	Triangles.Init(FAkTriangle(), 12);
	Triangles[0] = { 0, 1, 3, AK_INVALID_SURFACE };
	Triangles[1] = { 0, 1, 5, AK_INVALID_SURFACE };
	Triangles[2] = { 0, 2, 3, AK_INVALID_SURFACE };
	Triangles[3] = { 0, 2, 6, AK_INVALID_SURFACE };
	Triangles[4] = { 0, 4, 5, AK_INVALID_SURFACE };
	Triangles[5] = { 0, 4, 6, AK_INVALID_SURFACE };
	Triangles[6] = { 1, 3, 7, AK_INVALID_SURFACE };
	Triangles[7] = { 1, 5, 7, AK_INVALID_SURFACE };
	Triangles[8] = { 2, 3, 7, AK_INVALID_SURFACE };
	Triangles[9] = { 2, 6, 7, AK_INVALID_SURFACE };
	Triangles[10] = { 4, 5, 7, AK_INVALID_SURFACE };
	Triangles[11] = { 4, 6, 7, AK_INVALID_SURFACE };
}

/** Taken from GetOrientedHalfSphereMesh in PrimitiveDrawingUtils.cpp. See original for adding tangents and texture coords. */
void GenerateHalfSphereVerts(AkSurfIdx surfIdx, const FVector& Center, const FRotator& Orientation, const float Radius, int32 NumSides, int32 NumRings, float StartAngle, float EndAngle, FAkGeometryData& GeometryData)
{
	if (NumSides <= 0 || NumRings <= 0)
		return;
	// The first/last arc are on top of each other.
	int32 numVerts = (NumSides + 1) * (NumRings + 1);
	TArray<FVector> vertices;
	vertices.AddDefaulted(numVerts);
	TArray<FAkTriangle> triangles;

	int32 BaseVertIndex = GeometryData.Vertices.Num();

	// Calculate verts for one arc
	TArray<FVector> arcVertices;
	for (int32 i = 0; i < NumRings + 1; i++)
	{
		float angle = StartAngle + ((float)i / NumRings) * (EndAngle - StartAngle);
		arcVertices.Add(FVector(0.0f, FMath::Sin(angle) * Radius, FMath::Cos(angle) * Radius) + Center);
	}

	// Then rotate this arc NumSides+1 times.
	for (int32 s = 0; s < NumSides + 1; s++)
	{
		FRotator ArcRotator(0, 360.f * (float)s / NumSides, 0);
		FRotationMatrix ArcRot(ArcRotator);

		for (int32 v = 0; v < NumRings + 1; v++)
		{
			int32 VIx = (NumRings + 1) * s + v;
			vertices[VIx] = ArcRot.TransformPosition(arcVertices[v]);
		}
	}

	// Add all of the vertices we generated to the geometry data.
	for (int32 vertIdx = 0; vertIdx < numVerts; vertIdx++)
	{
		GeometryData.Vertices.Add(vertices[vertIdx]);
	}

	// If StartAngle is 0, the top-most ring is the top pole, and all sides will start on the same vertex.
	const bool sidesStartAtTopPole = StartAngle < PI * 0.1f;
	// Similarly, if EndAngle is PI, the bottom-most ring is the bottom pole, and all sides will end on the same vertex.
	const bool sidesEndAtBottomPole = EndAngle >= PI * 0.9f;
	// Add all of the triangles we generated to the geometry data.
	for (uint16 s = 0; s < NumSides; s++)
	{
		// Add triangles between consecutive sides, from the top-most ring to the bottom.
		uint16 side0Start = (s + 0) * (NumRings + 1) + BaseVertIndex;
		uint16 side1Start = (s + 1) * (NumRings + 1) + BaseVertIndex;

		uint16 s0 = side0Start;
		uint16 s1 = side1Start;

		// s0 and s1 refer to the vertices running up and down the 'sides' of the sphere.
		// the line from vertex s0 to vertex s0 + 1 runs down one 'side'
		// the line from vertex s0 to vertex s1 runs along one 'ring' (from one 'side' to the other).
		// the line from vertex s0 to vertex s1 + 1 runs diagonally down a side and along a ring.

		// Add the initial triangle for this side strip (or triangles, if we're not starting on a pole)
		if (sidesStartAtTopPole)
		{
			GeometryData.Triangles.Add({ s0, uint16(s1 + 1), uint16(s0 + 1), surfIdx });
		}
		else
		{
			GeometryData.Triangles.Add({ s0, s1, uint16(s0 + 1), surfIdx });
			GeometryData.Triangles.Add({ s1, uint16(s1 + 1), uint16(s0 + 1), surfIdx });
		}
		
		for (uint16 r = 1; r < NumRings - 1; r++)
		{
			s0 = side0Start + r;
			s1 = side1Start + r;
			GeometryData.Triangles.Add({ s0, s1, uint16(s0 + 1), surfIdx });
			GeometryData.Triangles.Add({ s1, uint16(s1 + 1), uint16(s0 + 1), surfIdx });
		}

		// Add the final triangle for this side strip (or triangles if we're not ending on a pole)
		s0 = side0Start + (NumRings - 1);
		s1 = side1Start + (NumRings - 1);
		GeometryData.Triangles.Add({ s0, s1, uint16(s0 + 1), surfIdx });
		if (!sidesEndAtBottomPole)
		{
			GeometryData.Triangles.Add({ s1, uint16(s1 + 1), uint16(s0 + 1), surfIdx });
		}
	}
}

/** Taken from BuildCylinderVerts in PrimitiveDrawingUtils.cpp. See original for adding tangents and texture coords. */
void GenerateCylinderVerts(AkSurfIdx surfIdx, const FVector& Base, const FVector& XAxis, const FVector& YAxis, const FVector& ZAxis, float Radius, float HalfHeight, uint32 Sides, FAkGeometryData& GeometryData)
{
	const float	AngleDelta = 2.0f * PI / Sides;
	FVector	LastVertex = Base + XAxis * Radius;

	FVector2D TC = FVector2D(0.0f, 0.0f);
	float TCStep = 1.0f / Sides;

	FVector TopOffset = HalfHeight * ZAxis;

	int32 BaseVertIndex = GeometryData.Vertices.Num();

	//Compute vertices for base circle.
	for (uint32 SideIndex = 0; SideIndex < Sides; SideIndex++)
	{
		const FVector Vertex = Base + (XAxis * FMath::Cos(AngleDelta * (SideIndex + 1)) + YAxis * FMath::Sin(AngleDelta * (SideIndex + 1))) * Radius;
		FVector Normal = Vertex - Base;
		Normal.Normalize();

		GeometryData.Vertices.Add(Vertex - TopOffset);

		LastVertex = Vertex;
		TC.X += TCStep;
	}

	LastVertex = Base + XAxis * Radius;
	TC = FVector2D(0.0f, 1.0f);

	//Compute vertices for the top circle
	for (uint16 SideIndex = 0; SideIndex < Sides; SideIndex++)
	{
		const FVector Vertex = Base + (XAxis * FMath::Cos(AngleDelta * (SideIndex + 1)) + YAxis * FMath::Sin(AngleDelta * (SideIndex + 1))) * Radius;
		FVector Normal = Vertex - Base;
		Normal.Normalize();

		GeometryData.Vertices.Add(Vertex + TopOffset);

		LastVertex = Vertex;
		TC.X += TCStep;
	}

	//Add sides.
	for (uint16 SideIndex = 0; SideIndex < Sides; SideIndex++)
	{
		uint16 V0 = BaseVertIndex + SideIndex;
		uint16 V1 = BaseVertIndex + ((SideIndex + 1) % Sides);
		uint16 V2 = V0 + Sides;
		uint16 V3 = V1 + Sides;

		GeometryData.Triangles.Add({ V0, V2, V1, surfIdx });
		GeometryData.Triangles.Add({ V2, V3, V1, surfIdx });
	}
}

void FAkGeometryData::AddBox(AkSurfIdx surfIdx, FVector center, FVector extent, FRotator rotation)
{
	TArray<FVector> boxVertices;
	TArray<FAkTriangle> boxTriangles;
	GetBasicBoxGeometryData(boxVertices, boxTriangles);

	AkVertIdx initialVertIdx = Vertices.Num();

	// move vertices according to the center and extents
	for (AkVertIdx idx = 0; idx < boxVertices.Num(); idx++)
	{
		FTransform transform(rotation, center, extent);
		FVector v = transform.TransformPosition(boxVertices[idx]);

		Vertices.Add(v);
	}

	for (AkTriIdx idx = 0; idx < boxTriangles.Num(); idx++)
	{
		boxTriangles[idx].Point0 += initialVertIdx;
		boxTriangles[idx].Point1 += initialVertIdx;
		boxTriangles[idx].Point2 += initialVertIdx;
		boxTriangles[idx].Surface = surfIdx;

		Triangles.Add(boxTriangles[idx]);
	}
}

void FAkGeometryData::AddSphere(AkSurfIdx surfIdx, const FVector& Center, const float Radius, int32 NumSides, int32 NumRings)
{
	GenerateHalfSphereVerts(surfIdx, Center, FRotator::ZeroRotator, Radius, NumSides, NumRings, 0, PI, *this);
}

void FAkGeometryData::AddCapsule(AkSurfIdx surfIdx, const FVector& Origin, const FVector& XAxis, const FVector& YAxis, const FVector& ZAxis, float Radius, float HalfHeight, int32 NumSides)
{
	const FVector BottomEnd = Origin - HalfHeight * ZAxis;
	const FVector TopEnd = Origin + HalfHeight * ZAxis;

	GenerateHalfSphereVerts(surfIdx, TopEnd, FRotationMatrix::MakeFromXY(XAxis, YAxis).Rotator(), Radius, NumSides, NumSides, 0, PI / 2, *this);
	GenerateCylinderVerts(surfIdx, Origin, XAxis, YAxis, ZAxis, Radius, HalfHeight, NumSides, *this);
	GenerateHalfSphereVerts(surfIdx, BottomEnd, FRotationMatrix::MakeFromXY(XAxis, YAxis).Rotator(), Radius, NumSides, NumSides, PI / 2, PI, *this);
}