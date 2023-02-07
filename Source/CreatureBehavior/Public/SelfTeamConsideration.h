#pragma once
#include "CoreMinimal.h"
#include "QualifierConsideration.h"
#include "SelfTeamConsideration.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USelfTeamConsideration : public UQualifierConsideration {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Team;
    
public:
    USelfTeamConsideration();
};

