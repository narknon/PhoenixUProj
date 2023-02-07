#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "NoiseParams.h"
#include "NoiseParams2D.h"
#include "NoiseParams3D.h"
#include "NoiseParams4D.h"
#include "OctaveNoiseParams.h"
#include "PerlinNoise.generated.h"

class AActor;
class UCurveFloat;
class UCurveLinearColor;
class UDynamicNoiseNormals;
class UDynamicNoiseOctaveNormals;
class UDynamicNoiseOctaveTexture;
class UDynamicNoiseTexture;
class UTexture2D;

UCLASS(Abstract, Blueprintable)
class PERLINNOISE_API UPerlinNoise : public UObject {
    GENERATED_BODY()
public:
    UPerlinNoise();
    UFUNCTION(BlueprintCallable)
    static UCurveFloat* SaveCurve(FSoftObjectPath Path, UCurveFloat* Curve);
    
    UFUNCTION(BlueprintCallable)
    static float PerlinNoiseSeed();
    
    UFUNCTION(BlueprintCallable)
    static UTexture2D* MakeOctaveNoiseTex(AActor* Owner, const FOctaveNoiseParams& Params, int32 Width, int32 Height, float SuperSample, UCurveLinearColor* Palette, bool WantMask);
    
    UFUNCTION(BlueprintCallable)
    static UTexture2D* MakeOctaveNoiseNormalTex(AActor* Owner, const FOctaveNoiseParams& Params, int32 Width, int32 Height, float Strength, bool Curl, float SuperSample);
    
    UFUNCTION(BlueprintCallable)
    static UCurveFloat* MakeOctaveNoiseCurve(AActor* Owner, float Duration, const FOctaveNoiseParams& Params, float SampleRate, float ErrorThreshold);
    
    UFUNCTION(BlueprintCallable)
    static UTexture2D* MakeNoiseTex(AActor* Owner, const FNoiseParams2D& Params, int32 Width, int32 Height, float SuperSample, UCurveLinearColor* Palette, bool WantMask);
    
    UFUNCTION(BlueprintCallable)
    static UTexture2D* MakeNoiseNormalTex(AActor* Owner, const FNoiseParams2D& Params, int32 Width, int32 Height, float Strength, bool Curl, float SuperSample);
    
    UFUNCTION(BlueprintCallable)
    static UCurveFloat* MakeNoiseNormalizedCurve(AActor* Owner, float Duration, const FNoiseParams& Params, float SampleRate, float ErrorThreshold);
    
    UFUNCTION(BlueprintCallable)
    static UCurveFloat* MakeNoiseCurve(AActor* Owner, float Duration, const FNoiseParams& Params, float SampleRate, float ErrorThreshold);
    
    UFUNCTION(BlueprintCallable)
    static void GetOctaveNoise4D(FVector Pos, float Time, const FOctaveNoiseParams& Params, float& Noise);
    
    UFUNCTION(BlueprintCallable)
    static void GetOctaveNoise3D(FVector Pos, const FOctaveNoiseParams& Params, float& Noise);
    
    UFUNCTION(BlueprintCallable)
    static void GetOctaveNoise2D(FVector2D Pos, const FOctaveNoiseParams& Params, float& Noise);
    
    UFUNCTION(BlueprintCallable)
    static void GetOctaveNoise(float Time, const FOctaveNoiseParams& Params, float& Noise);
    
    UFUNCTION(BlueprintCallable)
    static void GetNoiseNormalized(float Time, const FNoiseParams& Params, float& Noise);
    
    UFUNCTION(BlueprintCallable)
    static void GetNoiseNormal3D(FVector Pos, const FNoiseParams& Params, FVector& Normal, float inverseNormalStrength, float Epsilon);
    
    UFUNCTION(BlueprintCallable)
    static void GetNoiseNormal2D(FVector2D Pos, const FNoiseParams& Params, FVector& Normal, float inverseNormalStrength, float Epsilon);
    
    UFUNCTION(BlueprintCallable)
    static void GetNoise4DAsymmetric(FVector Pos, float Time, const FNoiseParams4D& Params, float& Noise);
    
    UFUNCTION(BlueprintCallable)
    static void GetNoise4D(FVector Pos, float Time, const FNoiseParams& Params, float& Noise);
    
    UFUNCTION(BlueprintCallable)
    static void GetNoise3DAsymmetric(FVector Pos, const FNoiseParams3D& Params, float& Noise);
    
    UFUNCTION(BlueprintCallable)
    static void GetNoise3D(FVector Pos, const FNoiseParams& Params, float& Noise);
    
    UFUNCTION(BlueprintCallable)
    static void GetNoise2DAsymmetric(FVector2D Pos, const FNoiseParams2D& Params, float& Noise);
    
    UFUNCTION(BlueprintCallable)
    static void GetNoise2D(FVector2D Pos, const FNoiseParams& Params, float& Noise);
    
    UFUNCTION(BlueprintCallable)
    static void GetNoise(float Time, const FNoiseParams& Params, float& Noise);
    
    UFUNCTION(BlueprintCallable)
    static void GetCurlNoiseAsNormal(FVector2D Pos, const FNoiseParams& Params, FVector& Curl, float CurlEpsilon, float inverseNormalStrength);
    
    UFUNCTION(BlueprintCallable)
    static void GetCurlNoise3D(FVector Pos, const FNoiseParams& Params, FVector& Curl, float CurlEpsilon);
    
    UFUNCTION(BlueprintCallable)
    static void GetCurlNoise2D(FVector2D Pos, const FNoiseParams& Params, FVector2D& Curl, float CurlEpsilon);
    
    UFUNCTION(BlueprintCallable)
    static UDynamicNoiseTexture* ConstructDynamicNoiseTexture(AActor* Owner, const FNoiseParams2D& Params, float TimeFactor, int32 Width, int32 Height, float UpdateInterval, UCurveLinearColor* Palette, bool WantMask);
    
    UFUNCTION(BlueprintCallable)
    static UDynamicNoiseOctaveTexture* ConstructDynamicNoiseOctaveTexture(AActor* Owner, const FOctaveNoiseParams& Params, float TimeFactor, int32 Width, int32 Height, float UpdateInterval, UCurveLinearColor* Palette, bool WantMask);
    
    UFUNCTION(BlueprintCallable)
    static UDynamicNoiseOctaveNormals* ConstructDynamicNoiseOctaveNormals(AActor* Owner, const FOctaveNoiseParams& Params, float TimeFactor, int32 Width, int32 Height, float UpdateInterval, float NormalStrength, bool Curl);
    
    UFUNCTION(BlueprintCallable)
    static UDynamicNoiseNormals* ConstructDynamicNoiseNormals(AActor* Owner, const FNoiseParams2D& Params, float TimeFactor, int32 Width, int32 Height, float UpdateInterval, float NormalStrength, bool Curl);
    
};

