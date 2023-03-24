#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AttachCameraActor.generated.h"

class UAttachCameraComponent;

UCLASS(Blueprintable)
class FXUTIL_API AAttachCameraActor : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAttachCameraComponent* AttachCamera;
    
    AAttachCameraActor(const FObjectInitializer& ObjectInitializer);
};

