/*******************************************************************************
The content of this file includes portions of the AUDIOKINETIC Wwise Technology
released in source code form as part of the SDK installer package.

Commercial License Usage

Licensees holding valid commercial licenses to the AUDIOKINETIC Wwise Technology
may use this file in accordance with the end user license agreement provided
with the software or, alternatively, in accordance with the terms contained in a
written agreement between you and Audiokinetic Inc.

Apache License Usage

Alternatively, this file may be used under the Apache License, Version 2.0 (the
"Apache License"); you may not use this file except in compliance with the
Apache License. You may obtain a copy of the Apache License at
http://www.apache.org/licenses/LICENSE-2.0.

Unless required by applicable law or agreed to in writing, software distributed
under the Apache License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES
OR CONDITIONS OF ANY KIND, either express or implied. See the Apache License for
the specific language governing permissions and limitations under the License.

Version: v2021.1.9  Build: 7847
Copyright (c) 2006-2022 Audiokinetic Inc.
*******************************************************************************/

/// \file 
/// Spatial Audio interface.

#pragma once

#include <AK/SpatialAudio/Common/AkSpatialAudioTypes.h>
#include <AK/Plugin/AkReflectGameData.h>
#include <AK/SoundEngine/Common/AkSoundEngine.h>

template<AkUInt32 TSize>
struct AkGrowByPolicy_Legacy_SpatialAudio
{
	static AkUInt32 GrowBy(AkUInt32 /*in_CurrentArraySize*/) { return TSize; }
};

/// Initialization settings of the spatial audio module.
struct AkSpatialAudioInitSettings
{
	AkSpatialAudioInitSettings()
		: uMaxSoundPropagationDepth(AK_MAX_SOUND_PROPAGATION_DEPTH)
		, fMovementThreshold(AK_DEFAULT_MOVEMENT_THRESHOLD)
		, uNumberOfPrimaryRays(100)
		, uMaxReflectionOrder(1)
		, fMaxPathLength(10000.0f)
		, fCPULimitPercentage(0.0f)
		, bEnableDiffractionOnReflection(true)
		, bEnableGeometricDiffractionAndTransmission(true)
		, bCalcEmitterVirtualPosition(true)
		, bUseObstruction(true)
		, bUseOcclusion(true)
		
	{}

	AkUInt32 uMaxSoundPropagationDepth;				///< Maximum number of portals that sound can propagate through; must be less than or equal to AK_MAX_SOUND_PROPAGATION_DEPTH.
	AkReal32 fMovementThreshold;					///< Amount that an emitter or listener has to move to trigger a recalculation of reflections/diffraction. Larger values can reduce the CPU load at the cost of reduced accuracy.
	AkUInt32 uNumberOfPrimaryRays;					///< The number of primary rays used in the ray tracing engine. A larger number of rays will increase the chances of finding reflection and diffraction paths, but will result in higher CPU usage. When CPU limit is active (see \ref AkSpatialAudioInitSettings::fCPULimitPercentage), this setting represents the maximum allowed number of primary rays.
	AkUInt32 uMaxReflectionOrder;					///< Maximum reflection order [1, 4] - the number of 'bounces' in a reflection path. A higher reflection order renders more details at the expense of higher CPU usage.
	AkReal32 fMaxPathLength;						///< The length of rays that are cast inside Spatial Audio. This effectively caps the maximum length of individual segments in reflection or diffraction paths.
													///< Each individual sound is also affected by its maximum attenuation distance, specified in the Authoring tool. Reflection or diffraction paths, calculated inside Spatial Audio, will never exceed a sound's maximum attenuation distance.
													///< Note, however, that attenuation is considered infinite if the furthest point is above the audibility threshold.
	AkReal32 fCPULimitPercentage;					///< Defines the targeted computation time allocated for the ray tracing engine. Defined as a percentage [0, 100] of the current audio frame. The ray tracing engine dynamically adapts the number of primary rays to target the specified computation time value. In all circumstances, the computed number of primary rays cannot exceed the number of primary rays specified by AkSpatialAudioInitSettings::uNumberOfPrimaryRays.
													///< A value of 0 indicates no target has been set. In this case, the number of primary rays is fixed and is set by AkSpatialAudioInitSettings::uNumberOfPrimaryRays.
	bool bEnableDiffractionOnReflection;			///< Enable diffraction at the end/beginning of reflection paths. Diffraction on reflection causes reflections to fade in and out smoothly as the listener or emitter move in and out of the reflection's shadow zone.
	bool bEnableGeometricDiffractionAndTransmission;///< Enable computation of geometric diffraction and transmission paths for all sources that have the <b>Enable Diffraction and Transmission</b> box checked in the Positioning tab of the Wwise Property Editor.
													///< This flag enables sound paths around (diffraction) and through (transmission) geometry (see \c AK::SpatialAudio::SetGeometry).
													///< Setting \c bEnableGeometricDiffractionAndTransmission to false implies that geometry is only to be used for reflection calculation.
													///< Diffraction edges must be enabled on geometry for diffraction calculation (see \c AkGeometryParams).
													///< If \c bEnableGeometricDiffractionAndTransmission is false but a sound has <b>Enable Diffraction and Transmission</b> selected in the Positioning tab of the authoring tool, the sound will diffract through portals but will pass through geometry as if it is not there.
													///< One would typically disable this setting in the case that the game intends to perform its own obstruction calculation, but geometry is still passed to spatial audio for reflection calculation.
	bool bCalcEmitterVirtualPosition;				///< An emitter that is diffracted through a portal or around geometry will have its apparent or virtual position calculated by Wwise Spatial Audio and passed on to the sound engine.
	bool bUseObstruction;							///< Use the Wwise obstruction curve for modeling the effect of diffraction on a sound.
													///< Diffraction is only applied to sounds that have the <b>Enable Diffraction and Transmission</b> box checked in the Positioning tab of the Wwise Property Editor.
													///< Diffraction can also be applied using the diffraction built-in parameter, mapped to an RTPC (the built-in parameter is populated whether AkSpatialAudioInitSettings::bUseObstruction is true or false).
													///< While the obstruction curve is a global setting for all sounds, using it to simulate diffraction is preferred over an RTPC, because it provides greater accuracy when modeling multiple diffraction paths, or a combination of diffraction and transmission paths.
													///< This is due to the fact that RTPCs cannot be applied separately to individual sound paths. Only the path with the least amount of diffraction is sent to the RTPC.
	bool bUseOcclusion;								///< Use the Wwise occlusion curve for modeling the effect of transmission loss on a sound.
													///< The transmission loss factor is applied using the occlusion curve defined in the wwise project settings.
													///< Transmission loss is only applied to sounds that have the <b>Enable Diffraction and Transmission</b> box checked in the Positioning tab of the Wwise Property Editor.
													///< Transmission loss can also be applied using the transmission loss built-in parameter, mapped to an RTPC (the built-in parameter is populated whether AkSpatialAudioInitSettings::bUseOcclusion is true or false).
													///< While the occlusion curve is a global setting for all sounds, using it to simulate transmission loss is preferred over an RTPC, because it provides greater accuracy when modeling both transmission and diffraction. 
													///< This is due to the fact that RTPCs cannot be applied to individual sound paths, therefore any parameter mapped to a transmission loss RTPC will also 
													///< affect any potential diffraction paths originating from an emitter.	
	
};

