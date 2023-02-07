#pragma once
#include "CoreMinimal.h"
#include "WorldFXOctreeFX.h"
#include "WorldFXOctreeFXAudioManaged.generated.h"

class UAkComponent;

UCLASS(Blueprintable, NonTransient)
class WORLDFX_API UWorldFXOctreeFXAudioManaged : public UWorldFXOctreeFX {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UAkComponent> AkComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 PlayingID;
    
    UWorldFXOctreeFXAudioManaged();
};

