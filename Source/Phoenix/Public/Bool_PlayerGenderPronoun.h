#pragma once
#include "CoreMinimal.h"
#include "BoolProvider.h"
#include "EGenderPronoun.h"
#include "Bool_PlayerGenderPronoun.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class PHOENIX_API UBool_PlayerGenderPronoun : public UBoolProvider {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EGenderPronoun Pronoun;
    
    UBool_PlayerGenderPronoun();
};