// Settings for individual image sources.
struct AkImageSourceSettings
{
	AkImageSourceSettings() {}

	AkImageSourceSettings(AkVector in_sourcePosition, AkReal32 in_fDistanceScalingFactor, AkReal32 in_fLevel)
		: params(in_sourcePosition, in_fDistanceScalingFactor, in_fLevel)
		, texture()
		, name()
	{
	}

	~AkImageSourceSettings()
	{
		name.Term();
	}

	/// Operator =
	AkImageSourceSettings& operator =(const AkImageSourceSettings & src)
	{
		params = src.params;
		texture = src.texture;
		name = src.name;
		name.AllocCopy();
		return *this;
	}

	void SetOneTexture(AkUniqueID in_texture)
	{
		texture.uNumTexture = 1;
		texture.arTextureID[0] = in_texture;
	}

	void SetName(const char* in_pName)
	{
		name = in_pName;
		name.AllocCopy();
	}

	/// Image source parameters.
	AkImageSourceParams params;

	/// Acoustic texture that goes with this image source.
	AkImageSourceTexture texture;

	/// Name given to image source, can be used to identify the image source in the AK Reflect plugin UI.
	AK::SpatialAudio::String name;
};

/// Vertex for a spatial audio mesh.
struct AkVertex
{
	/// Constructor
	AkVertex() : X(0.f), Y(0.f), Z(0.f) {}
	
	/// Constructor
	AkVertex(AkReal32 in_X, AkReal32 in_Y, AkReal32 in_Z) : X(in_X), Y(in_Y), Z(in_Z) {}

	AkReal32 X; ///< X coordinate
	AkReal32 Y; ///< Y coordinate
	AkReal32 Z; ///< Z coordinate
};

class Ak3DVector;

///  AkExtent describes an extent with width, height and depth. halfWidth, halfHeight and halfDepth should form a vector from the centre of the volume to the positive corner.
///  For portals, negative values in the extent will cause an error. For rooms, negative values can be used to opt out of room transmission.
struct AkExtent
{
	AkExtent() {}

	AkExtent(AkReal32 in_halfWidth, AkReal32 in_halfHeight, AkReal32 in_halfDepth)
		: halfWidth(in_halfWidth)
		, halfHeight(in_halfHeight)
		, halfDepth(in_halfDepth)
	{}
	
	AkReal32 halfWidth = 0.0f;
	AkReal32 halfHeight = 0.0f;
	AkReal32 halfDepth = 0.0f;
};

/// Triangle for a spatial audio mesh. 
struct AkTriangle
{
	/// Constructor
	AkTriangle()	: point0(AK_INVALID_VERTEX)
					, point1(AK_INVALID_VERTEX)
					, point2(AK_INVALID_VERTEX)
					, surface(AK_INVALID_SURFACE)
	{}

	/// Constructor
	AkTriangle(AkVertIdx in_pt0, AkVertIdx in_pt1, AkVertIdx in_pt2, AkSurfIdx in_surfaceInfo) 
		: point0(in_pt0)
		, point1(in_pt1)
		, point2(in_pt2)
		, surface(in_surfaceInfo)
	{}

	/// Index into the vertex table passed into \c AkGeometryParams that describes the first vertex of the triangle. Triangles are double-sided, so vertex order in not important.
	AkVertIdx point0; 

	/// Index into the vertex table passed into \c AkGeometryParams that describes the second vertex of the triangle. Triangles are double-sided, so vertex order in not important.
	AkVertIdx point1;

	/// Index into the vertex table passed into \c AkGeometryParams that describes the third vertex of the triangle. Triangles are double-sided, so vertex order in not important.
	AkVertIdx point2;

	/// Index into the surface table passed into \c AkGeometryParams that describes the surface properties of the triangle.  
	/// If this field is left as \c AK_INVALID_SURFACE, then a default-constructed \c AkAcousticSurface is used.
	AkSurfIdx surface;
};

/// Describes the acoustic surface properties of one or more triangles.
/// An single acoustic surface may describe any number of triangles, depending on the granularity desired.  For example, if desired for debugging, one could create a unique 
/// \c AkAcousticSurface struct for each triangle, and define a unique name for each.  Alternatively, a single \c AkAcousticSurface could be used to describe all triangles.
/// In fact it is not necessary to define any acoustic surfaces at all.  If the \c AkTriangle::surface field is left as \c AK_INVALID_SURFACE, then a default-constructed \c AkAcousticSurface is used.
struct AkAcousticSurface
{
	/// Constructor
	AkAcousticSurface(): textureID(AK_INVALID_UNIQUE_ID)
				, transmissionLoss(1.0f)
				, strName(NULL)
	{}

	/// Acoustic texture ShareSet ID for the surface.  The acoustic texture is authored in Wwise, and the shareset ID may be obtained by calling \c AK::SoundEngine::GetIDFromString
	/// \sa <tt>\ref AK::SoundEngine::GetIDFromString()</tt>
	AkUInt32 textureID;

	/// Value to set when modeling sound transmission through geometry. Transmission is modeled only when the sound emitted enables diffraction and there is no direct line of sight from the emitter to the listener.
	/// If more that one surface is between the emitter and the listener, the maximum of each surface's transmission loss value is used. If the emitter and listener are in different rooms, then the rooms' transmission loss is taken into account.
	/// The maximum of all the surfaces' transmission loss value, and the transmission loss value (see \c AkRoomParams) is used to render the transmission path.
	/// Valid range: (0.f-1.f)
	/// - \ref AkRoomParams
	AkReal32 transmissionLoss;

	/// Name to describe this surface
	const char* strName;
};

/// Structure for retrieving information about the indirect paths of a sound that have been calculated via the geometric reflections API. Useful for debug draw applications.
struct AkReflectionPathInfo
{
	/// Apparent source of the reflected sound that follows this path.
	AkVector imageSource;
	
	/// Vertices of the indirect path.
	/// pathPoint[0] is closest to the emitter, pathPoint[numPathPoints-1] is closest to the listener.
	AkVector pathPoint[AK_MAX_REFLECTION_PATH_LENGTH];

	/// The surfaces that were hit in the path.
	/// surfaces[0] is closest to the emitter, surfaces[numPathPoints-1] is closest to the listener.
	AkAcousticSurface surfaces[AK_MAX_REFLECTION_PATH_LENGTH];

	/// Number of valid elements in the \c pathPoint[], \c surfaces[], and \c diffraction[] arrays.
	AkUInt32 numPathPoints;

	/// Number of reflections in the \c pathPoint[] array. Shadow zone diffraction does not count as a reflection. If there is no shadow zone diffraction, \c numReflections is equal to \c numPathPoints.
	AkUInt32 numReflections;

