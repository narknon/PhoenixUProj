#include "PerlinNoise.h"

class AActor;
class UCurveFloat;
class UCurveLinearColor;
class UDynamicNoiseNormals;
class UDynamicNoiseOctaveNormals;
class UDynamicNoiseOctaveTexture;
class UDynamicNoiseTexture;
class UTexture2D;

UCurveFloat* UPerlinNoise::SaveCurve(FSoftObjectPath Path, UCurveFloat* Curve) {
    return NULL;
}

float UPerlinNoise::PerlinNoiseSeed() {
    return 0.0f;
}

UTexture2D* UPerlinNoise::MakeOctaveNoiseTex(AActor* Owner, const FOctaveNoiseParams& Params, int32 Width, int32 Height, float SuperSample, UCurveLinearColor* Palette, bool WantMask) {
    return NULL;
}

UTexture2D* UPerlinNoise::MakeOctaveNoiseNormalTex(AActor* Owner, const FOctaveNoiseParams& Params, int32 Width, int32 Height, float Strength, bool Curl, float SuperSample) {
    return NULL;
}

UCurveFloat* UPerlinNoise::MakeOctaveNoiseCurve(AActor* Owner, float Duration, const FOctaveNoiseParams& Params, float SampleRate, float ErrorThreshold) {
    return NULL;
}

UTexture2D* UPerlinNoise::MakeNoiseTex(AActor* Owner, const FNoiseParams2D& Params, int32 Width, int32 Height, float SuperSample, UCurveLinearColor* Palette, bool WantMask) {
    return NULL;
}

UTexture2D* UPerlinNoise::MakeNoiseNormalTex(AActor* Owner, const FNoiseParams2D& Params, int32 Width, int32 Height, float Strength, bool Curl, float SuperSample) {
    return NULL;
}

UCurveFloat* UPerlinNoise::MakeNoiseNormalizedCurve(AActor* Owner, float Duration, const FNoiseParams& Params, float SampleRate, float ErrorThreshold) {
    return NULL;
}

UCurveFloat* UPerlinNoise::MakeNoiseCurve(AActor* Owner, float Duration, const FNoiseParams& Params, float SampleRate, float ErrorThreshold) {
    return NULL;
}

void UPerlinNoise::GetOctaveNoise4D(FVector Pos, float Time, const FOctaveNoiseParams& Params, float& Noise) {
}

void UPerlinNoise::GetOctaveNoise3D(FVector Pos, const FOctaveNoiseParams& Params, float& Noise) {
}

void UPerlinNoise::GetOctaveNoise2D(FVector2D Pos, const FOctaveNoiseParams& Params, float& Noise) {
}

void UPerlinNoise::GetOctaveNoise(float Time, const FOctaveNoiseParams& Params, float& Noise) {
}

void UPerlinNoise::GetNoiseNormalized(float Time, const FNoiseParams& Params, float& Noise) {
}

void UPerlinNoise::GetNoiseNormal3D(FVector Pos, const FNoiseParams& Params, FVector& Normal, float inverseNormalStrength, float Epsilon) {
}

void UPerlinNoise::GetNoiseNormal2D(FVector2D Pos, const FNoiseParams& Params, FVector& Normal, float inverseNormalStrength, float Epsilon) {
}

void UPerlinNoise::GetNoise4DAsymmetric(FVector Pos, float Time, const FNoiseParams4D& Params, float& Noise) {
}

void UPerlinNoise::GetNoise4D(FVector Pos, float Time, const FNoiseParams& Params, float& Noise) {
}

void UPerlinNoise::GetNoise3DAsymmetric(FVector Pos, const FNoiseParams3D& Params, float& Noise) {
}

void UPerlinNoise::GetNoise3D(FVector Pos, const FNoiseParams& Params, float& Noise) {
}

void UPerlinNoise::GetNoise2DAsymmetric(FVector2D Pos, const FNoiseParams2D& Params, float& Noise) {
}

void UPerlinNoise::GetNoise2D(FVector2D Pos, const FNoiseParams& Params, float& Noise) {
}

void UPerlinNoise::GetNoise(float Time, const FNoiseParams& Params, float& Noise) {
}

void UPerlinNoise::GetCurlNoiseAsNormal(FVector2D Pos, const FNoiseParams& Params, FVector& Curl, float CurlEpsilon, float inverseNormalStrength) {
}

void UPerlinNoise::GetCurlNoise3D(FVector Pos, const FNoiseParams& Params, FVector& Curl, float CurlEpsilon) {
}

void UPerlinNoise::GetCurlNoise2D(FVector2D Pos, const FNoiseParams& Params, FVector2D& Curl, float CurlEpsilon) {
}

UDynamicNoiseTexture* UPerlinNoise::ConstructDynamicNoiseTexture(AActor* Owner, const FNoiseParams2D& Params, float TimeFactor, int32 Width, int32 Height, float UpdateInterval, UCurveLinearColor* Palette, bool WantMask) {
    return NULL;
}

UDynamicNoiseOctaveTexture* UPerlinNoise::ConstructDynamicNoiseOctaveTexture(AActor* Owner, const FOctaveNoiseParams& Params, float TimeFactor, int32 Width, int32 Height, float UpdateInterval, UCurveLinearColor* Palette, bool WantMask) {
    return NULL;
}

UDynamicNoiseOctaveNormals* UPerlinNoise::ConstructDynamicNoiseOctaveNormals(AActor* Owner, const FOctaveNoiseParams& Params, float TimeFactor, int32 Width, int32 Height, float UpdateInterval, float NormalStrength, bool Curl) {
    return NULL;
}

UDynamicNoiseNormals* UPerlinNoise::ConstructDynamicNoiseNormals(AActor* Owner, const FNoiseParams2D& Params, float TimeFactor, int32 Width, int32 Height, float UpdateInterval, float NormalStrength, bool Curl) {
    return NULL;
}

UPerlinNoise::UPerlinNoise() {
}

