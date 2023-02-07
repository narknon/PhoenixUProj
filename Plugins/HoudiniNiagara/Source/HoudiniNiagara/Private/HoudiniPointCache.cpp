#include "HoudiniPointCache.h"

void UHoudiniPointCache::SetUseCustomCSVTitleRow(bool bInUseCustomCSVTitleRow) {
}

bool UHoudiniPointCache::GetVelocityValue(const int32& SampleIndex, FVector& Value) const {
    return false;
}

bool UHoudiniPointCache::GetVectorValueForString(const int32& SampleIndex, const FString& Attribute, FVector& Value, const bool& DoSwap, const bool& DoScale) const {
    return false;
}

bool UHoudiniPointCache::GetVectorValue(const int32& SampleIndex, const int32& attrIndex, FVector& Value, const bool& DoSwap, const bool& DoScale) const {
    return false;
}

bool UHoudiniPointCache::GetVector4ValueForString(const int32& SampleIndex, const FString& Attribute, FVector4& Value) const {
    return false;
}

bool UHoudiniPointCache::GetVector4Value(const int32& SampleIndex, const int32& attrIndex, FVector4& Value) const {
    return false;
}

bool UHoudiniPointCache::GetUseCustomCSVTitleRow() const {
    return false;
}

bool UHoudiniPointCache::GetTimeValue(const int32& SampleIndex, float& Value) const {
    return false;
}

TArray<int32> UHoudiniPointCache::GetSpecialAttributeIndexes() const {
    return TArray<int32>();
}

TArray<float> UHoudiniPointCache::GetSpawnTimes() const {
    return TArray<float>();
}

bool UHoudiniPointCache::GetSampleIndexesForPointAtTime(const int32& POINTID, const float& desiredTime, int32& PrevSampleIndex, int32& NextSampleIndex, float& PrevWeight) const {
    return false;
}

bool UHoudiniPointCache::GetQuatValueForString(const int32& SampleIndex, const FString& Attribute, FQuat& Value, const bool& DoHoudiniToUnrealConversion) const {
    return false;
}

bool UHoudiniPointCache::GetQuatValue(const int32& SampleIndex, const int32& attrIndex, FQuat& Value, const bool& DoHoudiniToUnrealConversion) const {
    return false;
}

bool UHoudiniPointCache::GetPositionValue(const int32& SampleIndex, FVector& Value) const {
    return false;
}

bool UHoudiniPointCache::GetPointVectorValueAtTimeForString(int32 POINTID, const FString& Attribute, float desiredTime, FVector& Vector, bool DoSwap, bool DoScale) const {
    return false;
}

bool UHoudiniPointCache::GetPointVectorValueAtTime(int32 POINTID, int32 AttributeIndex, float desiredTime, FVector& Vector, bool DoSwap, bool DoScale) const {
    return false;
}

bool UHoudiniPointCache::GetPointVector4ValueAtTimeForString(int32 POINTID, const FString& Attribute, float desiredTime, FVector4& Vector) const {
    return false;
}

bool UHoudiniPointCache::GetPointVector4ValueAtTime(int32 POINTID, int32 AttributeIndex, float desiredTime, FVector4& Vector) const {
    return false;
}

TArray<FPointIndexes> UHoudiniPointCache::GetPointValueIndexes() const {
    return TArray<FPointIndexes>();
}

bool UHoudiniPointCache::GetPointValueAtTimeForString(const int32& POINTID, const FString& Attribute, const float& desiredTime, float& Value) const {
    return false;
}

bool UHoudiniPointCache::GetPointValueAtTime(const int32& POINTID, const int32& AttributeIndex, const float& desiredTime, float& Value) const {
    return false;
}

TArray<int32> UHoudiniPointCache::GetPointTypes() const {
    return TArray<int32>();
}

bool UHoudiniPointCache::GetPointType(const int32& POINTID, int32& Value) const {
    return false;
}