	/// Diffraction amount, normalized to the range [0,1]
	AkReal32 diffraction[AK_MAX_REFLECTION_PATH_LENGTH];
	
	/// Linear gain applied to image source.
	AkReal32 level;

	/// Deprecated - always false. Occluded paths are not generated.
	bool isOccluded;
};

/// Structure for retrieving information about paths for a given emitter. 
/// The diffraction paths represent indirect sound paths from the emitter to the listener, whether they go through portals 
/// (via the rooms and portals API) or are diffracted around edges (via the geometric diffraction API).
/// The direct path is included here and can be identified by checking \c nodeCount == 0. The direct path may have a non-zero transmission loss 
/// if it passes through geometry or between rooms.
struct AkDiffractionPathInfo
{
	/// Defines the maximum number of nodes that a user can retrieve information about.  Longer paths will be truncated. 
	static const AkUInt32 kMaxNodes = AK_MAX_SOUND_PROPAGATION_DEPTH;

	/// Diffraction points along the path. nodes[0] is the point closest to the listener; nodes[numNodes-1] is the point closest to the emitter. 
	/// Neither the emitter position nor the listener position are represented in this array.
	AkVector nodes[kMaxNodes];

	/// Emitter position. This is the source position for an emitter. In all cases, except for radial emitters, it is the same position as the game object position.
	/// For radial emitters, it is the calculated position at the edge of the volume.
	AkVector emitterPos;

	/// Raw diffraction angles at each point, in radians.
	AkReal32 angles[kMaxNodes];

	/// ID of the portals that the path passes through.  For a given node at position i (in the nodes array), if the path diffracts on a geometric edge, then portals[i] will be an invalid portal ID (ie. portals[i].IsValid() will return false). 
	/// Otherwise, if the path diffracts through a portal at position i, then portals[i] will be the ID of that portal.
	/// portal[0] represents the node closest to the listener; portal[numNodes-1] represents the node closest to the emitter.
	AkPortalID portals[kMaxNodes];

	/// ID's of the rooms that the path passes through. For a given node at position i, room[i] is the room on the listener's side of the node. If node i diffracts through a portal, 
	/// then rooms[i] is on the listener's side of the portal, and rooms[i+1] is on the emitters side of the portal.
	/// There is always one extra slot for a room so that the emitters room is always returned in slot room[numNodes] (assuming the path has not been truncated).
	AkRoomID rooms[kMaxNodes + 1];

	/// Virtual emitter position. This is the position that is passed to the sound engine to render the audio using multi-positioning, for this particular path.
	AkTransform virtualPos;

	/// Total number of nodes in the path.  Defines the number of valid entries in the \c nodes, \c angles, and \c portals arrays. The \c rooms array has one extra slot to fit the emitter's room.
	AkUInt32 nodeCount;

	/// Calculated total diffraction from this path, normalized to the range [0,1]
	/// The diffraction amount is calculated from the sum of the deviation angles from a straight line, of all angles at each nodePoint. 
	//	Can be thought of as how far into the 'shadow region' the sound has to 'bend' to reach the listener.
	/// Depending on the spatial audio initialization settings, this value is applied internally, by spatial audio, to the obstruction or built-in parameter of the emitter game object.
	/// \sa
	/// - \ref AkSpatialAudioInitSettings
	AkReal32 diffraction;

	/// Calculated total transmission loss from this path, normalized to the range [0,1]
	/// This field will be 0 for diffraction paths where \c nodeCount > 0. It may be non-zero for the direct path where \c nodeCount == 0.
	/// The path's transmission loss value is the combination of the geometric transmission loss and the room transmission loss, by taking the greater of the two.
	/// The geometric transmission loss is calculated from the transmission loss values assigned to the geometry that this path transmits through.
	/// If a path transmits through multiple geometries with different transmission loss values, the largest value is taken.
	/// The room transmission loss is taken from the emitter and listener rooms' transmission loss values, and likewise, 
	/// if the listener's room and the emitter's room have different transmission loss values, the greater of the two is used.
	/// \sa
	/// - \ref AkSpatialAudioInitSettings
	/// - \ref AkRoomParams
	/// - \ref AkAcousticSurface
	AkReal32 transmissionLoss;

	/// Total path length
	/// Represents the sum of the length of the individual segments between nodes, with a correction factor applied for diffraction. 
	/// The correction factor simulates the phenomenon where by diffracted sound waves decay faster than incident sound waves and can be customized in the spatial audio init settings.
	/// \sa
	/// - \ref AkSpatialAudioInitSettings
	AkReal32 totLength;

	/// Obstruction value for this path 
	/// This value includes the accumulated portal obstruction for all portals along the path.
	AkReal32 obstructionValue;
};

/// Parameters passed to \c SetPortal
struct AkPortalParams
{
	/// Constructor
	AkPortalParams() :
		bEnabled(false)
	{}

	/// Copy Constructor
	AkPortalParams(const AkPortalParams& in_rhs)
		: Transform(in_rhs.Transform)
		, Extent(in_rhs.Extent)
		, bEnabled(in_rhs.bEnabled)
		, strName(in_rhs.strName)
		, FrontRoom(in_rhs.FrontRoom)
		, BackRoom(in_rhs.BackRoom)
	{
		strName.AllocCopy();
	}

	/// Assignment operator
	AkPortalParams& operator=(const AkPortalParams& in_rhs)
	{
		Transform = in_rhs.Transform;
		Extent = in_rhs.Extent;
		bEnabled = in_rhs.bEnabled;

		strName = in_rhs.strName;
		strName.AllocCopy();

		FrontRoom = in_rhs.FrontRoom;
		BackRoom = in_rhs.BackRoom;

		return *this;
	}

	/// Portal's position and orientation in the 3D world. 
	/// Position vector is the center of the opening.
	/// OrientationFront vector must be unit-length and point along the normal of the portal, and must be orthogonal to Up. It defines the local positive-Z dimension (depth/transition axis) of the portal, used by Extent. 
	/// OrientationTop vector must be unit-length and point along the top of the portal (tangent to the wall), must be orthogonal to Front. It defines the local positive-Y direction (height) of the portal, used by Extent.
	AkTransform						Transform;

	/// Portal extent. Defines the dimensions of the portal relative to its center; all components must be positive numbers. The local right and up dimensions are used in diffraction calculations, 
	/// whereas the front dimension defines a depth value which is used to implement smooth transitions between rooms. It is recommended that users experiment with different portal depths to find a value 
	/// that results in appropriately smooth transitions between rooms. Extent dimensions must be positive.
	AkExtent						Extent;

	/// Whether or not the portal is active/enabled. For example, this parameter may be used to simulate open/closed doors.
	/// Portal diffraction is simulated when at least one portal exists and is active between an emitter and the listener.
	bool							bEnabled;

	/// Name used to identify portal (optional).
	AK::SpatialAudio::OsString		strName;

