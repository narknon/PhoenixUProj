#pragma once
#include "CoreMinimal.h"
#include "QualifierConsideration.h"
#include "OptionActorCheckSpeciesTeamConsideration.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UOptionActorCheckSpeciesTeamConsideration : public UQualifierConsideration {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Team;
    
public:
    UOptionActorCheckSpeciesTeamConsideration();
};

