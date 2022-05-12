class Solution:
    def numUniqueEmails(self, emails: List[str]) -> int:
        s = set()
        for i in emails:
            local, domain = i.split('@')
            local = local.split('+')[0].replace('.', '')
            s.add((local, domain))
        return len(s)