	/// ID of the room to which the portal connects, in the direction of the Front vector.  If a room with this ID has not been added via AK::SpatialAudio::SetRoom,
	/// a room will be created with this ID and with default AkRoomParams.  If you would later like to update the AkRoomParams, simply call AK::SpatialAudio::SetRoom again with this same ID.
	///	- \ref AK::SpatialAudio::SetRoom
	///	- \ref AK::SpatialAudio::RemoveRoom
	/// - \ref AkRoomParams
	AkRoomID FrontRoom;

	/// ID of the room to which the portal connects, in the direction opposite to the Front vector. If a room with this ID has not been added via AK::SpatialAudio::SetRoom,
	/// a room will be created with this ID and with default AkRoomParams.  If you would later like to update the AkRoomParams, simply call AK::SpatialAudio::SetRoom again with this same ID.
	///	- \ref AK::SpatialAudio::SetRoom
	///	- \ref AK::SpatialAudio::RemoveRoom
	/// - \ref AkRoomParams
	AkRoomID BackRoom;
};

/// Parameters passed to \c SetRoom
struct AkRoomParams
{
	/// Constructor
	AkRoomParams() :  ReverbAuxBus(AK_INVALID_AUX_ID)
					, ReverbLevel(1.f)
					, TransmissionLoss(1.f)
					, RoomGameObj_AuxSendLevelToSelf(0.f)
					, RoomGameObj_KeepRegistered(false)
	{
		// default invalid values
		Up.X = 0.f;
		Up.Y = 1.f;
		Up.Z = 0.f;
		Front.X = 0.f;
		Front.Y = 0.f;
		Front.Z = 1.f;
	}

	/// Copy Constructor
	AkRoomParams(const AkRoomParams& in_rhs)
		: Front(in_rhs.Front)
		, Up(in_rhs.Up)
		, ReverbAuxBus(in_rhs.ReverbAuxBus)
		, ReverbLevel(in_rhs.ReverbLevel)
		, TransmissionLoss(in_rhs.TransmissionLoss)
		, strName(in_rhs.strName)
		, RoomGameObj_AuxSendLevelToSelf(in_rhs.RoomGameObj_AuxSendLevelToSelf)
		, RoomGameObj_KeepRegistered(in_rhs.RoomGameObj_KeepRegistered)
		, GeometryID(in_rhs.GeometryID)
	{
		strName.AllocCopy();
	}

	/// Assignment operator
	AkRoomParams& operator=(const AkRoomParams& in_rhs)
	{
		Front = in_rhs.Front;
		Up = in_rhs.Up;
		ReverbAuxBus = in_rhs.ReverbAuxBus;
		ReverbLevel = in_rhs.ReverbLevel;
		TransmissionLoss = in_rhs.TransmissionLoss;

		strName = in_rhs.strName;
		strName.AllocCopy();

		RoomGameObj_AuxSendLevelToSelf = in_rhs.RoomGameObj_AuxSendLevelToSelf;
		RoomGameObj_KeepRegistered = in_rhs.RoomGameObj_KeepRegistered;

		GeometryID = in_rhs.GeometryID;

		return *this;
	}

	/// Room Orientation. Up and Front must be orthonormal.
	/// Room orientation has an effect when the associated aux bus (see ReverbAuxBus) is set with 3D Spatialization in Wwise, as 3D Spatialization implements relative rotation of the emitter (room) and listener.
	AkVector Front;

	/// Room Orientation. Up and Front must be orthonormal.
	/// Room orientation has an effect when the associated aux bus (see ReverbAuxBus) is set with 3D Spatialization in Wwise, as 3D Spatialization implements relative rotation of the emitter (room) and listener.
	AkVector Up;

	/// The reverb aux bus that is associated with this room.  
	/// When Spatial Audio is told that a game object is in a particular room via SetGameObjectInRoom, a send to this aux bus will be created to model the reverb of the room.
	/// Using a combination of Rooms and Portals, Spatial Audio manages which game object the aux bus is spawned on, and what control gain is sent to the bus.  
	/// When a game object is inside a connected portal, as defined by the portal's orientation and extent vectors, both this aux send and the aux send of the adjacent room are active.
	/// Spatial audio modulates the control value for each send based on the game object's position, in relation to the portal's z-azis and extent, to crossfade the reverb between the two rooms.
	/// If more advanced control of reverb is desired, SetGameObjectAuxSendValues can be used to add additional sends on to a game object.
	/// - \ref AK::SpatialAudio::SetGameObjectInRoom
	/// - \ref AK::SoundEngine::SetGameObjectAuxSendValues
	AkAuxBusID						ReverbAuxBus;

	/// The reverb control value for the send to ReverbAuxBus. Valid range: (0.f-1.f)
	/// Can be used to implement multiple rooms that share the same aux bus, but have different reverb levels.
	AkReal32						ReverbLevel;

	/// Level to set when modeling transmission through walls. Transmission is modeled only when the sound emitted enables diffraction and there is no direct line of sight from the emitter to the listener.
	/// This transmission loss value is only applied when the listener and the emitter are in different rooms; it is taken as the maximum between the emitter's room's transmission loss value and the listener's room's transmission loss value.
	/// If there is geometry in between the listener and the emitter, then the transmission loss value assigned to surfaces hit by the ray between the emitter and listener is also taken into account.
	/// The maximum of all the surfaces' transmission loss value (see \c AkAcousticSurface), and the room's transmission loss value is used to render the transmission path.
	/// Valid range: (0.f-1.f)
	/// - \ref AkAcousticSurface
	AkReal32						TransmissionLoss;
	
	/// Name used to identify room (optional)
	AK::SpatialAudio::OsString		strName;

	/// Send level for sounds that are posted on the room game object; adds reverb to ambience and room tones. Valid range: (0.f-1.f).  Set to a value greater than 0 to have spatial audio create a send on the room game object, 
	/// where the room game object itself is specified as the listener and ReverbAuxBus is specified as the aux bus. A value of 0 disables the aux send. This should not be confused with ReverbLevel, which is the send level 
	/// for spatial audio emitters sending to the room game object.
	/// \aknote The room game object can be accessed though the ID that is passed to \c SetRoom() and the \c AkRoomID::AsGameObjectID() method.  Posting an event on the room game object leverages automatic room game object placement 
	///	by spatial audio so that when the listener is inside the room, the sound comes from all around the listener, and when the listener is outside the room, the sound comes from the portal(s). Typically, this would be used for
	/// surround ambiance beds or room tones. Point source sounds should use separate game objects that are registered as spatial audio emitters.
	/// \sa
	/// - \ref AkRoomParams::RoomGameObj_KeepRegistered
	/// - \ref AkRoomID
	AkReal32						RoomGameObj_AuxSendLevelToSelf;

