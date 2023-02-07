#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "VanishmentStyleBase.generated.h"

class ATransfigurationPreviewActor;

UCLASS(Blueprintable)
class AVanishmentStyleBase : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ATransfigurationPreviewActor* PreviewActor;
    
    AVanishmentStyleBase();
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void StartVanishment();
    
};

