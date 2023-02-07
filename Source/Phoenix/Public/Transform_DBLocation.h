#pragma once
#include "CoreMinimal.h"
#include "TransformProvider.h"
#include "DBLocationReference.h"
#include "Transform_DBLocation.generated.h"

class UStringProvider;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UTransform_DBLocation : public UTransformProvider {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseBoundParameter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStringProvider* LocationNameProvider;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDBLocationReference Location;
    
    UTransform_DBLocation();
};