	/// If set to true, the room game object will be registered on calling \c SetRoom(), and not released untill the room is deleted or removed with \c RemoveRoom(). If set to false, spatial audio will register
	/// the room object only when it is needed by the sound propagation system for the purposes of reverb, and will unregister the game object when all reverb tails have finished.
	/// If the game intends to post events on the room game object for the purpose of ambiance or room tones, RoomGameObj_KeepRegistered should be set to true.
	/// \aknote The room game object can be accessed though the ID that is passed to \c SetRoom() and the \c AkRoomID::AsGameObjectID() method.  Posting an event on the room game object leverages automatic room game object placement 
	///	by spatial audio so that when the listener is inside the room, the sound comes from all around the listener, and when the listener is outside the room, the sound comes from the portal(s). Typically, this would be used for
	/// surround ambiance beds or room tones. Point source sounds should use separate game objects that are registered as spatial audio emitters.
	/// \sa
	/// - \ref AkRoomParams::RoomGameObj_AuxSendLevelToSelf
	/// - \ref AkRoomID
	bool							RoomGameObj_KeepRegistered;

	/// Associate this room with the geometry set \c GeometryID, describing the shape of the room. When a room is associated with a geometry set, the vertices are used to compute the spread value for room transmission.
	/// The vertices are used for computing an oriented bounding box for the room where the orientation of the bounding box is given by the Up and Front vectors. The center of the room is defined as the oriented bounding box center.
	/// The extent of the bounding box is computed from the geometry set's vertices projected on to the orientation axes.
	/// \aknote If the geometry set is only to be used for the room and not for reflection and diffraction calculation, then make sure to set \c AkGeometryParams::EnableTriangles to false.
	/// \sa
	/// - \ref spatial_audio_roomsportals_apiconfigroomgeometry
	/// - \ref AkGeometryParams
	AkGeometrySetID					GeometryID;
};

/// Parameters passed to \c SetGeometry
struct AkGeometryParams
{
	/// Constructor
	AkGeometryParams() : Triangles(NULL), NumTriangles(0), Vertices(NULL), NumVertices(0), Surfaces(NULL), NumSurfaces(0), EnableDiffraction(false), EnableDiffractionOnBoundaryEdges(false), EnableTriangles(true) {}

	/// Pointer to an array of AkTriangle structures. 
	/// This array will be copied into spatial audio memory and will not be accessed after \c SetGeometry returns.
	///	- \ref AkTriangle
	///	- \ref AK::SpatialAudio::SetGeometry
	///	- \ref AK::SpatialAudio::RemoveGeometry
	AkTriangle* Triangles;

	/// Number of triangles in Triangles.
	AkTriIdx NumTriangles;			

	/// Pointer to an array of AkVertex structures. 
	/// This array will be copied into spatial audio memory and will not be accessed after \c SetGeometry returns.
	///	- \ref AkVertex
	///	- \ref AK::SpatialAudio::SetGeometry
	///	- \ref AK::SpatialAudio::RemoveGeometry
	AkVertex* Vertices;

	///< Number of vertices in Vertices.
	AkVertIdx NumVertices;			
	
	///< Pointer to an array of AkAcousticSurface structures.
	/// This array will be copied into spatial audio memory and will not be accessed after \c SetGeometry returns.
	///	- \ref AkVertex
	///	- \ref AK::SpatialAudio::SetGeometry
	///	- \ref AK::SpatialAudio::RemoveGeometry
	AkAcousticSurface* Surfaces;

	/// Number of of AkTriangleInfo structures in in_pTriangleInfo and number of AkTriIdx's in in_infoMap.
	AkSurfIdx NumSurfaces;

	/// Associate this geometry set with the room \c RoomID. Associating a geometry set with a particular room will limit the scope in which the geometry is visible/accessible. \c RoomID can be left as default (-1), in which case 
	/// this geometry set will have a global scope. It is recommended to associate geometry with a room when the geometry is (1) fully contained within the room (ie. not visible to other rooms accept by portals), 
	/// and (2) the room does not share geometry with other rooms. Doing so reduces the search space for ray casting performed by reflection and diffraction calculations. Take note that once one or more geometry sets 
	/// are associated with a room, that room will no longer be able to access geometry that is in the global scope.
	///	- \ref AK::SpatialAudio::SetRoom
	///	- \ref AkRoomParams
	AkRoomID RoomID;

	/// Switch to enable or disable geometric diffraction for this Geometry.
	bool EnableDiffraction;
	
	/// Switch to enable or disable geometric diffraction on boundary edges for this Geometry.  Boundary edges are edges that are connected to only one triangle.
	bool EnableDiffractionOnBoundaryEdges;

	/// Switch to enable or disable the use of the triangles for this Geometry. When enabled, the geometry triangles are indexed for ray computation and used to computed reflection and diffraction.
	/// Set EnableTriangles to false when using a geometry set only to describe a room, and not for reflection and diffraction calculation.
	///	\sa
	/// - \ref AkRoomParams
	bool EnableTriangles;
};

/// Audiokinetic namespace
namespace AK
{
	/// Audiokinetic spatial audio namespace
	namespace SpatialAudio
	{
		////////////////////////////////////////////////////////////////////////
		/// @name Basic functions. 
		/// In order to use SpatialAudio, you need to initalize it using Init, and register the listeners that you plan on using with any of the services offered by SpatialAudio, using 
		/// RegisterListener respectively, _after_ having registered their corresponding game object to the sound engine.
		/// \akwarning At the moment, there can be only one Spatial Audio listener registered at any given time.
		//@{

		/// Initialize the SpatialAudio API.  
		AK_EXTERNAPIFUNC(AKRESULT, Init)(const AkSpatialAudioInitSettings& in_initSettings);

		/// Assign a game object as the Spatial Audio listener.  There can be only one Spatial Audio listener registered at any given time; in_gameObjectID will replace any previously set Spatial Audio listener.
		/// The game object passed in must be registered by the client, at some point, for sound to be heard.  It is not necessary to be registered at the time of calling this function.
		/// If not listener is explicitly registered to spatial audio, then a default listener (set via \c AK::SoundEngine::SetDefaultListeners()) is selected.  If the are no default listeners, or there are more than one
		/// default listeners, then it is necessary to call RegisterListener() to specify which listener to use with Spatial Audio.
		AK_EXTERNAPIFUNC(AKRESULT, RegisterListener)(
			AkGameObjectID in_gameObjectID				///< Game object ID
			);

		/// Unregister a game object as a listener in the SpatialAudio API; clean up Spatial Audio listener data associated with in_gameObjectID.  
		/// If in_gameObjectID is the current registered listener, calling this function will clear the Spatial Audio listener and
		/// Spatial Audio features will be disabled until another listener is registered.
		/// This function is optional - listener are automatically unregistered when their game object is deleted in the sound engine.
		/// \sa 
		/// - \ref AK::SpatialAudio::RegisterListener
		AK_EXTERNAPIFUNC(AKRESULT, UnregisterListener)(
			AkGameObjectID in_gameObjectID				///< Game object ID
			);

