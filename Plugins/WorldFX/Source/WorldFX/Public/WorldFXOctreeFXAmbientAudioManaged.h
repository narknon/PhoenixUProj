#pragma once
#include "CoreMinimal.h"
#include "WorldFXOctreeFX.h"
#include "WorldFXOctreeFXAmbientAudioManaged.generated.h"

class AAkAmbientSound;

UCLASS(Blueprintable, NonTransient)
class WORLDFX_API UWorldFXOctreeFXAmbientAudioManaged : public UWorldFXOctreeFX {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<AAkAmbientSound> AkAmbientSound;
    
    UWorldFXOctreeFXAmbientAudioManaged();
};

