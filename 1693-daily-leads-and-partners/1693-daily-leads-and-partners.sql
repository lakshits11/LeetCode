select
    date_id,
    make_name,
    COUNT(distinct lead_id) as unique_leads,
    COUNT(distinct partner_id) as unique_partners
from
    DailySales
group by
    date_id, make_name