		/// Define a inner and outer radius around each sound position for a specified game object. 
		/// The radii are used in spread and distance calculations, simulating a radial sound source.
		/// When applying attenuation curves, the distance between the listener and the inner sphere (defined by the sound position and \c in_innerRadius) is used. 
		/// The spread for each sound position is calculated as follows:
		/// - If the listener is outside the outer radius, then the spread is defined by the area that the sphere takes in the listener field of view. Specifically, this angle is calculated as 2.0*asinf( \c in_outerRadius / distance ), where distance is the distance between the listener and the sound position.
		///	- When the listener intersects the outer radius (the listener is exactly \c in_outerRadius units away from the sound position), the spread is exactly 50%.
		/// - When the listener is in between the inner and outer radius, the spread interpolates linearly from 50% to 100% as the listener transitions from the outer radius towards the inner radius.
		/// - If the listener is inside the inner radius, the spread is 100%.
		/// \aknote Transmission and diffraction calculations in Spatial Audio always use the center of the sphere (the position(s) passed into \c AK::SoundEngine::SetPosition or \c AK::SoundEngine::SetMultiplePositions) for raycasting. 
		/// To obtain accurate diffraction and transmission calculations for radial sources, where different parts of the volume may take different paths through or around geometry,
		/// it is necessary to pass multiple sound positions into \c AK::SoundEngine::SetMultiplePositions to allow the engine to 'sample' the area at different points.
		/// - \ref AK::SoundEngine::SetPosition
		/// - \ref AK::SoundEngine::SetMultiplePositions
		AK_EXTERNAPIFUNC(AKRESULT, SetGameObjectRadius)(
			AkGameObjectID in_gameObjectID,				///< Game object ID
			AkReal32 in_outerRadius,					///< Outer radius around each sound position, defining 50% spread. Must satisfy \c in_innerRadius <= \c in outerRadius.
			AkReal32 in_innerRadius						///< Inner radius around each sound position, defining 100% spread and 0 attenuation distance. Must satisfy \c in_innerRadius <= \c in outerRadius.
			);

		//@}

		////////////////////////////////////////////////////////////////////////
		/// @name Helper functions for passing game data to the Wwise Reflect plug-in. 
		/// Use this API for detailed placement of reflection image sources.
		/// \aknote These functions are low-level and useful when your game engine already implements a geometrical approach to sound propagation such as an image-source or a ray tracing algorithm.
		/// Functions of Geometry are preferred and easier to use with the Wwise Reflect plug-in. \endaknote
		//@{

		/// Add or update an individual image source for processing via the AkReflect plug-in.  Use this API for detailed placement of
		/// reflection image sources, whose positions have been determined by the client, such as from the results of a ray cast, computation or by manual placement.  One possible
		/// use case is generating reflections that originate far enough away that they can be modeled as a static point source, for example, off of a distant mountain.
		/// The SpatialAudio API manages image sources added via SetImageSource() and sends them to the AkReflect plug-in that is on the aux bus with ID \c in_AuxBusID. 
		/// The image source will apply only to the the game object specified by \c in_gameObjectID.
		/// SetImageSource takes a room ID to indicate which room the reflection is logically part of, even though the position of the image source may be outside of the extents of the room.  
		/// This ID is used as a filter, so that it is not possible to hear reflections for rooms that the emitter and listener are not both inside.  To use this feature, the emitter's and listener's rooms must also be
		/// specified using SetGameObjectInRoom. If you are not using the rooms and portals API, or the image source is not associated with a room, pass a default-constructed room ID.
		/// \aknote The \c AkImageSourceSettings struct passed in \c in_info must contain a unique image source ID to be able to identify this image source across frames and when updating and/or removing it later.  
		/// Each instance of AkReflect has its own set of data, so you may reuse ID, if desired, as long as \c in_gameObjectID and \c in_AuxBusID are different.
		/// \endaknote
		/// \aknote Early reflection send level and bus in the authoring tool do not apply to image sources set with \c SetImageSource(). When using this function, the Reflect bus and send level 
		/// may only be set programmatically. Also, it is not possible to use the geometric reflections API on the same aux bus and game object. If using the geometric reflections API and the SetImageSource API in conjunction, be sure to specify an
		/// aux bus to \c SetImageSource that is unique from the aux bus(es) defined in the authoring tool, and from those passed to \c SetEarlyReflectionsAuxSend.
		/// \endaknote
		/// \aknote For proper operation with AkReflect and the SpatialAudio API, any aux bus using AkReflect should have 'Listener Relative Routing' checked and the 3D Spatialization set to None in the Wwise authoring tool. See \ref spatial_audio_wwiseprojectsetup_businstances for more details. \endaknote
		/// \sa 
		/// - \ref AK::SpatialAudio::RemoveImageSource
		///	- \ref AK::SpatialAudio::ClearImageSources
		/// - \ref AK::SpatialAudio::SetGameObjectInRoom
		/// - \ref AK::SpatialAudio::SetEarlyReflectionsAuxSend
		AK_EXTERNAPIFUNC(AKRESULT, SetImageSource)(
			AkImageSourceID in_srcID,								///< The ID of the image source being added.
			const AkImageSourceSettings& in_info,					///< Image source information.
			AkUniqueID in_AuxBusID,									///< Aux bus that has the AkReflect plug in for early reflection DSP.
			AkRoomID in_roomID,										///< The ID of the room that the image source is logically a part of; pass a default-constructed ID if not in, or not using, a room.
			AkGameObjectID in_gameObjectID							///< The ID of the emitter game object to which the image source applies. Must be a valid and registered game object.
		);

		/// Remove an individual reflection image source that was previously added via \c SetImageSource.
		/// \sa 
		///	- \ref AK::SpatialAudio::SetImageSource
		///	- \ref AK::SpatialAudio::ClearImageSources
		AK_EXTERNAPIFUNC(AKRESULT, RemoveImageSource)(
			AkImageSourceID in_srcID,									///< The ID of the image source to remove.
			AkUniqueID in_AuxBusID,										///< Aux bus that was passed to SetImageSource.
			AkGameObjectID in_gameObjectID								///< Game object ID that was passed to SetImageSource.
		);

		/// Remove all image sources matching \c in_AuxBusID and \c in_gameObjectID that were previously added via \c SetImageSource.
		/// Both \c in_AuxBusID and \c in_gameObjectID can be treated as wild cards matching all aux buses and/or all game object, by passing \c AK_INVALID_AUX_ID and/or \c AK_INVALID_GAME_OBJECT, respectively.
		/// \sa 
		///	- \ref AK::SpatialAudio::SetImageSource
		/// - \ref AK::SpatialAudio::RemoveImageSource
		AK_EXTERNAPIFUNC(AKRESULT, ClearImageSources)(
			AkUniqueID in_AuxBusID = AK_INVALID_AUX_ID,							///< Aux bus that was passed to SetImageSource, or AK_INVALID_AUX_ID to match all aux buses.
			AkGameObjectID in_gameObjectID = AK_INVALID_GAME_OBJECT				///< Game object ID that was passed to SetImageSource, or AK_INVALID_GAME_OBJECT to match all game objects.
			);

		//@}

		////////////////////////////////////////////////////////////////////////
		/// @name Geometry 
		/// Geometry API for early reflection processing using Wwise Reflect.
		//@{

