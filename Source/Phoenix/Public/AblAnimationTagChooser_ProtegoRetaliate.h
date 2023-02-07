#pragma once
#include "CoreMinimal.h"
#include "AblAnimationTagChooser.h"
#include "AblAnimationTagChooser_ProtegoRetaliate.generated.h"

class USpellToolRecord;

UCLASS(Blueprintable, EditInlineNew)
class UAblAnimationTagChooser_ProtegoRetaliate : public UAblAnimationTagChooser {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<USpellToolRecord*> SpellToEquip;
    
    UAblAnimationTagChooser_ProtegoRetaliate();
};

