#pragma once
#include "CoreMinimal.h"
#include "GameFramework/DefaultPawn.h"
#include "MapPawn.generated.h"

class UCameraComponent;

UCLASS(Blueprintable)
class AMapPawn : public ADefaultPawn {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCameraComponent* CameraComponent;
    
    AMapPawn();
};