		/// Add or update a set of geometry from the \c SpatialAudio module for geometric reflection and diffaction processing. A geometry set is a logical set of vertices, triangles, and acoustic surfaces,
		/// which are referenced by the same \c AkGeometrySetID. The ID (\c in_GeomSetID) must be unique and is also chosen by the client in a manner similar to \c AkGameObjectID's.
		/// \sa 
		///	- \ref AkGeometryParams
		///	- \ref AK::SpatialAudio::RemoveGeometry
		AK_EXTERNAPIFUNC(AKRESULT, SetGeometry)(
			AkGeometrySetID in_GeomSetID,		///< Unique geometry set ID, chosen by client.
			const AkGeometryParams& in_params	///< Geometry parameters to set.
		);
		
		/// Remove a set of geometry to the SpatialAudio API.
		/// \sa 
		///	- \ref AK::SpatialAudio::SetGeometry
		AK_EXTERNAPIFUNC(AKRESULT, RemoveGeometry)(
			AkGeometrySetID in_SetID		///< ID of geometry set to be removed.
		);

		/// Query information about the reflection paths that have been calculated via geometric reflection processing in the SpatialAudio API. This function can be used for debugging purposes.
		/// This function must acquire the global sound engine lock and therefore, may block waiting for the lock.
		/// \sa
		/// - \ref AkReflectionPathInfo
		AK_EXTERNAPIFUNC(AKRESULT, QueryReflectionPaths)(
			AkGameObjectID in_gameObjectID, ///< The ID of the game object that the client wishes to query.
			AkUInt32 in_positionIndex,		///< The index of the associated game object position.
			AkVector& out_listenerPos,		///< Returns the position of the listener game object that is associated with the game object \c in_gameObjectID.
			AkVector& out_emitterPos,		///< Returns the position of the emitter game object \c in_gameObjectID.
			AkReflectionPathInfo* out_aPaths,	///< Pointer to an array of \c AkReflectionPathInfo's which will be filled after returning.
			AkUInt32& io_uArraySize			///< The number of slots in \c out_aPaths, after returning the number of valid elements written.
			);

		//@}

		////////////////////////////////////////////////////////////////////////
		/// @name Rooms and Portals
		/// Sound Propagation API using rooms and portals.
		//@{

		/// Add or update a room. Rooms are used to connect portals and define an orientation for oriented reverbs. This function may be called multiple times with the same ID to update the parameters of the room.
		/// \akwarning The ID (\c in_RoomID) must be chosen in the same manner as \c AkGameObjectID's, as they are in the same ID-space. The spatial audio lib manages the 
		/// registration/unregistration of internal game objects for rooms that use these IDs and, therefore, must not collide. 
		/// Also, the room ID must not be in the reserved range (AkUInt64)(-32) to (AkUInt64)(-2) inclusively. You may, however, explicitly add the default room ID AK::SpatialAudio::kOutdoorRoomID (-1) 
		/// in order to customize its AkRoomParams, to provide a valid auxiliary bus, for example.\endakwarning
		/// \sa
		/// - \ref AkRoomID
		/// - \ref AkRoomParams
		/// - \ref AK::SpatialAudio::RemoveRoom
		AK_EXTERNAPIFUNC(AKRESULT, SetRoom)(
			AkRoomID in_RoomID,				///< Unique room ID, chosen by the client.
			const AkRoomParams& in_Params	///< Parameter for the room.
			);

		/// Remove a room.
		/// \sa
		/// - \ref AkRoomID
		/// - \ref AK::SpatialAudio::SetRoom
		AK_EXTERNAPIFUNC(AKRESULT, RemoveRoom)(
			AkRoomID in_RoomID	///< Room ID that was passed to \c SetRoom.
			);

		/// Add or update an acoustic portal. A portal is an opening that connects two or more rooms to simulate the transmission of reverberated (indirect) sound between the rooms. 
		/// This function may be called multiple times with the same ID to update the parameters of the portal. The ID (\c in_PortalID) must be chosen in the same manner as \c AkGameObjectID's, 
		/// as they are in the same ID-space. The spatial audio lib manages the registration/unregistration of internal game objects for portals that use these IDs, and therefore must not collide.
		/// \sa
		/// - \ref AkPortalID
		/// - \ref AkPortalParams
		/// - \ref AK::SpatialAudio::RemovePortal
		AK_EXTERNAPIFUNC(AKRESULT, SetPortal)(
			AkPortalID in_PortalID,		///< Unique portal ID, chosen by the client.
			const AkPortalParams& in_Params	///< Parameter for the portal.
			);

		/// Remove a portal.
		/// \sa
		/// - \ref AkPortalID
		/// - \ref AK::SpatialAudio::SetPortal
		AK_EXTERNAPIFUNC(AKRESULT, RemovePortal)(
			AkPortalID in_PortalID		///< ID of portal to be removed, which was originally passed to SetPortal.
			);

		/// Set the room that the game object is currently located in - usually the result of a containment test performed by the client. The room must have been registered with \c SetRoom.
		///	Setting the room for a game object provides the basis for the sound propagation service, and also sets which room's reverb aux bus to send to.  The sound propagation service traces the path
		/// of the sound from the emitter to the listener, and calculates the diffraction as the sound passes through each portal.  The portals are used to define the spatial location of the diffracted and reverberated
		/// audio.
		/// \sa 
		///	- \ref AK::SpatialAudio::SetRoom
		///	- \ref AK::SpatialAudio::RemoveRoom
		AK_EXTERNAPIFUNC(AKRESULT, SetGameObjectInRoom)(
			AkGameObjectID in_gameObjectID, ///< Game object ID 
			AkRoomID in_CurrentRoomID		///< RoomID that was passed to \c AK::SpatialAudio::SetRoom
			);

		/// Set the early reflections order for reflection calculation. The reflections order indicates the number of times sound can bounce off of a surface. 
		/// A higher number requires more CPU resources but results in denser early reflections. Set to 0 to globally disable reflections processing.
		AK_EXTERNAPIFUNC(AKRESULT, SetReflectionsOrder)(
			AkUInt32 in_uReflectionsOrder,	///< Number of reflections to calculate. Valid range [0,4]
			bool in_bUpdatePaths			///< Set to true to clear existing higher-order paths and to force the re-computation of new paths. If false, existing paths will remain and new paths will be computed when the emitter or listener moves.
			);

		/// Set the number of rays cast from the listener by the stochastic ray casting engine.
		/// A higher number requires more CPU resources but provides more accurate results. Default value (100) should be good for most applications.
		///
		AK_EXTERNAPIFUNC(AKRESULT, SetNumberOfPrimaryRays)(
			AkUInt32 in_uNbPrimaryRays		///< Number of rays cast from the listener
			);

