#pragma once
#include "CoreMinimal.h"
#include "ActorMeshSetupMatch.h"
#include "ActorMeshSetupMatchCustomizableCharacterType.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UActorMeshSetupMatchCustomizableCharacterType : public UActorMeshSetupMatch {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> Types;
    
    UActorMeshSetupMatchCustomizableCharacterType();
};

