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

// AkMMDevice.h -- C++ RIAA object wrappers for Win32 MMDevice enumeration APIs

#pragma once

#include <AK/SoundEngine/Common/AkSoundEngine.h>
#include <AK/Tools/Common/AkPlatformFuncs.h>
#include <mmdeviceapi.h>

namespace AK
{
	namespace Win32
	{
		class DeviceProperty
		{
		public:
			// Default constructor
			DeviceProperty()
			{
				PropVariantInit(&variant);
			}

			// Construct a property from an existing property store
			DeviceProperty(const PROPERTYKEY &key, IPropertyStore* in_pProps)
			{
				PropVariantInit(&variant);
				if (in_pProps) in_pProps->GetValue(key, &variant);
			}

			// Move constructor
			DeviceProperty(DeviceProperty&& other)
			{
				variant = other.variant;
				PropVariantInit(&other.variant);
			}

			// Copy construction is not allowed
			DeviceProperty(const DeviceProperty& other) = delete;

			// Destructor
			~DeviceProperty()
			{
				PropVariantClear(&variant);
			}

			// Move assignment
			DeviceProperty& operator=(DeviceProperty&& other)
			{
				PropVariantClear(&variant);
				variant = other.variant;
				PropVariantInit(&other.variant);
				return *this;
			}

			// Copy assignment is not allowed
			DeviceProperty& operator=(const DeviceProperty& other) = delete;

			bool IsEmpty() const { return variant.vt == VT_EMPTY; }

			PROPVARIANT variant;
		};

		class DeviceProperties
		{
		public:
			// Default constructor
			DeviceProperties()
				: pProps(nullptr)
			{
			}

			// Construct properties from an IMMDevice
			DeviceProperties(IMMDevice* in_pDevice)
			{
				in_pDevice->OpenPropertyStore(STGM_READ, &pProps);
			}

			// Move constructor
			DeviceProperties(DeviceProperties&& other)
			{
				pProps = other.pProps;
				other.pProps = nullptr;
			}

			// Copy construction is not allowed
			DeviceProperties(const DeviceProperties& other) = delete;

			// Destructor
			~DeviceProperties()
			{
				if (pProps)
				{
					pProps->Release();
					pProps = nullptr;
				}
			}

			// Move assignment
			DeviceProperties& operator=(DeviceProperties&& other)
			{
				if (pProps)
					pProps->Release();
				pProps = other.pProps;
				other.pProps = nullptr;
				return *this;
			}

			// Copy assignment is not allowed
			DeviceProperties& operator=(const DeviceProperties& other) = delete;

			bool IsValid() { return pProps != nullptr; }

			DeviceProperty GetProperty(const PROPERTYKEY& key)
			{
				return DeviceProperty(key, pProps);
			}

			IPropertyStore* pProps;
		};
		class Device
		{
		public:
			// Default constructor
			Device()
				: pDevice(nullptr)
				, idDevice(AK_INVALID_DEVICE_ID)
			{
			}

			// Move constructor
			Device(Device&& other)
				: pDevice(nullptr)
			{
				SetDevice(other.pDevice);
				other.pDevice = nullptr;
			}
			
			Device(const Device& other)
				: pDevice(nullptr)
			{
				*this = other;
			}

			// Destructor
			~Device()
			{
				if (pDevice)
				{
					pDevice->Release();
					pDevice = nullptr;
				}
			}

			// Move assignment
			Device& operator=(Device&& other)
			{
				if (pDevice)
				{
					pDevice->Release();
					pDevice = nullptr; // Do not remove, protects against this == &other
				}
				pDevice = other.pDevice;
				idDevice = other.idDevice;
				other.pDevice = nullptr;
				return *this;
			}
			
			Device& operator=(const Device& other)
			{
				if (pDevice)
				{
					pDevice->Release();
					pDevice = nullptr; // Do not remove, protects against this == &other
				}
				pDevice = other.pDevice;
				if (pDevice)
					pDevice->AddRef();
				idDevice = other.idDevice;
				return *this;
			}

			Device& operator=(IMMDevice* pOther)
			{
				SetDevice(pOther);
				if (pDevice)
					pDevice->AddRef();
				return *this;
			}

			bool IsValid() const { return pDevice != nullptr; }

			AkUInt32 GetDeviceID() const
			{
				return pDevice ? idDevice : AK_INVALID_DEVICE_ID;
			}

			DeviceProperties GetProperties() const
			{
				return DeviceProperties(pDevice);
			}

			void ComputeId()
			{
				idDevice = AK_INVALID_DEVICE_ID;
				if (pDevice)
				{
					//Inlined version of GetDeviceID.
					LPWSTR pwszID = NULL;
					if (pDevice->GetId(&pwszID) == S_OK)
					{
						char szString[260];
						AKPLATFORM::AkWideCharToChar(pwszID, 260 - 1, szString);
						szString[260 - 1] = 0;

						idDevice = FNVHash32::ComputeLowerCase((const char*)szString);
						CoTaskMemFree(pwszID);
					}
				}
			}

			void SetDevice(IMMDevice* in_pNew)
			{
				if (pDevice)
					pDevice->Release();
				pDevice = in_pNew;				
				ComputeId();
			}

			interface IMMDevice* pDevice;
			AkUInt32 idDevice;			
		};
		class DeviceCollection
		{
		public:
			class Iterator
			{
			public:
				Iterator(IMMDeviceCollection* in_pDevices, UINT in_i)
					: pDevices(in_pDevices)
					, i(in_i)
				{
				}

