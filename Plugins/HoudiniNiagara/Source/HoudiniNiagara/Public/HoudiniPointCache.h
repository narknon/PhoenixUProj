#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "EHoudiniPointCacheFileType.h"
#include "PointIndexes.h"
#include "HoudiniPointCache.generated.h"

UCLASS(Blueprintable)
class HOUDININIAGARA_API UHoudiniPointCache : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString Filename;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 NumberOfSamples;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 NumberOfAttributes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 NumberOfPoints;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 NumberOfFrames;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FirstFrame;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LastFrame;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinSampleTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxSampleTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString SourceCSVTitleRow;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FString> AttributeArray;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<float> FloatSampleData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<float> SpawnTimes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<float> LifeValues;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<int32> PointTypes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<int32> SpecialAttributeIndexes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FPointIndexes> PointValueIndexes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool UseCustomCSVTitleRow;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EHoudiniPointCacheFileType FileType;
    
public:
    UHoudiniPointCache();
    UFUNCTION(BlueprintCallable)
    void SetUseCustomCSVTitleRow(bool bInUseCustomCSVTitleRow);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetVelocityValue(const int32& SampleIndex, FVector& Value) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetVectorValueForString(const int32& SampleIndex, const FString& Attribute, FVector& Value, const bool& DoSwap, const bool& DoScale) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetVectorValue(const int32& SampleIndex, const int32& attrIndex, FVector& Value, const bool& DoSwap, const bool& DoScale) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetVector4ValueForString(const int32& SampleIndex, const FString& Attribute, FVector4& Value) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetVector4Value(const int32& SampleIndex, const int32& attrIndex, FVector4& Value) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetUseCustomCSVTitleRow() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetTimeValue(const int32& SampleIndex, float& Value) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<int32> GetSpecialAttributeIndexes() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<float> GetSpawnTimes() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetSampleIndexesForPointAtTime(const int32& POINTID, const float& desiredTime, int32& PrevSampleIndex, int32& NextSampleIndex, float& PrevWeight) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetQuatValueForString(const int32& SampleIndex, const FString& Attribute, FQuat& Value, const bool& DoHoudiniToUnrealConversion) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetQuatValue(const int32& SampleIndex, const int32& attrIndex, FQuat& Value, const bool& DoHoudiniToUnrealConversion) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetPositionValue(const int32& SampleIndex, FVector& Value) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetPointVectorValueAtTimeForString(int32 POINTID, const FString& Attribute, float desiredTime, FVector& Vector, bool DoSwap, bool DoScale) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetPointVectorValueAtTime(int32 POINTID, int32 AttributeIndex, float desiredTime, FVector& Vector, bool DoSwap, bool DoScale) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetPointVector4ValueAtTimeForString(int32 POINTID, const FString& Attribute, float desiredTime, FVector4& Vector) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetPointVector4ValueAtTime(int32 POINTID, int32 AttributeIndex, float desiredTime, FVector4& Vector) const;
    
    UFUNCTION(BlueprintCallable)
    TArray<FPointIndexes> GetPointValueIndexes() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetPointValueAtTimeForString(const int32& POINTID, const FString& Attribute, const float& desiredTime, float& Value) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetPointValueAtTime(const int32& POINTID, const int32& AttributeIndex, const float& desiredTime, float& Value) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<int32> GetPointTypes() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetPointType(const int32& POINTID, int32& Value) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetPointQuatValueAtTimeForString(int32 POINTID, const FString& Attribute, float desiredTime, FQuat& Quat, bool DoHoudiniToUnrealConversion) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetPointQuatValueAtTime(int32 POINTID, int32 AttributeIndex, float desiredTime, FQuat& Quat, bool DoHoudiniToUnrealConversion) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetPointPositionAtTime(const int32& POINTID, const float& desiredTime, FVector& Vector) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetPointLifeAtTime(const int32& POINTID, const float& desiredTime, float& Value) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetPointLife(const int32& POINTID, float& Value) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetPointInt32ValueAtTime(int32 POINTID, int32 AttributeIndex, float desiredTime, int32& Value) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetPointIDsToSpawnAtTime(const float& desiredTime, int32& MinID, int32& MaxID, int32& Count, int32& LastSpawnedPointID, float& LastSpawnTime, float& LastSpawnTimeRequest) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetPointFloatValueAtTime(int32 POINTID, int32 AttributeIndex, float desiredTime, float& Value) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetNumberOfSamples() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetNumberOfPoints() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetNumberOfAttributes() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetNormalValue(const int32& SampleIndex, FVector& Value) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<float> GetLifeValues() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetLastSampleIndexAtTime(const float& desiredTime, int32& lastSampleIndex) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetLastPointIDToSpawnAtTime(const float& Time, int32& lastID) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetImpulseValue(const int32& SampleIndex, float& Value) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetFloatValueForString(const int32& SampleIndex, const FString& Attribute, float& Value) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetFloatValue(const int32& SampleIndex, const int32& attrIndex, float& Value) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<float> GetFloatSampleData() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetColorValue(const int32& SampleIndex, FLinearColor& Value) const;
    
    UFUNCTION(BlueprintCallable)
    static bool GetAttributeIndexInArrayFromString(const FString& InAttribute, const TArray<FString>& InAttributeArray, int32& OutAttributeIndex);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetAttributeIndexFromString(const FString& Attribute, int32& AttributeIndex) const;
    
};

