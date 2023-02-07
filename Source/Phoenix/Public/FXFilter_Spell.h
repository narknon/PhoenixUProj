#pragma once
#include "CoreMinimal.h"
#include "FXFilter.h"
#include "EMultiFXSpell.h"
#include "FXFilter_Spell.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXFilter_Spell : public UFXFilter {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EMultiFXSpell SpellCondition;
    
public:
    UFXFilter_Spell();
};

