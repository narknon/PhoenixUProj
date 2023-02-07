#pragma once
#include "CoreMinimal.h"
#include "AkComponent.h"
#include "AkAudioInputComponent.generated.h"

UCLASS(Abstract, Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class AKAUDIO_API UAkAudioInputComponent : public UAkComponent {
    GENERATED_BODY()
public:
    UAkAudioInputComponent();
    UFUNCTION(BlueprintCallable, BlueprintCosmetic)
    int32 PostAssociatedAudioInputEvent();
    
};

