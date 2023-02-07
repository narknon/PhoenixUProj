#pragma once
#include "CoreMinimal.h"
#include "GlobalLightingBlendableModsBase.h"
#include "GlobalLightingBlendableModCollection.generated.h"

class UGlobalLightRigModCollection;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class GLOBALLIGHTRIG_API UGlobalLightingBlendableModCollection : public UGlobalLightingBlendableModsBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGlobalLightRigModCollection* ModCollection;
    
    UGlobalLightingBlendableModCollection();
};

