#pragma once
#include "CoreMinimal.h"
#include "BoolProvider.h"
#include "Bool_IsMaleCharacter.generated.h"

class UActorProvider;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class SCENERIG_API UBool_IsMaleCharacter : public UBoolProvider {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UActorProvider* Actor;
    
    UBool_IsMaleCharacter();
};

