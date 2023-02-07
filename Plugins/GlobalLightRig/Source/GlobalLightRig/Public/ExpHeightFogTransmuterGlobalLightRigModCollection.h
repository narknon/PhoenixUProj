#pragma once
#include "CoreMinimal.h"
#include "ExpHeightFogTransmuter.h"
#include "ExpHeightFogTransmuterGlobalLightRigModCollection.generated.h"

class UGlobalLightRigModCollection;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class GLOBALLIGHTRIG_API UExpHeightFogTransmuterGlobalLightRigModCollection : public UExpHeightFogTransmuter {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGlobalLightRigModCollection* ModCollection;
    
    UExpHeightFogTransmuterGlobalLightRigModCollection();
};