		/// Set an early reflections auxiliary bus for a particular game object. 
		/// Geometrical reflection calculation inside spatial audio is enabled for a game object if any sound playing on the game object has a valid early reflections aux bus specified in the authoring tool,
		/// or if an aux bus is specified via \c SetEarlyReflectionsAuxSend.
		/// The \c in_auxBusID parameter of SetEarlyReflectionsAuxSend applies to sounds playing on the game object \c in_gameObjectID which have not specified an early reflection bus in the authoring tool -
		/// the parameter specified on individual sounds' reflection bus takes priority over the value passed in to \c SetEarlyReflectionsAuxSend.
		/// \aknote 
		/// Users may apply this function to avoid duplicating sounds in the actor-mixer hierarchy solely for the sake of specifying a unique early reflection bus, or in any situation where the same 
		/// sound should be played on different game objects with different early reflection aux buses (the early reflection bus must be left blank in the authoring tool if the user intends to specify it through the API). \endaknote
		AK_EXTERNAPIFUNC(AKRESULT, SetEarlyReflectionsAuxSend)(
			AkGameObjectID in_gameObjectID, ///< Game object ID 
			AkAuxBusID in_auxBusID			///< Auxiliary bus ID. Applies only to sounds which have not specified an early reflection bus in the authoring tool. Pass \c AK_INVALID_AUX_ID to set only the send volume.
			);

		/// Set an early reflections send volume for a particular game object. 
		/// The \c in_fSendVolume parameter is used to control the volume of the early reflections send. It is combined with the early reflections volume specified in the authoring tool, and is applied to all sounds 
		/// playing on the game object.
		/// Setting \c in_fSendVolume to 0.f will disable all reflection processing for this game object.
		AK_EXTERNAPIFUNC(AKRESULT, SetEarlyReflectionsVolume)(
			AkGameObjectID in_gameObjectID, ///< Game object ID 
			AkReal32 in_fSendVolume			///< Send volume (linear) for auxiliary send. Set 0.f to disable reflection processing. Valid range 0.f-1.f. 
			);

		/// Set the obstruction and occlusion value for a portal that has been registered with Spatial Audio.
		/// Portal obstruction is used to simulate objects between the portal and the listener that are obstructing the sound coming from the portal.  
		/// The obstruction value affects only the portals dry path, and should relate to how much of the opening
		/// is obstructed, and must be calculated by the client.  It is applied to the room's game object, as well as to all the emitters virtual positions 
		/// which propagate from that room through this portal.
		/// Portal occlusion is applied only on the room game object, and affects both the wet and dry path of the signal emitted from the room's bus.
		AK_EXTERNAPIFUNC(AKRESULT, SetPortalObstructionAndOcclusion)(
			AkPortalID in_PortalID,				///< Portal ID.
			AkReal32 in_fObstruction,			///< Obstruction value.  Valid range 0.f-1.f
			AkReal32 in_fOcclusion				///< Occlusion value.  Valid range 0.f-1.f
			);

		/// Set the obstruction value of the path between a game object and a portal that has been created by Spatial Audio.
		/// The obstruction value is applied on one of the path segments of the sound between the emitter and the listener.
		/// Diffraction must be enabled on the sound for a diffraction path to be created.
		/// Also, there should not be any portals between the provided game object and portal ID parameters.
		/// The obstruction value is used to simulate objects between the portal and the game object that are obstructing the sound.
		/// Send an obstruction value of 0 to ensure the value is removed from the internal data structure.
		AK_EXTERNAPIFUNC(AKRESULT, SetGameObjectToPortalObstruction)(
			AkGameObjectID in_gameObjectID,		///< Game object ID
			AkPortalID in_PortalID,				///< Portal ID
			AkReal32 in_fObstruction			///< Obstruction value.  Valid range 0.f-1.f
			);

		/// Set the obstruction value of the path between two portals that has been created by Spatial Audio.
		/// The obstruction value is applied on one of the path segments of the sound between the emitter and the listener.
		/// Diffraction must be enabled on the sound for a diffraction path to be created.
		/// Also, there should not be any portals between the two provided ID parameters.
		/// The obstruction value is used to simulate objects between the portals that are obstructing the sound.
		/// Send an obstruction value of 0 to ensure the value is removed from the internal data structure.
		AK_EXTERNAPIFUNC(AKRESULT, SetPortalToPortalObstruction)(
			AkPortalID in_PortalID0,			///< Portal ID
			AkPortalID in_PortalID1,			///< Portal ID
			AkReal32 in_fObstruction			///< Obstruction value.  Valid range 0.f-1.f
			);

		/// Query information about the wet diffraction amount for the portal \c in_portal, returned as a normalized value \c out_wetDiffraction in the range [0,1].  
		/// The wet diffraction is calculated from how far into the 'shadow region' the listener is from the portal.  Unlike dry diffraction, the 
		/// wet diffraction does not depend on the incident angle, but only the normal of the portal.
		/// Depending on the spatial audio initialization settings, this value is applied by spatial audio, to the obstruction and/or built-in game parameter of the room game object that is
		/// on the other side of the portal (relative to the listener).
		/// This function must acquire the global sound engine lock and therefore, may block waiting for the lock.
		/// \sa
		/// - \ref AkSpatialAudioInitSettings
		AK_EXTERNAPIFUNC(AKRESULT, QueryWetDiffraction)(
			AkPortalID in_portal,			///< The ID of the game object that the client wishes to query.
			AkReal32& out_wetDiffraction	///< The number of slots in \c out_aPaths, after returning the number of valid elements written.
			);

		/// Query information about the diffraction state for a particular listener and emitter, which has been calculated using the data provided via the spatial audio emitter API. This function can be used for debugging purposes.
		/// Returned in \c out_aPaths, this array contains the sound paths calculated from diffraction around a geometric edge and/or diffraction through portals connecting rooms.
		/// No paths will be returned in any of the following conditions: (1) the emitter game object has a direct line of sight to the listener game object, (2) the emitter and listener are in the same room, and the listener is completely outside the radius of the emitter, 
		/// or (3) The emitter and listener are in different rooms, but there are no paths found via portals between the emitter and the listener.
		/// A single path with zero diffraction nodes is returned when all of the following conditions are met: (1) the emitter and listener are in the same room, (2) there is no direct line of sight, and (3) either the Voice's Attenuation's curve max distance is exceeded or the accumulated diffraction coefficient exceeds 1.0.
		/// This function must acquire the global sound engine lock and, therefore, may block waiting for the lock.
		/// \sa
		/// - \ref AkDiffractionPathInfo
		AK_EXTERNAPIFUNC(AKRESULT, QueryDiffractionPaths)(
			AkGameObjectID in_gameObjectID,		///< The ID of the game object that the client wishes to query.
			AkUInt32 in_positionIndex,			///< The index of the associated game object position.
			AkVector& out_listenerPos,			///< Returns the position of the listener game object that is associated with the game object \c in_gameObjectID.
			AkVector& out_emitterPos,			///< Returns the position of the emitter game object \c in_gameObjectID.
			AkDiffractionPathInfo* out_aPaths,	///< Pointer to an array of \c AkDiffractionPathInfo's which will be filled on return.
			AkUInt32& io_uArraySize				///< The number of slots in \c out_aPaths, after returning the number of valid elements written.
			);

		/// Reset the stochastic engine state by re-initializing the random seeds.
		///
		AK_EXTERNAPIFUNC(AKRESULT, ResetStochasticEngine)();

		//@}
	}
};