				/// + operator
				Iterator operator+(AkUInt32 inc) const
				{
					Iterator returnedIt(pDevices, i + inc);
					return returnedIt;
				}

				/// - operator
				AkUInt32 operator-(Iterator const& rhs) const
				{
					return (AkUInt32)(i - rhs.i);
				}

				/// ++ operator
				Iterator& operator++()
				{
					++i;
					return *this;
				}

				/// -- operator
				Iterator& operator--()
				{
					--i;
					return *this;
				}

				/// == operator
				bool operator ==(const Iterator& in_rOp) const
				{
					return (pDevices == in_rOp.pDevices && i == in_rOp.i);
				}

				/// != operator
				bool operator !=(const Iterator& in_rOp) const
				{
					return (pDevices != in_rOp.pDevices || i != in_rOp.i);
				}
			
				Device GetDevice()
				{
					Device pDevice;
					pDevices->Item(i, (IMMDevice**)&pDevice.pDevice);	//Transfer the ref
					if (pDevice.pDevice)
						pDevice.ComputeId();
					return pDevice;
				}

				interface IMMDeviceCollection* pDevices;	//Keep first.
				UINT i;
			};

			DeviceCollection(IMMDeviceEnumerator* pEnumerator)
				: pDevices(nullptr)
				, uCount(0)
			{
				pEnumerator->EnumAudioEndpoints(eRender, DEVICE_STATEMASK_ALL, &pDevices);
				if (pDevices)
					pDevices->GetCount(&uCount);
			}
			DeviceCollection(IMMDeviceEnumerator* pEnumerator, EDataFlow eFlow, DWORD dwStateMask)
				: pDevices(nullptr)
				, uCount(0)
			{

				pEnumerator->EnumAudioEndpoints(eFlow, dwStateMask, &pDevices);
				if (pDevices)
					pDevices->GetCount(&uCount);
			}

			// Move constructor
			DeviceCollection(DeviceCollection&& other)
			{
				pDevices = other.pDevices;
				uCount = other.uCount;
				other.pDevices = nullptr;
				other.uCount = 0;
			}

			// Copy construction is not allowed
			DeviceCollection(const DeviceCollection& other) = delete;

			// Destructor
			~DeviceCollection()
			{
				if (pDevices)
				{
					pDevices->Release();
					pDevices = nullptr;
				}
			}

			// Move assignment
			DeviceCollection& operator=(DeviceCollection&& other)
			{
				if (pDevices)
				{
					pDevices->Release();
				}
				pDevices = other.pDevices;
				uCount = other.uCount;
				other.pDevices = nullptr;
				other.uCount = 0;
				return *this;
			}

			// Copy assignment is not allowed
			DeviceCollection& operator=(const DeviceCollection& other) = delete;

			bool IsValid() const { return pDevices != nullptr; }

			UINT Count() const
			{
				return uCount;
			}

			Iterator Begin()
			{
				Iterator it(pDevices, 0);
				return it;
			}
			Iterator End()
			{
				Iterator it(pDevices, uCount);
				return it;
			}

			interface IMMDeviceCollection* pDevices;
			UINT uCount;
		};

		class DeviceEnumerator
		{
		public:

			DeviceEnumerator()
				: pEnumerator(nullptr)
			{
				CoCreateInstance(
					__uuidof(MMDeviceEnumerator), NULL,
					CLSCTX_ALL, __uuidof(IMMDeviceEnumerator),
					(void**)&pEnumerator);
			}

			// Move constructor
			DeviceEnumerator(DeviceEnumerator&& other)
			{
				pEnumerator = other.pEnumerator;
				other.pEnumerator = nullptr;
			}

			// Copy construction is not allowed
			DeviceEnumerator(const DeviceEnumerator& other) = delete;

			// Destructor
			~DeviceEnumerator()
			{
				if (pEnumerator)
				{
					pEnumerator->Release();
					pEnumerator = nullptr;
				}
			}

			// Move assignment
			DeviceEnumerator& operator=(DeviceEnumerator&& other)
			{
				if (pEnumerator)
				{
					pEnumerator->Release();
				}
				pEnumerator = other.pEnumerator;
				other.pEnumerator = nullptr;
				return *this;
			}

			// Copy assignment is not allowed
			DeviceEnumerator& operator=(const DeviceEnumerator& other) = delete;

			bool IsValid() { return pEnumerator != nullptr; }

			Device GetDefaultDevice(ERole in_eRole)
			{
				Device pDevice;
				pEnumerator->GetDefaultAudioEndpoint(eRender, in_eRole, (IMMDevice**)&pDevice.pDevice);	//Transfer the ref
				if (pDevice.pDevice)
					pDevice.ComputeId();
				return pDevice;
			}

			interface IMMDeviceEnumerator* pEnumerator;
		};

		/// Interface to access the IMMDevice cache. This avoids driver accesses.
		class IAkDeviceEnumerator
		{
		public:
			virtual AkUInt32 Count() = 0;	///Returns the number of devices. This function can block.
			virtual Device Item(AkUInt32 in_idx) = 0;	///Gets item in_idx from the cache.  Must be smaller than Count(). This function can block.
			virtual void Lock() = 0;	/// For thread safety.  If you iterate through all the devices, lock the enumerator to avoid changes.  However, if only accessing one single item, Item() is thread safe in itself.
			virtual void Unlock() = 0;  /// For thread safety. See \ref Lock()
			virtual Device FindDevice(AkUInt32 in_id) = 0;	///Find a device that has this unique ID.  The Id is one returned by AK::GetDeviceID.
		};
	}
};