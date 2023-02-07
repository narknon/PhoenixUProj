#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SceneRigRegisteredActorComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class SCENERIG_API USceneRigRegisteredActorComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> RegisteredNames;
    
    USceneRigRegisteredActorComponent();
};

