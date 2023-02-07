#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "DuelTechnique.generated.h"

class UDuelTechniqueState;
class UDuelTechniquesController;

UCLASS(Abstract, Blueprintable)
class UDuelTechnique : public UObject {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDuelTechniquesController* ParentController;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDuelTechniqueState* State;
    
public:
    UDuelTechnique();
};

