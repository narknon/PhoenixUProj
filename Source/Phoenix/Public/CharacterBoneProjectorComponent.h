#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CharacterBoneProjectorComponent.generated.h"

class UCharacterBoneProjector;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UCharacterBoneProjectorComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCharacterBoneProjector* Projector;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDebugDraw;
    
    UCharacterBoneProjectorComponent();
};

