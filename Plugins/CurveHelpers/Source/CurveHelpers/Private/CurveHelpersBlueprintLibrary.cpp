#include "CurveHelpersBlueprintLibrary.h"

class AActor;
class UCurveFloat;
class USplineComponent;

void UCurveHelpersBlueprintLibrary::ShiftCurve(FRuntimeFloatCurve& RuntimeFloatCurve, float DeltaTime) {
}

void UCurveHelpersBlueprintLibrary::SetSplineHasBeenEdited(USplineComponent* Spline, bool bEdited) {
}

void UCurveHelpersBlueprintLibrary::SetExternalCurve(FRuntimeFloatCurve& RuntimeFloatCurve, UCurveFloat* ExternalCurve, bool bCopyToInternal) {
}

void UCurveHelpersBlueprintLibrary::SetCurveKeys(FRuntimeFloatCurve& RuntimeFloatCurve, const TArray<FBlueprintCurveKey>& Keys) {
}

void UCurveHelpersBlueprintLibrary::SetCurveDefaultValue(FRuntimeFloatCurve& RuntimeFloatCurve, float DefaultValue) {
}

void UCurveHelpersBlueprintLibrary::ScaleCurve(FRuntimeFloatCurve& RuntimeFloatCurve, float ScaleOrigin, float ScaleFactor) {
}

void UCurveHelpersBlueprintLibrary::RunConstructionScripts(AActor* Actor) {
}

void UCurveHelpersBlueprintLibrary::ResetCurve(FRuntimeFloatCurve& RuntimeFloatCurve) {
}

void UCurveHelpersBlueprintLibrary::RemoveRedundantCurveKeys(FRuntimeFloatCurve& RuntimeFloatCurve, float Tolerance) {
}

void UCurveHelpersBlueprintLibrary::MakeLinearCurveKey(float Time, float Value, FBlueprintCurveKey& Key) {
}

void UCurveHelpersBlueprintLibrary::MakeCurveKeysTriplet(TArray<FBlueprintCurveKey>& Keys, float StartTime, float StartValue, float MidTime, float MidValue, float EndTime, float EndValue, bool bLinear) {
}

void UCurveHelpersBlueprintLibrary::MakeCurveKeysSimple(TArray<FBlueprintCurveKey>& Keys, float StartTime, float StartValue, float EndTime, float EndValue, bool bLinear) {
}

void UCurveHelpersBlueprintLibrary::MakeCurveKey(float Time, float Value, FBlueprintCurveKey& Key, TEnumAsByte<ERichCurveInterpMode> InterpMode, float ArriveTangent, const float LeaveTangent) {
}

void UCurveHelpersBlueprintLibrary::IsUsingExternalCurve(const FRuntimeFloatCurve& RuntimeFloatCurve, bool& bExternalCurve) {
}

void UCurveHelpersBlueprintLibrary::InsertCurveKeys(FRuntimeFloatCurve& RuntimeFloatCurve, const TArray<FBlueprintCurveKey>& Keys) {
}

void UCurveHelpersBlueprintLibrary::InsertCurveKey(FRuntimeFloatCurve& RuntimeFloatCurve, const FBlueprintCurveKey& Key) {
}

void UCurveHelpersBlueprintLibrary::GetSplineHasBeenEdited(USplineComponent* Spline, bool& bEdited) {
}

void UCurveHelpersBlueprintLibrary::GetExternalCurve(const FRuntimeFloatCurve& RuntimeFloatCurve, UCurveFloat*& ExternalCurve) {
}

void UCurveHelpersBlueprintLibrary::GetCurveValueRange(const FRuntimeFloatCurve& RuntimeFloatCurve, float& MinValue, float& MaxValue) {
}

void UCurveHelpersBlueprintLibrary::GetCurveTimeRange(const FRuntimeFloatCurve& RuntimeFloatCurve, float& MinTime, float& MaxTime) {
}

void UCurveHelpersBlueprintLibrary::GetCurveKeyTimeValue(const FRuntimeFloatCurve& RuntimeFloatCurve, int32 KeyIndex, float& Time, float& Value, bool& bInRange) {
}

void UCurveHelpersBlueprintLibrary::GetCurveKeys(const FRuntimeFloatCurve& RuntimeFloatCurve, TArray<FBlueprintCurveKey>& Keys, int32& KeyCount) {
}

void UCurveHelpersBlueprintLibrary::GetCurveKeyCount(const FRuntimeFloatCurve& RuntimeFloatCurve, int32& KeyCount) {
}

void UCurveHelpersBlueprintLibrary::GetCurveKey(const FRuntimeFloatCurve& RuntimeFloatCurve, int32 KeyIndex, FBlueprintCurveKey& Key, bool& bInRange) {
}

void UCurveHelpersBlueprintLibrary::GetCurveDefaultValue(const FRuntimeFloatCurve& RuntimeFloatCurve, float& DefaultValue) {
}

void UCurveHelpersBlueprintLibrary::EvalCurve(const FRuntimeFloatCurve& RuntimeFloatCurve, float Time, float& Value) {
}

void UCurveHelpersBlueprintLibrary::CurveKeyIndexInRange(const FRuntimeFloatCurve& RuntimeFloatCurve, int32 KeyIndex, bool& bInRange) {
}

void UCurveHelpersBlueprintLibrary::CurveHasAnyData(const FRuntimeFloatCurve& RuntimeFloatCurve, bool& bHasAnyData) {
}

void UCurveHelpersBlueprintLibrary::ConvertExternalCurve(FRuntimeFloatCurve& RuntimeFloatCurve) {
}

void UCurveHelpersBlueprintLibrary::CloneCurve(const FRuntimeFloatCurve& SourceRuntimeFloatCurve, FRuntimeFloatCurve& NewRuntimeFloatCurve) {
}

void UCurveHelpersBlueprintLibrary::ClearCurveDefaultValue(FRuntimeFloatCurve& RuntimeFloatCurve) {
}

void UCurveHelpersBlueprintLibrary::AutoSetCurveTangents(FRuntimeFloatCurve& RuntimeFloatCurve, float Tension) {
}

void UCurveHelpersBlueprintLibrary::AppendCurveKey(FRuntimeFloatCurve& RuntimeFloatCurve, const FBlueprintCurveKey& Key) {
}

UCurveHelpersBlueprintLibrary::UCurveHelpersBlueprintLibrary() {
}