bool UHoudiniPointCache::GetPointQuatValueAtTimeForString(int32 POINTID, const FString& Attribute, float desiredTime, FQuat& Quat, bool DoHoudiniToUnrealConversion) const {
    return false;
}

bool UHoudiniPointCache::GetPointQuatValueAtTime(int32 POINTID, int32 AttributeIndex, float desiredTime, FQuat& Quat, bool DoHoudiniToUnrealConversion) const {
    return false;
}

bool UHoudiniPointCache::GetPointPositionAtTime(const int32& POINTID, const float& desiredTime, FVector& Vector) const {
    return false;
}

bool UHoudiniPointCache::GetPointLifeAtTime(const int32& POINTID, const float& desiredTime, float& Value) const {
    return false;
}

bool UHoudiniPointCache::GetPointLife(const int32& POINTID, float& Value) const {
    return false;
}

bool UHoudiniPointCache::GetPointInt32ValueAtTime(int32 POINTID, int32 AttributeIndex, float desiredTime, int32& Value) const {
    return false;
}

bool UHoudiniPointCache::GetPointIDsToSpawnAtTime(const float& desiredTime, int32& MinID, int32& MaxID, int32& Count, int32& LastSpawnedPointID, float& LastSpawnTime, float& LastSpawnTimeRequest) const {
    return false;
}

bool UHoudiniPointCache::GetPointFloatValueAtTime(int32 POINTID, int32 AttributeIndex, float desiredTime, float& Value) const {
    return false;
}

int32 UHoudiniPointCache::GetNumberOfSamples() const {
    return 0;
}

int32 UHoudiniPointCache::GetNumberOfPoints() const {
    return 0;
}

int32 UHoudiniPointCache::GetNumberOfAttributes() const {
    return 0;
}

bool UHoudiniPointCache::GetNormalValue(const int32& SampleIndex, FVector& Value) const {
    return false;
}

TArray<float> UHoudiniPointCache::GetLifeValues() const {
    return TArray<float>();
}

bool UHoudiniPointCache::GetLastSampleIndexAtTime(const float& desiredTime, int32& lastSampleIndex) const {
    return false;
}

bool UHoudiniPointCache::GetLastPointIDToSpawnAtTime(const float& Time, int32& lastID) const {
    return false;
}

bool UHoudiniPointCache::GetImpulseValue(const int32& SampleIndex, float& Value) const {
    return false;
}

bool UHoudiniPointCache::GetFloatValueForString(const int32& SampleIndex, const FString& Attribute, float& Value) const {
    return false;
}

bool UHoudiniPointCache::GetFloatValue(const int32& SampleIndex, const int32& attrIndex, float& Value) const {
    return false;
}

TArray<float> UHoudiniPointCache::GetFloatSampleData() const {
    return TArray<float>();
}

bool UHoudiniPointCache::GetColorValue(const int32& SampleIndex, FLinearColor& Value) const {
    return false;
}

bool UHoudiniPointCache::GetAttributeIndexInArrayFromString(const FString& InAttribute, const TArray<FString>& InAttributeArray, int32& OutAttributeIndex) {
    return false;
}

bool UHoudiniPointCache::GetAttributeIndexFromString(const FString& Attribute, int32& AttributeIndex) const {
    return false;
}

UHoudiniPointCache::UHoudiniPointCache() {
    this->NumberOfSamples = -1;
    this->NumberOfAttributes = -1;
    this->NumberOfPoints = -1;
    this->NumberOfFrames = -1;
    this->FirstFrame = 340282346638528859811704183484516925440.00f;
    this->LastFrame = -340282346638528859811704183484516925440.00f;
    this->MinSampleTime = 340282346638528859811704183484516925440.00f;
    this->MaxSampleTime = -340282346638528859811704183484516925440.00f;
    this->SpecialAttributeIndexes.AddDefaulted(11);
    this->UseCustomCSVTitleRow = false;
    this->FileType = EHoudiniPointCacheFileType::Invalid;
}

