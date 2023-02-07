#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Components/ActorComponent.h"
#include "LEDEffects.generated.h"

class ULEDFadeEffect;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class TOOLSET_API ULEDEffects : public UActorComponent {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<ULEDFadeEffect*> faders;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ULEDFadeEffect* BaseLEDFadeEffect;
    
public:
    ULEDEffects();
    UFUNCTION(BlueprintCallable)
    void SetColor(const int32& ControllerId, const FColor& Color);
    
    UFUNCTION(BlueprintCallable)
    void ResetLED(const int32& ControllerId);
    
    UFUNCTION(BlueprintCallable)
    void ResetAll();
    
    UFUNCTION(BlueprintCallable)
    bool GetActiveColor(FColor& Color);
    
};

