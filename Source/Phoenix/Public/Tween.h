#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "EEasingFunction.h"
#include "ETransformProperty.h"
#include "TweenFinishedSignatureDelegate.h"
#include "Tween.generated.h"

class UCurveFloat;
class UTween;

UCLASS(Blueprintable)
class UTween : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* EasingCurve;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTweenFinishedSignature OnTweenFinished;
    
    UTween();
    UFUNCTION(BlueprintCallable)
    UTween* TweenVector2DPropertyToEnd(UObject* ObjectIn, FName PropertyNameIn, FVector2D EndIn, float Duration, EEasingFunction EasingFunctionIn);
    
    UFUNCTION(BlueprintCallable)
    UTween* TweenVector2DPropertyFromStartToEnd(UObject* ObjectIn, FName PropertyNameIn, FVector2D StartIn, FVector2D EndIn, float Duration, EEasingFunction EasingFunctionIn);
    
    UFUNCTION(BlueprintCallable)
    UTween* TweenTransformPropertyToEnd(UObject* ObjectIn, ETransformProperty TransformProperty, FVector2D EndIn, float Duration, EEasingFunction EasingFunctionIn);
    
    UFUNCTION(BlueprintCallable)
    UTween* TweenTransformPropertyFromStartToEnd(UObject* ObjectIn, ETransformProperty TransformProperty, FVector2D StartIn, FVector2D EndIn, float Duration, EEasingFunction EasingFunctionIn);
    
    UFUNCTION(BlueprintCallable)
    UTween* TweenIntPropertyToEnd(UObject* ObjectIn, FName ProertyNameIn, int32 EndIn, float Duration, EEasingFunction EasingFunctionIn);
    
    UFUNCTION(BlueprintCallable)
    UTween* TweenIntPropertyFromStartToEnd(UObject* ObjectIn, FName ProertyNameIn, int32 StartIn, int32 EndIn, float Duration, EEasingFunction EasingFunctionIn);
    
    UFUNCTION(BlueprintCallable)
    UTween* TweenFloatPropertyToEnd(UObject* ObjectIn, FName ProertyNameIn, float EndIn, float Duration, EEasingFunction EasingFunctionIn);
    
    UFUNCTION(BlueprintCallable)
    UTween* TweenFloatPropertyFromStartToEnd(UObject* ObjectIn, FName ProertyNameIn, float StartIn, float EndIn, float Duration, EEasingFunction EasingFunctionIn);
    
    UFUNCTION(BlueprintCallable)
    UTween* TweenColorPropertyToEnd(UObject* ObjectIn, FName PropertyNameIn, FLinearColor EndIn, float Duration, EEasingFunction EasingFunctionIn);
    
    UFUNCTION(BlueprintCallable)
    UTween* TweenColorPropertyFromStartToEnd(UObject* ObjectIn, FName PropertyNameIn, FLinearColor StartIn, FLinearColor EndIn, float Duration, EEasingFunction EasingFunctionIn);
    
    UFUNCTION(BlueprintCallable)
    UTween* Play();
    
    UFUNCTION(BlueprintCallable)
    bool IsPlaying();
    
    UFUNCTION(BlueprintCallable)
    static UTween* ConstructTween();
    
};

