#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Placeholder.generated.h"

class USceneComponent;

UCLASS(Blueprintable)
class SCENERIG_API APlaceholder : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* SceneComponent;
    
    APlaceholder();
};

