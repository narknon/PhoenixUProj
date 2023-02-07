#pragma once
#include "CoreMinimal.h"
#include "QualifierConsideration.h"
#include "SelfCheckSpeciesTeamConsideration.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USelfCheckSpeciesTeamConsideration : public UQualifierConsideration {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Team;
    
public:
    USelfCheckSpeciesTeamConsideration();
};

