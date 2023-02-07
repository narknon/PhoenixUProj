#pragma once
#include "CoreMinimal.h"
#include "BoolProvider.h"
#include "Bool_IsFemaleCharacter.generated.h"

class UActorProvider;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class SCENERIG_API UBool_IsFemaleCharacter : public UBoolProvider {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UActorProvider* Actor;
    
    UBool_IsFemaleCharacter();
};

